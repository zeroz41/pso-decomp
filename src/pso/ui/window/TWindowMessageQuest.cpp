#include "types.h"
#include "pso/ui/window/TWindowMessageQuest.h"

TWindowMessageQuest::~TWindowMessageQuest() {

}

extern "C" {
extern s32 __vt__19TWindowMessageQuest[];
u8 *TWindowMessage__ct(u8 *arg0, s32 arg1, u32 arg2, s32 arg3);
extern s32 lbl_805D39A0;
extern s32 local_client_id;
u8 *TWindowMessageQuest__ct(u8 *arg0, s32 arg1) {
    TWindowMessage__ct((arg0), (arg1), 1, (local_client_id));
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowMessageQuest;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D39A0;
    *(s32 *)((s8 *)arg0 + 0x90) = 0;
    return arg0;
}

}
