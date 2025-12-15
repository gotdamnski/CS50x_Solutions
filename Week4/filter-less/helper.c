#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg_pix_value =
                (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(avg_pix_value);
            image[i][j].rgbtGreen = round(avg_pix_value);
            image[i][j].rgbtRed = round(avg_pix_value);
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
            // i know, this is awful realization
            float sepiaRed = (image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) +
                             (image[i][j].rgbtBlue * 0.189);
            float sepiaGreen = (image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) +
                               (image[i][j].rgbtBlue * 0.168);
            float sepiaBlue = (image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) +
                              (image[i][j].rgbtBlue * 0.131);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0, green = 0, blue = 0;
            int count = 0;

            for (int offset_i = -1; offset_i <= 1; offset_i++)
            {
                for (int offset_j = -1; offset_j <= 1; offset_j++)
                {
                    int neighbour_i = i + offset_i;
                    int neighbour_j = j + offset_j;

                    if (neighbour_i >= 0 && neighbour_i < height && neighbour_j >= 0 &&
                        neighbour_j < width)
                    {
                        red += copy[neighbour_i][neighbour_j].rgbtRed;
                        green += copy[neighbour_i][neighbour_j].rgbtGreen;
                        blue += copy[neighbour_i][neighbour_j].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float) red / count);
            image[i][j].rgbtGreen = round((float) green / count);
            image[i][j].rgbtBlue = round((float) blue / count);
        }
    }
}

