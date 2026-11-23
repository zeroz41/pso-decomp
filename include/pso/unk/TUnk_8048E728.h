#ifndef PSO_UNK_TUNK_8048E728_H
#define PSO_UNK_TUNK_8048E728_H
#include "types.h"
#include "pso/effect/particle/ParticleParam.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

struct GinjaTextureList;

class TUnk_8048E728 : public TObject {
public:
    TUnk_8048E728(ParticleParam *src, TObject *parent);
    virtual ~TUnk_8048E728();
    static void *operator new(size_t size);
    static void operator delete(void *p);
    void apply_particle_model_fade_color(s32);
    void draw_particle_refraction_quad();
    s32 is_particle_sprite_additive(s32 render_flags);
    u16 sprite_index;          // 0x1C, index into the particle sprite table
    u8 pad_1e[0x2];
    ParticleParam *param;      // 0x20
    u16 flags;                 // 0x24
    u16 target_id;             // 0x26, entity the particle follows (flags & 0x10)
    f32 size_x;                // 0x28, from ParticleParam size_min/size_range, decays by scale_decay
    f32 size_y;                // 0x2C
    Vec origin;                // 0x30
    Vec step;                  // 0x3C, last movement
    f32 unk_48;
    f32 color_base[3];         // 0x4C, used when flags & 0x100
    f32 age;                   // 0x58, 0..1 over the lifetime
    f32 age_rate;              // 0x5C
    f32 fade_in_scale;         // 0x60
    f32 fade_out_scale;        // 0x64
    f32 speed;                 // 0x68
    void *draw_next;           // 0x6C, link in the sprite draw list (append_node_to_tail)
    Vec pos;                   // 0x70
    Vec attach;                // 0x7C, offset to the followed entity
    f32 draw_scale_x;          // 0x88, quad width scale used when drawing
    f32 draw_scale_y;          // 0x8C, quad height scale
    u32 color;                 // 0x90, packed ARGB
    s8 frame;                  // 0x94, sprite frame
    s8 screen_space;           // 0x95, 1: pos is already in screen space
    s16 roll;                  // 0x96, rotation of the drawn quad
    s32 rot_x;                 // 0x98, model rotation angles
    s32 rot_y;                 // 0x9C
    s32 rot_z;                 // 0xA0
    f32 scale_x;               // 0xA4, multiplies the drawn size
    f32 scale_y;               // 0xA8
    u8 from_particle_heap;     // 0xAC, set by operator new: 1 = TParticleCtrl__heap
    u8 pad_ad[0x3];
    void *model;               // 0xB0, the Ginja model drawn when flags & 0x200
    GinjaTextureList *texlist; // 0xB4, textures of model
    NJS_MOTION *motion;        // 0xB8
    f32 motion_frame;          // 0xBC
};

#endif
