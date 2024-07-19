#include "img.hh"
#include "filter.hh"
#include "fast_gaussian_blur.h"
#include <vector>
#include <utility>
#include <cmath>

std::vector<Image> process(Image & img);

std::pair<std::vector<int>,std::vector<int>> get_pixels(Image & img, uint8_t threshold);
