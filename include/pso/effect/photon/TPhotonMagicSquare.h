#ifndef PSO_EFFECT_PHOTON_TPHOTONMAGICSQUARE_H
#define PSO_EFFECT_PHOTON_TPHOTONMAGICSQUARE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"

struct AnimationMotion;

// The magic circle drawn under a photon blast: model 2 of the shared photon
// blast resource, played through its motion while it grows in and fades out.
struct TPhotonMagicSquare : public TObjBase {
    TPhotonMagicSquare(TObject *parent, s32 palette_index, const Vec *pos, s32 duration, f32 fade_rate);
    TPhotonMagicSquare(TObject *parent, s32 palette_index, const Vec *pos, s32 duration);
    TPhotonMagicSquare(TObject *parent, s32 palette_index, u16 owner_id);
    virtual ~TPhotonMagicSquare();
    virtual void render();
    virtual void run_task();

    AnimationMotion *motion;
    f32 last_frame;
    f32 frame_step;
    f32 frame;
    NJS_ARGB color;
    u32 age;        // frames since it appeared
    u32 state;      // 0 growing in, 1 fading out
    Vec pos;        // where it is drawn
    u32 duration;   // frames before it starts to fade
    f32 fade_rate;  // scale and alpha change per frame
    u32 flash_period;  // every this many frames it draws grey

    static NJS_ARGB color_palette[6];
};

LAYOUT_ASSERT(TPhotonMagicSquare_color_offset, offsetof(TPhotonMagicSquare, color) == 0xA0);
LAYOUT_ASSERT(TPhotonMagicSquare_origin_offset, offsetof(TPhotonMagicSquare, pos) == 0xB8);
LAYOUT_ASSERT(TPhotonMagicSquare_size, sizeof(TPhotonMagicSquare) == 0xD0);
#endif
