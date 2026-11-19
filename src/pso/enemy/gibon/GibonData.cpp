#include "types.h"

// Data-only unit split off the gibon enemy at 0x8043BF30; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_8043BF30[2] = {
    0x0000003B, 0x0000003C,
};

__declspec(section ".rodata") extern const u32 lbl_8043BF38[2] = {
    0x0000003B, 0x0000003C,
};

__declspec(section ".rodata") extern const u32 lbl_8043BF40[2] = {
    0x0000003B, 0x0000003C,
};

__declspec(section ".rodata") extern const u32 lbl_8043BF48[2] = {
    0x0000003B, 0x0000003C,
};
