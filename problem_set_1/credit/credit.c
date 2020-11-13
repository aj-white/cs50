#include <stdio.h>

int get_length(long n);
int get_first_sum(long n);
int get_second_sum(long n);


int main(void)
{
    long cc_no;
    printf("Credit Card Number: ");
    scanf("%li", &cc_no);

    // First part of checksum
    int first_sum = get_first_sum(cc_no);

    // Second part of checksum
    int second_sum = get_second_sum(cc_no);

    //Final validation
    int checksum = first_sum + second_sum;
    if (checksum % 10 == 0)
    {
        int length = get_length(cc_no);
        
        // Get frist 2 numbers
        long first_two_digits = cc_no;
        while (first_two_digits >= 100)
        {
            first_two_digits /= 10;
        }
        if ((length == 15) & (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 16) & (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) & ((first_two_digits/10) % 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
   
}

int get_length(long n)
{
    int length = 0;
    while (n > 0)
    {
        n /= 10;
        length += 1;
    }
    return length;
}

int get_first_sum(long n)
{
    long start_digit = n / 10;
    int sum = 0;

    while (start_digit > 0)
    {
        int digit = (start_digit % 10) * 2;
        // Split numbers into rpoducts if over 10
        if (digit > 1)
        {
            sum += (digit / 10) % 10;
            sum += digit % 10;
        }
        else
        {
            sum += digit;
        }
        start_digit /= 100;
    }
    return sum;
}

int get_second_sum(long n)
{
    int sum = 0;
    while (n > 1)
    {
        int digit = n % 10;
        sum += digit;
        n /= 100;
    }
    return sum;

}
