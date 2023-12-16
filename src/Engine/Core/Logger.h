#ifndef CPONG_LOGGER_H
#define CPONG_LOGGER_H

#include <memory>
#include <fstream>
#include <string>
#include <mutex>

class Logger {
public:
    enum Level {
        LTrace,
        LInfo,
        LWarn,
        LError,
        LCritical
    };

    static void Initialize(std::string_view log_path);

    static void Trace(std::string_view sv);

    static void Info(std::string_view sv);

    static void Warn(std::string_view sv);

    static void Error(std::string_view sv);

    static void Critical(std::string_view sv);

private:
    static void Log(Level level, std::string_view sv);

    static std::string GetLevelString(Level level);

    static std::string GetTimestamp();

    static std::string log_path_;

    static std::unique_ptr<std::ofstream> log_file;

    static std::mutex log_mutex;
};

#endif //CPONG_LOGGER_H
