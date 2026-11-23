#ifndef PSO_EFFECT_PARTICLE_PARTICLEPARAM_H
#define PSO_EFFECT_PARTICLE_PARTICLEPARAM_H

#include "types.h"
#include <stddef.h>
#include <dolphin/mtx/GeoTypes.h>

// The slots at 0x6C that orbit particles read instead of colour rates.
struct ParticleOrbitRates {
    f32 spin_rate;             // pulse angle step in degrees
    f32 pulse;                 // size pulse amplitude
    f32 angular_speed_range;
};

// One 0x98-byte record in particleentry.dat or a floor particle-entry file.
// The particles a generator kind creates read some slots differently.
struct ParticleParam {
    u8 pad_00[0x10];
    s32 generator_kind;
    s32 sprite_id;             // 0x14, looked up with find_particle_texture_index
    Vec spawn_spread;          // 0x18, random spawn offset around the emitter
    f32 size_min;              // 0x24
    f32 size_range;            // 0x28
    f32 scale_decay;           // 0x2C, size factor per frame
    f32 speed_min;             // 0x30, orbit particles: angular speed in degrees
    f32 rise_min;              // 0x34, upward speed
    union {
        f32 speed_range;       // 0x38
        f32 orbit_green_rate;  // 0x38, orbit particles
    };
    union {
        f32 rise_range;        // 0x3C
        f32 orbit_blue_rate;   // 0x3C, orbit particles
    };
    f32 emission_frequency;    // +0x40, oscillation frequency in degrees
    f32 emission_rate;         // +0x44, amount emitted per frame
    s32 life_min;              // 0x48, frames
    s32 life_range;            // 0x4C
    union {
        f32 speed_decay;       // 0x50
        f32 orbit_red_rate;    // 0x50, orbit particles
    };
    f32 gravity;               // 0x54, added to the step's y
    f32 fade_in_end;           // 0x58
    f32 fade_out_start;        // 0x5C
    union {
        f32 bounce;            // 0x60, ballistic: rise factor when it falls below its origin, spin when it does not move
        f32 streak_width;      // 0x60, radial particles: width per unit of the step's length
        f32 orbit_radius_min;  // 0x60, orbit particles
    };
    union {
        f32 tilt;              // 0x64, ballistic: roll per unit of the step
        f32 streak_height;     // 0x64, radial particles
        f32 orbit_radius_range; // 0x64, orbit particles
    };
    union {
        f32 ballistic_streak_height; // 0x68, ballistic streaks; their width is `tilt`
        f32 orbit_rise_range;  // 0x68, orbit particles
    };
    union {
        f32 color_rate[3];     // 0x6C, colour change per unit of age
        ParticleOrbitRates orbit; // 0x6C, orbit particles
    };
    u8 pad_78[0x4];
    f32 color_base[3];         // 0x7C
    u8 flags;                  // 0x88
    u8 pad_89[0xF];
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
