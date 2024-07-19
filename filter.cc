#include "filter.hh"

Image filter_color(Image & img, Color c, uint8_t threshold){
	Image n_img(img.w, img.h, 4); //new image with transparency layer

	for(int i = 0; i < img.h; ++i){
		for(int j = 0; j < img.w; ++j){
			uint8_t* pixel = img.data + (i * img.w + j) * img.ch;
			uint8_t* n_pixel = n_img.data + (i * img.w + j) * n_img.ch;
			
			uint8_t rr = *(pixel);
			uint8_t gg = *(pixel + 1);
			uint8_t bb = *(pixel + 2);

			 if (std::abs(c.r - rr) < threshold && std::abs(c.g - gg) < threshold && std::abs(c.b - bb) < threshold) {
				*(n_pixel + 0) = rr;
				*(n_pixel + 1) = gg;
				*(n_pixel + 2) = bb;
				*(n_pixel + 3) = 255;
			}
			else{
				//invisible violet for indication of error
				*(n_pixel + 0) = 255;
				*(n_pixel + 1) = 0;
				*(n_pixel + 2) = 255;
				*(n_pixel + 3) = 0;
			}
		}
	}

	return n_img;
}