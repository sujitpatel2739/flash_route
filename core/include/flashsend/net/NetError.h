<<<<<<< HEAD
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
=======
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
>>>>>>> f7276a6b74000d82beb236e1de8a6310326eba5b
