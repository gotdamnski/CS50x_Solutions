#include <cs50.h>
#include <stdio.h>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1


int main(void)
{
    int change_owed;
    int counter = 0;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 1);

    while (change_owed > 0)
    {
        if (change_owed - QUARTER >= 0)
        {
            change_owed = change_owed - QUARTER;
            counter++;
        }
        else if (change_owed - DIME >= 0)
        {
            change_owed = change_owed - DIME;
            counter++;
        }
        else if (change_owed - NICKEL >= 0)
        {
            change_owed = change_owed - NICKEL;
            counter++;
        }
        else if (change_owed - PENNY >= 0)
        {
            change_owed = change_owed - PENNY;
            counter++;
        }
    }
    printf("%i\n", counter);
}

