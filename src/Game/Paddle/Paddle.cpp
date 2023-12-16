#include "Engine/Window/Window.h"
#include "Paddle.h"

Paddle::Paddle() : position{0, 0}, prev_position{0, 0}, height{0} {}

Paddle::Paddle(int x, int y, int height)
        : position{x, y}, prev_position{x, y}, height{height} {}

void Paddle::Draw(Window &window) const {
    ClearPrevious(window);
    Render(window);
}

void Paddle::ClampToWindow(const Window &window) {
    if (position.y < 1) {
        position.y = 1;
    }
    if (position.y + height > window.Height() - 1) {
        position.y = window.Height() - height - 1;
    }
}

void Paddle::ClearPrevious(Window &window) const {
    for (int i = 0; i < height; i++) {
        window.SetChar(prev_position.x, prev_position.y + i, ' ');
    }
}

void Paddle::Render(Window &window) const {
    for (int i = 0; i < height; i++) {
        window.SetChar(position.x, position.y + i, '|');
    }
}
