#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/hud/TLoadingCur.h"
#include "pso/ui/frontend/TAdLoadNetworkGC.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
const char *now_loading_class_name = "TNowLoading";

void TNowLoading::render() {  }

#pragma push
#pragma fp_contract on
void TNowLoading::run_task() {
    Vec marker_position;
    if (camera_ctrl_instance == NULL) {
        this->m_position.x = (65.0f * ninja_camera.vx) + ninja_camera.px;
        this->m_position.y = (65.0f * ninja_camera.vy) + ninja_camera.py;
        this->m_position.z = (65.0f * ninja_camera.vz) + ninja_camera.pz;
        if (this->m_particles[0] != NULL) {
            this->m_particles[0]->set_position(&this->m_position);
        }
        if (this->m_particles[1] != NULL) {
            this->m_particles[1]->set_position(&this->m_position);
        }
        if (this->m_particles[2] != NULL) {
            this->m_particles[2]->set_position(&this->m_position);
        }
        if (this->m_particles[3] != NULL) {
            this->m_particles[3]->set_position(&this->m_position);
        }
    } else {
        marker_position.x = (65.0f * ninja_camera.vx) + ninja_camera.px;
        marker_position.y = (65.0f * ninja_camera.vy) + ninja_camera.py;
        marker_position.z = (65.0f * ninja_camera.vz) + ninja_camera.pz;
        if (this->m_particles[0] != NULL) {
            this->m_particles[0]->set_position(&marker_position);
        }
        if (this->m_particles[1] != NULL) {
            this->m_particles[1]->set_position(&marker_position);
        }
        if (this->m_particles[2] != NULL) {
            this->m_particles[2]->set_position(&marker_position);
        }
        if (this->m_particles[3] != NULL) {
            this->m_particles[3]->set_position(&marker_position);
        }
    }
}
#pragma pop

}
TNowLoading::~TNowLoading() {
    if (this->m_particles[0] != NULL) { this->m_particles[0]->queue_destruction(); this->m_particles[0] = NULL; }
    if (this->m_particles[1] != NULL) { this->m_particles[1]->queue_destruction(); this->m_particles[1] = NULL; }
    if (this->m_particles[2] != NULL) { this->m_particles[2]->queue_destruction(); this->m_particles[2] = NULL; }
    if (this->m_particles[3] != NULL) { this->m_particles[3]->queue_destruction(); this->m_particles[3] = NULL; }
}


#pragma push
#pragma fp_contract on
TNowLoading::TNowLoading(TObject *parent, Vec *pos) : TObject(parent) {
    Vec dir;
    s32 out[3];
    this->m_name = now_loading_class_name;
    VecCopy(&this->m_position, pos);
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    dir.x = -ninja_camera.vx;
    dir.y = -ninja_camera.vy;
    dir.z = -ninja_camera.vz;
    direction_to_rotation_xz((u8 *)&dir, &out[0], &out[2]);
    this->m_position.x = 65.0f * ninja_camera.vx + ninja_camera.px;
    this->m_position.y = 65.0f * ninja_camera.vy + ninja_camera.py;
    this->m_position.z = 65.0f * ninja_camera.vz + ninja_camera.pz;
    this->m_particles[0] = NULL;
    this->m_particles[1] = NULL;
    this->m_particles[2] = NULL;
    this->m_particles[3] = NULL;
    new TAdLoadNetworkGC(this, &this->m_position);
    new TLoadingCur(this, &this->m_position);
}
#pragma pop

void TNowLoading::cleanup() {  }
void TNowLoading::setup() {  }
