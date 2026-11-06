#ifndef PSO_BOSS_BARBARAY_BOSS7DEROLLECBEHAVIOR_H
#define PSO_BOSS_BARBARAY_BOSS7DEROLLECBEHAVIOR_H

#include "types.h"

struct TObjEneDD;
extern "C" {
void TBoss7DeRolLeC__dispatch_state(u8 *arg0, u32 arg1, u32 arg2);
void TBoss7DeRolLeC__handle_crawfish_spawn_state(u8 *self, u32 event, s32 variant);
void TBoss7DeRolLeC__sub_802EC994(void *p);
s32 TBoss7Joint_get_shell_max_hp(void);
void TBoss7LaserPtcl__sub_802E8FCC(u8 *arg0, u32 arg1);
void TBoss7LaserPtcl__sub_802ECE28(u8 *arg0);
void TBoss7PhotonBullet__sub_802ED5A0(void *arg0, int arg1);
void TObjFish__sub_802E8528(void *o, u32 k);
void TObjFish__sub_802E8584(void *o, u32 k);
void TObjFish__sub_802E85E0(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E88F8(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8990(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8E34(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8EEC(u8 *arg0, u32 arg1, s32 _w2);
void TObjFish__sub_802E9458(u8 *arg0, u32 arg1);
void TObjFish__sub_802E95F8(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802EA4D8(u8 *arg0, u32 arg1);
void TObjFish__sub_802EAAC8(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
void TObjFish__sub_802EBBC8(u8 *arg0, u32 arg1);
void TObjFish__sub_802EBE50(void *o, u32 k);
void TObjFish__sub_802EC32C(void);
void TObjFish__sub_802EC468(s32 arg0, f32 farg0, f32 farg1);
f32 TObjFish__sub_802ED3E4(u8 *arg0);
void TObjFish__sub_802ED4AC(u8 *arg0, s32 arg1);
void TObjPlayer__sub_802E7F30(void *unused, s32 arg1);
void TObjPlayer__sub_802E80A0(void);
void render__14TBoss7DeRolLeCFv(u8 *unused);
void TObjPlayer__sub_802E8274(void);
void fn_802EC52C(s32 arg0, s32 arg1);
void fn_802EC9A4(void *arg0, void *arg1);
void fn_802EC9F0(TObjEneDD *arg0, void *arg1);
void free_laser_light__15TBoss7LaserPtclFv(void *arg0);
}
void handle_6xA9_barba_ray_boss_actions(void *arg0);
void handle_6xAA_barba_ray_boss_actions(void *arg0);
extern "C" {
void queue_boss_effect__10TObjPlayerFPv(void *a0);
void release_laser_light__15TBoss7LaserPtclFPv(void *arg0);
void set_swim_direction__8TObjFishFPv(void *arg0);
void spawn_particle_201__8TObjFishFii(s32 arg1, s32 arg2);
}

#endif
