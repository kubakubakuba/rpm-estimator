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

Image gaussian_blur_3(Image & img){
	Image n_img(img.w, img.h, 4);
	
	int kernel[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

	for(int i = 1; i < img.h - 1; ++i){ //cols
		for(int j = 1; j < img.w - 1; ++j){ //rows
			uint8_t* pixel_ul = img.data + ((i - 1) * img.w + (j - 1)) * img.ch;
			uint8_t* pixel_uu = img.data + ((i - 1) * img.w + j) * img.ch;
			uint8_t* pixel_ur = img.data + ((i - 1) * img.w + (j +1)) * img.ch;
			uint8_t* pixel_ll = img.data + (i * img.w + j) * img.ch;
			uint8_t* pixel =	img.data + (i * img.w + j) * img.ch;
			uint8_t* pixel_rr = img.data + (i * img.w + j) * img.ch;
			uint8_t* pixel_bl = img.data + ((i + 1) * img.w + (j - 1)) * img.ch;
			uint8_t* pixel_bb = img.data + ((i + 1) * img.w + j) * img.ch;
			uint8_t* pixel_br = img.data + ((i + 1) * img.w + (j + 1)) * img.ch;

			uint8_t* n_pixel = n_img.data + (i * img.w + j) * n_img.ch;

			uint8_t val[4];
			for(int c = 0; c < 4; ++c){
				val[c] = (*(pixel_ul + c) * kernel[0][0] + *(pixel_uu + c) * kernel[0][1] + *(pixel_ur + c) * kernel[0][2] +
							  *(pixel_ll + c) * kernel[1][0] + *(pixel + c) * kernel[1][1] + *(pixel_rr + c) * kernel[1][2] +
							  *(pixel_bl + c) * kernel[2][0] + *(pixel_bb + c) * kernel[2][1] + *(pixel_br + c) * kernel[2][2])
							  / 16.0;
			}

			*(n_pixel) = 	 val[0];
			*(n_pixel + 1) = val[1];
			*(n_pixel + 2) = val[2];
			*(n_pixel + 3) = val[3];
		}
	}

	return n_img;
}