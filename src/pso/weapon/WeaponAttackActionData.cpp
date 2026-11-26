#include "types.h"

// Data-only unit split off the weapon attack actions; the referencing unit keeps these extern.

__declspec(section ".rodata") extern const u32 srank_weapon_model_ids[4] = {
    0xAAABACAD, 0xAEAFB0B1, 0xB2B3B4B5, 0xB6B7B800,
};

__declspec(section ".rodata") extern const u32 weapon_light_direction[3] = {
    0x00000000, 0x00000000, 0x3F800000,
};

__declspec(section ".rodata") extern const u32 weapon_light_color[5] = {
    0x3F800000, 0x3F4CCCCD, 0x3F4CCCCD, 0x3F800000,
    0x00000000,
};
