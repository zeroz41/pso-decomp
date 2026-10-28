#include "types.h"
#include "pso/unk/text_80086E28.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/unk/text_80302FD8.h"
#include "pso/unk/TObjEneDellBiter_Eff_TpAbsorb1.h"
#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/TParticleCtrl.h"
struct Stack_80302FD8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_80302FD8_lbl_8047512C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80302FD8_lbl_804E6AF8 {
    s32 value;
    u8 remaining[0x58];
};

extern "C" {
f32 sin_table_lookup(void *);
f32 cos_table_lookup(void *);
extern RecoveredGlobal_80302FD8_lbl_8047512C lbl_8047512C;
extern RecoveredGlobal_80302FD8_lbl_804E6AF8 lbl_804E6AF8;
extern s32 TObjEneDellBiter_Eff_TpAbsorb1__class_name;
extern const f32 lbl_805DEFAC;
typedef char RecoveredGlobal_80302FD8_lbl_8047512C_size[sizeof(RecoveredGlobal_80302FD8_lbl_8047512C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80302FD8_lbl_804E6AF8_size[sizeof(RecoveredGlobal_80302FD8_lbl_804E6AF8) == 0x5C ? 1 : -1];
u8 *fn_80302FD8(u8 *ene_dell_biter_eff_tp_absorb1, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_80302FD8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80302FD8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80302FD8, sp10) == 0x8) ? 1 : -1];
    Stack_80302FD8 stack;
    construct_collision_body((ene_dell_biter_eff_tp_absorb1), (arg1), (arg2));
    *(s32 **)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0x18) = &lbl_804E6AF8.value;
    *(s32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0) = (s32) TObjEneDellBiter_Eff_TpAbsorb1__class_name;
    *(f32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0xC8) = farg0;
    *(f32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0xC0) = (f32) lbl_805DEFAC;
    ((TObjEneDellBiter_Eff_TpAbsorb1 *)ene_dell_biter_eff_tp_absorb1)->m_c4 = (f32) lbl_805DEFAC;
    VecCopy((Vec *)(ene_dell_biter_eff_tp_absorb1 + 0x38), (const Vec *)(arg3));
    *(f32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0xB0) = sin_table_lookup((void *)arg4);
    ((TObjEneDellBiter_Eff_TpAbsorb1 *)ene_dell_biter_eff_tp_absorb1)->m_b4 = (f32) lbl_805DEFAC;
    *(f32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0xB8) = cos_table_lookup((void *)arg4);
    ((TObjEneDellBiter_Eff_TpAbsorb1 *)ene_dell_biter_eff_tp_absorb1)->m_bc = arg5;
    *(s32 *)((s8 *)(((TObjEneDellBiter_Eff_TpAbsorb1 *)ene_dell_biter_eff_tp_absorb1)->bodies) + 0x14) = 1;
    stack.spC = *(s32 *)((s8 *)&lbl_8047512C.value + 4);
    stack.sp8 = *(s32 *)((s8 *)&lbl_8047512C.value + 0);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8047512C.value + 8);
    stack.spC = arg4 - 0x4000;
    *(s32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0xCC) = (s32)create_particle_controller_with_angles((ene_dell_biter_eff_tp_absorb1 + 0x38), (&stack.sp8), 0x210, 0x32, 2);
    ((TParticleCtrl *)(*(s32 *)((s8 *)ene_dell_biter_eff_tp_absorb1 + 0xCC)))->clear_active_flag();
    return ene_dell_biter_eff_tp_absorb1;
}

}
