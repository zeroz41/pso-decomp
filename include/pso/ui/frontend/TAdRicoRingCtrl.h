#ifndef PSO_UI_FRONTEND_TADRICORINGCTRL_H
#define PSO_UI_FRONTEND_TADRICORINGCTRL_H
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TAdRicoRing;
struct TAdRicoRingCtrl : public TObject {
    TAdRicoRingCtrl(TObject *parent);
    virtual ~TAdRicoRingCtrl();
    virtual void run_task();
    virtual void render();
    void sub_8001B424(const Vec *position);
    void sub_8001B4A0(f32 duration);
    static TAdRicoRing *create(TObject *parent);
    static void release_global_805D4A00();
    static void load_static_resource();
    void start_fade_all(f32 duration);
    TAdRicoRing *rings[2];
    f32 fade;
    f32 fade_step;
};
LAYOUT_ASSERT(TAdRicoRingCtrl_size, sizeof(TAdRicoRingCtrl) == 0x2C);
LAYOUT_ASSERT(TAdRicoRingCtrl_rings_offset, offsetof(TAdRicoRingCtrl, rings) == 0x1C);
LAYOUT_ASSERT(TAdRicoRingCtrl_fade_offset, offsetof(TAdRicoRingCtrl, fade) == 0x24);
#endif
