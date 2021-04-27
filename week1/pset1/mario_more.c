/******************************************************************************

	@file		mario_more.c

	@author		Julia Amadio

	@date		Created Saturday, 24 April 2021

	@brief		Draw double pyramid of Mario

******************************************************************************/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Getting the height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Drawing pyramid
    int counter = 0;
    for (int i = 0; i < height; i++)
    {
        // Drawing first pyramid
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
                counter++;
            }
        }
        printf("  ");
        // Drawing inverted pyramid
        while (counter > 0)
        {
            printf("#");
            counter--;
        }
        printf("\n");
    }
}
