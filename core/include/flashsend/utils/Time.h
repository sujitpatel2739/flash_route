#ifndef FLASHSEND_UTILS_TIME_H
#define FLASHSEND_UTILS_TIME_H

#include <ctime>

namespace flashsend
{

// Centralized time utility.
// All engine code must use this instead of calling std::time() directly.
class Time
{
public:
    // Returns current wall-clock time in seconds since epoch.
    static std::time_t now();

    // Overrides current time (used for testing).
    static void setOverride(std::time_t fakeTime);

    // Clears any active time override.
    static void clearOverride();

    // Returns true if time is currently overridden.
    static bool isOverridden();

private:
    static bool overridden_;
    static std::time_t overriddenTime_;
};

} // namespace flashsend

#endif // FLASHSEND_UTILS_TIME_H
