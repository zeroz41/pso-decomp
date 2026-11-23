#ifndef PSO_EFFECT_PHOTON_TPHOTONRAINBOW_H
#define PSO_EFFECT_PHOTON_TPHOTONRAINBOW_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;

// The two counter-rotating rainbow rings a photon blast summon raises over the
// field; they follow the camera on x and z. Boss arenas use models 6 and 8 of
// the shared photon blast resource, everywhere else 5 and 7.
struct TPhotonRainbow : public TObjBase {
    TPhotonRainbow(TObject *parent, const Vec *pos, s32 boss_area);
    virtual ~TPhotonRainbow();
    virtual void render();
    virtual void run_task();

    NJS_TEXLIST *ring_texlist[2];
    NJS_OBJECT *ring_model[2];
    u8 pad_A0[0x8];
    // The constructor never stores its boss_area argument, so the model choice
    // reads this field before anything has set it.
    s32 boss_area;
};

LAYOUT_ASSERT(TPhotonRainbow_size, sizeof(TPhotonRainbow) == 0xAC);

// Its entry in photon_blast_load_callback_table; it loads and frees nothing.
void load_photon_rainbow_resources(void);
void release_photon_rainbow_resources(void);

#endif
