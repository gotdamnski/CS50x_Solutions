#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool argv_number_check(string argv);
char rotate(char c, int i);


int main(int argc, string argv[])
{
    // key validation
    if (argc == 2 && argv_number_check(argv[1]))
    {
        // convert key from string to int
        int key = atoi(argv[1]);

        // get plain text from user
        string plain_text = get_string("plaintext:  ");

        // cipher text
        printf("ciphertext: ");
        for (int i = 0, len = strlen(plain_text); i < len; i++)
        {
            char c = rotate(plain_text[i], key);
            printf("%c", c);
        }
        printf("\n");

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}



bool argv_number_check(string argv)
{
    for (int i = 0, len = strlen(argv); i < len; i++)
    {
        if (!isdigit(argv[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int i)
{
    if(isalpha(c))
    {
        if(isupper(c))
        {
            c = ((c - 'A' + i) % 26) + 'A';
        }
        else if(islower(c))
        {
            c = ((c - 'a' + i) % 26) + 'a';
        }
    }
    else
    {
        return c;
    }
    return c;
}
