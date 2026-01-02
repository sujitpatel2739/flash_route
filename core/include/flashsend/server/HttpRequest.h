#ifndef FLASHSEND_SERVER_HTTPREQUEST_H
#define FLASHSEND_SERVER_HTTPREQUEST_H

#include <string>
#include <unordered_map>
#include <vector>

namespace flashsend
{
    // Supported HTTP methods
    enum class HttpMethod
    {
        GET,
        POST,
        HEAD,
        PUT,
        DELETE,
        UNKNOWN
    };

    // Type aliases for clarity
    using HeaderMap = std::unordered_map<std::string, std::string>;
    using QueryParams = std::unordered_map<std::string, std::string>;

    // Immutable representation of an HTTP request.
    class HttpRequest
    {
    public:
        // Constructs a fully-initialized HTTP request.
        HttpRequest(HttpMethod method,
                    std::string path,
                    HeaderMap headers,
                    QueryParams queryParams,
                    std::vector<std::uint8_t> body) noexcept;

        // Read-only accessors
        HttpMethod method() const noexcept;
        const std::string &path() const noexcept;
        const HeaderMap &headers() const noexcept;
        const QueryParams &queryParams() const noexcept;
        const std::vector<std::uint8_t> &body() const noexcept;

        // Header helpers
        bool hasHeader(const std::string &name) const noexcept;
        const std::string &header(const std::string &name) const;

    private:
        HttpMethod method_;
        std::string path_;
        HeaderMap headers_;
        QueryParams queryParams_;
        std::vector<std::uint8_t> body_;
    };

} // namespace flashsend

#endif // FLASHSEND_SERVER_HTTPREQUEST_H
