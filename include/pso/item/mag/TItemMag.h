#ifndef PSO_ITEM_MAG_TITEMMAG_H
#define PSO_ITEM_MAG_TITEMMAG_H

#include "types.h"
#include "pso/item/MagStats.h"
#include "pso/system/NinjaTypes.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/mag/TItemMagSub.h"
#include <stddef.h>

struct TItem;
struct TItemData;
struct TObjPlayer;

// What the mag last saw of its owner; collect_owner_events compares the
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

// TItemMag::state: the support action running (low bits) and its state.
enum {
    MAG_ACTION_MASK = 0xF,
    MAG_LOCAL = 0x10,         // the owner is this client's player
    MAG_INACTIVE = 0x20,      // equipped while its effects are off
    MAG_FORM_CHANGED = 0x40,  // the next model load plays the grow effect
};

// The support actions (the low bits of TItemMag::state, and the actions a
// mag's parameter record assigns to its triggers).
enum {
    MAG_ACTION_IDLE = 1,
    MAG_ACTION_LEVEL_UP = 2,     // 45 frames
    MAG_ACTION_FED = 3,          // 90 frames
    MAG_ACTION_SHIFTA_DEBAND = 4,
    MAG_ACTION_WAIT = 5,         // 90 frames, casts nothing
    MAG_ACTION_RESTA = 6,
    MAG_ACTION_REVERSER = 7,
    MAG_ACTION_INVINCIBILITY = 8,
};

// collect_owner_events' bits.
enum {
    MAG_EVENT_LOW_HP = 0x1,
    MAG_EVENT_DEATH = 0x2,
    MAG_EVENT_LOW_SYNCHRO = 0x4,
    MAG_EVENT_HIGH_SYNCHRO = 0x8,
    MAG_EVENT_FED = 0x10,
    MAG_EVENT_LEVEL_UP = 0x20,
    MAG_EVENT_PB_FULL = 0x40,
    MAG_EVENT_BOSS_AREA = 0x80,
};

// A mag's ItemPMT record (TObjPlayer::get_pmt_record by item group).
struct MagPmtRecord {
    u8 pad_0[0x8];
    s16 feed_table;
    u8 photon_blast;        // the blast its form adds
    u8 activation_rate;
    u8 trigger_actions[4];  // TItemMag::trigger_actions
    u8 trigger_modes[4];
};

// ItemMagEdit.prs: the mag models' tables, indexed by item group.
struct MagEditData {
    s8 **motion_tables;  // per model variant: each group's 2 x 6 motion types
    s8 *oscillation_ids; // each group's 2 oscillation states, -1 for none
    MagNodeOscillationState *oscillations;
    u8 *material_nodes;  // per group; 0xFF (-1) for none
    NJS_ARGB *colors;
    s8 *evolution_stages;
};

// The files TItemMag::load_data_files reads (TItemMagSub.cpp).
extern const char item_mag_motion_path[20];
extern const char item_mag_edit_path[20];

// itemmagmotion.dat, one record per mag motion type (TItemMag::load_data_files).
extern MagFollowParameters *item_mag_motions;

// A mag: it follows its owner, is fed items, gains stats and photon blasts,
// and acts on the owner's support events.
struct TItemMag : public TItemEquipBase {
    TItemMag(TObject *parent, u8 *item);
    virtual ~TItemMag();
    // Sends the owner's stats again when the mag's are out of range.
    virtual void update_owned();
    virtual void update_in_inventory();
    virtual void update_equipped();
    // A support action another client's copy of the mag started.
    virtual void activate_effect(s32 action);
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

    // The mag entry of construct_item's table: NULL without data.
    static TItem *create(u8 *item);
    static void cleanup();
    static void load_data_files();
    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    // Whether player's equipped mag meets quest condition kind (0-5).
    static s32 check_evolution_cond(TObjPlayer *player, s32 kind);

    int is_local();
    s16 get_iq();
    s16 get_synchro();
    s16 get_def_level();
    s16 get_pow_level();
    s16 get_dex_level();
    s16 get_mind_level();
    s32 is_owner_frozen();
    u32 is_owner_acting();
    u32 is_inactive();
    // Changes the mag into form (its item group) unless it has evolved
    // past the third stage.
    void evolve_into(u8 form);
    s32 get_evolution_stage();
    // Counts down the frames until the mag gets hungry again after a feed.
    void tick_fullness_timer();
    // A colour past the table's 18 ones: the owner's section id's.
    void resolve_color();
    void load_param_record();
    void set_triggers(const u8 *actions, const u8 *modes);
    void register_photon_blasts();
    s32 roll_trigger(s32 trigger);
    s32 can_perform_action(s32 action);
    void set_subs_visible(s32 visible);
    s32 get_model_variant();
    void set_action_motion();
    s32 get_dominant_stats();
    void evolve_first_form();
    void evolve_second_form();
    void evolve_third_form();
    s32 evolve_rare_form();
    void evolve_special_form(u8 kind);
    void evolve_by_level();
    void on_form_changed();
    s8 collect_owner_events();
    void react_to_events(s8 events);
    void on_events_handled();
    void cast_support_technique(s32 technique);
    s32 apply_feed(MagStats *change);
    void request_action(s32 action);
    void start_action(s32 action);
    void update_idle_action();
    void update_short_action();
    void update_long_action();
    void update_shifta_deband_action();
    void update_wait_action();
    void update_resta_action();
    void update_reverser_action();
    void update_invincibility_action();
    void start_invincibility();
    void refresh_invincibility();
    void end_invincibility();

    u32 state;               // MAG_ACTION_MASK and MAG_* bits
    f32 fullness_frames;     // until it may be fed again; 0 when hungry
    f32 feeds_while_full;
    MagStats stats;
    TItemMagSub *children[2];
    s8 *motion_types[2];     // each child's motion per support action
    s32 feed_table;          // the feed table its parameter record names
    u8 activation_rate;
    u8 trigger_actions[4];   // PB full, low HP, death, boss area
    u8 trigger_modes[4];     // how each trigger's chance is worked out
    u8 pad_1c5[3];
    f32 action_cooldown;
    s32 action_frames;       // frames into the support action
    s32 invincibility_frames;
    MagOwnerWatch owner_watch;
};

typedef char MagOffset_state[offsetof(TItemMag, state) == 0x18C ? 1 : -1];
typedef char MagOffset_stats[offsetof(TItemMag, stats) == 0x198 ? 1 : -1];
typedef char MagOffset_children[offsetof(TItemMag, children) == 0x1A8 ? 1 : -1];
typedef char MagOffset_motion_types[offsetof(TItemMag, motion_types) == 0x1B0 ? 1 : -1];
typedef char MagOffset_trigger_modes[offsetof(TItemMag, trigger_modes) == 0x1C1 ? 1 : -1];
typedef char MagOffset_action_cooldown[offsetof(TItemMag, action_cooldown) == 0x1C8 ? 1 : -1];
typedef char MagOwnerWatchOffset[offsetof(TItemMag, owner_watch) == 0x1D4 ? 1 : -1];
typedef char MagSize[sizeof(TItemMag) == 0x1E0 ? 1 : -1];

#endif
