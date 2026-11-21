#ifndef PSO_UNK_TUNK_804CFA28_H
#define PSO_UNK_TUNK_804CFA28_H

#include "types.h"

struct WindowDrawContext;

class TUnk_804CFA28 {
public:
    u16 flags;
    s16 m_2;
    virtual ~TUnk_804CFA28();
    virtual void update();
    virtual void render(WindowDrawContext *);
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    f32 m_18;
    f32 m_1c;
    char *text;
    s32 color;
    f32 m_28;
};

LAYOUT_ASSERT(TUnk_804CFA28_size, sizeof(TUnk_804CFA28) == 0x2C);
#endif
