#include <stdio.h>
#include <cs50.h>

void print_space(int n);
void print_hash(int n);

int main(void)
{
    int pyramid_height;
    do
    {
        pyramid_height = get_int("Hight: ");
    }
    while (pyramid_height < 1 || pyramid_height > 8);

    for (int row = 1; row <= pyramid_height; row++)
    {
        print_space(pyramid_height - row);
        print_hash(row);
        printf("  ");
        print_hash(row);
        printf("\n");
    }
}

void print_space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_hash(int n)
{
    for (int k = 0; k < n; k++)
    {
        printf("#");
    }
}


