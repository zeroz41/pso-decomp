#ifndef PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_800EDB98_H
#define PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_800EDB98_H

#include "types.h"
#include "pso/enemy/AreaSoundRemap.h"

struct TObjEneRe4Sorcerer;
extern "C" {
void TBoss3Volopt__sub_800F059C(void);
TObjEneRe4Sorcerer *TObjEneRe4Sorcerer__ct(TObjEneRe4Sorcerer *self, void *arg1, void *arg2);
void TObjEneRe4Sorcerer__sub_800EE0F8(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE1CC(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *arg0, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEC00(TObjEneRe4Sorcerer *self, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEDE4(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EEFE4(TObjEneRe4Sorcerer *self, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EF214(TObjEneRe4Sorcerer *self);
void TObjEneRe4Sorcerer__sub_800EFE30(void);
void TObjEneRe4Sorcerer__vt85(TObjEneRe4Sorcerer *self, u32 state, s32 reason);
s32 select_attack_target__18TObjEneRe4SorcererFiff(TObjEneRe4Sorcerer *self, f32 farg0, f32 farg1);
void set_motion_by_state__18TObjEneRe4SorcererFPv(TObjEneRe4Sorcerer *self);
}

#endif
