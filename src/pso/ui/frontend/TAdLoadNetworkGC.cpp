#include "types.h"
#include "pso/ui/frontend/TAdLoadNetworkGC.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/NinjaTypes.h"
#pragma readonly_strings on

void TAdLoadNetworkGC::render() {  }

ParticleAngles TAdLoadNetworkGC__object_offset_table[5] = {
    {0x4000, 0, 0}, {0x4000, 0, 0}, {0, 0, 0}, {0x4000, 0, 0}, {0x4000, 0, 0},
};

extern "C" {
const s32 load_network_object_id_table[5] = {19, 21, 23, 29, 110};
const char *TAdLoadNetworkGC__class_name = "TAdLoadNetworkGC";
void TAdLoadNetworkGC::run_task() {
    u32 i;
    for (i = 0; i < 5; i++) {
        this->particles[i]->set_position(&this->position);
        this->particles[i]->set_direction(&TAdLoadNetworkGC__object_offset_table[i]);
    }
}
}
TAdLoadNetworkGC::~TAdLoadNetworkGC() {
    u32 i;
    for (i = 0; i < 5; i++) {
        this->particles[i]->queue_destruction();
        this->particles[i] = 0;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
TAdLoadNetworkGC::TAdLoadNetworkGC(TObject *parent, Vec *pos) : TObject(parent) {
    u32 i;
    m_name = TAdLoadNetworkGC__class_name;
    VecCopy(&this->position, (const Vec *)pos);
    this->position.x = 100.0f * ninja_camera.vx + ninja_camera.px;
    this->position.y = 100.0f * ninja_camera.vy + ninja_camera.py;
    this->position.z = 100.0f * ninja_camera.vz + ninja_camera.pz;
    for (i = 0; i < 5; i++) {
        this->particles[i] = 0;
        this->particles[i] = create_particle_controller_with_angles(&this->position, &TAdLoadNetworkGC__object_offset_table[i], load_network_object_id_table[i], 1);
    }
}
#pragma pop
