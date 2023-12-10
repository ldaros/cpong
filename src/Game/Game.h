#ifndef CPONG_GAME_H
#define CPONG_GAME_H

#include "Engine/Window/Window.h"
#include "Game/Ball/Ball.h"
#include "Game/AI/AI.h"
#include "Game/Player/Player.h"

class Game {
public:
    Game();

    void Setup(Window &window);

    void Update(Window &window);

private:
    Ball ball_;
    Player player_;
    AI ai_;
    int player_score_;
    int ai_score_;

    static constexpr int kPlayerStartX = 3;
    static constexpr int kAIStartXOffset = 3;
    static constexpr int kPaddleHeight = 5;
    static constexpr int kTopBottomBorderY = 0;

    void InitializePlayerAndAI(Window &window);

    static void InitializeBorders(Window &window);

    void DrawScores(Window &window) const;

    static void HandleGameControls(Window &window);
};

#endif //CPONG_GAME_H
