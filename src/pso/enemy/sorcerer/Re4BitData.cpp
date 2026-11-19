#include "types.h"

// Data-only unit split off the re4 bit enemy at 0x8043D2B0; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_8043D2B0[2] = {
    0x0000000B, 0x0000000C,
};

__declspec(section ".rodata") extern const u32 lbl_8043D2B8[2] = {
    0x0000000B, 0x0000000C,
};

__declspec(section ".rodata") extern const u32 lbl_8043D2C0[2] = {
    0x0000000B, 0x0000000C,
};

__declspec(section ".rodata") extern const u32 lbl_8043D2C8[2] = {
    0x0000000B, 0x0000000C,
};

__declspec(section ".rodata") extern const u8 TObjEneRe4Bit__class_name_string[14] ATTRIBUTE_ALIGN(4) = {
    0x54, 0x4F, 0x62, 0x6A, 0x45, 0x6E, 0x65, 0x52, 0x65, 0x34, 0x42, 0x69, 0x74, 0x00,
};

__declspec(section ".rodata") extern const u32 re4_bit_render_vec[4] = {
    0x3F000000, 0x3F800000, 0x3F000000, 0x00000000,
};
