#ifndef PSO_ENEMY_SLIME_TOBJENESLIMEWATERBOMB_H
#define PSO_ENEMY_SLIME_TOBJENESLIMEWATERBOMB_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEneSlimeWaterBomb : public TObjEnemy {
    virtual ~TObjEneSlimeWaterBomb();
    int find_nearest_enemy_masked(f32);
    virtual void run_task();
    void* m_374;
    u8 unk_378[0x4];
    f32 m_37c;
    f32 m_380;
    u8 unk_384[0x4];
    u32 m_388;
    u32 m_38c;
    u8 _pad390[0x4];
    u32 m_394;
    virtual void render();
    void *create(void *arg1);
};

typedef char TObjEneSlimeWaterBomb_size[sizeof(TObjEneSlimeWaterBomb) == 0x398 ? 1 : -1];
#endif
