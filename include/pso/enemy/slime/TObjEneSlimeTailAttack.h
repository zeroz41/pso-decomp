#ifndef PSO_ENEMY_SLIME_TOBJENESLIMETAILATTACK_H
#define PSO_ENEMY_SLIME_TOBJENESLIMETAILATTACK_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEneSlimeTailAttack : public TObjEnemy {
    virtual ~TObjEneSlimeTailAttack();
    void draw_stretched_segment(void *, void *, f32);
    void sub_800E841C();
    virtual void run_task();
    virtual void render();
    int find_nearest_enemy_with_flag(f32);
};

struct TObjEneSlimeOne;
struct TObjEneSlimeWaterBomb;
extern "C" {
u8 *TObjEneSlimeOne__ct(u8 *actor, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void *TObjEneSlimeTailAttack__ct(TObjEneSlimeTailAttack *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
void *TObjEneSlimeWaterBomb__ct(TObjEneSlimeWaterBomb *arg0, void *arg1, void *arg2);
void TObjPlayer__sub_800E80C0(u8 *dst);
void TObjPlayer__sub_800E8128(void);
void TObjPlayer__sub_800E81A8(void);
void sub_800E841C__22TObjEneSlimeTailAttackFv(u8 *arg0);
void render__22TObjEneSlimeTailAttackFv(u8 *arg0);
void run_task__22TObjEneSlimeTailAttackFv(u8 *arg0);
void *__dt__15TObjEneSlimeOneFv(void *arg0, s16 arg1);
void *__dt__21TObjEneSlimeWaterBombFv(void *arg0, s16 arg1);
void *create__22TObjEneSlimeTailAttackFiiii(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void *dt__22TObjEneSlimeTailAttackFPvs(void *arg0, s16 arg1);
void fn_800E9238(s32 arg0);
u8 *init__15TObjEneSlimeOneFPviii(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void initialize_slime_instance_state__15TObjEneSlimeOneFv(u8 *actor);
void render__15TObjEneSlimeOneFv(TObjEneSlimeOne *arg0);
void set_display_mode__15TObjEneSlimeOneFPvi(void *arg0, s32 arg1);
void set_random_timer__15TObjEneSlimeOneFPvii(void *arg0, s32 arg1, s32 arg2);
s32 try_spawn_child__15TObjEneSlimeOneFPv(int origin, void *arg1);
}
extern "C" {
}
s32 water_bomb_hit_nearby(u8 *target);

#endif
