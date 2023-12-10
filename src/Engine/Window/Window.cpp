#include <algorithm>
#include "Windows.h"
#include "Window.h"

Window::Window(char const *title, int width, int height) : width_(width), height_(height), running_(true),
                                                           data_(width * height, ' ') {
    SetConsoleTitle(title);
}

bool Window::SetChar(int x, int y, char value) {
    if (!IsInBounds(x, y)) {
        return false;
    }

    data_[y * width_ + x] = value;

    return true;
}

char Window::GetChar(int x, int y) const {
    if (!IsInBounds(x, y)) {
        return ' ';
    }

    return data_[y * width_ + x];
}

void Window::Fill(char clear_char) {
    std::fill(data_.begin(), data_.end(), clear_char);
}

bool Window::IsInBounds(int x, int y) const {
    return x >= 0 && x < width_ && y >= 0 && y < height_;
}

int Window::GetWidth() const { return width_; }

int Window::GetHeight() const { return height_; }

bool Window::IsRunning() const { return running_; }

void Window::Close() { running_ = false; }

const std::vector<char> &Window::GetData() const { return data_; }

void Window::HideCursor() {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console_handle, &info);
}
