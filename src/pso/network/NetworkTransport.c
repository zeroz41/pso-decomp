/* The network stack's transport (a C library, built with GC/1.2.5n): the modem/PPPoE send path with its ring buffer
 * and queue thread, the start-up parameters, and the functions that fill the stack's configuration records with
 * this file's static buffers. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80426CAC.h"

#include "types.h"

typedef struct RecoveredGlobal_803F76F4_lbl_805A9008 {
    s32 value;
    u8 remaining[0x108C];
} RecoveredGlobal_803F76F4_lbl_805A9008;

typedef struct RecoveredGlobal_803F7790_lbl_805A9008 {
    s32 value;
    u8 remaining[0x108C];
} RecoveredGlobal_803F7790_lbl_805A9008;

typedef struct NetworkPacketBufferStorage {
    u8 packet_slots[4][1500];
    u32 workspace_70_a[70];
    u32 workspace_550_a[550];
    u32 workspace_550_b[550];
    u32 workspace_1030[1030];
    u32 workspace_70_b[70];
    u32 workspace_550_pair[2][550];
} NetworkPacketBufferStorage;
typedef char NetworkPacketBufferStorage_size[sizeof(NetworkPacketBufferStorage) == 0x4C18 ? 1 : -1];

typedef struct RecoveredGlobal_803F79C0_lbl_805A9008 {
    s32 value;
    u8 remaining[0x108C];
} RecoveredGlobal_803F79C0_lbl_805A9008;

typedef struct RecoveredGlobal_803F7A30_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
} RecoveredGlobal_803F7A30_lbl_805C18A0;

typedef struct E_803F7684 { u32 key; s32 val; } E_803F7684;

typedef struct P_803F7A90 { s32 a; s32 b; } P_803F7A90;

typedef struct Q_803F7AF4 { s32 a; s32 b; } Q_803F7AF4;

typedef struct A_803F8314 {
    u8 pad[0x1A];
    s16 flag;
    char *name;
} A_803F8314;

typedef struct Sub_803F77E4 {
    s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; u8 padA[2];
    void *fC; void *f10; void *f14; void *f18; void *f1C; void *f20; void *f24; void *f28;
    void *f2C; void *f30; void *f34; s8 f38; u8 pad39[3]; void *f3C; void *f40; s32 f44;
} Sub_803F77E4;

typedef struct Obj_803F77E4 {
    u8 *f0; s16 f4; u8 *f8; s16 fC; s16 fE; u8 *f10; s16 f14; void *f18; s16 f1C;
    u8 *f20; u8 *f24; u8 *f28; u8 *f2C; u8 *f30; u8 *f34; u8 *f38;
    s16 f3C; s16 f3E; s16 f40; s16 f42; s16 f44; s16 f46; s16 f48;
    Sub_803F77E4 *f4C;
} Obj_803F77E4;

s32 send_at_ms_command__23TAdSinglePlyChrSelectGCFl(s32 mode);
s32 send_at_error_correction_cmd__23TAdSinglePlyChrSelectGCFl(s32 mode);
s32 send_at_compression_cmd__23TAdSinglePlyChrSelectGCFl(s32 mode);
s32 send_atx_command__23TAdSinglePlyChrSelectGCFl(s32 mode);
s32 copy_default_and_get_state__23TAdSinglePlyChrSelectGCFv(void *self);

extern s32 lbl_805D7A00;
void TLobby__sub_803F97E8(s32);
s32 TLobby__sub_80428094(s16);
void TAdSinglePlyChrSelectGC__sub_8042D604(void);
extern s16 net_slot_id;
extern s32 queue_thread_handle;
extern u32 TLobby__send_ring_mutex;
extern s16 network_pppoe_transport_enabled;
extern RecoveredGlobal_803F7A30_lbl_805C18A0 lbl_805C18A0;
extern s32 send_ring_buffer_base;
extern s32 lobby_ring_buffer_size;
extern s16 lbl_805D47F8;
extern s16 lbl_805D4804;
extern s32 lbl_805D4808;
extern s32 lbl_805D480C;
extern s32 net_param_word_h;
extern s32 net_param_word_i;
extern s32 lobby_map_state_code;
extern E_803F7684 lbl_804FD350[];
extern u8 run_net_thread_loop[];
s16 TLobby__sub_803F96AC(void *);
s16 TLobby__sub_803F9B94(void *, void *);
s32 TAdSinglePlyChrSelectGC__sub_8042DD70(s32 arg0, s32 arg1, s32 arg2);
s32 TAdSinglePlyChrSelectGC__sub_8042E184(void);
s32 TAdSinglePlyChrSelectGC__sub_8042E320(s32, s32, void *);
extern s32 TLobby__queue_timeout_remaining;
void subtract_network_queue_timeout(s32 arg0);
void set_lobby_map_state_code(s32 arg0);
extern s32 lobby_send_ring_read_pos;
extern s32 lobby_send_ring_pending_bytes;
extern Q_803F7AF4 TLobby__next_send_chunk;
extern s32 lobby_send_chunk_size;
Q_803F7AF4 *get_next_send_chunk(void);
s32 OSIsThreadSuspended(s32);
extern s32 lobby_ring_buffer_write_pos;
s16 TLobby__sub_804281DC(void *);
s32 TAdSinglePlyChrSelectGC__sub_8042CEF8(char *);
void TAdSinglePlyChrSelectGC__sub_8042E488(s32);
s32 open_network_transport(A_803F8314 *arg0);
u32 layout_buffers(u8 *, u32, u32);
s32 layout_net_params_buffer(u8 *data, s32 size);
s32 TAdSinglePlyChrSelectGC__sub_8042D49C(int);
s32 configure_modem_options(s32 arg0, s32 arg1, s32 arg2, s32 n, s32 p);
s32 TAdSinglePlyChrSelectGC__sub_8042D7E0(void *);
s32 TLobby__sub_803F8D24(NetTransportParams *);
s32 get_net_params_and_size(NetTransportParams *arg0);
s32 send_network_frame(u16 arg0, u8 *arg1);
void TLobby__sub_803F76F0(void);
void TLobby__sub_803F778C(void);
void TLobby__sub_803F77E0(void);
void TLobby__sub_803F7980(void);
void TLobby__sub_803F79AC(void);
void TLobby__sub_803F79BC(void);
u32 compute_range_end(NetTransportParams *params, s32 base, u32 limit);

extern s32 lbl_805D79F8;

__declspec(section ".sdata2") const char modem_tone_dial_command[] = "ATDT";
__declspec(section ".sdata2") const char modem_pulse_dial_command[] = "ATDP";
__declspec(section ".sdata2") const char modem_answer_command[] = "ATA";
__declspec(section ".sdata2") const char modem_ok_response[] = "OK";
__declspec(section ".sdata2") const char modem_connect_response[] = "CONNECT";
__declspec(section ".sdata2") const char modem_busy_response[] = "BUSY";
__declspec(section ".sdata2") const char modem_error_response[] = "ERROR";
__declspec(section ".sdata2") const char modem_delayed_response[] = "DELAYED";
__declspec(section ".sdata2") const char modem_ring_response[] = "RING";
__declspec(section ".sdata2") const char modem_default_connect_argument[] = "00";

static u8 lbl_805A9008[0xA88];
static u8 lbl_805A9A90[0x60];
static u8 lbl_805A9AF0[0x80];
static u8 lbl_805A9B70[0x80];
static u8 lbl_805A9BF0[0x80];
static u8 lbl_805A9C70[0x80];
static u8 lbl_805A9CF0[0x80];
static u8 lbl_805A9D70[0x80];
static u8 lbl_805A9DF0[0x80];
static u8 lbl_805A9E70[0x10];
static u8 lbl_805A9E80[0x200];
static u8 lbl_805AA080[0x18];
static NetworkPacketBufferStorage network_packet_buffer_storage;
static u8 pppoe_discovery_name_storage[2][256];
static const char modem_no_carrier_response[] = "NO CARRIER";
static const char modem_no_dialtone_response[] = "NO DIALTONE";
static const char modem_initialization_script[] = "send \"AT&FE0\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATS0=1\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATW2\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATX3&C1&D2\\r\"\nwait \"OK\\r\\n\",3\n";
static const char modem_dial_script[] = "dial \"%t\"\n";
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
void init_net_buffer_table(void *table) {
    u8 *cfg = (u8 *)table;
    typedef struct NetBufferTableFields { u8 * field_0; u8 * field_4; u8 * field_8; u8 * field_C; u8 * field_10; u8 * field_14; u8 * field_18; u8 * field_1C; s32 * field_20; s16 field_24; s16 field_26; s16 field_28; s16 field_2A; s16 field_2C; s16 field_2E; s16 field_30; s16 field_32; s16 field_34; s8 field_36; s8 field_37; s16 field_38; } NetBufferTableFields;
    ((NetBufferTableFields*)cfg)->field_0 = (u8 *)&lbl_805A9008.value + 0x808;
    ((NetBufferTableFields*)cfg)->field_4 = (u8 *)&lbl_805A9008.value + 0x788;
    ((NetBufferTableFields*)cfg)->field_8 = (u8 *)&lbl_805A9008.value + 0x708;
    ((NetBufferTableFields*)cfg)->field_C = (u8 *)&lbl_805A9008.value + 0x608;
    ((NetBufferTableFields*)cfg)->field_10 = (u8 *)&lbl_805A9008.value + 0x508;
    ((NetBufferTableFields*)cfg)->field_14 = (u8 *)&lbl_805A9008.value + 0x384;
    ((NetBufferTableFields*)cfg)->field_18 = (u8 *)&lbl_805A9008.value + 0x200;
    ((NetBufferTableFields*)cfg)->field_1C = (u8 *)&lbl_805A9008.value + 0x100;
    ((NetBufferTableFields*)cfg)->field_20 = &lbl_805A9008.value;
    ((NetBufferTableFields*)cfg)->field_24 = 0x80;
    ((NetBufferTableFields*)cfg)->field_26 = 0x80;
    ((NetBufferTableFields*)cfg)->field_28 = 0x80;
    ((NetBufferTableFields*)cfg)->field_2A = 0x100;
    ((NetBufferTableFields*)cfg)->field_2C = 0x100;
    ((NetBufferTableFields*)cfg)->field_2E = 0x181;
    ((NetBufferTableFields*)cfg)->field_30 = 0x181;
    ((NetBufferTableFields*)cfg)->field_32 = 0x100;
    ((NetBufferTableFields*)cfg)->field_34 = 0x100;
    ((NetBufferTableFields*)cfg)->field_36 = 0xA;
    ((NetBufferTableFields*)cfg)->field_37 = 5;
    ((NetBufferTableFields*)cfg)->field_38 = 3;
}

void TLobby__sub_803F778C(void) {

}

typedef char RecoveredGlobal_803F7790_lbl_805A9008_size[sizeof(RecoveredGlobal_803F7790_lbl_805A9008) == 0x1090 ? 1 : -1];
void init_net_block_620_params(void *params) {
    u8 *cfg = (u8 *)params;
    typedef struct NetBlock620Fields { u8 * field_0; u8 * field_4; u8 * field_8; s16 field_C; s16 field_E; s16 field_10; s8 field_12; s8 field_13; s16 field_14; } NetBlock620Fields;
    ((NetBlock620Fields*)cfg)->field_0 = (unsigned char *) ((void *) ((u8 *)&(*(RecoveredGlobal_803F7790_lbl_805A9008 *)&lbl_805A9008).value + 0xA08));
    ((NetBlock620Fields*)cfg)->field_4 = (unsigned char *) ((void *) ((u8 *)&(*(RecoveredGlobal_803F7790_lbl_805A9008 *)&lbl_805A9008).value + 0x988));
    ((NetBlock620Fields*)cfg)->field_8 = (unsigned char *) ((void *) ((u8 *)&(*(RecoveredGlobal_803F7790_lbl_805A9008 *)&lbl_805A9008).value + 0x888));
    ((NetBlock620Fields*)cfg)->field_C = 0x80;
    ((NetBlock620Fields*)cfg)->field_E = 0x80;
    ((NetBlock620Fields*)cfg)->field_10 = 0x100;
    ((NetBlock620Fields*)cfg)->field_12 = 0xA;
    ((NetBlock620Fields*)cfg)->field_13 = 5;
    ((NetBlock620Fields*)cfg)->field_14 = 3;
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

void init_buffer_desc_b(void *desc) {
    u8 *cfg = (u8 *)desc;
    typedef struct BufferDescBFields { u8 pad_0[12]; s32 * field_C; s32 * field_10; s16 field_14; s16 field_16; } BufferDescBFields;
    ((BufferDescBFields*)cfg)->field_C = &lbl_805D7A00;
    ((BufferDescBFields*)cfg)->field_10 = (s32 *)network_packet_buffer_storage.packet_slots;
    ((BufferDescBFields*)cfg)->field_16 = 4;
    ((BufferDescBFields*)cfg)->field_14 = 0x5DC;
}

void TLobby__sub_803F79AC(void) {

}

void TLobby__sub_803F79B0(u8 *cfg) {
    *(s16 *)((s8 *)cfg + 8) = 0x28;
}

void TLobby__sub_803F79BC(void) {

}

typedef char RecoveredGlobal_803F79C0_lbl_805A9008_size[sizeof(RecoveredGlobal_803F79C0_lbl_805A9008) == 0x1090 ? 1 : -1];
void init_net_buffer_desc(void *desc) {
    u8 *cfg = (u8 *)desc;
    typedef struct BufferDescFields { s32 field_0; u8 * field_4; s16 field_8; s16 field_A; u8 * field_C; u8 * field_10; u8 * field_14; u8 * field_18; u8 * field_1C; s16 field_20; s16 field_22; s16 field_24; s16 field_26; s16 field_28; } BufferDescFields;
    ((BufferDescFields*)cfg)->field_4 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x4B78;
    ((BufferDescFields*)cfg)->field_8 = 2;
    ((BufferDescFields*)cfg)->field_A = 0x226;
    ((BufferDescFields*)cfg)->field_C = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x4A60;
    ((BufferDescFields*)cfg)->field_10 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x3A48;
    ((BufferDescFields*)cfg)->field_14 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x31B0;
    ((BufferDescFields*)cfg)->field_18 = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x2918;
    ((BufferDescFields*)cfg)->field_1C = (u8 *)(&(*(RecoveredGlobal_803F79C0_lbl_805A9008 *)&lbl_805A9008).value) + 0x2800;
    ((BufferDescFields*)cfg)->field_0 = 0x18;
    ((BufferDescFields*)cfg)->field_20 = 0x46;
    ((BufferDescFields*)cfg)->field_22 = 0x406;
    ((BufferDescFields*)cfg)->field_24 = 0x226;
    ((BufferDescFields*)cfg)->field_26 = 0x226;
    ((BufferDescFields*)cfg)->field_28 = 0x46;
}

typedef char RecoveredGlobal_803F7A30_lbl_805C18A0_size[sizeof(RecoveredGlobal_803F7A30_lbl_805C18A0) == 0x10 ? 1 : -1];
void stop_network_thread(void) {
    lock_mutex((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 0)));
    cancel_thread_if_running((void *)(*(s32 *)((s8 *)&lbl_805C18A0.value + 4)));
    deactivate_entry_by_key((u32)((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 4))));
    unlock_mutex((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 0)));
    NetReleaseMutex((u32)((int) (*(s32 *)((s8 *)&lbl_805C18A0.value + 0))));
}

void start_network_thread(void) {
    if (TLobby__sub_803F96AC(((P_803F7A90 *)&lbl_805C18A0)) < 0 || TLobby__sub_803F9B94(run_net_thread_loop, &((P_803F7A90 *)&lbl_805C18A0)[0].b) < 0) {
        return;
    }
    NetResumeThread(((P_803F7A90 *)&lbl_805C18A0)[0].b);
}

/* Send thread: takes chunks from the send ring and hands them to the modem, waiting for each to drain. */
void queue_thread_main(void) {
    Q_803F7AF4 *p;
    for (;;) {
        p = get_next_send_chunk();
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

/* Consumes the previous chunk and returns the next contiguous run (at most 0x200 bytes) of the send ring, or NULL. */
Q_803F7AF4 *get_next_send_chunk(void) {
    s32 pos;
    lock_mutex(TLobby__send_ring_mutex);
    lobby_send_ring_pending_bytes -= lobby_send_chunk_size;
    if (lobby_send_ring_pending_bytes <= 0) {
        lobby_send_ring_pending_bytes = 0;
        lobby_send_chunk_size = 0;
        unlock_mutex(TLobby__send_ring_mutex);
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
    unlock_mutex(TLobby__send_ring_mutex);
    return &TLobby__next_send_chunk;
}

/* Appends len bytes to the send ring (wrapping) and wakes the send thread; returns 0 if there is no room. */
s32 write_ring_buffer(u8 *src, s32 len) {
    s32 first;
    s32 over;
    s32 end;
    s32 thread;
    u8 pad[8];
    thread = queue_thread_handle;
    lock_mutex(TLobby__send_ring_mutex);
    if (lobby_ring_buffer_size - lobby_send_ring_pending_bytes < len) {
        unlock_mutex(TLobby__send_ring_mutex);
        if (OSIsThreadSuspended(thread) == 1) {
            resume_thread(queue_thread_handle);
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
    unlock_mutex(TLobby__send_ring_mutex);
    if (OSIsThreadSuspended(thread) == 1) {
        resume_thread(queue_thread_handle);
    }
    return 1;
}

void set_lobby_map_state_code(s32 code) {
    lobby_map_state_code = code;
}

void subtract_network_queue_timeout(s32 elapsed_ms) {
    TLobby__queue_timeout_remaining -= elapsed_ms;
}

/* Maps lobby_map_state_code to a mode id (-1 for state 4). */
s32 map_state_to_mode_id(void) {
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

s32 map_state_to_code(s32 handle, s16 kind) {
    s32 mode;
    switch (kind) {
    case 0:
        mode = 1;
        break;
    case 1:
        mode = 2;
        break;
    default:
        return -1;
    }
    lobby_map_state_code = 4;
    if (TAdSinglePlyChrSelectGC__sub_8042E320(handle, mode, (void *)set_lobby_map_state_code) != 1) {
        return -1;
    }
    return 0;
}

s32 configure_modem_options(s32 ms_mode, s32 error_correction, s32 compression, s32 count, s32 cmd) {
    s32 value;
    s32 valid;
    u32 cmd_len;
    s32 result;
    valid = 1;
    switch (ms_mode) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 4: value = 4; break;
    case 5: value = 5; break;
    case 0: value = 2; break;
    default: valid = 0; break;
    }
    if (valid != 0 && send_at_ms_command__23TAdSinglePlyChrSelectGCFl(value) != 1) {
        return -1;
    }
    valid = 1;
    switch (error_correction) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 0:
    default: valid = 0; break;
    }
    if (valid != 0 && send_at_error_correction_cmd__23TAdSinglePlyChrSelectGCFl(value) != 1) {
        return -1;
    }
    valid = 1;
    switch (compression) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 4: value = 4; break;
    case 0:
    default: valid = 0; break;
    }
    if (valid != 0 && send_at_compression_cmd__23TAdSinglePlyChrSelectGCFl(value) != 1) {
        return -1;
    }
    while (count != 0) {
        cmd_len = NetStringLength((const char*)cmd);
        if (cmd_len > 0x3FU) {
            return -1;
        }
        result = TAdSinglePlyChrSelectGC__sub_8042D49C(cmd);
        if (result != 1 && result != -8) {
            return -1;
        }
        cmd = cmd_len + cmd;
        cmd++;
        count--;
    }
    return 0;
}

s32 send_atx_command_mode(s32 extended) {
    s32 mode;
    if (extended == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    if (send_atx_command__23TAdSinglePlyChrSelectGCFl(mode) == 1) {
        return 0;
    }
    return -1;
}

void TLobby__sub_803F808C(void) {

}

s32 is_transport_connected(void) {
    u8 buf[0x20];
    if (network_pppoe_transport_enabled != 0) {
        if (net_slot_id < 0) {
            return 0;
        }
        pppoe_recv_packet(NULL, 0, NULL);
        if (get_pppoe_session_id(net_slot_id) == 4) {
            return 1;
        }
        return 0;
    }
    if (copy_default_and_get_state__23TAdSinglePlyChrSelectGCFv(buf) == 3) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_803F811C(s16 *out) {
    *out = 0;
    return 0;
}

s32 recv_network_frame(u16 max_len, void *lobby, u16 *out_len) {
    if (network_pppoe_transport_enabled != 0) {
        if (net_slot_id < 0) {
            return 6;
        }
        {
            s16 slot = pppoe_recv_packet(lobby, max_len, out_len);
            if (slot != net_slot_id) {
                return 6;
            }
        }
    } else {
        s32 result = TAdSinglePlyChrSelectGC__sub_8042D7E0(lobby);
        if (result < 0) {
            *out_len = 0;
        } else {
            *out_len = result;
        }
    }
    return 0;
}

/* Sends a frame over PPPoE or the modem send ring; returns 5 on failure. */
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
    if (((u16)write_ring_buffer(src, (s32) len)) == 0) {
        return 5;
    }
block_7:
    return 0;
}

void close_network_transport(void) {
    s32 tries;
    if ((s16) network_pppoe_transport_enabled != 0) {
        if ((s16) net_slot_id >= 0) {
            TLobby__sub_80428094(net_slot_id);
            tries = 0;
retry_close:
            TLobby__sub_803F97E8(0xA);
            if ((pppoe_recv_packet(NULL, 0U, NULL) >= 0) && (get_pppoe_session_id(net_slot_id) != -1)) {
                tries += 1;
                if (tries < 0x12C) {
                    goto retry_close;
                }
            }
            if (get_pppoe_session_id(net_slot_id) != -1) {
                TLobby__sub_80428094(net_slot_id);
            }
            net_slot_id = -1;
            goto after_close;
        }
    } else {
        cancel_thread_if_running((void *)queue_thread_handle);
        deactivate_entry_by_key((u32) queue_thread_handle);
        NetReleaseMutex(TLobby__send_ring_mutex);
after_close:
        if ((u32) (copy_default_and_get_state__23TAdSinglePlyChrSelectGCFv((void *)0U) - 2) <= 1U) {
            TAdSinglePlyChrSelectGC__sub_8042D604();
        }
    }
}

s32 open_network_transport(A_803F8314 *cfg) {
    u8 *buf = pppoe_discovery_name_storage[0];
    char *name;
    s32 ret;
    if ((u32)send_ring_buffer_base == 0) {
        return 2;
    }
    if (cfg->flag != 0) {
        network_pppoe_transport_enabled = 1;
        buf[0] = 0;
        buf[0x100] = 0;
        net_slot_id = TLobby__sub_804281DC(buf);
        if (net_slot_id < 0) {
            return 2;
        }
    } else {
        network_pppoe_transport_enabled = 0;
        if (cfg->name != NULL) {
            name = cfg->name;
        } else {
            name = (char *)modem_default_connect_argument;
        }
        unlock_mutex(lbl_805C18A0.value);
        ret = TAdSinglePlyChrSelectGC__sub_8042CEF8(name);
        lock_mutex(lbl_805C18A0.value);
        if (ret == 1) {
            TAdSinglePlyChrSelectGC__sub_8042E488(5);
            if (TLobby__sub_803F96AC(&TLobby__send_ring_mutex) < 0) {
                return 2;
            }
            if (TLobby__sub_803F9B94((void *)queue_thread_main, &queue_thread_handle) < 0) {
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
/* Places the send ring at base; returns its end, or 0 (and clears the ring) if it passes limit. */
u32 compute_range_end(NetTransportParams *params, s32 base, u32 limit) {
    u32 end;
    send_ring_buffer_base = base;
    lobby_ring_buffer_size = params->ring_buffer_size;
    end = base + lobby_ring_buffer_size;
    if (end > limit) {
        send_ring_buffer_base = 0;
        lobby_ring_buffer_size = 0;
        return 0U;
    }
    return end;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
s32 layout_net_params_buffer(u8 *data, s32 size) {
    NetTransportParams params;
    u32 end;
    u8 *cur;
    s32 header_size;
    u32 after_tables;
    end = (u32)(data + size);
    header_size = get_net_params_and_size((NetTransportParams *)((int)&params));
    if (size < 0) {
        return -1;
    }
    if (size < header_size) {
        return -1;
    }
    net_transport_buffer_ptr_a = (u32)data;
    cur = data + params.player_count * 0x44;
    if ((u32)cur > end) {
        return -1;
    }
    net_transport_buffer_ptr_b = (u32)cur;
    cur += params.room_count * 0x544;
    if ((u32)cur > end) {
        return -1;
    }
    after_tables = layout_buffers((u8 *)&params, (u32)cur, end);
    if (after_tables == 0) {
        return -1;
    }
    if (params.b != 0 && compute_range_end(&params, after_tables, end) == 0) {
        return -1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
s32 validate_and_store_net_params(NetTransportParams *params) {
    u8 *raw = (u8 *)params;
    s32 e;
    if ((u16) params->player_count > 0x200U) {
        return -1;
    }
    if ((u16) params->room_count > 0x400U) {
        return -1;
    }
    e = params->e;
    if ((e < 0x400) || (e > 0xFFFF)) {
        return -1;
    }
    lbl_805D47F8 = params->a;
    lbl_805D4804 = *(s16 *)((s8 *)raw + 2);
    net_param_player_count = params->player_count;
    net_param_room_count = params->room_count;
    lbl_805D4800 = params->e;
    lbl_805D4808 = params->f;
    lbl_805D480C = params->ring_buffer_size;
    net_param_word_h = params->h;
    net_param_word_i = *(s32 *)((s8 *)raw + 0x18);
    return get_net_params_and_size((NetTransportParams *)(0));
}
#pragma pop

s32 get_net_params_and_size(NetTransportParams *out) {
    NetTransportParams local;
    s32 rooms_size;
    s32 players_size;
    s32 total;
    if (out == NULL) {
        out = &local;
    }
    out->a = lbl_805D47F8;
    out->b = lbl_805D4804;
    out->player_count = net_param_player_count;
    players_size = net_param_player_count * 0x44;
    out->room_count = net_param_room_count;
    rooms_size = net_param_room_count * 0x544;
    out->ring_buffer_size = lbl_805D480C;
    total = players_size + rooms_size;
    total += lbl_805D480C;
    out->e = lbl_805D4800;
    out->f = lbl_805D4808;
    out->h = net_param_word_h;
    out->i = net_param_word_i;
    total += TLobby__sub_803F8D24(out);
    return total;
}
