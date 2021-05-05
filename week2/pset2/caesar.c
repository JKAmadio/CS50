/******************************************************************************

	@file		caesar.c

	@author		Julia Amdio

	@date		Created Sunday, 25 April 2021

	@brief		implement caesar cipher with user input

******************************************************************************/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string LOWER = "abcdefghijklmnopqrstuvwxyz";

int ft_check_chars(string argv);

int main(int argc, string argv[])
{
    // Input validation
    if (argc != 2 || ft_check_chars(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }

    // Taking user input
    string plain_text = get_string("plaintext: ");

    int k = atoi(argv[1]);
    int index;
    char cipher_text[strlen(plain_text)];

    // Changing characters (only if they are letters)
    for (int i = 0; plain_text[i] != '\0'; i++)
    {
        // case if they are uppercase
        if (isupper(plain_text[i]))
        {
            index = plain_text[i] - 65;
            cipher_text[i] = UPPER[(index + k) % 26];
        }
        // case if they are lowercase
        else if (islower(plain_text[i]))
        {
            index = plain_text[i] - 97;
            cipher_text[i] = LOWER[(index + k) % 26];
        }
        // case if they aren't letters
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    printf("ciphertext: %s\n", cipher_text);
    return (0);
}

int ft_check_chars(string argv)
{
    int is_not_number = 0;
    for (int i = 0; argv[i] != '\0'; i++)
    {
        if (argv[i] < '0' || argv[i] > '9')
        {
            is_not_number++;
            return (1);
        }
    }
    return (0);
}
