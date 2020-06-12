#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float price = get_float ("What's the base price?\n");
    float tax = get_float ("what's the tax cut?\n");
    float final_price = price + (price * tax / 100);
    printf("The consumer price will be US$%.2f\n", final_price);
}