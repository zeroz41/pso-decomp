#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"

#pragma readonly_strings on


const char *TObjBoss5PillarSmoke__name = "TObjBoss5PillarSmoke";

// Where the smoke particles are parked (fn_8028AE1C, the constructor) and the
// node origin the model callback projects (TObjBoss5PillarDemo__sub_8028ACE8).
static const Vec lbl_80450CD0 = {0.0f, -1000.0f, 0.0f};
static const Vec lbl_80450CDC = {0.0f, 0.0f, 0.0f};

// The pillar's model callback and the smoke placement: their .sbss, the two
// templates above and the smoke layout are this unit's, so the TU starts at
// 0x8028ACE8, not at the destructor.
extern "C" {
s32 boss5_pillar_demo_index;
TObjBoss5PillarSmoke *boss5_pillar_demo_ptr;

void TObjBoss5PillarDemo__sub_8028ACE8(TObjBoss5PillarSmoke *smoke, NJS_OBJECT *node) {
    Vec position;
    s32 idx;
    idx = boss5_pillar_demo_index - 1;
    boss5_pillar_demo_index += 1;
    if (idx >= 0 && idx < smoke->count) {
        TCameraCtrl::transform_to_view(&lbl_80450CDC, &position);
        if (smoke->particles_a != NULL && smoke->particles_a[idx] != NULL) {
            smoke->particles_a[idx]->set_position(&position);
        }
        if (smoke->particles_b != NULL && smoke->particles_b[idx] != NULL) {
            smoke->particles_b[idx]->set_position(&position);
        }
    }
}

void TObjBoss5PillarDemo__sub_8028AD88(NJS_OBJECT *node) { TObjBoss5PillarDemo__sub_8028ACE8(boss5_pillar_demo_ptr, node); }

void TObjBoss5PillarDemo__sub_8028ADB0(TObjBoss5PillarSmoke *smoke) {
    if (smoke != NULL) {
        set_model_node_callback(0);
    }
}

void fn_8028ADDC(TObjBoss5PillarSmoke *smoke) {
    if (smoke) {
        boss5_pillar_demo_index = 0;
        boss5_pillar_demo_ptr = smoke;
        set_model_node_callback(TObjBoss5PillarDemo__sub_8028AD88);
    }
}
void fn_8028AE1C(TObjBoss5PillarSmoke *smoke) {
    s32 i;
    for (i = 0; i < smoke->count; i++) {
        if (smoke->particles_a[i] != 0) {
            smoke->particles_a[i]->set_position((void *)&lbl_80450CD0);
        }
        if (smoke->particles_b[i] != 0) {
            smoke->particles_b[i]->set_position((void *)&lbl_80450CD0);
        }
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
    m_name = TObjBoss5PillarSmoke__name;
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
        this->particles_a[i] = spawn_continuous_particle_effect_with_flags((void *)&lbl_80450CD0, 0x213, 0x40);
        this->particles_b[i] = spawn_continuous_particle_effect_with_flags((void *)&lbl_80450CD0, 0x214, 0x40);
    }
}
