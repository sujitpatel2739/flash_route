#ifndef FLASHSEND_NET_TCPSERVER_H
#define FLASHSEND_NET_TCPSERVER_H

#include <cstdint>

#include "NetError.h"
#include "Socket.h"

namespace flashsend
{
    // TCP server that listens on a port and accepts incoming connections.
    // Does not spawn threads and does not handle protocols.
    class TcpServer
    {
    public:
        // Creates a server bound to the given port.
        explicit TcpServer(std::uint16_t port) noexcept;

        // Starts listening on the port.
        NetError start() noexcept;

        // Stops listening and closes the server socket.
        void stop() noexcept;

        // Returns true if the server is currently listening.
        bool isRunning() const noexcept;

        // Accepts an incoming connection.
        // On success, returns a valid Socket.
        // On failure, returns an invalid Socket.
        Socket accept(NetError &outError) noexcept;

    private:
        std::uint16_t port_;
        int listenSocket_; // native listening socket (-1 if invalid)
        bool running_;
    };

} // namespace flashsend

#endif // FLASHSEND_NET_TCPSERVER_H
