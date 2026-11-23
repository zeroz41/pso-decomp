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

struct Net_803084AC { u8 pad0[0x20]; void *obj[5]; Vec pos; };

struct Net_80308518 { u8 pad0[0x18]; void *vt; u8 pad1[4]; void *obj[5]; };

ParticleAngles TAdLoadNetworkGC__object_offset_table[5] = {
    {0x4000, 0, 0}, {0x4000, 0, 0}, {0, 0, 0}, {0x4000, 0, 0}, {0x4000, 0, 0},
};

extern "C" {
const s32 load_network_object_id_table[5] = {19, 21, 23, 29, 110};
const char *TAdLoadNetworkGC__class_name = "TAdLoadNetworkGC";
void TAdLoadNetworkGC::run_task() {
    Net_803084AC *o = (Net_803084AC *)this;
    u32 i;
    for (i = 0; i < 5; i++) {
        ((TParticleCtrl *)o->obj[i])->set_position(&o->pos);
        ((TParticleCtrl *)(o->obj[i]))->set_direction(&TAdLoadNetworkGC__object_offset_table[i]);
    }
}
}
TAdLoadNetworkGC::~TAdLoadNetworkGC() {
    u32 i;
    for (i = 0; i < 5; i++) {
        ((TObject *)(((Net_80308518 *)this)->obj[i]))->queue_destruction();
        ((Net_80308518 *)this)->obj[i] = 0;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((Net_803084AC *)this)
TAdLoadNetworkGC::TAdLoadNetworkGC(TObject *parent, Vec *pos) : TObject(parent) {
    u32 i;
    m_name = TAdLoadNetworkGC__class_name;
    VecCopy((Vec *)&self->pos, (const Vec *)pos);
    self->pos.x = 100.0f * ninja_camera.vx + ninja_camera.px;
    self->pos.y = 100.0f * ninja_camera.vy + ninja_camera.py;
    self->pos.z = 100.0f * ninja_camera.vz + ninja_camera.pz;
    for (i = 0; i < 5; i++) {
        self->obj[i] = 0;
        self->obj[i] = fn_80086FE0(&self->pos, &TAdLoadNetworkGC__object_offset_table[i], load_network_object_id_table[i], 1);
    }
}
#undef self
#pragma pop
