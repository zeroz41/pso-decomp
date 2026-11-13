#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILON_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILON_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include <dolphin/mtx/GeoTypes.h>

// What TObjEnemy::movementParameters points at for the epsilon body and guard.
struct TObjEneEpsilonMovement {
    f32 m_0;
    f32 m_4;
    s32 m_8;
    s32 m_c[4];
};

struct TObjEneEpsilon : public TObjEneDD_ST {
    TObjEneEpsilon(TObject *parent);
    virtual ~TObjEneEpsilon();
    s32 update_movement_status();
    s32 is_target_in_attack_range();
    u8 pad_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 pad_380[0xC];
    u16 m_38c;
    u8 pad_38E[0x2];
    TObjCollidable *m_390;
    Vec m_394;  // target destination
    f32 m_3a0;  // m_3a0..m_3a8: m_394 - position, made unit in xz
    f32 m_3a4;
    f32 m_3a8;
    f32 m_3ac;  // the xz distance to m_394
    u8 pad_3B0[0x10];
    RenderFadeState fades[4];  // built and destroyed by TObjEneEpsilon
    void fire_attack_a(s32 arg1, s32 arg2, f32 farg0);
    void fire_attack_b(s32 arg1, s32 arg2, f32 farg0);
    void fire_attack_c(s32 arg1, s32 arg2, f32 farg0);
    s32 update_death_check();
};

#endif
