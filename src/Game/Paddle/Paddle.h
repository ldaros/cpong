#ifndef CPONG_PADDLE_H
#define CPONG_PADDLE_H

#include "Engine/Window/Window.h"
#include "Engine/Core/Core.h"

class Paddle {
public:
    Paddle();

    Paddle(int x, int y, int height);

    void Draw(Window &window) const;

    void ClampToWindow(const Window &window);

    void ClearPrevious(Window &window) const;

    void Render(Window &window) const;

    static constexpr int kWidth = 1;
    Vector2i position;
    Vector2i prev_position;
    int height;
};

#endif //CPONG_PADDLE_H
