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
                    int neighbor_i = i + offset_i;
                    int neighbor_j = j + offset_j;

                    if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 &&
                        neighbor_j < width)
                    {
                        red += copy[neighbor_i][neighbor_j].rgbtRed;
                        green += copy[neighbor_i][neighbor_j].rgbtGreen;
                        blue += copy[neighbor_i][neighbor_j].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float) red / count);
            image[i][j].rgbtGreen = round((float) green / count);
            image[i][j].rgbtBlue = round((float) blue / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_x = 0, green_x = 0, blue_x = 0;
            int red_y = 0, green_y = 0, blue_y = 0;


            for (int offset_i = -1; offset_i <= 1; offset_i++)
            {
                for (int offset_j = -1; offset_j <= 1; offset_j++)
                {
                    int neighbor_i = i + offset_i;
                    int neighbor_j = j + offset_j;

                    if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 &&
                        neighbor_j < width)
                    {
                        int weight_x = Gx[offset_i + 1][offset_j + 1];
                        int weight_y = Gy[offset_i + 1][offset_j + 1];

                        red_x += copy[neighbor_i][neighbor_j].rgbtRed * weight_x;
                        green_x += copy[neighbor_i][neighbor_j].rgbtGreen * weight_x;
                        blue_x += copy[neighbor_i][neighbor_j].rgbtBlue * weight_x;

                        red_y += copy[neighbor_i][neighbor_j].rgbtRed * weight_y;
                        green_y += copy[neighbor_i][neighbor_j].rgbtGreen * weight_y;
                        blue_y += copy[neighbor_i][neighbor_j].rgbtBlue * weight_y;
                    }
                }
            }
            int sobel_red = round(sqrt(red_x * red_x + red_y * red_y));
            int sobel_green = round(sqrt(green_x * green_x + green_y * green_y));
            int sobel_blue = round(sqrt(blue_x * blue_x + blue_y * blue_y));

            if(sobel_red > 255)
            {
                sobel_red = 255;
            }
            if(sobel_green > 255)
            {
                sobel_green = 255;
            }
            if(sobel_blue > 255)
            {
                sobel_blue = 255;
            }
            image[i][j].rgbtRed = sobel_red;
            image[i][j].rgbtGreen = sobel_green;
            image[i][j].rgbtBlue = sobel_blue;
        }
    }
    return;
}

