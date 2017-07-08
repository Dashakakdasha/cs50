/*
* Greedy (less comfortable)
*
* Written by Ankit R Gadiya
* CS50 Pset1
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float change;
    // Makes sure input is +ve
    do
    {
        printf("Change: ");
        change = get_float();
    }
    while(change <= 0);

    // Greedy cashier here
    change = (change * 100) + 0.1;
    int cents = change;

    int coins = 0;

    for (int i = 0; cents > 0; i++)
    {

        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents <= 25 && cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }
        else if (cents <= 10 && cents >= 5)
        {
            cents = cents - 5;
            coins++;
        }
        else
        {
            cents = cents - 1;
            coins++;
        }
    }


    printf("%i\n", coins);
}
