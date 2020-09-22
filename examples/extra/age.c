#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int age;
    printf("Qual é a sua idade: ");
    scanf("%i", &age);
    int day = age * 365;
    printf("You have at least %i days of life!\n", day);
    return 0;
}
