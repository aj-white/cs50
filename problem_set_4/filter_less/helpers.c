#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;
            int r = image[i][j].rgbtRed;

            int avg = round((b + g + r) / 3.0);

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }

    }    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;
            int r = image[i][j].rgbtRed;

            int sepia_blue = round((0.272 * r) + (0.534 * g) + (0.131 * b));
            int limit_blue = sepia_blue < 255 ? sepia_blue : 255;

            int sepia_green = round((0.349 * r) + (0.686 * g) + (0.168 * b));
            int limit_green = sepia_green < 255 ? sepia_green : 255;

            int sepia_red = round((0.393 * r) + (0.769 * g) + (0.189 * b));
            int limit_red = sepia_red < 255 ? sepia_red : 255;


                       
            image[i][j].rgbtBlue = limit_blue;
            image[i][j].rgbtGreen = limit_green;
            image[i][j].rgbtRed = limit_red;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = width/2;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width - (j+1)] = temp;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporary rgbtriple to store averages so does not affect maths in original
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue_total = 0;
            int green_total = 0;
            int red_total = 0;
            int count = 0;
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
                    blue_total += image[i + k][j + m].rgbtBlue;
                    green_total += image[i + k][j + m].rgbtGreen;
                    red_total += image[i + k][j + m].rgbtRed;
                    count ++;
                }                   
            }
            
            temp[i][j].rgbtBlue = round(blue_total/(float) count);
            temp[i][j].rgbtGreen = round(green_total/(float) count);
            temp[i][j].rgbtRed = round(red_total/(float) count);
            
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
