#include "types.h"

// Data-only unit split off the technique ringwave name table at 0x8044D5D0; the .data list lbl_804CC8C8 keeps these extern.

__declspec(section ".rodata") extern const u8 lbl_8044D5D0[17] ATTRIBUTE_ALIGN(4) = {
    0x66, 0x30, 0x33, 0x32, 0x5F, 0x6C, 0x69, 0x67, 0x68, 0x74, 0x6E, 0x69, 0x6E, 0x67, 0x30, 0x31,
    0x00,
};

__declspec(section ".rodata") extern const u32 lbl_8044D5E4[3] = {
    0x66303634, 0x5F72696E, 0x67303100,
};

__declspec(section ".rodata") extern const u32 lbl_8044D5F0[3] = {
    0x66303634, 0x5F72696E, 0x67303200,
};

__declspec(section ".rodata") extern const u32 lbl_8044D5FC[3] = {
    0x66303634, 0x5F72696E, 0x67303300,
};

__declspec(section ".rodata") extern const u32 lbl_8044D608[3] = {
    0x66303634, 0x5F72696E, 0x67303400,
};

__declspec(section ".rodata") extern const u32 lbl_8044D614[3] = {
    0x66303634, 0x5F72696E, 0x67303500,
};

__declspec(section ".rodata") extern const u32 lbl_8044D620[3] = {
    0x66303634, 0x5F72696E, 0x67303600,
};

__declspec(section ".rodata") extern const u32 lbl_8044D62C[3] = {
    0x66303634, 0x5F72696E, 0x67303700,
};

__declspec(section ".rodata") extern const u32 lbl_8044D638[3] = {
    0x66303634, 0x5F72696E, 0x67303800,
};
