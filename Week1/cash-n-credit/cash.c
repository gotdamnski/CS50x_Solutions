#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change_owed;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int counter = 0;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 1);

    while (change_owed > 0)
    {
        if (change_owed - quarter >= 0)
        {
            change_owed = change_owed - quarter;
            counter++;
        }
        else if (change_owed - dime >= 0)
        {
            change_owed = change_owed - dime;
            counter++;
        }
        else if (change_owed - nickel >= 0)
        {
            change_owed = change_owed - nickel;
            counter++;
        }
        else if (change_owed - penny >= 0)
        {
            change_owed = change_owed - penny;
            counter++;
        }
    }
    printf("%i\n", counter);
}

