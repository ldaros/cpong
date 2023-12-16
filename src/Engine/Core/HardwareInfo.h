#ifndef CPONG_HARDWAREINFO_H
#define CPONG_HARDWAREINFO_H

#include <string>

class HardwareInfo {
public:
    static std::string GetCPUCoreCount();

    static std::string GetRAMTotal();

    static std::string GetRAMAvailable();
};

#endif //CPONG_HARDWAREINFO_H
