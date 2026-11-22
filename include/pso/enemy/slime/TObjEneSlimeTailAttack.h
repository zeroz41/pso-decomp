#ifndef PSO_ENEMY_SLIME_TOBJENESLIMETAILATTACK_H
#define PSO_ENEMY_SLIME_TOBJENESLIMETAILATTACK_H

#include <stddef.h>
#include "types.h"

struct NJS_OBJECT;
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
    static TObjEneSlimeTailAttack *create(saddr, const Vec *, s32, TObjEneSlimeOne *);
    void draw_blob_shadows();
    s32 sub_800E85BC();
    // The tail segment from `from` stretched towards `to`, t the segment's progress (0..1).
    void draw_stretched_segment(Vec *from, Vec *to, f32 t);
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

LAYOUT_ASSERT(SlimeTailOwnerOffset, offsetof(TObjEneSlimeTailAttack, owner) == 0x374);
LAYOUT_ASSERT(SlimeTailPoseOffset, offsetof(TObjEneSlimeTailAttack, pose) == 0x390);
LAYOUT_ASSERT(SlimeTailSize, sizeof(TObjEneSlimeTailAttack) == 0x3CC);

struct TObjEneSlimeWaterBomb;
extern "C" {
void TObjPlayer__sub_800E80C0(u8 *dst);
void TObjPlayer__sub_800E8128(NJS_OBJECT *);
void TObjPlayer__sub_800E81A8(void);
}

// lbl_80501010: layout known from its uses only.
struct RecoveredGlobal_lbl_80501010 { s32 value; u8 remaining[0x3C]; };
extern RecoveredGlobal_lbl_80501010 lbl_80501010;

#endif
