#include "types.h"
#include <string.h>
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/item/shop/ShopItemSort.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include <stdlib.h>
#include "pso/item/TItemData.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopItemListWindow.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


ShopWeaponRandomTables *lobby_weapon_random_tables_ptr;
int shop_weapon_stock_level;

s32 classify_level_bracket_wide(s32 shop_weapon_stock_level) {
    if ((shop_weapon_stock_level >= 1) && (shop_weapon_stock_level <= 5)) {
        return 0;
    }
    if ((shop_weapon_stock_level >= 6) && (shop_weapon_stock_level <= 0xA)) {
        return 1;
    }
    if ((shop_weapon_stock_level >= 0xB) && (shop_weapon_stock_level <= 0x11)) {
        return 2;
    }
    if ((shop_weapon_stock_level >= 0x12) && (shop_weapon_stock_level <= 0x19)) {
        return 3;
    }
    if ((shop_weapon_stock_level >= 0x1A) && (shop_weapon_stock_level <= 0x23)) {
        return 4;
    }
    if ((shop_weapon_stock_level >= 0x24) && (shop_weapon_stock_level <= 0x2D)) {
        return 5;
    }
    if ((shop_weapon_stock_level >= 0x2E) && (shop_weapon_stock_level <= 0x3C)) {
        return 6;
    }
    if ((shop_weapon_stock_level >= 0x3D) && (shop_weapon_stock_level <= 0x4B)) {
        return 7;
    }
    if ((shop_weapon_stock_level >= 0x4C) && (shop_weapon_stock_level <= 0x64)) {
        return 8;
    }
    if (shop_weapon_stock_level >= 0x65) {
        return 8;
    }
    return -1;
}

s32 get_level_bracket(s32 shop_weapon_stock_level) {
    if ((shop_weapon_stock_level >= 1) && (shop_weapon_stock_level <= 3)) {
        return 0;
    }
    if ((shop_weapon_stock_level >= 4) && (shop_weapon_stock_level <= 0xA)) {
        return 1;
    }
    if ((shop_weapon_stock_level >= 0xB) && (shop_weapon_stock_level <= 0x11)) {
        return 2;
    }
    if ((shop_weapon_stock_level >= 0x12) && (shop_weapon_stock_level <= 0x19)) {
        return 3;
    }
    if ((shop_weapon_stock_level >= 0x1A) && (shop_weapon_stock_level <= 0x23)) {
        return 4;
    }
    if ((shop_weapon_stock_level >= 0x24) && (shop_weapon_stock_level <= 0x2D)) {
        return 5;
    }
    if ((shop_weapon_stock_level >= 0x2E) && (shop_weapon_stock_level <= 0x3C)) {
        return 6;
    }
    if ((shop_weapon_stock_level >= 0x3D) && (shop_weapon_stock_level <= 0x4B)) {
        return 7;
    }
    if ((shop_weapon_stock_level >= 0x4C) && (shop_weapon_stock_level <= 0x64)) {
        return 8;
    }
    if (shop_weapon_stock_level >= 0x65) {
        return 8;
    }
    return -1;
}

s32 get_special_level_bracket(s32 shop_weapon_stock_level) {
    if ((shop_weapon_stock_level >= 1) && (shop_weapon_stock_level <= 0xA)) {
        return 0;
    }
    if ((shop_weapon_stock_level >= 0xB) && (shop_weapon_stock_level <= 0x11)) {
        return 1;
    }
    if ((shop_weapon_stock_level >= 0x12) && (shop_weapon_stock_level <= 0x19)) {
        return 2;
    }
    if ((shop_weapon_stock_level >= 0x1A) && (shop_weapon_stock_level <= 0x23)) {
        return 3;
    }
    if ((shop_weapon_stock_level >= 0x24) && (shop_weapon_stock_level <= 0x2D)) {
        return 4;
    }
    if ((shop_weapon_stock_level >= 0x2E) && (shop_weapon_stock_level <= 0x3C)) {
        return 5;
    }
    if ((shop_weapon_stock_level >= 0x3D) && (shop_weapon_stock_level <= 0x4B)) {
        return 6;
    }
    if ((shop_weapon_stock_level >= 0x4C) && (shop_weapon_stock_level <= 0x64)) {
        return 7;
    }
    if (shop_weapon_stock_level >= 0x65) {
        return 7;
    }
    return -1;
}

s32 classify_level_bracket_narrow(s32 shop_weapon_stock_level) {
    if ((shop_weapon_stock_level >= 1) && (shop_weapon_stock_level <= 3)) {
        return 0;
    }
    if ((shop_weapon_stock_level >= 4) && (shop_weapon_stock_level <= 0xA)) {
        return 1;
    }
    if ((shop_weapon_stock_level >= 0xB) && (shop_weapon_stock_level <= 0x19)) {
        return 2;
    }
    if ((shop_weapon_stock_level >= 0x1A) && (shop_weapon_stock_level <= 0x28)) {
        return 3;
    }
    if ((shop_weapon_stock_level >= 0x29) && (shop_weapon_stock_level <= 0x37)) {
        return 4;
    }
    if ((shop_weapon_stock_level >= 0x38) && (shop_weapon_stock_level <= 0x64)) {
        return 5;
    }
    if (shop_weapon_stock_level >= 0x65) {
        return 5;
    }
    return -1;
}

s32 get_level_tier(s32 level) {
    if ((s32) shop_difficulty_tier != 3) {
        if ((level >= 1) && (level <= 0xA)) {
            return 0;
        }
        if ((level >= 0xB) && (level <= 0x19)) {
            return 1;
        }
        if ((level >= 0x1A) && (level <= 0x2A)) {
            return 2;
        }
        if ((level >= 0x2B) && (level <= 0x3C)) {
            return 3;
        }
        if ((level >= 0x3D) && (level <= 0x64)) {
            return 4;
        }
        if (level >= 0x65) {
            return 4;
        }
        return -1;
    }
    if ((level >= 1) && (level <= 0xA)) {
        return 0;
    }
    if ((level >= 0xB) && (level <= 0x19)) {
        return 1;
    }
    if ((level >= 0x1A) && (level <= 0x2A)) {
        return 2;
    }
    if ((level >= 0x2B) && (level <= 0x3C)) {
        return 3;
    }
    if ((level >= 0x3D) && (level <= 0x63)) {
        return 4;
    }
    if ((level >= 0x64) && (level <= 0x96)) {
        return 5;
    }
    if (level >= 0x97) {
        return 6;
    }
    return -1;
}

s32 level_to_reward(s32 shop_weapon_stock_level) {
    if ((shop_weapon_stock_level >= 1) && (shop_weapon_stock_level <= 0xA)) {
        return 0xA;
    }
    if ((shop_weapon_stock_level >= 0xB) && (shop_weapon_stock_level <= 0x19)) {
        return 0xC;
    }
    if ((shop_weapon_stock_level >= 0x1A) && (shop_weapon_stock_level <= 0x2A)) {
        return 0xC;
    }
    if ((shop_weapon_stock_level >= 0x2B) && (shop_weapon_stock_level <= 0x64)) {
        return 0x10;
    }
    if (shop_weapon_stock_level >= 0x65) {
        return 0x10;
    }
    return 0;
}

#pragma push
#pragma optimization_level 1
s32 is_duplicate_shop_weapon(TItemData *item, s32 tbl) {
    s32 n;
    TItemData *p;
    s32 i;
    if (shop_weapon_stock_counts[tbl] == 0) {
        return 1;
    }
    n = 0;
    p = shop_weapon_stock_buffers[tbl];
    for (i = 0; i < shop_weapon_stock_counts[tbl]; i++, p++) {
        if (memcmp(item, p, 0x14) == 0) {
            return 0;
        }
        if (p->data1.data_u8[0] == item->data1.data_u8[0] && p->data1.data_u8[1] == item->data1.data_u8[1]) {
            n++;
        }
    }
    return (n <= 1) ? 1 : 0;
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_second_bonus(TItemData *item) {
    ShopPool pool;
    ShopPoolEntry *e;
    ShopRollRange *r;
    s32 idx;
    s32 i;
    s32 n;
    s32 v;
    s32 x;
    s32 hi;
    s32 lo;
    pool.clear();
    e = lobby_weapon_random_tables_ptr->second_bonus_ents;
    r = lobby_weapon_random_tables_ptr->second_bonus_ranges;
    idx = classify_level_bracket_wide(shop_weapon_stock_level);
    lo = r[idx].min;
    hi = r[idx].max;
    i = 0;
    idx *= 6;
    while (i++ < 6) {
        n = e[idx].weight;
        while (n != 0) {
            pool.push(e[idx].id);
            n--;
        }
        idx++;
    }
    pool.shuffle_n_times(3);
    do {
        v = pool.pop();
        if (v < 0) {
            v = 0;
            break;
        }
    } while (v == item->data1.data_u8[6]);
    item->data1.data_u8[8] = v;
    item->data1.data_u8[9] = 0;
    switch (v) {
    case 0:
        item->data1.data_u8[9] = 0;
        break;
    default:
        x = (s32)((hi + 1) * ((1.0f / 32768.0f) * (f32)rand()));
        if (x < lo) {
            x = lo;
        }
        item->data1.data_u8[9] = shop_weapon_bonus_table[x];
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_first_bonus(TItemData *item) {
    ShopPool pool;
    ShopPoolEntry *e;
    ShopRollRange *r;
    s32 idx;
    s32 i;
    s32 n;
    s32 v;
    s32 x;
    s32 lo;
    s32 hi;
    pool.clear();
    e = lobby_weapon_random_tables_ptr->first_bonus_ents;
    r = lobby_weapon_random_tables_ptr->first_bonus_ranges;
    idx = get_level_bracket(shop_weapon_stock_level);
    lo = r[idx].min;
    hi = r[idx].max;
    i = 0;
    idx *= 6;
    while (i++ < 6) {
        n = e[idx].weight;
        while (n != 0) {
            pool.push(e[idx].id);
            n--;
        }
        idx++;
    }
    pool.shuffle_n_times(3);
    v = pool.pop();
    if (v != -1) {
        item->data1.data_u8[6] = v;
        item->data1.data_u8[7] = 0;
    } else {
        item->data1.data_u8[6] = 0;
        item->data1.data_u8[7] = 0;
        v = 0;
    }
    switch (v) {
    case 0:
        item->data1.data_u8[7] = 0;
        break;
    default:
        x = (s32)((hi + 1) * ((1.0f / 32768.0f) * (f32)rand()));
        if (x < lo) {
            x = lo;
        }
        item->data1.data_u8[7] = shop_weapon_bonus_table[x];
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_special(TItemData *item) {
    ShopPool pool;
    ShopPoolEntry *e;
    s32 idx;
    s32 i;
    s32 n;
    pool.clear();
    e = lobby_weapon_random_tables_ptr->special_ents;
    idx = get_special_level_bracket(shop_weapon_stock_level);
    i = 0;
    idx *= 3;
    while (i++ < 3) {
        n = e[idx].weight;
        while (n != 0) {
            pool.push(e[idx].id);
            n--;
        }
        idx++;
    }
    pool.shuffle_n_times(3);
    switch (pool.pop()) {
    case 1:
        item->data1.data_s8[4] = roll_weapon_special_channel15(0);
        break;
    case 2:
        item->data1.data_s8[4] = roll_weapon_special_channel15(1);
        break;
    case 0:
    default:
        item->data1.data_s8[4] = 0;
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void roll_shop_weapon_grind(TItemData *item) {
    ShopRollRange *lo;
    ShopRollRange *hi;
    s32 b;
    u8 v;
    u8 m;
    lo = lobby_weapon_random_tables_ptr->grind_ranges;
    hi = lobby_weapon_random_tables_ptr->favored_grind_ranges;
    b = classify_level_bracket_narrow(shop_weapon_stock_level);
    if (b != -1) {
        if (section_id_favored_grind_table[shop_section_id] != -1 && item->data1.data_u8[1] == section_id_favored_grind_table[shop_section_id]) {
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
        item->data1.data_u8[3] = v;
    }
    m = item->get_max_grind();
    if (item->data1.data_u8[3] > m) {
        item->data1.data_u8[3] = m;
    }
}
#pragma pop

void generate_shop_weapon_stock_at_level(s32 shop, s32 level) {
    shop_weapon_stock_level = level;
    generate_shop_weapon_stock(shop);
}

#pragma push
#pragma optimization_level 1
#pragma dont_inline on
s32 shop_weapon_stock_target_counts[4];
s32 shop_weapon_stock_counts[4];
s32 shop_weapon_stock_generated_flags[4];
TItemData *shop_weapon_stock_buffers[4];  // each stock table's generated items, 16 of 0x14 bytes
void generate_shop_weapon_stock(s32 tbl) {
  long long new_var;
  TItemData item;
  ShopPool pool;
  TItemData *stock;
  s32 n;
  ShopStockEntry *e;
  s32 i;
  u8 c;
  s32 id;
  ShopStockTier *t;
  ShopStockEntry *ents;
  if ((lobby_weapon_random_tables_ptr != NULL) && (shop_weapon_stock_generated_flags[tbl] == 0))
  {
    shop_weapon_stock_generated_flags[tbl] = 1;
    shop_weapon_stock_target_counts[tbl] = 0;
    shop_weapon_stock_counts[tbl] = 0;
    stock = shop_weapon_stock_buffers[tbl];
    shop_weapon_stock_target_counts[tbl] = level_to_reward(shop_weapon_stock_level);
    pool.clear();
    id = get_level_tier(shop_weapon_stock_level);
    t = &lobby_weapon_random_tables_ptr->stock_tiers[id];
    i = 0;
    n = t->count;
    ents = t->ents;
    new_var = n * shop_section_id;
    e = ents + new_var;
    while ((i++) < n)
    {
      for (c = e->count; c != 0; c--)
      {
        pool.push(e->id);
      }
      e++;
    }
    pool.shuffle_n_times(4);
    while (shop_weapon_stock_counts[tbl] < shop_weapon_stock_target_counts[tbl])
    {
      id = pool.pop();
      if (id == (-1))
      {
        continue;
      }
      item.init();
      if (id == 0x39)
      {
        if (shop_section_id_weapon_table_a[shop_section_id].group != (-1))
        {
          item.data1.data_u8[0] = 0;
          item.data1.data_u8[1] = shop_section_id_weapon_table_a[shop_section_id].group;
          item.data1.data_u8[2] = shop_section_id_weapon_table_a[shop_section_id].subtype;
        }
      }
      else
        if (id == 0x3A)
      {
        if (shop_section_id_weapon_table_b[shop_section_id].group != (-1))
        {
          item.data1.data_u8[0] = 0;
          item.data1.data_u8[1] = shop_section_id_weapon_table_b[shop_section_id].group;
          item.data1.data_u8[2] = shop_section_id_weapon_table_b[shop_section_id].subtype;
        }
      }
      else
      {
        item.data1.data_u8[0] = 0;
        item.data1.data_u8[1] = shop_weapon_group_subtype_table[id].group;
        item.data1.data_u8[2] = shop_weapon_group_subtype_table[id].subtype;
      }
      roll_shop_weapon_grind(&item);
      roll_shop_weapon_special(&item);
      roll_shop_weapon_first_bonus(&item);
      roll_shop_weapon_second_bonus(&item);
      item.data1.data_u8[10] = 0;
      item.data1.data_u8[11] = 0;
      if (is_duplicate_shop_weapon(&item, tbl) == 1)
      {
        stock[shop_weapon_stock_counts[tbl]++].copy_from(&item);
      }
    }
    sort_shop_items(stock, shop_weapon_stock_counts[tbl], 2);
  }
}
#pragma pop

#pragma push
#pragma optimization_level 1

// A stocked item copied as plain bytes, word by word.
struct ItemDataBytes { u8 bytes[0x14]; };

void get_shop_weapon_stock_item(TItemData *dst, s32 idx, s32 tbl) {
    ItemDataBytes *arr = (ItemDataBytes *)shop_weapon_stock_buffers[tbl];
    *(ItemDataBytes *)dst = arr[idx];
}
#pragma pop

void clear_shop_weapon_flags(void) {
    memset(shop_weapon_stock_generated_flags, 0, 0x10);
}

#pragma push
#pragma optimization_level 1

void mark_shop_weapon_sold_out(s32 index, s32 slot) {
    TItemData *arr = shop_weapon_stock_buffers[slot];
    if (index >= 0 && index <= 0xf) {
        if (arr[index].data2.price != -1) {
            arr[index].data2.price = -1;
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void free_weapon_random_tables(void) {
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (shop_weapon_stock_buffers[i] != NULL) {
            mem_free(shop_weapon_stock_buffers[i]);
            shop_weapon_stock_buffers[i] = NULL;
        }
    }
    if (lobby_weapon_random_tables_ptr != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(lobby_weapon_random_tables_ptr));
        lobby_weapon_random_tables_ptr = NULL;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
#pragma pool_data off
void load_weapon_random_tables(void) {
    s32 i;
    s32 j;
    switch (shop_difficulty_tier) {
    case 0:
        lobby_weapon_random_tables_ptr = (ShopWeaponRandomTables *)create_named_object("WeaponRandomNormal.rel");
        break;
    case 1:
        lobby_weapon_random_tables_ptr = (ShopWeaponRandomTables *)create_named_object("WeaponRandomHard.rel");
        break;
    case 2:
        lobby_weapon_random_tables_ptr = (ShopWeaponRandomTables *)create_named_object("WeaponRandomVeryHard.rel");
        break;
    case 3:
        lobby_weapon_random_tables_ptr = (ShopWeaponRandomTables *)create_named_object("WeaponRandomUltimate.rel");
        break;
    default:
        lobby_weapon_random_tables_ptr = (ShopWeaponRandomTables *)create_named_object("WeaponRandomNormal.rel");
        break;
    }
    for (j = 0; j < 4; j++) {
        shop_weapon_stock_buffers[j] = NULL;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            shop_weapon_stock_buffers[i] = (TItemData *)mem_alloc(0x140);
        }
    } else {
        shop_weapon_stock_buffers[0] = (TItemData *)mem_alloc(0x140);
    }
    shop_weapon_stock_level = 0;
}
#pragma pop
