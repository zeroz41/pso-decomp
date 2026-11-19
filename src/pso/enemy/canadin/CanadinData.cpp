#include "types.h"

// Data-only unit split off the canadin enemy: four identical node-index lists
// at 0x8043A180. The referencing unit keeps these extern (separate lis/addi).

__declspec(section ".rodata") extern const u32 lbl_8043A180[3] = {
    0x00000007, 0x00000008, 0x00000009,
};

__declspec(section ".rodata") extern const u32 lbl_8043A18C[3] = {
    0x00000007, 0x00000008, 0x00000009,
};

__declspec(section ".rodata") extern const u32 lbl_8043A198[3] = {
    0x00000007, 0x00000008, 0x00000009,
};

__declspec(section ".rodata") extern const u32 lbl_8043A1A4[3] = {
    0x00000007, 0x00000008, 0x00000009,
};
