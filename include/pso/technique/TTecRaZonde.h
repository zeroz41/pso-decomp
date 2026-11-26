#ifndef PSO_TECHNIQUE_TTECRAZONDE_H
#define PSO_TECHNIQUE_TTECRAZONDE_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

class TParticleCtrl;

struct TTecRaZonde : public TTecCircle {
    TTecRaZonde(TObjBase *source, Vec *origin, s32 level);
    virtual ~TTecRaZonde();
    virtual void spawn_effects(Vec *pos);
    virtual void apply_to_target(TObjChara *);
    virtual void run_task();
    TParticleCtrl **emitters;  // one per razonde_band_emitter_table[band] entry
    void calc_damage();
    static void create(TObjBase *source, Vec *origin, s32 level);
    virtual void render();
    Vec bolt_points[8];  // the constructor's spiral; a bolt runs between each neighbouring pair
};

LAYOUT_ASSERT(TTecRaZonde_size, sizeof(TTecRaZonde) == 0x150);
#endif
