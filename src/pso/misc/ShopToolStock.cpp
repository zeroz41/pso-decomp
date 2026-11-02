#include "types.h"
#include "pso/misc/ShopToolStock.h"
#include "pso/unk/text_80223B98.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TWindowSubComCard.h"

struct SRock_80224544_8022448C;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

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
s32 is_split_screen(void);
s32 mem_alloc(s32);
extern s32 shop_tool_stock_buffers[];
extern u32 lobby_tool_random_rel;
extern int shop_tool_stock_level;
void mem_free(void *p);
void sort_shop_items(s32, s32, s32);
u32 lobby_tool_random_rel;
int shop_tool_stock_level;

void TLobby::set_6264_and_call_2244B0(int a0, int a1) { shop_tool_stock_level = a1; TLobby::generate_shop_inventory(a0); }

s32 shop_tool_stock_counts[4];
s32 shop_tool_stock_table[4];
s32 shop_tool_flags[4];
s32 shop_tool_stock_buffers[4];
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
