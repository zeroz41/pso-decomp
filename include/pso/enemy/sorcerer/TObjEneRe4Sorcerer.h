#ifndef PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_H
#define PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TargetCursorList.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"
#include <stddef.h>

struct TObjEneRe4Sorcerer : public TObjEneDD_ST {
    virtual ~TObjEneRe4Sorcerer();
    virtual void vfunc_88();
    virtual u8 *vfunc_101(u8 *);
    virtual u8 *vfunc_102();
    virtual void vfunc_105();
    virtual void vfunc_106();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    static void step_effect_sequence();
    void handle_death_state(s32 arg1);
    void update_state_machine(s32 reason);
    void state_wait(s32 arg1);
    s32 handle_state(s32 arg1);
    void create_effect();
    s32 cast_resta();
    s32 cast_technique();
    void turn_to_target();
    void calc_orb_positions();
    void apply_mylla_effect();
    void set_photon_state();
    s32 check_shield(TObjChara *target);
    void advance_anim_frame();
    void request_death_effect();
    s32 try_attack(f32 farg0, f32 farg1);
    void update_collision_center();
    void init_enemy();
    void create_enabled(Vec *anchor, u16 id, s32 set_index);
    void create_disabled(Vec *anchor, u16 id, s32 set_index);
    static void free_bits();
    TObjEneRe4Sorcerer *create();
    static void load_resources();
    s32 update_farthest_target(s32 arg1, f32 *arg2);

    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0xC];
    u16 m_38c;
    u8 unk_38E[0x2];
    TObjChara *m_390;
    Vec m_394;
    Vec m_3a0;
    f32 m_3ac;
    s32 m_3b0;
    u8 unk_3B4[0xC];
    s16 m_3c0;
    u8 unk_3C2[0x2];
    f32 m_3c4;
    s32 m_3c8;
    Vec bit_anchors[2];
    u16 bit_ids[2];
    s32 m_3e8;
    s32 m_3ec;
    s32 m_3f0;
    s32 m_3f4;
    f32 m_3f8;
    TUnk_80490470 fade;
    TargetCursorList targets;
    RenderFadeState fades[4];
    s32 m_4e4;
    s32 m_4e8;
    f32 m_4ec;
};

typedef char TObjEneRe4Sorcerer_m_3c0_offset[offsetof(TObjEneRe4Sorcerer, m_3c0) == 0x3C0 ? 1 : -1];
typedef char TObjEneRe4Sorcerer_bit_ids_offset[offsetof(TObjEneRe4Sorcerer, bit_ids) == 0x3E4 ? 1 : -1];
typedef char TObjEneRe4Sorcerer_fade_offset[offsetof(TObjEneRe4Sorcerer, fade) == 0x3FC ? 1 : -1];
typedef char TObjEneRe4Sorcerer_fades_offset[offsetof(TObjEneRe4Sorcerer, fades) == 0x474 ? 1 : -1];
typedef char TObjEneRe4Sorcerer_size[sizeof(TObjEneRe4Sorcerer) == 0x4F0 ? 1 : -1];

#endif
