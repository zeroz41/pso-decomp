#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_SONICADV2_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_SONICADV2_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

struct TObjCity_Season_SonicAdv2 : public TUnk_804B5E48 {
    virtual ~TObjCity_Season_SonicAdv2();
    virtual void debug_draw_model_index();
    s32 sub_80183C38();
    virtual void render();
    virtual void run_task();
    void *dt(s16 arg1);
};

typedef char TObjCity_Season_SonicAdv2_size[sizeof(TObjCity_Season_SonicAdv2) == 0xB4 ? 1 : -1];
#endif
