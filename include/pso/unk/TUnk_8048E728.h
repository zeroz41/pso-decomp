#ifndef PSO_UNK_TUNK_8048E728_H
#define PSO_UNK_TUNK_8048E728_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

// Emitter parameter record a particle is built from (init_particle_base).
struct ParticleParam {
    u8 pad_0[0x2C];
    f32 scale_decay;           // 0x2C, size factor per frame
    f32 unk_30;                // 0x30
    f32 unk_34;                // 0x34
    f32 unk_38;                // 0x38, orbit particles: green colour rate
    f32 unk_3C;                // 0x3C, orbit particles: blue colour rate
    u8 pad_40[0x10];
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
};

// Sprite set of a particle texture slot: flags bit 0 = additive.
struct ParticleSpriteSet {
    u32 flags;
    u8 pad_4[0x8];
    s32 frame_count;           // 0xC
};

struct ParticleTexture {
    u8 pad_0[0x28];
    ParticleSpriteSet *sprites; // 0x28
};

class TUnk_8048E728 : public TObject {
public:
    virtual ~TUnk_8048E728();
    void free_from_heap();
    void apply_particle_model_fade_color(s32);
    void draw_particle_refraction_quad();
    s32 is_particle_sprite_additive();
    u16 sprite_index;          // 0x1C, index into the particle sprite table
    u8 pad_1e[0x2];
    ParticleParam *param;      // 0x20, set by init_particle_base
    u16 flags;                 // 0x24
    u16 target_id;             // 0x26, entity the particle follows (flags & 0x10)
    f32 m_28;
    f32 unk_2C;
    Vec origin;                // 0x30
    Vec step;                  // 0x3C, last movement
    u8 pad_48[0x4];
    f32 color_base[3];         // 0x4C, used when flags & 0x100
    f32 age;                   // 0x58, 0..1 over the lifetime
    f32 age_rate;              // 0x5C
    f32 fade_in_scale;         // 0x60
    f32 fade_out_scale;        // 0x64
    f32 speed;                 // 0x68
    u8 pad_6c[0x4];
    Vec pos;                   // 0x70
    Vec attach;                // 0x7C, offset to the followed entity
    f32 m_88;
    u8 unk_8C[0x4];
    u32 color;                 // 0x90, packed ARGB
    s8 frame;                  // 0x94, sprite frame
    u8 pad_95[0x1];
    s16 m_96;
    s32 unk_98;
    s32 m_9c;
    s32 unk_A0;
    f32 m_a4;
    f32 unk_A8;
    u8 pad_ac[0x4];
    u32 m_b0;
    u8 unk_B4[0x4];
    NJS_MOTION *motion;        // 0xB8
    f32 motion_frame;          // 0xBC
};

#endif
