#include "types.h"
#include "pso/boss/TObjBoss2Tunnel_802F2070.h"
#include "pso/unk/text_802F1FB0.h"
#include "pso/unk/TUnk_804E4B24.h"
#include "pso/boss/TObjBoss7TunnelCol.h"

struct RecoveredGlobal_802F1FB0_lbl_804E4978 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_802F1FB0_lbl_804E4B24 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *, int, int);
s32 __ct__7TObjectFP7TObject();
s32 copy_position__16TBoss8DragonDemoFv(int, void *);
extern RecoveredGlobal_802F1FB0_lbl_804E4978 boss2_tunnel_effect_name_table;
extern RecoveredGlobal_802F1FB0_lbl_804E4B24 __vt__13TUnk_804E4B24;
typedef char RecoveredGlobal_802F1FB0_lbl_804E4978_size[sizeof(RecoveredGlobal_802F1FB0_lbl_804E4978) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_802F1FB0_lbl_804E4B24_size[sizeof(RecoveredGlobal_802F1FB0_lbl_804E4B24) == 0x18 ? 1 : -1];
u8 *fn_802F1FB0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 farg0) {
    s32 temp_r5;
    s32 temp_r6;
    u8 *temp_r31;
    __ct__7TObjectFP7TObject();
    temp_r5 = arg2 * 8;
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804E4B24.value;
    temp_r6 = *(s32 *)((s8 *)arg1 + 0x10);
    temp_r31 = (u8 *)&boss2_tunnel_effect_name_table.value + temp_r5;
    ((TUnk_804E4B24 *)arg0)->m_34 = temp_r6;
    VecCopy__FP3VecPC3Vec(arg0 + 0x1C, (void *)arg3, (int)temp_r5, (int)temp_r6);
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    ((TUnk_804E4B24 *)arg0)->m_3c = (s32) *(s32 *)((s8 *)temp_r31 + 4);
    *(s32 *)((s8 *)arg0 + 0x38) = (s32) *(s32 *)((s8 *)temp_r31 + 0);
    ((TUnk_804E4B24 *)arg0)->m_40 = arg2;
    *(f32 *)((s8 *)arg0 + 0x44) = farg0;
    if (arg2 == 4) {
        copy_position__16TBoss8DragonDemoFv((int) (((TUnk_804E4B24 *)arg0)->m_34), arg0 + 0x1C);
        TObjBoss2Tunnel__sub_802F2278();
    }
    ((TUnk_804E4B24 *)arg0)->update_collision();
    return arg0;
}

}
