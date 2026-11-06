#ifndef PSO_ITEM_DROP_TITEMDROP_80105D0C_H
#define PSO_ITEM_DROP_TITEMDROP_80105D0C_H

#include "types.h"

extern "C" {
void TItemDrop__sub_80105D10(void);
u8 *TItemDrop__sub_80107840(u8 *arg0, s16 arg1);
int TItemDrop__sub_80107B04(void);
void TItemDrop__vt0(void);
void TItemDrop__vt1(void);
void __dt__9TItemDropFv(void);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *item);
void calc_drop_item__9TItemDropFiPvi(s32 rng, void *arg1, s32 arg2);
void calc_drop_rarity__9TItemDropFiiPv(s32 rng, s32 arg1, void *item_);
u8 can_drop__9TItemDropFv(void);
u8 *create_drop__9TItemDropFi(s32 parent);
s32 drop_item__9TItemDropFiii(s32 arg0, s32 arg1, s32 arg2);
void format_drop_table_filename(void *out, s32 arg1);
void generate_drop_item__9TItemDropFPviPv(u8 *self, s32 idx, u8 *item);
void generate_tool_drop__9TItemDropFiiPv(s32 arg0, s32 off, void *arg2);
s8 get_bool_from_1d6ddc__9TItemDropFPv(void *p);
s32 get_drop_table_mode_flags(void);
void handle_type3__9TItemDropFPvPv(void *p, void *a1);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *item_data);
u8 is_enabled__9TItemDropFv(void);
u8 is_not_special__9TItemDropFv(void);
s32 item_drop_rng_below(s32 arg0, u32 arg1);
void roll_armor_bonuses__9TItemDropFv(s32 rng, void *item_);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 count, u32 arg2);
u16 roll_meseta_range__9TItemDropFPviiii(void *self, s32 arg1, s32 a, s32 b, s32 c);
void roll_table_ratio__9TItemDropFPvUi(u8 *arg0, u32 arg1);
void roll_weapon_special__9TItemDropFiPvi(s32 rng, u8 *item, s32 idx);
void run_task__9TItemDropFv(void);
void select_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *item);
s32 select_rare_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *arg2);
void select_weapon_drop__9TItemDropFv(s32 rng, s32 level, u8 *item);
u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
u8 select_weighted_column_u16__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
void set_flag__9TItemDropFPvPv(void *arg0, void *item);
s32 try_generate_rare_item__9TItemDropFiPvPv(s32 arg0, u8 *arg1, u8 *arg2);
}

// --- C functions defined in TItemDrop_80105D0C.cpp ---
extern "C" {
void TItemDrop__sub_80105D10(void);
u8 *TItemDrop__sub_80107840(u8 *arg0, s16 arg1);
int TItemDrop__sub_80107B04(void);
void TItemDrop__vt0(void);
void TItemDrop__vt1(void);
void __dt__9TItemDropFv(void);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *item);
void calc_drop_item__9TItemDropFiPvi(s32 rng, void *arg1, s32 arg2);
void calc_drop_rarity__9TItemDropFiiPv(s32 rng, s32 arg1, void *item_);
u8 *create_drop__9TItemDropFi(s32 parent);
s32 drop_item__9TItemDropFiii(s32 arg0, s32 arg1, s32 arg2);
void format_drop_table_filename(void *out, s32 arg1);
void generate_drop_item__9TItemDropFPviPv(u8 *self, s32 idx, u8 *item);
void generate_tool_drop__9TItemDropFiiPv(s32 arg0, s32 off, void *arg2);
s8 get_bool_from_1d6ddc__9TItemDropFPv(void *p);
s32 get_drop_table_mode_flags(void);
void handle_type3__9TItemDropFPvPv(void *p, void *a1);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *item_data);
s32 item_drop_rng_below(s32 arg0, u32 arg1);
void roll_armor_bonuses__9TItemDropFv(s32 rng, void *item_);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 count, u32 arg2);
u16 roll_meseta_range__9TItemDropFPviiii(void *self, s32 arg1, s32 a, s32 b, s32 c);
void roll_table_ratio__9TItemDropFPvUi(u8 *arg0, u32 arg1);
u8 roll_technique_level__9TItemDropFv(s32 self, s32 table, s32 row, s32 col, s32 stride);
void roll_weapon_special__9TItemDropFiPvi(s32 rng, u8 *item, s32 idx);
void run_task__9TItemDropFv(void);
void select_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *item);
s32 select_rare_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *arg2);
void select_weapon_drop__9TItemDropFv(s32 rng, s32 level, u8 *item);
u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
u8 select_weighted_column_u16__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
void set_flag__9TItemDropFPvPv(void *arg0, void *item);
s32 try_generate_rare_item__9TItemDropFiPvPv(s32 arg0, u8 *arg1, u8 *arg2);
}
// --- end of C functions

#endif
