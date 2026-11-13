#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLY_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLY_H

#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"

class TParticleCtrl;
struct TObjEneBm3FlyNest;

// TObjEnemy::movementParameters of a fly or its nest (same layout as MojaMovementParameters).
struct Bm3FlyMovementParameters {
    f32 unknown_00;
    f32 unknown_04;
    s32 unknown_08;
    u32 unknown_0C[4];
};

// The block TLobby::dispatch_shared_handler_a(0) returns; the fly's load_resources keeps it in lbl_805D50EC.
struct Bm3FlyParameters {
    f32 unknown_00;
    u8 unknown_04[0x18];
    s32 unknown_1C;
};

// The motion binding the fly and the nest pass to TLobby::spawn_npc_enemy.
struct Bm3FlyAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

// One entry collect_enemy_target_candidates fills in.
struct EnemyTargetCandidate {
    u16 id;
    f32 dist;
};

struct TObjEneBm3Fly : public TObjEneDD_ST {
    virtual ~TObjEneBm3Fly();
    virtual s32 vfunc_104(f32);
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_89();
    virtual void vfunc_88();
    void handle_message(s32 arg1);
    void state_death_fall(s32 arg1);
    void update_recoil_state(s32 arg1);
    void state_circle_target(s32 arg1);
    void execute_action(s32 arg1);
    void play_pitched_cue();
    u16 get_active_id();
    void sub_800B1634();
    s32 can_attack_target();
    f32 approach_value(f32 current, f32 target);
    int was_hit_by_ranged();
    void clamp_flight_height();
    void store_position();
    void update_state_flag();
    void update_collide_flag();
    void circle_destination(s32 arg1);
    void update_height_offset();
    void update();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    void init_child_params();
    static void release_shared_data();
    void *create(void *arg1, void *arg2, void *arg3, void *arg4);
    static void load_resources();

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
    u8 unk_3B0[0x10];
    s32 m_3c0;
    s32 m_3c4;
    s32 m_3c8;
    s32 m_3cc;
    s32 m_3d0;
    s32 m_3d4;
    s32 m_3d8;
    s32 m_3dc;
    f32 m_3e0;
    f32 m_3e4;
    Vec m_3e8;
    Vec m_3f4;
    Vec m_400;
    Vec m_40c;
    u16 owner_id;
    u8 unk_41A[0x2];
    Vec m_41c;
    s32 m_428;
    f32 m_42c;
    Vec m_430;
    f32 m_43c;
    s32 m_440;
    f32 m_444;
    s32 m_448;
    f32 m_44c;
    f32 m_450;
    s32 m_454;
    TParticleCtrl *particle_effect;
    s32 alternate_phase;
    u8 unk_460[0x48];
};

typedef char TObjEneBm3Fly_owner_id_offset[(offsetof(TObjEneBm3Fly, owner_id) == 0x418) ? 1 : -1];
typedef char TObjEneBm3Fly_particle_effect_offset[(offsetof(TObjEneBm3Fly, particle_effect) == 0x458) ? 1 : -1];
typedef char TObjEneBm3Fly_alternate_phase_offset[(offsetof(TObjEneBm3Fly, alternate_phase) == 0x45C) ? 1 : -1];
typedef char TObjEneBm3Fly_size[sizeof(TObjEneBm3Fly) == 0x4A8 ? 1 : -1];

extern "C" {
TObjEneBm3Fly *TObjEneBm3Fly__ct(TObjEneBm3Fly *fly, TObject *parent, TObjEneBm3FlyNest *nest, s32 entity_id, s32 set_index, const Vec *position, const Vec *arg6);
void TObjEneBm3Fly__play_orbit_flight_sound(TObjEneBm3Fly *fly);
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B0B20(TObjEneBm3Fly *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B0F70(TObjEneBm3Fly *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B1214(TObjEneBm3Fly *arg0, s32 arg1);
void vfunc_104__13TObjEneBm3FlyFf(void *arg0, f32 farg0);
void TObjEneBm3Fly__vt103(void);
void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0);
void TObjEneBm3Fly__vt85(TObjEneBm3Fly *fly, u32 arg1, s32 arg2);
TObjEneBm3Fly *__dt__13TObjEneBm3FlyFv(TObjEneBm3Fly *fly, s16 arg1);
void action__13TObjEneBm3FlyFPvi(TObjEneBm3Fly *arg0, s32 arg1);
void update_dd_flag__13TObjEneBm3FlyFPv(TObjEneBm3Fly *fly, f32 x, f32 z, f32 speed);
}


#endif
