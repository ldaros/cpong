#include "Input.h"
#include "Windows.h"

bool Input::IsKeyPressed(KeyCode key) {
    return GetAsyncKeyState(key) & 0x8000;
}
