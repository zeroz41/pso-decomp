#include "types.h"

// Data-only unit split off ChallengeMode data at 0x805D2850; the referencing unit keeps these extern.

extern u8 lbl_80438570[];

__declspec(section ".sdata") extern u32 lbl_805D2850[2] = {
    (uaddr)lbl_80438570, 0x00000000,
};

__declspec(section ".sdata") extern u32 lbl_805D2858[1] = {
    0x00000000,
};

__declspec(section ".sdata") extern u32 lbl_805D285C[1] = {
    0x00000000,
};
