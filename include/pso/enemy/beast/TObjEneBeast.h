#ifndef PSO_ENEMY_BEAST_TOBJENEBEAST_H
#define PSO_ENEMY_BEAST_TOBJENEBEAST_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"

struct TObjEneBeast : public TUnk_80493450 {
    virtual ~TObjEneBeast();
    void render(void *);
    void vfunc_83();
    void vfunc_101();
    void vfunc_99();
    void vfunc_98();
    void vfunc_97();
    void vfunc_96();
    void vfunc_95();
    void vfunc_94();
    void vfunc_93();
    void* m_3a8;
    void* m_3ac;
    u8 m_3b0[4][0x1C];
    void select_subtype();
    static void *create(void *arg0);
    static void load_resources();
    void select_model_record(s32 i);
};

#include <stddef.h>
typedef char BeastSize[(sizeof(TObjEneBeast) == 0x420) ? 1 : -1];
typedef char BeastEmbeddedObjects[(offsetof(TObjEneBeast, m_3b0) == 0x3B0) ? 1 : -1];

extern "C" {
void *TObjEneBeast__ct(void *arg0v, void *arg1, void *arg2);
void free_boss4_rock_pool(void);
}

#endif
