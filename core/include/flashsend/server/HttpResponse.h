<<<<<<< HEAD
#ifndef FLASHSEND_SERVER_HTTPRESPONSE_H
#define FLASHSEND_SERVER_HTTPRESPONSE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>

namespace flashsend
{
    // Supported HTTP response statuses
    enum class HttpStatus
    {
        OK,                 // 200
        BadRequest,         // 400
        Unauthorized,       // 401
        NotFound,           // 404
        InternalServerError // 500
    };

    // Type alias for headers
    using HeaderMap = std::unordered_map<std::string, std::string>;

    // Immutable representation of an HTTP response.
    class HttpResponse
    {
    public:
        // Constructs an HTTP response with status, headers, and body.
        HttpResponse(HttpStatus status,
                     HeaderMap headers,
                     std::vector<std::uint8_t> body) noexcept;

        // Read-only accessors  
        HttpStatus status() const noexcept;
        const HeaderMap &headers() const noexcept;
        const std::vector<std::uint8_t> &body() const noexcept;

        // Header mutation (used during response building)
        void setHeader(const std::string &name,
                       const std::string &value);

    private:
        HttpStatus status_;
        HeaderMap headers_;
        std::vector<std::uint8_t> body_;
    };

} // namespace flashsend

#endif // FLASHSEND_SERVER_HTTPRESPONSE_H
=======
#ifndef FLASHSEND_SERVER_HTTPRESPONSE_H
#define FLASHSEND_SERVER_HTTPRESPONSE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>

namespace flashsend
{
    // Supported HTTP response statuses
    enum class HttpStatus
    {
        OK,                 // 200
        BadRequest,         // 400
        Unauthorized,       // 401
        NotFound,           // 404
        InternalServerError // 500
    };

    // Type alias for headers
    using HeaderMap = std::unordered_map<std::string, std::string>;

    // Immutable representation of an HTTP response.
    class HttpResponse
    {
    public:
        // Constructs an HTTP response with status, headers, and body.
        HttpResponse(HttpStatus status,
                     HeaderMap headers,
                     std::vector<std::uint8_t> body) noexcept;

        // Read-only accessors  
        HttpStatus status() const noexcept;
        const HeaderMap &headers() const noexcept;
        const std::vector<std::uint8_t> &body() const noexcept;

        // Header mutation (used during response building)
        void setHeader(const std::string &name,
                       const std::string &value);

    private:
        HttpStatus status_;
        HeaderMap headers_;
        std::vector<std::uint8_t> body_;
    };

} // namespace flashsend

#endif // FLASHSEND_SERVER_HTTPRESPONSE_H
>>>>>>> f7276a6b74000d82beb236e1de8a6310326eba5b
