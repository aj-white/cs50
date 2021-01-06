#include <cs50.h>
#include <stdio.h>

// Define minimum population size
#define MIN_SIZE 9

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < MIN_SIZE);
    

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    
    // TODO: Print number of years
    printf("Years: %d\n", years);
    return 0;
    
}
