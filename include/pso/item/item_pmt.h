#ifndef PSO_ITEM_ITEM_PMT_H
#define PSO_ITEM_ITEM_PMT_H

#include "types.h"

struct TObjPlayer;
class TObjChara;

// What the item sound players read: the item's group and index, the player
// using it and, for a hit, what it hit and which of its colliders.
struct ItemSoundRequest {
    u8 group;
    u8 index;
    u8 pad_2[2];
    TObjPlayer *player;
    s32 unused;
    TObjChara *target;
    s32 collider;

    void clear();
};

void play_shield_sound_cue(ItemSoundRequest *cue);

void free_item_pmt(void);
void load_item_pmt(void);
void load_items(void);
void unload_items(void);

void find_tool_pmt_base_id(s32 item_id, u8 *item_code);
f32 get_item_price_coefficient(u8 type, u8 sub);
extern "C" {
s32 get_item_star_count(s32 id);
s32 get_unit_attribute_index__10TObjPlayerFUc(u8 flags);
}
u8 get_weapon_class_motion_type(u8 group);
extern "C" {
u8 roll_weapon_special_for_stars(u8 stars);
}
saddr get_item_stat_boost_record(s32 item_type, s32 group, s32 index);
saddr get_mag_feed_result(s32 feed_table, s32 food_id);
u8 get_technique_learn_limit(u8 char_class, u8 technique);
void get_weapon_special_type_amount(u8 x, s16 *a, s16 *b);
s32 is_unsealable_item(u8 *id);
void roll_item_channel_below(u32 count, s32 channel);

void *get_armor_pmt_record(int type, int id);

// One row of the item combination table: using use_item while equipped_item
// is equipped turns it into result_item; 0xFF fields match anything.
struct ItemCombination {
    u8 use_item[3];
    u8 equipped_item[3];
    u8 result_item[3];
    u8 mag_level;
    u8 grind;
    u8 level;
    u8 section_id;
    u8 pad_D[3];
};

ItemCombination *find_item_combination_recipe(u8 *id, void *item);

#endif