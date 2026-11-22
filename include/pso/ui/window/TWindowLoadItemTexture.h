#ifndef PSO_UI_WINDOW_TWINDOWLOADITEMTEXTURE_H
#define PSO_UI_WINDOW_TWINDOWLOADITEMTEXTURE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowLoadItemTexture : public TWindowBase {
    TWindowLoadItemTexture(u8 *parent, void *pos, s32 client);
    virtual ~TWindowLoadItemTexture();
    virtual void render();
    u8 m_60;
    u8 m_61;
    u8 _pad62[0x2];
    void* m_64;
    u8 _pad68[0x4];
    u32 m_6c;
    u32 m_70;
    void *create(void *client);
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowLoadItemTexture_size, sizeof(TWindowLoadItemTexture) == 0x74);

extern "C" {
void fn_80262C2C(void *p);
}

// --- C functions defined in TWindowLoadItemTexture.cpp ---
extern "C" {
TWindowLoadItemTexture *fn_802628C0(void *layout, void *table, void *id);
void fn_80262C2C(void *p);
}
// --- end of C functions

#endif
