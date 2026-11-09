#ifndef PSO_PLAYER_TOBJPLAYER_8011C000_H
#define PSO_PLAYER_TOBJPLAYER_8011C000_H

#include "types.h"

extern "C" {
void find_tool_pmt_base_id(s32 arg0, u8 *arg1);
f32 get_item_price_coefficient(u8 arg0, u8 arg1);
s32 get_item_star_count(s32 id);
}
s32 get_item_stat_boost_record(s32 arg0, s32 type, s32 id);
s32 get_mag_feed_result(s32 arg0, s32 arg1);
extern "C" {
u8 get_technique_learn_limit(u8 arg0, u8 arg1);
s32 get_unit_attribute_index__10TObjPlayerFUc(u8 arg0);
u8 get_weapon_class_motion_type(u8 arg0);
void get_weapon_special_type_amount(u32 x, s16 *a, s16 *b);
}
s32 is_unsealable_item(u8 *id);
void roll_item_channel_below(u32 count, s32 arg1);
extern "C" {
u8 roll_weapon_special_for_stars(u8 arg0);
}

// --- C functions defined in TObjPlayer_8011C000.cpp ---
extern "C" {
void find_tool_pmt_base_id(s32 arg0, u8 *arg1);
f32 get_item_price_coefficient(u8 arg0, u8 arg1);
s32 get_item_star_count(s32 id);
u8 get_technique_learn_limit(u8 arg0, u8 arg1);
u8 get_weapon_class_motion_type(u8 arg0);
void get_weapon_special_type_amount(u32 x, s16 *a, s16 *b);
u8 roll_weapon_special_for_stars(u8 arg0);
}
// --- end of C functions

#endif
