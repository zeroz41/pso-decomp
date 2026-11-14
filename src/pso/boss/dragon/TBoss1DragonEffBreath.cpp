#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/dragon/TBoss1DragonEffBreath.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"

#include "pso/system/vector.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/system/task/TObject.h"

extern "C" {
extern s32 TBoss1DragonEffBreath__name;
s32 vec3_add_to(void *, void *);

void TBoss1DragonEffBreath::render() {  }


void TBoss1DragonEffBreath::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;

    vec3_add_to((u8 *)&this->m_1c, (u8 *)&this->m_28);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
    if (temp_f1 < -10.0f) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    if (temp_f1 < 30.0f) {
        ((TBoss1Dragon *)((int) TBoss1Dragon::get_instance()))->deliver_breath_attack((s32)(arg0 + 0x1C), (s32)((int)this->m_34));
    }
}

}
TBoss1DragonEffBreath::~TBoss1DragonEffBreath() {
    __dt__17AreaAttackHistoryFv((s32)(*(void **)((s8 *)this + 0x34)), 1);
    this->m_34 = 0;
}
TBoss1DragonEffBreath::TBoss1DragonEffBreath(TObject *object, void *arg2, void *arg3) : TObject(object) {
    void *p;
    *(s32 *)((s8 *)this + 0) = (s32) TBoss1DragonEffBreath__name;
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)arg3);
    *(f32 *)((s8 *)this + 0x28) *= 5.0f;
    *(f32 *)((s8 *)this + 0x2C) *= 5.0f;
    this->m_30 *= 5.0f;
    p = ::operator new(0x10);
    if (p != NULL) {
        p = __ct__17AreaAttackHistoryFl((u8 *)p, 4);
    }
    *(void **)((s8 *)this + 0x34) = p;
}
