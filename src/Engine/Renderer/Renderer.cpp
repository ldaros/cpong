#include <iostream>
#include <chrono>
#include <thread>
#include "windows.h"
#include "Engine/Window/Window.h"
#include "Renderer.h"

Renderer::Renderer(int frameRate) {
    frameDuration = std::chrono::milliseconds(1000 / frameRate);
    next_frame = std::chrono::steady_clock::now() + frameDuration;
}

void Renderer::DrawFrame(const Window &canvas) {
    std::string frame;
    frame.reserve(canvas.GetWidth() * canvas.GetHeight() + canvas.GetHeight());

    for (int y = 0; y < canvas.GetHeight(); y++) {
        frame.append(canvas.GetData().begin() + y * canvas.GetWidth(),
                     canvas.GetData().begin() + (y + 1) * canvas.GetWidth());
        frame.push_back('\n');
    }

    COORD cursor_coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_coord);

    std::cout << frame;
}

void Renderer::WaitForNextFrame() {
    std::this_thread::sleep_until(next_frame);
    next_frame += frameDuration;
}