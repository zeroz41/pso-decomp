#ifndef PSO_ENEMY_SORCERER_RE4BITDATA_H
#define PSO_ENEMY_SORCERER_RE4BITDATA_H

#include "types.h"
#include "pso/system/vector.h"

// The Bit's read-only data, defined in its own unit: TObjEneRe4Bit::load_resources loads
// each table's address on its own, where data the Bit unit defines shares one base.
// The ids TObjEneRe4Bit::load_resources hands TLobby, one per variant.
extern const s32 re4_bit_base_param_ids[2];
extern const s32 re4_bit_attack_param_ids[2];
extern const s32 re4_bit_resistance_param_ids[2];
extern const s32 re4_bit_behavior_param_ids[2];
extern const char TObjEneRe4Bit__class_name_string[];

struct Re4BitShadowScale {
    Vec scale;
    u32 reserved;
};

extern const Re4BitShadowScale re4_bit_render_vec;

#endif
