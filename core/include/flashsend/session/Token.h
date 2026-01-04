#ifndef FLASHSEND_SESSION_TOKEN_H
#define FLASHSEND_SESSION_TOKEN_H

#include <string>

namespace flashsend
{

    // Represents an access token for a single sharing session.
    // Token objects are immutable value types.
    class Token
    {
    public:
        // Creates an invalid token.
        Token();

        // Factory method to generate a new valid token.
        // Actual generation logic is hidden in implementation.
        static Token generate();

        // Returns string representation of the token
        // (used for URLs, QR codes, etc.).
        std::string toString() const;

        // Returns true if this token represents a valid session.
        bool isValid() const;

        // Equality comparison
        bool operator==(const Token &other) const;
        bool operator!=(const Token &other) const;

    private:
        // Internal token representation (opaque to users)
        std::string value_;
    };

} // namespace flashsend

#endif // FLASHSEND_SESSION_TOKEN_H
