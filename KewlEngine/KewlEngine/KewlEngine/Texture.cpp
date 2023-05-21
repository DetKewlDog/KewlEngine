#include "Texture.hpp"

#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(std::string filename) {
	this->_image = stbi_load(filename.c_str(), &this->_width, &this->_height, &this->_bpp, 4);
}

Texture::~Texture() {
	stbi_image_free(this->_image);
}

int Texture::width() const {
	return this->_width;
}
int Texture::height() const {
	return this->_height;
}

Color Texture::getPixel(int x, int y) const {
	unsigned bytePerPixel = 4;
	unsigned char* pixel = this->_image + (x + this->_width * y) * bytePerPixel;
	return Color(pixel[0], pixel[1], pixel[2], pixel[3]);
}