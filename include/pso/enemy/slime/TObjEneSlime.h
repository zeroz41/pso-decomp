#ifndef PSO_ENEMY_SLIME_TOBJENESLIME_H
#define PSO_ENEMY_SLIME_TOBJENESLIME_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEneSlime : public TObjEnemy {
    virtual ~TObjEneSlime();
    virtual void vfunc_63();
    void* m_374;
    u8 _pad378[0x3C];
    u32 m_3b4;
    void release_split_slimes();
    virtual void render();
    virtual void run_task();
    static void free_instance();
    static void spawn_pair();
    static s32 create(s32 arg0);
    static void spawn_child(s16 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
    void init_slots();
};

typedef char TObjEneSlime_size[sizeof(TObjEneSlime) == 0x3B8 ? 1 : -1];

extern "C" {
void TObjEneSlime__sub_800EB9F0(void *p, void *q);
}

#endif
