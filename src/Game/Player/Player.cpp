#include "Engine/Input/Input.h"
#include "Player.h"

Player::Player() : paddle_() {}

Player::Player(int x, int y, int height) : paddle_(x, y, height) {}

void Player::Update(Window &window) {
    paddle_.prev_position = paddle_.position;

    if (Input::IsKeyPressed(Key::UP)) {
        --paddle_.position.y;
    }
    if (Input::IsKeyPressed(Key::DOWN)) {
        ++paddle_.position.y;
    }

    paddle_.ClampToWindow(window);
}

Vector2i Player::Position() const {
    return paddle_.position;
}

int Player::Height() const {
    return paddle_.height;
}

void Player::Draw(Window &window) const {
    paddle_.Draw(window);
}
