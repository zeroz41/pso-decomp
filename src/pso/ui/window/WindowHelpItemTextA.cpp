#include "types.h"

// Data-only unit split off the window help item at 0x8044EDA8 (class-name string and help text); the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 TWindowHelpItem__class_name_string[4] = {
    0x5457696E, 0x646F7748, 0x656C7049, 0x74656D00,
};

__declspec(section ".rodata") extern const u8 lbl_8044EDB8[5] ATTRIBUTE_ALIGN(4) = {
    0x4D, 0x49, 0x4E, 0x44, 0x00,
};

__declspec(section ".rodata") extern const u8 lbl_8044EDC0[10] ATTRIBUTE_ALIGN(4) = {
    0x4C, 0x65, 0x76, 0x65, 0x6C, 0x20, 0x55, 0x70, 0x21, 0x00,
};
