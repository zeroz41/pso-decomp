#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLEL01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLEL01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;

struct TORockJungleL01 : public TORockCave {
    TORockJungleL01(void *set_data);
    virtual ~TORockJungleL01();
    virtual void vfunc_15();
    virtual void vfunc_14();
    virtual void run_task();
    RenderFadeState fade;
    s32 fade_active;         // fade.isFading() of the last vfunc_14, 0 in split screen
    TObjMapCsn *map_csn;     // the rock's map collision
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockJungleL01_size, sizeof(TORockJungleL01) == 0xD8);

#endif
