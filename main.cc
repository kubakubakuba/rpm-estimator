#include <iostream>
#include <vector>
#include "img.hh"
#include "filter.hh"

int main(){
	Image img("test.png");

	Color w(255, 255, 255, 255); //white
	Color b(0, 0, 0, 255); //black

	Image white_mask = filter_color(img, w, 25);
	Image black_mask = filter_color(img, b, 25);

	Image gauss = gaussian_blur_3(white_mask);

	white_mask.write_file("white.png");
	black_mask.write_file("black.png");
	gauss.write_file("gauss.png");
}