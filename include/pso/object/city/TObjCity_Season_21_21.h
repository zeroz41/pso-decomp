#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_21_21_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_21_21_H

#include "types.h"
#include "pso/object/city/TObjCitySeasonBase.h"

class TParticleCtrl;

struct TObjCity_Season_21_21 : public TObjCitySeasonBase {
    static const char *class_name;
    TObjCity_Season_21_21(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjCity_Season_21_21();
    virtual void render();
    virtual void run_task();

    // UV offset: run_task steps it by 2 and wraps at 0xFF, render hands it to
    // StripBufferPair::scroll_uvs.
    s32 uv_scroll;
    // Particle emitter created at the decoration (create_particle_emitter id
    // 0x90) and queued for destruction by the destructor (name inferred).
    TParticleCtrl *emitter;
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_21_21_size, sizeof(TObjCity_Season_21_21) == 0xBC);
#endif
