#ifndef CPONG_AI_H
#define CPONG_AI_H

#include "Game/Paddle/Paddle.h"
#include "Game/Ball/Ball.h"

class AI : public Paddle {
public:
    AI();

    AI(int x, int y, int height);

    void Update(Window &window) override;

    void Update(Window &window, Vector2i ball_pos);
};

#endif //CPONG_AI_H
