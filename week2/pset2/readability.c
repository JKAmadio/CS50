/******************************************************************************

	@file		readability.c

	@author		Julia Amadio

	@date		Created, Sunday 25 April 2021

	@brief		Calculate readability grade (Coleman-Liau index)

******************************************************************************/

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Getting input from the user
    string str = get_string("Text: ");

    // Counting the text characters
    int count_char = strlen(str);

    // Counters
    int count_sent = 0;
    int count_word = 1;
    int count_letter = 0;

    // Counting sentences, words and letters
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper(str[i]) || islower(str[i]))
        {
            count_letter++;
        }
        else if (str[i] == ' ')
        {
            count_word++;
        }
        else if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            count_sent++;
        }
    }

    // Index variable
    float L = (float)(100 * count_letter) / count_word;
    float S = (float)(100 * count_sent) / count_word;

    // Calculating the index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return (0);
}
