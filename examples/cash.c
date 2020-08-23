#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //show me the money
    int cents;
    do
    {
        cents = get_int("How many cents of change? ");
    }
    while (cents < 0 || cents > 100);

    //Calculete the change owed
    int quarters = cents / 25;
    int rest_quarters = cents % 25;
    int dimes = rest_quarters / 10;
    int rest_dimes = rest_quarters % 10;
    int nickels = rest_dimes / 5;
    int pennies = rest_dimes % 5;
    int coins = quarters + dimes + nickels + pennies;
    printf("Total of %i, %i coins of quarters, %i coins of dimes, %i coins of nickles, and %i coins of pennies\n", coins, quarters, dimes, nickels, pennies);
}