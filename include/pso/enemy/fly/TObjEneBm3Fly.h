#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLY_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLY_H

#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"

struct TObjEneBm3Fly : public TObjEneDD_ST {
    virtual ~TObjEneBm3Fly();
    virtual s32 vfunc_104(f32);
    virtual void vfunc_89();
    virtual void vfunc_88();
    void sub_800B1634();
    int was_hit_by_ranged();
    void update_collide_flag();
    void clamp_flight_height();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0xC];
    u16 m_38c;
    u8 unk_38E[0x2];
    void * m_390;
    u8 unk_394[0x4];
    f32 m_398;
    u8 unk_39C[0x10];
    f32 m_3ac;
    u8 unk_3B0[0x10];
    s32 m_3c0;
    u8 unk_3C4[0x4];
    s32 m_3c8;
    u8 unk_3CC[0x4];
    s32 m_3d0;
    u8 unk_3D4[0x4];
    s32 m_3d8;
    u8 unk_3DC[0x4];
    f32 m_3e0;
    u8 unk_3E4[0x4];
    f32 m_3e8;
    u8 unk_3EC[0x4];
    f32 m_3f0;
    u8 unk_3F4[0x4];
    f32 m_3f8;
    u8 unk_3FC[0x4];
    f32 m_400;
    u8 unk_404[0x4];
    f32 m_408;
    u8 unk_40C[0xC];
    u16 owner_id;
    u8 unknown41A[0x458 - 0x41A];
    u8* particle_effect;
    s32 alternate_phase;
    void store_position();
    s32 init_child_params();
    static void release_shared_data();
    void *create(void *arg1, void *arg2, void *arg3, void *arg4);
    static void load_resources();
    void play_pitched_cue();
    u8 unk_460[0x48];
    void handle_message(s32 arg1);
    void state_death_fall(s32 arg1);
    void update_recoil_state(s32 arg1);
    void state_circle_target(s32 arg1);
    void execute_action(s32 arg1);
    u16 get_active_id();
    s32 can_attack_target();
    void update_state_flag();
    void circle_destination(s32 arg1);
    void update_height_offset();
    void update();
};

typedef char TObjEneBm3Fly_owner_id_offset[(offsetof(TObjEneBm3Fly, owner_id) == 0x418) ? 1 : -1];
typedef char TObjEneBm3Fly_particle_effect_offset[(offsetof(TObjEneBm3Fly, particle_effect) == 0x458) ? 1 : -1];
typedef char TObjEneBm3Fly_alternate_phase_offset[(offsetof(TObjEneBm3Fly, alternate_phase) == 0x45C) ? 1 : -1];
typedef char TObjEneBm3Fly_size[sizeof(TObjEneBm3Fly) == 0x4A8 ? 1 : -1];

extern "C" {
u8 *TObjEneBm3Fly__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6);
void TObjEneBm3Fly__play_orbit_flight_sound(s32 arg0);
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B0B20(u8 *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B0F70(u8 *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B1214(u8 *arg0, s32 arg1);
void vfunc_104__13TObjEneBm3FlyFf(void *arg0, f32 farg0);
void TObjEneBm3Fly__vt103(void);
void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0);
void TObjEneBm3Fly__vt85(s32 arg0, u32 arg1, s32 arg2);
void *__dt__13TObjEneBm3FlyFv(void *arg0, s16 arg1);
void action__13TObjEneBm3FlyFPvi(u8 *arg0, s32 arg1);
f32 approach_value__13TObjEneBm3FlyFff(f32 farg0, f32 farg1);
void update_dd_flag__13TObjEneBm3FlyFPv(void *arg0);
}

// --- C functions defined in TObjEneBm3Fly.cpp ---
extern "C" {
u8 *TObjEneBm3Fly__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6);
void TObjEneBm3Fly__play_orbit_flight_sound(s32 arg0);
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B0B20(u8 *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B0F70(u8 *arg0, s32 arg1);
void TObjEneBm3Fly__sub_800B1214(u8 *arg0, s32 arg1);
void vfunc_104__13TObjEneBm3FlyFf(void *arg0, f32 farg0);
void TObjEneBm3Fly__vt103(void);
void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0);
void TObjEneBm3Fly__vt85(s32 arg0, u32 arg1, s32 msg);
void *__dt__13TObjEneBm3FlyFv(void *arg0, s16 arg1);
void action__13TObjEneBm3FlyFPvi(u8 *arg0, s32 arg1);
f32 approach_value__13TObjEneBm3FlyFff(f32 farg0, f32 farg1);
void update_dd_flag__13TObjEneBm3FlyFPv(void *arg0);
}
// --- end of C functions

#endif
