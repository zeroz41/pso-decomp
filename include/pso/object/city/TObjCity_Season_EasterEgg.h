#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_EASTEREGG_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_EASTEREGG_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

class TParticleCtrl;

struct TObjCity_Season_EasterEgg : public TUnk_804B5E48 {
    TObjCity_Season_EasterEgg(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_EasterEgg();
    virtual void render();
    virtual void run_task();

    s32 unk_B4;
    // Particle emitter created at the decoration (create_particle_emitter id
    // 0x90) and queued for destruction by the destructor (name inferred).
    TParticleCtrl *emitter;
    // Second emitter, 25 units above the egg (id 0x91; name inferred).
    TParticleCtrl *upper_emitter;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_EasterEgg_size, sizeof(TObjCity_Season_EasterEgg) == 0xC0);
#endif
