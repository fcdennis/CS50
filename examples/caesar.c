//lots of libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//main need a command line
int main(int argc, string argv[])
{
    //first verifying if there're more or less than 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //verifying if the second argument is valid
    else
    {
        string validation_k = argv[1];
        int valid = 0;
        for (int i = 0, len = strlen(validation_k); i < len; ++i)
        {
            if (isdigit(validation_k[i]))
            {
                valid += 0;
            }
            else
            {
                valid++;
            }
        }
        //if is invalid you recive a fail mensage
        if (valid > 0)
        {   
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //if is valid you can enter the plaintext
        else
        {
            string plaintext = get_string("plaintext: ");
            int k = atoi(validation_k);
            char cyphertext;
            printf("ciphertext: ");
            for (int j = 0, len_pt = strlen(plaintext); j < len_pt; j++)
            {
                if (isalpha(plaintext[j]))
                {
                    cyphertext = plaintext[j];
                    //Encoding the capital letters
                    if (cyphertext < 91)
                    {
                        for (int y = 0; y < k; y++)
                        {
                            cyphertext++;
                            if (cyphertext > 90)
                            {
                                cyphertext = 65;
                            }
                        }
                    }
                    //encoding the small letters
                    else
                    {
                        for (int x = 0; x < k; x++)
                        {
                            cyphertext++;
                            if (cyphertext > 122)
                            {
                                cyphertext = 97;
                            }
                        }
                    }
                    printf("%c", cyphertext);
                }
                //printing numbers and signs
                else
                {
                    printf("%c", plaintext[j]);
                }
            }
        }
    }
    printf("\n");
    return 0;
}