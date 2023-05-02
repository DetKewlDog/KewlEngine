#ifndef TEXTURE_H
#define TEXTURE_H

#include "Color.h"
#include <vector>
#include <string>

class Texture {
protected:
	int _width, _height, _bpp;
	uint8_t* _image;
public:
	Texture(std::string filename);
	virtual ~Texture();

	virtual int width() const;
	virtual int height() const;

	virtual Color getPixel(int x, int y) const;
};

#endif TEXTURE_H