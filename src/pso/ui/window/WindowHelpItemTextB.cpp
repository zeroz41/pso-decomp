#include "types.h"

// Data-only unit split off the window help item at 0x8044EDD8 (help text); the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u8 lbl_8044EDD8[7] ATTRIBUTE_ALIGN(4) = {
    0x4E, 0x61, 0x74, 0x69, 0x76, 0x65, 0x00,
};

__declspec(section ".rodata") extern const u32 lbl_8044EDE0[2] = {
    0x412E4265, 0x61737400,
};

__declspec(section ".rodata") extern const u32 lbl_8044EDE8[2] = {
    0x4D616368, 0x696E6500,
};

__declspec(section ".rodata") extern const u8 lbl_8044EDF0[5] ATTRIBUTE_ALIGN(4) = {
    0x44, 0x61, 0x72, 0x6B, 0x00,
};
