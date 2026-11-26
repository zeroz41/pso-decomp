#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/DebugFont.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#pragma readonly_strings on

// Where the mist sits relative to the camera: straight ahead along its view axis.
extern Vec mist_camera_forward;

TObjMistCtrl *TObjMistCtrl::create(TObject *parent, void *set_data) {
    return new TObjMistCtrl(parent, set_data);
}

// Keeps the mist particles 60 units in front of the camera.
void TObjMistCtrl::follow_camera() {
    Vec v = mist_camera_forward;
    push_matrix_from(identity_matrix);
    rotate_matrix_zyx(0, camera_ctrl_instance->pitch, camera_ctrl_instance->yaw, camera_ctrl_instance->roll);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    normalize_vector(&v);
    v.x *= 60.0f;
    v.y *= 60.0f;
    v.z *= 60.0f;
    vec3_add_to(&v, &camera_ctrl_instance->pos);
    VecCopy(&position, &v);
    if (particle != NULL) {
        particle->set_position(&position);
    }
}

const char *TObjMistCtrl::class_name = "TObjMistCtrl";

void TObjMistCtrl::run_task() { follow_camera(); }

TObjMistCtrl::~TObjMistCtrl() {
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
}

TObjMistCtrl::TObjMistCtrl(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = class_name;
    if (set_data != NULL) {
        apply_object_set_data(set_data);
    }
    particle = spawn_continuous_particle_effect_with_flags(&position, 0x200, 0x800);
}

__declspec(section ".rodata") Vec mist_camera_forward = { 0, 0, -1.0f };
