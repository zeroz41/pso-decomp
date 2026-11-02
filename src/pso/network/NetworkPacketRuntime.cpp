#include "pso/protocol/NetworkRuntime.h"
#include "pso/network/NetworkPacketPool.h"
#include <stddef.h>
#include "pso/network/NetworkTransport.h"
#include "pso/network/NetworkDispatch.h"

#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TUdpSocket.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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
extern u32 lbl_805D7BA8;
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
extern s16 lbl_805D7B08;
void TLobby__sub_80423298(void);
extern s32 lbl_805D7B14;
extern s16 lbl_805D7B18;
void TLobby__sub_80424CA8(void);
extern u8 lbl_805CF240[];
s32 TLobby__sub_804251C0(s16, void *);
extern s32 lbl_805D4820;
extern volatile s32 lbl_805D7BA0;

extern G_804249F0 lbl_805C1E00;
extern s32 lbl_805D7B0C;
extern s32 lbl_805D7B10;
extern u8 lbl_805D7B1C[6];
extern u32 lbl_805D7B28;
extern u32 lbl_805D7B4C;
extern u32 lbl_805D7B50;
extern u8 dhcp_hostname[0x2C];
extern u32 lbl_805D7B5C;
extern u32 lbl_805D7B60;
extern u32 lbl_805D7B70;
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
s16 TUdpSocket__sub_80421DEC(void *, int, void *, int, int, s32 (*)(s16, Arg_804249F0 *));
s32 TLobby__sub_80424DCC(s16, s32, s32, void *, void *, void *, void *, s32);
s32 dhcp_handle_reply__6TLobbyFsPv(s16 arg0, Arg_804249F0 *arg1);
extern void *lbl_805D7B40;
extern void *lbl_805D7B44;
extern void *lbl_805D7B48;
extern s32 lbl_805D7B54;
extern s32 lbl_805D7B58;
extern s32 lbl_805D7B74;

s32 TLobby::get_task_count() {
    return lbl_805D4820;
}

s32 TLobby__sub_80425288(s16, s16, void *);
extern u32 lbl_805D7B64;
extern u32 lbl_805D7B68;
extern u32 lbl_805D7B6C;
extern u32 lbl_805D7B78;
extern u32 lbl_805D7B7C;

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
        TLobby::get_time_seconds((s32 *)&lbl_805D7B78);
        lbl_805D7B7C = lbl_805D7B78 + lbl_805D7B64;
        if (find_dhcp_option__6TLobbyFPvUcPv(arg0, 0x3A, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            TLobby__sub_80425288(8, 4, &w);
        } else {
            TLobby__sub_80425288(8, 0, NULL);
            lbl_805D7B68 = lbl_805D7B64 >> 1;
        }
        if (find_dhcp_option__6TLobbyFPvUcPv(arg0, 0x3B, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            TLobby__sub_80425288(9, 4, &w);
        } else {
            TLobby__sub_80425288(9, 0, NULL);
            lbl_805D7B6C = (lbl_805D7B64 >> 1) + (lbl_805D7B64 >> 2) + (lbl_805D7B64 >> 3);
        }
    } else {
        TLobby__sub_80425288(7, 0, NULL);
        lbl_805D7B64 = -1;
    }
}

s32 TLobby__sub_8042474C(void *lease, void *renew, void *rebind) {
    lbl_805D7BA0 = 0;
    if ((*(volatile s32 *)&lbl_805D4820) == 3 || (*(volatile s32 *)&lbl_805D4820) == 4 || (*(volatile s32 *)&lbl_805D4820) == 5) {
        if (TLobby__sub_804251C0(7, lease) != 0) {
            lbl_805D7BA0 = 0x11;
        }
        if (TLobby__sub_804251C0(8, renew) != 0 && lbl_805D7BA0 == 0) {
            lbl_805D7BA0 = 0x12;
        }
        if (TLobby__sub_804251C0(9, rebind) != 0 && lbl_805D7BA0 == 0) {
            lbl_805D7BA0 = 0x13;
        }
        return 0;
    }
    lbl_805D7BA0 = 2;
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
    lbl_805D7BA0 = 0;
    if ((*(volatile s32 *)&lbl_805D4820) != 3 && (*(volatile s32 *)&lbl_805D4820) != 4 && (*(volatile s32 *)&lbl_805D4820) != 5) {
        lbl_805D7BA0 = 2;
        return -1;
    }
    if (TLobby__sub_804251C0(6, out) != 0) {
        lbl_805D7BA0 = 0x10;
    }
    return 0;
}

s32 TLobby::validate_slot_buffers(s32 arg0, void *arg1, void *arg2, void *arg3) {
    lbl_805D7BA0 = 0;
    if ((*(volatile s32 *)&lbl_805D4820) != 3 && (*(volatile s32 *)&lbl_805D4820) != 4 && (*(volatile s32 *)&lbl_805D4820) != 5) {
        lbl_805D7BA0 = 2;
        return -1;
    }
    if (TLobby__sub_804251C0(4, arg2) != 0) {
        lbl_805D7BA0 = 0xE;
    }
    if (TLobby__sub_804251C0(5, arg3) != 0 && lbl_805D7BA0 == 0) {
        lbl_805D7BA0 = 0xF;
    }
    if (TLobby__sub_804251C0(3, arg1) != 0 && lbl_805D7BA0 == 0) {
        lbl_805D7BA0 = 0xD;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
s32 dhcp_handle_reply__6TLobbyFsPv(s16 arg0, Arg_804249F0 *arg1) {
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
    if (lbl_805D7B0C != 2) {
        return 0;
    }
    switch (lbl_805D4820) {
    case 3:
        break;
    case 1:
        if (lbl_805D7B10 == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 2 &&
            find_dhcp_option__6TLobbyFPvUcPv(q, 0x36, &p) == 4) {
            TLobby__sub_80425288(0xE, 4, p);
            lbl_805D7B28 = pk->f10;
            lbl_805D7B10 = 1;
        }
        break;
    case 2:
        if (lbl_805D7B10 == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 5) {
            NetMemcpy(g->buf, pk, arg1->len);
            lbl_805D7B10 = 1;
        }
        break;
    case 4:
        if (lbl_805D7B10 == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 5 &&
            lbl_805D7B28 == pk->f10) {
            NetMemcpy(g->buf, pk, arg1->len);
            lbl_805D7B10 = 1;
        }
        break;
    case 5:
        if (lbl_805D7B10 == 0 && find_dhcp_option__6TLobbyFPvUcPv(q, 0x35, &p) == 1 && *p == 5 &&
            lbl_805D7B28 == pk->f10) {
            NetMemcpy(g->buf, pk, arg1->len);
            lbl_805D7B10 = 1;
        }
        break;
    }
    return 0;
}
#pragma pop

void TLobby__sub_80424CA8(void) {
    NetUnregisterTimer((void *)TLobby__sub_80423298);
    if (lbl_805D7B18 != -1) {
        TLobby__sub_80421B3C(lbl_805D7B18);
        lbl_805D7B18 = -1;
    }
    lbl_805D7B14 = TLobby__sub_804250A8(0);
}

s32 TLobby__sub_80424CF4(void *, void *, s32 timeout) {
    s32 state;
    *(volatile s32 *)&lbl_805D4820 = 6;
    *(volatile s32 *)&lbl_805D7B0C = 0;
    lbl_805D7B74 = timeout;
    lbl_805D7BA0 = 0;
    do {
        state = *(volatile s32 *)&lbl_805D4820;
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
        state = lbl_805D4820;
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
    lbl_805D7BA0 = 0;
    if (*(volatile s32 *)&lbl_805D4820 != 0) {
        lbl_805D7BA0 = 2;
        return -1;
    }
    if (a4 == NULL || a5 == NULL || a6 == NULL) {
        lbl_805D7BA0 = 1;
        return -1;
    }
    lbl_805D7B40 = a4;
    lbl_805D7B44 = a5;
    lbl_805D7B48 = a6;
    lbl_805D7B54 = a1;
    lbl_805D7B58 = a2;
    lbl_805D7B74 = a7;
    *(volatile s32 *)&lbl_805D4820 = 1;
    *(volatile s32 *)&lbl_805D7B0C = 0;
    return 0;
}

// Inferred name: clears the DHCP client state (lease timers, option table, hostname) and records the interface.
static inline void dhcp_reset_state(s16 iface) {
    u32 i;

    lbl_805D4820 = 0;
    lbl_805D7B0C = 0;
    lbl_805D7B10 = 0;
    lbl_805D7B14 = TLobby__sub_804250A8(0);
    lbl_805D7B18 = -1;
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
    lbl_805D7B5C = 0;
    lbl_805D7B60 = 0;
    lbl_805D7B64 = 0;
    lbl_805D7B68 = 0;
    lbl_805D7B6C = 0;
    lbl_805D7B70 = 0;
    lbl_805D7B74 = 0;
    lbl_805D7B78 = 0;
    lbl_805D7B7C = 0;
    lbl_805D7BA0 = 0;
    lbl_805D7B08 = iface;
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
    if (dhcp_open_interface(lbl_805D7B08) != 0) {
        lbl_805D7BA0 = 3;
        return -1;
    }
    NetRegisterTimer(50, 0, TLobby__sub_80423298);
    return 0;
}

s32 TLobby__sub_80424FE0(void) {
    s32 addr[7];
    u8 unused[4];
    if ((*(volatile s32 *)&lbl_805D4820) == 4 || (*(volatile s32 *)&lbl_805D4820) == 5 || (*(volatile s32 *)&lbl_805D4820) == 6) {
        if (lbl_805D7B18 > -1) {
            TLobby__sub_80421B3C(lbl_805D7B18);
        }
        addr[0] = 4;
        addr[1] = 0;
        if ((lbl_805D7B18 = TUdpSocket__sub_80421DEC(0, 0x44, addr, 0x43, 0, dhcp_handle_reply__6TLobbyFsPv)) < 0) {
            if (*(volatile s32 *)&lbl_805D4820 == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            lbl_805D7BA0 = 4;
            *(volatile s32 *)&lbl_805D7B0C = -1;
            *(volatile s32 *)&lbl_805D4820 = -2;
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
    cur = TLobby__sub_80422F70(lbl_805D7B08, info, sizeof(info), mac) < 0 ? 0 : 1;
    if (cur != mode) {
        switch (mode) {
        case 1: {
            s32 req[7];
            req[0] = 4;
            req[1] = 0;
            req[2] = -1;
            req[3] = -1;
            if (TLobby__sub_8042315C(lbl_805D7B08, req) != 0) {
                TLobby__sub_80423064(lbl_805D7B08, 4);
                if (request_iface_mode4(lbl_805D7B08) != 0) {
                    lbl_805D7BA0 = 3;
                    *(volatile s32 *)&lbl_805D7B0C = -1;
                    *(volatile s32 *)&lbl_805D4820 = -2;
                    return 0;
                }
            }
            return 1;
        }
        case 0:
            TLobby__sub_80423064(lbl_805D7B08, 4);
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
    TLobby::lock_mutex((int)((void *)lbl_805D7BA8));
    r = (R_804253A0 *)TLobby::find_entry_by_address(a);
    TUdpSocket::unlock_mutex((int)((void *)lbl_805D7BA8));
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
    TLobby::lock_mutex((int)((void *)lbl_805D7BA8));
    buf = alloc_packet_buffer(size);
    TUdpSocket::unlock_mutex((int)((void *)lbl_805D7BA8));
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
    TLobby::lock_mutex((int)((void *)lbl_805D7BA8));
    e = find_804253F8(addr);
    TUdpSocket::unlock_mutex((int)((void *)lbl_805D7BA8));
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
    NetReleaseMutex(lbl_805D7BA8);
}
}
s32 initialize_network_packet_pool(void) {
    s32 i;
    if (TLobby__sub_803F96AC(&lbl_805D7BA8) < 0) {
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
