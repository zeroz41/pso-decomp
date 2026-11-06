#ifndef PSO_UI_FRONTEND_TADRICORINGCTRL_H
#define PSO_UI_FRONTEND_TADRICORINGCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdRicoRingCtrl : public TObject {
    virtual ~TAdRicoRingCtrl();
    void sub_8001B424(s32);
    virtual void render();
    u32 m_1c;
    u32 m_20;
    void set_scale4(f32 farg0);
    static void *create(void *arg0);
    static void release_global_805D4A00();
    static void load_static_resource();
    void start_fade_all(f32 x);
    virtual void run_task();
    void start_fade(f32 farg0);
    void start_anim(f32 farg0);
    u8 unk_24[0x4];
    f32 m_28;
};

typedef char TAdRicoRingCtrl_size[sizeof(TAdRicoRingCtrl) == 0x2C ? 1 : -1];

extern "C" {
void TAdRicoRingCtrl__sub_8001BED0(void *p, f32 v);
}

#endif
