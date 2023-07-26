#include <stdio.h>

int main()
{
    float a = 1.0;
    float b = 0.3;
    float c = a - b;

    printf("a: %f b: %f c: %f\n", a);
    // a: 1.000000 b: 0.000000 c: 0.000000
    printf("a/b: %f\n", a/b);
    // a/b: 3.333333
    printf("a: %d b: %d c: %d\n", a, b, c);
    // a: 0 b: 1073741824 c: 1610612736
}