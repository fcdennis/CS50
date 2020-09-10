#include<stdio.h>

typedef char *string;

int main(void)
{
    string name = "EMMA"; // usando o typedef
    char *surname = "MILLSTEIN"; // usando *
    printf("%s ", name);
    printf("%s\n", surname);
}