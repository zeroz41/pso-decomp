#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLEM01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLEM01_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"
#include "pso/render/RenderFadeState.h"

struct TObjMapCsn;

struct TORockJungleM01 : public TORockCaveBrakable {
    TORockJungleM01(void *set_data);
    virtual ~TORockJungleM01();
    virtual void throw_debris();
    virtual void post_draw();
    virtual void pre_draw();
    virtual void play_break_sound();
    RenderFadeState fade;
    s32 fade_active;         // fade.isFading() of the last pre_draw, 0 in split screen
    TObjMapCsn *map_csn;     // the rock's map collision
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockJungleM01_size, sizeof(TORockJungleM01) == 0xE0);

#endif
