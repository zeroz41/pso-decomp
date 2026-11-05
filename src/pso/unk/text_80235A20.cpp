#include "types.h"
#include "pso/unk/TUnk_804CCA78.h"
#include "pso/misc/TLobby_80226070.h"
#include "pso/unk/text_80235A20.h"

struct RecoveredGlobal_80235A20_lbl_804CCA78 { s32 value; u8 remaining[0x14]; };

extern "C" {
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_80235A20_lbl_804CCA78 lbl_804CCA78;
u8 *__dt__13TUnk_804CCA78Fv(u8 *arg0, s16 arg1) {
    s32 temp_r3;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804CCA78.value;
        temp_r3 = ((TUnk_804CCA78 *)arg0)->m_24;
        if (temp_r3 >= 0) {
            stop_sound_request(temp_r3);
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}


extern "C" {
s32 update_technique_slot__10TTecRaFoieFl(int, void *, int);
s32 play_sound_effect(int, void *, int, int);
s32 __ct__7TObjectFP7TObject(void *, void *);
}
u8 *construct_timed_sound_voice(u8 *arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 handle;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg5);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804CCA78.value;
    *(s16 *)((s8 *)arg0 + 0x1C) = arg2;
    ((TUnk_804CCA78 *)arg0)->m_1e = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = arg3;
    ((TUnk_804CCA78 *)arg0)->m_24 = play_sound_effect((int) (*(s32 *)((s8 *)arg0 + 0x20)), (void *)arg1, 0, 0);
    handle = ((TUnk_804CCA78 *)arg0)->m_24;
    if ((handle >= 0) && (arg4 != 0)) {
        update_technique_slot__10TTecRaFoieFl((int)handle, (void *)arg4, 0);
    }
    return arg0;
}
