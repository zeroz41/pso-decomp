#include "types.h"

// Data-only unit split off the gee enemy at 0x8043BCD8; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_8043BCD8[3] = {
    0x00000007, 0x00000007, 0x00000007,
};

__declspec(section ".rodata") extern const u32 lbl_8043BCE4[3] = {
    0x00000007, 0x00000007, 0x00000007,
};

__declspec(section ".rodata") extern const u32 lbl_8043BCF0[3] = {
    0x00000007, 0x00000007, 0x00000007,
};

__declspec(section ".rodata") extern const u32 lbl_8043BCFC[3] = {
    0x00000007, 0x00000007, 0x00000007,
};
