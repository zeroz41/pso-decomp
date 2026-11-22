#include "types.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"

// Data-only unit split off the morfos enemy at 0x804774A0; the referencing unit keeps these extern.

__declspec(section ".rodata") const s32 morfos_attack_param_ids[2] = {
    0x00000040, 0x00000050,
};

__declspec(section ".rodata") const s32 morfos_base_params_index[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") const s32 morfos_attack_params_index[2] = {
    0x00000000, 0x00000001,
};

__declspec(section ".rodata") const s32 morfos_resistance_params_index[2] = {
    0x00000000, 0x00000000,
};
