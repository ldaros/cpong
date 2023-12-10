#include "Engine/Window/Window.h"
#include "Engine/Renderer/Renderer.h"
#include "Game/Game.h"

int main() {
    Window window("CPONG", 80, 25);
    Renderer renderer(30);

    Window::HideCursor();

    Game game = Game();
    game.Setup(window);

    while (window.IsRunning()) {
        game.Update(window);

        Renderer::DrawFrame(window);
        renderer.WaitForNextFrame();
    }

    return 0;
}
