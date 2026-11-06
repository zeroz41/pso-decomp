#ifndef PSO_NETWORK_TTCPSOCKET_H
#define PSO_NETWORK_TTCPSOCKET_H

#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/forward.h"
#include "pso/TSocket.h"
#include "pso/TObject.h"
#include "pso/PSOV3EncryptionTCP.h"

EXTERN_OBJECT_NAME(TTcpSocket);
extern TTcpSocket *tcp_socket_table[16];

class TTcpSocket : public TSocket {
public:
    PSOV3EncryptionTCP m_send_crypt;
    PSOV3EncryptionTCP m_recv_crypt;
    int m_is_encrypted;
public:
    TTcpSocket(TObject *parent) : TSocket(parent) {
        m_name = TTcpSocket_name;
    }

    virtual ~TTcpSocket();

    virtual int open();
    virtual short close();
    virtual void recv();
    virtual short send(u8 *data);
    virtual short send(u8 *data, size_t size);

    short stat();
    void some_stub();
    int test_connection();

    static void notify(short size, short sock_fd);
};

extern "C" {
void *__dt__10TUdpSocketFv(void *arg0, s16 arg1);
}

#endif
