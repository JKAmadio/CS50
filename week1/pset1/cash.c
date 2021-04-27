/******************************************************************************

	@file		cash.c

	@author		Julia Amadio

	@date		Created Saturday, 24 April 2021

	@brief		Count the number of coins for the passed change

******************************************************************************/

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //Getting the value of the change
    float change;
    do
    {
        change = get_float("Change owned: ");
    }
    while (change < 0);

    // Transforming the change into cents
    int change_cents = round(change * 100);

    int coins = 0;

    // Counting 25cents coins
    while (change_cents >= 25)
    {
        coins = coins + change_cents / 25;
        change_cents %= 25;
    }

    // Counting 10cents coins
    while (change_cents >= 10)
    {
        coins = coins + change_cents / 10;
        change_cents %= 10;
    }

    // Counting 5cents coins
    while (change_cents >= 5)
    {
        coins = coins + change_cents / 5;
        change_cents %= 5;
    }

    // Counting 1cent coins
    while (change_cents >= 1)
    {
        coins = coins + change_cents / 1;
        change_cents %= 1;
    }
    printf("%i\n", coins);
}
