#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/galgryphon/Boss5CommonResource.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_80067034.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/system/BmlResource.h"

#pragma readonly_strings on


const char *TObjBoss5PillarSmoke::name = "TObjBoss5PillarSmoke";

// Where the smoke particles are parked (park_pillar_smoke_particles, the constructor) and the
// node origin the model callback projects (place_pillar_smoke_at_node).
static const Vec pillar_smoke_parked_position = {0.0f, -1000.0f, 0.0f};
static const Vec pillar_smoke_node_origin = {0.0f, 0.0f, 0.0f};

// The pillar's model callback and the smoke placement: their .sbss, the two
// templates above and the smoke layout are this unit's, so the TU starts at
// the model callback, not at the destructor.
s32 boss5_pillar_demo_index;
TObjBoss5PillarSmoke *boss5_pillar_demo_ptr;

void place_pillar_smoke_at_node(TObjBoss5PillarSmoke *smoke, NJS_OBJECT *node) {
    Vec position;
    s32 idx;
    idx = boss5_pillar_demo_index - 1;
    boss5_pillar_demo_index += 1;
    if (idx >= 0 && idx < smoke->count) {
        TCameraCtrl::transform_to_view(&pillar_smoke_node_origin, &position);
        if (smoke->particles_a != NULL && smoke->particles_a[idx] != NULL) {
            smoke->particles_a[idx]->set_position(&position);
        }
        if (smoke->particles_b != NULL && smoke->particles_b[idx] != NULL) {
            smoke->particles_b[idx]->set_position(&position);
        }
    }
}

void pillar_smoke_node_callback(NJS_OBJECT *node) { place_pillar_smoke_at_node(boss5_pillar_demo_ptr, node); }

void end_pillar_smoke_node_capture(TObjBoss5PillarSmoke *smoke) {
    if (smoke != NULL) {
        set_model_node_callback(0);
    }
}

void begin_pillar_smoke_node_capture(TObjBoss5PillarSmoke *smoke) {
    if (smoke) {
        boss5_pillar_demo_index = 0;
        boss5_pillar_demo_ptr = smoke;
        set_model_node_callback(pillar_smoke_node_callback);
    }
}
void park_pillar_smoke_particles(TObjBoss5PillarSmoke *smoke) {
    s32 i;
    for (i = 0; i < smoke->count; i++) {
        if (smoke->particles_a[i] != 0) {
            smoke->particles_a[i]->set_position(const_cast<Vec *>(&pillar_smoke_parked_position));
        }
        if (smoke->particles_b[i] != 0) {
            smoke->particles_b[i]->set_position(const_cast<Vec *>(&pillar_smoke_parked_position));
        }
    }
}

void TObjBoss5PillarSmoke::render() {  }
void TObjBoss5PillarSmoke::run_task() {  }

TObjBoss5PillarSmoke::~TObjBoss5PillarSmoke() {
    s32 i;
    for (i = this->count - 1; i >= 0; i--) {
        if (this->particles_b[i] != NULL) {
            this->particles_b[i]->queue_destruction();
            this->particles_b[i] = NULL;
        }
        if (this->particles_a[i] != NULL) {
            this->particles_a[i]->queue_destruction();
            this->particles_a[i] = NULL;
        }
    }
    mem_free(this->particles_b);
    mem_free(this->particles_a);
}

TObjBoss5PillarSmoke::TObjBoss5PillarSmoke(TObject *parent, NJS_OBJECT *node) : TObject(parent) {
    s32 i;
    m_name = TObjBoss5PillarSmoke::name;
    this->count = 0;
    this->particles_a = NULL;
    this->particles_b = NULL;
    if (node == NULL) {
        queue_destruction();
        return;
    }
    for (node = node->child; node != NULL; node = node->sibling) {
        this->count++;
    }
    if (this->count <= 0) {
        queue_destruction();
        return;
    }
    this->particles_a = (TParticleCtrl **)mem_alloc(this->count * 4);
    this->particles_b = (TParticleCtrl **)mem_alloc(this->count * 4);
    for (i = 0; i < this->count; i++) {
        this->particles_a[i] = spawn_continuous_particle_effect_with_flags(&pillar_smoke_parked_position, 0x213, 0x40);
        this->particles_b[i] = spawn_continuous_particle_effect_with_flags(&pillar_smoke_parked_position, 0x214, 0x40);
    }
}

TObjBoss5PillarSmoke *TObjBoss5Pillar::create_smoke(TObject *parent, NJS_OBJECT *node) {
    return new TObjBoss5PillarSmoke(parent, node);
}


void trigger_pillars_in_range(TObjBoss5PillarCtrl *pillar_controller, const Vec *pos, const DragonAttackParams *params) {
    f32 off;
    NJS_OBJECT *n;
    s32 i;

    n = boss5_common_bml_resource->models[2].model;
    off = TBoss8Dragon::calc_sq_offset(params, 50.0f);
    n = n->child;
    for (i = 0; i < pillar_controller->count; i++) {
        if (pillar_controller->pillars[i] != NULL && TBoss8Dragon::is_within_xz_distance(pos, n, off) != 0) {
            pillar_controller->pillars[i]->play_sound_once();
        }
        n = n->sibling;
    }
}
