//Order a list of numbers by bubble sort
#include <stdio.h>
#include <stdlib.h>

void bubble (int a[], int b);

int main(int argc, char *argv[])
{
    //Verifing the requesits for program to run
    if (argc != 2)
    {
        printf("./bubble n\n");
        return 1;
    }
    
    int elements = atoi(argv[1]);
    printf("Programa ordena %d números fornecidos pelo usuário.\n", elements);
    //Getting the number from the user
    int numbers[elements];
    for (int i = 0; i < elements; i++)
    {
        printf("Digite o %d° número: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    //Printing the unordered number list
    printf("\nLista dos números digitados antes da ordenação: \n");
    for (int k= 0; k < elements; k++)
    {
        printf(" %d -", numbers[k]);
    }
    printf(" END\n");
    
    //Ordering the numbers
    bubble(numbers, elements);
    
    //Printing the ordered numbers list
    printf("\nLista dos números digitados após a ordenação: \n");
    for (int j = 0; j < elements; j++)
    {
        printf(" %d -", numbers[j]);
    }
    printf(" END\n\n");
    
}

//Function that order numbers by bubble sort
void bubble (int a[], int b)
{
    int temp;
    for (int i = 0; i < b; i++)
    {
        for(int j = 0; j < b - 1; j++)
        {
            if (a[j] > a[j +1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}