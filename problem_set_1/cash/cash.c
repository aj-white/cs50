#include <stdio.h>
#include <math.h>


int main(void)
{
    // Get change amount in dollars
    float change_in_dollars;
    do
    {
        printf("Change amount: ");
        scanf("%f", &change_in_dollars);
    }
    while (change_in_dollars < 0);
    
    // Convert dollar into cents
    int change_in_cents = round(change_in_dollars * 100);
    
    // Create coin values
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // Coin counter
    int coins = 0;
    
    int change_remaining = change_in_cents;

    while (change_remaining !=0)
    {
        if (change_remaining >= quarter)
        {
            change_remaining -= quarter;
            coins +=1;
        }
        else if (change_remaining >= dime)
        {
            change_remaining -= dime;
            coins += 1;
        }
        else if (change_remaining >= nickel)
        {
            change_remaining -= nickel;
            coins += 1;
        }
        else if (change_remaining >= penny)
        {
            change_remaining -= penny;
            coins += 1;
        }      
        
    }
    printf("%i", coins);
        

}
