#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_SONICADV2_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_SONICADV2_H

#include "types.h"
#include "pso/object/TObjCitySeasonBase.h"

struct TObjCity_Season_SonicAdv2 : public TObjCitySeasonBase {
    TObjCity_Season_SonicAdv2(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_SonicAdv2();
    virtual void debug_draw_model_index();
    s32 sub_80183C38();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_SonicAdv2_size, sizeof(TObjCity_Season_SonicAdv2) == 0xB4);
#endif
