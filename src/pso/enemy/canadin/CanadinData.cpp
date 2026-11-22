#include "types.h"

// Data-only unit split off the canadin enemy: the stat ids of the three kinds, which
// TObjEneMe1Canadin::load_resources registers with TLobby.

__declspec(section ".rodata") extern const u32 canadin_base_stat_ids[3] = {
    0x00000007, 0x00000008, 0x00000009,
};

__declspec(section ".rodata") extern const u32 canadin_attack_stat_ids[3] = {
    0x00000007, 0x00000008, 0x00000009,
};

__declspec(section ".rodata") extern const u32 canadin_resist_stat_ids[3] = {
    0x00000007, 0x00000008, 0x00000009,
};

__declspec(section ".rodata") extern const u32 canadin_param_ids[3] = {
    0x00000007, 0x00000008, 0x00000009,
};
