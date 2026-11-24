#include "types.h"
#include "pso/enemy/sorcerer/Re4BitData.h"

// The Bit enemy's read-only data (Re4BitData.h says why it is a unit of its own).

__declspec(section ".rodata") extern const s32 re4_bit_base_param_ids[2] = {11, 12};

__declspec(section ".rodata") extern const s32 re4_bit_attack_param_ids[2] = {11, 12};

__declspec(section ".rodata") extern const s32 re4_bit_resistance_param_ids[2] = {11, 12};

__declspec(section ".rodata") extern const s32 re4_bit_behavior_param_ids[2] = {11, 12};

__declspec(section ".rodata") extern const char TObjEneRe4Bit__class_name_string[14] ATTRIBUTE_ALIGN(4) = "TObjEneRe4Bit";

__declspec(section ".rodata") extern const Re4BitShadowScale re4_bit_render_vec = {
    {0.5f, 1.0f, 0.5f}, 0,
};
