#include "types.h"

// Data-only unit split off the berura enemy at 0x80439DA0; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 berura_attack_stat_ids[2] = {
    0x0000000E, 0x00000013,
};

__declspec(section ".rodata") extern const u32 TObjEneRe7Berura__base_stat_rows[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 TObjEneRe7Berura__attack_stat_rows[2] = {
    0x00000000, 0x00000001,
};

__declspec(section ".rodata") extern const u32 TObjEneRe7Berura__resist_stat_rows[2] = {
    0x00000000, 0x00000000,
};
