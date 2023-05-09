#ifndef SCREEN_H
#define SCREEN_H

#pragma once
#include <vector>
#include <windows.h>
#include "Texture.h"
#include "Pixel.h"

class Screen {
private:
	int _width, _height;
	std::vector<std::vector<Pixel>> _buffer;
public:
	int FPS;
	HANDLE hConsole;
	Screen(int width, int height, int FPS);
	~Screen();

	virtual int width() const;
	virtual int height() const;

	virtual void setPixel(int x, int y, Color c);
	virtual void fillScreen(Color c);
};

#endif SCREEN_H