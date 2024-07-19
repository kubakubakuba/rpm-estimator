#include "process.hh"

std::vector<Image> process(Image & img){
	Image gauss_tmp(img);
	Image gauss(img);
	
	float sigma = 0.6;
	int select_threshold = 25;

	fast_gaussian_blur(gauss_tmp.data, gauss.data, gauss.w, gauss.h, gauss.ch, sigma, 1);

	Color w(255, 255, 255, 255); //white
	Color b(0, 0, 0, 255); //black

	Image white_mask = filter_color(gauss, w, select_threshold);
	Image black_mask = filter_color(gauss, b, select_threshold);

	std::vector<Image> imgs;
	imgs.push_back(white_mask);
	imgs.push_back(white_mask);
	
	return imgs;
}

std::pair<std::vector<int>,std::vector<int>> get_pixels(Image & img, uint8_t threshold){
	//get pixel locations of alpha greater than threshold
	std::vector<int> xi;
	std::vector<int> yi;

	for(int i = 0; i < img.h; ++i){
		for(int j = 0; j < img.w; ++j){
			uint8_t* pixel = img.data + (i * img.w + j) * img.ch;

			uint8_t aa = *(pixel + 3);

			if (aa > threshold) {
				xi.push_back(i);
				yi.push_back(j);
			}
		}
	}

	return std::make_pair(xi, yi);
}