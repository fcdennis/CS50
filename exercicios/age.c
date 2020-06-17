#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int age = get_int("What's your age?\n");
    int day = age * 365;
    printf("You have at least %i days of life!\n", day);
}