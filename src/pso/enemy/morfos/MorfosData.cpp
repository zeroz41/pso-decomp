#include "types.h"

// Data-only unit split off the morfos enemy at 0x804774A0; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_804774A0[2] = {
    0x00000040, 0x00000050,
};

__declspec(section ".rodata") extern const u32 lbl_804774A8[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 lbl_804774B0[2] = {
    0x00000000, 0x00000001,
};

__declspec(section ".rodata") extern const u32 lbl_804774B8[2] = {
    0x00000000, 0x00000000,
};
