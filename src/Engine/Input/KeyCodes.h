#ifndef CPONG_KEYCODES_H
#define CPONG_KEYCODES_H

#include "Windows.h"

using KeyCode = int;

namespace Key {
    // Virtual-Key Codes: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
    enum : KeyCode {
        ESCAPE = VK_ESCAPE,
        SPACE = VK_SPACE,
        LEFT = VK_LEFT,
        RIGHT = VK_RIGHT,
        UP = VK_UP,
        DOWN = VK_DOWN,
        A = 0x41,
        B = 0x42,
        C = 0x43,
        D = 0x44,
        E = 0x45,
        F = 0x46,
        G = 0x47,
        H = 0x48,
        I = 0x49,
        J = 0x4A,
        K = 0x4B,
        L = 0x4C,
        M = 0x4D,
        N = 0x4E,
        O = 0x4F,
        P = 0x50,
        Q = 0x51,
        R = 0x52,
        S = 0x53,
        T = 0x54,
        U = 0x55,
        V = 0x56,
        W = 0x57,
        X = 0x58,
        Y = 0x59,
        Z = 0x5A
    };
}

#endif //CPONG_KEYCODES_H
