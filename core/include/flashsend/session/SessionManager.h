<<<<<<< HEAD
#ifndef FLASHSEND_SESSION_SESSIONMANAGER_H
#define FLASHSEND_SESSION_SESSIONMANAGER_H

#include <ctime>
#include <memory>
#include "Session.h"
#include "Token.h"

namespace flashsend
{

    // Manages the lifecycle of a single active sharing session.
    // Responsible for session creation, expiration, validation, and revocation.
    class SessionManager
    {
    public:
        // sessionTimeoutSeconds defines how long a session remains valid
        explicit SessionManager(int sessionTimeoutSeconds);

        // Session lifecycle control
        void startNewSession();
        void endSession();

        // Session state queries
        bool hasActiveSession() const;
        bool isTokenValid(const Token &token) const;

        // Read-only session information
        Token currentToken() const;
        std::time_t sessionExpiryTime() const;

    private:
        std::unique_ptr<Session> session_;
        int sessionTimeoutSeconds_;
    };

} // namespace flashsend

#endif // FLASHSEND_SESSION_SESSIONMANAGER_H
=======
#ifndef FLASHSEND_SESSION_SESSIONMANAGER_H
#define FLASHSEND_SESSION_SESSIONMANAGER_H

#include <ctime>
#include <memory>
#include "Session.h"
#include "Token.h"

namespace flashsend
{

    // Manages the lifecycle of a single active sharing session.
    // Responsible for session creation, expiration, validation, and revocation.
    class SessionManager
    {
    public:
        // sessionTimeoutSeconds defines how long a session remains valid
        explicit SessionManager(int sessionTimeoutSeconds);

        // Session lifecycle control
        void startNewSession();
        void endSession();

        // Session state queries
        bool hasActiveSession() const;
        bool isTokenValid(const Token &token) const;

        // Read-only session information
        Token currentToken() const;
        std::time_t sessionExpiryTime() const;

    private:
        std::unique_ptr<Session> session_;
        int sessionTimeoutSeconds_;
    };

} // namespace flashsend

#endif // FLASHSEND_SESSION_SESSIONMANAGER_H
>>>>>>> f7276a6b74000d82beb236e1de8a6310326eba5b
