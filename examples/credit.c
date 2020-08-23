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
    //Conjunto de variaveis
    long resultado1 = 0, resultado2 = 0;
    int sobra = 0, validador1 = 0, validador2 = 0;
    // Loop
    do
    {
        validador2 += (number % 10);
        resultado1 = number / 10;
        resultado2 = resultado1 / 10;
        sobra = 2 * (resultado1 % 10);
        //desvio
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
    //contador
    long i = 0;
    int cont = 1;
    for (i = number; i > 100;)
    {
        i /= 10;
        cont++;
    }
    //Mastercards
    if (i == 51 || i == 52)
    {
        return "MASTERCARD";
    }
    else if (i == 53 || i == 54)
    {
        return "MASTERCARD";
    }
    else if (i == 55)
    {
        return "MASTERCARD";
    }
    //AMEX
    else if (i == 34 || i == 37)
    {
        return "AMEX";
    }
    //VISA
    else if (cont + 1 == 13 && i / 10 == 4)
    {
        return "VISA";
    }
    else if (cont + 1 == 16 && i / 10 == 4)
    {
        return "VISA";
    }
    //INVALID
    else
    {
        return "INVALID";
    }
}