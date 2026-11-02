#include "types.h"
#include "pso/unk/text_800A02AC.h"
#include "pso/system/vector.h"

struct RecoveredGlobal_800A02AC_lbl_80490458 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_800A02AC_lbl_80490458 __vt__29TObjEneMe1Canadin_EffLineFade;
extern s32 TObjEneMe1Canadin_EffLineFade__class_name;
typedef char RecoveredGlobal_800A02AC_lbl_80490458_size[sizeof(RecoveredGlobal_800A02AC_lbl_80490458) == 0x18 ? 1 : -1];
u8 *fn_800A02AC(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__29TObjEneMe1Canadin_EffLineFade.value;
    *(s32 *)((s8 *)object + 0) = (s32) TObjEneMe1Canadin_EffLineFade__class_name;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg3);
    *(s32 *)((s8 *)object + 0x34) = 0xFFFF0033;
    *(s32 *)((s8 *)object + 0x38) = 0xFFFF0033;
    return object;
}

}
