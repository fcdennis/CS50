#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while(h <1 || h >8);
    
    int w = h - 1;
    for(int i = 0; i <h; i++)
    {
        for(int j =w; j >0; j--)
        {
            printf(" ");
        }
        w--;
        for(int l =0; l <=i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}