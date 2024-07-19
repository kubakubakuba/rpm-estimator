//*https://github.com/Code-Break0/Image-Processing*

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "img.hh"
#include "stb_image.h"
#include "stb_image_write.h"

Color::Color (uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a){

}

Image::Image(const char* path){
	if (!read_file(path)){
		std::cout << "Error when loading image" << std::endl;
		return;
	}

	size = w * h * ch;
}

Image::Image(int w, int h, int ch) : w(w), h(h), ch(ch){
	size = w * h * ch;
	data = new uint8_t[size];
}

Image::Image(const Image & img) : Image(img.w, img.h, img.ch){
	memcpy(data, img.data, img.size);
}

Image::~Image(){
	stbi_image_free(data);
}

bool Image::read_file(const char* path){
	data = stbi_load(path, &w, &h, &ch, 0);
	return data != NULL;
}

bool Image::write_file(const char* path){
	ImageType t = get_type(path);
	bool s = false;

	switch(t){
		case JPG:
			s = stbi_write_jpg(path, w, h, ch, data, 100);
		case PNG:
			s = stbi_write_png(path, w, h, ch, data, w*ch);
			break;
		case BMP:
			s = stbi_write_bmp(path, w, h, ch, data);
	}

	return s;
}

ImageType Image::get_type(const char* path){
	const char* ext = strrchr(path, '.');
	if(ext != nullptr){
		if(strcmp(ext, ".jpg") == 0){
			return JPG;
		}
		else if (strcmp(ext, ".png") == 0){
			return PNG;
		}
		else if (strcmp(ext, ".bmp") == 0){
			return BMP;
		}
	}

	return PNG; //failsafe
}