/******************************************************************************

	@file		hello.c

	@author		Julia Amadio

	@date		Created Saturday, 24 April 2021

	@brief		Greet user with "Hello, <user_name>"

******************************************************************************/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //getting user name
    string name = get_string("What's your name?\n");

    //greet user
    printf("hello, %s\n", name);
}
