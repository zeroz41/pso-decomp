#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_80087278.h"

extern "C" TCameraCtrl *camera_ctrl_instance;

#pragma push
#pragma fp_contract on
void TObjEneBm9Mericarol_EffCurse3::run_task() {
    Vec a;
    Vec b;
    m_1c++;
    if (m_1c > 10) {
        queue_destruction();
        return;
    }
    if (m_20->is_alive() != 0) {
        VecCopy(&a, &m_20->position);
        a.y += 14.0f;
        VecCopy(&b, (const Vec *)&camera_ctrl_instance->pos_x);
        subtract_vector(&b, &a);
        ((TObjBoss2Tunnel *)&b)->update_scale();
        a.x = 20.0f * b.x + a.x;
        a.y = 20.0f * b.y + a.y;
        a.z = 20.0f * b.z + a.z;
        m_24->set_position(&a);
    }
}
#pragma pop

TObjEneBm9Mericarol_EffCurse3::~TObjEneBm9Mericarol_EffCurse3() {
    if (m_24 != NULL) {
        m_24->queue_destruction();
        m_24 = NULL;
    }
}

const char *TObjEneBm9Mericarol_EffCurse3__class_name = "TObjEneBm9Mericarol_EffCurse3";

TObjEneBm9Mericarol_EffCurse3::TObjEneBm9Mericarol_EffCurse3(TObject *parent, TObjBase *target) : TObject(parent) {
    m_name = TObjEneBm9Mericarol_EffCurse3__class_name;
    m_1c = 0;
    m_20 = target;
    if (m_20->is_alive() != 0) {
        m_24 = spawn_continuous_particle_effect_with_flags(&m_20->position, 0x20D, 0x40);
    }
}
