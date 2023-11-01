#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Set each color channel to the average of the 3 color channels
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //Swap Mirroring pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Copy Image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float counter = 0.00;

            //Get neighboring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //Check if pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //Get the sum of neighboring pixels
                    totalRed += temp[currentX][currentY].rgbtRed;
                    totalGreen += temp[currentX][currentY].rgbtGreen;
                    totalBlue += temp[currentX][currentY].rgbtBlue;
                    counter++;
                }
            }

            //Put new values back into image
            image[i][j].rgbtRed = round(totalRed / counter);
            image[i][j].rgbtGreen = round(totalGreen / counter);
            image[i][j].rgbtBlue = round(totalBlue / counter);

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Copy Image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    //Convolution Matrix
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 1, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed, gyRed, gxGreen, gyGreen, gxBlue, gyBlue;
            gxRed = gyRed = gxGreen = gyGreen = gxBlue = gyBlue = 0;

            //Get neighboring pixels
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int currentX = i - 1 + x;
                    int currentY = j - 1 + y;

                    //Check if pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //Calculate Gx and Gy of each color channel
                    gxRed += (temp[currentX][currentY].rgbtRed * Gx[x][y]);
                    gyRed += (temp[currentX][currentY].rgbtRed * Gy[x][y]);
                    gxGreen += (temp[currentX][currentY].rgbtGreen * Gx[x][y]);
                    gyGreen += (temp[currentX][currentY].rgbtGreen * Gy[x][y]);
                    gxBlue += (temp[currentX][currentY].rgbtBlue * Gx[x][y]);
                    gyBlue += (temp[currentX][currentY].rgbtBlue * Gy[x][y]);
                }
            }

            //Calculate Sobel operator
            int red = round(sqrt((gxRed * gxRed) + (gyRed * gyRed)));
            if (red > 255)
            {
                red = 255;
            }
            int green = round(sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));
            if (green > 255)
            {
                green = 255;
            }
            int blue = round(sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));
            if (blue > 255)
            {
                blue = 255;
            }

            //Put new values back into image
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;

        }
    }    
    return;
}
