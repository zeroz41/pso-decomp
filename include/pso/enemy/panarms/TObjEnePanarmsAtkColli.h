#ifndef PSO_ENEMY_PANARMS_TOBJENEPANARMSATKCOLLI_H
#define PSO_ENEMY_PANARMS_TOBJENEPANARMSATKCOLLI_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEnePanarmsAtkColli : public TObjEnemy {
    virtual ~TObjEnePanarmsAtkColli();
    void sub_800E32C0(void *);
    u32 m_374;
    u8 unk_378[0x4];
    f32 m_37c;
    u32 m_380;
    u32 m_384;
    u32 m_388;
    virtual void run_task();
    void *create(void *arg1, void *arg2, void *arg3);
    u8 unk_38C[0x4];
};

typedef char TObjEnePanarmsAtkColli_size[sizeof(TObjEnePanarmsAtkColli) == 0x390 ? 1 : -1];
#endif
