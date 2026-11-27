#ifndef PSO_ENEMY_SLIME_TOBJENESLIME_H
#define PSO_ENEMY_SLIME_TOBJENESLIME_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/EnemyPlacement.h"

struct TObjEneSlimeOne;

struct SlimeChildSlot {
    s32 state;
    TObjEneSlimeOne *slime;
};

// The spawner's placement; the split slimes get copies numbered up from its enemy_index
// and id, with child_count 0. Copied whole, as 0x40 bytes.
union SlimeSpawnTemplate {
    EnemyPlacement entry;
    u8 bytes[0x40];
};

struct TObjEneSlime : public TObjEnemy {
    TObjEneSlime(TObject *parent, EnemyPlacement *set_data);
    virtual ~TObjEneSlime();
    virtual void run_death_reaction();
    SlimeSpawnTemplate spawn_template;
    s32 child_limit;
    SlimeChildSlot child_slots[4];
    s32 try_spawn_child(Vec *position);
    void release_child_slot(s32 id);
    void release_split_slimes();
    // 1 when no child slot holds a live slime (state 1).
    s32 has_no_active_slot();
    virtual void render();
    virtual void run_task();
    static void free_instance();
    static void spawn_pair();
    static void *create(EnemyPlacement *set_data);
    void init_slots();
};

LAYOUT_ASSERT(TObjEneSlime_size, sizeof(TObjEneSlime) == 0x3D8);

// Copies a child slot; init_slots empties the slots from slime_empty_child_slot.
void copy_child_slot(SlimeChildSlot *dst, SlimeChildSlot *src);

#endif
