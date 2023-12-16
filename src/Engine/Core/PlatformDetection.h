#ifdef _WIN32
#define ENGINE_PLATFORM_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
#define ENGINE_PLATFORM_MACOS
#error "Unsupported platform!"
#elif defined(__linux__)
#define ENGINE_PLATFORM_LINUX
#error "Unsupported platform!"
#else
#error "Unsupported platform!"
#endif

#ifndef CPONG_PLATFORM_DETECTION_H
#define CPONG_PLATFORM_DETECTION_H

#include <string>

namespace PlatformDetection {
    std::string GetOS();
}

#endif //CPONG_PLATFORM_DETECTION_H