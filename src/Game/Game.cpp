#define NOMINMAX

#include <algorithm>
#include "Engine/Input/Input.h"
#include "Game.h"
#include "Engine/Core/Logger.h"

Game::Game() : player_score_(0), ai_score_(0) {
}

void Game::Setup(Window &window) {
    Logger::Info("Setting up game...");

    InitializePlayerAndAI(window);
    ball_.Setup(window);
    player_score_ = 0;
    ai_score_ = 0;
    InitializeBorders(window);
}

void Game::Update(Window &window) {
    HandleGameControls(window);
    player_.Update(window);
    ai_.Update(window, ball_.Position());
    ball_.Update(window, player_.Position(), player_.Height(), ai_.Position(), ai_.Height(), player_score_,
                 ai_score_);

    player_.Draw(window);
    ai_.Draw(window);
    ball_.Draw(window);
    DrawScores(window);
}

void Game::InitializePlayerAndAI(Window &window) {
    player_ = Player(kPlayerStartX, window.Height() / 2 - kPaddleHeight / 2, kPaddleHeight);
    ai_ = AI(window.Width() - kAIStartXOffset, window.Height() / 2 - kPaddleHeight / 2, kPaddleHeight);
}

void Game::InitializeBorders(Window &window) {
    window.Fill(' ');
    for (int i = 0; i < window.Width(); i++) {
        window.SetChar(i, kTopBottomBorderY, '-');
        window.SetChar(i, window.Height() - 1, '-');
    }
}

void Game::DrawScores(Window &window) const {
    char playerScoreChar = static_cast<char>('0' + std::min(player_score_, 9));
    char aiScoreChar = static_cast<char>('0' + std::min(ai_score_, 9));

    window.SetChar(window.Width() / 2 - 1, kTopBottomBorderY, playerScoreChar);
    window.SetChar(window.Width() / 2 + 1, kTopBottomBorderY, aiScoreChar);
}


void Game::HandleGameControls(Window &window) {
    if (Input::IsKeyPressed(Key::ESCAPE)) {
        window.Close();
        Logger::Info("Closing game...");
    }
}
