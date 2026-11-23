#include "types.h"
#include <string.h>
#include "pso/player/TPlySmth.h"
#include "pso/network/TPlyMeetUserExtension_801DAC6C.h"
#include "pso/unk/text_801DF280.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3EncryptionTCP.h"
#include "pso/network/TSocket.h"
#include "pso/network/TProtocol.h"

struct Tags_801DAC6C { u32 w[16]; };

struct Nm_801DAC6C { char c[16]; };

struct Ext_801DAC6C { Tags_801DAC6C tags; u32 m; Nm_801DAC6C a; Nm_801DAC6C b; };


extern "C" {
Ext_801DAC6C *__as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(Ext_801DAC6C *arg0, const Ext_801DAC6C *arg1);
s32 set_port__7TSocketFUl(void *, s16);

struct BaseDA { char pad[0x18]; };
struct VObjDA : BaseDA {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
Ext_801DAC6C *__as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(Ext_801DAC6C *ext, const Ext_801DAC6C *arg1) {
    ext->tags = arg1->tags;
    ext->m = arg1->m;
    ext->a = arg1->a;
    ext->b = arg1->b;
    return ext;
}

void TProtocol::handle_cmd_9A(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    m_regist_state = header.flags;
    if (m_recv_handlers.handle_18_90_9A_recv_pso_regist_check != NULL) {
        m_recv_handlers.handle_18_90_9A_recv_pso_regist_check(header.flags);
    }
}

void TProtocol::handle_cmd_9B(packet &pkt) {
    TRecvPsoRegistConnect tmp = as(TRecvPsoRegistConnect &, pkt);
    tmp.bswap();
    if (!strcmp(port_map_copyright, tmp.copyright)) {
        m_recv_crypt.reset(tmp.server_key);
        m_send_crypt.reset(tmp.client_key);
        m_is_encrypted = true;
        TSendVerifyLicense tmp2;
        memset(&tmp2, 0, sizeof(tmp2));
        tmp2.header.command = 0xDB;
        tmp2.header.size = sizeof(tmp2);
        strncpy(tmp2.serial_number_v1, m_serial_number_v1, sizeof(tmp2.serial_number_v1));
        strncpy(tmp2.access_key_v1, m_access_key_v1, sizeof(tmp2.access_key_v1));
        strncpy(tmp2.serial_number, m_serial_number2, sizeof(tmp2.serial_number));
        strncpy(tmp2.access_key, m_access_key2, sizeof(tmp2.access_key));
        tmp2.hardware_id = m_smth;
        tmp2.sub_version = m_sub_version;
        strncpy(tmp2.serial_number2, m_serial_number, sizeof(tmp2.serial_number2));
        strncpy(tmp2.access_key2, m_access_key, sizeof(tmp2.access_key2));
        strncpy(tmp2.password, m_password, sizeof(tmp2.password));
        tmp2.bswap();
        send(as(u8 *, &tmp2), sizeof(tmp2));
    } else {
        close();
    }
}

s32 socket_set_server_info(TProtocol *protocol, const char *serial_v1, const char *access_key_v1, const char *serial,
                           const char *access_key, const char *host, u16 port) {
    s32 error;

    error = protocol->resolve_domain((char *)host);
    set_port__7TSocketFUl(protocol, port);
    if (error != 0) {
        return 2;
    }
    memset(protocol->m_serial_number_v1, 0, 0x11);
    memset(protocol->m_access_key_v1, 0, 0x11);
    memset(protocol->m_serial_number2, 0, 0x11);
    memset(protocol->m_access_key2, 0, 0x11);
    strncpy(protocol->m_serial_number_v1, serial_v1, 8);
    strncpy(protocol->m_access_key_v1, access_key_v1, 0xC);
    strncpy(protocol->m_serial_number2, serial, 8);
    strncpy(protocol->m_access_key2, access_key, 0xC);
    if (protocol->open() < 0) {
        return 1;
    }
    protocol->recv();
    return 0;
}

}
