#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_EASTEREGG_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_EASTEREGG_H

#include "types.h"
#include "pso/object/TObjCitySeasonBase.h"

class TParticleCtrl;

struct TObjCity_Season_EasterEgg : public TObjCitySeasonBase {
    static const char *class_name;
    TObjCity_Season_EasterEgg(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjCity_Season_EasterEgg();
    virtual void render();
    virtual void run_task();

    // Stepped by 2 and wrapped at 0xFF each frame like the board's uv_scroll,
    // never read.
    s32 uv_scroll;
    // Particle emitter created at the decoration (create_particle_emitter id
    // 0x90) and queued for destruction by the destructor (name inferred).
    TParticleCtrl *emitter;
    // Second emitter, 25 units above the egg (id 0x91; name inferred).
    TParticleCtrl *upper_emitter;
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_EasterEgg_size, sizeof(TObjCity_Season_EasterEgg) == 0xC0);
#endif
