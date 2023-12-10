#include "AI.h"

AI::AI() : Paddle() {}

AI::AI(int x, int y, int height) : Paddle(x, y, height) {}

void AI::Update(Window &window, Vector2i ball_pos) {
    prev_position_ = position_;

    // Move towards ball
    if (ball_pos.y < position_.y) {
        --position_.y;
    }
    if (ball_pos.y > position_.y) {
        ++position_.y;
    }

    ClampToWindow(window);
}


void AI::Update(Window &window) {
    // Do nothing
}