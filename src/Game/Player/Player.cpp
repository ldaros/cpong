#include "Engine/Input/Input.h"
#include "Player.h"

Player::Player() : Paddle() {}

Player::Player(int x, int y, int height) : Paddle(x, y, height) {}

void Player::Update(Window &window) {
    prev_position_ = position_;

    if (Input::IsKeyPressed(Key::UP)) {
        --position_.y;
    }
    if (Input::IsKeyPressed(Key::DOWN)) {
        ++position_.y;
    }

    ClampToWindow(window);
}
