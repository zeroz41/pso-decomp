#ifndef PSO_TECHNIQUE_TTECBARTA_H
#define PSO_TECHNIQUE_TTECBARTA_H

#include "types.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/technique/TechniqueEmitterTable.h"
#include "pso/technique/TTecShot.h"

struct TechniqueParticleEmitter;

struct TTecBarta : public TTecShot {
    static const char *class_name;
    TTecBarta(TObjBase *source, Vec *pos, Vec *target, s32 level);
    TTecBarta(TObjBase *source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecBarta();
    virtual void apply_to_target(TObjChara *);
    TechniqueParticleEmitter** emitters;
    u16 hitIds[32];
    s32 hitCursor;
    void update_technique_by_state();
    void create_particle_emitters();
    void init_parameters();
    static void create(TObjBase *source, Vec *origin, Vec *aim, s32 level);
    static void create_ex(TObjBase *source, Vec *origin, s32 angle, s32 level);
    virtual void run_task();
    virtual void render();
};
LAYOUT_ASSERT(TTecBarta_size, sizeof(TTecBarta)==0x178);

#endif
