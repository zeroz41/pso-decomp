#ifndef PSO_ITEM_DROP_TITEMDROP_H
#define PSO_ITEM_DROP_TITEMDROP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct SubtractiveRng;
struct TItemData;
class LoadUnloadSet;

// A {lo, hi} range of a drop table: meseta amounts and technique levels.
// 0xFF in either end, or hi below lo, is no range.
struct ItemDropMesetaRange {
    u16 lo;
    u16 hi;
};

struct ItemDropLevelRange {
    u8 lo;
    u8 hi;
};

// The common drop table of the current section ID and difficulty
// (ItemPT<mode><difficulty><section>.rel from ItemPT.gsl). Most tables have
// one column per area group (10) and one row per choice; a weight of 0 is
// never chosen.
struct ItemDropTable {
    u8 *weapon_kind_weights;             // 12 weapon kinds
    s8 *weapon_tier_bases;               // per weapon kind: the area of its first tier
    s8 *weapon_tier_lengths;             // per weapon kind: areas per tier
    u8 *grind_weights;                   // 9 grinds x 4 area columns
    u8 *armor_level_weights;             // 5 level bonuses
    u8 *slot_count_weights;              // 5 slot counts
    ItemDropMesetaRange *enemy_meseta;   // per enemy type
    u8 *enemy_drop_chance;               // per enemy type, percent
    u8 *enemy_drop_kind;                 // per enemy type
    ItemDropMesetaRange *box_meseta;     // per area
    u16 *attribute_value_weights;        // 23 values x 6 rows
    s8 *attribute_rows;                  // 3 attributes x 10 areas, -1 for none
    u8 *attribute_kind_weights;          // 6 attribute kinds x 10 areas
    u8 *special_stars;                   // per area
    u8 *special_chance;                  // per area, percent
    u16 *tool_weights;                   // 28 tools x 10 areas
    u8 *technique_weights;               // 19 techniques x 10 areas
    ItemDropLevelRange *technique_levels; // 19 techniques x 10 areas
    u8 armor_level_bias;
    u8 *unit_max_stars;                  // per area
    u8 *box_kind_weights;                // 7 kinds x 10 areas
};

// A rare drop: its chance (5-bit exponent, 3-bit mantissa) and item type.
struct ItemDropRareEntry {
    u8 chance;
    u8 type[3];
};

// The rare drop table (ItemRT<...>.rel from ItemRT.gsl): the rare drop of
// each enemy type and the rare box drops, each with its area.
struct ItemDropRareTable {
    ItemDropRareEntry *enemy_items;
    s32 box_count;
    s8 *box_areas;
    ItemDropRareEntry *box_items;
};

// The item drop generator: rolls enemy and box drops from the section's
// drop tables with 17 random channels of its own.
struct TItemDrop : public TObject {
    TItemDrop(TObject *parent, s8 section);
    virtual ~TItemDrop();
    static TItemDrop *create_drop(TObject *parent);

    // item_drop_load_unload_table's {load, unload} pairs: the first opens
    // ItemPT.gsl/ItemRT.gsl, the second allocates and frees the unit star
    // tables.
    static void load_drop_tables();
    static void unload_drop_tables();
    static void alloc_unit_star_tables();
    static void free_unit_star_tables();
    static void refresh_drop_table_if_changed();
    static s32 get_drop_table_mode_flags();
    static void format_drop_table_filename(char *out, const char *prefix);
    static s32 calc_drop_offset(s32 section);
    static void init_drop_table();
    static void count_unit_star_buckets();

    static s32 is_enabled();
    s32 is_not_special();
    static s32 can_drop();

    f32 roll_table_ratio(u32 channel);
    u32 roll_channel_below(s32 count, u32 channel);
    u16 roll_meseta_range(ItemDropMesetaRange *ranges, s32 row, s32 column, s32 stride);
    u8 roll_technique_level(ItemDropLevelRange *ranges, s32 row, s32 column, s32 stride);
    u8 select_weighted_column_u16(u16 *weights, s32 column, s32 count, s32 stride);
    u8 select_weighted_byte(u8 *weights, s32 column, s32 count, s32 stride);

    void select_enemy_drop(s32 enemy_type, s32 area, TItemData *item);
    void select_box_item(s32 area, TItemData *item);
    void generate_drop_item(s32 area, TItemData *item);
    s32 select_rare_box_item(s32 area, TItemData *item);
    s32 drop_item(s32 enemy_type, TItemData *item);
    s32 try_generate_rare_item(ItemDropRareEntry *entry, TItemData *item);
    void select_weapon_drop(s32 area, TItemData *item);
    void calc_drop_item(TItemData *item, s32 grind_column);
    void roll_rare_weapon_attributes(TItemData *item, s32 area);
    void build_weapon_type_weights(TItemData *item, s32 area);
    void prune_weapon_attributes(TItemData *item);
    void roll_weapon_special(TItemData *item, s32 area);
    void set_flag(TItemData *item);
    void calc_drop_rarity(s32 area, TItemData *item);
    void roll_armor_bonuses(TItemData *item);
    void set_drop_index(TItemData *item);
    void select_unit_drop(u8 stars, TItemData *item);
    void generate_tool_drop(s32 area, TItemData *item);
    void init_rare_item_data(TItemData *item);
    void handle_type3(TItemData *item);
    void apply_item_data(TItemData *item);
    void apply_drop_restrictions(TItemData *item);
    void clear_item_if_player_picked_up(TItemData *item);
    s8 get_bool_from_1d6ddc();

    // create_load_unload_set(item_drop_load_unload_table).
    LoadUnloadSet *load_unload_set;
    // The 17 random channels the constructor seeds.
    SubtractiveRng **rngs;

    static s32 section_id;
    static s32 drop_table_mode_flags;
    static ItemDropTable *common_probability_table;
    static ItemDropRareTable *rare_item_table_file;
    static u8 *unit_star_classes;
    static u8 *unit_star_bucket_counts;
    static void *relocatable_load_buffer;
    static void *second_relocatable_load_buffer;
};

LAYOUT_ASSERT(TItemDrop_size, sizeof(TItemDrop) == 0x24);

// item_class_load_unload_table's item drop pair.
void init_item_drop_globals();
void unload_item_drop_globals();

// A random value below count from rng.
s32 item_drop_rng_below(SubtractiveRng *rng, u32 count);

u8 default_rule_value_stub(void *lobby);

struct DifficultyLetters { char *n[4]; };

#endif
