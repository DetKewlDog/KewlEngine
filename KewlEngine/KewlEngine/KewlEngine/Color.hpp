#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <sstream>

class Color {
public:
	int r, g, b, a;

	Color() : r(0), g(0), b(0), a(0) { }
	Color(int red, int green, int blue, int alpha) : r(red), g(green), b(blue), a(alpha) { }
	~Color() { }
	virtual std::string toString() const {
		std::stringstream s;
		s << *this;
		return s.str();
	}
	friend std::ostream& operator<<(std::ostream& os, const Color& c) {
		os << "\x1b[48;2;" << c.r << ";" << c.g << ";" << c.b << "m ";
		return os;
	}
	bool operator==(const Color& other) const {
		return r == other.r && g == other.g && b == other.b && a == other.a;
	}
	bool operator!=(const Color& other) const {
		return *this == other;
	}
};

#endif COLOR_HPP