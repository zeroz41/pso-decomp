#include "types.h"

// TObjChara's constants (doubles, MESETA/MISS, angle scale); TObjChara.cpp declares them extern.

__declspec(section ".rodata") extern const u32 lbl_80434090[2] = {
    0x3F847AE1, 0x47AE147B,
};

__declspec(section ".rodata") extern const u32 lbl_80434098[2] = {
    0x3FE00000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 lbl_804340A0[2] = {
    0x40080000, 0x00000000,
};

__declspec(section ".rodata") extern const u8 lbl_804340A8[7] ATTRIBUTE_ALIGN(4) = {
    0x4D, 0x45, 0x53, 0x45, 0x54, 0x41, 0x00,
};

__declspec(section ".rodata") extern const char lbl_804340B0[5] ATTRIBUTE_ALIGN(4) = "MISS";

__declspec(section ".rodata") extern const u32 TObjPlayer__data_804340B8[2] = {
    0x40C45F30, 0xB21788BB,
};
