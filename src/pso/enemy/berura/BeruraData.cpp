#include "types.h"
#include "pso/enemy/berura/BeruraData.h"

// The berura enemy's constant tables.

__declspec(section ".rodata") extern const s32 berura_attack_stat_ids[2] = {
    0x0000000E, 0x00000013,
};

__declspec(section ".rodata") extern const s32 re7_berura_base_stat_rows[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const s32 re7_berura_attack_stat_rows[2] = {
    0x00000000, 0x00000001,
};

__declspec(section ".rodata") extern const s32 re7_berura_resist_stat_rows[2] = {
    0x00000000, 0x00000000,
};
