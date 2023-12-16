#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Engine/Window/Window.h"

TEST_CASE("Window::Window", "[window]") {
    Window window("CPONG", 80, 25);

    REQUIRE(window.Width() == 80);
    REQUIRE(window.Height() == 25);
    REQUIRE(window.IsRunning() == true);
}

TEST_CASE("Window::SetChar", "[window]") {
    Window window("CPONG", 80, 25);

    REQUIRE(window.SetChar(0, 0, 'a') == true);
    REQUIRE(window.SetChar(80, 25, 'd') == false);
}

TEST_CASE("Window::GetChar", "[window]") {
    Window window("CPONG", 80, 25);

    window.SetChar(30, 10, 'a');
    REQUIRE(window.GetChar(30, 10) == 'a');
}

TEST_CASE("Window::Fill", "[window]") {
    Window window("CPONG", 80, 25);

    window.Fill('a');
    REQUIRE(window.GetChar(0, 0) == 'a');
    REQUIRE(window.GetChar(79, 24) == 'a');
}

TEST_CASE("Window::IsInBounds", "[window]") {
    Window window("CPONG", 80, 25);

    REQUIRE(window.IsInBounds(0, 0) == true);
    REQUIRE(window.IsInBounds(79, 24) == true);
    REQUIRE(window.IsInBounds(-1, 0) == false);
    REQUIRE(window.IsInBounds(0, -1) == false);
    REQUIRE(window.IsInBounds(80, 0) == false);
    REQUIRE(window.IsInBounds(0, 25) == false);
}

TEST_CASE("Window::Close", "[window]") {
    Window window("CPONG", 80, 25);

    window.Close();
    REQUIRE(window.IsRunning() == false);
}

TEST_CASE("Window::HideCursor", "[window]") {
    Window::HideCursor();
}