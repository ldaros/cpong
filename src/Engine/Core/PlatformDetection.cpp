#include "PlatformDetection.h"
#include <string>

std::string PlatformDetection::GetOS() {
    std::string os;

#ifdef ENGINE_PLATFORM_WINDOWS
    os = "Windows";
#elif ENGINE_PLATFORM_MACOS
    os = "MacOS";
#elif ENGINE_PLATFORM_LINUX
    os = "Linux";
#else
    os = "Unsupported";
#endif

    return os;
}