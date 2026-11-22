#ifndef PSO_UI_WINDOW_TWINDOWEFFECTLIGHT_H
#define PSO_UI_WINDOW_TWINDOWEFFECTLIGHT_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TWindowEffectLight : public TObject {
public:
    TWindowEffectLight(void *position, s16 arg2, u32 id);
    virtual ~TWindowEffectLight();
    void sub_802AD040(f32);
    void draw_outline_quad(s32);
    virtual void render();
    virtual void run_task();
public:
    f32 calc_scale();
    u32 calc_alpha();
    static void *create(void *position, s16 effect_kind, u32 player_id);

    f32 x;
    f32 y;
    s16 effect_kind;
    s16 age;
    u32 player_id;
};

LAYOUT_ASSERT(TWindowEffectLight_size, sizeof(TWindowEffectLight) == 0x2C);
LAYOUT_ASSERT(TWindowEffectLight_kind_offset, offsetof(TWindowEffectLight, effect_kind) == 0x24);
LAYOUT_ASSERT(TWindowEffectLight_age_offset, offsetof(TWindowEffectLight, age) == 0x26);
LAYOUT_ASSERT(TWindowEffectLight_player_offset, offsetof(TWindowEffectLight, player_id) == 0x28);

extern "C" {
u8 *__ct__18TWindowEffectLightFPvsUl(u8 *self, void *arg1, s16 arg2, u32 id);
}

#endif
