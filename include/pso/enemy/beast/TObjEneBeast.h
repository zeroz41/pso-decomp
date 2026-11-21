#ifndef PSO_ENEMY_BEAST_TOBJENEBEAST_H
#define PSO_ENEMY_BEAST_TOBJENEBEAST_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/RenderFadeState.h"

class TObject;

struct TObjEneBeast : public TUnk_80493450 {
    TObjEneBeast(TObject *parent, void *set_data);
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
    TObject *m_3a8[2];
    RenderFadeState m_3b0[4];
    void select_subtype();
    static void *create(void *arg0);
    static void load_resources();
    void select_model_record(s32 i);
};

#include <stddef.h>
LAYOUT_ASSERT(BeastSize, sizeof(TObjEneBeast) == 0x420);
LAYOUT_ASSERT(BeastEmbeddedObjects, offsetof(TObjEneBeast, m_3b0) == 0x3B0);

void free_boss4_rock_pool(void);

#endif
