#ifndef PSO_UNK_TUNK_804EF440_H
#define PSO_UNK_TUNK_804EF440_H

#include "types.h"
#include "pso/unk/TUnk_804CF998.h"

// A window list row with an icon, a name, three message columns and a count
// (case 12 of init_window_layout_entries).
class TUnk_804EF440 : public TUnk_804CF998 {
public:
    s32 m_18;
    s8 icon;
    s8 m_1d;
    s8 m_1e;
    s8 m_1f;
    s8 m_20;
    s8 m_21;
    char *text;

    TUnk_804EF440(u8 *rec, s32 m_2);
    virtual ~TUnk_804EF440();
    virtual void update();
    virtual void render(WindowDrawContext *context);
};

LAYOUT_ASSERT(TUnk_804EF440_size, sizeof(TUnk_804EF440) == 0x28);

extern "C" {
// TUnk_804EF440::TUnk_804EF440(u8 *, s32), called by init_window_layout_entries.
void *__ct__13TUnk_804EF440FPUcl(void *p, u8 *rec, s32 m_2);
}

#endif
