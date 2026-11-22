#ifndef PSO_ENEMY_RECON_TOBJENERECONBOMB_H
#define PSO_ENEMY_RECON_TOBJENERECONBOMB_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

struct BmlResource;

class TObjEneRecon;

struct TObjEneReconBomb : public TObjChara {
    TObjEneReconBomb(TObject *parent, TObjEneRecon *recon, const Vec *pos);
    virtual ~TObjEneReconBomb();
    virtual void render();
    virtual void run_task();
    static void release_resources();
    static void *create(void *parent, void *recon, void *pos);
    static void load_resources();
    s32 has_player_nearby();

    TObjEneRecon *owner;  // the Recon that dropped it; its blast hits players in the owner's name
    u16 owner_id;         // get_entity_id(owner)
    u8 pad_33A[0x2];
    Vec velocity;         // starts at launch_speed along the owner's heading; gravity 0.1, drag 0.95
    f32 ground_y;         // height of the ground under it; the blob shadow sits there
    f32 blast_radius;     // players within it (xz) take the blast
    f32 blast_power;      // DirectAttackPayload power of the blast
    f32 launch_speed;
    s32 lifetime;         // frames before it goes off by itself
    s32 state;            // 0 falling, 1 bouncing, 2 resting until a player comes near, 3 blast
    s32 age;              // frames since the drop
};

LAYOUT_ASSERT(TObjEneReconBomb_size, sizeof(TObjEneReconBomb) == 0x364);

#endif
