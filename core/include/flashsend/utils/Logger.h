#ifndef FLASHSEND_UTILS_LOGGER_H
#define FLASHSEND_UTILS_LOGGER_H

#include <string>
#include <mutex>

namespace flashsend
{

// Logging severity levels
enum class LogLevel
{
    Trace,
    Debug,
    Info,
    Warn,
    Error,
    Fatal
};

// Thread-safe, static logging utility.
// No instances allowed.
class Logger
{
public:
    // Initializes global logging configuration.
    // Safe to call multiple times.
    static void init(bool enableLogging, LogLevel level);

    // Convenience logging methods
    static void trace(const std::string& message);
    static void debug(const std::string& message);
    static void info(const std::string& message);
    static void warn(const std::string& message);
    static void error(const std::string& message);
    static void fatal(const std::string& message);

private:
    // Core logging sink
    static void log(LogLevel level, const std::string& message);

    static LogLevel currentLogLevel_;
    static bool loggingEnabled_;
    static std::mutex logMutex_;
};

} // namespace flashsend

#endif // FLASHSEND_UTILS_LOGGER_H
