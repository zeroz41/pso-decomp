#ifndef PSO_EFFECT_PARTICLE_TPARTICLE_H
#define PSO_EFFECT_PARTICLE_TPARTICLE_H
#include "types.h"
#include "pso/effect/particle/ParticleParam.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

struct NJS_TEXLIST;
struct ParticleAngles;
class TParticleCtrl;

class TParticle : public TObject {
public:
    TParticle(ParticleParam *src, TObject *parent);
    virtual ~TParticle();
    static void *operator new(size_t size);
    static void operator delete(void *p);
    void apply_particle_model_fade_color(s32);
    void draw_particle_refraction_quad();
    s32 is_particle_sprite_additive(s32 render_flags);
    // Sets flags 0x2000 and requests indirect effect 0x1F (the refraction quad).
    void mark_active();
    // Sets the model rotation angles.
    void set_rotation(ParticleAngles *rotation);
    // Draws model (texlist, motion) instead of the sprite; loop repeats the motion.
    void attach_model(void *model, NJS_TEXLIST *texlist, NJS_MOTION *motion, s32 loop, f32 speed);
    // Tints the particle by rgba (flags 0x100).
    void set_tint_color(NJS_ARGB *rgba);
    void set_draw_scale(f32 x, f32 y);
    u16 sprite_index;          // 0x1C, index into the particle sprite table
    u8 pad_1e[0x2];
    ParticleParam *param;      // 0x20
    u16 flags;                 // 0x24
    u16 target_id;             // 0x26, entity the particle follows (flags & 0x10)
    f32 size_x;                // 0x28, from ParticleParam size_min/size_range, decays by scale_decay
    f32 size_y;                // 0x2C
    Vec origin;                // 0x30
    Vec step;                  // 0x3C, last movement
    NJS_ARGB tint;             // 0x48, used when flags & 0x100
    f32 age;                   // 0x58, 0..1 over the lifetime
    f32 age_rate;              // 0x5C
    f32 fade_in_scale;         // 0x60
    f32 fade_out_scale;        // 0x64
    f32 speed;                 // 0x68
    // 0x6C: the particle's entry in the draw list of its sprite (append_node_to_tail); pos is where it is,
    // offset the distance to the followed entity, scale_x/scale_y the quad size, uv_index the sprite frame,
    // type 1 when pos is already in screen space, angle the roll of the quad.
    QuadSpriteNode sprite;
    s32 rot_x;                 // 0x98, model rotation angles
    s32 rot_y;                 // 0x9C
    s32 rot_z;                 // 0xA0
    f32 scale_x;               // 0xA4, multiplies the drawn size
    f32 scale_y;               // 0xA8
    u8 from_particle_heap;     // 0xAC, set by operator new: 1 = TParticleCtrl::heap
    u8 pad_ad[0x3];
    void *model;               // 0xB0, the Ginja model drawn when flags & 0x200
    NJS_TEXLIST *texlist; // 0xB4, textures of model
    NJS_MOTION *motion;        // 0xB8
    f32 motion_frame;          // 0xBC
    f32 motion_speed;          // 0xC0, motion frames per frame
};

#endif
