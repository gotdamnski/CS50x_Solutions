#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_key_valid(string s);
int is_duplicate(string s);
string substitution_cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || is_key_valid(argv[1]) == 1)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext:  ");
    string ciphertext = substitution_cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

int is_key_valid(string s)
{
    int len = strlen(s);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            printf("Key must only contain alphabetical characters.\n");
            return 1;
        }
        if (is_duplicate(s) == 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    return 0;
}

int is_duplicate(string s)
{
    int duplicate[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        int letter = toupper(s[i]) - 'A';
        duplicate[letter]++;
        if (duplicate[letter] > 1)
        {
            return 1;
        }
    }
    return 0;
}

string substitution_cipher(string plaintext, string key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(key[plaintext[i] - 'a']);
        }
    }
    return plaintext;
}

