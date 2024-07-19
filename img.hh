// -- file img.hh -- //

#ifndef IMG_HH
#define IMG_HH

#include <inttypes.h>
#include <iostream>

enum ImageType {
	JPG, PNG, BMP
};

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	Color (uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};

struct Image{
	public:
		uint8_t* data = NULL;
		unsigned int size = 0; //size of the data

		int w; //width
		int h; //height
		int ch; //channel

		Image(const char* path);

		Image(int w, int h, int ch);

		Image(const Image & img);

		~Image();

		bool read_file(const char* path);

		bool write_file(const char* path);

		ImageType get_type(const char* path);
};

#endif

// -- end of file img.hh -- //