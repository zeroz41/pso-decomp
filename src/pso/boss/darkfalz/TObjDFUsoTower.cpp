#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TOBoss4.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"
#include "pso/object/base/TObjMotion.h"

struct RecoveredGlobal_80052200_lbl_804858A8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80052200___vt__14TObjDFUsoTower {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
u8 * __ct__8TObjBaseFP7TObject(void *);
extern RecoveredGlobal_80052200_lbl_804858A8 lbl_804858A8;
extern s32 __vt__14TObjDFUsoTower[];
extern s32 TObjDFUsoTower__name;
extern const f32 lbl_805D8A30;
s32 rand();
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__14TObjDFUsoTowerFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjDFUsoTower;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80052200_lbl_804858A8_size[sizeof(RecoveredGlobal_80052200_lbl_804858A8) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80052200___vt__14TObjDFUsoTower_size[sizeof(RecoveredGlobal_80052200___vt__14TObjDFUsoTower) == 0x34 ? 1 : -1];
u8 *TObjDFUsoTower__ct(u8 *obj_df_uso_tower, s32 _w1) {
    __ct__8TObjBaseFP7TObject(obj_df_uso_tower);
    *(s32 **)((s8 *)obj_df_uso_tower + 0x18) = &(*(RecoveredGlobal_80052200___vt__14TObjDFUsoTower *)&__vt__14TObjDFUsoTower).value;
    *(s32 *)((s8 *)obj_df_uso_tower + 0) = (s32) TObjDFUsoTower__name;
    *(s32 *)((s8 *)obj_df_uso_tower + 0x34) = get_bml_model(TOBoss4::model_resource, 5);
    ((TObjDFUsoTower *)obj_df_uso_tower)->texlist = TObjFish__sub_8001EDB0(TOBoss4::model_resource, 5);
    VecCopy((Vec *)(obj_df_uso_tower + 0x38), (const Vec *)&lbl_804858A8.value);
    *(f32 *)((s8 *)obj_df_uso_tower + 0x94) = (f32) lbl_805D8A30;
    ((TObjDFUsoTower *)obj_df_uso_tower)->m_90 = 0;
    return obj_df_uso_tower;
}

void *TObjDFUsoTower::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjDFUsoTower__ct((u8 *)o, (s32)arg0);
    }
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
