<<<<<<< HEAD
#ifndef FLASHSEND_SESSION_SESSION_H
#define FLASHSEND_SESSION_SESSION_H

#include <ctime>
#include "Token.h"

namespace flashsend
{
    // Represents a single sharing session.
    // A session has a fixed lifetime and can be explicitly revoked.
    class Session
    {
    public:
        // Creates a session with a token, start time, and expiry time.
        // The session is considered valid until expiry or revocation.
        explicit Session(const Token &token,
                         std::time_t startTime,
                         std::time_t expiryTime);

        // Read-only accessors
        const Token &token() const;
        std::time_t startTime() const;
        std::time_t expiryTime() const;

        // State checks
        bool isExpired() const;
        bool isValid() const;

        // Explicitly revoke this session
        void revoke();

    private:
        Token token_;
        std::time_t startTime_;
        std::time_t expiryTime_;
        bool revoked_;
    };

} // namespace flashsend

#endif // FLASHSEND_SESSION_SESSION_H
=======
#ifndef FLASHSEND_SESSION_SESSION_H
#define FLASHSEND_SESSION_SESSION_H

#include <ctime>
#include "Token.h"

namespace flashsend
{
    // Represents a single sharing session.
    // A session has a fixed lifetime and can be explicitly revoked.
    class Session
    {
    public:
        // Creates a session with a token, start time, and expiry time.
        // The session is considered valid until expiry or revocation.
        explicit Session(const Token &token,
                         std::time_t startTime,
                         std::time_t expiryTime);

        // Read-only accessors
        const Token &token() const;
        std::time_t startTime() const;
        std::time_t expiryTime() const;

        // State checks
        bool isExpired() const;
        bool isValid() const;

        // Explicitly revoke this session
        void revoke();

    private:
        Token token_;
        std::time_t startTime_;
        std::time_t expiryTime_;
        bool revoked_;
    };

} // namespace flashsend

#endif // FLASHSEND_SESSION_SESSION_H
>>>>>>> f7276a6b74000d82beb236e1de8a6310326eba5b
