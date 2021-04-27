/******************************************************************************

	@file		mario_less.c

	@author		Julia Amadio

	@date		Created Saturday, 24 April 2021

	@brief		Draw single pyramid of Mario

******************************************************************************/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting the pyramid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Drawing pyramid
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
