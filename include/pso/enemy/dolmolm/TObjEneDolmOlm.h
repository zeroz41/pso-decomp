#ifndef PSO_ENEMY_DOLMOLM_TOBJENEDOLMOLM_H
#define PSO_ENEMY_DOLMOLM_TOBJENEDOLMOLM_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/TUnk_80493450.h"

struct TObjEneDolmOlm : public TUnk_80493450 {
    TObjEneDolmOlm(saddr parent, saddr arg2);
    virtual ~TObjEneDolmOlm();
    virtual void run_task();
    virtual void render();
    s32 render_model_if_visible();
    void check_path_ahead(s32, f32);
    void sub_80301148();
    virtual void run_attack_action();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void beast_update_appear();
    virtual void request_stand_action();
    virtual void run_demo_task();
    virtual void select_post_attack_mode();
    virtual void play_death_sound();
    virtual void play_hurt_sound();
    virtual void play_attack_sound();
    virtual void play_alert_sound();
    virtual void spawn_death_effect();
    virtual void update_attack_trail();
    void* m_3a8;
    u8 _pad3AC[0x10];
    u32 m_3bc;
    u8 _pad3C0[0x4];
    u32 m_3c4;
    u32 m_3c8;
    u8 unk_3CC[0x4];
    f32 m_3d0;
    u8 unk_3D4[0x4];
    void* m_3d8;
    u8 _pad3DC[0x8];
    u32 m_3e4;
    void load_params_from_table(s32 i);
    static void load_shared_resources();
    static void free_shared_resources();
    static void toggle_effect_render(NJS_OBJECT *);
    void advance_position();
    void init_body_sub();
    static void reset_count();
};

LAYOUT_ASSERT(TObjEneDolmOlm_size, sizeof(TObjEneDolmOlm) == 0x3E8);

extern "C" {
void *TObjEneDolmOlm__create(void *arg0);
u8 *__ct__14TObjEneDolmOlmFll(u8 *arg0, s32 arg1, s32 arg2);
s32 TObjEneDolmOlm__sub_80300CF0(void);
void TObjEneDolmOlm__sub_8030177C(void *arg0_);
void TObjEneDolmOlm__sub_80301C3C(u8 *self);
void run_task__14TObjEneDolmOlmFv(u8 *arg0_);
}

#endif
