#ifndef PSO_ENEMY_SLIME_TOBJENESLIME_H
#define PSO_ENEMY_SLIME_TOBJENESLIME_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEneSlimeOne;

struct SlimeChildSlot {
    s32 state;
    TObjEneSlimeOne *slime;
};

union SlimeSpawnTemplate {
    struct {
        s16 set_index;    // the split slimes' set indices count up from the spawner's
        s16 child_count;  // the spawner's child_limit (1..4); 0 for the split slimes
        u8 pad_04[0x2];
        u16 entity_id;    // the split slimes' entity ids count up from the spawner's
        u8 pad8[8];
        Vec position;
        u8 rest[0x40 - 0x1C];
    } entry;
    u8 bytes[0x40];
};

struct TObjEneSlime : public TObjEnemy {
    TObjEneSlime(TObject *parent, u8 *set_data);
    virtual ~TObjEneSlime();
    virtual void run_death_reaction();
    SlimeSpawnTemplate spawn_template;
    s32 child_limit;
    SlimeChildSlot child_slots[4];
    s32 try_spawn_child(void *position);
    void release_child_slot(s32 id);
    void release_split_slimes();
    virtual void render();
    virtual void run_task();
    static void free_instance();
    static void spawn_pair();
    static s32 create(saddr set_data);
    void init_slots();
};

LAYOUT_ASSERT(TObjEneSlime_size, sizeof(TObjEneSlime) == 0x3D8);

// Copies a child slot; init_slots empties the slots from slime_empty_child_slot.
void copy_child_slot(SlimeChildSlot *dst, SlimeChildSlot *src);

#endif
