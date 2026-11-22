#include "types.h"

// Data-only unit split off the gibon enemy at 0x8043BF30; the referencing unit keeps these extern.

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
