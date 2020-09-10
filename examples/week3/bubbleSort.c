#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int unsortedNumbers[9] = {9, 5, 4, 6, 3, 7, 2, 8, 1 };
    int aux;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (unsortedNumbers[i] < unsortedNumbers[j])
            {
                aux = unsortedNumbers[j];
                unsortedNumbers[j] = unsortedNumbers[i];
                unsortedNumbers[i] = aux;
            }
        }
    }
    //Print the Sorted List
    for (int k = 0; k < 9; k++)
    {
        printf("%d", unsortedNumbers[k]);
    }
    printf("\n");
}