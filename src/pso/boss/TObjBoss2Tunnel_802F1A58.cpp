#include "types.h"
#include "pso/boss/TObjBoss2Tunnel_802F1A58.h"
#include "pso/boss/TUnk_804E4AD4.h"
#include "pso/boss/TObjBoss2Tunnel.h"

struct RecoveredGlobal_802F1AE0_lbl_804E4AD4 { s32 value; u8 remaining[0x14]; };

extern "C" {
extern const f32 lbl_805DEC98;
s32 get_bml_motion(void *, s32);
s32 get_bml_model(void *, s32);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804E4AD4[];
extern u8 *boss7_common_bml_resource;
extern const f32 lbl_805DEC9C;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TUnk_804E4AD4::run_task() {
    f32 temp_f0;
    f32 temp_f1;
    *(f32 *)&this->unk_28 = (f32) (*(f32 *)&this->unk_28 + lbl_805DEC98);
    temp_f1 = this->m_24;
    temp_f0 = *(f32 *)&this->unk_28;
    if (temp_f1 <= temp_f0) {
        *(f32 *)&this->unk_28 = (f32) (temp_f0 - temp_f1);
    }
}

void *__dt__13TUnk_804E4AD4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804E4AD4;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjBoss2Tunnel__sub_802F1AE0(u8 *arg0, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802F1AE0_lbl_804E4AD4 *)&__vt__13TUnk_804E4AD4).value;
    *(s32 *)((s8 *)arg0 + 0x1C) = get_bml_model(boss7_common_bml_resource, arg2 + 0x11);
    ((TUnk_804E4AD4 *)arg0)->m_20 = get_bml_motion(boss7_common_bml_resource, arg2);
    ((TUnk_804E4AD4 *)arg0)->m_24 = (f32) ((f32) *(u32 *)((s8 *)(((TUnk_804E4AD4 *)arg0)->m_20) + 4) - lbl_805DEC98);
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) lbl_805DEC9C;
    return arg0;
}

}
