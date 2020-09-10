#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string namesList[4] = {"EMMA", "RODRIGO", "MARIA", "DAVID"};
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(namesList[i], "EMMA") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
}