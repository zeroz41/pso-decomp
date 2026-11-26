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
    static const char *name;
};

LAYOUT_ASSERT(TObjBoss5PillarSmoke_size, sizeof(TObjBoss5PillarSmoke) == 0x28);

// The model-node callback TObjBoss5Pillar::render installs (begin_pillar_smoke_node_capture) and clears for a smoke.
void pillar_smoke_node_callback(NJS_OBJECT *node);
void end_pillar_smoke_node_capture(TObjBoss5PillarSmoke *smoke);
void begin_pillar_smoke_node_capture(TObjBoss5PillarSmoke *smoke);
void park_pillar_smoke_particles(TObjBoss5PillarSmoke *smoke);
void place_pillar_smoke_at_node(TObjBoss5PillarSmoke *smoke, NJS_OBJECT *node);

#endif
