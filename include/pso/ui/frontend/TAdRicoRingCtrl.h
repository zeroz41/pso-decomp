#ifndef PSO_UI_FRONTEND_TADRICORINGCTRL_H
#define PSO_UI_FRONTEND_TADRICORINGCTRL_H
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TAdRicoRing;
struct BmlResourceDescriptor;
struct TAdRicoRingCtrl : public TObject {
    static BmlResourceDescriptor resource_descriptor;
    static const char *class_name;
    TAdRicoRingCtrl(TObject *parent);
    virtual ~TAdRicoRingCtrl();
    virtual void run_task();
    virtual void render();
    void set_position(const Vec *position);
    void start_rings_anim(f32 duration);
    static TAdRicoRing *create(TObject *parent);
    static void release_static_resource();
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
