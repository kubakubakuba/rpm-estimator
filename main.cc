#include <iostream>
#include <vector>
#include "img.hh"
#include "filter.hh"

int main(){
	Image img("test.png");

	Color w(255, 255, 255, 255); //white
	Color b(0, 0, 0, 255); //black

	filter_color(img, w, 25);
	
	img.write_file("test2.png");
}