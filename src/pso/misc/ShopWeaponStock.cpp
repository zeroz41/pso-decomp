#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/ShopWeaponStock.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/unk/text_8020EEFC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"

struct SRock_80224544_8022448C;

struct RecoveredGlobal_8022559C_lbl_80513F50 {
    s32 value;
    u8 remaining[0xC];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct C14_80225550 { u8 bytes[0x14]; };

struct G_80225550 { s32 value; u8 remaining[0xC]; };

struct E_802255CC { u8 pad[0x10]; s32 f10; };

struct C14_80224B7C { u8 b[0x14]; };

struct Cnt_80224B7C { s32 n; };

struct Lst_80224B7C { C14_80224B7C *p; };

struct Ent_80224F7C { s32 id; s32 n; };

struct Hdr_80224F7C { u8 pad[0x14]; Ent_80224F7C *ents; };

struct Obj_80224F7C { u8 pad[4]; s8 v; };

struct Range_80225064 { s32 min; s32 max; };

struct Tbl_80225064 { u8 pad[0x18]; Range_80225064 *lo; Range_80225064 *hi; };

struct Item_80225064 { u8 f0; u8 f1; u8 f2; u8 f3; };

struct Ent_80224C68 { s32 id; s32 n; };

struct Rng_80224C68 { s32 lo; s32 hi; };

struct Hdr_80224C68 { u8 pad[8]; Ent_80224C68 *ents; u8 pad2[4]; Rng_80224C68 *rng; };

struct Obj_80224C68 { u8 pad[6]; u8 b6; u8 b7; u8 b8; u8 b9; };

struct Ent_80224DF0 { s32 id; s32 n; };

struct Rng_80224DF0 { s32 lo; s32 hi; };

struct Hdr_80224DF0 { u8 pad[4]; Ent_80224DF0 *ents; u8 pad2[4]; Rng_80224DF0 *rng; };

struct Obj_80224DF0 { u8 pad[6]; u8 b6; u8 b7; };

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
s32 memset(void *, int, int);
extern RecoveredGlobal_8022559C_lbl_80513F50 shop_weapon_stock_generated_flags;
extern G_80225550 shop_weapon_stock_buffers;
void get_shop_weapon_stock_item(C14_80225550 *dst, s32 idx, s32 tbl);
s32 is_split_screen(void);
s32 mem_alloc(s32);
void mem_free(void *p);
extern u32 lobby_weapon_random_tables_ptr;
s32 memcmp(const void *, const void *, u32);
extern Cnt_80224B7C shop_weapon_stock_counts[];
s32 is_duplicate_shop_weapon(C14_80224B7C *item, s32 tbl);
void push_shop_pool_entry(void *, u8);
extern int shop_weapon_stock_level;
void roll_shop_weapon_special(Obj_80224F7C *obj);
extern char lbl_8044C7C0[];
extern char lbl_8044C7D8[];
extern char lbl_8044C7F0[];
extern char lbl_8044C80C[];
extern s32 shop_difficulty_tier;
u8 get_entry_field16__9TItemDataFv(void *);
s32 rand();
extern s32 section_id_favored_grind_table[];
extern s32 lbl_805D6238;
void roll_shop_weapon_grind(Item_80225064 *it);
extern s32 shop_weapon_bonus_table[];
void roll_shop_weapon_second_bonus(Obj_80224C68 *obj);
void roll_shop_weapon_first_bonus(Obj_80224DF0 *obj);
void sort_shop_items(s32, s32, s32);
void init__9TItemDataFv(void *);
extern Pair_8022525C shop_weapon_group_subtype_table[];
extern Pair_8022525C shop_section_id_weapon_table_a[];
extern Pair_8022525C shop_section_id_weapon_table_b[];

u32 lobby_weapon_random_tables_ptr;
int shop_weapon_stock_level;

s32 TLobby::classify_level_bracket_wide(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 5)) {
        return 0;
    }
    if ((arg0 >= 6) && (arg0 <= 0xA)) {
        return 1;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x11)) {
        return 2;
    }
    if ((arg0 >= 0x12) && (arg0 <= 0x19)) {
        return 3;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x23)) {
        return 4;
    }
    if ((arg0 >= 0x24) && (arg0 <= 0x2D)) {
        return 5;
    }
    if ((arg0 >= 0x2E) && (arg0 <= 0x3C)) {
        return 6;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x4B)) {
        return 7;
    }
    if ((arg0 >= 0x4C) && (arg0 <= 0x64)) {
        return 8;
    }
    if (arg0 >= 0x65) {
        return 8;
    }
    return -1;
}

s32 TLobby::get_level_bracket(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 3)) {
        return 0;
    }
    if ((arg0 >= 4) && (arg0 <= 0xA)) {
        return 1;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x11)) {
        return 2;
    }
    if ((arg0 >= 0x12) && (arg0 <= 0x19)) {
        return 3;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x23)) {
        return 4;
    }
    if ((arg0 >= 0x24) && (arg0 <= 0x2D)) {
        return 5;
    }
    if ((arg0 >= 0x2E) && (arg0 <= 0x3C)) {
        return 6;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x4B)) {
        return 7;
    }
    if ((arg0 >= 0x4C) && (arg0 <= 0x64)) {
        return 8;
    }
    if (arg0 >= 0x65) {
        return 8;
    }
    return -1;
}

s32 TLobby__sub_80224840(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x11)) {
        return 1;
    }
    if ((arg0 >= 0x12) && (arg0 <= 0x19)) {
        return 2;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x23)) {
        return 3;
    }
    if ((arg0 >= 0x24) && (arg0 <= 0x2D)) {
        return 4;
    }
    if ((arg0 >= 0x2E) && (arg0 <= 0x3C)) {
        return 5;
    }
    if ((arg0 >= 0x3D) && (arg0 <= 0x4B)) {
        return 6;
    }
    if ((arg0 >= 0x4C) && (arg0 <= 0x64)) {
        return 7;
    }
    if (arg0 >= 0x65) {
        return 7;
    }
    return -1;
}

s32 TLobby::classify_level_bracket_narrow(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 3)) {
        return 0;
    }
    if ((arg0 >= 4) && (arg0 <= 0xA)) {
        return 1;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 2;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x28)) {
        return 3;
    }
    if ((arg0 >= 0x29) && (arg0 <= 0x37)) {
        return 4;
    }
    if ((arg0 >= 0x38) && (arg0 <= 0x64)) {
        return 5;
    }
    if (arg0 >= 0x65) {
        return 5;
    }
    return -1;
}

s32 TLobby::get_level_tier(s32 arg0) {
    if ((s32) shop_difficulty_tier != 3) {
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
    if ((arg0 >= 0x64) && (arg0 <= 0x96)) {
        return 5;
    }
    if (arg0 >= 0x97) {
        return 6;
    }
    return -1;
}

s32 TLobby::level_to_reward(s32 arg0) {
    if ((arg0 >= 1) && (arg0 <= 0xA)) {
        return 0xA;
    }
    if ((arg0 >= 0xB) && (arg0 <= 0x19)) {
        return 0xC;
    }
    if ((arg0 >= 0x1A) && (arg0 <= 0x2A)) {
        return 0xC;
    }
    if ((arg0 >= 0x2B) && (arg0 <= 0x64)) {
        return 0x10;
    }
    if (arg0 >= 0x65) {
        return 0x10;
    }
    return 0;
}

#pragma push
#pragma optimization_level 1
struct G_80225550;
s32 is_duplicate_shop_weapon(C14_80224B7C *item, s32 tbl) {
    s32 n;
    C14_80224B7C *p;
    s32 i;
    if (shop_weapon_stock_counts[tbl].n == 0) {
        return 1;
    }
    n = 0;
    p = ((Lst_80224B7C *)&shop_weapon_stock_buffers)[tbl].p;
    for (i = 0; i < shop_weapon_stock_counts[tbl].n; i++, p++) {
        if (memcmp(item, p, 0x14) == 0) {
            return 0;
        }
        if (p->b[0] == item->b[0] && p->b[1] == item->b[1]) {
            n++;
        }
    }
    return (n <= 1) ? 1 : 0;
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_second_bonus(Obj_80224C68 *obj) {
    u8 buf[0x68];
    Ent_80224C68 *e;
    Rng_80224C68 *r;
    s32 idx;
    s32 i;
    s32 n;
    s32 v;
    s32 x;
    s32 hi;
    s32 lo;
    ((TLobby *)buf)->reset_counter_64();
    e = ((Hdr_80224C68 *)lobby_weapon_random_tables_ptr)->ents;
    r = ((Hdr_80224C68 *)lobby_weapon_random_tables_ptr)->rng;
    idx = TLobby::classify_level_bracket_wide(shop_weapon_stock_level);
    lo = r[idx].lo;
    hi = r[idx].hi;
    i = 0;
    idx *= 6;
    while (i++ < 6) {
        n = e[idx].n;
        while (n != 0) {
            push_shop_pool_entry(buf, e[idx].id);
            n--;
        }
        idx++;
    }
    shuffle_shop_pool_n_times(buf, 3);
    do {
        v = ((TLobby *)buf)->pop_byte();
        if (v < 0) {
            v = 0;
            break;
        }
    } while (v == obj->b6);
    obj->b8 = v;
    obj->b9 = 0;
    switch (v) {
    case 0:
        obj->b9 = 0;
        break;
    default:
        x = (s32)((hi + 1) * ((1.0f / 32768.0f) * (f32)rand()));
        if (x < lo) {
            x = lo;
        }
        obj->b9 = shop_weapon_bonus_table[x];
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_first_bonus(Obj_80224DF0 *obj) {
    u8 buf[0x68];
    Ent_80224DF0 *e;
    Rng_80224DF0 *r;
    s32 idx;
    s32 i;
    s32 n;
    s32 v;
    s32 x;
    s32 lo;
    s32 hi;
    ((TLobby *)buf)->reset_counter_64();
    e = ((Hdr_80224DF0 *)lobby_weapon_random_tables_ptr)->ents;
    r = ((Hdr_80224DF0 *)lobby_weapon_random_tables_ptr)->rng;
    idx = TLobby::get_level_bracket(shop_weapon_stock_level);
    lo = r[idx].lo;
    hi = r[idx].hi;
    i = 0;
    idx *= 6;
    while (i++ < 6) {
        n = e[idx].n;
        while (n != 0) {
            push_shop_pool_entry(buf, e[idx].id);
            n--;
        }
        idx++;
    }
    shuffle_shop_pool_n_times(buf, 3);
    v = ((TLobby *)buf)->pop_byte();
    if (v != -1) {
        obj->b6 = v;
        obj->b7 = 0;
    } else {
        obj->b6 = 0;
        obj->b7 = 0;
        v = 0;
    }
    switch (v) {
    case 0:
        obj->b7 = 0;
        break;
    default:
        x = (s32)((hi + 1) * ((1.0f / 32768.0f) * (f32)rand()));
        if (x < lo) {
            x = lo;
        }
        obj->b7 = shop_weapon_bonus_table[x];
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_special(Obj_80224F7C *obj) {
    u8 buf[0x68];
    Ent_80224F7C *e;
    s32 idx;
    s32 i;
    s32 n;
    ((TLobby *)buf)->reset_counter_64();
    e = ((Hdr_80224F7C *)lobby_weapon_random_tables_ptr)->ents;
    idx = TLobby__sub_80224840(shop_weapon_stock_level);
    i = 0;
    idx *= 3;
    while (i++ < 3) {
        n = e[idx].n;
        while (n != 0) {
            push_shop_pool_entry(buf, e[idx].id);
            n--;
        }
        idx++;
    }
    shuffle_shop_pool_n_times(buf, 3);
    switch (((TLobby *)buf)->pop_byte()) {
    case 1:
        obj->v = roll_weapon_special_channel15(0);
        break;
    case 2:
        obj->v = roll_weapon_special_channel15((void *)(1));
        break;
    case 0:
    default:
        obj->v = 0;
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_grind(Item_80225064 *it) {
    Range_80225064 *lo;
    Range_80225064 *hi;
    s32 b;
    u8 v;
    u8 m;
    lo = ((Tbl_80225064 *)lobby_weapon_random_tables_ptr)->lo;
    hi = ((Tbl_80225064 *)lobby_weapon_random_tables_ptr)->hi;
    b = TLobby::classify_level_bracket_narrow(shop_weapon_stock_level);
    if (b != -1) {
        if (section_id_favored_grind_table[lbl_805D6238] != -1 && it->f1 == section_id_favored_grind_table[lbl_805D6238]) {
            v = (hi[b].max + 1) * ((1.0f / 32768.0f) * (f32)rand());
            if (v < hi[b].min) {
                v = hi[b].min;
            }
        } else {
            v = (lo[b].max + 1) * ((1.0f / 32768.0f) * (f32)rand());
            if (v < lo[b].min) {
                v = lo[b].min;
            }
        }
        it->f3 = v;
    }
    m = get_entry_field16__9TItemDataFv(it);
    if (it->f3 > m) {
        it->f3 = m;
    }
}
#pragma pop

void TLobby__sub_80225238(int a0, int a1) { shop_weapon_stock_level = a1; generate_shop_weapon_stock(a0); }
}
s32 create_named_object(s32 arg0);
typedef char RecoveredGlobal_8022559C_lbl_80513F50_size[sizeof(RecoveredGlobal_8022559C_lbl_80513F50) == 0x10 ? 1 : -1];

#pragma push
#pragma optimization_level 1
#pragma dont_inline on
typedef struct Ent_8022525C Ent_8022525C;
typedef struct Hdr_8022525C Hdr_8022525C;
typedef struct Item_8022525C Item_8022525C;
typedef struct Pair_8022525C Pair_8022525C;
typedef struct Pool_8022525C Pool_8022525C;
typedef struct Tier_8022525C Tier_8022525C;
s32 shop_weapon_stock_target_counts[4];
Cnt_80224B7C shop_weapon_stock_counts[4];
RecoveredGlobal_8022559C_lbl_80513F50 shop_weapon_stock_generated_flags;
G_80225550 shop_weapon_stock_buffers;
void generate_shop_weapon_stock(s32 tbl) {
  long long new_var;
  Item_8022525C item;
  Pool_8022525C pool;
  u8 *buf;
  s32 n;
  Ent_8022525C *e;
  s32 i;
  u8 c;
  s32 id;
  Tier_8022525C *t;
  Ent_8022525C *ents;
  if ((lobby_weapon_random_tables_ptr != 0) && (((s32 *)&shop_weapon_stock_generated_flags)[tbl] == 0))
  {
    ((s32 *)&shop_weapon_stock_generated_flags)[tbl] = 1;
    shop_weapon_stock_target_counts[tbl] = 0;
    ((s32 *)shop_weapon_stock_counts)[tbl] = 0;
    buf = ((u8 **)&shop_weapon_stock_buffers)[tbl];
    shop_weapon_stock_target_counts[tbl] = TLobby::level_to_reward(shop_weapon_stock_level);
    ((TLobby *)(&pool))->reset_counter_64();
    id = TLobby::get_level_tier(shop_weapon_stock_level);
    t = &((Hdr_8022525C *) lobby_weapon_random_tables_ptr)->tiers[id];
    i = 0;
    n = t->n;
    ents = t->ents;
    new_var = n * lbl_805D6238;
    e = ents + new_var;
    while ((i++) < n)
    {
      for (c = e->count; c != 0; c--)
      {
        push_shop_pool_entry(&pool, e->id);
      }
      e++;
    }
    shuffle_shop_pool_n_times(&pool, 4);
    while (((s32 *)shop_weapon_stock_counts)[tbl] < shop_weapon_stock_target_counts[tbl])
    {
      id = ((TLobby *)(&pool))->pop_byte();
      if (id == (-1))
      {
        continue;
      }
      init__9TItemDataFv(&item);
      if (id == 0x39)
      {
        if (shop_section_id_weapon_table_a[lbl_805D6238].a != (-1))
        {
          item.b0 = 0;
          item.b1 = shop_section_id_weapon_table_a[lbl_805D6238].a;
          item.b2 = shop_section_id_weapon_table_a[lbl_805D6238].b;
        }
      }
      else
        if (id == 0x3A)
      {
        if (shop_section_id_weapon_table_b[lbl_805D6238].a != (-1))
        {
          item.b0 = 0;
          item.b1 = shop_section_id_weapon_table_b[lbl_805D6238].a;
          item.b2 = shop_section_id_weapon_table_b[lbl_805D6238].b;
        }
      }
      else
      {
        item.b0 = 0;
        item.b1 = shop_weapon_group_subtype_table[id].a;
        item.b2 = shop_weapon_group_subtype_table[id].b;
      }
      roll_shop_weapon_grind((Item_80225064 *)(&item));
      roll_shop_weapon_special((Obj_80224F7C *)(&item));
      roll_shop_weapon_first_bonus((Obj_80224DF0 *)(&item));
      roll_shop_weapon_second_bonus((Obj_80224C68 *)(&item));
      item.b12 = 0;
      item.b13 = 0;
      if (is_duplicate_shop_weapon((C14_80224B7C *)(&item), tbl) == 1)
      {
        ((TItemData *)(buf + ((((s32 *)shop_weapon_stock_counts)[tbl]++) * 0x14)))->copy_from((TItemData *)(&item));
      }
    }
    sort_shop_items((s32)buf, (s32)(((s32 *)shop_weapon_stock_counts)[tbl]), 2);
  }
}
#pragma pop

#pragma push
#pragma optimization_level 1

void get_shop_weapon_stock_item(C14_80225550 *dst, s32 idx, s32 tbl) {
    C14_80225550 *arr = ((C14_80225550 **)&shop_weapon_stock_buffers)[tbl];
    *dst = arr[idx];
}
#pragma pop

void clear_shop_weapon_flags(void) {
    memset(&shop_weapon_stock_generated_flags.value, 0, 0x10);
}

#pragma push
#pragma optimization_level 1

void TLobby::clear_slot_field_f10(s32 a, s32 b) {
    E_802255CC *arr = ((E_802255CC **)&shop_weapon_stock_buffers)[b];
    if (a >= 0 && a <= 0xf) {
        if (arr[a].f10 != -1) {
            arr[a].f10 = -1;
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void TLobby::free_lobby_resources() {
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (((u32 *)&shop_weapon_stock_buffers)[i] != 0) {
            mem_free((void *)(((u32 *)&shop_weapon_stock_buffers)[i]));
            ((u32 *)&shop_weapon_stock_buffers)[i] = 0;
        }
    }
    if (lobby_weapon_random_tables_ptr != 0) {
        TLobby::free_nodes_with_id((u32)((void *)lobby_weapon_random_tables_ptr));
        lobby_weapon_random_tables_ptr = 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void load_weapon_random_tables(void) {
    s32 i;
    s32 j;
    switch (shop_difficulty_tier) {
    case 0:
        lobby_weapon_random_tables_ptr = create_named_object((s32)lbl_8044C7C0);
        break;
    case 1:
        lobby_weapon_random_tables_ptr = create_named_object((s32)lbl_8044C7D8);
        break;
    case 2:
        lobby_weapon_random_tables_ptr = create_named_object((s32)lbl_8044C7F0);
        break;
    case 3:
        lobby_weapon_random_tables_ptr = create_named_object((s32)lbl_8044C80C);
        break;
    default:
        lobby_weapon_random_tables_ptr = create_named_object((s32)lbl_8044C7C0);
        break;
    }
    for (j = 0; j < 4; j++) {
        ((s32 *)&shop_weapon_stock_buffers)[j] = 0;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            ((s32 *)&shop_weapon_stock_buffers)[i] = mem_alloc(0x140);
        }
    } else {
        ((s32 *)&shop_weapon_stock_buffers)[0] = mem_alloc(0x140);
    }
    shop_weapon_stock_level = 0;
}
#pragma pop
