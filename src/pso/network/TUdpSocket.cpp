#include "types.h"

extern "C" {

void *TUdpSocket__ct(void *arg0);
void __ct__7TSocketFP7TObject(void *);

extern s32 __vt__10TUdpSocket[];
extern void *TUdpSocket__class_name;

void *TUdpSocket__ct(void *socket) {
    __ct__7TSocketFP7TObject(socket);
    *(s32 **)((s8 *)socket + 0x18) = __vt__10TUdpSocket;
    *(void **)((s8 *)socket + 0x0) = TUdpSocket__class_name;
    return socket;
}

}
