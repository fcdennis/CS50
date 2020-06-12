#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char gender = get_char("Are you b or g? ");
    if (gender == 'b')
    {
        printf("You're a boy!\n");
    }
    else if (gender == 'g')
    {
        printf("You're a girl!\n");
    }
    else
    {
        printf("Hum, interesting...\n");
    }
}