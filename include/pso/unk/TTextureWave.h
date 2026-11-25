#ifndef PSO_UNK_TTEXTUREWAVE_H
#define PSO_UNK_TTEXTUREWAVE_H
#include "types.h"

struct NJS_TEXLIST;

// A texture image that update_texture_wave_image redraws distorted every frame (TEF_PvrWave).
class TTextureWave {
public:
    s32 height;
    s32 width;
    s32 texture_id;
    u8 records[0x30];
    s32 texture_list;
    u8 *image_data;
    s32 output;
    s32 displacement;
    s32 phase;

    TTextureWave(NJS_TEXLIST *list);
    virtual void advance_wrapped_cursor();
    virtual void update_texture_wave_image();
    ~TTextureWave();
    void init_image_buffer(u8 *image, s32 displacement);
};

LAYOUT_ASSERT(TTextureWave_size, sizeof(TTextureWave) == 0x54);

extern "C" {
// TTextureWave::~TTextureWave(), called by the destructors that are still written by hand.
void *__dt__12TTextureWaveFv(void *p, s16 flags);
}

#endif
