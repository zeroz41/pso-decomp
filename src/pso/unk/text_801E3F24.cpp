#include "types.h"
#include "pso/unk/text_801E3F24.h"

// GX FIFO write helpers and a word copy, called only by the draw helpers of
// TLobby_801E2F94.cpp; the 6x subcommand handlers after them open TGameProtocol.cpp.
extern "C" {
void TObjPlayer__sub_801E3F24(s32 arg0) {
    *(s32 *)0xCC008000 = arg0;
}

void TObjPlayer__sub_801E3F30(f32 farg0, f32 farg1, f32 farg2) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
    *(f32 *)0xCC008000 = farg2;
}

void fn_801E3F44(f32 farg0, f32 farg1) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
}

void *TObjCMHairMenu__sub_801E3F54(void *p, void *q) {
    *(u32 *)p = *(u32 *)q;
    return p;
}
}
