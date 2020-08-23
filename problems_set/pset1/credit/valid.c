#include <stdio.h>
#include <cs50.h>

long valid_number(long number);
int main(void)
{
    long number = valid_number();
}

long valid_number(long number)
{
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    return number
}