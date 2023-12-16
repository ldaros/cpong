#include "Engine/Core/Logger.h"
#include "Engine/Core/PlatformDetection.h"
#include "Engine/Core/HardwareInfo.h"
#include "Engine/Window/Window.h"
#include "Engine/Renderer/Renderer.h"
#include "Game/Game.h"

int main() {
    Logger::Initialize("cpong.log");
    Logger::Info("Logger initialized.");
    Logger::Info("Starting CPONG...");

    Logger::Info("OS: " + PlatformDetection::GetOS());
    Logger::Info("CPU Core Count: " + HardwareInfo::GetCPUCoreCount());
    Logger::Info("RAM Total: " + HardwareInfo::GetRAMTotal());
    Logger::Info("RAM Available: " + HardwareInfo::GetRAMAvailable());

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
