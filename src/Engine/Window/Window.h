#ifndef CPONG_WINDOW_H_
#define CPONG_WINDOW_H_

#include <vector>

class Window {
public:
    Window(char const *title, int width, int height);

    bool SetChar(int x, int y, char value);

    char GetChar(int x, int y) const;

    bool IsInBounds(int x, int y) const;

    int Width() const;

    int Height() const;

    bool IsRunning() const;

    const std::vector<char> &Data() const;

    void Fill(char clear_char);

    void Close();

    static void HideCursor();

private:
    int width_;
    int height_;
    std::vector<char> data_;
    bool running_;
};

#endif  // CPONG_WINDOW_H_
