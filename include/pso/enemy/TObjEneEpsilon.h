#ifndef PSO_ENEMY_TOBJENEEPSILON_H
#define PSO_ENEMY_TOBJENEEPSILON_H

#include "types.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/misc/RenderFadeState.h"

struct TObjEneEpsilon : public TObjEneDD_ST {
    TObjEneEpsilon(TObject *parent);
    virtual ~TObjEneEpsilon();
    s32 update_movement_status();
    s32 is_target_in_attack_range();
    u8 unk_374[0x8];
    f32 m_37c;
    u8 unk_380[0xC];
    u16 m_38c;
    u8 unk_38E[0x2];
    u32 m_390;
    u8 unk_394[0xC];
    f32 m_3a0;
    u8 unk_3A4[0x1C];
    RenderFadeState fades[4];  // built and destroyed by TObjEneEpsilon
    void fire_attack_a(s32 arg1, s32 arg2, f32 farg0);
    void fire_attack_b(s32 arg1, s32 arg2, f32 farg0);
    void fire_attack_c(s32 arg1, s32 arg2, f32 farg0);
    s32 update_death_check();
};

#endif
