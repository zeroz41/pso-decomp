#ifndef PSO_BOSS_DARKFALZ_TOBJDFHORMING_H
#define PSO_BOSS_DARKFALZ_TOBJDFHORMING_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TParticleCtrl;

struct TObjDFHorming : public TObjChara {
    TObjDFHorming(TObject *parent, const Vec *position, u16 target_id);
    virtual ~TObjDFHorming();
    void sub_8005076C();
    void check_attack_trigger();
    virtual void run_task();
    u16 m_334; // client id of the player it homes on
    u8 _pad336[0x2];
    u32 m_338;
    Vec spawn_position;        // copied with prev_position and m_2fc from the spawn point
    Vec velocity;              // normalised and scaled by speed each frame, added to m_2fc
    f32 speed;
    TParticleCtrl *effects[2]; // create_particle_emitter per TObjDFJisin__particle_emitter_id_table entry
    u32 m_360;
    f32 homing_rate;           // 0..1 from the shared table, sets how hard it turns (steer_homing_direction)
    u32 m_368;
    void* m_36c;
    u8 unk_370[0x8];
    f32 m_378;
    u8 unk_37C[0x4];
    static s32 is_boss_active();
};

LAYOUT_ASSERT(TObjDFHorming_velocity_offset, offsetof(TObjDFHorming, velocity) == 0x348);
LAYOUT_ASSERT(TObjDFHorming_effects_offset, offsetof(TObjDFHorming, effects) == 0x358);
LAYOUT_ASSERT(TObjDFHorming_size, sizeof(TObjDFHorming) == 0x380);

struct TBoss4DarkFalz;
extern "C" {
int TBoss4DarkFalz__sub_8004B07C(TBoss4DarkFalz *);
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
void TBoss4DarkFalz__sub_8004B5A0(void);
void TBoss4DarkFalz__sub_8004B7DC(TBoss4DarkFalz *boss4_dark_falz);
void TBoss4DarkFalz__sub_8004B8F8(TBoss4DarkFalz *boss4_dark_falz);
}

// --- C functions defined in TObjDFHorming.cpp ---
extern "C" {
int TBoss4DarkFalz__sub_8004B07C(TBoss4DarkFalz *);
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
void TBoss4DarkFalz__sub_8004B5A0(void);
void TBoss4DarkFalz__sub_8004B7DC(TBoss4DarkFalz *boss4_dark_falz);
void TBoss4DarkFalz__sub_8004B8F8(TBoss4DarkFalz *boss4_dark_falz);
}
// --- end of C functions

#endif
