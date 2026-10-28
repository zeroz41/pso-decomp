#ifndef PSO_ITEM_TITEMMAG_H
#define PSO_ITEM_TITEMMAG_H

#include "types.h"

struct TItem;
struct TItemData;
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemMagSub.h"
#include <stddef.h>

// What the mag last saw of its owner; collect_support_events compares the
// owner against it each frame and flags holds the events already reported.
struct MagOwnerWatch {
    void clear_flags(u32 mask);
    void set_flags(u32 mask);
    u32 test_flags(u32 mask);

    s16 owner_level;  // a rise is the level-up event
    s16 area;         // a change into a boss area is the boss event
    u32 flags;
    s16 hp;           // a drop is the low-HP event
    s16 tp;
};

// A mag: it follows its owner, is fed items, gains stats and photon blasts,
// and acts on the owner's support events.
struct TItemMag : public TItemEquipBase {
    TItemMag(TObject *parent, u8 *item);
    virtual ~TItemMag();
    virtual void update_owned();
    virtual void update_in_inventory();
    virtual void update_equipped();
    virtual void activate_effect(s32 effect);
    virtual void write_item_data(TItemData *data);
    virtual void render_equipped();
    virtual void render_equipped_shadow();
    virtual s32 feed(TItemData *food);
    virtual void snap_to_owner();
    virtual void on_equip();
    virtual void on_unequip();
    virtual void request_equipped_model();
    virtual void release_model();
    virtual void on_model_loaded();

    u32 m_18c;
    f32 m_190;
    f32 m_194;
    void* m_198;
    u8 _pad19C[0x8];
    u8 m_1a4;
    u8 unk_1A5[0x1];
    u8 m_1a6;
    u8 unk_1A7[0x1];
    TItemMagSub *children[2];
    s8 *model_entries[2];
    u32 m_1b8;
    u8 unk_1BC[0x1];
    u8 m_1bd;
    u8 unk_1BE[0x1];
    u8 m_1bf;
    u8 unk_1C0[0x8];
    f32 m_1c8;
    u32 m_1cc;
    u8 _pad1D0[0x4];
    MagOwnerWatch owner_watch;
    void resolve_sentinel_color();
    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    static s32 check_evolution_cond(u32 arg0, s32 arg1);
    s32 check_feed_state(s32 arg1);
    void copy_owner_data();
    s32 check_action_probability(s32 arg1);
    void copy_owner_pair(void *a, void *b);
    void set_subs_visible(s32 on);
    void update_feed_anim();
    void do_action_by_class();
    void evolve_first_form();
    void apply_form_change();
    void feed_by_item_flags(s8 arg1);
    s8 collect_support_events();
    void cast_support_technique(s32 technique);
    s32 apply_feed_stats(u8 *arg1);
    void request_support_action(s32 arg1);
    void transfer_energy();
    void apply_feed_delta();
    void update_feed_timer();
    void feed_if_over_90();
    void feed_if_over_45();
    void update_feed();
    void check_level_cap();
    void check_level_evolve();
    void apply_auto_support_techniques();
    void update();
    // The mag entry of construct_item's table: NULL without data.
    static TItem *create(u8 *item);
    static void cleanup();
    static void load_data_files();
    int get_status_flag();
    s16 get_item_type();
    s16 get_sync();
    int is_active();
    s32 get_sub_value();
    s32 get_mag_id();
    f32 get_stat_f32();
    int check_state_flag_1();
    void add_photon_blast(u8 blast);
    void add_clamped_stat(s32 arg1);
    static void add_stat_clamped(s16 *arg0, s32 arg1);
    s32 get_photon_blast_at_slot(s32 slot);
    void apply_transform_action(u8 arg1);
    void apply_natural_evolution();
    void select_support_action(s32 arg1);
    void add_stat_level_capped(s16 arg1);
    void register_photon_blasts();
    s32 is_pb_registered(u8 arg1);
};

typedef char MagOffset_m_18c[offsetof(TItemMag, m_18c) == 0x18C ? 1 : -1];
typedef char MagOffset_m_198[offsetof(TItemMag, m_198) == 0x198 ? 1 : -1];
typedef char MagOffset_children[offsetof(TItemMag, children) == 0x1A8 ? 1 : -1];
typedef char MagOffset_model_entries[offsetof(TItemMag, model_entries) == 0x1B0 ? 1 : -1];
typedef char MagOwnerWatchOffset[offsetof(TItemMag, owner_watch) == 0x1D4 ? 1 : -1];
typedef char MagSize[sizeof(TItemMag) == 0x1E0 ? 1 : -1];
#endif
