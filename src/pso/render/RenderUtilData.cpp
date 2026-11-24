#include "types.h"

// Data-only unit split off render_util at 0x8043F298; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 sqrt_double_zero[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 sqrt_double_half[2] = {
    0x3FE00000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 sqrt_double_three[2] = {
    0x40080000, 0x00000000,
};
