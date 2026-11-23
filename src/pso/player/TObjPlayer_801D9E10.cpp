#include "types.h"
#include "pso/player/TObjPlayer_801D9E10.h"
#include "pso/player/TObjPlayer.h"


void TObjPlayer__sub_801D9E10(Obj_801D9E10 *p, s16 v) {
    p->m_8 = v;
}

u8 *TObjPlayer__sub_801D9E18(Obj_801D9E10 *p, s32 i) {
    return p->m_20[i];
}

void TObjPlayer__sub_801D9E2C(Obj_801D9E10 *p, s16 i) {
    p->m_48[i] = 0xFF;
}

void PlayerTechniqueState::set_field_1c(f32 v) { pad_1c = v; }
void PlayerTechniqueState::set_field18(f32 v) { pad_18 = v; }
