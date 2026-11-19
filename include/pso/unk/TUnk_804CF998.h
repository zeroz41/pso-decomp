#ifndef PSO_UNK_TUNK_804CF998_H
#define PSO_UNK_TUNK_804CF998_H

#include "types.h"
#include "pso/unk/TUnk_804CF918.h"

// A window part with a position and size (case 0 of init_window_layout_entries).
class TUnk_804CF998 : public TUnk_804CF918 {
public:
    f32 x;
    f32 y;
    f32 width;
    f32 height;

    TUnk_804CF998(s32 m_2);
    TUnk_804CF998(u8 *rec, s32 m_2);
    virtual ~TUnk_804CF998();
    virtual void update();
    virtual void render(WindowDrawContext *context);
};

typedef char TUnk_804CF998_size[sizeof(TUnk_804CF998) == 0x18 ? 1 : -1];

extern "C" {
// The constructors and destructor, called by the parts that are still written by hand.
void *__ct__13TUnk_804CF998Fl(void *p, s32 m_2);
void *__ct__13TUnk_804CF998FPUcl(void *p, u8 *rec, s32 m_2);
void *__dt__13TUnk_804CF998Fv(void *p, s16 flags);
}

#endif
