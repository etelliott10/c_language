#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bmp.h"
#include <time.h>
#include <stdint.h>

#define STBI_RGB_TO_BGR
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h" 


void grayscale(int height, int width, RGBTRIPLE image[height][width]);
void sepia(int height, int width, RGBTRIPLE image[height][width]);
void reflect(int height, int width, RGBTRIPLE image[height][width]);
void blur(int height, int width, RGBTRIPLE image[height][width]);
void edge(int height, int width, RGBTRIPLE image[height][width]);

int main(void){  
   int width = 0, height = 0, channels = 0;
    const char *img_path = "example.jpg";
    // const char *output_path = "example_grayscale.jpg"; 
    // const char *output_path = "example_sepia.jpg"; 
    // const char *output_path = "example_reflect.jpg"; 
    const char *output_path = "example_blur.jpg"; 




    // Load raw pixels forcing 3 channels (RGB)
    unsigned char *raw_pixels = stbi_load(img_path, &width, &height, &channels, 3);
   // Explicit Path Debugging block
    if (!raw_pixels) {
        printf("ERROR: Could not load image file.\n");
        printf("Looking for file at path: %s\n", img_path);
        printf("Reason given by library: %s\n", stbi_failure_reason());
        printf("Tip: Check your current folder with 'pwd' and make sure the file is there.\n");
        return 1;
    }

    
    // Cast the memory block straight into your 2D BGR pixel matrix
    RGBTRIPLE (*image)[width] = (RGBTRIPLE (*)[width])raw_pixels;

    // grayscale(width, height, image);
    // sepia(height, width, image);
    // reflect(height, width, image);
    blur(height, width, image);

    


    printf("Successfully read dimensions and filtered image: %dx%d\n", width, height);

    // 3. EXPLICITLY SAVE THE EDITED BUFFER BACK TO DISK
    // Arguments: filename, width, height, channel count (3), pointer data, compression quality (100 = max)
    if (stbi_write_jpg(output_path, width, height, 3, raw_pixels, 100)) {
        printf("SUCCESS: New grayscale file saved to -> %s\n", output_path);
    } else {
        printf("ERROR: Failed to save the image output file to disk.\n");
    }

    stbi_image_free(raw_pixels);

    return 0;
}

void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            float sum = (float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue;
            // Round average values 
            int average = round(sum / 3.0);
            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}


void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            float sepiaRed = .393 * (float)image[i][j].rgbtRed  + .769 * (float)image[i][j].rgbtGreen + .189 * (float)image[i][j].rgbtBlue;
            float sepiaGreen = .349 * (float)image[i][j].rgbtRed  + .686 * (float)image[i][j].rgbtGreen + .168 * (float)image[i][j].rgbtBlue;
            float sepiaBlue = .272 * (float)image[i][j].rgbtRed  + .534 * (float)image[i][j].rgbtGreen + .131 * (float)image[i][j].rgbtBlue;
            // Update pixel with sepia values
            image[i][j].rgbtRed = round(sepiaRed) < 255 ? round(sepiaRed) : 255;
            image[i][j].rgbtGreen = round(sepiaGreen) < 255 ? round(sepiaGreen) : 255;
            image[i][j].rgbtBlue = round(sepiaBlue) < 255 ? round(sepiaBlue) : 255;
        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width]){
  // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
          // Calculate the matching index on the opposite side of the same row
            int opposite_j = width - 1 - j;
          
            RGBTRIPLE temp = image[i][j];
            // Swap pixels
            image[i][j] = image[i][opposite_j];
            image[i][opposite_j] = temp;
        }
    }
  return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           copy[i][j] = image[i][j];
        }
    }

    // Loop over all pixels
    for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++)
        {
           float sum_neighbors_rgbtRed = 0;
        float sum_neighbors_rgbtGreen = 0;
        float sum_neighbors_rgbtBlue = 0;
        int count = 0;

          // -1, 0 , 1
          for (int r = -1; r < 2; r++)
          {
            // -1, 0 , 1
            for (int c = -1; c < 2; c++)
            {
              int neighbor_row = i + r;
              int neighbor_column = j + c;

              if(neighbor_row >= 0 && neighbor_row < height && neighbor_column >= 0 && neighbor_column < width) {
                sum_neighbors_rgbtRed += copy[neighbor_row][neighbor_column].rgbtRed;
                sum_neighbors_rgbtGreen += copy[neighbor_row][neighbor_column].rgbtGreen;
                sum_neighbors_rgbtBlue += copy[neighbor_row][neighbor_column].rgbtBlue;
                count += 1;
              }
            }
          }

          image[i][j].rgbtRed = round(sum_neighbors_rgbtRed / count);
          image[i][j].rgbtGreen = round(sum_neighbors_rgbtGreen / count);
          image[i][j].rgbtBlue = round(sum_neighbors_rgbtBlue / count);
        }
    }
}

void edge(int height, int width, RGBTRIPLE image[height][width])
 {
return;
}
