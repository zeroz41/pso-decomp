#include "types.h"

// TObjChara's constants (doubles, MESETA/MISS, angle scale); TObjChara.cpp declares them extern.

__declspec(section ".rodata") extern const u32 accuracy_distance_penalty_scale[2] = {
    0x3F847AE1, 0x47AE147B,
};

__declspec(section ".rodata") extern const u32 newton_sqrt_half[2] = {
    0x3FE00000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 newton_sqrt_three[2] = {
    0x40080000, 0x00000000,
};

__declspec(section ".rodata") extern const u8 meseta_label_text[7] ATTRIBUTE_ALIGN(4) = {
    0x4D, 0x45, 0x53, 0x45, 0x54, 0x41, 0x00,
};

__declspec(section ".rodata") extern const char miss_label_text[5] ATTRIBUTE_ALIGN(4) = "MISS";

__declspec(section ".rodata") extern const u32 angle_units_per_radian[2] = {
    0x40C45F30, 0xB21788BB,
};
