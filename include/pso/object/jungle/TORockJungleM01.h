#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLEM01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLEM01_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;

struct TORockJungleM01 : public TORockCaveBrakable {
    TORockJungleM01(void *set_data);
    virtual ~TORockJungleM01();
    virtual void vfunc_16();
    virtual void vfunc_15();
    virtual void vfunc_14();
    virtual void vfunc_18();
    RenderFadeState fade;
    s32 fade_active;         // fade.isFading() of the last vfunc_14, 0 in split screen
    TObjMapCsn *map_csn;     // the rock's map collision
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockJungleM01_size, sizeof(TORockJungleM01) == 0xE0);

#endif
