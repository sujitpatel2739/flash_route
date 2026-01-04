#ifndef FLASHSEND_UTILS_STRING_H
#define FLASHSEND_UTILS_STRING_H

#include <string>
#include <vector>

namespace flashsend
{

// Collection of safe, stateless string utility functions
// used primarily for URL handling and HTTP-related operations.
class StringUtil
{
public:
    // URL-encodes the input string (RFC 3986 compatible).
    static std::string urlEncode(const std::string& input);

    // Decodes a URL-encoded string.
    static std::string urlDecode(const std::string& input);

    // Joins multiple strings using the given delimiter.
    static std::string join(const std::vector<std::string>& parts,
                            const std::string& delimiter);

    // Extracts the filename component from a path.
    static std::string basename(const std::string& path);

private:
    // Prevent instantiation
    StringUtil() = delete;
};

} // namespace flashsend

#endif // FLASHSEND_UTILS_STRING_H
