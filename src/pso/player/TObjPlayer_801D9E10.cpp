#include "types.h"
#include "pso/player/TObjPlayer_801D9E10.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void TObjPlayer__sub_801D9E10(Obj_801D9E10 *p, s16 v) {
    p->m_8 = v;
}

u8 *TObjPlayer__sub_801D9E18(Obj_801D9E10 *p, s32 i) {
    return p->m_20[i];
}

void TObjPlayer__sub_801D9E2C(Obj_801D9E10 *p, s16 i) {
    p->m_48[i] = 0xFF;
}
}

void TObjPlayer::set_field_1c(f32 v) { *(f32*)((char*)this + 0x1c) = v; }
void TObjPlayer::set_field18(f32 v) { *(f32*)((char*)this + 0x18) = v; }
