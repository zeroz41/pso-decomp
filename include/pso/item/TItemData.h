#ifndef PSO_ITEM_TITEMDATA_H
#define PSO_ITEM_TITEMDATA_H

#include "types.h"

struct ObjectSetData;
struct AttackParams;
struct ActorParamBlock;
struct TObjPlayer;

// The start every ItemPMT record shares (lookup_item_pmt_record): its id and
// the ItemModel.afs / ItemTexture.afs file indices of the item's model.
struct ItemPmtHeader {
    u32 id;
    s16 model;
    s16 texture;
};

// What an equipped item adds to its owner's stats; TItemData::apply_equip_effects
// fills it and add_equip_stats hands each stat to TObjPlayer::add_<stat>.
struct EquipStatBonus {
    s16 atp;
    s16 mst;
    s16 evp;
    s16 hp;
    s16 dfp;
    s16 ata;
    s16 lck;
    u8 pad_e[0x16];
};

// What an equipped item adds to its owner's HP and TP maxima
// (add_actor_hp_bonus / add_actor_tp_bonus).
struct EquipHpTpBonus {
    s16 hp;
    s16 tp;
};

struct TItemData {
    int isValidGroundDrop();
    void init();
    // Makes this item a meseta drop of `amount`.
    void init_meseta(s32 amount);
    void bswap();
    static s32 is_usable(void *data);
    static s32 lookup_item_def(void *data);
    static s32 is_wrapped(void *data);
    static s32 is_rare_item(void *data);
    static s32 is_custom_name_srank(void *data);
    // Packs a mag's MagStats into its item data, and unpacks them.
    static void serialize_mag(void *item, void *mag);
    static void deserialize_mag(void *item, void *mag);


    union {
        u8 data_u8[12];
        s8 data_s8[12];
        u8 data_u8_pair[6][2];
        u16 data_u16[6];
        u32 data_u32[3];
    } data1;
    u32 id;
    union {
        u8 data_u8[4];
        u16 data_u16[2];
        u32 data_u32;
        s32 price;  // a shop stock item's price
        s32 meseta; // a meseta item's amount
    } data2;
    // A letter's index in the alphabet (1 for 'a' or 'A'), 0 for anything else,
    // and back to its capital.
    s8 char_to_letter_index(s8 c);
    s8 letter_index_to_char(s8 index);
    void copy_from(TItemData *src);
    // Empty in this build: an item received from the network is converted
    // from the sender's version (0: DC v1, 2: v2 and later) and decoded, and
    // one sent is encoded.
    void convert_from_version(s32 version);
    // 2 draws the item name in the window's alternate style; always 0 here.
    s32 get_name_style();
    void decode_from_network();
    void encode_for_network();
    // A weapon's highest grind (its WeaponParams::max_grind).
    u8 get_max_grind();
    void register_drop();
    static void register_item_drop(TItemData *item);
    s32 get_max_stack_size();
    // A tool's stack count (data1 byte 5); 1 for an item that does not stack.
    s32 get_stack_count();
    void set_stack_count(u8 count);
    void set_unit_modifier(s16 modifier);
    // The item data's byte-swapped s16 at +6 (a unit's modifier).
    static s16 get_field6_bswap(void *data);
    // The byte-swapped s16s at +6 and +8 (an armor's or shield's DFP and
    // EVP bonus).
    static s16 getS16_06(void *data);
    static s16 get_bswap16_field8(void *data);
    void set_bswapped_field_8(s16 evp_bonus);
    void set_dfp_bonus(s16 dfp_bonus);
    s16 get_technique_level();
    s32 has_bonus_stats();
    void bswap_fields();
    f32 get_shield_set_multiplier(TObjPlayer *player);
    f32 get_armor_set_multiplier(TObjPlayer *player);
    f32 get_weapon_set_multiplier(TObjPlayer *player);
    // Adds what this item gives `owner` (the local player for 0) when
    // equipped; each item kind's part takes the same arguments.
    void apply_equip_effects(TObjPlayer *owner, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                             EquipHpTpBonus *hp_tp);
    void apply_custom_shield_bonus(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                                   EquipHpTpBonus *hp_tp);
    void apply_bonuses(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                       EquipHpTpBonus *hp_tp);
    void apply_unit_stat_bonus(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                               EquipHpTpBonus *hp_tp);
    void add_shield_stat_contribution(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params,
                                      EquipStatBonus *stats, EquipHpTpBonus *hp_tp);
    void add_armor_stat_contribution(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params,
                                     EquipStatBonus *stats, EquipHpTpBonus *hp_tp);
    f32 calc_clock_bonus(TObjPlayer *player);
    saddr calc_buy_price();
    void format_item_name(char *buf);
    int calc_display_grade();
    s32 get_base_rarity();
    s32 check_item_flags();
    void clear_unidentified_flag();
    static s32 is_item_usable(saddr arg0, u8 *item);
    void set_present_color(s8 color);
    s32 get_type_nibble();
    void add_weapon_stat_bonuses(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                                 EquipHpTpBonus *hp_tp);
    void set_wrapped();
    void set_packed_value(u16 kill_count);
    void unpack_from_item(ObjectSetData *set);
    void pack_three_colors(u8 *in);
    s32 calc_action_flags(s32 mask, TObjPlayer *player);
    s32 calc_price();
    // calc_price, or 0 without an item.
    static s32 calc_price_of(TItemData *data);
    u16 get_packed_value();
    void decode_packed_name_chars(s8 *out);
    void add_mag_stat_bonuses(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                              EquipHpTpBonus *hp_tp);
    f32 get_set_bonus_multiplier(TObjPlayer *player);
};

// The ItemPMT record for an item's type bytes, NULL for none.
void *lookup_item_pmt_record(u8 *item);

#include <stddef.h>
LAYOUT_ASSERT(ItemDataSize, sizeof(TItemData) == 0x14);
LAYOUT_ASSERT(ItemDataIDOffset, offsetof(TItemData, id) == 0xC);
LAYOUT_ASSERT(ItemDataExtensionOffset, offsetof(TItemData, data2) == 0x10);
#endif
