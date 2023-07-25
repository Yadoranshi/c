#include <stdio.h>

int main()
{
    char arr1[5] = {'a','p','p','l','e'};
    int arr2[5] = {1,2,3,4,5};

    printf("arr1[0]: %c arr1[3]: %c\n", arr1[0], arr1[3]);
    // arr1[0]: a arr1[3]: l
    printf("%s\n", arr1);
    //apple

    printf("arr2[0]: %d arr2[3]: %d\n", arr2[0], arr2[3]);
    // arr2[0]: 1 arr2[3]: 4
    printf("arr2[5]: %d", arr2[5]);
}