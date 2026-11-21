#ifndef PSO_EFFECT_PARTICLE_PARTICLEPARAM_H
#define PSO_EFFECT_PARTICLE_PARTICLEPARAM_H

#include "types.h"
#include <stddef.h>

// One 0x98-byte record in particleentry.dat or a floor particle-entry file.
struct ParticleParam {
    u8 pad_00[0x10];
    s32 generator_kind;
    s32 unk_14;                // 0x14, looked up with find_particle_texture_index
    u8 pad_18[0x14];
    f32 scale_decay;           // 0x2C, size factor per frame
    f32 unk_30;                // 0x30
    f32 unk_34;                // 0x34
    f32 unk_38;                // 0x38, orbit particles: green colour rate
    f32 unk_3C;                // 0x3C, orbit particles: blue colour rate
    f32 emission_frequency;    // +0x40, oscillation frequency in degrees
    f32 emission_rate;         // +0x44, amount emitted per frame
    u8 pad_48[0x8];
    union {
        f32 speed_decay;       // 0x50
        f32 orbit_red_rate;    // 0x50, orbit particles
    };
    f32 gravity;               // 0x54, added to the step's y
    f32 fade_in_end;           // 0x58
    f32 fade_out_start;        // 0x5C
    f32 unk_60;                // 0x60
    f32 unk_64;                // 0x64
    u8 pad_68[0x4];
    union {
        f32 color_rate[3];     // 0x6C, colour change per unit of age
        f32 orbit_spin_rate;   // 0x6C, orbit particles
    };
    u8 pad_78[0x4];
    f32 color_base[3];         // 0x7C
    u8 flags;                  // 0x88
    u8 tail_89[0xF];
};

LAYOUT_ASSERT(ParticleParamSize, sizeof(ParticleParam) == 0x98);
LAYOUT_ASSERT(ParticleParamGeneratorOffset, offsetof(ParticleParam, generator_kind) == 0x10);
LAYOUT_ASSERT(ParticleParamEmissionOffset, offsetof(ParticleParam, emission_frequency) == 0x40);
LAYOUT_ASSERT(ParticleParamFlagsOffset, offsetof(ParticleParam, flags) == 0x88);

extern "C" {
extern ParticleParam *particle_global_entry_table;
extern ParticleParam *particle_area_entry_table;
}

#endif
