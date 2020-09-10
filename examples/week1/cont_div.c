#include <stdio.h>
#include <cs50.h>

int cont_div(int numero, int divisor, int contador);
int main(void)
{
    int a = 1000000, b = 10, c = 0;
    int contagem = cont_div(a, b, c);
    printf("%i\n", contagem);
}

//Função que define quantas vezes um número pode ser dividido por um outro número
int cont_div(int numero, int divisor, int contador)
{
    do
    {
        numero /= divisor;
        contador++;
    }
    while(numero > 1);
    return contador;
}