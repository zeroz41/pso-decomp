#include "types.h"
#include "pso/network/TTcpSocket_801E0BB4.h"
#include "pso/network/TTcpSocket.h"

extern "C" {

void __ct__18PSOV3EncryptionTCPFv(void *);
void __ct__7TSocketFP7TObject(void *);

extern s32 __vt__10TTcpSocket[];
extern void *TTcpSocket__class_name;

void *__ct__10TTcpSocketFP7TObject(void *tcp_socket) {
    __ct__7TSocketFP7TObject(tcp_socket);
    *(s32 **)((s8 *)tcp_socket + 0x18) = __vt__10TTcpSocket;
    __ct__18PSOV3EncryptionTCPFv((void *)((char *)tcp_socket + 2180));
    __ct__18PSOV3EncryptionTCPFv((void *)((char *)tcp_socket + 4284));
    *(void * *)&((TTcpSocket *)tcp_socket)->m_name = TTcpSocket__class_name;
    return tcp_socket;
}

}
