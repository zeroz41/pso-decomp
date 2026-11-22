#ifndef PSO_ENEMY_MERILLLIA_TOBJENEMERILLLIA_H
#define PSO_ENEMY_MERILLLIA_TOBJENEMERILLLIA_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/TUnk_80494938.h"

struct TObjEneMerillLia : public TUnk_80493450 {
    TObjEneMerillLia(TObject *parent, void *setData);
    virtual ~TObjEneMerillLia();
    static void *create(void *arg0);
    virtual void beast_idle_update();
    virtual void beast_update_hurt();
    virtual void run_task();
    virtual void render();
    virtual void beast_update_approach();
    virtual void beast_update_group_chase();
    virtual void update_attack_trail();
    virtual void spawn_death_effect();
    virtual void play_attack_sound();
    virtual void play_hurt_sound();
    virtual void play_death_sound();
    virtual void play_group_chase_sound();
    virtual void run_demo_task();
    void sub_800D5570();
    virtual void beast_update_appear();
    virtual void run_attack_action();
    virtual void run_move_action();
    virtual void run_idle_action();
    TUnk_80494938 fade;
    s32 get_clamped_level();
    void clamp_and_apply_mode_param();
    void reset_state_clear_status();
    void init_attack_state();
    void reset_action_state();
    static void search_target(void *ov);
    static void update_emerge_state(void *ov);
    static void update_kafun_attack(void *p);
    void init_params_from_position();
    void select_action_by_distance();
    static void sub_800D6D64();
    static void destroy_rocks();
    void load_entry_params(s32 i);
    void sub_800D4EC8();
    void sub_800D501C();
    static void spawn_ground_effect(void *motion);
    f32 m_3c4;
    f32 unk_3C8;
    f32 unk_3CC;
    f32 m_3d0;
    f32 unk_3D4;
    s16 m_3d8;
    u8 pad_3DA[0x2];
};

LAYOUT_ASSERT(TObjEneMerillLia_size, sizeof(TObjEneMerillLia) == 0x3DC);

#endif
