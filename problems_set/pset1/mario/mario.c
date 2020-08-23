#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Getting the Height from the user
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    
    int w = h - 1;
    for (int i = 0; i < h; i++)
    {
        //Constructing the pyramid
        //First, create blank spaces
        for (int j = w; j > 0; j--)
        {
            printf(" ");
        }
        w--;
        
        //now put some bricks
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
         
        //The gap
        printf("  ");
        
        //The inverted pyramid
        for (int y = 0; y <= i; y++)
        {
            printf("#");
        }
        
        //The break line
        printf("\n");
    }
}