#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TSlicerHistory.h"
#include "pso/system/vector.h"
#include "pso/misc/TTecSlicer.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 __ct__7TObjectFP7TObject();

extern s32 __vt__14TSlicerHistory[];
extern s32 lbl_805D382C;
extern const f32 lbl_805DC948;
extern const f32 lbl_805DC950;

u8 *__ct__14TSlicerHistoryFv(u8 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TSlicerHistory;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D382C;
    ((TObjPlayer *)(arg0 + 0x1C))->copy_xyz((void *)(arg1 + 0x5C));
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(arg1 + 0x38));
    *(s32 *)((s8 *)arg0 + 0x38) = arg2;
    if (arg3 != 0U) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 1;
        copy_argb((NJS_ARGB *)(arg0 + 0x3C), (NJS_ARGB *)arg3);
    } else {
        *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805DC948;
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805DC950;
        *(f32 *)((s8 *)arg0 + 0x44) = (f32) lbl_805DC950;
        *(f32 *)((s8 *)arg0 + 0x48) = (f32) lbl_805DC950;
    }
    *(s32 *)((s8 *)arg0 + 0x34) = ((TTecSlicer *)arg1)->get_field_110();
    VecCopy((Vec *)(arg0 + 0x4C), (const Vec *)(arg1 + 0x68));
    *(s32 *)((s8 *)arg0 + 0x58) = arg4;
    return arg0;
}

}
