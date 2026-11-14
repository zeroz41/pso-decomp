#include "types.h"
#include "pso/boss/goldragon/TBoss8DragonEffBreath.h"

#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#pragma readonly_strings on

struct Vec_802FE024 { f32 x, y, z; };

struct Obj_802FE024 {
    u8 pad0[0x18];
    void *vt;
    Vec_802FE024 pos;
    Vec_802FE024 vel;
    s32 a;
    s16 b;
    void *h;
};

extern "C" {
const char *TBoss8DragonEffBreath__name = "TBoss8DragonEffBreath";
s32 vec3_add_to(void *, void *);
u8 *get_enemy_entity(u16 arg0);
void queue_destruction__7TObjectFv(void *arg0);

void TBoss8DragonEffBreath::render() {  }


void TBoss8DragonEffBreath::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u32 ent;

    vec3_add_to((u8 *)&this->m_1c, (u8 *)&this->m_28);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
    if (temp_f1 < -10.0f) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if ((temp_f1 < 30.0f) && ((ent = (u32)get_enemy_entity((this->m_38))) != 0U)) {
        TBoss8Dragon::setup_breath_instance((void *)ent, (int)(arg0 + 0x1C), (u32)((int)this->m_34), (int)((int)this->m_3c));
    }
}

}
TBoss8DragonEffBreath::~TBoss8DragonEffBreath() {
    __dt__17AreaAttackHistoryFv((s32)(*(void **)((s8 *)this + 0x3C)), 1);
    this->m_3c = 0;
}
TBoss8DragonEffBreath::TBoss8DragonEffBreath(TObject *parent, void *p, void *v, s32 a, s16 b) : TObject(parent) {
    void *h;
    *(const char **)this = TBoss8DragonEffBreath__name;
    VecCopy((Vec *)&((Obj_802FE024 *)this)->pos, (const Vec *)p);
    VecCopy((Vec *)&((Obj_802FE024 *)this)->vel, (const Vec *)v);
    ((Obj_802FE024 *)this)->vel.x *= 5.0f;
    ((Obj_802FE024 *)this)->vel.y *= 5.0f;
    ((Obj_802FE024 *)this)->vel.z *= 5.0f;
    ((Obj_802FE024 *)this)->a = a;
    ((Obj_802FE024 *)this)->b = b;
    h = ::operator new(0x10);
    if (h != NULL) {
        h = __ct__17AreaAttackHistoryFl((u8 *)h, 4);
    }
    ((Obj_802FE024 *)this)->h = h;
}
