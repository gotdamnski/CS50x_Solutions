#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompting user for some text
    string text = get_string("Text: ");

    // counting letters, words, sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // counting letters and sentences ratio per 100 words
    float L = (float) letters / words * 100.0;
    float S = (float) sentences / words * 100.0;

    // use Coleman-Liau Index to calculate grade 'index = 0.0588 * L - 0.296 * S - 15.8'
    float CLindex = 0.0588 * L - 0.296 * S - 15.8;

    // printing grade with rounding
    if (CLindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (CLindex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(CLindex));
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

