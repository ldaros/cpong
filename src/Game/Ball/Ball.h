#ifndef CPONG_BALL_H
#define CPONG_BALL_H

#include "Engine/Window/Window.h"
#include "Engine/Core/Core.h"

class Ball {
public:
    Ball();

    void Setup(Window &window);

    void Update(Window &window, Vector2i paddle_pos, int paddle_height,
                Vector2i ai_pos, int ai_height, int &player_score, int &ai_score);

    void Draw(Window &window) const;

    Vector2i GetPosition() const;

private:
    static constexpr int kTopBoundary = 2;
    static constexpr int kBottomOffset = 3;
    static constexpr int kPaddleWidth = 1;
    static constexpr int kBallSize = 1;
    static constexpr int kInitialVelocityX = 1;
    static constexpr int kInitialVelocityY = 1;

    // Sounds
    static constexpr int kPaddleHitFrequency = 1000;
    static constexpr int kPaddleHitDuration = 100;
    static constexpr int kWallHitFrequency = 500;
    static constexpr int kWallHitDuration = 100;
    static constexpr int kScoreFrequency = 1000;
    static constexpr int kScoreDuration = 100;

    Vector2i position;       // Current position
    Vector2i prev_position;  // Previous position
    Vector2i velocity;       // Velocity

    void CheckBoundaryCollision(const Window &window);

    void CheckPaddleCollision(Vector2i paddle_pos, int paddle_width);

    void CheckAICollision(Vector2i ai_pos, int ai_width);

    bool UpdateScore(int &player_score, int &ai_score, const Window &window) const;

    void ResetPosition(Window &window);
};

#endif // CPONG_BALL_H
