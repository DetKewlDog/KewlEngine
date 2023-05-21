#ifndef SCREEN_HPP
#define SCREEN_HPP

#pragma once
#include <vector>
#include <windows.h>
#include "Texture.hpp"
#include "Pixel.hpp"

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

#endif SCREEN_HPP