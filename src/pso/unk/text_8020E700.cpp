// ---- pso/unk/text_8020E700
#include "types.h"
#include <string.h>
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/text_8020E700.h"
#include "pso/unk/text_8020EEFC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8020E400.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>

#pragma readonly_strings on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

struct Ent_8020EC68 { u8 pad[0x10]; s32 v; };

struct Item_8020E934 { u8 b[0x14]; };

// Shop stock draw pool: up to 100 entry ids and their count (pop_byte/push_shop_pool_entry).
struct ShopPool {
    u8 entries[0x64];
    s32 count;
    u8 pad_68[0xC];
};

struct Tbl_8020E934 { u8 pad[8]; u8 *pairs; u8 count; };

struct Tbl_8020E800 { u8 pad[0x10]; u8 *pairs; u8 count; };

struct Tbl_8020EACC { u8 *pairs; u8 count; };

struct Rec_8020E700 { u8 a, b, c, d, e, f; u8 pad[0x14 - 6]; };

extern "C" {
// Per shop list (four in split screen): the stock array (0x1A4 bytes, allocated by load_armor_random_table),
// its entry count and whether it was generated.
s32 shop_armor_stock_generated_flags[4];
s32 lbl_80513D68[4];
saddr lbl_80513D78[4];
Tbl_8020E934 ** lbl_805D6158;
s32 lbl_805D615C;
extern s32 shop_difficulty_tier;
void push_shop_pool_entry(ShopPool *, u8);
s32 is_duplicate_shop_shield_or_unit(Item_8020E934 *, s32);
s32 is_duplicate_shop_armor(Rec_8020E700 *arg0, s32 arg1);
s32 is_duplicate_shop_armor(Rec_8020E700 *arg0, s32 arg1) {
    s32 i;
    Rec_8020E700 *tbl = (Rec_8020E700 *)lbl_80513D78[arg1];
    for (i = 0; i < lbl_80513D68[arg1]; i++) {
        if (arg0->a == tbl[i].a && arg0->b == tbl[i].b && arg0->c == tbl[i].c && arg0->f == tbl[i].f) {
            return 0;
        }
    }
    return 1;
}

s32 is_duplicate_shop_shield_or_unit(Item_8020E934 *arg0, s32 arg1) {
    s32 i;
    Item_8020E934 *tbl = (Item_8020E934 *)lbl_80513D78[arg1];
    for (i = 0; i < lbl_80513D68[arg1]; i++) {
        if (arg0->b[0] == tbl[i].b[0] && arg0->b[1] == tbl[i].b[1] && arg0->b[2] == tbl[i].b[2]) {
            return 0;
        }
    }
    return 1;
}

}

void generate_shop_unit_pool(s32 arg0) {
    Item_8020E934 item;
    ShopPool ctr;
    Item_8020E934 *dst;
    s32 cnt;
    s32 n;
    Tbl_8020E800 *tbl;
    u8 *p;
    s32 i;
    s32 b;
    s32 k;
    s32 grp;
    ((TLobby *)(&ctr))->reset_counter_64();
    dst = (Item_8020E934 *)lbl_80513D78[arg0];
    n = get_shop_unit_count(lbl_805D615C);
    if (n == 0) {
        return;
    }
    tbl = (Tbl_8020E800 *)*lbl_805D6158;
    grp = TLobby::get_lobby_group(lbl_805D615C);
    cnt = tbl->count;
    p = tbl->pairs + grp * cnt * 2;
    i = 0;
    while (i++ < cnt) {
        for (k = p[1]; k != 0; k--) {
            push_shop_pool_entry(&ctr, p[0]);
        }
        p += 2;
    }
    shuffle_shop_pool_n_times(&ctr, 8);
    cnt = 0;
    while (cnt < n) {
        b = ((TLobby *)(&ctr))->pop_byte();
        if (b == -1) {
            continue;
        }
        ((TItemData *)(&item))->init();
        item.b[0] = 1;
        item.b[1] = 3;
        item.b[2] = b;
        if (is_duplicate_shop_shield_or_unit(&item, arg0) == 1) {
            ((TItemData *)(&dst[lbl_80513D68[arg0]++]))->copy_from((TItemData *)(&item));
            cnt++;
        }
    }
}

void generate_shop_shield_pool(s32 arg0) {
    Item_8020E934 item;
    ShopPool ctr;
    Item_8020E934 *dst;
    s32 n;
    Tbl_8020E934 *tbl;
    u8 *p;
    s32 i;
    s32 b;
    s32 *counts;
    s32 cnt;
    s32 j;
    s32 k;
    s32 grp;
    ((TLobby *)(&ctr))->reset_counter_64();
    dst = (Item_8020E934 *)lbl_80513D78[arg0];
    n = TLobby::get_shield_shop_tier_for_level(lbl_805D615C);
    tbl = *lbl_805D6158;
    grp = TLobby::get_lobby_group(lbl_805D615C);
    cnt = tbl->count;
    p = tbl->pairs + grp * cnt * 2;
    i = 0;
    while (i++ < cnt) {
        for (k = p[1]; k != 0; k--) {
            push_shop_pool_entry(&ctr, p[0]);
        }
        p += 2;
    }
    shuffle_shop_pool_n_times(&ctr, 8);
    j = 0;
    counts = lbl_80513D68;
    while (j < n) {
        b = ((TLobby *)(&ctr))->pop_byte();
        if (b == -1) {
            continue;
        }
        ((TItemData *)(&item))->init();
        item.b[0] = 1;
        item.b[1] = 2;
        if (shop_difficulty_tier != 3) {
            item.b[2] = b;
        } else if (lbl_805D615C >= 1 && lbl_805D615C <= 99) {
            item.b[2] = b;
        } else if (lbl_805D615C >= 100 && lbl_805D615C <= 150) {
            item.b[2] = b + 2;
        } else if (lbl_805D615C >= 151 && lbl_805D615C <= 200) {
            item.b[2] = b + 3;
        } else {
            item.b[2] = b;
        }
        if (is_duplicate_shop_shield_or_unit(&item, arg0) == 1) {
            ((TItemData *)(&dst[counts[arg0]++]))->copy_from((TItemData *)(&item));
            j++;
        }
    }
}


void generate_shop_armor_pool(s32 arg0) {
    Item_8020E934 item;
    ShopPool ctr;
    Item_8020E934 *dst;
    s32 n;
    s32 cnt;
    s32 i;
    Tbl_8020EACC *tbl;
    u8 *p;
    s32 b;
    s32 *counts;
    s32 j;
    s32 k;
    s32 grp;
    ((TLobby *)(&ctr))->reset_counter_64();
    dst = (Item_8020E934 *)lbl_80513D78[arg0];
    n = TLobby::get_armor_shop_tier_for_level(lbl_805D615C);
    tbl = *(Tbl_8020EACC **)lbl_805D6158;
    grp = TLobby::get_lobby_group(lbl_805D615C);
    cnt = tbl->count;
    grp *= cnt;
    p = tbl->pairs + grp * 2;
    i = 0;
    while (i++ < cnt) {
        for (k = p[1]; k != 0; k--) {
            push_shop_pool_entry(&ctr, p[0]);
        }
        p += 2;
    }
    shuffle_shop_pool_n_times(&ctr, 8);
    j = 0;
    counts = lbl_80513D68;
    while (j < n) {
        b = ((TLobby *)(&ctr))->pop_byte();
        if (b == -1) {
            continue;
        }
        ((TItemData *)(&item))->init();
        item.b[0] = 1;
        item.b[1] = 1;
        if (shop_difficulty_tier != 3) {
            item.b[2] = b;
        } else if (lbl_805D615C >= 1 && lbl_805D615C <= 99) {
            item.b[2] = b;
        } else if (lbl_805D615C >= 100 && lbl_805D615C <= 150) {
            item.b[2] = b + 2;
        } else if (lbl_805D615C >= 151 && lbl_805D615C <= 200) {
            item.b[2] = b + 3;
        } else {
            item.b[2] = b;
        }
        ((TItemData *)&item)->register_drop();
        if (is_duplicate_shop_armor((Rec_8020E700 *)&item, arg0) == 1) {
            ((TItemData *)(&dst[counts[arg0]++]))->copy_from((TItemData *)(&item));
            j++;
        }
    }
}

void TLobby::clear_shop_entry_value(s32 i, s32 j) {
    Ent_8020EC68 *e = (Ent_8020EC68 *)lbl_80513D78[j];
    if (i >= 0 && i <= 0x14) {
        if (e[i].v != -1) e[i].v = -1;
    }
}

void clear_shop_armor_flags(void) {
    memset(shop_armor_stock_generated_flags, 0, 0x10);
}

void TLobby::copy_armor_shop_entry(s32 arg1, s32 base) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_14 *)(arg0) = ((const ByteBlock_14 *)lbl_80513D78[base])[arg1];
}

// ---- pso/unk/TLobby_8020ED20


void TLobby::set_shop_armor_list_flag(int a0, int a1) { lbl_805D615C = a1; generate_armor_shop_stock(a0); }


// ---- pso/unk/text_8020ED44


#include "pso/unk/text_8020ED44.h"

void generate_armor_shop_stock(s32 arg0) {
    if (lbl_805D6158 != NULL) {
        if (shop_armor_stock_generated_flags[arg0] == 0) {
            shop_armor_stock_generated_flags[arg0] = 1;
            lbl_80513D68[arg0] = 0;
            generate_shop_armor_pool(arg0);
            generate_shop_shield_pool(arg0);
            generate_shop_unit_pool(arg0);
        }
    }
}
extern "C" {

// ---- pso/unk/TLobby_8020EDBC
void mem_free(void *p);
}

void TLobby::free_rocks() {
    s32 i = 3;
    saddr *var_r29 = lbl_80513D78;
    saddr var_r30 = 0;
    s32 var_r31 = 3;
    do {
        uaddr v = (u32)var_r29[var_r31];
        if (v != 0U) {
            mem_free((void *)v);
            var_r29[var_r31] = var_r30;
        }
        i -= 1;
        var_r31 -= 1;
    } while (i >= 0);
    if (lbl_805D6158 != NULL) {
        TLobby::free_nodes_with_id((uaddr)lbl_805D6158);
        lbl_805D6158 = (Tbl_8020E934 **)var_r30;
    }
}

// ---- pso/unk/text_8020EE2C

#include "pso/unk/text_8020EE2C.h"
#include "pso/unk/text_800F9B84.h"
extern "C" {
s32 mem_alloc(s32);
}

// Dead-stripped from the DOL: no code of it survives, only its literals. The TU's int-to-float
// constant (0x4330000080000000, .rodata 0x8044BC38) is pooled ahead of "ArmorRandom.rel"
// (0x8044BC40), yet load_armor_random_table is compiled before shuffle_shop_pool, the constant's
// one surviving user: a function compiled ahead of it converted an int. This reconstruction draws
// a random pool index the way shuffle_shop_pool (and ShopToolStock's roll_shop_technique_level)
// draws. Name inferred.
s32 draw_shop_pool_index(s32 count) {
    return (s32)((f32)count * (3.0517578e-05f * (f32)rand()));
}

void load_armor_random_table(void) {
    s32 i;
    lbl_805D6158 = static_cast<Tbl_8020E934 **>(create_named_object("ArmorRandom.rel"));
    for (i = 0; i < 4; i++) {
        lbl_80513D78[i] = 0;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            lbl_80513D78[i] = mem_alloc(0x1A4);
        }
    } else {
        lbl_80513D78[0] = mem_alloc(0x1A4);
    }
    lbl_805D615C = 0;
}

// ---- pso/unk/TLobby_8020EED8

// Called on a draw pool (ShopPool), not on a lobby: takes the last entry.
s32 TLobby::pop_byte() {
    ShopPool *pool = (ShopPool *)this;
    s32 count = pool->count;

    if (count > 0) {
        s32 last = count - 1;
        pool->count = last;
        return pool->entries[last];
    }
    return -1;
}

// ---- pso/unk/text_8020EEFC


void shuffle_shop_pool_n_times(void *pool, s32 times) {
    while (times-- > 0) {
        shuffle_shop_pool(pool);
    }
}
void shuffle_shop_pool(void *pool_) {
    ShopPool *pool = (ShopPool *)pool_;
    s32 i;
    s32 k;
    u8 t;
    for (i = 0; i < pool->count; i++) {
        k = (s32)((f32)pool->count * (3.0517578e-05f * (f32)rand()));
        t = pool->entries[i];
        pool->entries[i] = pool->entries[k];
        pool->entries[k] = t;
    }
}

// ---- pso/unk/TLobby_8020F00C

#include "pso/ui/hud/TRaderMapCore.h"

void push_shop_pool_entry(ShopPool *pool, u8 entry) {
    s32 count;
    count = pool->count;
    if (count < 0x64) {
        pool->count = count + 1;
        pool->entries[count] = entry;
    }
}

void TLobby::reset_counter_64() { ((ShopPool *)this)->count = 0; }
