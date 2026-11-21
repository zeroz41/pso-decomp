#ifndef PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H
#define PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"

struct TObjEneDf2Bringer : public TObjEneDD_ST {
    TObjEneDf2Bringer(TObject *arg1, void *arg2);
    virtual ~TObjEneDf2Bringer();
    virtual s32 acquire_target(f32);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_effect_pos_above_self();
    void sub_80098DEC();
    void sub_800994F8();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    u8 _pad3DC[0x4];
    void* m_3e0;
    u8 _pad3E4[0x6C];
    void* m_450;
    u8 _pad454[0x2C];
    u32 m_480;
    u8 _pad484[0x4];
    u32 m_488;
    u8 _pad48C[0x8];
    u32 m_494;
    u8 _pad498[0x10];
    u32 m_4a8;
    void exec(s32 arg1);
    void handle_state(s32 arg1);
    s32 check_stage_advance();
    void init_enemy();
    static void set_entry_value_clamped(s32 arg0, f32 farg0);
    static void free_resources();
    void *create();
    static void load_resources();
    u8 unk_490[0x38];
    void spawn_offset_particle();
    void spawn_particle_if_in_band();
    void update_if_in_band();
};

LAYOUT_ASSERT(TObjEneDf2Bringer_size, sizeof(TObjEneDf2Bringer) == 0x4C8);
#endif
