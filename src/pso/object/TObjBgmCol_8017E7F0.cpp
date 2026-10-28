#include "types.h"
#include "pso/object/TObjBgmCol_8017E7F0.h"
#include "pso/object/TObjBgmCol.h"
#include "pso/object/TObjMotion.h"

extern "C" {

s32 __ct__8TObjBaseFP7TObject();
void __dl__7TObjectFPv(void *);

extern s32 __vt__10TObjBgmCol[];

void *__dt__10TObjBgmColFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TObjBgmCol;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TObjBgmCol__name;

void *TObjBgmCol__ct(TObjBgmCol *bgm_col, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject();
    *(s32 **)((s8 *)bgm_col + 0x18) = __vt__10TObjBgmCol;
    *(s32 *)((s8 *)bgm_col + 0) = (s32) TObjBgmCol__name;
    bgm_col->apply_object_set_data((void *)arg2);
    bgm_col->m_90 = 1;
    bgm_col->m_98 = (f32) bgm_col->scale.x;
    bgm_col->m_9c = (s32) (bgm_col->set_params[0] % 6);
    if ((s32) bgm_col->m_9c < 0) {
        bgm_col->m_9c = 0;
    }
    return bgm_col;
}

extern char lbl_80443870[];
s32 TObjBgmCol__name = (s32)lbl_80443870;
}
