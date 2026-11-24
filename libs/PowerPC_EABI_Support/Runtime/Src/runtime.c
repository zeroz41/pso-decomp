#pragma ANSI_strict off
#pragma tvectors off
#pragma internal on

#define SAVE_FPR(reg) _savefpr_##reg
#define RESTORE_FPR(reg) _restfpr_##reg
#define SAVE_GPR(reg) _savegpr_##reg
#define RESTORE_GPR(reg) _restgpr_##reg
#define ENTRY_SAVE_FPR(reg) entry SAVE_FPR(reg)
#define ENTRY_RESTORE_FPR(reg) entry RESTORE_FPR(reg)
#define ENTRY_SAVE_GPR(reg) entry SAVE_GPR(reg)
#define ENTRY_RESTORE_GPR(reg) entry RESTORE_GPR(reg)
#define SAVE_FPR2(reg) _savef##reg
#define RESTORE_FPR2(reg) _restf##reg
#define ENTRY_SAVE_FPR2(reg)
#define ENTRY_RESTORE_FPR2(reg)

#define save_restore_reg r11

asm void __div2u(void);
asm void __div2i(void);
asm void __mod2u(void);
asm void __mod2i(void);
asm void __shl2i(void);
asm void __shr2u(void);
asm void __shr2i(void);
asm void __cvt_sll_dbl(void);
asm void __cvt_sll_flt(void);
asm void __cvt_dbl_usll(void);

void SAVE_FPR(14)(void);
void SAVE_FPR(15)(void);
void SAVE_FPR(16)(void);
void SAVE_FPR(17)(void);
void SAVE_FPR(18)(void);
void SAVE_FPR(19)(void);
void SAVE_FPR(20)(void);
void SAVE_FPR(21)(void);
void SAVE_FPR(22)(void);
void SAVE_FPR(23)(void);
void SAVE_FPR(24)(void);
void SAVE_FPR(25)(void);
void SAVE_FPR(26)(void);
void SAVE_FPR(27)(void);
void SAVE_FPR(28)(void);
void SAVE_FPR(29)(void);
void SAVE_FPR(30)(void);
void SAVE_FPR(31)(void);
void SAVE_FPR2(14)(void);
void SAVE_FPR2(15)(void);
void SAVE_FPR2(16)(void);
void SAVE_FPR2(17)(void);
void SAVE_FPR2(18)(void);
void SAVE_FPR2(19)(void);
void SAVE_FPR2(20)(void);
void SAVE_FPR2(21)(void);
void SAVE_FPR2(22)(void);
void SAVE_FPR2(23)(void);
void SAVE_FPR2(24)(void);
void SAVE_FPR2(25)(void);
void SAVE_FPR2(26)(void);
void SAVE_FPR2(27)(void);
void SAVE_FPR2(28)(void);
void SAVE_FPR2(29)(void);
void SAVE_FPR2(30)(void);
void SAVE_FPR2(31)(void);
void RESTORE_FPR(14)(void);
void RESTORE_FPR(15)(void);
void RESTORE_FPR(16)(void);
void RESTORE_FPR(17)(void);
void RESTORE_FPR(18)(void);
void RESTORE_FPR(19)(void);
void RESTORE_FPR(20)(void);
void RESTORE_FPR(21)(void);
void RESTORE_FPR(22)(void);
void RESTORE_FPR(23)(void);
void RESTORE_FPR(24)(void);
void RESTORE_FPR(25)(void);
void RESTORE_FPR(26)(void);
void RESTORE_FPR(27)(void);
void RESTORE_FPR(28)(void);
void RESTORE_FPR(29)(void);
void RESTORE_FPR(30)(void);
void RESTORE_FPR(31)(void);
void RESTORE_FPR2(14)(void);
void RESTORE_FPR2(15)(void);
void RESTORE_FPR2(16)(void);
void RESTORE_FPR2(17)(void);
void RESTORE_FPR2(18)(void);
void RESTORE_FPR2(19)(void);
void RESTORE_FPR2(20)(void);
void RESTORE_FPR2(21)(void);
void RESTORE_FPR2(22)(void);
void RESTORE_FPR2(23)(void);
void RESTORE_FPR2(24)(void);
void RESTORE_FPR2(25)(void);
void RESTORE_FPR2(26)(void);
void RESTORE_FPR2(27)(void);
void RESTORE_FPR2(28)(void);
void RESTORE_FPR2(29)(void);
void RESTORE_FPR2(30)(void);
void RESTORE_FPR2(31)(void);
void SAVE_GPR(14)(void);
void SAVE_GPR(15)(void);
void SAVE_GPR(16)(void);
void SAVE_GPR(17)(void);
void SAVE_GPR(18)(void);
void SAVE_GPR(19)(void);
void SAVE_GPR(20)(void);
void SAVE_GPR(21)(void);
void SAVE_GPR(22)(void);
void SAVE_GPR(23)(void);
void SAVE_GPR(24)(void);
void SAVE_GPR(25)(void);
void SAVE_GPR(26)(void);
void SAVE_GPR(27)(void);
void SAVE_GPR(28)(void);
void SAVE_GPR(29)(void);
void SAVE_GPR(30)(void);
void SAVE_GPR(31)(void);
void RESTORE_GPR(14)(void);
void RESTORE_GPR(15)(void);
void RESTORE_GPR(16)(void);
void RESTORE_GPR(17)(void);
void RESTORE_GPR(18)(void);
void RESTORE_GPR(19)(void);
void RESTORE_GPR(20)(void);
void RESTORE_GPR(21)(void);
void RESTORE_GPR(22)(void);
void RESTORE_GPR(23)(void);
void RESTORE_GPR(24)(void);
void RESTORE_GPR(25)(void);
void RESTORE_GPR(26)(void);
void RESTORE_GPR(27)(void);
void RESTORE_GPR(28)(void);
void RESTORE_GPR(29)(void);
void RESTORE_GPR(30)(void);
void RESTORE_GPR(31)(void);

static const unsigned __constants[] = {
    0x00000000, 0x00000000,
    0x41F00000, 0x00000000,
    0x41E00000, 0x00000000,
};

asm unsigned __cvt_fp2unsigned(register double d) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__cvt_fp2unsigned.inc"
}

#pragma force_active on
asm void __save_fpr(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__save_fpr.inc"
}

asm void __restore_fpr(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__restore_fpr.inc"
}

asm void __save_gpr(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__save_gpr.inc"
}

asm void __restore_gpr(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__restore_gpr.inc"
}
#pragma force_active reset

asm void __div2u(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__div2u.inc"
}

asm void __div2i(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__div2i.inc"
}

asm void __mod2u(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__mod2u.inc"
}

asm void __mod2i(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__mod2i.inc"
}

asm void __shl2i(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__shl2i.inc"
}

asm void __shr2u(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__shr2u.inc"
}

asm void __shr2i(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__shr2i.inc"
}

asm void __cvt_sll_dbl(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__cvt_sll_dbl.inc"
}

asm void __cvt_sll_flt(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__cvt_sll_flt.inc"
}

asm void __cvt_dbl_usll(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/runtime/__cvt_dbl_usll.inc"
}
