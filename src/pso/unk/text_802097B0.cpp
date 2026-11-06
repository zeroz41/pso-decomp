#include "types.h"
#include "pso/unk/text_802097B0.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/unk/TLobby_8020A350.h"
#include "pso/unk/TLobby_8020A568.h"
#include "pso/unk/TLobby.h"
#include "pso/system/EventShuffleTable.h"
struct Ent_802098AC { f32 a, b, c; u32 d, e, f, g; };

struct Out_802098AC { u8 pad[0x14]; f32 a, b, c; u32 d, e, f; };

struct Hdr_802099FC { s32 table; s32 b; s32 count; s32 d; };

struct Rec_802099FC { f32 f[5]; s16 h[6]; };

struct Out_802099FC {
    u8 pad0[6];
    s16 f6;
    u8 pad8[0x2C - 8];
    f32 f[5];
    s16 f40;
    s16 f42;
};

struct Hdr_80209AEC { s32 a; s32 table; s32 c; s32 count; };

struct Ent_80209AEC { u8 b0; u8 b1; u8 weight; u8 pad; };

struct Rec_802099FC;
struct Tmp_8020994C { u8 pad[0x18]; s16 v; u8 pad2[2]; };

struct Hdr_802097B0 { s32 table; s32 data; s32 count; };

struct Ent_802097B0 { s16 id; s16 count; s32 offset; };

void init_event_shuffle_table(EventShuffleTable *table, s32 count);

s32 next_event_shuffle_entry(EventShuffleTable *s);
extern s32 lbl_805D60A4;
Ent_802098AC *lbl_805D60B8;
extern "C" {
s16 clamp_min_drop__6TLobbyFUl(s32, s32);
extern u8 *TLobby__item_data_table_buffer;
void TLobby__sub_802099FC(Out_802099FC *arg0, s32 arg1);
extern s32 item_drop_rng;
Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key);
extern u8 *lbl_805D60AC;

void TLobby__sub_802097B0(s16 id) {
    Ent_802097B0 e;
    Hdr_802097B0 hdr = *(Hdr_802097B0 *)lbl_805D60AC;
    u8 *table;
    s32 lo;
    s32 hi;
    s32 mid;

    ((TLobby *)(&hdr))->bswap_vec3();
    table = lbl_805D60AC + hdr.table;
    lo = 0;
    hi = hdr.count - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        TLobby__sub_8020A3D0(&e, table + mid * 8);
        TLobby__sub_8020A394(&e);
        if (e.id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    TLobby__sub_8020A3D0(&e, table + lo * 8);
    TLobby__sub_8020A394(&e);
    if (e.id == id) {
        lbl_805D60B8 = (Ent_802098AC *)((u32)lbl_805D60AC + hdr.data + e.offset);
        init_event_shuffle_table((EventShuffleTable *)lbl_805D60A4, e.count);
    }
}

void TLobby::pick_random_entry() {
    Out_802098AC *out = (Out_802098AC *)this;
    s32 i = next_event_shuffle_entry((EventShuffleTable *)lbl_805D60A4);
    Ent_802098AC e = lbl_805D60B8[i];
    ((TLobby *)(&e))->swap_header_endian();
    out->a = e.a;
    out->b = e.b;
    out->c = e.c;
    out->d = e.d;
    out->e = e.e;
    out->f = e.f;
}

Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key) {
    u8 *arr = (u8 *)arg0;
    u8 *e;
    Tmp_8020994C t;
    s32 lo;
    s32 hi;
    s32 mid;
    hi = n - 1;
    lo = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        ((TLobby *)(&t))->copy_record_entry((s32)(arr + mid * 32));
        TLobby__sub_8020A48C(&t);
        if (t.v < key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    e = arr + lo * 32;
    ((TLobby *)(&t))->copy_record_entry((s32)e);
    TLobby__sub_8020A48C(&t);
    if (t.v == key) {
        return (Rec_802099FC *)e;
    }
    return NULL;
}

void TLobby__sub_802099FC(Out_802099FC *arg0, s32 key) {
    Hdr_802099FC hdr = *(Hdr_802099FC *)TLobby__item_data_table_buffer;
    Rec_802099FC *p;
    TLobby__sub_8020A568(&hdr);
    p = bsearch_record__6TLobbyFPvii((void *)(TLobby__item_data_table_buffer + hdr.table), hdr.count, key);
    if (p != NULL) {
        Rec_802099FC r = *p;
        TLobby__sub_8020A48C(&r);
        arg0->f[0] = r.f[0];
        arg0->f[1] = r.f[1];
        arg0->f[2] = r.f[2];
        arg0->f[3] = r.f[3];
        arg0->f[4] = r.f[4];
        arg0->f40 = r.h[1];
        arg0->f42 = r.h[0];
        arg0->f6 = clamp_min_drop__6TLobbyFUl(r.h[4], r.h[5] + 1);
    }
}
}
void TLobby::pick_weighted_entry(s32 *arg0, s32 *arg1) {
    Hdr_80209AEC hdr = *(Hdr_80209AEC *)TLobby__item_data_table_buffer;
    Ent_80209AEC *tbl;
    u32 total;
    u32 r;
    s32 i;
    s32 n;
    TLobby__sub_8020A568(&hdr);
    tbl = (Ent_80209AEC *)(TLobby__item_data_table_buffer + hdr.table);
    n = hdr.count;
    total = 0;
    for (i = 0; i < n; i++) {
        total += tbl[i].weight;
    }
    r = item_drop_rng_below(item_drop_rng, total);
    for (i = 0; i < n; i++) {
        if (tbl[i].weight != 0) {
            if (r < tbl[i].weight) {
                *arg0 = tbl[i].b1;
                *arg1 = tbl[i].b0;
                return;
            }
            r -= tbl[i].weight;
        }
    }
    *arg1 = -1;
    *arg0 = -1;
}
