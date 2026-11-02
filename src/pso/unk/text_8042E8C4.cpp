#include "types.h"

// Reset-payload relocator: copies the header+image at `arg` to 0x80003100,
// stores it, OSResetSystem(2,0,0), clears the [0xd8] region, replays the
// 7-entry (delta,dst,len) move/store/invalidate table at base+0x00/+0x48/
// +0x90 and the 11-entry move/store table at +0x1c/+0x64/+0xac (base =
// arg->0x104), then tail-jumps into the reloaded image at base+0xE0.
//
// The tail is an epilogue-free computed jump (lwz r0,0xE0(r26); isync;
// mtlr r0; blr).  No installed MWCC (probed GC/1.2.5, 2.0p1, 2.5, 2.6,
// 2.7, 3.0a5.2) can emit that from C: every inline-asm `blr` variant
// still appends the lmw/mtlr/addi/blr epilogue, and the only
// epilogue-dropping terminator (for(;;)) emits a `b .` word the object
// does not contain.  Body is therefore kept as function-level asm
// (nofralloc) per the TRK_MINNOW/musyx orig_asm precedent, byte-exact.

extern "C" {

void* memmove(void*, const void*, u32);
void* memset(void*, s32, u32);
void DCStoreRange(void*, u32);
void ICInvalidateRange(void*, u32);
int OSResetSystem(int, int, int);

asm void LaunchDol(register void* dol) {
#include "orig_asm/pso/unk/text_8042E8C4/LaunchDol.inc"
}

}
