#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //reciving a valid number
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    
    long resultado1 = 0, resultado2 = 0;
    int sobra = 0, validador1 = 0, validador2 = 0;
    do
    {
       validador2 = validador2 + (number % 10);
       resultado1 = number / 10;
       resultado2 = resultado1 / 10;
       number = resultado2;
    }
    while (number > 0);
    printf("%i\n", validador2);
}