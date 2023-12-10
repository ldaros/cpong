#include "Engine/Window/Window.h"
#include "Paddle.h"

Paddle::Paddle() : position_{0, 0}, prev_position_{0, 0}, height_{0} {}

Paddle::Paddle(int x, int y, int height)
        : position_{x, y}, prev_position_{x, y}, height_{height} {}

void Paddle::Draw(Window &window) {
    ClearPrevious(window);
    Render(window);
}

Vector2i Paddle::GetPosition() const {
    return position_;
}

int Paddle::GetHeight() const {
    return height_;
}

void Paddle::ClampToWindow(const Window &window) {
    if (position_.y < 1) {
        position_.y = 1;
    }
    if (position_.y + height_ > window.GetHeight() - 1) {
        position_.y = window.GetHeight() - height_ - 1;
    }
}

void Paddle::ClearPrevious(Window &window) const {
    for (int i = 0; i < height_; i++) {
        window.SetChar(prev_position_.x, prev_position_.y + i, ' ');
    }
}

void Paddle::Render(Window &window) const {
    for (int i = 0; i < height_; i++) {
        window.SetChar(position_.x, position_.y + i, '|');
    }
}
