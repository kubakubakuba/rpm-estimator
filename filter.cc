#include "filter.hh"

void filter_color(Image & img, Color c, uint8_t threshold){
	for(int i = 0; i < img.h * img.ch; ++i){ //row idx
		for(int j = 0; j < img.w * img.ch; j += img.ch){ //col idx
		//std::cout << (int) c.r << std::endl;
			uint8_t* pixel = img.data + i*img.w + j;
			
			uint8_t rr = *(pixel);
			uint8_t gg = *(pixel + 1);
			uint8_t bb = *(pixel + 2);
			uint8_t aa = *(pixel + 3);

			//std::cout << "r: " << (int)rr << " g: " << (int)gg << " b: " << (int)bb << " a: " << (int) aa;
			//std::cout << " rr: " << std::abs(c.r - rr) << " gg: " << std::abs(c.g - gg) << " bb: " << std::abs(c.b - bb) << " aa: " << (int) std::abs(c.a - aa) << std::endl;

			if(std::abs(c.r - rr) < threshold && std::abs(c.g - gg) < threshold && std::abs(c.b - bb) < threshold && std::abs(c.a - aa) < threshold){
				//std::cout << "hit" << std::endl;
			}
			else{
				//std::memset(pixel, 0xFF00FF, 4); //set RGBA to 0
				*pixel = i;
			}
		}
	}
}

void filter_color(Image & img, uint8_t r, uint8_t g, uint8_t b);