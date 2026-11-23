#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

#pragma push
#pragma fp_contract on
void TObjEneBm9Mericarol_EffCurse3::run_task() {
    Vec a;
    Vec b;
    age++;
    if (age > 10) {
        queue_destruction();
        return;
    }
    if (target->is_alive() != 0) {
        VecCopy(&a, &target->position);
        a.y += 14.0f;
        VecCopy(&b, (const Vec *)&camera_ctrl_instance->pos.x);
        subtract_vector(&b, &a);
        normalize_vector_safe(&b);
        a.x = 20.0f * b.x + a.x;
        a.y = 20.0f * b.y + a.y;
        a.z = 20.0f * b.z + a.z;
        effect->set_position(&a);
    }
}
#pragma pop

TObjEneBm9Mericarol_EffCurse3::~TObjEneBm9Mericarol_EffCurse3() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

const char *TObjEneBm9Mericarol_EffCurse3__class_name = "TObjEneBm9Mericarol_EffCurse3";

TObjEneBm9Mericarol_EffCurse3::TObjEneBm9Mericarol_EffCurse3(TObject *parent, TObjBase *victim) : TObject(parent) {
    m_name = TObjEneBm9Mericarol_EffCurse3__class_name;
    age = 0;
    target = victim;
    if (target->is_alive() != 0) {
        effect = spawn_continuous_particle_effect_with_flags(&target->position, 0x20D, 0x40);
    }
}
