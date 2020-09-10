#include "helpers.h"
#include<math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixels = image[i][j]; // pixels map
            int average = round((pixels.rgbtRed + pixels.rgbtGreen + pixels.rgbtBlue) / 3.0); // average of rgb color, so grayscale can be made
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average; //substitution of origianl color by grayscale color
        }
    }
}

// Reflect image horizontally
// Swap a value in a pixel for another value from other pixel
void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]); // calls the swap function so the pixel in [i][j] position is swap for its counterpart
        }
    }
}

//found out if the pixel is valed for the blur calculus
bool is_valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

// Blur image
//Blur a single pixel
RGBTRIPLE blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redDensityValue = 0; // Density values of red
    int greenDensityValue = 0; // Density value og green
    int blueDensityValue = 0; // Density value of blue
    int numOfValidPixels = 0; // a counter for valid pixels

    //a iteration for the amount of each color
    for (int bi = -1; bi <= 1; bi++)
    {
        for (int bj = -1; bj <= 1; bj++)
        {
            int new_i = i + bi;
            int new_j = j + bj;
            if (is_valid_pixel(new_i, new_j, height, width))
            {
                numOfValidPixels++;
                redDensityValue += image[new_i][new_j].rgbtRed;
                blueDensityValue += image[new_i][new_j].rgbtBlue;
                greenDensityValue += image[new_i][new_j].rgbtGreen;
            }
        }
    }

    //definig the Blur pixel
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float)redDensityValue / numOfValidPixels);
    blurred_pixel.rgbtGreen = round((float)greenDensityValue / numOfValidPixels);
    blurred_pixel.rgbtBlue = round((float)blueDensityValue / numOfValidPixels);
    return blurred_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Creat a blured copy of the image
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = blurred_pixel(i, j, height, width, image);
        }
    }

    //blur the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
}

// Detect edges
int ceiling(int densityValue)
{
    return densityValue > 255 ? 255 : densityValue; // Return a 255 maximum density Value for sepia color
}

RGBTRIPLE edge_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int redValueX = 0;
    int greenValueX = 0;
    int blueValueX = 0;
    int redValueY = 0;
    int greenValueY = 0;
    int blueValueY = 0;
    
    for(int di = -1; di <= 1; di++)
    {
        for(int dj = -1; dj <= 1; dj++)
        {
            if(is_valid_pixel(i +di, i + dj, height, width))
            {
                int weightX = Gx[di + 1][dj + 1];
                redValueX += weightX * image[i + di][j + dj].rgbtRed;
                greenValueX += weightX * image[i + di][j + dj].rgbtGreen;
                blueValueX += weightX * image[i + di][j + dj].rgbtBlue;
                
                int weightY = Gx[dj + 1][di + 1];
                redValueY += weightY * image[i + di][j + dj].rgbtRed;
                greenValueY += weightY * image[i + di][j + dj].rgbtGreen;
                blueValueY += weightY * image[i + di][j + dj].rgbtBlue;
            }
        }
    }
    RGBTRIPLE pixel;
    pixel.rgbtRed = ceiling(round(sqrt(redValueX * redValueX + redValueY * redValueY)));
    pixel.rgbtGreen = ceiling(round(sqrt(greenValueX * greenValueX + greenValueY * greenValueY)));
    pixel.rgbtRed = ceiling(round(sqrt(blueValueX * blueValueX + blueValueY * blueValueY)));
    
    return pixel;
    
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            new_image[i][j] = edge_pixel(i, j, height, width, image);
        }
    }
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
}