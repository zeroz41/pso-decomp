#ifndef PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H
#define PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"

class TObject;

struct TObjEneDimedian : public TUnk_80493450 {
    TObjEneDimedian(TObject *parent, void *set_data);
    virtual ~TObjEneDimedian();
    virtual void render();
    void load_dimedian_param_entry(s32);
    void sub_800A7B54();
    virtual void vfunc_83();
    virtual void vfunc_101();
    virtual void vfunc_99();
    virtual void vfunc_98();
    virtual void vfunc_97();
    virtual void vfunc_96();
    virtual void vfunc_95();
    virtual void vfunc_94();
    virtual void vfunc_93();
    virtual int beast_retire_corpse();
    TUnk_80490470 m_3a8;
    TObject *m_3c4[2];
    RenderFadeState m_3cc[4];
    static void *create(void *arg0);
    static void free_boss_objects();
};

LAYOUT_ASSERT(TObjEneDimedian_size, sizeof(TObjEneDimedian) == 0x43C);


#endif
