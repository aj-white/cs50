#include <stdio.h>
#include <time.h>

int binary_search(int arr[], int first_index, int last_index, int search_item);

int main(void)
{
    int doors[] = {1,2,3,4,5,6};
    int door_len = sizeof(doors) / sizeof(doors[0]);
    int search = 2;
    
    clock_t t;
    t = clock();
    int result = binary_search(doors, 0, door_len - 1, search);
    t = clock() - t;
    double time_taken = ((double) t) / CLOCKS_PER_SEC;

    if (result == -1)
    {
        printf("Not behind doors\n");
    }
    else
    {
        printf("Found it at index %i\n", result);
        printf("It took %f seconds\n", time_taken);
    }
}

int binary_search(int arr[], int first_index, int last_index, int search_item)
{
    
    if (last_index >= first_index)
    {
        // Find the middle of array, works for any length
        int middle = (first_index + (last_index - first_index) / 2);
        
        if (arr[middle] == search_item)
        {
            return middle;
        }
        if (search_item < arr[middle])
        {
            return binary_search(arr, first_index, middle - 1, search_item);
        }
        else if (search_item > arr[middle])
        {
            return binary_search(arr, middle + 1, last_index, search_item);
        }
    }
    return -1;
}
