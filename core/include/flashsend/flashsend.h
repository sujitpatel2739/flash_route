#ifndef FLASHSEND_CORE_FLASHSEND_H
#define FLASHSEND_CORE_FLASHSEND_H

#include <string>
#include <vector>
#include <cstdint>
#include <ctime>

namespace flashsend
{
    enum class ErrorCode
    {
        None,
        AlreadyRunning,
        NotRunning,
        InvalidConfig,
        FileNotFound,
        FileTooLarge,
        SessionExpired,
        InternalError
    };

    struct Config
    {
        int serverPort;            // e.g. 8080
        uint64_t maxFileSizeBytes; // e.g. 50 * 1024 * 1024
        int sessionTimeoutSeconds; // e.g. 300
        int maxConcurrentClients;  // e.g. 10
        std::string webAssetsPath; // path to /web folder
        bool enableLogging;
    };

    class FlashSend
    {
    public:
        // Lifecycle
        explicit FlashSend(const Config &config);
        ~FlashSend();

        bool start();
        void stop();
        bool isRunning() const;

        // File management
        bool addFile(const std::string &absolutePath);
        bool addFiles(const std::vector<std::string> &absolutePaths);
        void clearFiles();
        int sharedFileCount() const;

        // Session & Access
        std::string sessionToken() const;
        std::string serverUrl() const;
        std::time_t sessionExpiryTime() const;

        // Error handling
        ErrorCode lastError() const;

        // Threading contract:
        // All public methods must be called from the same thread
        // except isRunning(), lastError(), and sessionExpiryTime()
        // which are safe for concurrent reads.

    private:
        // Opaque internal pointer (PIMPL pattern)
        struct Impl;
        Impl *impl_;
    };

}

#endif
#ifndef FLASHSEND_CORE_FLASHSEND_H
#define FLASHSEND_CORE_FLASHSEND_H

#include <string>
#include <vector>
#include <cstdint>
#include <ctime>

namespace flashsend
{
    enum class ErrorCode
    {
        None,
        AlreadyRunning,
        NotRunning,
        InvalidConfig,
        FileNotFound,
        FileTooLarge,
        SessionExpired,
        InternalError
    };

    struct Config
    {
        int serverPort;            // e.g. 8080
        uint64_t maxFileSizeBytes; // e.g. 50 * 1024 * 1024
        int sessionTimeoutSeconds; // e.g. 300
        int maxConcurrentClients;  // e.g. 10
        std::string webAssetsPath; // path to /web folder
        bool enableLogging;
    };

    class FlashSend
    {
    public:
        // Lifecycle
        explicit FlashSend(const Config &config);
        ~FlashSend();

        bool start();
        void stop();
        bool isRunning() const;

        // File management
        bool addFile(const std::string &absolutePath);
        bool addFiles(const std::vector<std::string> &absolutePaths);
        void clearFiles();
        int sharedFileCount() const;

        // Session & Access
        std::string sessionToken() const;
        std::string serverUrl() const;
        std::time_t sessionExpiryTime() const;

        // Error handling
        ErrorCode lastError() const;

        // Threading contract:
        // All public methods must be called from the same thread
        // except isRunning(), lastError(), and sessionExpiryTime()
        // which are safe for concurrent reads.

    private:
        // Opaque internal pointer (PIMPL pattern)
        struct Impl;
        Impl *impl_;
    };

}

#endif