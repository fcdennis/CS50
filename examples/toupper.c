//Capitalizes a copy of a string

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    //Get a string
    char *l = get_string("l: ");
    
    //Allocate memory for another string
    char *t = malloc(strlen(l) + 1);
    
    //Copy string into memory
    strcpy(t,l);

    //Capitalize copy
    t[0] = toupper(t[0]);
    
    //Print strings
    printf("l: %s\n", l);
    printf("u: %s\n", t);
}