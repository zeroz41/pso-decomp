#include "types.h"

// Data-only unit split off the gee enemy at 0x8043BCD8; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 gee_base_stat_ids[3] = {
    0x00000007, 0x00000007, 0x00000007,
};

__declspec(section ".rodata") extern const u32 gee_attack_stat_ids[3] = {
    0x00000007, 0x00000007, 0x00000007,
};

__declspec(section ".rodata") extern const u32 gee_resist_stat_ids[3] = {
    0x00000007, 0x00000007, 0x00000007,
};

__declspec(section ".rodata") extern const u32 gee_param_ids[3] = {
    0x00000007, 0x00000007, 0x00000007,
};
