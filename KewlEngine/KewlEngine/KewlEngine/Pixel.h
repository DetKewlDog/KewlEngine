#ifndef PIXEL_H
#define PIXEL_H

#pragma once
#include <thread>
#include <stdio.h>
#include <chrono>
#include <iostream>
#include "Screen.h"


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
		const char* buff = this->_color.toString().c_str();
		WriteConsoleOutputCharacter(this->_hConsole, (LPCWSTR)buff, sizeof(buff), this->_pos, nullptr);
	}
};

#endif PIXEL_H