#ifndef PSO_ITEM_TITEMDATA_H
#define PSO_ITEM_TITEMDATA_H

#include "types.h"

struct EquipStats { s16 s0; s16 s2; s16 s4; s16 s6; s16 s8; s16 sA; s16 sC; };

struct TItemData {
    int isValidGroundDrop();
    void init();
    void bswap();
    static s32 is_usable(void *data);
    static s32 is_wrapped(void *data);
    static s32 is_rare_item(void *data);
    static s32 is_custom_name_srank(void *data);


    union {
        u8 data_u8[12];
        u8 data_u8_pair[6][2];
        u16 data_u16[6];
        u32 data_u32[3];
    } data1;
    u32 id;
    union {
        u8 data_u8[4];
        u16 data_u16[2];
        u32 data_u32;
    } data2;
    static s8 char_to_letter_index(void *self, s8 c);
    void copy_from(TItemData *src);
    // Empty in this build: an item received from the network is converted
    // from the sender's version (0: DC v1, 2: v2 and later) and decoded, and
    // one sent is encoded.
    void convert_from_version(s32 version);
    // 2 draws the item name in the window's alternate style; always 0 here.
    s32 get_name_style();
    void decode_from_network();
    void encode_for_network();
    static u8 get_entry_field16();
    int register_drop();
    s32 get_max_stack_size();
    // A tool's stack count (data1 byte 5); 1 for an item that does not stack.
    s32 get_stack_count();
    void set_stack_count(u8 count);
    void set_unit_modifier(s16 arg1);
    // The item data's byte-swapped s16 at +6 (a unit's modifier).
    static s16 get_field6_bswap(void *data);
    void set_bswapped_field_8(s16 arg1);
    void set_dfp_bonus(s16 arg1);
    s16 get_technique_level();
    s32 has_bonus_stats();
    void bswap_fields();
    f32 get_shield_set_multiplier(u8 *arg1);
    f32 get_armor_set_multiplier(u8 *arg1);
    f32 get_weapon_set_multiplier(u8 *arg1);
    void apply_equip_effects(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    void apply_custom_shield_bonus(s32 player, TItemData *a, TItemData *b, EquipStats *stats, s32);
    s32 calc_buy_price();
    void format_item_name(char *buf);
    int calc_display_grade();
    s32 get_base_rarity();
    s32 check_item_flags();
    static u8 is_item_usable(s32 arg0, u8 *arg1);
    int test_flag3();
    int get_item_field_2();
    void*initialize_mag_data();
    void add_quantity(s32 arg1);
    void adjust_count(s32 arg1);
    static void add_stat_ptr(s16 *arg0, s32 arg1);
    void add_bonus(s16 arg1);
    s16 get_mag_mind_level();
    s16 get_stat_percent();
    s16 get_level();
    s16 get_percent();
    void update_player_field();
    void set_present_color(s8 color);
    s32 get_type_nibble();
    void add_weapon_stat_bonuses(s32 player, s16 *out, s32 unused, s16 *out2, s32 _w5);
    void set_wrapped();
    void set_packed_value(u16 arg1);
    void unpack_from_item(void *arg1);
    void pack_three_colors(u8 *in);
    s32 calc_action_flags(s32 mask, u8 *player);
    s32 calc_price();
    // calc_price, or 0 without an item.
    static s32 calc_price_of(TItemData *data);
    s32 update_mag_status_gauges();
    u16 get_packed_value();
    void decode_packed_name_chars(s8 *out);
};

extern "C" {
}

#include <stddef.h>
typedef char ItemDataSize[(sizeof(TItemData) == 0x14) ? 1 : -1];
typedef char ItemDataIDOffset[(offsetof(TItemData, id) == 0xC) ? 1 : -1];
typedef char ItemDataExtensionOffset[(offsetof(TItemData, data2) == 0x10) ? 1 : -1];
#endif
