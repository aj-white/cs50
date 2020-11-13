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
    for (int lrow = 1; lrow <= height; lrow += 1)
    {
        // Number of spaces printed is height - row
        printf("%*s", height - lrow, "");
        for (int lcolumn = 0;lcolumn < lrow; lcolumn += 1)
        {
            printf("#");
        }
        printf("  ");
        for (int rcolumn = 0; rcolumn < lrow; rcolumn += 1)
        {
            printf("#");
        }
        printf("\n");

    }
}
