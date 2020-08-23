#include <stdio.h>
#include <cs50.h>

int factorial(int n);
int main()
{
    int number = get_int("Digite um número inteiro: ");
    int fact = factorial(number);
    printf("%d\n", fact);
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n-1);
}