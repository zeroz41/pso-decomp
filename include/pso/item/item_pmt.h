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
void play_weapon_hit_sound(ItemSoundRequest *request);
void play_weapon_owner_sounds(ItemSoundRequest *request);

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

// A {count, records} list of the item parameter table; the record size
// depends on the list (weapon 0x28, armor 0x1C, unit 0x10, mag 0x18).
struct ItemPmtList {
    s32 count;
    char *records;
};

// A tool record; find_tool_pmt_base_id matches its id.
struct ItemPmtTool {
    s32 id;
    u8 pad_4[0x10];
};

struct ItemPmtToolList {
    s32 count;
    ItemPmtTool *records;
};

// Item codes (type, group, index) that is_unsealable_item accepts.
struct ItemPmtCode {
    u8 code[3];
    u8 pad_3;
};

struct ItemPmtCodeList {
    s32 count;
    ItemPmtCode *codes;
};

struct ItemCombinationList {
    s32 count;
    ItemCombination *recipes;
};

// A weapon's range record; its callers read the range as the first float.
struct WeaponRangeRecord {
    f32 range;
    u8 pad_4[0x10];
};

// The per-group range records, then the special ones the rules pick.
struct WeaponRangeTable {
    WeaponRangeRecord groups[0xAA];
    WeaponRangeRecord specials[1];
};

// Picks the special range record for a weapon group and index (0xFF: any)
// in a mode (1: always, 0: only for mode 2 when the weapon asks for it).
struct WeaponRangeRule {
    u8 group;
    u8 index;
    u8 record;
    u8 mode;
};

struct WeaponRangeRuleList {
    s32 count;
    WeaponRangeRule *rules;
};

// What a random item can turn into: item codes with their weights out of 256.
struct ItemChoice {
    u8 code[3];
    u8 weight;
};

struct ItemChoiceList {
    s32 count;
    ItemChoice *choices;
};

struct ItemChoiceListTable {
    s32 count;
    ItemChoiceList *lists;
};

// get_weapon_special_type_amount's pair for one weapon special.
struct WeaponSpecialParam {
    s16 type;
    s16 amount;
};

// A sound effect and its pitch request (0: none).
struct ItemSoundCue {
    s32 key;
    s32 pitch;
};

// The sounds a weapon group plays for its owner and on what it hits.
struct WeaponSoundSet {
    ItemSoundCue owner[2];
    ItemSoundCue target[2];
};

// Replaces a hit sound by the target's type or class.
struct ItemSoundRemap {
    s32 key;
    s32 *by_target_type;
    s32 *by_class;
};

struct ItemSoundRemapList {
    s32 count;
    ItemSoundRemap *entries;
};

// The root of ItemPMT.prs; field names follow the functions that read them.
// units and mags are inferred from the item type order (weapon, armor,
// unit, tool, mag) of the first five lists.
struct ItemPmt {
    ItemPmtList *weapons;               // per weapon group, 0xAA of them
    ItemPmtList *armors;                // armors, shields
    ItemPmtList *units;
    ItemPmtToolList *tools;             // per tool group, 0x18 of them
    ItemPmtList *mags;
    u8 *weapon_motion_types;            // per weapon group
    char *photon_colors;                // 0x24-byte records
    WeaponRangeTable *weapon_ranges;
    f32 *weapon_price_coefficients;     // per weapon group
    f32 *price_coefficients;            // armor, shield, unit, mag
    char **mag_feed_tables;             // 8 tables of 8-byte results
    u8 *star_counts;                    // from item id 0x94
    WeaponSpecialParam *weapon_specials;
    WeaponSoundSet *weapon_sounds;      // per weapon group
    u8 *stat_boosts;                    // 6-byte records
    ItemSoundCue *shield_sounds;        // per shield index
    u8 (*technique_limits)[12];         // per technique, per character class
    ItemCombinationList *combinations;
    ItemSoundRemapList *sound_remaps;
    u8 *technique_boosts;               // 0x18-byte TechniqueBoostParam sets
    ItemChoiceListTable *random_items;  // per random item index
    ItemPmtCodeList *unsealable_items;
    WeaponRangeRuleList *weapon_range_rules;
};

extern ItemPmt *item_pmt_tbl;

#endif