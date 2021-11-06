/*
 * A simple DOP program, inspired by:
 *
 * http://proftp.cvs.sourceforge.net/viewvc/proftp/proftpd/src/main.c?revision=1.275&view=markup&pathrev=R1_3_0RC3 (line 801)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

static unsigned char zone1[0x10];
static unsigned char vulbuf[] = { 'A', 'A', 'A', 'A', 'A', 'A', '\x00' };

#define PAYLOAD_SIZE 300
static unsigned char payload[PAYLOAD_SIZE];

static void read_payload(void)
{
  ssize_t err;
  err = read(0, payload, PAYLOAD_SIZE);
  assert(err >= 0 && "Read error!");
#if 0
  for (err = 0; err < PAYLOAD_SIZE; err++)
    printf("%02x, ", payload[err]);
  printf("\n");
#endif
}

static void f(void)
{
  unsigned char *pc = payload;
  unsigned char *p1 = zone1;
  unsigned char *p2 = zone1;
  unsigned char cond = 0x1, count = 0x42;
  unsigned char buf[8];

  /* Our gadget dispatcher */
  while (count--) {
    // haxx
    memcpy(buf, pc, 8 + 2 + 16);
    /* count = buf[8]; */
    /* cond = buf[9]; */
    /* memcpy(&p2, &buf[10], 8); */
    /* memcpy(&p1, &buf[18], 8); */

    /* no turing complete program counter, but we could do that in
       theory... */
    pc += 8 + 2 + 16;
#if 1
    printf("count = %02x, cond = %02x, p1 = %lx, p2 = %lx, pc = %lx\n",
           count, cond, p1, p2, pc);
#endif
    if (cond == 0x0)
      /* Gadget 0: halt machine */
      break;
    if (cond == 0x1) {
      /* Gadget 1: store */
      *p1 = *p2;
    } else {
      /* Gadget 2: load */
      *p2 = cond;
    }
  }
}

int main(void)
{
  read_payload();
  f();

  printf("End of program: %s!\n", vulbuf);
  return 0;
}
