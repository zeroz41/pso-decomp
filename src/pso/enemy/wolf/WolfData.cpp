#include "types.h"

// Data-only unit split off the wolf enemy at 0x8043B3A8; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_8043B3A8[2] = {
    0x00000002, 0x00000003,
};

__declspec(section ".rodata") extern const u32 lbl_8043B3B0[2] = {
    0x00000002, 0x00000003,
};

__declspec(section ".rodata") extern const u32 lbl_8043B3B8[2] = {
    0x00000002, 0x00000003,
};

__declspec(section ".rodata") extern const u32 lbl_8043B3C0[2] = {
    0x00000002, 0x00000003,
};
