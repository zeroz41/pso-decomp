#ifndef PSO_UNK_TTEXTUREWAVE_H
#define PSO_UNK_TTEXTUREWAVE_H
#include "types.h"

struct NJS_TEXLIST;

// A texture image that update_texture_wave_image redraws distorted every frame (TEF_PvrWave).
class TTextureWave {
public:
    s32 m_0;
    s32 m_4;
    s32 m_8;
    u8 m_c[0x30];
    s32 m_3c;
    u8 *m_40;
    s32 m_44;
    s32 m_48;
    s32 m_4c;

    TTextureWave(NJS_TEXLIST *texture_list);
    virtual void advance_wrapped_cursor();
    virtual void update_texture_wave_image();
    ~TTextureWave();
    void init_image_buffer(u8 *arg1, s32 arg2);
};

LAYOUT_ASSERT(TTextureWave_size, sizeof(TTextureWave) == 0x54);

extern "C" {
// TTextureWave::~TTextureWave(), called by the destructors that are still written by hand.
void *__dt__12TTextureWaveFv(void *p, s16 flags);
}

#endif
