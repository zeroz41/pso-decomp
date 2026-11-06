#include "types.h"
#include "pso/ui/frontend/TAdLoadNetworkGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80086FE0.h"
#include "pso/unk/text_80086B64.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdLoadNetworkGC.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
struct V_803084AC { f32 x, y, z; };

struct Net_803084AC { u8 pad0[0x20]; void *obj[5]; V_803084AC pos; };

struct Net_80308518 { u8 pad0[0x18]; void *vt; u8 pad1[4]; void *obj[5]; };

struct Ray_803085A0 { V_803084AC a; V_803084AC b; };

ParticleAngles TAdLoadNetworkGC__object_offset_table[5] = {
    {0x4000, 0, 0}, {0x4000, 0, 0}, {0, 0, 0}, {0x4000, 0, 0}, {0x4000, 0, 0},
};

extern "C" {
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
extern u8 __vt__16TAdLoadNetworkGC[];
Net_80308518 *__dt__16TAdLoadNetworkGCFv(Net_80308518 *self, s16 flag);
void *__ct__7TObjectFP7TObject(void *, void *);
extern const s32 load_network_object_id_table[];
extern Ray_803085A0 lbl_804FF5E8;
extern s32 TAdLoadNetworkGC__class_name;
Net_803084AC *TAdLoadNetworkGC__ct(Net_803084AC *self, void *parent, V_803084AC *pos);
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
        queue_destruction__7TObjectFv(((Net_80308518 *)this)->obj[i]);
        ((Net_80308518 *)this)->obj[i] = 0;
    }
}
extern "C" {
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
Net_803084AC *TAdLoadNetworkGC__ct(Net_803084AC *self, void *parent, V_803084AC *pos) {
    u32 i;
    __ct__7TObjectFP7TObject(self, parent);
    *(void **)((u8 *)self + 0x18) = __vt__16TAdLoadNetworkGC;
    *(s32 *)self = TAdLoadNetworkGC__class_name;
    VecCopy((Vec *)&self->pos, (const Vec *)pos);
    self->pos.x = 100.0f * lbl_804FF5E8.b.x + lbl_804FF5E8.a.x;
    self->pos.y = 100.0f * lbl_804FF5E8.b.y + lbl_804FF5E8.a.y;
    self->pos.z = 100.0f * lbl_804FF5E8.b.z + lbl_804FF5E8.a.z;
    for (i = 0; i < 5; i++) {
        self->obj[i] = 0;
        self->obj[i] = fn_80086FE0(&self->pos, &TAdLoadNetworkGC__object_offset_table[i], load_network_object_id_table[i], 1);
    }
    return self;
}
#pragma pop

}
