#ifndef FLASHSEND_SERVER_ROUTEHANDLER_H
#define FLASHSEND_SERVER_ROUTEHANDLER_H

#include <functional>

#include "HttpRequest.h"
#include "HttpResponse.h"

namespace flashsend
{

    // A RouteHandler processes an HTTP request and returns a response.
    // Handlers must be side-effect free with respect to networking.
    // They must not read from or write to sockets directly.
    using RouteHandler = std::function<HttpResponse(const HttpRequest &)>;

} // namespace flashsend

#endif // FLASHSEND_SERVER_ROUTEHANDLER_H
