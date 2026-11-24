#ifndef PSO_TECHNIQUE_TTECRABARTA_H
#define PSO_TECHNIQUE_TTECRABARTA_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

class TParticleCtrl;

struct TTecRaBarta : public TTecCircle {
    TTecRaBarta(saddr source, Vec *origin, Vec *pos, s32 level);
    TTecRaBarta(saddr source, Vec *origin, s32 level);
    virtual ~TTecRaBarta();
    virtual void apply_to_target(TObjChara *);
    virtual void play_cast_sound();
    virtual void spawn_effects(Vec *pos);
    void calc_parameters();
    s32 sound;                 // play_cast_sound's handle, stopped by the dtor
    u32 has_point;             // 1 when cast on a chosen point, 0 when on the caster
    TParticleCtrl **emitters;  // one per rabarta_band_emitter_table[band] entry
    u16 hit_ids[32];  // entity ids apply_to_target has already hit
    s32 hitCursor;  // next free hit_ids slot, capped at 31
    static void create(void *source, void *origin, void *pos, s32 level);
    static void create(void *source, void *origin, s32 level);
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TTecRaBarta_size, sizeof(TTecRaBarta) == 0x13C);
#endif
