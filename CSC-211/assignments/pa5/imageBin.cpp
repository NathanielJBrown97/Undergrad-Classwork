#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// this will throw an error if you don't have the bitmap library installed
// so be sure to do that before uncommenting this #include line
#include "bitmap_image.hpp"

int main(int argc, char *argv[])
{
    // strings for input and output file names
    std::string input_file_name(argv[1]);
    std::string output_file_name(argv[2]);

    // open the input image
    bitmap_image image(input_file_name);

    // call convert_to_grayscale prebuilt function to get standardized greyscale image for gradescope
    image.convert_to_grayscale();

    // collect width and height for future iteration markers
    const int width = image.width();
    const int height = image.height();

    // find mean pixel value
    double sum = 0;
    // iterate through starting height pixel through height of image --- i.e. x position in image
    for (int cur_height_pixel = 0; cur_height_pixel < height; ++cur_height_pixel)
    {
        // iterate through each width of each height, until reaching width of image --- i.e. y position in image
        for (int current_width_pixel = 0; current_width_pixel < width; ++current_width_pixel)
        {
            //
            rgb_t color;
            image.get_pixel(current_width_pixel, cur_height_pixel, color);
            sum += color.red;
        }
    }
    const int threshold = sum / (width * height);

    // binarize the image using the threshold
    for (int current_height_pixel = 0; current_height_pixel < height; ++current_height_pixel)
    {
        for (int current_width_pixel = 0; current_width_pixel < width; ++current_width_pixel)
        {
            // struct of rgb_t type from bitmap image libary - call variable color
            rgb_t color;
            // retrieves the current width/height pixels and stores it within our color variable
            image.get_pixel(current_width_pixel, current_height_pixel, color);
            // check if red is less than threshol val
            if (color.red < threshold)
            {
                // if it is set to black
                color.red = 0;
                color.green = 0;
                color.blue = 0;
                // otherwise
            }
            else
            {
                // it isn't and set to white.
                color.red = 255;
                color.green = 255;
                color.blue = 255;
            }
            // set the current pixel to the updated color; continues looping till finished.
            image.set_pixel(current_width_pixel, current_height_pixel, color);
        }
    }

    // save the modified image as our outputfilename
    image.save_image(output_file_name);
}