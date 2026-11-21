#ifndef PSO_UI_WINDOW_TWINDOWMESETA_H
#define PSO_UI_WINDOW_TWINDOWMESETA_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowMeseta : public TWindowBase {
    TWindowMeseta(saddr parent, s32 client, s32 text);
    virtual ~TWindowMeseta();
    virtual void render();
    f32 m_60;
    u32 m_64;
    u32 m_68;
    void* m_6c;
    void run_task();
    s32 get_meseta_value();
    void draw_value(s32 ctx);
    void set_value(s32 value);
    u8 unk_70[0x4];
};

LAYOUT_ASSERT(TWindowMeseta_size, sizeof(TWindowMeseta) == 0x74);
#endif
