#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
public:
	int r, g, b, a;

	Color() : r(0), g(0), b(0), a(0) { }
	Color(int red, int green, int blue, int alpha) : r(red), g(green), b(blue), a(alpha) { }
	~Color() { }
	friend std::ostream& operator<<(std::ostream& os, const Color& c) {
		os << "\x1b[48;2;" << c.r << ";" << c.g << ";" << c.b << "m  ";
		return os;
	}
};

#endif COLOR_H