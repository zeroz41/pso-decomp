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
    RenderFadeState fades[4];  // built and destroyed by TObjEneEpsilon
    void fire_attack_a(saddr arg1, s32 arg2, f32 farg0);
    void fire_attack_b(saddr arg1, s32 arg2, f32 farg0);
    void fire_attack_c(saddr shot_pos, s32 arg2, f32 scale);
    s32 update_death_check();
};

#endif
