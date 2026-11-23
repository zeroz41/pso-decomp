#ifndef PSO_MISC_TEF_LENSFLARE_H
#define PSO_MISC_TEF_LENSFLARE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// One reflected flare element: a sprite drawn on the line from the light's
// screen position to the screen centre, as render() reads it.
struct LensFlareElement {
    s32 sprite;      // index into the particle sprite table
    f32 position;    // 0 at the light, 1 at the screen centre
    f32 size;
    f32 shrink;      // how much of the size goes as the light leaves the view centre
    f32 brightness;
    f32 pad_14;      // -10.0, -10.1, ... -10.9 in the table; render() never reads it
};

// A screen sprite node as TQuadSpriteSclColRot::render reads it; render() only
// fills it on the stack, so the link and type byte stay unset.
struct FlareSprite {
    FlareSprite *next;
    Vec pos;
    Vec offset;
    f32 scale_x;
    f32 scale_y;
    u32 color;
    u8 frame;
    u8 type;
    u16 angle;
};

// The flare colour, copied into the sprite as a whole word.
struct FlareColor {
    struct { u8 a, r, g, b; } argb;
} ATTRIBUTE_ALIGN(4);

// The glare colour: its alpha goes through a signed int before it is cut to a byte.
struct FlareGlareColor {
    struct { signed int a : 8; u8 r, g, b; } argb;
};

struct TEF_LensFlare : public TObjBase {
    static const char *class_name;
    TEF_LensFlare(TObject *parent, void *set_data);
    virtual ~TEF_LensFlare();
    virtual void render();
    virtual void run_task();
    // 1 when the local player is at least sqrt(range_sq) away on the xz plane.
    int is_player_out_of_range(f32 range_sq);
    LensFlareElement *elements;  // 0x90, the table render() draws 9 of
};

LAYOUT_ASSERT(TEF_LensFlare_size, sizeof(TEF_LensFlare) == 0x94);
#endif
