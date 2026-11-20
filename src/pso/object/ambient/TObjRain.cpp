#include "types.h"
#include "pso/object/ambient/TObjRain.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include <dolphin/mtx/GeoTypes.h>
extern "C" { extern const char TObjRain__class_name_string[9] = "TObjRain"; }


struct Drop_80197998 {
    u32 active;
    Vec pos;
    Vec vel;
    f32 floor;
};

struct Rain_80197998 {
    u8 pad0[0x1C];
    Drop_80197998 drops[16];
    u32 count;
};

struct Cam_80197998 {
    u8 pad0[0x178];
    f32 x, y, z;
    u8 pad184[0x194 - 0x184];
    s32 yaw;
};


extern Cam_80197998 *camera_ctrl_instance;
#pragma push
#pragma fp_contract on
void TObjRain::init_drops() {
    u8 *arg0 = (u8 *)this;
    Rain_80197998 *rain = (Rain_80197998 *)arg0;
    s32 angle;
    Drop_80197998 *d;
    s32 i;
    f32 radius;
    f32 x;
    f32 z;
    d = rain->drops;
    for (i = 0; i < rain->count; i++, d++) {
        radius = 150.0f * (0.000030517578f * (f32)rand());
        angle = (s32)(182.04445f * (-15.0f - 150.0f * (0.000030517578f * (f32)rand())));
        angle -= camera_ctrl_instance->yaw;
        x = radius * cos_table_lookup(angle);
        z = radius * sin_table_lookup(angle);
        d->pos.x = camera_ctrl_instance->x + x;
        d->pos.y = 120.0f + camera_ctrl_instance->y;
        d->pos.z = camera_ctrl_instance->z + z;
        d->vel.x = 1.2f * (0.000030517578f * (f32)rand());
        d->vel.y = -(5.5f * (0.000030517578f * (f32)rand()) + 9.0f);
        d->vel.z = 1.2f * (0.000030517578f * (f32)rand());
        d->floor = -20.0f;
        d->active = 1;
    }
}
#pragma pop

struct RecoveredGlobal_80197C84___vt__8TObjRain {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 __ct__7TObjectFP7TObject();
extern RecoveredGlobal_80197C84___vt__8TObjRain __vt__8TObjRain;
const char *lbl_805D3420 = TObjRain__class_name_string;
void TObjRain::render() { draw_streaks(); }
void TObjRain::run_task() { update_drops(); }
LAYOUT_ASSERT(RecoveredGlobal_80197C84___vt__8TObjRain_size, sizeof(RecoveredGlobal_80197C84___vt__8TObjRain) == 0x18);
TObjRain::~TObjRain() {}
u8 *__ct__8TObjRainFv(u8 *rain, s32 arg1, u32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)rain + 0x18) = &__vt__8TObjRain.value;
    *(saddr *)((s8 *)rain + 0) = (saddr) lbl_805D3420;
    *(u32 *)((s8 *)rain + 0x21C) = (arg2 > 0x10U) ? 0x10U : arg2;
    ((TObjRain *)rain)->init_drops();
    return rain;
}

}
