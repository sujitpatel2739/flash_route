#ifndef FLASHSEND_SERVER_HTTPSERVER_H
#define FLASHSEND_SERVER_HTTPSERVER_H

#include <cstdint>
#include <string>

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "RouteHandler.h"
#include "RouteRegistry.h"
#include "TCPServer.h"

namespace flashsend
{
    // HTTP server that accepts TCP connections, parses HTTP requests,
    // dispatches them to registered route handlers, and sends responses.
    //
    // Threading model (MVP):
    // - Blocking I/O
    // - One thread per connection
    class HttpServer
    {
    public:
        // Creates an HTTP server bound to the given port.
        explicit HttpServer(std::uint16_t port);

        // Registers an HTTP route handler.
        void addRoute(HttpMethod method,
                      const std::string &path,
                      RouteHandler handler);

        // Starts the server.
        bool start();

        // Stops the server. Safe to call multiple times.
        void stop();

        // Returns true if the server is currently running.
        bool isRunning() const noexcept;

    private:
        TCPServer server_;
        RouteRegistry routes_;
        bool running_;
    };

} // namespace flashsend

#endif // FLASHSEND_SERVER_HTTPSERVER_H
