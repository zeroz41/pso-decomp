#include "types.h"
#include "pso/boss/TBoss1DragonEffBreath.h"
#include "pso/boss/TBoss8Dragon_800BC53C.h"

#include "pso/system/vector.h"
#include "pso/boss/TBoss1Dragon.h"

extern "C" {
extern s32 TBoss1DragonEffBreath__name;
extern const f32 lbl_805D8138;
s32 vec3_add_to(void *, void *);
void queue_destruction__7TObjectFv(void *arg0);

void TBoss1DragonEffBreath::render() {  }

extern const f32 lbl_805D8130;
extern const f32 lbl_805D8134;

void TBoss1DragonEffBreath::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;

    vec3_add_to((u8 *)&this->m_1c, (u8 *)&this->m_28);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
    if (temp_f1 < lbl_805D8130) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (temp_f1 < lbl_805D8134) {
        ((TBoss1Dragon *)((int) TBoss1Dragon::get_instance()))->deliver_breath_attack((s32)(arg0 + 0x1C), (s32)((int)this->m_34));
    }
}

}
TBoss1DragonEffBreath::~TBoss1DragonEffBreath() {
    delete_buffer__12TBoss8DragonFis((s32)(*(void **)((s8 *)this + 0x34)), 1);
    this->m_34 = 0;
}
TBoss1DragonEffBreath::TBoss1DragonEffBreath(TObject *object, void *arg2, void *arg3) : TObject(object) {
    void *p;
    *(s32 *)((s8 *)this + 0) = (s32) TBoss1DragonEffBreath__name;
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)arg3);
    *(f32 *)((s8 *)this + 0x28) = (f32) (*(f32 *)((s8 *)this + 0x28) * lbl_805D8138);
    *(f32 *)((s8 *)this + 0x2C) = (f32) (*(f32 *)((s8 *)this + 0x2C) * lbl_805D8138);
    this->m_30 = (f32) (this->m_30 * lbl_805D8138);
    p = ::operator new(0x10);
    if (p != NULL) {
        p = TBoss8Dragon__sub_800BC5EC((u8 *)p, 4);
    }
    *(void **)((s8 *)this + 0x34) = p;
}
