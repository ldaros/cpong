#include "HardwareInfo.h"
#include <windows.h>
#include <string>

std::string HardwareInfo::GetCPUCoreCount() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return std::to_string(sysInfo.dwNumberOfProcessors);
}

std::string HardwareInfo::GetRAMTotal() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    if (GlobalMemoryStatusEx(&statex)) {
        return std::to_string(statex.ullTotalPhys / 1024 / 1024) + " MB";
    }
    return "Not available";
}

std::string HardwareInfo::GetRAMAvailable() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    if (GlobalMemoryStatusEx(&statex)) {
        return std::to_string(statex.ullAvailPhys / 1024 / 1024) + " MB";
    }
    return "Not available";
}
