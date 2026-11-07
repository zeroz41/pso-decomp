#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkPacketPool.h"
#include <stddef.h>
#include "pso/network/NetworkTransport.h"
#include "pso/network/NetworkDispatch.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TUdpSocket.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Pkt_804249F0 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 pad3;
    u8 f4[4];
    u8 pad8[0x10 - 0x8];
    u32 f10;
    u8 pad14[0x1C - 0x14];
    u8 f1C[6];
    u8 pad22[0xEC - 0x22];
    u8 opts[4];
};

struct G_804249F0 {
    u8 pad0[0x5DC];
    u8 buf[0xBB8 - 0x5DC];
    Pkt_804249F0 pkt;
};

struct Arg_804249F0 {
    u8 pad0[2];
    s16 len;
    void *p;
};

struct RecoveredGlobal_80428374_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
};

struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
};

struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

typedef struct Names_8042E57C {
    char *name[6];
} Names_8042E57C;

typedef struct Names_8042E628 {
    char *name[4];
} Names_8042E628;

typedef struct Names_8042E6C4 {
    char *name[5];
} Names_8042E6C4;

typedef struct Names_8042E7B8 {
    char *name[3];
} Names_8042E7B8;

typedef struct Ent_80426894 {
    s16 count;
    u8 id[6];
} Ent_80426894;

typedef struct Tbl_80426894 {
    u8 pad[6];
    Ent_80426894 ent[6];
} Tbl_80426894;

typedef struct Ent_80427C6C {
    u16 pad0;
    u16 id;
    u8 rest[0xE10];
} Ent_80427C6C;

struct R_804253A0 { s32 a; s32 b; };

struct Rec_80426998 { u16 a; u16 b; };

struct Obj_80426998 { u8 pad[0x36]; s16 count; Rec_80426998 recs[5]; };

NetworkPacketBufferDescriptor network_packet_buffer_descriptors[NETWORK_PACKET_BUFFER_COUNT];
u8 network_packet_buffers[NETWORK_PACKET_BUFFER_COUNT][NETWORK_PACKET_BUFFER_BYTES];
extern u8 lbl_805CF240[0xA0];
extern u8 TLobby__pppoe_message_queue[0xA0];
extern u8 lbl_805CF380[0x48];
extern "C" {
extern u32 network_packet_mutex;
void TAdSinglePlyChrSelectGC__sub_8042DDE4(int, int);
extern u8 lobby_net_channel_table[];
extern u8 lbl_805CF380[];
extern u8 TLobby__pppoe_message_queue[];
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

s16 TLobby__sub_804262CC(void *);
u8 find_dhcp_option__6TLobbyFPvUcPv(u8 *p, u8 tag, u8 **out);
void NetUnregisterTimer(void *);
s32 TLobby__sub_80421B3C(s32);
s32 TLobby__sub_804250A8(s32);
s16 TLobby__sub_80422F70(s16 iface, void *buf, s32 len, void *out);
s16 TLobby__sub_8042315C(s16 iface, void *req);
s16 TLobby__sub_80423064(s16 iface, s32 mode);
extern s16 dhcp_iface;
void TLobby__sub_80423298(void);
extern s32 lbl_805D7B14;
extern s16 dhcp_socket;
void TLobby__sub_80424CA8(void);
extern u8 lbl_805CF240[];
s32 TLobby__sub_804251C0(s16, void *);
extern s32 dhcp_state;
extern volatile s32 dhcp_error;

extern G_804249F0 lbl_805C1E00;
extern s32 dhcp_step;
extern s32 dhcp_reply_received;
extern u8 lbl_805D7B1C[6];
extern u32 lbl_805D7B28;
extern u32 lbl_805D7B4C;
extern u32 lbl_805D7B50;
extern u8 dhcp_hostname[0x2C];
extern u32 dhcp_elapsed_ms;
extern u32 dhcp_last_tick_ms;
extern u32 dhcp_lease_elapsed;
s16 TLobby__sub_803F96AC(u32*);
struct DhcpOption_804FD948 {
    s16 id;
    s16 present;
    s16 kind;
    s16 size;
    void *data;
};
extern DhcpOption_804FD948 lbl_804FD948[12];
void TLobby__sub_803F97E8(s32);
s16 TUdpSocket__sub_80421DEC(void *, int, void *, int, int, s32 (*)(s16, void *));
s32 TLobby__sub_80424DCC(s16, s32, s32, void *, void *, void *, void *, s32);
extern void *lbl_805D7B40;
extern void *lbl_805D7B44;
extern void *lbl_805D7B48;
extern s32 lbl_805D7B54;
extern s32 lbl_805D7B58;
extern s32 dhcp_max_retries;

s32 TLobby::get_task_count() {
    return dhcp_state;
}

s32 TLobby__sub_80425288(s16, s16, void *);
// DHCP lease (RFC 2131 names, inferred): lease = option 0x33, renewal T1 = option 0x3A (default lease/2),
// rebinding T2 = option 0x3B (default 7/8 lease), start/expiry in seconds from get_time_seconds.
extern u32 dhcp_lease_time;
extern u32 dhcp_renewal_time;
extern u32 dhcp_rebinding_time;
extern u32 dhcp_lease_start;
extern u32 dhcp_lease_expiry;

void TLobby::parse_dhcp_lease_times() {
    u8 *arg0 = (u8 *)this;
    s32 find_dhcp_option__6TLobbyFPvUcPv(u8 *p, u8 tag, u8 **out);
    u8 *p;
    s32 v;
    s32 w;

    if (find_dhcp_option__6TLobbyFPvUcPv(arg0, 0x33, &p) == 4) {
        NetMemcpy(&v, p, 4);
        w = v;
        TLobby__sub_80425288(7, 4, &w);
        TLobby::get_time_seconds((s32 *)&dhcp_lease_start);
        dhcp_lease_expiry = dhcp_lease_start + dhcp_lease_time;
        if (find_dhcp_option__6TLobbyFPvUcPv(arg0, 0x3A, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            TLobby__sub_80425288(8, 4, &w);
        } else {
            TLobby__sub_80425288(8, 0, NULL);
            dhcp_renewal_time = dhcp_lease_time >> 1;
        }
        if (find_dhcp_option__6TLobbyFPvUcPv(arg0, 0x3B, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            TLobby__sub_80425288(9, 4, &w);
        } else {
            TLobby__sub_80425288(9, 0, NULL);
            dhcp_rebinding_time = (dhcp_lease_time >> 1) + (dhcp_lease_time >> 2) + (dhcp_lease_time >> 3);
        }
    } else {
        TLobby__sub_80425288(7, 0, NULL);
        dhcp_lease_time = -1;
    }
}

s32 TLobby__sub_8042474C(void *lease, void *renew, void *rebind) {
    dhcp_error = 0;
    if ((*(volatile s32 *)&dhcp_state) == 3 || (*(volatile s32 *)&dhcp_state) == 4 || (*(volatile s32 *)&dhcp_state) == 5) {
        if (TLobby__sub_804251C0(7, lease) != 0) {
            dhcp_error = 0x11;
        }
        if (TLobby__sub_804251C0(8, renew) != 0 && dhcp_error == 0) {
            dhcp_error = 0x12;
        }
        if (TLobby__sub_804251C0(9, rebind) != 0 && dhcp_error == 0) {
            dhcp_error = 0x13;
        }
        return 0;
    }
    dhcp_error = 2;
    return -1;
}

u8 find_dhcp_option__6TLobbyFPvUcPv(u8 *p, u8 tag, u8 **out) {
    u8 *base = p;
    u8 t;
    u8 len;
    p += 4;
    while ((s32)((u32)base - (u32)p) < 0x4D4) {
        t = *p++;
        if (t == 0) {
            continue;
        }
        if (t == 0xFF) {
            return 0;
        }
        if (t == tag) {
            len = *p++;
            *out = p;
            return len;
        }
        len = *p++;
        p += len;
    }
    return 0;
}

s32 TLobby__sub_8042489C(void *, void *out) {
    dhcp_error = 0;
    if ((*(volatile s32 *)&dhcp_state) != 3 && (*(volatile s32 *)&dhcp_state) != 4 && (*(volatile s32 *)&dhcp_state) != 5) {
        dhcp_error = 2;
        return -1;
    }
    if (TLobby__sub_804251C0(6, out) != 0) {
        dhcp_error = 0x10;
    }
    return 0;
}

s32 TLobby::validate_slot_buffers(s32 arg0, void *arg1, void *arg2, void *arg3) {
    dhcp_error = 0;
    if ((*(volatile s32 *)&dhcp_state) != 3 && (*(volatile s32 *)&dhcp_state) != 4 && (*(volatile s32 *)&dhcp_state) != 5) {
        dhcp_error = 2;
        return -1;
    }
    if (TLobby__sub_804251C0(4, arg2) != 0) {
        dhcp_error = 0xE;
    }
    if (TLobby__sub_804251C0(5, arg3) != 0 && dhcp_error == 0) {
        dhcp_error = 0xF;
    }
    if (TLobby__sub_804251C0(3, arg1) != 0 && dhcp_error == 0) {
        dhcp_error = 0xD;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
s32 TLobby::dhcp_handle_reply(s16 arg0, void *arg) {
    Arg_804249F0 *arg1 = (Arg_804249F0 *)arg;
    s32 find_dhcp_option__6TLobbyFPvUcPv(u8 *p, u8 tag, u8 **out);
    G_804249F0 *g = &lbl_805C1E00;
    Pkt_804249F0 *pk;
    u8 *q;
    u8 *p;

    if (arg0 == 0) {
        arg1->p = &g->pkt;
        return 0;
    }
    pk = &g->pkt;
    q = pk->opts;
    if (pk->f0 != 2 || pk->f1 != 1 || pk->f2 != 6) {
        return 0;
    }
    if (NetMemcmp(pk->f4, &lbl_805D7B50, 4) != 0) {
        return 0;
    }
    if (NetMemcmp(pk->f1C, lbl_805D7B1C, 6) != 0) {
        return 0;
    }
    if (NetMemcmp(q, &lbl_805D7B4C, 4) != 0) {
        return 0;
    }
    if (dhcp_step != 2) {
        return 0;
    }
    switch (dhcp_state) {
    case 3:
        break;
    case 1:
        if (dhcp_reply_received == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 2 &&
            find_dhcp_option__6TLobbyFPvUcPv(q, 0x36, &p) == 4) {
            TLobby__sub_80425288(0xE, 4, p);
            lbl_805D7B28 = pk->f10;
            dhcp_reply_received = 1;
        }
        break;
    case 2:
        if (dhcp_reply_received == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 5) {
            NetMemcpy(g->buf, pk, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    case 4:
        if (dhcp_reply_received == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 5 &&
            lbl_805D7B28 == pk->f10) {
            NetMemcpy(g->buf, pk, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    case 5:
        if (dhcp_reply_received == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 5 &&
            lbl_805D7B28 == pk->f10) {
            NetMemcpy(g->buf, pk, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    }
    return 0;
}
#pragma pop

void TLobby__sub_80424CA8(void) {
    NetUnregisterTimer((void *)TLobby__sub_80423298);
    if (dhcp_socket != -1) {
        TLobby__sub_80421B3C(dhcp_socket);
        dhcp_socket = -1;
    }
    lbl_805D7B14 = TLobby__sub_804250A8(0);
}

s32 TLobby__sub_80424CF4(void *, void *, s32 timeout) {
    s32 state;
    *(volatile s32 *)&dhcp_state = 6;
    *(volatile s32 *)&dhcp_step = 0;
    dhcp_max_retries = timeout;
    dhcp_error = 0;
    do {
        state = *(volatile s32 *)&dhcp_state;
        TLobby__sub_803F97E8(0x10);
    } while (state == 6);
    if (state != 0) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80424D58(s16 a0, s32 a1, s32 a2, void *a3, void *a4, void *a5, void *a6, s32 a7) {
    s32 state;
    if (TLobby__sub_80424DCC(a0, a1, a2, a3, a4, a5, a6, a7) != 0) {
        return -1;
    }
    do {
        state = dhcp_state;
        TLobby__sub_803F97E8(0x10);
    } while (state == 1 || state == 2);
    if (state == -1) {
        return 1;
    }
    if (state == -2) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80424DCC(s16, s32 a1, s32 a2, void *, void *a4, void *a5, void *a6, s32 a7) {
    dhcp_error = 0;
    if (*(volatile s32 *)&dhcp_state != 0) {
        dhcp_error = 2;
        return -1;
    }
    if (a4 == NULL || a5 == NULL || a6 == NULL) {
        dhcp_error = 1;
        return -1;
    }
    lbl_805D7B40 = a4;
    lbl_805D7B44 = a5;
    lbl_805D7B48 = a6;
    lbl_805D7B54 = a1;
    lbl_805D7B58 = a2;
    dhcp_max_retries = a7;
    *(volatile s32 *)&dhcp_state = 1;
    *(volatile s32 *)&dhcp_step = 0;
    return 0;
}

// Inferred name: clears the DHCP client state (lease timers, option table, hostname) and records the interface.
static inline void dhcp_reset_state(s16 iface) {
    u32 i;

    dhcp_state = 0;
    dhcp_step = 0;
    dhcp_reply_received = 0;
    lbl_805D7B14 = TLobby__sub_804250A8(0);
    dhcp_socket = -1;
    for (i = 0; i < 12; i++) {
        lbl_804FD948[i].present = 0;
        NetMemset(lbl_804FD948[i].data, 0, lbl_804FD948[i].size);
    }
    lbl_805D7B40 = 0;
    lbl_805D7B44 = 0;
    lbl_805D7B48 = 0;
    lbl_805D7B4C = 0x63825363;
    lbl_805D7B50 = 0;
    lbl_805D7B54 = 0;
    lbl_805D7B58 = 0;
    NetMemset(dhcp_hostname, 0, 0x20);
    dhcp_elapsed_ms = 0;
    dhcp_last_tick_ms = 0;
    dhcp_lease_time = 0;
    dhcp_renewal_time = 0;
    dhcp_rebinding_time = 0;
    dhcp_lease_elapsed = 0;
    dhcp_max_retries = 0;
    dhcp_lease_start = 0;
    dhcp_lease_expiry = 0;
    dhcp_error = 0;
    dhcp_iface = iface;
}

// Inferred name: brings the interface up (mode-4 request, then reads its 0x1C-byte info and 6-byte hardware address into lbl_805D7B1C).
static inline s32 dhcp_open_interface(s16 iface) {
    s32 addr[7];
    addr[0] = 4;
    addr[1] = 0;
    addr[2] = 0;
    addr[3] = 0;
    if (TLobby__sub_8042315C(iface, addr) < 0) {
        return -1;
    }
    if (TLobby__sub_80422F70(iface, addr, 0x1C, lbl_805D7B1C) < 0) {
        TLobby__sub_80423064(iface, 4);
        return -1;
    }
    TLobby__sub_80423064(iface, 4);
    return 0;
}

s32 TLobby__sub_80424E44(s16 iface) {
    dhcp_reset_state(iface);
    if (dhcp_open_interface(dhcp_iface) != 0) {
        dhcp_error = 3;
        return -1;
    }
    NetRegisterTimer(50, 0, TLobby__sub_80423298);
    return 0;
}

// Opens the DHCP client UDP socket (port 68 to server port 67; names inferred); returns the handle or an error.
// Same helper as in text_80421620.cpp (dhcp_discover_step expands it too).
static inline s16 dhcp_open_socket(u32 *addr) {
    s16 r;
    addr[0] = 4;
    addr[1] = 0;
    r = TUdpSocket__sub_80421DEC(0, 0x44, addr, 0x43, 0, TLobby::dhcp_handle_reply);
    dhcp_socket = r;
    return r;
}

s32 TLobby__sub_80424FE0(void) {
    s16 sock;
    u32 addr[5];
    if ((*(volatile s32 *)&dhcp_state) == 4 || (*(volatile s32 *)&dhcp_state) == 5 || (*(volatile s32 *)&dhcp_state) == 6) {
        if (dhcp_socket > -1) {
            TLobby__sub_80421B3C(dhcp_socket);
        }
        sock = dhcp_open_socket(addr);
        if (sock < 0) {
            if (*(volatile s32 *)&dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_error = 4;
            *(volatile s32 *)&dhcp_step = -1;
            *(volatile s32 *)&dhcp_state = -2;
            return -1;
        }
    }
    return 0;
}

struct P_8042315C {
    s32 type;
    s32 a;
    s32 b;
    s32 c;
    s32 pad10;
    s16 n;
    s16 m;
    s32 d;
    s32 pad1C;
};

static inline s16 request_iface_mode4(s16 iface) {
    P_8042315C req;
    req.type = 4;
    req.a = 0;
    req.b = -1;
    req.c = -1;
    return TLobby__sub_8042315C(iface, &req);
}

s32 TLobby__sub_804250A8(s32 mode) {
    u8 mac[6];
    u8 info[0x1C];
    s32 cur;
    cur = TLobby__sub_80422F70(dhcp_iface, info, sizeof(info), mac) < 0 ? 0 : 1;
    if (cur != mode) {
        switch (mode) {
        case 1: {
            s32 req[7];
            req[0] = 4;
            req[1] = 0;
            req[2] = -1;
            req[3] = -1;
            if (TLobby__sub_8042315C(dhcp_iface, req) != 0) {
                TLobby__sub_80423064(dhcp_iface, 4);
                if (request_iface_mode4(dhcp_iface) != 0) {
                    dhcp_error = 3;
                    *(volatile s32 *)&dhcp_step = -1;
                    *(volatile s32 *)&dhcp_state = -2;
                    return 0;
                }
            }
            return 1;
        }
        case 0:
            TLobby__sub_80423064(dhcp_iface, 4);
            return 0;
        }
    }
    return cur;
}

s32 TLobby__sub_804251C0(s16 id, void *out) {
    DhcpOption_804FD948 *tbl = lbl_804FD948;
    s32 result = -1;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (id == tbl[i].id) {
            if (tbl[i].present != 0) {
                result = 0;
            }
            if (out != NULL) {
                switch (tbl[i].kind) {
                case 0:
                    NetCopyString((char*)out, (const char*)tbl[i].data);
                    break;
                case 1:
                    NetMemcpy(out, tbl[i].data, tbl[i].size);
                    break;
                }
            }
            break;
        }
    }
    return result;
}

s32 TLobby__sub_80425288(s16 id, s16 len, void *value) {
    DhcpOption_804FD948 *tbl = lbl_804FD948;
    s32 result = -1;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (id == tbl[i].id) {
            result = 0;
            switch (tbl[i].kind) {
            case 0:
            case 1:
                if (value != NULL) {
                    tbl[i].present = 1;
                    NetMemcpy(tbl[i].data, value, tbl[i].size);
                    if (tbl[i].kind == 0) {
                        u8 *end = (u8 *)tbl[i].data;
                        if (len < tbl[i].size) {
                            end += len;
                        } else {
                            end += tbl[i].size - 1;
                        }
                        *end = 0;
                    }
                } else {
                    tbl[i].present = 0;
                    if (len > 0) {
                        NetMemset(tbl[i].data, 0, tbl[i].size);
                    }
                }
                break;
            }
            break;
        }
    }
    return result;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline NetworkPacketBufferDescriptor *find_804253F8(u32 arg0) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (network_packet_buffer_descriptors[i].in_use != 0 && (u32)network_packet_buffer_descriptors[i].data <= arg0 &&
            arg0 < (u32)network_packet_buffer_descriptors[i].data + 0x600) {
            break;
        }
    }
    if (i >= 0x20) {
        return NULL;
    }
    return &network_packet_buffer_descriptors[i];
}

void TLobby::clear_message_entry(s32 a) {
    R_804253A0 *r;
    u8 unused[8];
    TLobby::lock_mutex((int)((void *)network_packet_mutex));
    r = (R_804253A0 *)TLobby::find_entry_by_address(a);
    TUdpSocket::unlock_mutex((int)((void *)network_packet_mutex));
    if (r != 0) {
        r->a = 0;
        r->b = 0;
    }
}

void TLobby::release_entry_by_id(u32 arg0) {
    NetworkPacketBufferDescriptor *e = find_804253F8(arg0);
    if (e != NULL) {
        e->in_use = 0;
        e->queued_length = 0;
    }
}

static inline u8 *alloc_packet_buffer(u32 size) {
    s16 i;
    u8 *buf = NULL;
    if (size > NETWORK_PACKET_BUFFER_BYTES) {
        return NULL;
    }
    for (i = 0; i < NETWORK_PACKET_BUFFER_COUNT; i++) {
        if (network_packet_buffer_descriptors[i].in_use == 0) {
            network_packet_buffer_descriptors[i].in_use = 1;
            buf = network_packet_buffer_descriptors[i].data;
            break;
        }
    }
    if (i >= NETWORK_PACKET_BUFFER_COUNT) {
        return NULL;
    }
    return buf;
}

u8 *TLobby__sub_8042558C(u32 size) {
    u8 *buf;
    TLobby::lock_mutex((int)((void *)network_packet_mutex));
    buf = alloc_packet_buffer(size);
    TUdpSocket::unlock_mutex((int)((void *)network_packet_mutex));
    return buf;
}

u8 *TLobby__sub_80425640(u32 size) {
    s16 i;
    u8 *buf = NULL;
    if (size > NETWORK_PACKET_BUFFER_BYTES) {
        return NULL;
    }
    for (i = 0; i < NETWORK_PACKET_BUFFER_COUNT; i++) {
        if (network_packet_buffer_descriptors[i].in_use == 0) {
            network_packet_buffer_descriptors[i].in_use = 1;
            buf = network_packet_buffer_descriptors[i].data;
            break;
        }
    }
    if (i >= NETWORK_PACKET_BUFFER_COUNT) {
        return NULL;
    }
    return buf;
}

NetworkPacketBufferDescriptor *TLobby__sub_804256B8(u32 addr) {
    NetworkPacketBufferDescriptor *e;
    TLobby::lock_mutex((int)((void *)network_packet_mutex));
    e = find_804253F8(addr);
    TUdpSocket::unlock_mutex((int)((void *)network_packet_mutex));
    return e;
}
#pragma pop

u8 *TLobby::find_entry_by_address(s32 arg0) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i].in_use != 0 && (u32)((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i].data <= (u32)arg0 && (u32)arg0 < (u32)((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i].data + 0x600) {
            break;
        }
    }
    if (i >= 32) {
        return NULL;
    }
    return (u8 *)&((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i];
}

void TLobby::cancel_alarm_a() {
    NetReleaseMutex(network_packet_mutex);
}
}
s32 initialize_network_packet_pool(void) {
    s32 i;
    if (TLobby__sub_803F96AC(&network_packet_mutex) < 0) {
        return -1;
    } else {
    for (i = 0; (0x20) > (i); i++) {
        network_packet_buffer_descriptors[i].in_use = 0;
        network_packet_buffer_descriptors[i].queued_length = 0;
        network_packet_buffer_descriptors[i].data = network_packet_buffers[i];
    }
    }
    return 0;
}

#define arg0 ((s32)argp)
extern "C" {
s16 TLobby__sub_804262CC(void *argp);
#undef arg0

#pragma push
#pragma dont_inline on
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s16 remove_rec_80426998(u16 key) {
    s32 i;
    Obj_80426998 *o = ((Obj_80426998 *)&lobby_net_channel_table);
    Rec_80426998 *p = o->recs;
    for (i = 5; i != 0; i--, p++) {
        if (p->a != 0 && p->b == key) {
            p->a = 0;
            p->b = 0;
            o->count--;
            return 0;
        }
    }
    return -1;
}
#pragma pop

typedef char RecoveredGlobal_80427D0C_lbl_805CFC20_size[sizeof(RecoveredGlobal_80427D0C_lbl_805CFC20) == 0xE20 ? 1 : -1];

typedef char RecoveredGlobal_80428374_lbl_805D0A40_size[sizeof(RecoveredGlobal_80428374_lbl_805D0A40) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80428360_lbl_805CFC20_size[sizeof(RecoveredGlobal_80428360_lbl_805CFC20) == 0xE20 ? 1 : -1];

typedef char RecoveredGlobal_8042839C_lbl_805D0A40_size[sizeof(RecoveredGlobal_8042839C_lbl_805D0A40) == 0x60 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8042DD70_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042DD70_lbl_805D1D20) == 0x1C ? 1 : -1];
#pragma pop

void TAdSinglePlyChrSelectGC__sub_8042DDE4(int _w0, int _w1);
}

typedef char RecoveredGlobal_8042E768_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042E768_lbl_805D1D20) == 0x1C ? 1 : -1];

typedef char NetworkPacketDescriptorSize[sizeof(NetworkPacketBufferDescriptor)==12 ? 1 : -1];
typedef char NetworkPacketInUseOffset[offsetof(NetworkPacketBufferDescriptor,in_use)==0 ? 1 : -1];
typedef char NetworkPacketLengthOffset[offsetof(NetworkPacketBufferDescriptor,queued_length)==4 ? 1 : -1];
typedef char NetworkPacketDataOffset[offsetof(NetworkPacketBufferDescriptor,data)==8 ? 1 : -1];
