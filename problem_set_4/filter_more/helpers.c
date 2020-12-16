#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Helper function to calcuate final Sobel value
int calc_sobel(int gx, int gy)
{
    int sobel = round(
        sqrt(
            (pow(gx,2) + pow(gy,2))
        )
    );
    int limited = (sobel < 255) ? sobel:255;
    return limited;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Inistialise convolutional arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0 ,1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2 ,1}};
    
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue_gx = 0, blue_gy = 0;
            int green_gx = 0, green_gy = 0;
            int red_gx = 0, red_gy =0;
            
			 // iterate over 3x3 grid round each pixel
            for (int k = -1; k < 2; k++)
			{
				// Skips iteration if index out of bounds for rows
                if (i + k < 0 || (i + k > height - 1))
                {
                    continue;
                }
                for (int m = -1; m < 2; m++)
                {
                    // Skips iteration if index out of bounds for columns
                    if (j + m < 0 || j + m > width -1)
                    {
                        continue;
                    }
                    blue_gx += image[i + k][j + m].rgbtBlue * Gx[k+1][m+1];
                    blue_gy += image[i + k][j + m].rgbtBlue * Gy[k+1][m+1];
                    green_gx += image[i + k][j + m].rgbtGreen * Gx[k+1][m+1];
                    green_gy += image[i + k][j + m].rgbtGreen * Gy[k+1][m+1];
                    red_gx += image[i + k][j + m].rgbtRed * Gx[k+1][m+1];
                    red_gy += image[i + k][j + m].rgbtRed * Gy[k+1][m+1];
                }
                
            }
            temp[i][j].rgbtBlue = calc_sobel(blue_gx, blue_gy);
            temp[i][j].rgbtGreen = calc_sobel(green_gx, green_gy);
            temp[i][j].rgbtRed = calc_sobel(red_gx, red_gy);

           
        }
    }
    // Replaces image values with values from temp rgbtriple
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
        
    }
    return;
}


