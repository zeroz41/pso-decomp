#include "types.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEneBm9Mericarol_Bomb.h"
#include "pso/enemy/TObjEneBm9Mericarol_EffCurse3.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/effect/TParticleCtrl.h"

struct VBase_18_477421
{
  char pad[0x18];
};

typedef struct Vec_800C4B78 {
    f32 x, y, z;
} Vec_800C4B78;

typedef struct Ent_800C4B78 {
    u8 pad0[0x38];
    Vec_800C4B78 pos;
} Ent_800C4B78;

typedef struct Obj_800C4B78 {
    u8 pad0[0x1C];
    s32 timer;
    Ent_800C4B78 *target;
    s32 effect;
} Obj_800C4B78;

extern "C" {
s32 subtract_vector(void *, void *);
s32 is_alive__8TObjBaseFv(s32);
extern u8 *camera_ctrl_instance;

void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);

#pragma push
#pragma fp_contract on

void TObjEneBm9Mericarol_EffCurse3::run_task() {
    Obj_800C4B78 *o = (Obj_800C4B78 *)this;
    Vec_800C4B78 a;
    Vec_800C4B78 b;
    o->timer++;
    if (o->timer > 0xa) {
        queue_destruction__7TObjectFv(o);
        return;
    }
    if (is_alive__8TObjBaseFv((s32)o->target) != 0) {
        VecCopy((Vec *)&a, (const Vec *)&o->target->pos);
        a.y += 14.0f;
        VecCopy((Vec *)&b, (const Vec *)(camera_ctrl_instance + 0x178));
        subtract_vector(&b, &a);
        ((TObjBoss2Tunnel *)(&b))->update_scale();
        a.x = 2e+01f * b.x + a.x;
        a.y = 2e+01f * b.y + a.y;
        a.z = 2e+01f * b.z + a.z;
        ((TParticleCtrl *)o->effect)->set_position(&a);
    }
}
typedef struct VBase_18_477421 VBase_18_477421;
#pragma pop

}

TObjEneBm9Mericarol_EffCurse3::~TObjEneBm9Mericarol_EffCurse3() {
    if (*(void * *)&this->unk_24 != NULL) { queue_destruction__7TObjectFv(*(void * *)&this->unk_24); *(s32 *)&this->unk_24 = 0; }
}

const char *TObjEneBm9Mericarol_EffCurse3__class_name = "TObjEneBm9Mericarol_EffCurse3";

TObjEneBm9Mericarol_EffCurse3::TObjEneBm9Mericarol_EffCurse3(TObject *parent, s32 target) : TObject(parent) {
    m_name = TObjEneBm9Mericarol_EffCurse3__class_name;
    *(s32 *)((s8 *)this + 0x1C) = 0;
    this->m_20 = target;
    if (is_alive__8TObjBaseFv(this->m_20) != 0) {
        *(s32 *)&this->unk_24 = (s32)spawn_continuous_particle_effect_with_flags((void *)(this->m_20 + 0x38), 0x20D, 0x40);
    }
}
