#include "types.h"

// Data-only unit split off the mericarol enemy at 0x804722E8; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_804722E8[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};

__declspec(section ".rodata") extern const u32 lbl_804722F4[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};

__declspec(section ".rodata") extern const u32 lbl_80472300[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};

__declspec(section ".rodata") extern const u32 lbl_8047230C[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};
