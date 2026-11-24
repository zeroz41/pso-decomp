#ifndef PSO_ITEM_DROP_TITEMDROP_H
#define PSO_ITEM_DROP_TITEMDROP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct SubtractiveRng;

struct TItemDrop : public TObject {
    TItemDrop(TObject *parent, s8 section);
    virtual ~TItemDrop();
    // create_load_unload_set(item_drop_load_unload_table) (name inferred).
    saddr load_unload_set;
    SubtractiveRng **entries;
    // item_drop_load_unload_table's {load, unload} pairs (names inferred:
    // the first opens ItemPT.gsl/ItemRT.gsl, the second allocates and frees
    // the unit star tables).
    static void load_drop_tables();
    static void unload_drop_tables();
    static void alloc_unit_star_tables();
    static void free_unit_star_tables();
    static void clear_item_if_player_picked_up(void* p, void* id);
    static s32 calc_drop_offset(s32 arg0);
    static void set_drop_index(void *rng, void *item);
    void select_unit_drop(u8 kind, u8 *item);
    static void init_drop_table();
    static void count_unit_star_buckets();
    static void refresh_drop_table_if_changed();
    static s32 is_enabled();
    static s32 is_not_special(void *);
    static s32 can_drop();
    u32 roll_channel_below(s32 count, u32 channel);
    f32 roll_table_ratio(u32 channel);
    void generate_drop_item(s32 idx, u8 *item);
    static s32 select_rare_box_item(s32 rng, s32 off, u8 *item);
    static s32 drop_item(s32 rng, s32 area, saddr item);
    static void calc_drop_rarity(saddr rng, s32 idx, void *item_);
    static void init_rare_item_data(void *arg0, void *item_data);
    static void handle_type3(void* p, void* a1);
    static void apply_item_data(void *arg0, void *item);
    static void set_flag(void *rng, void *item);
    static void calc_drop_item(saddr rng, void *item, s32 value);
    u16 roll_meseta_range(saddr arg1, s32 a, s32 b, s32 c);
    u8 roll_technique_level(saddr table, s32 row, s32 col, s32 stride);
    u8 select_weighted_byte(saddr base, s32 off, s32 count, s32 stride);
    s8 get_bool_from_1d6ddc();
};

LAYOUT_ASSERT(TItemDrop_size, sizeof(TItemDrop) == 0x24);

struct TItemData;
extern "C" void select_enemy_drop__9TItemDropFPviiPv(u8 *self, s32 area, s32 idx, TItemData *item);

#endif
