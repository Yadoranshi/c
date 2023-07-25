#include <stdio.h>

int main()
{
    char name[10];
    int age, weight, height;
    
    puts("what's your name?");
    scanf("%s", name);

    puts("how old are you?");
    scanf("%d", &age);

    puts("how much do you weigh?");
    scanf("%d", &weight);

    puts("how tall are you?");
    scanf("%d", &height);

    printf("Hi %s here is your profile\n", name);
    printf("age: %d weight: %d height: %d\n", age, weight, height);
}