#include <stdio.h>

void cough(void)
{
    printf("Cough\n");
}

int main(void)
{
    for(int i = 0; i < 3; i++)
    {
        cough();
    }
}

/* 
Versão alternativa

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Cough\n");
    }
}
*/
