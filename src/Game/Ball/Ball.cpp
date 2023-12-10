#include "Ball.h"
#include "Engine/Window/Window.h"
#include "Engine/Audio/Audio.h"

Ball::Ball() : position{0, 0}, prev_position{0, 0}, velocity{kInitialVelocityX, kInitialVelocityY} {}

void Ball::Setup(Window &window) {
    ResetPosition(window);
}

void Ball::Update(Window &window, Vector2i paddle_pos, int paddle_height,
                  Vector2i ai_pos, int ai_height, int &player_score, int &ai_score) {
    prev_position = position;
    position.x += velocity.x;
    position.y += velocity.y;

    CheckBoundaryCollision(window);
    CheckPaddleCollision(paddle_pos, paddle_height);
    CheckAICollision(ai_pos, ai_height);

    if (UpdateScore(player_score, ai_score, window)) {
        ResetPosition(window);
        Audio::PlayFrequency(kScoreFrequency, kScoreDuration);
    }
}

void Ball::CheckBoundaryCollision(const Window &window) {
    if (position.y < kTopBoundary || position.y > window.GetHeight() - kBottomOffset) {
        velocity.y *= -1;
        Audio::PlayFrequency(kWallHitFrequency, kWallHitDuration);
    }
    if (position.x < kBallSize || position.x > window.GetWidth() - kBallSize) {
        velocity.x *= -1;
        Audio::PlayFrequency(kWallHitFrequency, kWallHitDuration);
    }
}

void Ball::CheckPaddleCollision(Vector2i paddle_pos, int paddle_height) {
    if (position.x == paddle_pos.x + kPaddleWidth && position.y >= paddle_pos.y &&
        position.y <= paddle_pos.y + paddle_height) {
        velocity.x *= -1;
        Audio::PlayFrequency(kPaddleHitFrequency, kPaddleHitDuration);
    }
}

void Ball::CheckAICollision(Vector2i ai_pos, int ai_width) {
    if (position.x == ai_pos.x && position.y >= ai_pos.y && position.y <= ai_pos.y + ai_width) {
        velocity.x *= -1;
        Audio::PlayFrequency(kPaddleHitFrequency, kPaddleHitDuration);
    }
}

bool Ball::UpdateScore(int &player_score, int &ai_score, const Window &window) const {
    if (position.x < kBallSize) {
        ai_score++;
        return true;
    }
    if (position.x > window.GetWidth() - kBallSize) {
        player_score++;
        return true;
    }
    return false;
}

void Ball::ResetPosition(Window &window) {
    position = {window.GetWidth() / 2, window.GetHeight() / 2};
}

void Ball::Draw(Window &window) const {
    window.SetChar(prev_position.x, prev_position.y, ' ');
    window.SetChar(position.x, position.y, 'O');
}

Vector2i Ball::GetPosition() const {
    return position;
}
