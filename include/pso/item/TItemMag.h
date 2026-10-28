#ifndef PSO_ITEM_TITEMMAG_H
#define PSO_ITEM_TITEMMAG_H

#include "types.h"

struct TItem;
struct TItemData;
#include "pso/item/TItemMagSub.h"
#include <stddef.h>

struct TItemMag
{
    void serialize_to_item(void *item);

    u8 unk_0[0x1];
    u8 m_1;
    u8 unk_2[0x2];
    u32 m_4;
    u8 unk_8[0x14];
    u8 _pad1C[0x8];
    u32 m_24;
    u8 unk_28[0x14];
    f32 m_3c;
    u8 unk_40[0x9C];
    u32 m_dc;
    u8 unk_E0[0xE];
    u8 m_ee;
    u8 unk_EF[0x1];
    MagDrawOwner *m_f0;
    void *m_f4;
    u8 _padF8[0x80];
    void* m_178;
    void *m_17c;
    u8 _pad180[0x8];
    void *m_188;
    u32 m_18c;
    u8 _pad190[0x8];
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
    u16 m_1d4;
    s16 m_1d6;
    u8 _pad1D8[0x4];
    u16 m_1dc;
    u16 m_1de;
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
    static u8 *create(s32 arg0);
    static void cleanup();
    static void load_data_files();
    int get_status_flag();
    void copy_record(u8 *arg1);
    s16 get_item_type();
    s16 get_sync();
    int is_active();
    s32 get_sub_value();
    void init_feed_timer();
    s32 get_mag_id();
    f32 get_stat_f32();
    int check_state_flag_1();
    void clear_feed_flags(u32 v);
    void set_flags(u32 v);
    int test_flags(u32 m);
    void add_photon_blast(u8 blast);
    void add_clamped_stat(s32 arg1);
    static void add_stat_clamped(s16 *arg0, s32 arg1);
    s32 get_photon_blast_at_slot(s32 slot);
    void apply_transform_action(u8 arg1);
    void apply_natural_evolution();
    void select_support_action(s32 arg1);
    s32 get_type();
    void add_stat_level_capped(s16 arg1);
    void register_photon_blasts();
    s32 is_pb_registered(u8 arg1);
};

typedef char MagOffset_m_24[offsetof(TItemMag, m_24) == 0x24 ? 1 : -1];
typedef char MagOffset_m_f0[offsetof(TItemMag, m_f0) == 0xF0 ? 1 : -1];
typedef char MagOffset_m_f4[offsetof(TItemMag, m_f4) == 0xF4 ? 1 : -1];
typedef char MagOffset_m_17c[offsetof(TItemMag, m_17c) == 0x17C ? 1 : -1];
typedef char MagOffset_m_188[offsetof(TItemMag, m_188) == 0x188 ? 1 : -1];
typedef char MagOffset_m_18c[offsetof(TItemMag, m_18c) == 0x18C ? 1 : -1];
typedef char MagOffset_m_198[offsetof(TItemMag, m_198) == 0x198 ? 1 : -1];
typedef char MagOffset_children[offsetof(TItemMag, children) == 0x1A8 ? 1 : -1];
typedef char MagOffset_model_entries[offsetof(TItemMag, model_entries) == 0x1B0 ? 1 : -1];
typedef char MagSize[sizeof(TItemMag) == 0x1E0 ? 1 : -1];
#endif
