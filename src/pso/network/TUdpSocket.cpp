#include "types.h"
#include "pso/network/TUdpSocket.h"

extern "C" {

void *TUdpSocket__ct(void *arg0);
void __ct__7TSocketFP7TObject(void *);

extern s32 __vt__10TUdpSocket[];

void *TUdpSocket__ct(void *socket) {
    __ct__7TSocketFP7TObject(socket);
    *(s32 **)((s8 *)socket + 0x18) = __vt__10TUdpSocket;
    *(const char **)((s8 *)socket + 0x0) = TUdpSocket_name;
    return socket;
}

}
