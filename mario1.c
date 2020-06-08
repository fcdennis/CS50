#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int linha = get_int("Height? ");
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}