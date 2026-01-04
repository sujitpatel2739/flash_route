#ifndef FLASHSEND_NET_NETERROR_H
#define FLASHSEND_NET_NETERROR_H

namespace flashsend
{
    enum class NetError
    {
        None,
        BindFailed,
        ListenFailed,
        AcceptFailed,
        SendFailed,
        ReceiveFailed,
        ConnectionClosed,
        InvalidSocket,
        Unknown,
    };

    const char *toString(NetError e);

} // namespace flashsend

#endif // FLASHSEND_NET_NETERROR_H
