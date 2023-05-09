#include <iostream>
#include "Texture.h"
#include "Screen.h"

int main() {
	std::cout << std::endl;
	Screen screen(316, 180, 10);
	for (int x = 0; x < screen.width(); x++) {
		float val = (float)x / (float)(screen.width() - 1) * 255;
		for (int y = 0; y < screen.height(); y++) {
			Color c(val, (float)y / (float)(screen.height() - 1) * 255, 0, 255);
			screen.setPixel(x, y, c);
		}
	}
	while(true) {}
	return 0;
}