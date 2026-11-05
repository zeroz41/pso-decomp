#include "types.h"
#include "pso/misc/TUnk_804CCA90.h"
#include "pso/misc/TTecMegid_80235B24.h"
#include "pso/object/TObject_80019A50.h"

#include "pso/misc/TTecMegid.h"
#include "pso/unk/text_80235BDC.h"
#include "pso/system/vector.h"

extern "C" {

s32 play_sound_effect(s32, void *, s32, s32);

void TUnk_804CCA90::run_task() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x1E) = (s16) (*(s16 *)((s8 *)arg0 + 0x1E) + 1);
    if ((s16) *(s16 *)((s8 *)arg0 + 0x1E) > (s16) *(s16 *)((s8 *)arg0 + 0x1C)) {
        play_sound_effect(*(s32 *)((s8 *)arg0 + 0x20), arg0 + 0x24, 0, 0);
        queue_destruction__7TObjectFv(arg0);
    }
}

}
TUnk_804CCA90::~TUnk_804CCA90() {

}

struct RecoveredGlobal_80235BDC_lbl_804CCA90 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
}
extern RecoveredGlobal_80235BDC_lbl_804CCA90 __vt__13TUnk_804CCA90;
typedef char RecoveredGlobal_80235BDC_lbl_804CCA90_size[sizeof(RecoveredGlobal_80235BDC_lbl_804CCA90) == 0x18 ? 1 : -1];
u8 *construct_delayed_point_sound(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3, u8 *arg4) {
    __ct__7TObjectFP7TObject(arg0, arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804CCA90.value;
    *(s16 *)((s8 *)arg0 + 0x1C) = arg2;
    ((TUnk_804CCA90 *)arg0)->m_1e = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = arg3;
    VecCopy((Vec *)(arg0 + 0x24), (const Vec *)arg1);
    return arg0;
}
