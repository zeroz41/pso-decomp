#ifndef PSO_TECHNIQUE_TTECBARTA_H
#define PSO_TECHNIQUE_TTECBARTA_H

#include "types.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/technique/TTecShot.h"

struct TechniqueDamagePayload { s32 kind; f32 power; };
struct TechniqueHitRecipient;
struct TechniqueHitRecipientVtable {
    u8 beforeReceive[0x5c];
    void (*receive)(TechniqueHitRecipient*, TechniqueHitRecipient*,
        const TechniqueDamagePayload*, TechniqueContactBody*, s32, s32);
};
struct TechniqueHitRecipient {
    u8 task[0x18];
    TechniqueHitRecipientVtable* vtable;
};
struct TechniqueParticleEmitter;
struct TechniqueEmitterSourceRow { u32 entry; u32 flags; f32 scale; };
struct TechniqueEmitterSourceTable { const TechniqueEmitterSourceRow *rows; u32 count; };

struct TTecBarta : public TTecShot {
    TTecBarta(saddr source, u8 *pos, u8 *target, s32 level);
    TTecBarta(saddr source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecBarta();
    virtual void vfunc_8(void *);
    TechniqueParticleEmitter** emitters;
    u16 hitIds[32];
    s32 hitCursor;
    void update_technique_by_state();
    void create_particle_emitters();
    void init_parameters();
    static void create(void *source, void *origin, void *aim, s32 level);
    static void create_ex(void *source, void *origin, s32 angle, s32 level);
    virtual void run_task();
    virtual void render();
};
LAYOUT_ASSERT(TTecBarta_size, sizeof(TTecBarta)==0x178);

#endif
