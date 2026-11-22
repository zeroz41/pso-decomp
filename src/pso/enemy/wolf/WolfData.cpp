#include "types.h"

// Data-only unit split off the wolf enemy at 0x8043B3A8; the referencing unit keeps these extern.

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
