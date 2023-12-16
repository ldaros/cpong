#include "AI.h"

AI::AI() : paddle_() {}

AI::AI(int x, int y, int height) : paddle_(x, y, height) {}

void AI::Update(Window &window, Vector2i ball_pos) {
    paddle_.prev_position = paddle_.position;

    // Move towards ball
    if (ball_pos.y < paddle_.position.y) {
        --paddle_.position.y;
    }
    if (ball_pos.y > paddle_.position.y) {
        ++paddle_.position.y;
    }

    paddle_.ClampToWindow(window);
}

Vector2i AI::Position() const {
    return paddle_.position;
}

int AI::Height() const {
    return paddle_.height;
}

void AI::Draw(Window &window) const {
    paddle_.Draw(window);
}
