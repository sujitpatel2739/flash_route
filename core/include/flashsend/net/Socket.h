#ifndef FLASHSEND_NET_SOCKET_H
#define FLASHSEND_NET_SOCKET_H

#include <cstddef>
#include <cstdint>
#include "NetError.h"

namespace flashsend
{

    // Represents a single TCP connection.
    // Owns the underlying OS socket handle (RAII).
    class Socket
    {
    public:
        // Creates an invalid socket.
        Socket() noexcept;

        // Takes ownership of an existing native socket handle.
        explicit Socket(int nativeHandle) noexcept;

        // Closes the socket if valid.
        ~Socket() noexcept;

        // Non-copyable
        Socket(const Socket &) = delete;
        Socket &operator=(const Socket &) = delete;

        // Movable
        Socket(Socket &&other) noexcept;
        Socket &operator=(Socket &&other) noexcept;

        // Returns true if the socket is valid and open.
        bool isValid() const noexcept;

        // Sends data through the socket.
        // bytesSent may be less than size.
        NetError send(const void *data, std::size_t size, std::size_t &bytesSent) noexcept;

        // Receives data from the socket.
        // bytesReceived may be less than size.
        NetError receive(void *buffer, std::size_t size, std::size_t &bytesReceived) noexcept;

        // Closes the socket. Safe to call multiple times.
        void close() noexcept;

    private:
        int socketHandle_; // -1 indicates invalid socket
    };

} // namespace flashsend

#endif // FLASHSEND_NET_SOCKET_H
