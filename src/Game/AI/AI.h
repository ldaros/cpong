#ifndef CPONG_AI_H
#define CPONG_AI_H

#include "Game/Paddle/Paddle.h"
#include "Game/Ball/Ball.h"

class AI {
public:
    AI();

    AI(int x, int y, int height);

    void Update(Window &window, Vector2i ball_pos);

    void Draw(Window &window) const;

    Vector2i Position() const;

    int Height() const;

protected:
    Paddle paddle_;
};

#endif //CPONG_AI_H
