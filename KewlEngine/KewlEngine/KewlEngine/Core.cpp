#include <iostream>
#include "Texture.h"

int main() {
	Texture tex("C:\\Users\\bar\\Desktop\\wood.png");
	Color c;
	for (int y = 0; y < tex.height(); y++) {
		for (int x = 0; x < tex.width(); x++) {
			std::cout << tex.getPixel(x, y);
		}
		std::cout << std::endl;
	}
	return 0;
}