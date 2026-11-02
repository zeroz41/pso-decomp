#ifndef PSO_MISC_TTECBARTA_H
#define PSO_MISC_TTECBARTA_H

#include "types.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/effect/TUnk_804CCC68.h"

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

struct TTecBarta : public TUnk_804CCC68 {
    virtual ~TTecBarta();
    virtual void vfunc_8(void *);
    TechniqueParticleEmitter** emitters;
    u16 hitIds[32];
    s32 hitCursor;
    void update_technique_by_state();
    void create_particle_emitters();
    void init_parameters();
    void create(void *arg1, void *arg2, void *arg3);
    void create_ex(void *arg1, void *arg2, void *arg3);
    virtual void run_task();
    virtual void render();
};
typedef char TTecBarta_size[sizeof(TTecBarta)==0x178?1:-1];

#endif
