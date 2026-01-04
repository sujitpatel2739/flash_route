#include "Socket.h"
#include <unistd.h>
#include <sys/socket.h>
#include <utility>

namespace flashsend
{
    Socket::Socket() noexcept : socketHandle_(-1) {}

    Socket::Socket(int nativeHandle) noexcept : socketHandle_(nativeHandle) {}

    Socket::~Socket() noexcept
    {
        this->close();
        this->socketHandle_ = -1;
    }

    Socket::Socket(Socket &&other) noexcept : socketHandle_(other.socketHandle_)
    {
        if (this != &other)
        {
            close();
            socketHandle_ = other.socketHandle_;
            other.socketHandle_ = -1;
        }
    }

    Socket &Socket::operator=(Socket &&other) noexcept
    {
        if (this != &other)
        {
            close();
            socketHandle_ = other.socketHandle_;
            other.socketHandle_ = -1;
        }
        return *this;
    }

    bool Socket::isValid() const noexcept
    {
        return this->socketHandle_ != -1;
    }

    NetError Socket::send(const void *data, std::size_t size, std::size_t &bytesSent) noexcept
    {
        if (!isValid())
            return NetError::InvalidSocket;

        ssize_t result = ::send(socketHandle_, data, size, 0);
        if (result > 0)
        {
            bytesSent = static_cast<std::size_t>(result);
            return NetError::None;
        }
        bytesSent = 0;
        if (result < 0)
        {
            return NetError::SendFailed;
        }
        else
        {
            return NetError::ConnectionClosed;
        }
    }

    NetError Socket::receive(void *buffer, std::size_t size, std::size_t &bytesReceived) noexcept
    {
        if (!isValid())
            return NetError::InvalidSocket;

        ssize_t result = ::recv(socketHandle_, buffer, size, 0);
        if (result > 0)
        {
            bytesReceived = static_cast<std::size_t>(result);
            return NetError::None;
        }
        bytesReceived = 0;
        if (result < 0)
        {
            return NetError::SendFailed;
        }
        else
        {
            return NetError::ConnectionClosed;
        }
    }

    void Socket::close() noexcept
    {
        if (!isValid)
        {
            ::close(socketHandle_);
            this->socketHandle_ = -1;
        }
    }
}