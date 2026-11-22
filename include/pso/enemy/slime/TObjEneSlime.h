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
        s16 field_00;
        s16 field_02;
        s16 field_04;
        u16 field_06;
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
    static void spawn_child(s16 id, s32 model, s32 texlist, f32 radius, f32 y_offset);
    void init_slots();
};

LAYOUT_ASSERT(TObjEneSlime_size, sizeof(TObjEneSlime) == 0x3D8);

extern "C" {
void TObjEneSlime__sub_800EB9F0(void *p, void *q);
}

#endif
