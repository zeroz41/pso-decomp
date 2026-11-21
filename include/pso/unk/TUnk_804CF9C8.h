#ifndef PSO_UNK_TUNK_804CF9C8_H
#define PSO_UNK_TUNK_804CF9C8_H

#include "types.h"
#include "pso/unk/TUnk_804CF998.h"

// A window part that draws a number right-aligned (case 4 of init_window_layout_entries).
class TUnk_804CF9C8 : public TUnk_804CF998 {
public:
    f32 depth;
    s32 style;
    s32 value;

    TUnk_804CF9C8(u8 *rec, s32 m_2);
    virtual ~TUnk_804CF9C8();
    virtual void update();
    virtual void render(WindowDrawContext *context);
};

LAYOUT_ASSERT(TUnk_804CF9C8_size, sizeof(TUnk_804CF9C8) == 0x24);

// A number part that counts towards its target (case 5 of init_window_layout_entries).
class TUnk_804CF9E0 : public TUnk_804CF9C8 {
public:
    f32 current;
    f32 target;
    f32 step;

    TUnk_804CF9E0(u8 *rec, s32 m_2);
    virtual ~TUnk_804CF9E0();
    virtual void update();
};

LAYOUT_ASSERT(TUnk_804CF9E0_size, sizeof(TUnk_804CF9E0) == 0x30);

extern "C" {
// The constructors, called by init_window_layout_entries.
void *__ct__13TUnk_804CF9C8FPUcl(void *p, u8 *rec, s32 m_2);
void *__ct__13TUnk_804CF9E0FPUcl(void *p, u8 *rec, s32 m_2);
}

#endif
