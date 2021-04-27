/******************************************************************************

	@file		credit.c

	@author		Julia Amadio

	@date		Created Saturday, 24 April 2021

	@brief		Check if credit card is valid or not

******************************************************************************/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Getting number of the credit card
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    // Validing only card_numbers with 13 to 16 digits
    if (card_number / 1000000000000 < 1 || card_number / 1000000000000 > 9999)
    {
        printf("INVALID\n");
        return (0);
    }

    long aux = card_number;
    int i = 0;
    int even = 0;
    int odd = 0;
    int odd_ten;
    int odd_unit;
    int odd_total = 0;
    int last_sum;

    //Sums
    while (aux > 0)
    {
        if (i % 2 == 0)
        {
            even = even + aux % 10;
        }
        else
        {
            odd = aux % 10;
            odd *= 2;
            if (odd > 9)
            {
                odd_ten = odd / 10;
                odd_unit = odd % 10;
                odd = odd_ten + odd_unit;
            }
            odd_total += odd;
        }
        i++;
        aux /= 10;
    }
    last_sum = odd_total + even;
    if (last_sum % 10 != 0)
    {
        printf("INVALID\n");
        return (0);
    }

    // Checking possible type (AMEX, MASTER, VISA or none)
    if (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37)
    {
        printf("AMEX\n");
    }
    else if (card_number / 100000000000000 >= 51 && card_number / 100000000000000 <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (card_number / 1000000000000 == 4 || card_number / 1000000000000000 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return (0);
    }
    return (0);
}
