#ifndef PSO_NETWORK_TSOCKET_H
#define PSO_NETWORK_TSOCKET_H

#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/forward.h"
#include "pso/system/task/TObject.h"

union ipv4_addr {
    u32 addr;
    u8 addr_bytes[4];
};

extern u16 to_be_uint16_t(u16 val);
extern u16 to_le_uint16_t(u16 val);

class TSocket : public TObject {
public:
    ipv4_addr m_dst_addr;
    u16 m_dst_port;
    u16 m_src_port;
    ipv4_addr m_src_addr;
    s16 m_sock_fd;
    char m_is_invalid_packet;
    char m_buffer_cleared;
    s16 m_size;
    s16 m_buffer_offset;
    u32 m_unused;
    u8 m_unused2[64];
    u8 m_packet_buffer[2048];
    s16 m_stat_val;
    u16 m_unused3;
    u32 m_send_window;
    u32 m_recv_window;
    void (*m_callback)(TSocket *socket);
public:
    TSocket(TObject *parent);
    virtual ~TSocket();

    virtual int open() = 0;
    virtual short close() = 0;
    virtual void recv() = 0;
    virtual short send(u8 *data) = 0;
    virtual short send(u8 *data, size_t size) = 0;

    int resolve_domain(char *domain);
    void set_ip_address(u32 addr);
    void set_port(u32 port);
    int is_empty();
};

#endif
