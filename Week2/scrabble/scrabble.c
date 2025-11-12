#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calculate_result(string x);

int main(void)
{
    // get input from player
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");

    // calculate each player's result
    int points_player_one = calculate_result(player_one);
    int points_player_two = calculate_result(player_two);

    // compare results
    if (points_player_one > points_player_two)
    {
        printf("Player 1 wins!\n");
    }
    else if (points_player_one < points_player_two)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_result(string x)
{
    int total = 0;
    for (int i = 0, len = strlen(x); i <= len; i++)
    {
        x[i] = toupper(x[i]);
        if (isupper(x[i]))
        {
            total += points[x[i] - 'A'];
        }
    }
    return total;
}

