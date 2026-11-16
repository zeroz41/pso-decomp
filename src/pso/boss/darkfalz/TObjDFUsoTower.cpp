#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TOBoss4.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include <stdlib.h>

struct RecoveredGlobal_80052200_lbl_804858A8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80052200___vt__14TObjDFUsoTower {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
extern RecoveredGlobal_80052200_lbl_804858A8 lbl_804858A8;
extern s32 __vt__14TObjDFUsoTower[];
extern s32 TObjDFUsoTower__name;
extern const f32 lbl_805D8A30;
void __dl__7TObjectFPv(void *);

void *__dt__14TObjDFUsoTowerFv(void *base, s16 arg1) {
    if (base != NULL) {
        *(s32 **)((s8 *)base + 0x18) = __vt__14TObjDFUsoTower;
        __dt__8TObjBaseFv(base, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(base);
        }
    }
    return base;
}

typedef char RecoveredGlobal_80052200_lbl_804858A8_size[sizeof(RecoveredGlobal_80052200_lbl_804858A8) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80052200___vt__14TObjDFUsoTower_size[sizeof(RecoveredGlobal_80052200___vt__14TObjDFUsoTower) == 0x34 ? 1 : -1];
}
TObjDFUsoTower::TObjDFUsoTower(s32 _w1) : TObjBase((TObject *)_w1) {
    *(s32 *)((s8 *)this + 0) = (s32) TObjDFUsoTower__name;
    *(s32 *)((s8 *)this + 0x34) = get_bml_model(TOBoss4::model_resource, 5);
    this->texlist = get_bml_texlist(TOBoss4::model_resource, 5);
    VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)&lbl_804858A8.value);
    *(f32 *)((s8 *)this + 0x94) = (f32) lbl_805D8A30;
    this->m_90 = 0;
}
extern "C" {

void *TObjDFUsoTower::create(void *arg0) {
    void *o = (void *)new TObjDFUsoTower((s32)arg0);
    return o;
}
s32 TBoss4Type2::pick_weighted_random(s32 n, f32 *w, s32 *t) {
    s32 i;
    f32 acc;
    f32 r;
    r = 3.0517578e-05f * (f32)rand();
    acc = w[0];
    for (i = 0; i < n - 1; i++) {
        if (r < acc) {
            return t[i];
        }
        acc += w[i];
    }
    return t[n - 1];
}

}
