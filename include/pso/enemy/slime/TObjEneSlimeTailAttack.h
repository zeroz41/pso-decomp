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
    // Hits the players and flagged enemies near body_center during frames 17..30; 1 on a hit.
    s32 apply_tail_hits();
    // The tail segment from `from` stretched towards `to`, t the segment's progress (0..1).
    void draw_stretched_segment(Vec *from, Vec *to, f32 t);
    // Draws the tail model; the node callback captures pose for the shadows and body_center.
    void draw_body();
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
// The tail model's node callback (set_chunk_model_node_callback): counts the nodes drawn and
// stores the view-space origins of nodes 4..7 in slime_tail_node_capture's shadows, node 7's also
// in its attachment.
void capture_slime_tail_node(NJS_OBJECT *);
void reset_slime_tail_node_index(void);
void get_slime_tail_pose(SlimeTailPose *dst);
SlimeTailPose *copy_slime_tail_pose(SlimeTailPose *dst, SlimeTailPose *src);
}

// The node callback's scratch pose; draw_body copies it into pose (get_slime_tail_pose).
struct SlimeTailNodeCapture {
    SlimeTailPose pose;
    u8 pad_3C[0x4];
};
extern SlimeTailNodeCapture slime_tail_node_capture;

#endif
