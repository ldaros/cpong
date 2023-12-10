#ifndef CPONG_PLAYER_H
#define CPONG_PLAYER_H

#include "Game/Paddle/Paddle.h"

class Player : public Paddle {
public:
    Player();

    Player(int x, int y, int height);

    void Update(Window &window) override;
};

#endif //CPONG_PLAYER_H
