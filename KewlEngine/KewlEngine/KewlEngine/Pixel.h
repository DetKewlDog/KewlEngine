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
	std::thread _thread;
	HANDLE _hConsole;

public:
	Pixel(const Pixel&) { }
	Pixel(int x, int y) {
		this->_pos = { (short)x, (short)y };
		this->_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		this->_color = Color(255, 0, 0, 0);
		this->_thread = std::thread(&Pixel::updatePixel, this);
		this->_thread.detach();
	}
	~Pixel() { }

	Color getColor() const {
		return this->_color;
	}

	void setColor(Color c) {
		this->_color = c;
	}

	void updatePixel() {
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(1) / 10);
			if (this->_lastColor != this->_color) {
				SetConsoleCursorPosition(this->_hConsole, this->_pos);
				printf("%s", this->_color.toString().c_str());
				this->_lastColor = this->_color;
			}
		}
	}
};

#endif PIXEL_H