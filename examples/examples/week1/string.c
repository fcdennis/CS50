#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = get_long("Digite um número: ");
    int cont = 1;
    long i = 0;
    
    for (i = number; i > 100;)
    {
        i /= 10;
        cont++;
    }
    
    if (i == 51 || i == 52)
    {
        printf("%li\n", i);
        printf("MASTERCARD\n");
    }
    else if (i == 53 || i == 54)
    {
        printf("%li\n", i);
        printf("MASTERCARD\n");
    }
    else if (i == 55)
    {
        printf("%li\n", i);
        printf("MASTERCARD\n");
    }
    else if (i == 34 || i == 37)
    {
        printf("AMEX\n");
    }
    else if (i / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}