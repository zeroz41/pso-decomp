#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TUdpSocket.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_803F76F4_lbl_805A9008 {
    s32 value;
    u8 remaining[0x108C];
};

struct RecoveredGlobal_803F7790_lbl_805A9008 {
    s32 value;
    u8 remaining[0x108C];
};

struct NetworkPacketBufferStorage {
    u8 packet_slots[4][1500];
    u32 workspace_70_a[70];
    u32 workspace_550_a[550];
    u32 workspace_550_b[550];
    u32 workspace_1030[1030];
    u32 workspace_70_b[70];
    u32 workspace_550_pair[2][550];
};
typedef char NetworkPacketBufferStorage_size[sizeof(NetworkPacketBufferStorage) == 0x4C18 ? 1 : -1];

struct RecoveredGlobal_803F79C0_lbl_805A9008 {
    s32 value;
    u8 remaining[0x108C];
};

struct RecoveredGlobal_803F7A30_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};

struct E_803F7684 { u32 key; s32 val; };

struct P_803F7A90 { s32 a; s32 b; };

struct Q_803F7AF4 { s32 a; s32 b; };

struct A_803F8314 {
    u8 pad[0x1A];
    s16 flag;
    char *name;
};

struct H_803F8470 {
    s16 a;
    s16 b;
    u16 n1;
    u16 n2;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
};

struct T_803F86C0 { s16 a; s16 b; s16 c; };

struct Cfg_803F86C0 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    T_803F86C0 *fC;
    s16 f10;
    s16 f12;
    u8 *f14;
    s16 f18;
    s16 f1A;
    s16 f1C;
    s16 f1E;
    u8 *f20;
    s16 f24;
    s16 f26;
    u8 *f28;
    s16 f2C;
    s16 f2E;
    s16 f30;
    s16 f32;
    u8 *f34;
    u8 *f38;
    u8 *f3C;
    s16 f40;
    s16 f42;
    u8 *f44;
};

struct Sub_803F77E4 {
    s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; u8 padA[2];
    void *fC; void *f10; void *f14; void *f18; void *f1C; void *f20; void *f24; void *f28;
    void *f2C; void *f30; void *f34; s8 f38; u8 pad39[3]; void *f3C; void *f40; s32 f44;
};

struct Obj_803F77E4 {
    u8 *f0; s16 f4; u8 *f8; s16 fC; s16 fE; u8 *f10; s16 f14; void *f18; s16 f1C;
    u8 *f20; u8 *f24; u8 *f28; u8 *f2C; u8 *f30; u8 *f34; u8 *f38;
    s16 f3C; s16 f3E; s16 f40; s16 f42; s16 f44; s16 f46; s16 f48;
    Sub_803F77E4 *f4C;
};

struct Info_803F861C {
    s16 a;
    s16 b;
    u16 c;
    u16 d;
    s32 e;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
};

extern NetworkPacketBufferStorage network_packet_buffer_storage;
extern s32 lbl_805D7A00;
extern "C" {
void TLobby__sub_803F97E8(s32);
s32 TLobby__sub_80428094(s16);
void TAdSinglePlyChrSelectGC__sub_8042D604(void);
extern s16 net_slot_id;
extern s32 queue_thread_handle;
extern u32 TLobby__send_ring_mutex;
extern s16 network_pppoe_transport_enabled;
void TLobby__sub_803F8238(void);
extern RecoveredGlobal_803F7A30_lbl_805C18A0 lbl_805C18A0;
extern s32 send_ring_buffer_base;
extern s32 lobby_ring_buffer_size;
extern s16 lbl_805D47F8;
extern u16 net_param_player_count;
extern u16 net_param_room_count;
extern s32 lbl_805D4800;
extern s16 lbl_805D4804;
extern s32 lbl_805D4808;
extern s32 lbl_805D480C;
extern s32 net_param_word_h;
extern s32 net_param_word_i;
extern s32 lobby_map_state_code;
extern E_803F7684 lbl_804FD350[];
s32 TLobby__sub_803F7684(void *arg0);
extern u8 run_net_thread_loop__6TLobbyFv[];
s16 TLobby__sub_803F96AC(void *);
s16 TLobby__sub_803F9B94(void *, void *);
void TLobby__sub_803F7A90(void);
s32 TAdSinglePlyChrSelectGC__sub_8042DD70(s32 arg0, s32 arg1, s32 arg2);
s32 TAdSinglePlyChrSelectGC__sub_8042E184(void);
s32 TAdSinglePlyChrSelectGC__sub_8042E320(s32, s32, void *);
}
extern s32 TLobby__queue_timeout_remaining;
void subtract_network_queue_timeout(s32 arg0);
void set_lobby_map_state_code(s32 arg0);
extern "C" {
s32 TLobby__sub_803F8090(void);
extern s32 lobby_send_ring_read_pos;
extern s32 lobby_send_ring_pending_bytes;
extern Q_803F7AF4 TLobby__next_send_chunk;
extern s32 lobby_send_chunk_size;
Q_803F7AF4 *get_next_send_chunk__6TLobbyFv(void);
s32 OSIsThreadSuspended(s32);
extern s32 lobby_ring_buffer_write_pos;
s16 TLobby__sub_804281DC(void *);
s32 TAdSinglePlyChrSelectGC__sub_8042CEF8(char *);
void TAdSinglePlyChrSelectGC__sub_8042E488(s32);
extern u8 pppoe_discovery_name_storage[2][256];
s32 TLobby__sub_803F8314(A_803F8314 *arg0);
u32 layout_buffers__6TLobbyFPUcPUc(u8 *, u32, u32);
extern u32 net_transport_buffer_ptr_a;
extern u32 net_transport_buffer_ptr_b;
s32 TLobby__sub_803F8470(u8 *data, s32 size);
extern u8 lobby_net_config_block[];
extern T_803F86C0 lbl_805D7A50;
s32 TAdSinglePlyChrSelectGC__sub_8042D49C(int);
s32 TLobby__sub_803F7E50(s32 arg0, s32 arg1, s32 arg2, s32 n, s32 p);
s32 TAdSinglePlyChrSelectGC__sub_8042D7E0(void *);
s32 TLobby__sub_803F812C(u16 arg0, void *arg1, u16 *arg2);
s32 TLobby__sub_803F8D24(Info_803F861C *);
s32 TLobby__sub_803F861C(Info_803F861C *arg0);
s16 TLobby__sub_80427F48(s16, u8 *, u16);
s32 send_network_frame(u16 arg0, u8 *arg1);
void TLobby__sub_803F7678(void);
s32 TLobby__sub_803F767C(void);
void TLobby__sub_803F76F0(void);
void TLobby__sub_803F778C(void);
void TLobby__sub_803F77E0(void);
void TLobby__sub_803F7980(void);
void TLobby__sub_803F79AC(void);
void TLobby__sub_803F79B0(u8 *arg0);
void TLobby__sub_803F79BC(void);
void TLobby__sub_803F808C(void);
s32 TLobby__sub_803F811C(s16 *arg0);
void TLobby__sub_803F86BC(void);

extern s32 lbl_805D79F8;

__declspec(section ".sdata2") extern const char modem_tone_dial_command[] = "ATDT";
__declspec(section ".sdata2") extern const char modem_pulse_dial_command[] = "ATDP";
__declspec(section ".sdata2") extern const char modem_answer_command[] = "ATA";
__declspec(section ".sdata2") extern const char modem_ok_response[] = "OK";
__declspec(section ".sdata2") extern const char modem_connect_response[] = "CONNECT";
__declspec(section ".sdata2") extern const char modem_busy_response[] = "BUSY";
__declspec(section ".sdata2") extern const char modem_error_response[] = "ERROR";
__declspec(section ".sdata2") extern const char modem_delayed_response[] = "DELAYED";
__declspec(section ".sdata2") extern const char modem_ring_response[] = "RING";
__declspec(section ".sdata2") extern const char modem_default_connect_argument[] = "00";

u8 lbl_805A9008[0xA88];
u8 lbl_805A9A90[0x60];
u8 lbl_805A9AF0[0x80];
u8 lbl_805A9B70[0x80];
u8 lbl_805A9BF0[0x80];
u8 lbl_805A9C70[0x80];
u8 lbl_805A9CF0[0x80];
u8 lbl_805A9D70[0x80];
u8 lbl_805A9DF0[0x80];
u8 lbl_805A9E70[0x10];
u8 lbl_805A9E80[0x200];
u8 lbl_805AA080[0x18];
NetworkPacketBufferStorage network_packet_buffer_storage;
u8 pppoe_discovery_name_storage[2][256];
const char modem_no_carrier_response[] = "NO CARRIER";
const char modem_no_dialtone_response[] = "NO DIALTONE";
const char modem_initialization_script[] = "send \"AT&FE0\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATS0=1\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATW2\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATX3&C1&D2\\r\"\nwait \"OK\\r\\n\",3\n";
const char modem_dial_script[] = "dial \"%t\"\n";
#define lbl_805A9008 (*(RecoveredGlobal_803F76F4_lbl_805A9008 *)lbl_805A9008)

void TLobby__sub_803F7678(void) {

}

s32 TLobby__sub_803F767C(void) {
    return 0;
}

s32 TLobby__sub_803F7684(void *lobby) {
    E_803F7684 *p;
    for (p = lbl_804FD350; p->key != 0; p++) {
        if (NetCompareStrings((const char*)lobby, (const char*)p->key) == 0) {
            return p->val;
        }
    }
    return 0;
}

void TLobby__sub_803F76F0(void) {

}

typedef char RecoveredGlobal_803F76F4_lbl_805A9008_size[sizeof(RecoveredGlobal_803F76F4_lbl_805A9008) == 0x1090 ? 1 : -1];
void TLobby::init_net_buffer_table() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { u8 * field_0; u8 * field_4; u8 * field_8; u8 * field_C; u8 * field_10; u8 * field_14; u8 * field_18; u8 * field_1C; s32 * field_20; s16 field_24; s16 field_26; s16 field_28; s16 field_2A; s16 field_2C; s16 field_2E; s16 field_30; s16 field_32; s16 field_34; s8 field_36; s8 field_37; s16 field_38; };
    ((Fields_arg0*)arg0)->field_0 = (u8 *)&lbl_805A9008.value + 0x808;
    ((Fields_arg0*)arg0)->field_4 = (u8 *)&lbl_805A9008.value + 0x788;
    ((Fields_arg0*)arg0)->field_8 = (u8 *)&lbl_805A9008.value + 0x708;
    ((Fields_arg0*)arg0)->field_C = (u8 *)&lbl_805A9008.value + 0x608;
    ((Fields_arg0*)arg0)->field_10 = (u8 *)&lbl_805A9008.value + 0x508;
    ((Fields_arg0*)arg0)->field_14 = (u8 *)&lbl_805A9008.value + 0x384;
    ((Fields_arg0*)arg0)->field_18 = (u8 *)&lbl_805A9008.value + 0x200;
    ((Fields_arg0*)arg0)->field_1C = (u8 *)&lbl_805A9008.value + 0x100;
    ((Fields_arg0*)arg0)->field_20 = &lbl_805A9008.value;
    ((Fields_arg0*)arg0)->field_24 = 0x80;
    ((Fields_arg0*)arg0)->field_26 = 0x80;
    ((Fields_arg0*)arg0)->field_28 = 0x80;
    ((Fields_arg0*)arg0)->field_2A = 0x100;
    ((Fields_arg0*)arg0)->field_2C = 0x100;
    ((Fields_arg0*)arg0)->field_2E = 0x181;
    ((Fields_arg0*)arg0)->field_30 = 0x181;
    ((Fields_arg0*)arg0)->field_32 = 0x100;
    ((Fields_arg0*)arg0)->field_34 = 0x100;
    ((Fields_arg0*)arg0)->field_36 = 0xA;
    ((Fields_arg0*)arg0)->field_37 = 5;
    ((Fields_arg0*)arg0)->field_38 = 3;
}

void TLobby__sub_803F778C(void) {

}

typedef char RecoveredGlobal_803F7790_lbl_805A9008_size[sizeof(RecoveredGlobal_803F7790_lbl_805A9008) == 0x1090 ? 1 : -1];
void TLobby::init_net_block_620_params() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { u8 * field_0; u8 * field_4; u8 * field_8; s16 field_C; s16 field_E; s16 field_10; s8 field_12; s8 field_13; s16 field_14; };
    ((Fields_arg0*)arg0)->field_0 = (unsigned char *) ((void *) ((u8 *)&(*(RecoveredGlobal_803F7790_lbl_805A9008 *)&lbl_805A9008).value + 0xA08));
    ((Fields_arg0*)arg0)->field_4 = (unsigned char *) ((void *) ((u8 *)&(*(RecoveredGlobal_803F7790_lbl_805A9008 *)&lbl_805A9008).value + 0x988));
    ((Fields_arg0*)arg0)->field_8 = (unsigned char *) ((void *) ((u8 *)&(*(RecoveredGlobal_803F7790_lbl_805A9008 *)&lbl_805A9008).value + 0x888));
    ((Fields_arg0*)arg0)->field_C = 0x80;
    ((Fields_arg0*)arg0)->field_E = 0x80;
    ((Fields_arg0*)arg0)->field_10 = 0x100;
    ((Fields_arg0*)arg0)->field_12 = 0xA;
    ((Fields_arg0*)arg0)->field_13 = 5;
    ((Fields_arg0*)arg0)->field_14 = 3;
}

void TLobby__sub_803F77E0(void) {

}

void init_modem_buffer_config(void *arg0) {
    Obj_803F77E4 *o = (Obj_803F77E4 *)arg0;

    o->f0 = lbl_805AA080;
    o->f4 = 6;
    o->f8 = lbl_805A9E80;
    o->fC = 4;
    o->fE = 0x80;
    o->f10 = lbl_805A9E70;
    o->f14 = 4;
    o->f18 = &lbl_805D79F8;
    o->f1C = 4;
    o->f20 = lbl_805A9DF0;
    o->f24 = lbl_805A9D70;
    o->f28 = lbl_805A9CF0;
    o->f2C = lbl_805A9C70;
    o->f30 = lbl_805A9BF0;
    o->f34 = lbl_805A9B70;
    o->f38 = lbl_805A9AF0;
    o->f3C = 0x80;
    o->f3E = 0x80;
    o->f40 = 0x80;
    o->f42 = 0x80;
    o->f44 = 0x80;
    o->f46 = 0x80;
    o->f48 = 0x80;
    o->f4C = (Sub_803F77E4 *)(lbl_805A9A90);
    o->f4C->f0 = 1;
    o->f4C->f2 = 1;
    o->f4C->f4 = 1;
    o->f4C->f6 = 0;
    o->f4C->f8 = 1;
    o->f4C->fC = (void *)modem_tone_dial_command;
    o->f4C->f10 = (void *)modem_pulse_dial_command;
    o->f4C->f14 = (void *)modem_answer_command;
    o->f4C->f18 = (void *)modem_ok_response;
    o->f4C->f1C = (void *)modem_connect_response;
    o->f4C->f20 = (void *)modem_busy_response;
    o->f4C->f24 = (void *)modem_error_response;
    o->f4C->f28 = (void *)modem_delayed_response;
    o->f4C->f2C = (void *)modem_no_carrier_response;
    o->f4C->f30 = (void *)modem_no_dialtone_response;
    o->f4C->f34 = (void *)modem_ring_response;
    o->f4C->f38 = 0xD;
    o->f4C->f3C = (void *)modem_initialization_script;
    o->f4C->f40 = (void *)modem_dial_script;
    o->f4C->f44 = 0;
}

void TLobby__sub_803F7980(void) {

}

void TLobby::init_buffer_desc_b() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { u8 pad_0[12]; s32 * field_C; s32 * field_10; s16 field_14; s16 field_16; };
    ((Fields_arg0*)arg0)->field_C = &lbl_805D7A00;
    ((Fields_arg0*)arg0)->field_10 = (s32 *)network_packet_buffer_storage.packet_slots;
    ((Fields_arg0*)arg0)->field_16 = 4;
    ((Fields_arg0*)arg0)->field_14 = 0x5DC;
}

void TLobby__sub_803F79AC(void) {

}

void TLobby__sub_803F79B0(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 8) = 0x28;
}

void TLobby__sub_803F79BC(void) {

}

typedef char RecoveredGlobal_803F79C0_lbl_805A9008_size[sizeof(RecoveredGlobal_803F79C0_lbl_805A9008) == 0x1090 ? 1 : -1];
void TLobby::init_net_buffer_desc() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s32 field_0; u8 * field_4; s16 field_8; s16 field_A; u8 * field_C; u8 * field_10; u8 * field_14; u8 * field_18; u8 * field_1C; s16 field_20; s16 field_22; s16 field_24; s16 field_26; s16 field_28; };
    ((Fields_arg0*)arg0)->field_4 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x4B78;
    ((Fields_arg0*)arg0)->field_8 = 2;
    ((Fields_arg0*)arg0)->field_A = 0x226;
    ((Fields_arg0*)arg0)->field_C = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x4A60;
    ((Fields_arg0*)arg0)->field_10 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x3A48;
    ((Fields_arg0*)arg0)->field_14 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x31B0;
    ((Fields_arg0*)arg0)->field_18 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x2918;
    ((Fields_arg0*)arg0)->field_1C = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x2800;
    ((Fields_arg0*)arg0)->field_0 = 0x18;
    ((Fields_arg0*)arg0)->field_20 = 0x46;
    ((Fields_arg0*)arg0)->field_22 = 0x406;
    ((Fields_arg0*)arg0)->field_24 = 0x226;
    ((Fields_arg0*)arg0)->field_26 = 0x226;
    ((Fields_arg0*)arg0)->field_28 = 0x46;
}

typedef char RecoveredGlobal_803F7A30_lbl_805C18A0_size[sizeof(RecoveredGlobal_803F7A30_lbl_805C18A0) == 0x10 ? 1 : -1];
void TLobby::stop_network_thread() {
    TLobby::lock_mutex((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 0)));
    ((TLobby *)(*(s32 *)((s8 *)&lbl_805C18A0.value + 4)))->cancel_thread_if_running();
    TLobby::deactivate_entry_by_key((u32)((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 4))));
    TUdpSocket::unlock_mutex((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 0)));
    NetReleaseMutex((u32)((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 0))));
}

void TLobby__sub_803F7A90(void) {
    if (TLobby__sub_803F96AC(((P_803F7A90 *)&lbl_805C18A0)) < 0 || TLobby__sub_803F9B94(run_net_thread_loop__6TLobbyFv, &((P_803F7A90 *)&lbl_805C18A0)[0].b) < 0) {
        return;
    }
    NetResumeThread(((P_803F7A90 *)&lbl_805C18A0)[0].b);
}

void TLobby::queue_thread_main() {
    Q_803F7AF4 *p;
    for (;;) {
        p = get_next_send_chunk__6TLobbyFv();
        if (p == NULL) {
            NetSuspendCurrentThread();
            continue;
        }
        TLobby__queue_timeout_remaining = p->b;
        for (;;) {
            if (TAdSinglePlyChrSelectGC__sub_8042E184() == 0) {
                if (TAdSinglePlyChrSelectGC__sub_8042DD70((s32)p->a, (s32)p->b, (s32)subtract_network_queue_timeout) == 1) {
                    break;
                }
            }
            NetYieldThread();
        }
        for (;;) {
            if (TLobby__queue_timeout_remaining <= 0) {
                break;
            }
            NetYieldThread();
        }
        NetYieldThread();
    }
}

Q_803F7AF4 *get_next_send_chunk__6TLobbyFv(void) {
    s32 pos;
    TLobby::lock_mutex(TLobby__send_ring_mutex);
    lobby_send_ring_pending_bytes -= lobby_send_chunk_size;
    if (lobby_send_ring_pending_bytes <= 0) {
        lobby_send_ring_pending_bytes = 0;
        lobby_send_chunk_size = 0;
        TUdpSocket::unlock_mutex(TLobby__send_ring_mutex);
        return NULL;
    }
    pos = lobby_send_ring_read_pos;
    if (pos + lobby_send_ring_pending_bytes >= lobby_ring_buffer_size) {
        lobby_send_chunk_size = lobby_ring_buffer_size - pos;
    } else {
        lobby_send_chunk_size = lobby_send_ring_pending_bytes;
    }
    if (lobby_send_chunk_size > 0x200) {
        lobby_send_chunk_size = 0x200;
    }
    lobby_send_ring_read_pos += lobby_send_chunk_size;
    if (lobby_send_ring_read_pos >= lobby_ring_buffer_size) {
        lobby_send_ring_read_pos = 0;
    }
    TLobby__next_send_chunk.a = send_ring_buffer_base + pos;
    TLobby__next_send_chunk.b = lobby_send_chunk_size;
    TUdpSocket::unlock_mutex(TLobby__send_ring_mutex);
    return &TLobby__next_send_chunk;
}

s32 TLobby::write_ring_buffer(u8 *src, s32 len) {
    s32 first;
    s32 over;
    s32 end;
    s32 thread;
    u8 pad[8];
    thread = queue_thread_handle;
    TLobby::lock_mutex(TLobby__send_ring_mutex);
    if (lobby_ring_buffer_size - lobby_send_ring_pending_bytes < len) {
        TUdpSocket::unlock_mutex(TLobby__send_ring_mutex);
        if (OSIsThreadSuspended(thread) == 1) {
            TLobby::resume_thread(queue_thread_handle);
        }
        return 0;
    }
    end = lobby_ring_buffer_write_pos + len;
    if (end >= lobby_ring_buffer_size) {
        over = end - lobby_ring_buffer_size;
        first = len - over;
        NetMemcpy((void *)(send_ring_buffer_base + lobby_ring_buffer_write_pos), src, first);
        NetMemcpy((void *)send_ring_buffer_base, src + first, over);
        lobby_ring_buffer_write_pos = over;
    } else {
        NetMemcpy((void *)(send_ring_buffer_base + lobby_ring_buffer_write_pos), src, len);
        lobby_ring_buffer_write_pos += len;
    }
    lobby_send_ring_pending_bytes += len;
    TUdpSocket::unlock_mutex(TLobby__send_ring_mutex);
    if (OSIsThreadSuspended(thread) == 1) {
        TLobby::resume_thread(queue_thread_handle);
    }
    return 1;
}
}

void set_lobby_map_state_code(s32 arg0) {
    lobby_map_state_code = arg0;
}

void subtract_network_queue_timeout(s32 arg0) {
    TLobby__queue_timeout_remaining -= arg0;
}

s16 TLobby::map_state_to_mode_id() {
    switch ((*(u32 *)&lobby_map_state_code)) {
    case 3:
        return 0;
    case 2:
        return 2;
    case 0:
        return 3;
    case 4:
        return -1;
    case 1:
        return 8;
    case 5:
        return 9;
    case 6:
        return 0xA;
    case 7:
        return 0xB;
    default:
        return 1;
    }
}

s32 TLobby::map_state_to_code(s32 arg0, s16 arg1) {
    s32 v;
    switch (arg1) {
    case 0:
        v = 1;
        break;
    case 1:
        v = 2;
        break;
    default:
        return -1;
    }
    lobby_map_state_code = 4;
    if (TAdSinglePlyChrSelectGC__sub_8042E320(arg0, v, (void *)set_lobby_map_state_code) != 1) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_803F7E50(s32 arg0, s32 arg1, s32 arg2, s32 n, s32 p) {
    s32 v;
    s32 ok;
    u32 len;
    s32 r;
    ok = 1;
    switch (arg0) {
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    case 4: v = 4; break;
    case 5: v = 5; break;
    case 0: v = 2; break;
    default: ok = 0; break;
    }
    if (ok != 0 && TAdSinglePlyChrSelectGC::send_at_ms_command(v) != 1) {
        return -1;
    }
    ok = 1;
    switch (arg1) {
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    case 0:
    default: ok = 0; break;
    }
    if (ok != 0 && TAdSinglePlyChrSelectGC::send_at_error_correction_cmd(v) != 1) {
        return -1;
    }
    ok = 1;
    switch (arg2) {
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    case 4: v = 4; break;
    case 0:
    default: ok = 0; break;
    }
    if (ok != 0 && TAdSinglePlyChrSelectGC::send_at_compression_cmd(v) != 1) {
        return -1;
    }
    while (n != 0) {
        len = NetStringLength((const char*)p);
        if (len > 0x3FU) {
            return -1;
        }
        r = TAdSinglePlyChrSelectGC__sub_8042D49C(p);
        if (r != 1 && r != -8) {
            return -1;
        }
        p = len + p;
        p++;
        n--;
    }
    return 0;
}

s32 TLobby::send_atx_command_mode(s32 arg0) {
    s32 var_r3;
    if (arg0 == 0) {
        var_r3 = 1;
    } else {
        var_r3 = 2;
    }
    if (TAdSinglePlyChrSelectGC::send_atx_command(var_r3) == 1) {
        return 0;
    }
    return -1;
}

void TLobby__sub_803F808C(void) {

}

s32 TLobby__sub_803F8090(void) {
    u8 buf[0x20];
    if (network_pppoe_transport_enabled != 0) {
        if (net_slot_id < 0) {
            return 0;
        }
        ((TLobby *)NULL)->pppoe_recv_packet(0, NULL);
        if (TLobby::get_slot_id(net_slot_id) == 4) {
            return 1;
        }
        return 0;
    }
    if (((TAdSinglePlyChrSelectGC *)buf)->copy_default_and_get_state() == 3) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_803F811C(s16 *arg0) {
    *arg0 = 0;
    return 0;
}

s32 TLobby__sub_803F812C(u16 arg0, void *lobby, u16 *arg2) {
    if (network_pppoe_transport_enabled != 0) {
        if (net_slot_id < 0) {
            return 6;
        }
        {
            s16 v = ((TLobby *)lobby)->pppoe_recv_packet(arg0, arg2);
            if (v != net_slot_id) {
                return 6;
            }
        }
    } else {
        s32 r = TAdSinglePlyChrSelectGC__sub_8042D7E0(lobby);
        if (r < 0) {
            *arg2 = 0;
        } else {
            *arg2 = r;
        }
    }
    return 0;
}

s32 send_network_frame(u16 len, u8 *src) {
    if ((s16) network_pppoe_transport_enabled != 0) {
        if ((s16) net_slot_id < 0) {
            return 5;
        }
        if (TLobby__sub_80427F48(net_slot_id, src, len) < 0) {
            return 5;
        }
        goto block_7;
    }
    if (((u16)TLobby::write_ring_buffer(src, (s32) len)) == 0) {
        return 5;
    }
block_7:
    return 0;
}

void TLobby__sub_803F8238(void) {
    s32 var_r31;
    if ((s16) network_pppoe_transport_enabled != 0) {
        if ((s16) net_slot_id >= 0) {
            TLobby__sub_80428094(net_slot_id);
            var_r31 = 0;
loop_3:
            TLobby__sub_803F97E8(0xA);
            if ((((TLobby *)NULL)->pppoe_recv_packet(0U, NULL) >= 0) && (TLobby::get_slot_id(net_slot_id) != -1)) {
                var_r31 += 1;
                if (var_r31 < 0x12C) {
                    goto loop_3;
                }
            }
            if (TLobby::get_slot_id(net_slot_id) != -1) {
                TLobby__sub_80428094(net_slot_id);
            }
            net_slot_id = -1;
            goto block_10;
        }
    } else {
        ((TLobby *)queue_thread_handle)->cancel_thread_if_running();
        TLobby::deactivate_entry_by_key((u32) queue_thread_handle);
        NetReleaseMutex(TLobby__send_ring_mutex);
block_10:
        if ((u32) (((TAdSinglePlyChrSelectGC *)0U)->copy_default_and_get_state() - 2) <= 1U) {
            TAdSinglePlyChrSelectGC__sub_8042D604();
        }
    }
}

s32 TLobby__sub_803F8314(A_803F8314 *arg0) {
    u8 *buf = pppoe_discovery_name_storage[0];
    char *name;
    s32 ret;
    if ((u32)send_ring_buffer_base == 0) {
        return 2;
    }
    if (arg0->flag != 0) {
        network_pppoe_transport_enabled = 1;
        buf[0] = 0;
        buf[0x100] = 0;
        net_slot_id = TLobby__sub_804281DC(buf);
        if (net_slot_id < 0) {
            return 2;
        }
    } else {
        network_pppoe_transport_enabled = 0;
        if (arg0->name != NULL) {
            name = arg0->name;
        } else {
            name = (char *)modem_default_connect_argument;
        }
        TUdpSocket::unlock_mutex(lbl_805C18A0.value);
        ret = TAdSinglePlyChrSelectGC__sub_8042CEF8(name);
        TLobby::lock_mutex(lbl_805C18A0.value);
        if (ret == 1) {
            TAdSinglePlyChrSelectGC__sub_8042E488(5);
            if (TLobby__sub_803F96AC(&TLobby__send_ring_mutex) < 0) {
                return 2;
            }
            if (TLobby__sub_803F9B94((void *)TLobby::queue_thread_main, &queue_thread_handle) < 0) {
                return 2;
            }
            NetResumeThread(queue_thread_handle);
        } else {
            return 2;
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
u32 TLobby::compute_range_end(s32 arg1, u32 arg2) {
    u32 temp_r3;
    send_ring_buffer_base = arg1;
    lobby_ring_buffer_size = *(s32 *)&this->m_up;
    temp_r3 = arg1 + lobby_ring_buffer_size;
    if (temp_r3 > arg2) {
        send_ring_buffer_base = 0;
        lobby_ring_buffer_size = 0;
        return 0U;
    }
    return temp_r3;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
s32 TLobby__sub_803F8470(u8 *data, s32 size) {
    H_803F8470 hdr;
    u32 end;
    u8 *p;
    s32 r;
    u32 q;
    end = (u32)(data + size);
    r = TLobby__sub_803F861C((Info_803F861C *)((int)&hdr));
    if (size < 0) {
        return -1;
    }
    if (size < r) {
        return -1;
    }
    net_transport_buffer_ptr_a = (u32)data;
    p = data + hdr.n1 * 0x44;
    if ((u32)p > end) {
        return -1;
    }
    net_transport_buffer_ptr_b = (u32)p;
    p += hdr.n2 * 0x544;
    if ((u32)p > end) {
        return -1;
    }
    q = layout_buffers__6TLobbyFPUcPUc((u8 *)&hdr, (u32)p, end);
    if (q == 0) {
        return -1;
    }
    if (hdr.b != 0 && ((TLobby *)((u8 *)&hdr))->compute_range_end(q, end) == 0) {
        return -1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
s32 TLobby::validate_and_store_net_params() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r5;
    if ((u16) this->m_flags > 0x200U) {
        return -1;
    }
    if ((u16) this->m_id > 0x400U) {
        return -1;
    }
    temp_r5 = *(s32 *)&this->m_prev;
    if ((temp_r5 < 0x400) || (temp_r5 > 0xFFFF)) {
        return -1;
    }
    lbl_805D47F8 = *(s16 *)&this->m_name;
    lbl_805D4804 = *(s16 *)((s8 *)arg0 + 2);
    net_param_player_count = this->m_flags;
    net_param_room_count = this->m_id;
    lbl_805D4800 = *(s32 *)&this->m_prev;
    lbl_805D4808 = *(s32 *)&this->m_next;
    lbl_805D480C = *(s32 *)&this->m_up;
    net_param_word_h = *(s32 *)&this->m_down;
    net_param_word_i = *(s32 *)((s8 *)arg0 + 0x18);
    return TLobby__sub_803F861C((Info_803F861C *)(0));
}
#pragma pop

s32 TLobby__sub_803F861C(Info_803F861C *arg0) {
    Info_803F861C local;
    s32 y;
    s32 x;
    s32 n;
    if (arg0 == NULL) {
        arg0 = &local;
    }
    arg0->a = lbl_805D47F8;
    arg0->b = lbl_805D4804;
    arg0->c = net_param_player_count;
    x = net_param_player_count * 0x44;
    arg0->d = net_param_room_count;
    y = net_param_room_count * 0x544;
    arg0->g = lbl_805D480C;
    n = x + y;
    n += lbl_805D480C;
    arg0->e = lbl_805D4800;
    arg0->f = lbl_805D4808;
    arg0->h = net_param_word_h;
    arg0->i = net_param_word_i;
    n += TLobby__sub_803F8D24(arg0);
    return n;
}

void TLobby__sub_803F86BC(void) {

}
#pragma push
#pragma optimization_level 2
void TLobby::init_net_config() {
    Cfg_803F86C0 *c = (Cfg_803F86C0 *)this;
    u8 *buf = lobby_net_config_block;
    c->f0 = 0;
    c->f2 = 0x3F;
    c->f4 = 0xFF;
    c->f6 = 0x200;
    c->fA = 3;
    c->fC = &lbl_805D7A50;
    lbl_805D7A50.a = 2;
    lbl_805D7A50.b = 4;
    lbl_805D7A50.c = 8;
    c->f10 = 2;
    c->f14 = buf + 0x49A0;
    c->f1A = 6;
    c->f1C = 0x200;
    c->f20 = buf + 0x39A0;
    c->f24 = 8;
    c->f28 = buf + 0x3960;
    c->f2C = 0x20;
    c->f34 = buf + 0x3460;
    c->f2E = 0x10;
    c->f38 = buf + 0x13A0;
    c->f30 = 0x10;
    c->f3C = buf + 0x1E0;
    c->f40 = 8;
    c->f44 = buf;
}
#pragma pop
