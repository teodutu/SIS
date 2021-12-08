#include <stdio.h>


int main()
{
    int a = 1, b;
    b = a++ + ++a + a++;
    printf("a=%d\n", a);
    printf("b=%d\n", b);

}

