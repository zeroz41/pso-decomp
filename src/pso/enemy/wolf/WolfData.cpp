#include "types.h"

// The wolf enemy's constant tables.

__declspec(section ".rodata") extern const u32 wolf_base_stat_ids[2] = {
    0x00000002, 0x00000003,
};

__declspec(section ".rodata") extern const u32 wolf_attack_stat_ids[2] = {
    0x00000002, 0x00000003,
};

__declspec(section ".rodata") extern const u32 wolf_resist_stat_ids[2] = {
    0x00000002, 0x00000003,
};

__declspec(section ".rodata") extern const u32 wolf_param_ids[2] = {
    0x00000002, 0x00000003,
};
