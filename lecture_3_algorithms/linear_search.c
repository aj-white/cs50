#include <stdio.h>
#include <time.h>
// Turn pseudocode into C code

// Pseudocode
// For i from 0 to n -1
    // If number behind i'th door
        // Return True
// Return False

// Final array is to return multiple values from function
int linear_search(int a[], int size, int x, int arr[]);

int main(void)
{
    // Initialise number array
    int doors[8] = {3, 5, 2, 6, 4, 8, 0};
    int search_item;
    clock_t t;
    // Get user search item
    printf("Enter a number: ");
    scanf("%i", &search_item);

    int arr[2];
    t = clock();
    int result = linear_search(doors, 8, search_item, arr);
    t = clock() - t;
    double time_taken = ((double) t)/CLOCKS_PER_SEC;
    if (arr[0] == 1)
    {
        printf("Found it\n");
        printf("It took %i steps and %f seconds\n", arr[1], time_taken);
    }
    else if (arr[0] == 0)
    {
        printf("Not there\n");
        printf("It took %i steps\n", arr[1]);
        
    }
    else
    {
        printf("Hmm something weird happened\n");
    }
}

int linear_search(int a[], int size, int x, int arr[])
{
    int steps = 0;
    arr[0] = 0;
    for (int i = 0; i < size; i++)
    {
        steps += 1;
        if (a[i] == x)
        {
            arr[0] = 1;
            arr[1] = steps;
            break;
        }
    }
    arr[1] = steps;
    
}
