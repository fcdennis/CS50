#include <cs50.h>
#include <stdio.h>

int valido(long number);
string brand(long number);
int main(void)
{
    //reciving a valid number
    long number = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    //verifying if the card is valid
    int validador = valido(number);
    
    //finding out the card brand
    if (validador % 10 == 0)
    {
       string card_brand = brand(number);
       printf("%s\n", card_brand);
    }
    else
    {
        printf("INVALID\n");
    }
}

// function that verify if the number is a valid card
int valido(long number)
{
    long resultado1 = 0, resultado2 = 0;
    int sobra = 0, validador1 = 0, validador2 = 0;
    do
    {
       validador2 += (number % 10);
       resultado1 = number / 10;
       resultado2 = resultado1 / 10;
       sobra = 2 * (resultado1 % 10);
       if (sobra < 10)
       {
           validador1 += sobra;
       }
       else
       {
           validador1 += 1 + (sobra - 10);
       }
       number = resultado2;
    }
    while (number > 0);
    int validador = validador1 + validador2;
    return validador;
}

// function that defines the credit card brand
string brand(long number)
{
    int cont = 1;
    long i = 0;
    for (i = number; i > 10;)
    {
        i /= 10;
        cont++;
    }
    //brandes
    if (cont == 16 && i == 5)
    {
        return "MASTERCARD";
    }
    else if (cont == 15)
    {
        return "AMEX";
    }
    else if (cont == 13 || (cont == 16 && i == 4))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}