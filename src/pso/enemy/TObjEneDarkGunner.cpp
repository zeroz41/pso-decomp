#include "types.h"
#include "pso/enemy/TObjEneMe1Canadin_EffLineFade.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/enemy/TObjEneDarkGunner.h"
#include "pso/unk/text_800A02AC.h"
#include "pso/system/vector.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TObjEneMe1Canadin_EffLineFade::run_task() {
    s32 var_r31;

    var_r31 = this->m_37;
    var_r31 -= 0x10;
    if (var_r31 < 0) {
        var_r31 = 0;
        queue_destruction__7TObjectFv(this);
    }
    this->m_37 = (u8) var_r31;
    this->m_3b = (s8) var_r31;
}

extern s32 __vt__29TObjEneMe1Canadin_EffLineFade[];

}
TObjEneMe1Canadin_EffLineFade::~TObjEneMe1Canadin_EffLineFade() {

}
extern "C" {

}

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 TObjEneMe1Canadin_EffLineFade__class_name;
u8 *fn_800A02AC(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = __vt__29TObjEneMe1Canadin_EffLineFade;
    *(s32 *)((s8 *)object + 0) = (s32) TObjEneMe1Canadin_EffLineFade__class_name;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg3);
    *(s32 *)((s8 *)object + 0x34) = 0xFFFF0033;
    *(s32 *)((s8 *)object + 0x38) = 0xFFFF0033;
    return object;
}

}
