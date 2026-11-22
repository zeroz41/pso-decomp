#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARSMOKE_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLARSMOKE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct NJS_OBJECT;
class TParticleCtrl;

// Smoke on a pillar model: particle effects 0x213 and 0x214 for each child node.
struct TObjBoss5PillarSmoke : public TObject {
    TObjBoss5PillarSmoke(TObject *parent, NJS_OBJECT *node);
    virtual ~TObjBoss5PillarSmoke();
    virtual void render();
    virtual void run_task();

    s32 count;  // child nodes of the model
    TParticleCtrl **particles_a;  // effect 0x213 per node
    TParticleCtrl **particles_b;  // effect 0x214 per node
};

LAYOUT_ASSERT(TObjBoss5PillarSmoke_size, sizeof(TObjBoss5PillarSmoke) == 0x28);

// The model-node callback TObjBoss5Pillar::render installs (fn_8028ADDC) and clears (sub_8028ADB0) for a smoke.
extern "C" {
void TObjBoss5PillarDemo__sub_8028AD88(NJS_OBJECT *node);
void TObjBoss5PillarDemo__sub_8028ADB0(TObjBoss5PillarSmoke *smoke);
void fn_8028ADDC(TObjBoss5PillarSmoke *smoke);
void fn_8028AE1C(TObjBoss5PillarSmoke *smoke);
}
#endif
