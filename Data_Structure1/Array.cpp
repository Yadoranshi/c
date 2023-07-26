#include <stdio.h>

int main()
{
    int arr[10];

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    puts("index?");
    int idx;
    scanf("%d", &idx);
    printf("%d", arr[idx]);
}