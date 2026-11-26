#include "types.h"

// The gibon enemy's constant tables.

__declspec(section ".rodata") extern const u32 gibon_base_stat_ids[2] = {
    0x0000003B, 0x0000003C,
};

__declspec(section ".rodata") extern const u32 gibon_attack_stat_ids[2] = {
    0x0000003B, 0x0000003C,
};

__declspec(section ".rodata") extern const u32 gibon_resist_stat_ids[2] = {
    0x0000003B, 0x0000003C,
};

__declspec(section ".rodata") extern const u32 gibon_param_ids[2] = {
    0x0000003B, 0x0000003C,
};
