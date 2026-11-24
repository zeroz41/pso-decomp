#ifndef PSO_PLAYER_TOBJPLAYER_801D2E20_H
#define PSO_PLAYER_TOBJPLAYER_801D2E20_H

#include "types.h"
#include "pso/player/CapturedTargetList.h"
#include <dolphin/mtx.h>

class TObjPlayer;
struct PlayerAttackController;

struct Self_801D32A0 { u8 pad[0x20]; f32 f20; f32 f24; f32 f28; f32 f2c; CapturedTargetList targets; };

struct Cur_801D32A0 { u8 pad[0x28]; f32 x28; f32 x2c; f32 x30; u8 pad2[8]; f32 x3c; u8 pad3[0x5C]; u8 lock[4]; };

struct Pl_801D32A0 { u8 pad[0x424]; void *cursor; };

// --- functions of other files both player files call (no owner header yet) ---
extern "C" {
Cur_801D32A0 * TObjPlayer__sub_801B57E8(void *);
void* get_anim_field_c__10TObjPlayerFPv(void* p);
void VecCopy__FP3VecPC3Vec(void *, void *);
void * TObjPlayer__sub_80116620(void *, s32);
u16 get_action_palette_entry__10TObjPlayerFl(void *, s32);
}

extern "C" {

// --- functions defined in TObjPlayer_801D2E20.cpp ---
s32 TObjPlayer__sub_801D2EE8(s16 stage);
s16 TObjPlayer__sub_801D2F0C(void *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s32 TObjPlayer__sub_801D2F8C(s16 arg0);
void queue_physical_attack_input(PlayerAttackController *self, TObjPlayer *obj, s32 kind, s16 arg3);
void apply_anim_action__10TObjPlayerFPvi(u8 *arg0, saddr arg1);
s32 get_first_target_position__10TObjPlayerFPvPv(void *arg0, Vec *out);
void * capture_lockon_targets(Self_801D32A0 *self, Pl_801D32A0 *player);
s32 *TObjPlayer__sub_801D345C(void *p);
void handle_6x54(void);
void handle_6x8C(void);
void handle_6x65(void);
void handle_6x8B(void);
void handle_6x64(void);
}
void begin_player_attack(u8 *arg0, s32 arg1, s16 arg2, s32 arg3);

#endif
