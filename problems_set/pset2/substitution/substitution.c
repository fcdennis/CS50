#include <stdio.h> //printf
#include <cs50.h> //get_string
#include <ctype.h> //isalpha toupper tolower
#include <string.h> //strlen

int alphaValidation(string argument);
int duplicated(string argument);

int main(int argc, string argv[])
{
    //Verificando se há dois argumentos
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Verificando se o segundo argumento tem 26 caracteres
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Verificando se são 26 caracteres alfabéticos
    else if (alphaValidation(argv[1]) != 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Verificando se há duplicados
    else if (duplicated(argv[1]) == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Parte principal
    else
    {
        //Chamando o plaintext
        string pt = get_string("plaintext: ");
        int cont = 0;
        printf("ciphertext: ");
        //Iniciando a decodificação
        for (int i = 0, len = strlen(pt); i < len; i++)
        {
            //Verificando se é um caractere alfabético
            if (isalpha(pt[i]))
            {
                //Maiusculas
                if (pt[i] < 91)
                {
                    while (pt[i] > 65)
                    {
                        pt[i]--;
                        cont++;
                    }
                    printf("%c", toupper(argv[1][cont]));
                    cont = 0;
                }
                //Minusculas
                else
                {
                    while (pt[i] > 97)
                    {
                        pt[i]--;
                        cont++;
                    }
                    printf("%c", tolower(argv[1][cont]));
                    cont = 0;
                }
            }
            //Caracteres não alfabeticos
            else
            {
                printf("%c", pt[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

int alphaValidation(string argument) //Verifica se há 26 caracteres alfabéticos
{
    int valid = 0;
    for (int j = 0, lenV = strlen(argument); j < lenV; j++)
    {
        if (isalpha(argument[j]))
        {
            valid += 0;
        }
        else
        {
            valid++;
        }
    }
    return valid;
}

int duplicated(string argument) //verifica se há duplicados
{
    for (int k = 0, lenD = strlen(argument); k < lenD; k++)
    {
        int unic = 0;
        for (int l = 0; l < lenD; l++)
        {
            if (argument[k] == argument [l])
            {
                unic++;
            }
        }
        if (unic != 1)
        {
            return 1;
        }
    }
    return 0;
}