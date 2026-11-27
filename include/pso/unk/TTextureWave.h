#ifndef PSO_UNK_TTEXTUREWAVE_H
#define PSO_UNK_TTEXTUREWAVE_H
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureInput.h"

struct NJS_TEXLIST;
struct GvrTexture;

// A texture image that update_texture_wave_image redraws distorted every frame (TEF_PvrWave).
class TTextureWave {
public:
    s32 height;
    s32 width;
    s32 texture_id;
    NJS_TEXNAME texture_name;
    GinjaTextureInput texture_input;
    NJS_TEXLIST *texture_list;
    GvrTexture *image_data;
    GvrTexture *output;
    s32 displacement;
    s32 phase;

    TTextureWave(NJS_TEXLIST *list);
    virtual void advance_wrapped_cursor();
    virtual void update_texture_wave_image();
    // Redraws output from image_data, shifting each texel by the displacement map at the current phase.
    void distort_image();
    ~TTextureWave();
    void init_image_buffer(u8 *image, s32 displacement);
};

LAYOUT_ASSERT(TTextureWave_size, sizeof(TTextureWave) == 0x54);

#endif
