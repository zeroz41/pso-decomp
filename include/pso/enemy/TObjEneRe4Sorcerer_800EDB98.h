#ifndef PSO_ENEMY_TOBJENERE4SORCERER_800EDB98_H
#define PSO_ENEMY_TOBJENERE4SORCERER_800EDB98_H

#include "types.h"
#include "pso/enemy/AreaSoundRemap.h"

struct TObjEneRe4Sorcerer;
extern "C" {
void TBoss3Volopt__sub_800F059C(void);
void *TObjEneRe4Sorcerer__ct(void *arg0, void *arg1, void *arg2);
void TObjEneRe4Sorcerer__sub_800EE0F8(u8 *arg0, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE1CC(u8 *arg0, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *arg0, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEC00(void *arg0p, void *arg1p);
s32 TObjEneRe4Sorcerer__sub_800EEDE4(void *arg0p, void *arg1p);
void TObjEneRe4Sorcerer__sub_800EEFE4(u8 *arg0, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EF214(s32 arg0);
void TObjEneRe4Sorcerer__sub_800EFE30(void);
void TObjEneRe4Sorcerer__vt85(s32 arg0p, u32 arg1, s32 arg1p);
void render__18TObjEneRe4SorcererFv(u8 *arg0);
void run_task__18TObjEneRe4SorcererFv(u8 *arg0);
s32 select_attack_target__18TObjEneRe4SorcererFiff(s32 arg0, f32 farg0, f32 farg1);
void set_motion_by_state__18TObjEneRe4SorcererFPv(void *arg0);
}

// --- C functions defined in TObjEneRe4Sorcerer_800EDB98.cpp ---
extern "C" {
void TBoss3Volopt__sub_800F059C(void);
void *TObjEneRe4Sorcerer__ct(void *ene_re4_sorcerer, void *arg1, void *arg2);
void TObjEneRe4Sorcerer__sub_800EE0F8(u8 *ene_dd, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE1CC(u8 *arg0, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *ene_re4_sorcerer, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEC00(void *arg0p, void *arg1p);
s32 TObjEneRe4Sorcerer__sub_800EEDE4(void *arg0p, void *arg1p);
void TObjEneRe4Sorcerer__sub_800EEFE4(u8 *ene_re4_sorcerer, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EF214(s32 arg0);
void TObjEneRe4Sorcerer__sub_800EFE30(void);
void TObjEneRe4Sorcerer__vt85(s32 arg0p, u32 arg1, s32 arg1p);
void render__18TObjEneRe4SorcererFv(u8 *ene_re7_berura);
void run_task__18TObjEneRe4SorcererFv(u8 *arg0);
s32 select_attack_target__18TObjEneRe4SorcererFiff(s32 arg0, f32 farg0, f32 farg1);
void set_motion_by_state__18TObjEneRe4SorcererFPv(void *ene_dd);
}
// --- end of C functions

#endif
