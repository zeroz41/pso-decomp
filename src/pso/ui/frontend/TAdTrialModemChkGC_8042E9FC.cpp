#include "types.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/ResetConnectParam.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"

extern "C" {
extern char lbl_80480270[];

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
// disassembly by tools/orig_asm.py) is byte-exact on 20/20.  force_active: nothing
// calls it, so the linker would strip it.  `static` so the
// symbol stays local, as the original object declares it.
#pragma push
#pragma force_active on
static asm void pad_03_8042E9FC_text(void) {
#include "orig_asm/pso/ui/frontend/TAdTrialModemChkGC_8042E9FC/pad_03_8042E9FC_text.inc"
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TAdTrialModemChkGC::init_modem_check_params() {
    return reset_connect_param(lbl_80480270);
}
#pragma pop

}
