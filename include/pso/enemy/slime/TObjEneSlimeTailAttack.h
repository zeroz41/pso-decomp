#ifndef PSO_ENEMY_SLIME_TOBJENESLIMETAILATTACK_H
#define PSO_ENEMY_SLIME_TOBJENESLIMETAILATTACK_H

#include <stddef.h>
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEneSlimeOne;
struct NJS_OBJECT;

struct SlimeTailPose {
    Vec attachment;
    Vec shadows[4];
};

struct TObjEneSlimeTailAttack : public TObjEnemy {
    TObjEneSlimeTailAttack(TObject *parent, const Vec *position, s32 angle, TObjEneSlimeOne *owner);
    virtual ~TObjEneSlimeTailAttack();
    static TObjEneSlimeTailAttack *create(s32, const Vec *, s32, TObjEneSlimeOne *);
    void draw_blob_shadows();
    s32 sub_800E85BC();
    void draw_stretched_segment(void *, void *, f32);
    void sub_800E841C();
    virtual void run_task();
    virtual void render();
    int find_nearest_enemy_with_flag(f32);

    TObjEneSlimeOne *owner;
    s32 active;
    s32 last_hit_player;
    Vec stretch_scale;
    f32 fade;
    SlimeTailPose pose;
};

typedef char SlimeTailOwnerOffset[offsetof(TObjEneSlimeTailAttack, owner) == 0x374 ? 1 : -1];
typedef char SlimeTailPoseOffset[offsetof(TObjEneSlimeTailAttack, pose) == 0x390 ? 1 : -1];
typedef char SlimeTailSize[sizeof(TObjEneSlimeTailAttack) == 0x3CC ? 1 : -1];

struct TObjEneSlimeWaterBomb;
extern "C" {
void TObjPlayer__sub_800E80C0(u8 *dst);
void TObjPlayer__sub_800E8128(void);
void TObjPlayer__sub_800E81A8(void);
void sub_800E841C__22TObjEneSlimeTailAttackFv(u8 *arg0);
void render__22TObjEneSlimeTailAttackFv(u8 *arg0);
void run_task__22TObjEneSlimeTailAttackFv(u8 *arg0);
void *__dt__15TObjEneSlimeOneFv(void *arg0, s16 arg1);
void *__dt__21TObjEneSlimeWaterBombFv(void *arg0, s16 arg1);
void initialize_slime_instance_state__15TObjEneSlimeOneFv(u8 *actor);
}

// lbl_80501010: layout known from its uses only.
struct RecoveredGlobal_lbl_80501010 { s32 value; u8 remaining[0x3C]; };
extern RecoveredGlobal_lbl_80501010 lbl_80501010;

#endif
