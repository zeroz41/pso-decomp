#ifndef PSO_UI_WINDOW_TWINDOWEFFECTLIGHT_H
#define PSO_UI_WINDOW_TWINDOWEFFECTLIGHT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TWindowEffectLight : public TObject {
public:
    TWindowEffectLight(void *arg1, s16 arg2, u32 id);
    virtual ~TWindowEffectLight();
    void draw_outline_quad(s32);
    virtual void render();
    virtual void run_task();
public:
    f32 calc_scale();
    u32 calc_alpha();
    static void *create(void *arg0, void *arg1, void *arg2);
};

extern "C" {
u8 *__ct__18TWindowEffectLightFPvsUl(u8 *self, void *arg1, s16 arg2, u32 id);
void render__18TWindowEffectLightFv(u8 *arg0);
void run_task__18TWindowEffectLightFv(void *arg0);
}

#endif
