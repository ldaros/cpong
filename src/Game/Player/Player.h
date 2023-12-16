#ifndef CPONG_PLAYER_H
#define CPONG_PLAYER_H

#include "Game/Paddle/Paddle.h"

class Player {
public:
    Player();

    Player(int x, int y, int height);

    void Update(Window &window);

    void Draw(Window &window) const;

    Vector2i Position() const;

    int Height() const;

protected:
    Paddle paddle_;
};

#endif //CPONG_PLAYER_H
