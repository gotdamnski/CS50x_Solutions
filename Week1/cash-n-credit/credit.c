#include <cs50.h>
#include <stdio.h>

int sum_even_func(long n);
int sum_odd_func(long n);

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number <= 0);

    long copy_for_length = card_number;
    int length = 0;
    while (copy_for_length != 0)
    {
        copy_for_length /= 10;
        length++;
    }

    long copy_for_sum = card_number;
    int checksum = 0;
    while (copy_for_sum != 0)
    {
        checksum += sum_even_func(copy_for_sum);
        checksum += sum_odd_func(copy_for_sum);
        copy_for_sum /= 100;
    }

    long first_two = card_number;
    while (first_two >= 100)
    {
        first_two /= 10;
    }
    int first_digit = first_two / 10;

    if (checksum % 10 == 0 && length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (checksum % 10 == 0 && length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (checksum % 10 == 0 && (length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int sum_even_func(long n)
{
    int sum_even = 0;
    n /= 10;
    int even = n % 10;
    even *= 2;
    if (even > 9)
    {
        sum_even += (even / 10) + (even % 10);
    }
    else
    {
        sum_even += even;
    }
    return sum_even;
}

int sum_odd_func(long n)
{
    int sum_odd = 0;
    int odd = n % 10;
    sum_odd += odd;
    return sum_odd;
}

