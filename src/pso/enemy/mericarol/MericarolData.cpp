#include "types.h"

// Data-only unit split off the mericarol enemy at 0x804722E8; TObjEneBm9Mericarol.h declares these.

__declspec(section ".rodata") extern const u32 mericarol_phase_hp_ids[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};

__declspec(section ".rodata") extern const u32 mericarol_phase_attack_ids[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};

__declspec(section ".rodata") extern const u32 mericarol_phase_resist_ids[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};

__declspec(section ".rodata") extern const u32 mericarol_phase_param_ids[3] = {
    0x0000003A, 0x00000045, 0x00000046,
};
