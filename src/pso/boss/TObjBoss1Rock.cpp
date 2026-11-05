#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/boss/TObjBoss1Rock.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/boss/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"


extern "C" {
s32 vec3_add_to(void *, void *);
extern const f32 lbl_805D8204;
extern const f32 lbl_805D8208;
extern const f32 lbl_805D820C;
extern const f32 lbl_805D8210;
extern const f32 lbl_805D8214;
extern const f32 lbl_805D8218;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjBoss1Rock::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    this->m_3c = (this->m_3c + 1);
    if ((s32) this->m_3c > 0x28) {
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) (*(f32 *)((s8 *)arg0 + 0x40) - lbl_805D8204);
        if (*(f32 *)((s8 *)arg0 + 0x40) < lbl_805D8208) {
            *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805D8208;
            queue_destruction__7TObjectFv(arg0);
        }
    }
    vec3_add_to((u8 *)&this->m_1c, (u8 *)&this->m_28);
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x20);
    if (temp_f2 < lbl_805D8208) {
        *(f32 *)((s8 *)arg0 + 0x20) = (f32) (temp_f2 * lbl_805D820C);
        *(f32 *)&this->unk_2C = (f32) (*(f32 *)&this->unk_2C * lbl_805D8210);
        *(f32 *)&this->m_28 = (f32) (*(f32 *)&this->m_28 * lbl_805D8214);
        this->m_30 = (f32) (this->m_30 * lbl_805D8214);
    }
    *(f32 *)&this->unk_2C = (f32) (*(f32 *)&this->unk_2C + lbl_805D8218);
    this->m_34 = (this->m_34 + 0x60);
    this->m_38 = (this->m_38 + 0x110);
}
#pragma pop

}


extern "C" {
s32 rand(void);
extern s32 lbl_805D26A0;
extern const f32 lbl_805D8200;
extern const f32 lbl_805D821C;
extern const f32 lbl_805D8220;
void *__dt__13TObjBoss1RockFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

extern s32 __vt__13TObjBoss1Rock[];

void *__dt__13TObjBoss1RockFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjBoss1Rock;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void TObjBoss1Rock::sub_8002E1CC(u8 *arg1, u8 *arg2, s32 arg3) {
    *(s32 *)&this->m_name = (s32) lbl_805D26A0;
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)arg1);
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)arg2);
    this->m_34 = (s32) (lbl_805D821C * (lbl_805D8220 * (f32) rand()));
    this->m_38 = (s32) (lbl_805D821C * (lbl_805D8220 * (f32) rand()));
    this->m_3c = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) lbl_805D8200;
    this->m_44 = (f32) lbl_805D8200;
    *(f32 *)((s8 *)((u8 *)this) + 0x48) = (f32) lbl_805D8200;
    this->m_4c = (f32) lbl_805D8200;
    if (arg3 == 0) {
        this->m_50 = 2;
        return;
    }
    this->m_50 = 1;
}

}

extern "C" {
void __ct__7TObjectFP7TObject(void *);
void TObjBoss1Rock__sub_8002E3CC(void);
void TObjBoss1Rock__sub_8002E3D0(void);

void *TObjBoss1Rock::construct(void *arg1, void *arg2, void *arg3, void *arg4) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TObjBoss1Rock;
    sub_8002E1CC((u8 *)arg2, (u8 *)arg3, (s32)arg4);
    return this;
}

extern const f32 lbl_805D8224;
}

TObjBoss1Rock::TObjBoss1Rock(TObject *object, void *arg2, void *arg3) : TObject(object) {
    s32 flag;
    if (lbl_805D8220 * (f32)rand() > lbl_805D8224) {
        flag = 0;
    } else {
        flag = 1;
    }
    sub_8002E1CC((u8 *)arg2, (u8 *)arg3, (s32)flag);
}


void TObjBoss1Rock__sub_8002E3CC(void) {  }
void TObjBoss1Rock__sub_8002E3D0(void) {  }
