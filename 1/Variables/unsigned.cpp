#include <stdio.h>

int main()
{
    int a = 4294967295;
    unsigned int b = 4294967295;
    printf("a: %d b: %u\n", a, b);
    //a: -1 b: 4294967295
}