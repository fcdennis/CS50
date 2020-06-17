#include <stdio.h>
#include <cs50.h>

bool valid_triangule(float a, float b, float c);

int main (void)
{
    float x = get_float("Primeiro lado: ");
    float y = get_float("Segundo lado: ");
    float z = get_float("Terceiro lado: ");
    
    if (valid_triangule(x, y, z) == true)
    {
        printf("Valid triangule\n");
    }
    else
    {
        printf("Invalid triangule\n");
    }
}

bool valid_triangule(float a, float b, float c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }
    return true;
}