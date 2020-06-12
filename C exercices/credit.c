#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //reciving a valid number
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
}