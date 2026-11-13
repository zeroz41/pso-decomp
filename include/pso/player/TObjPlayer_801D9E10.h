#ifndef PSO_PLAYER_TOBJPLAYER_801D9E10_H
#define PSO_PLAYER_TOBJPLAYER_801D9E10_H

#include "types.h"

struct Obj_801D9E10 {
    u8 pad_0[0x8];
    s16 m_8;
    u8 pad_A[0x18 - 0xA];
    f32 m_18;
    f32 m_1C;
    u8 m_20[10][4];
    u8 m_48[0x13];
};

extern "C" {
void TObjPlayer__sub_801D9E10(Obj_801D9E10 *p, s16 v);
u8 *TObjPlayer__sub_801D9E18(Obj_801D9E10 *p, s32 i);
void TObjPlayer__sub_801D9E2C(Obj_801D9E10 *p, s16 i);
}

#endif
