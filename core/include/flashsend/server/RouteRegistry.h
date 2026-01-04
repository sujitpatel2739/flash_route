<<<<<<< HEAD
#ifndef FLASHSEND_SERVER_ROUTEREGISTRY_H
#define FLASHSEND_SERVER_ROUTEREGISTRY_H

#include <map>
#include <string>
#include <utility>
#include "RouteHandler.h"
#include "HttpRequest.h"

namespace flashsend
{

    // Stores and resolves HTTP route handlers.
    class RouteRegistry
    {
    public:
        // Registers a handler for a method + path combination.
        void addRoute(HttpMethod method,
                      const std::string &path,
                      RouteHandler handler);

        // Finds a handler for the given method + path.
        // Returns nullptr if no route matches.
        const RouteHandler *findRoute(HttpMethod method,
                                      const std::string &path) const;

    private:
        using RouteKey = std::pair<HttpMethod, std::string>;
        std::map<RouteKey, RouteHandler> routes_;
    };

} // namespace flashsend

#endif // FLASHSEND_SERVER_ROUTEREGISTRY_H
=======
#ifndef FLASHSEND_SERVER_ROUTEREGISTRY_H
#define FLASHSEND_SERVER_ROUTEREGISTRY_H

#include <map>
#include <string>
#include <utility>
#include "RouteHandler.h"
#include "HttpRequest.h"

namespace flashsend
{

    // Stores and resolves HTTP route handlers.
    class RouteRegistry
    {
    public:
        // Registers a handler for a method + path combination.
        void addRoute(HttpMethod method,
                      const std::string &path,
                      RouteHandler handler);

        // Finds a handler for the given method + path.
        // Returns nullptr if no route matches.
        const RouteHandler *findRoute(HttpMethod method,
                                      const std::string &path) const;

    private:
        using RouteKey = std::pair<HttpMethod, std::string>;
        std::map<RouteKey, RouteHandler> routes_;
    };

} // namespace flashsend

#endif // FLASHSEND_SERVER_ROUTEREGISTRY_H
>>>>>>> f7276a6b74000d82beb236e1de8a6310326eba5b
