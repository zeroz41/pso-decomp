#ifndef PSO_UNK_TUNK_804C57E0_H
#define PSO_UNK_TUNK_804C57E0_H
#include "types.h"

class TUnk_804C57E0 {
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

    virtual void advance_wrapped_cursor();
    virtual void update_texture_wave_image();
    ~TUnk_804C57E0();
    void init_image_buffer(u8 *arg1, s32 arg2);
};

typedef char TUnk_804C57E0_size[sizeof(TUnk_804C57E0) == 0x54 ? 1 : -1];

extern "C" {
// TUnk_804C57E0::~TUnk_804C57E0(), called by the destructors that are still written by hand.
void *__dt__13TUnk_804C57E0Fv(void *p, s16 flags);
}

#endif
