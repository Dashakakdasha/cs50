/*
* Water
*
* Written by Ankit R Gadiya
* CS50 Pset1
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    int min = get_int();
    int bottle = min * 12;
    printf("Bottles: %i\n", bottle);
}
