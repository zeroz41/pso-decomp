#include "types.h"

// Data-only unit split off the berura enemy at 0x80439DA0; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 lbl_80439DA0[2] = {
    0x0000000E, 0x00000013,
};

__declspec(section ".rodata") extern const u32 TObjEneRe7Berura__data_80439DA8[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 TObjEneRe7Berura__data_80439DB0[2] = {
    0x00000000, 0x00000001,
};

__declspec(section ".rodata") extern const u32 TObjEneRe7Berura__data_80439DB8[2] = {
    0x00000000, 0x00000000,
};
