#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

std::unique_ptr<std::ofstream> Logger::log_file;
std::mutex Logger::log_mutex;
std::string Logger::log_path_;

void Logger::Trace(std::string_view sv) {
    Log(Level::LTrace, sv);
}

void Logger::Info(std::string_view sv) {
    Log(Level::LInfo, sv);
}

void Logger::Warn(std::string_view sv) {
    Log(Level::LWarn, sv);
}

void Logger::Error(std::string_view sv) {
    Log(Level::LError, sv);
}

void Logger::Critical(std::string_view sv) {
    Log(Level::LCritical, sv);
}

void Logger::Log(Logger::Level level, std::string_view sv) {
    std::lock_guard<std::mutex> lock(log_mutex);

    if (log_path_.empty()) {
        throw std::runtime_error("Logger not initialized.");
    }

    if (!log_file) {
        log_file = std::make_unique<std::ofstream>(log_path_, std::ios::app);
        if (!log_file->is_open()) {
            throw std::runtime_error("Failed to open log file.");
        }
    }

    *log_file << GetTimestamp() << " [" << GetLevelString(level) << "] " << sv << std::endl;
}


std::string Logger::GetLevelString(Logger::Level level) {
    switch (level) {
        case LTrace:
            return "TRACE";
        case LInfo:
            return "INFO";
        case LWarn:
            return "WARN";
        case LError:
            return "ERROR";
        case LCritical:
            return "CRITICAL";
        default:
            return "UNKNOWN";
    }
}

std::string Logger::GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::tm tm{};
    localtime_s(&tm, &in_time_t);

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %X");
    return ss.str();
}

void Logger::Initialize(std::string_view log_path) {
    log_path_ = log_path;
}
