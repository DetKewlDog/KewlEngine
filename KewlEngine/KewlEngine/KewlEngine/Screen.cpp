#include "Screen.h"

Screen::Screen(int width, int height, int fps) : _width(width), _height(height) {
    Screen::FPS = fps;
    Screen::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int x = GetSystemMetrics(SM_CXSCREEN), y = GetSystemMetrics(SM_CYSCREEN);

    // set font size
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.dwFontSize.X = 1.25f * x / width - 0.5f;
    cfi.dwFontSize.Y = 1.25f * y / height - 0.5f;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_DONTCARE;
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    // set fullscreen
    HWND Hwnd = GetForegroundWindow();
    LONG winstyle = GetWindowLong(Hwnd, GWL_STYLE);
    SetWindowLong(Hwnd, GWL_STYLE, (winstyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME);
    SetWindowPos(Hwnd, HWND_TOP, 0, 0, x, y, 0);

    // remove scrollbars
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hConsole, &info);

    COORD new_size = {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };

    SetConsoleScreenBufferSize(hConsole, new_size);

    DWORD prev_mode;
    GetConsoleMode(hConsole, &prev_mode);
    SetConsoleMode(hConsole, ENABLE_EXTENDED_FLAGS |
        (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

    for (int x = 0; x < this->_width; x++) {
        std::vector<Pixel> column;
        for (int y = 0; y < this->_height; y++) {
            column.push_back(Pixel(x, y));
        }
        this->_buffer.push_back(column);
    }
}
Screen::~Screen() {

}

int Screen::width() const {
    return this->_width;
}
int Screen::height() const {
    return this->_height;
}

void Screen::setPixel(int x, int y, Color c) {
    if (x < 0 || y < 0 || x >= this->_width || y >= this->_height) return;
    this->_buffer[x][y].setColor(c);
}

void Screen::fillScreen(Color c) {
    for (int y = 0; y < this->_height; y++) {
        for (int x = 0; x < this->_width; x++) {
            this->_buffer[x][y].setColor(c);
        }
    }
}