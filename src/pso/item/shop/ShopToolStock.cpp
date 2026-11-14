#include "types.h"
#include "pso/item/shop/ShopToolStock.h"
#include "pso/unk/text_80223B98.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/text_8020EEFC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/item/TItemData.h"
struct SRock_80224544_8022448C;


typedef struct Item_8022525C
{
  u8 b0;
  u8 b1;
  u8 b2;
  u8 pad3[7];
  u8 b12;
  u8 b13;
  u8 padC[8];
} Item_8022525C;

typedef struct Pool_8022525C
{
  u8 b[0x68];
} Pool_8022525C;

typedef struct Pair_8022525C
{
  s32 a;
  s32 b;
} Pair_8022525C;

typedef struct Ent_8022525C
{
  u8 id;
  u8 count;
} Ent_8022525C;

typedef struct Tier_8022525C
{
  Ent_8022525C *ents;
  u8 n;
} Tier_8022525C;

typedef struct Hdr_8022525C
{
  Tier_8022525C *tiers;
} Hdr_8022525C;

extern "C" {
s32 mem_alloc(s32);
void mem_free(void *p);
void sort_shop_items(s32, s32, s32);
u32 lobby_tool_random_rel;
int shop_tool_stock_level;
s32 shop_tool_stock_counts[4];
s32 shop_tool_stock_table[4];
s32 shop_tool_flags[4];
s32 shop_tool_stock_buffers[4];

}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

struct E_8022444C { u8 pad[0x10]; s32 f10; };

struct Item_802242F8 { u8 b[0x14]; };

struct Pair_802242F8 { s32 a; s32 b; };

struct Tbl_802242F8 { u8 *base; u8 count; };

struct Tbl_802242F8;
struct Tbl_80223EE0 { u8 *base; u8 count; };

struct Ent_80223EE0 { u8 kind; u8 a; u8 b; };

struct Obj_80223EE0 { u8 pad[2]; s8 lv; };

struct Obj_80223EE0;
struct Ent_8022403C { u8 id; u8 n; };

struct Tbl_8022403C { u8 pad[8]; Ent_8022403C *base; u8 count; };

struct Ctr_8022403C { u8 buf[0x74]; };

struct Ent_80224190 { u8 id; u8 n; };

struct Tbl_80224190 { Ent_80224190 *base; u8 count; };

struct Ctr_80224190 { u8 buf[0x74]; };

const Pair_802242F8 shop_tool_group_subtype_table[16] = {
    { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 6, 0 }, { 6, 1 },
    { 3, 0 }, { 4, 0 }, { 5, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { -1, -1 },
};
const s32 shop_technique_pool_table[19] = {
    0, 3, 6, 15, 16, 13, 10, 11, 12, 1, 4, 7, 14, 17, 2, 5, 8, 9, 18,
};

extern "C" {
s32 memset(void *, int, int);
void roll_shop_technique_level(Obj_80223EE0 *arg0, s32 arg1);
void push_shop_pool_entry(void *, u8);
s32 TLobby__sub_80223DD8(Item_802242F8 *, s32);
s32 TLobby__sub_80223E64(Item_802242F8 *, s32);
s32 fn_80223B98(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 4;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 5;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 5;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 7;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 7;
    }
    if (arg0 >= 0x65) {
        return 7;
    }
    return -1;
}

s32 fn_80223C28(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 2;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 2;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 2;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 2;
    }
    if (arg0 >= 0x65) {
        return 2;
    }
    return -1;
}
}

s32 classify_tool_shop_level_bracket(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 1;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 2;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 3;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x63)) {
        return 4;
    }
    if (arg0 >= 0x64) {
        return 5;
    }
    return -1;
}

s32 TLobby__sub_80223D48(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 1;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 2;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x3C)) {
        return 3;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x64)) {
        return 4;
    }
    if (arg0 >= 0x65) {
        return 4;
    }
    return -1;
}
s32 TLobby__sub_80223DD8(Item_802242F8 *item, s32 shop) {
    Item_802242F8 *stock = ((Item_802242F8 **)&shop_tool_stock_buffers)[shop];
    s32 i = 0;
    while (i++ < shop_tool_stock_counts[shop]) {
        if (item->b[0] == stock[i].b[0] && item->b[1] == stock[i].b[1] && item->b[2] == stock[i].b[2] &&
            item->b[4] == stock[i].b[4]) {
            return 0;
        }
    }
    return 1;
}

s32 TLobby__sub_80223E64(Item_802242F8 *item, s32 shop) {
    Item_802242F8 *stock = ((Item_802242F8 **)&shop_tool_stock_buffers)[shop];
    s32 i = 0;
    while (i++ < shop_tool_stock_counts[shop]) {
        if (item->b[0] == stock[i].b[0] && item->b[1] == stock[i].b[1] && item->b[2] == stock[i].b[2]) {
            return 0;
        }
    }
    return 1;
}



void roll_shop_technique_level(Obj_80223EE0 *arg0, s32 arg1) {
    Tbl_80223EE0 *t = ((Tbl_80223EE0 **)lobby_tool_random_rel)[2];
    s32 idx = TLobby__sub_80223D48(shop_tool_stock_level);
    Ent_80223EE0 *e;
    s32 level;
    idx *= t->count;
    e = &((Ent_80223EE0 *)t->base)[idx + arg1];
    level = shop_tool_stock_level;
    if (level > 99) {
        level = 99;
    }
    switch (e->kind) {
    case 0:
        arg0->lv = 0;
        break;
    case 1: {
        s8 v = level / e->a - 1;
        if (v < 0) {
            v = 0;
        }
        if (v > 14) {
            v = 14;
        }
        arg0->lv = v;
        break;
    }
    case 2: {
        s32 lo;
        s8 v = (s8)((f32)e->b * ((1.0f / 32768.0f) * (f32)rand()));
        lo = e->a - 1;
        if (v < lo) {
            v = lo;
        }
        if (v < 0) {
            v = 0;
        }
        if (v > 14) {
            v = 14;
        }
        arg0->lv = v;
        break;
    }
    }
}

void generate_shop_technique_pool(s32 shop) {
    Item_802242F8 it;
    Ctr_8022403C ctr;
    Ent_8022403C *e;
    s32 n;
    Item_802242F8 *arr;
    Tbl_8022403C *t;
    s32 i;
    s32 c;
    u8 k;
    arr = ((Item_802242F8 **)&shop_tool_stock_buffers)[shop];
    n = fn_80223B98(shop_tool_stock_level);
    if (n > 0) {
        ((TLobby *)(&ctr))->reset_counter_64();
        i = TLobby__sub_80223D48(shop_tool_stock_level);
        t = ((Tbl_8022403C **)lobby_tool_random_rel)[1];
        e = &t->base[i * t->count];
        c = 0;
        while (c++ < t->count) {
            k = e->n;
            while (k-- != 0) {
                push_shop_pool_entry(&ctr, e->id);
            }
            e++;
        }
        shuffle_shop_pool_n_times(&ctr, 5);
        i = 0;
        while (i < n) {
            s32 b = ((TLobby *)(&ctr))->pop_byte();
            if (b != -1) {
                ((TItemData *)(&it))->init();
                it.b[0] = 3;
                it.b[1] = 2;
                it.b[4] = shop_technique_pool_table[b];
                roll_shop_technique_level((Obj_80223EE0 *)&it, b);
                if (TLobby__sub_80223DD8(&it, shop) == 1) {
                    ((TItemData *)(&arr[shop_tool_stock_counts[shop]++]))->copy_from((TItemData *)(&it));
                    i++;
                }
            }
        }
    }
}

void generate_shop_rare_tool_pool(s32 shop) {
    Item_802242F8 it;
    Ctr_80224190 ctr;
    Tbl_80224190 *t;
    s32 j;
    Item_802242F8 *arr;
    s32 n;
    Ent_80224190 *e;
    s32 orig;
    s32 i;
    s32 b;
    s32 c;
    u8 k;
    arr = ((Item_802242F8 **)&shop_tool_stock_buffers)[shop];
    n = fn_80223C28(shop_tool_stock_level);
    if (n > 0) {
        ((TLobby *)(&ctr))->reset_counter_64();
        i = TLobby__sub_80223D48(shop_tool_stock_level);
        t = ((Tbl_80224190 **)lobby_tool_random_rel)[1];
        e = &t->base[i * t->count];
        c = 0;
        while (c++ < t->count) {
            k = e->n;
            while (k-- != 0) {
                push_shop_pool_entry(&ctr, e->id);
            }
            e++;
        }
        shuffle_shop_pool_n_times(&ctr, 8);
        {
            orig = n;
            j = 0;
            while (n > j) {
                b = ((TLobby *)(&ctr))->pop_byte();
                if (b == 0xF) {
                    if (orig == n) {
                        n--;
                    }
                } else if (b != -1) {
                    ((TItemData *)(&it))->init();
                    it.b[0] = 3;
                    it.b[1] = shop_tool_group_subtype_table[b].a;
                    it.b[2] = shop_tool_group_subtype_table[b].b;
                    if (TLobby__sub_80223E64(&it, shop) == 1) {
                        ((TItemData *)(&arr[shop_tool_stock_counts[shop]++]))->copy_from((TItemData *)(&it));
                        j++;
                    }
                }
            }
        }
    }
}

void generate_shop_common_tool_pool(s32 arg0) {
    Item_802242F8 it;
    Item_802242F8 *arr;
    Tbl_802242F8 *t;
    u8 *p;
    s32 i;
    s32 row;
    arr = ((Item_802242F8 **)&shop_tool_stock_buffers)[arg0];
    row = classify_tool_shop_level_bracket(shop_tool_stock_level);
    if (row >= 0) {
        t = *(Tbl_802242F8 **)lobby_tool_random_rel;
        row *= t->count;
        p = t->base + row;
        for (i = 0; i < t->count; i++, p++) {
            if (*p != 0xf) {
                ((TItemData *)(&it))->init();
                it.b[0] = 3;
                it.b[1] = shop_tool_group_subtype_table[*p].a;
                it.b[2] = shop_tool_group_subtype_table[*p].b;
                ((TItemData *)(&arr[shop_tool_stock_counts[arg0]++]))->copy_from((TItemData *)(&it));
            }
        }
    }
}

void clear_shop_tool_flags(void) {
    memset(shop_tool_flags, 0, 0x10);
}

void TLobby::copy_shop_item_entry(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    *(ByteBlock_14 *)(arg0) = *(const ByteBlock_14 *)(shop_tool_stock_buffers[arg2] + (arg1 * 0x14));
}
void mark_shop_tool_sold_out(s32 a, s32 b) {
    E_8022444C *arr = ((E_8022444C * *)&shop_tool_stock_buffers)[b];
    if (a >= 0 && a <= 0x11) {
        if (arr[a].f10 != -1) {
            arr[a].f10 = -1;
        }
    }
}

extern "C" {
void TLobby::set_6264_and_call_2244B0(int a0, int a1) { shop_tool_stock_level = a1; TLobby::generate_shop_inventory(a0); }

void TLobby::generate_shop_inventory(s32 idx) {
    if (lobby_tool_random_rel != 0) {
        if (shop_tool_flags[idx] == 0) {
            shop_tool_flags[idx] = 1;
            shop_tool_stock_counts[idx] = 0;
            shop_tool_stock_table[idx] = 0;
            generate_shop_common_tool_pool(idx);
            generate_shop_rare_tool_pool(idx);
            generate_shop_technique_pool(idx);
            sort_shop_items(shop_tool_stock_buffers[idx], shop_tool_stock_counts[idx], 2);
        }
    }
}

void TLobby::free_all_rocks() {
    s32 var_r28 = 3;
    s32 *var_r29 = shop_tool_stock_buffers;
    s32 var_r30 = 0;
    s32 var_r31 = 3;
    do {
        u32 v = (u32)var_r29[var_r31];
        if (v != 0U) {
            mem_free((void *)v);
            var_r29[var_r31] = (s32)var_r30;
        }
        var_r28 -= 1;
        var_r31 -= 1;
    } while (var_r28 >= 0);
    if ((u32) lobby_tool_random_rel != 0U) {
        TLobby::free_nodes_with_id(lobby_tool_random_rel);
        lobby_tool_random_rel = var_r30;
    }
}
}
s32 create_named_object(s32 arg0);
void load_tool_random_rel(void) {
    s32 i;
    (*(s32 *)&lobby_tool_random_rel) = create_named_object((s32)"ToolRandom.rel");
    for (i = 0; i < 4; i++) {
        ((s32 *)&shop_tool_stock_buffers)[i] = 0;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            ((s32 *)&shop_tool_stock_buffers)[i] = mem_alloc(0x168);
        }
    } else {
        ((s32 *)&shop_tool_stock_buffers)[0] = mem_alloc(0x168);
    }
    (*(s32 *)&shop_tool_stock_level) = 0;
}
