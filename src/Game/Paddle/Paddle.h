#ifndef CPONG_PADDLE_H
#define CPONG_PADDLE_H

#include "Engine/Window/Window.h"
#include "Engine/Core/Core.h"

class Paddle {
public:
    Paddle();

    Paddle(int x, int y, int height);

    virtual void Update(Window &window) = 0;

    void Draw(Window &window);

    Vector2i GetPosition() const;

    int GetHeight() const;

protected:
    static constexpr int kWidth = 1;
    Vector2i position_;
    Vector2i prev_position_;
    int height_;

    void ClampToWindow(const Window &window);

    void ClearPrevious(Window &window) const;

    void Render(Window &window) const;
};

#endif //CPONG_PADDLE_H
