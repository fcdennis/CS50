#include <stdio.h>

int main(void)
{
    char name[] = get_string("Digite seu nome: ");
    printf("Hello, %s\n", name);
}