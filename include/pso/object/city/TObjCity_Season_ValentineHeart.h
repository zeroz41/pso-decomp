#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_VALENTINEHEART_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_VALENTINEHEART_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

class TParticleCtrl;

struct TObjCity_Season_ValentineHeart : public TUnk_804B5E48 {
    TObjCity_Season_ValentineHeart(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_ValentineHeart();
    virtual void render();
    virtual void run_task();

    // Particle emitter created at the decoration (create_particle_emitter id
    // 0x90) and queued for destruction by the destructor (name inferred).
    TParticleCtrl *emitter;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_ValentineHeart_size, sizeof(TObjCity_Season_ValentineHeart) == 0xB8);
#endif
