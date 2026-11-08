/* The network stack's configuration: the stack (a C library, built with GC/1.2.5n) calls these at start-up to
 * fill its configuration records with counts, sizes and the static buffers below. */
#include "types.h"
#include <stddef.h>
#include "pso/network/netcfg.h"
#include "pso/network/NetworkMessageTransport.h"

typedef struct Big_803F8AD8 {
    u8 pad0[0xB7A0];
    u8 bufB7A0[0x2FC0];
    u8 bufE760[0x30];
    u8 bufE790[0x10];
    void *funcs[7];
} Big_803F8AD8;

typedef struct Ent_803F8DBC { s32 active; s32 size; s32 val; } Ent_803F8DBC;
typedef struct Ent_803F8BA4 { u8 pad[0x31C]; s32 size; u8 *buf; u8 pad2[4]; } Ent_803F8BA4;
typedef struct Ent_803F8D84 { s32 active; s32 unk4; u32 key; } Ent_803F8D84;
typedef struct Ent_803F9B48 { s32 active; u32 key; u8 pad[0x328 - 8]; } Ent_803F9B48;

extern s16 net_param_room_count;
extern s32 lbl_805D4800;
extern s32 net_transport_buffer_ptr_b;
extern s16 net_param_player_count;
extern s32 net_transport_buffer_ptr_a;
s32 lbl_805D7A58;
extern u16 lobby_buffer_slot_count;
extern Ent_803F8D84 *lobby_buffer_slots;
extern u16 lobby_thread_pool_count;
extern Ent_803F9B48 *lobby_thread_pool_base;
extern u8 *lobby_buffer_pool_base;
extern u8 *lobby_second_buffer_pool_base;
extern u32 lobby_buffer_pool_size;
extern u8 *lbl_805D7C04;
extern u32 lbl_805D7C08;


static u32 lobby_net_config_block[4722];
static NetIpv6IfParams ipv6_interface_config;
static u32 lbl_805B38A0[13];
static u32 lbl_805B38D4[50];
static u32 lbl_805B399C[99];
static u32 lbl_805B3B28[36];
static u32 lbl_805B3BB8[1267];
static s32 lbl_805B4F84[212];
static s32 lbl_805B52D4[96];
static s32 lbl_805B5454[26];
static s32 lbl_805B54BC[4096];
static s32 lbl_805B94BC[30];
static s32 lbl_805B9534[1059];
static s32 lbl_805BA5C0[3115];
static s32 lobby_net_recv_desc[641];

extern NetSizes lbl_805D7A50;

void TLobby__sub_803F86BC(void *cfg) {
}

void init_net_config(NetConfig *c) {
    u8 *buf = (u8 *)lobby_net_config_block;
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

void TLobby__sub_803F8794(void *cfg) {
}

void init_params(NetParamCfg *cfg) {
    cfg->count = net_param_room_count;
    cfg->f8 = lbl_805D4800;
    cfg->fC = lbl_805D4800;
    cfg->fA0 = 0x64;
    cfg->buffer = net_transport_buffer_ptr_b;
}

void TLobby__sub_803F87C4(void *cfg) {
}

void TLobby__sub_803F87C8(u8 *cfg) {
    *(s16 *)(cfg + 0) = net_param_player_count;
    *(s32 *)(cfg + 8) = net_transport_buffer_ptr_a;
}

void TLobby__sub_803F87DC(void *cfg) {
}

void init_ipv6_interface_config(NetIpv6IfCfg *cfg) {
    cfg->x0 = 1;
    cfg->xc = 0;
    cfg->x10 = 0;
    cfg->x14 = 0x40;
    cfg->x4 = lbl_805B38A0;
    cfg->cfg = ipv6_interface_config;
}

void TLobby__sub_803F8864(void *cfg) {
}

void init_udp_socket_config(NetUdpCfg *o) {
    o->a0 = 0x1A;
    o->a2 = 3;
    o->a4 = 9;
    o->a14 = 9;
    o->a6 = 1;
    o->aA = 1;
    o->a8 = 1;
    o->aC = 1;
    o->a10 = 1;
    o->aE = 2;
    o->a16 = 0x1E;
    o->a12 = 0x500;
    o->p18 = (u8 *)lbl_805B3BB8;
    o->p1C = (u8 *)lbl_805B3B28;
    o->p20 = (u8 *)lbl_805B399C;
    o->p24 = (u8 *)lbl_805B38D4;
}

void TLobby__sub_803F88E0(void *cfg) {
}

void init_buffer_descriptor_b(NetBufDescB *cfg) {
    u8 *new_var;
    cfg->f0 = 2;
    new_var = (u8 *)lobby_net_config_block;
    cfg->f2 = 8;
    cfg->f4 = 8;
    cfg->f14 = 0x5DC;
    cfg->f8 = new_var + 0x6064;
    cfg->fC = new_var + 0x5E24;
    cfg->f10 = new_var + 0x5D04;
    cfg->f18 = (u8 *)lobby_net_config_block + 0x514C;
}

void TLobby__sub_803F892C(void *cfg) {
}

#pragma push
#pragma opt_common_subs on
void TLobby__sub_803F8930(u8 *cfg) {
    *(s16 *)(cfg + 0) = 1;
    *(s8 *)(cfg + 0xA) = 0;
    *(s8 *)(cfg + 0xB) = 0x78;
    *(s32 **)(cfg + 4) = lbl_805B4F84;
}
#pragma pop

void TLobby__sub_803F8958(void *cfg) {
}

void init_buffer_descriptor_a(NetBufDescA *cfg) {
    cfg->f0 = 0x1A;
    cfg->f2 = 3;
    cfg->f4 = 9;
    cfg->f6 = 0x240;
    cfg->f8 = (u8 *)lobby_net_config_block + 0x621C;
    cfg->fC = (u8 *)lobby_net_config_block + 0x61C8;
    cfg->f10 = (u8 *)lobby_net_config_block + 0x60F0;
}

void TLobby__sub_803F89A0(void *cfg) {
}

void TLobby__sub_803F89A4(u8 *cfg) {
    struct NetConfig { s16 field_0; s16 field_2; s16 field_4; u8 pad_6[2]; s32 *field_8; s32 *field_C; };
    ((struct NetConfig *)cfg)->field_0 = 2;
    ((struct NetConfig *)cfg)->field_2 = 0x10;
    ((struct NetConfig *)cfg)->field_4 = 8;
    ((struct NetConfig *)cfg)->field_8 = lbl_805B5454;
    ((struct NetConfig *)cfg)->field_C = lbl_805B52D4;
}

void TLobby__sub_803F89D8(void *cfg) {
}

void init_buffer_desc_a(NetBufDescA2 *cfg) {
    cfg->f0 = 2;
    cfg->f2 = 0x2000;
    cfg->f4 = lbl_805B94BC;
    cfg->f8 = lbl_805B54BC;
}

void TLobby__sub_803F8A08(void *cfg) {
}

void TLobby__sub_803F8A0C(u8 *cfg) {
    *(s16 *)(cfg + 0) = 5;
    *(s32 **)(cfg + 4) = lbl_805B9534;
}

void TLobby__sub_803F8A24(void *cfg) {
}

void init_net_buffer_config(NetBufferCfg *cfg) {
    cfg->f0 = 8;
    cfg->f2 = 3;
    cfg->f4 = 2;
    cfg->f6 = 0x5DC;
    cfg->f8 = 9;
    cfg->fA = 0x14;
    cfg->fC = 3;
    cfg->f10 = (u8 *)lobby_net_config_block + 0xB650;
    cfg->f14 = (u8 *)lobby_net_config_block + 0xB5F0;
    cfg->f1C = (u8 *)lobby_net_config_block + 0xB5D0;
    cfg->f18 = (u8 *)lobby_net_config_block + 0xB564;
    cfg->f20 = (u8 *)lobby_net_config_block + 0xA9AC;
    cfg->f24 = (u8 *)lobby_net_config_block + 0xA990;
}

void TLobby__sub_803F8A9C(void *cfg) {
}

void TLobby__sub_803F8AA0(u8 *cfg) {
    *(s16 *)(cfg + 0) = 3;
    *(s32 **)(cfg + 4) = lbl_805BA5C0;
}

void TLobby__sub_803F8AB8(void *cfg) {
    reset_message_thread();
}

void init_net_func_table(NetFuncTableCfg *cfg) {
    Big_803F8AD8 *g = (Big_803F8AD8 *)lobby_net_config_block;
    g->funcs[0] = (void *)TLobby__sub_80426B88;
    g->funcs[1] = (void *)open_channel_checked;
    g->funcs[2] = (void *)remove_rec_by_handle;
    g->funcs[3] = (void *)add_multicast_address;
    g->funcs[4] = (void *)consume_item_count_by_id;
    g->funcs[5] = (void *)get_local_address;
    g->funcs[6] = (void *)queue_timeout_message;
    cfg->a = 1;
    cfg->b = 1;
    cfg->c = 3;
    cfg->d = 8;
    cfg->funcs = g->funcs;
    cfg->x = g->bufE790;
    cfg->y = g->bufE760;
    cfg->z = g->bufB7A0;
}

void TLobby__sub_803F8B78(void *cfg) {
}

void init_net_recv_desc(NetRecvDescCfg *cfg) {
    cfg->fA = 0x500;
    cfg->fC = 2;
    cfg->f10 = &lbl_805D7A58;
    cfg->f14 = lobby_net_recv_desc;
}

u8 *layout_buffers(NetBufferLayout *h, u8 *p, u8 *end) {
    Ent_803F8DBC *e;
    Ent_803F8BA4 *f;
    s32 i;
    u16 n = h->n2;
    lobby_thread_pool_count = 2;
    lobby_buffer_slot_count = n * 2;
    if (h->a != 0) {
        lobby_thread_pool_count += 1;
    }
    if (h->b != 0) {
        lobby_thread_pool_count += 2;
    }
    *(u8 **)&lobby_buffer_slots = p;
    p += lobby_buffer_slot_count * 12;
    if (p > end) {
        return NULL;
    }
    e = *(Ent_803F8DBC **)&lobby_buffer_slots;
    for (i = 0; i < lobby_buffer_slot_count; i++, e++) {
        e->active = 0;
        e->size = h->c;
        e->val = (s32)p;
        p += h->c;
        if (p > end) {
            return NULL;
        }
    }
    *(u8 **)&lobby_thread_pool_base = p;
    p += lobby_thread_pool_count * 0x328;
    if (p > end) {
        return NULL;
    }
    f = *(Ent_803F8BA4 **)&lobby_thread_pool_base;
    for (i = 0; i < lobby_thread_pool_count; i++, f++) {
        f->size = h->d;
        f->buf = p;
        p += h->d;
        if (p > end) {
            return NULL;
        }
    }
    if (h->f != 0) {
        lobby_buffer_pool_base = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
        lobby_second_buffer_pool_base = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
        lobby_buffer_pool_size = h->f;
    }
    if (h->g != 0) {
        lbl_805D7C04 = p;
        p += h->g;
        if (p > end) {
            return NULL;
        }
        lbl_805D7C08 = h->g;
    }
    return p;
}

s32 TLobby__sub_803F8D24(NetBufferLayout *h) {
    s32 n = 2;
    s32 size;
    if (h->a != 0) {
        n = 3;
    }
    if (h->b != 0) {
        n += 2;
    }
    size = (h->d + 0x328) * n;
    size += (h->c + 12) * h->n2 * 2;
    size += h->f * 2;
    size += h->g;
    return size;
}

void TLobby__sub_803F8D84(u32 key) {
    Ent_803F8D84 *e = lobby_buffer_slots;
    s32 i;
    for (i = 0; i < lobby_buffer_slot_count; i++) {
        if (e->key == key) {
            e->active = 0;
            return;
        }
        e++;
    }
}

s32 alloc_buffer_slot(s32 size) {
    Ent_803F8DBC *e = *(Ent_803F8DBC **)&lobby_buffer_slots;
    s32 i;
    s32 r = 0;
    for (i = 0; i < lobby_buffer_slot_count; i++) {
        if (e->active == 0 && e->size >= size) {
            e->active = size;
            r = e->val;
            break;
        }
        e++;
    }
    return r;
}
