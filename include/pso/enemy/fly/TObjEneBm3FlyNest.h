#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H

#include "types.h"
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/render/RenderFadeState.h"

struct BmlResource;

// The motion binding the fly and the nest pass to TLobby::spawn_npc_enemy.
struct Bm3FlyAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u32 unknown_0C;  // the action count in the high half
};

struct TObjEneBm3FlyNest : public TObjEneDD {
    virtual ~TObjEneBm3FlyNest();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
    // Slot 104, the first one TObjEneDD leaves to its subclasses (dispatch_action's state-0 handler).
    virtual void init(void *);
    virtual void render_with_state_debug();
    virtual void render_shadows();
    void init_params();
    void state_initial_emit(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    static void capture_attachment(void * _w0);
    void remove_child(u8 *child);
    s32 has_free_attack_slot(u16 id);
    void spawn_child();
    void update_replenish();
    void copy_pos();
    static void free_fly();
    static void *create(void *arg0);
    static void load_resources();
    static void init_vertex_table();
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0xC];
    s32 m_38c;
    s32 m_390;
    s32 m_394;
    s32 m_398[4];
    s32 m_3a8;
    s32 m_3ac;
    s32 m_3b0;
    s32 m_3b4;
    u16 m_3b8[6];
    u16 m_3c4;
    u8 unk_3C6[0x2];
    Vec m_3c8[2];
    Vec m_3e0[8];
    RenderFadeState m_440[4];
    f32 m_4b0;
    s32 m_4b4;
    s32 m_4b8;
    s32 m_4bc;
    s32 m_4c0;
    s32 m_4c4;
    s32 m_4c8;
    s32 m_4cc;
    s32 m_4d0;
    s32 m_4d4;
    f32 m_4d8;
};

typedef char TObjEneBm3FlyNest_size[sizeof(TObjEneBm3FlyNest) == 0x4DC ? 1 : -1];
typedef char TObjEneBm3FlyNest_m_3b0_offset[offsetof(TObjEneBm3FlyNest, m_3b0) == 0x3B0 ? 1 : -1];
typedef char TObjEneBm3FlyNest_m_440_offset[offsetof(TObjEneBm3FlyNest, m_440) == 0x440 ? 1 : -1];
typedef char TObjEneBm3FlyNest_m_4d8_offset[offsetof(TObjEneBm3FlyNest, m_4d8) == 0x4D8 ? 1 : -1];

extern "C" {
u8 *__ct__26TObjEneBm3FlyNest_CarryFlyFP7TObjectlllll(u8 *self, void *parent, s32 a, s32 b, s32 unused, s32 c, s32 d);
TObjEneBm3FlyNest *TObjEneBm3FlyNest__ct(TObjEneBm3FlyNest *nest, TObject *parent, void *set_data);
Vec *TObjEneBm3FlyNest__sub_800B2A54(TObjEneBm3FlyNest *nest);
void TObjEneBm3FlyNest__sub_800B318C(TObjEneBm3FlyNest *nest, s32 arg1);
s32 TObjEneBm3FlyNest__sub_800B3AC8(TObjEneBm3FlyNest *nest);
BmlResource *TObjEneBm3FlyNest__sub_800B4158(void);
void *__dt__26TObjEneBm3FlyNest_CarryFlyFv(void *arg0, s16 arg1);
s32 copy_target_state__17TObjEneBm3FlyNestFPv(TObjEneBm3FlyNest *nest, s32 sound_id);
void dispatch_state__17TObjEneBm3FlyNestFiUii(TObjEneBm3FlyNest *nest, u32 arg1, s32 arg2);
void handle_appear__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void handle_attachment_sample__17TObjEneBm3FlyNestFi(s32 arg0);
void handle_event__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void handle_motion_event__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void handle_state__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void render__17TObjEneBm3FlyNestFv(u8 *arg0);
void run_task__17TObjEneBm3FlyNestFv(u8 *arg0);
void state_dying__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void state_spawn__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void state_wait__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
void update_state__17TObjEneBm3FlyNestFPvi(TObjEneBm3FlyNest *nest, s32 arg1);
}

#endif
