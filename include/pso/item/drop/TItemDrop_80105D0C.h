#ifndef PSO_ITEM_DROP_TITEMDROP_80105D0C_H
#define PSO_ITEM_DROP_TITEMDROP_80105D0C_H

#include "types.h"

struct SubtractiveRng;

void init_item_drop_globals(void);
extern "C" {
int TItemDrop__sub_80107B04(void);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *item);
void calc_drop_item__9TItemDropFlPvl(s32 rng, void *arg1, s32 arg2);
void calc_drop_rarity__9TItemDropFllPv(s32 rng, s32 arg1, void *item_);
u8 can_drop__9TItemDropFv(void);
u8 *create_drop__9TItemDropFi(saddr parent);
s32 drop_item__9TItemDropFlll(s32 arg0, s32 arg1, s32 arg2);
void format_drop_table_filename(void *out, s32 prefix);
void generate_drop_item__9TItemDropFlPUc(u8 *self, s32 idx, u8 *item);
void generate_tool_drop__9TItemDropFiiPv(saddr item_drop, s32 off, void *item_data);
s8 get_bool_from_1d6ddc__9TItemDropFv(void *p);
s32 get_drop_table_mode_flags(void);
void handle_type3__9TItemDropFPvPv(void *p, void *a1);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *item_data);
u8 is_enabled__9TItemDropFv(void);
u8 is_not_special__9TItemDropFPv(void);
s32 item_drop_rng_below(SubtractiveRng *rng, u32 count);
void roll_armor_bonuses__9TItemDropFv(saddr rng, void *item_);
u32 roll_channel_below__9TItemDropFlUl(u8 *arg0, s32 count, u32 arg2);
u16 roll_meseta_range__9TItemDropFllll(void *self, s32 arg1, s32 a, s32 b, s32 c);
void roll_weapon_special__9TItemDropFiPvi(saddr rng, u8 *item, s32 idx);
void select_box_item__9TItemDropFiiPv(saddr rng, s32 off, u8 *item);
s32 select_rare_box_item__9TItemDropFllPUc(s32 arg0, s32 arg1, u8 *arg2);
void select_weapon_drop__9TItemDropFv(saddr rng, s32 level, u8 *item);
u8 select_weighted_byte__9TItemDropFllll(s32 rng, s32 base, s32 off, s32 count, s32 stride);
u8 select_weighted_column_u16__9TItemDropFiiiii(saddr rng, saddr base, s32 off, s32 count, s32 stride);
void set_flag__9TItemDropFPvPv(void *arg0, void *item);
s32 try_generate_rare_item__9TItemDropFiPvPv(saddr rng, u8 *arg1, u8 *item);
}

// --- C functions defined in TItemDrop_80105D0C.cpp ---
void init_item_drop_globals(void);
extern "C" {
int TItemDrop__sub_80107B04(void);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *item);
void calc_drop_item__9TItemDropFlPvl(s32 rng, void *arg1, s32 arg2);
void calc_drop_rarity__9TItemDropFllPv(s32 rng, s32 arg1, void *item_);
u8 *create_drop__9TItemDropFi(saddr parent);
s32 drop_item__9TItemDropFlll(s32 arg0, s32 arg1, s32 arg2);
void format_drop_table_filename(void *out, s32 prefix);
void generate_drop_item__9TItemDropFlPUc(u8 *self, s32 idx, u8 *item);
void generate_tool_drop__9TItemDropFiiPv(saddr item_drop, s32 off, void *item_data);
s8 get_bool_from_1d6ddc__9TItemDropFv(void *p);
s32 get_drop_table_mode_flags(void);
void handle_type3__9TItemDropFPvPv(void *p, void *a1);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *item_data);
s32 item_drop_rng_below(SubtractiveRng *rng, u32 count);
void roll_armor_bonuses__9TItemDropFv(saddr rng, void *item_);
u32 roll_channel_below__9TItemDropFlUl(u8 *arg0, s32 count, u32 arg2);
u16 roll_meseta_range__9TItemDropFllll(void *self, s32 arg1, s32 a, s32 b, s32 c);
u8 roll_technique_level__9TItemDropFllll(s32 self, s32 table, s32 row, s32 col, s32 stride);
void roll_weapon_special__9TItemDropFiPvi(saddr rng, u8 *item, s32 idx);
void select_box_item__9TItemDropFiiPv(saddr rng, s32 off, u8 *item);
s32 select_rare_box_item__9TItemDropFllPUc(s32 arg0, s32 arg1, u8 *arg2);
void select_weapon_drop__9TItemDropFv(saddr rng, s32 level, u8 *item);
u8 select_weighted_byte__9TItemDropFllll(s32 rng, s32 base, s32 off, s32 count, s32 stride);
u8 select_weighted_column_u16__9TItemDropFiiiii(saddr rng, saddr base, s32 off, s32 count, s32 stride);
void set_flag__9TItemDropFPvPv(void *arg0, void *item);
s32 try_generate_rare_item__9TItemDropFiPvPv(saddr rng, u8 *arg1, u8 *item);
}
// --- end of C functions

void unload_item_drop_globals();

#endif
