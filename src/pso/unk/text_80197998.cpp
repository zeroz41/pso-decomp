#include "types.h"
#include "pso/object/TObjRain.h"


struct Vec_80197998 { f32 x, y, z; };

struct Drop_80197998 {
    u32 active;
    Vec_80197998 pos;
    Vec_80197998 vel;
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

extern "C" {
int rand(void);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
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

}
