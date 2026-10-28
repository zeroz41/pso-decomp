#include "types.h"
#include "pso/boss/TBoss8DragonEffBreath.h"

#include "pso/boss/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"

#include "pso/boss/TBoss8Dragon.h"

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
extern s32 TBoss8DragonEffBreath__name;
extern const f32 lbl_805DEEF8;
s32 vec3_add_to(void *, void *);
u8 *get_enemy_entity(u16 arg0);
void queue_destruction__7TObjectFv(void *arg0);

void TBoss8DragonEffBreath::render() {  }

extern const f32 lbl_805DEEF0;
extern const f32 lbl_805DEEF4;

void TBoss8DragonEffBreath::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u32 ent;

    vec3_add_to((u8 *)&this->m_1c, (u8 *)&this->m_28);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
    if (temp_f1 < lbl_805DEEF0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if ((temp_f1 < lbl_805DEEF4) && ((ent = (u32)get_enemy_entity((this->m_38))) != 0U)) {
        TBoss8Dragon::setup_breath_instance((void *)ent, (int)(arg0 + 0x1C), (u32)((int)this->m_34), (int)((int)this->m_3c));
    }
}

}
TBoss8DragonEffBreath::~TBoss8DragonEffBreath() {
    delete_buffer__12TBoss8DragonFis((s32)(*(void **)((s8 *)this + 0x3C)), 1);
    this->m_3c = 0;
}
TBoss8DragonEffBreath::TBoss8DragonEffBreath(TObject *parent, void *p, void *v, s32 a, s16 b) : TObject(parent) {
    void *h;
    *(s32 *)this = TBoss8DragonEffBreath__name;
    VecCopy((Vec *)&((Obj_802FE024 *)this)->pos, (const Vec *)p);
    VecCopy((Vec *)&((Obj_802FE024 *)this)->vel, (const Vec *)v);
    ((Obj_802FE024 *)this)->vel.x = ((Obj_802FE024 *)this)->vel.x * lbl_805DEEF8;
    ((Obj_802FE024 *)this)->vel.y = ((Obj_802FE024 *)this)->vel.y * lbl_805DEEF8;
    ((Obj_802FE024 *)this)->vel.z = ((Obj_802FE024 *)this)->vel.z * lbl_805DEEF8;
    ((Obj_802FE024 *)this)->a = a;
    ((Obj_802FE024 *)this)->b = b;
    h = ::operator new(0x10);
    if (h != NULL) {
        h = TBoss8Dragon__sub_800BC5EC((u8 *)h, 4);
    }
    ((Obj_802FE024 *)this)->h = h;
}
