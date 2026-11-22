#ifndef PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H
#define PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"

class AreaAttackHistory;
class TUnk_804928CC;
class TUnk_8048FE08;
class TUnk_80494968;

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
    void exec(s32 arg1);
    void handle_state(s32 arg1);
    s32 check_stage_advance();
    void sub_80097620(s32 mode);
    void sub_80097714(s32 mode);
    void sub_800987E8(s32 mode);
    void sub_80098BAC(s32 mode);
    void init_enemy();
    static void set_entry_value_clamped(s32 arg0, f32 farg0);
    static void free_resources();
    void *create();
    static void load_resources();
    void spawn_offset_particle();
    void spawn_particle_if_in_band();
    void update_if_in_band();
    s32 pad_3C0;  // flags; init_enemy sets bit 0
    TUnk_80490470 pad_3C4;
    RenderFadeState renderFadeStates[4];
    Vec pad_450[4];
    s32 pad_480;
    s32 pad_484;
    s32 pad_488;
    s32 pad_48C;
    s32 pad_490;
    s32 pad_494;
    TUnk_804928CC *collider;  // built over the Bringer's collision bodies
    AreaAttackHistory *attack_history;
    TUnk_8048FE08 *pad_4A0;
    TUnk_80494968 *pad_4A4;
    s32 pad_4A8;
    s32 pad_4AC;
    s32 pad_4B0;
    s32 pad_4B4;
    s32 pad_4B8;
    f32 pad_4BC;
    f32 pad_4C0;
    TObject *pad_4C4;
};

LAYOUT_ASSERT(TObjEneDf2Bringer_size, sizeof(TObjEneDf2Bringer) == 0x4C8);
#endif
