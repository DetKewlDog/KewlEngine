#ifndef PIXEL_HPP
#define PIXEL_HPP

#pragma once
#include <thread>
#include <stdio.h>
#include <chrono>
#include <iostream>
#include "Screen.hpp"


class Screen;

class Pixel {
private:
	COORD _pos = { 0, 0 };
	Color _color, _lastColor;
	HANDLE _hConsole;

public:
	Pixel(int x, int y) {
		this->_pos = { (short)x, (short)y };
		this->_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		this->_color = Color(255, 0, 0, 0);
	}
	~Pixel() { }

	Color getColor() const {
		return this->_color;
	}

	void setColor(Color c) {
		if (c == this->_color) return;
		this->_color = c;
		SetConsoleCursorPosition(this->_hConsole, this->_pos);
		fputs(this->_color.toString().c_str(), stdout);
	}
};

#endif PIXEL_HPP