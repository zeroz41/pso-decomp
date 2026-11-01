#ifndef PSO_MISC_TWINDOWLOADITEMTEXTURE_H
#define PSO_MISC_TWINDOWLOADITEMTEXTURE_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowLoadItemTexture : public TWindowBase {
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
void *TWindowLoadItemTexture__ct(TWindowLoadItemTexture *window_load_item_texture, void *arg1, void *arg2, void *arg3);
void *__dt__22TWindowLoadItemTextureFv(void *arg0, s16 arg1);
void fn_80262C2C(void *p);
void render__22TWindowLoadItemTextureFv(TWindowLoadItemTexture *arg0);
}

// --- C functions defined in TWindowLoadItemTexture.cpp ---
extern "C" {
void *TWindowLoadItemTexture__ct(TWindowLoadItemTexture *window_load_item_texture, void *arg1, void *arg2, void *arg3);
void *__dt__22TWindowLoadItemTextureFv(void *arg0, s16 arg1);
void fn_80262C2C(void *p);
void render__22TWindowLoadItemTextureFv(TWindowLoadItemTexture *arg0);
}
// --- end of C functions

#endif
