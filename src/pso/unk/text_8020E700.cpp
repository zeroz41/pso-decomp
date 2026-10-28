#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/unk/text_8020E700.h"
#include "pso/unk/text_8020EEFC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_8020E400.h"
#include "pso/item/TItemData.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

struct RecoveredGlobal_8020ECD8_lbl_80513D78 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8020ECA8_lbl_80513D58 {
    s32 value;
    u8 remaining[0xC];
};

struct Ent_8020EC68 { u8 pad[0x10]; s32 v; };

struct Item_8020E934 { u8 b[0x14]; };

struct Ctr_8020E934 { u8 b[0x74]; };

struct Tbl_8020E934 { u8 pad[8]; u8 *pairs; u8 count; };

struct Tbl_8020E800 { u8 pad[0x10]; u8 *pairs; u8 count; };

struct Tbl_8020EACC { u8 *pairs; u8 count; };

struct Rec_8020E700 { u8 a, b, c, d, e, f; u8 pad[0x14 - 6]; };

extern RecoveredGlobal_8020ECD8_lbl_80513D78 lbl_80513D78;
extern "C" {
s32 memset(void *, int, int);
extern RecoveredGlobal_8020ECA8_lbl_80513D58 shop_armor_stock_generated_flags;
extern s32 lbl_80513D68[];
extern Tbl_8020E934 **lbl_805D6158;
extern s32 lbl_805D615C;
extern s32 shop_difficulty_tier;
void push_shop_pool_entry(Ctr_8020E934 *, u8);
void init__9TItemDataFv(Item_8020E934 *);
s32 is_duplicate_shop_shield_or_unit(Item_8020E934 *, s32);
s32 is_duplicate_shop_armor(Rec_8020E700 *arg0, s32 arg1);
void generate_shop_armor_pool(s32 arg0);
void generate_shop_unit_pool(s32 arg0);
typedef char RecoveredGlobal_8020ECD8_lbl_80513D78_size[sizeof(RecoveredGlobal_8020ECD8_lbl_80513D78) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_8020ECA8_lbl_80513D58_size[sizeof(RecoveredGlobal_8020ECA8_lbl_80513D58) == 0x10 ? 1 : -1];

s32 is_duplicate_shop_armor(Rec_8020E700 *arg0, s32 arg1) {
    s32 i;
    Rec_8020E700 *tbl = ((Rec_8020E700 **)&lbl_80513D78)[arg1];
    for (i = 0; i < lbl_80513D68[arg1]; i++) {
        if (arg0->a == tbl[i].a && arg0->b == tbl[i].b && arg0->c == tbl[i].c && arg0->f == tbl[i].f) {
            return 0;
        }
    }
    return 1;
}

s32 is_duplicate_shop_shield_or_unit(Item_8020E934 *arg0, s32 arg1) {
    s32 i;
    Item_8020E934 *tbl = ((Item_8020E934 **)&lbl_80513D78)[arg1];
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
    Ctr_8020E934 ctr;
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
    dst = ((Item_8020E934 **)&lbl_80513D78)[arg0];
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
        init__9TItemDataFv(&item);
        item.b[0] = 1;
        item.b[1] = 3;
        item.b[2] = b;
        if (is_duplicate_shop_shield_or_unit(&item, arg0) == 1) {
            ((ItemData *)(&dst[lbl_80513D68[arg0]++]))->copy_from((ItemData *)(&item));
            cnt++;
        }
    }
}

void generate_shop_shield_pool(s32 arg0) {
    Item_8020E934 item;
    Ctr_8020E934 ctr;
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
    dst = ((Item_8020E934 **)&lbl_80513D78)[arg0];
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
        init__9TItemDataFv(&item);
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
            ((ItemData *)(&dst[counts[arg0]++]))->copy_from((ItemData *)(&item));
            j++;
        }
    }
}

extern "C" {
void generate_shop_armor_pool(s32 arg0) {
    Item_8020E934 item;
    Ctr_8020E934 ctr;
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
    dst = ((Item_8020E934 **)&lbl_80513D78)[arg0];
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
        init__9TItemDataFv(&item);
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
            ((ItemData *)(&dst[counts[arg0]++]))->copy_from((ItemData *)(&item));
            j++;
        }
    }
}
}

void TLobby::clear_shop_entry_value(s32 i, s32 j) {
    Ent_8020EC68 *e = ((Ent_8020EC68 * *)&lbl_80513D78)[j];
    if (i >= 0 && i <= 0x14) {
        if (e[i].v != -1) e[i].v = -1;
    }
}

void clear_shop_armor_flags(void) {
    memset(&shop_armor_stock_generated_flags.value, 0, 0x10);
}

void TLobby::copy_armor_shop_entry(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    *(ByteBlock_14 *)(arg0) = *(const ByteBlock_14 *)(*(s32 *)((s8 *)&lbl_80513D78.value + (arg2 * 4)) + (arg1 * 0x14));
}
