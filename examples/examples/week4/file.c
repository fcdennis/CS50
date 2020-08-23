#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    //Open a File
    FILE *file = fopen("phonebook.csv", "a");

    //Get strings from user
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    //Print the strings
    fprintf(file, "%s,%s\n", name, number);

    //Close the file
    fclose(file);
}