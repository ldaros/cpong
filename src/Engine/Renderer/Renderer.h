#ifndef CPONG_RENDERER_H
#define CPONG_RENDERER_H

#include <chrono>
#include "Engine/Window/Window.h"

class Renderer {
public:
    explicit Renderer(int frameRate);

    static void DrawFrame(const Window &canvas);

    void WaitForNextFrame();

private:
    std::chrono::steady_clock::time_point next_frame;
    std::chrono::milliseconds frameDuration{};
};

#endif //CPONG_RENDERER_H
