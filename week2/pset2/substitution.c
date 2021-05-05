/******************************************************************************

	@file		substitution.c

	@author		Julia Amadio

	@date		Created Sunday, 25 April 2021

	@brief		Execute the cipher with a 26 letters key

******************************************************************************/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int ft_only_alpha(string argv);
int ft_has_repetitions(string argv);

int main(int argc, string argv[])
{
    // Validing key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    else if (ft_only_alpha(argv[1]))
    {
        printf("Key must contain only alphabetics.\n");
        return (1);
    }
    else if (ft_has_repetitions(argv[1]))
    {
        printf("Key must not contain repetitions.\n");
        return (1);
    }
    printf("input valid!\n");

    string key = argv[1];
    // Getting plaintext from user
    string plain_text = get_string("plaintext: ");

    char cipher_text[strlen(plain_text)];
    for (int i = 0; plain_text[i] != '\0'; i++)
    {
        if (isupper(plain_text[i]))
        {
            cipher_text[i] = toupper(key[(plain_text[i] - 65) % 26]);
        }
        else if (islower(plain_text[i]))
        {
            cipher_text[i] = tolower(key[(plain_text[i] - 97) % 26]);
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[strlen(plain_text)] = '\0';
    printf("ciphertext: %s\n", cipher_text);
    return (0);
}

int ft_only_alpha(string argv)
{
    // Checking if only alphabetic
    for (int i = 0; argv[i] != '\0'; i++)
    {
        if (!isalpha(argv[i]))
        {
            return (1);
        }
    }
    return (0);
}

int ft_has_repetitions(string argv)
{
    // Checking for repetitions
    for (int i = 0; argv[i] != '\0'; i++)
    {
        for (int j = i + 1; argv[j] != '\0'; j++)
        {
            if (argv[i] == argv[j])
            {
                return (1);
            }
        }
    }
    return (0);
}

