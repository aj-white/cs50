#include <stdio.h>

int main(void)
{
    // Get height from user
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    }
    while (height < 1 || height > 8);

    // Draw pyramid
    for (int row = 1; row <= height; row += 1)
    {
        // Number of spaces printed is height - row
        printf("%*s", height - row, "");
        for (int column = 0;column < row; column += 1)
        {
            printf("#");
        }
        printf("\n");
    }
}
