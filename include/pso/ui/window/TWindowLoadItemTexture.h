#ifndef PSO_UI_WINDOW_TWINDOWLOADITEMTEXTURE_H
#define PSO_UI_WINDOW_TWINDOWLOADITEMTEXTURE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowLoadItemTexture : public TWindowBase {
    TWindowLoadItemTexture(u8 *parent, void *pos, s32 client);
    virtual ~TWindowLoadItemTexture();
    virtual void render();
    u8 _pad1C[0x8];
    void* m_24;
    u8 unk_28[0x10];
    f32 m_38;
    u8 unk_3C[0x24];
    u8 m_60;
    u8 m_61;
    u8 _pad62[0x2];
    void* m_64;
    u8 _pad68[0x4];
    u32 m_6c;
    u32 m_70;
    void *create(void *arg1);
    virtual void run_task();
};

typedef char TWindowLoadItemTexture_size[sizeof(TWindowLoadItemTexture) == 0x74 ? 1 : -1];

extern "C" {
void fn_80262C2C(void *p);
void render__22TWindowLoadItemTextureFv(TWindowLoadItemTexture *arg0);
}

// --- C functions defined in TWindowLoadItemTexture.cpp ---
extern "C" {
TWindowLoadItemTexture *fn_802628C0(void *layout, void *table, void *id);
void fn_80262C2C(void *p);
void render__22TWindowLoadItemTextureFv(TWindowLoadItemTexture *arg0);
}
// --- end of C functions

#endif
