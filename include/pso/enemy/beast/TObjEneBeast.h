#ifndef PSO_ENEMY_BEAST_TOBJENEBEAST_H
#define PSO_ENEMY_BEAST_TOBJENEBEAST_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"

struct TObjEneBeast : public TUnk_80493450 {
    virtual ~TObjEneBeast();
    virtual void render();
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
LAYOUT_ASSERT(BeastSize, sizeof(TObjEneBeast) == 0x420);
LAYOUT_ASSERT(BeastEmbeddedObjects, offsetof(TObjEneBeast, m_3b0) == 0x3B0);

extern "C" {
void *TObjEneBeast__ct(void *arg0v, void *arg1, void *arg2);
}
void free_boss4_rock_pool(void);

#endif
