#ifndef PSO_NETWORK_TUDPSOCKET_H
#define PSO_NETWORK_TUDPSOCKET_H

#include "types.h"
#include "pso/macros.h"

EXTERN_OBJECT_NAME(TUdpSocket);

struct TUdpSocket
{
    void release_entry();
    static s32 handle_socket_event(s16 arg0, u8 *arg1);
    static void unlock_mutex(int _w0);
};

#endif
