#include <inttypes.h>
#include <bitset>
#include <iostream>
#include <cstring>
#include "img.hh"

Image filter_color(Image & img, Color c, uint8_t threshold);

Image gaussian_blur_3(Image & img);