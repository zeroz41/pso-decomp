#include "types.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/ui/TAdTrialModemChkGC.h"

extern "C" {
int sprintf(char *, const char *, ...);
void *memset(void *, int, u32);
extern char lbl_80480270[];
extern s32 lbl_805D7CA8;
extern u8 *lbl_805D7CC0;
extern s32 lbl_805D7CC4;

// pad_03_8042E9FC_text: the frame-restore epilogue of the reset relocator
// fn_8042E8C4 (previous unit).  That function leaves through an epilogue-free
// computed jump (lwz r0,0xE0(r26); isync; mtlr r0; blr), but the compiler
// still emitted the lmw/mtlr/addi/blr restore after it; the split boundary at
// 0x8042E9FC drops those 5 words into this unit as an unclaimed code gap.  No
// C construct can produce an epilogue with no prologue: probed every installed
// MWCC in build/compilers/GC/ (20 versions, unit profile -O4,p -inline off
// -use_lmw_stmw on -lang=c++): an empty function gives `blr` (0x4), a
// callee-register-hungry function gives prologue+stmw+epilogue (0x50), and
// statement-level asm is wrapped in its own frame (0x28..0x30).  0/20 emit the
// 20 bytes; the function-level asm body (generated from the original
// disassembly by tools/orig_asm.py) is byte-exact on 20/20.  `static` so the
// symbol stays local, as the original object declares it.
static asm void pad_03_8042E9FC_text(void) {
#include "orig_asm/pso/unk/text_8042E9FC/pad_03_8042E9FC_text.inc"
}

s32 TAdTrialModemChkGC::init_modem_check_params() {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    memset(lbl_805D7CC0 + 0x7020, 0, 0x800);
    *(s32 *)((s8 *)lbl_805D7CC0 + 0x1C) = 0x674;
    sprintf((char *) (lbl_805D7CC4 + 4), lbl_80480270);
    TAdPlayerLoadGC__sub_8042F108(0);
    TAdTrialModemChkGC__sub_8042F0D4(3);
    set_modem_trial_param(1);
    TAdTrialModemChkGC__sub_8042F080(3);
    set_modem_check_param(3);
    set_modem_flag(1);
    set_modem_check_char(1);
    set_modem_param(5);
    set_modem_check_param_360(0);
    *(s32 *)((s8 *)lbl_805D7CC0 + 4) = (s32) (*(s32 *)((s8 *)lbl_805D7CC0 + 4) & 0xFFFFF7FF);
    return 0;
}

}
