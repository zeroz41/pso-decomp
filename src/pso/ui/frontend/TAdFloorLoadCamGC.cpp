#include "types.h"
#include "pso/ui/frontend/TAdFloorLoadCamGC.h"
#include "pso/system/vector.h"

#include "pso/camera/TCameraCtrl.h"

struct Vec_8034BE5C { f32 x, y, z; };

struct Cam_8034BE5C {
    u8 pad0[0x1C];
    s32 direction;
    s32 ticks;
    s32 angle;
    Vec_8034BE5C pos;
    Vec_8034BE5C target;
    Vec_8034BE5C up;
};

struct Pad_8034BE5C { u8 pad0[0x34]; s16 tilt; u8 pad36[4]; s16 speed; };

extern "C" {
extern void *lbl_805D4340;
void set_default_camera__21TAdMultiChgGameModeGCFv(void *);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
s32 activate_camera_mode(s32 arg0);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 vec_squared_length(u8 *arg0);
void normalize_vector(void *);
extern Pad_8034BE5C controller_physical_port_bank;
extern const f32 lbl_805DFDB8;
void TCameraCtrl__sub_800687C8(void);

u16 fn_8034BE30(void* p) { return *(u16*)((char*)p + 0x24); }
void fn_8034BE38(void* p) { *(u32*)((char*)p + 0x334) &= 0xbfffffff; }
void fn_8034BE48(void* p) { *(u32*)((char*)p + 0x334) |= 0x40000000; }
void TAdFloorLoadCamGC::render() {  }

extern "C" {
extern const f32 lbl_805DFDA8 = 182.04445f;
extern const f32 lbl_805DFDAC = -0.1f;
extern const f32 lbl_805DFDB0 = 1.2f;
extern const f32 lbl_805DFDB4 = 100.0f;
extern const f32 lbl_805DFDB8 = 0.0f;
extern const f32 lbl_805DFDBC = 99.3f;
extern const f32 lbl_805DFDC0 = 0.4f;
}
#pragma push
#pragma fp_contract on
void TAdFloorLoadCamGC::run_task() {
    Cam_8034BE5C *s = (Cam_8034BE5C *)this;
    Vec_8034BE5C up;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dy;
    f32 dz;
    s16 tilt;
    s32 a;
    activate_camera_mode(9);
    s->ticks++;
    tilt = controller_physical_port_bank.tilt;
    s->angle += (s32)((*(const f32 *)&lbl_805DFDA8) * (f32)(s32)((*(const f32 *)&lbl_805DFDAC) * (f32)controller_physical_port_bank.speed)) / 10 + 0x1B4;
    a = s->angle;
    if (a >= 0x10000) {
        a -= 0x10000;
    }
    s->angle = a;
    s->pos.x = (*(const f32 *)&lbl_805DFDB0) * sin_table_lookup(s->angle);
    s->pos.y = (*(const f32 *)&lbl_805DFDB4) * cos_table_lookup(s->angle);
    s->pos.z = (*(const f32 *)&lbl_805DFDB4) * sin_table_lookup(s->angle);
    s->target.x = (*(const f32 *)&lbl_805DFDB8);
    s->target.y = (*(const f32 *)&lbl_805DFDBC) * cos_table_lookup(s->angle + 0x1B4);
    s->target.z = (*(const f32 *)&lbl_805DFDBC) * sin_table_lookup(s->angle + 0x1B4);
    if (s->direction == 0) {
        x = (*(const f32 *)&lbl_805DFDC0) * (f32)tilt + -s->pos.x;
        y = -s->pos.y;
        z = -s->pos.z;
    } else {
        x = (*(const f32 *)&lbl_805DFDC0) * (f32)tilt + s->pos.x;
        y = s->pos.y;
        z = s->pos.z;
    }
    dx = (x - s->up.x) / 15.0f;
    dy = (y - s->up.y) / 15.0f;
    dz = (z - s->up.z) / 15.0f;
    s->up.x += dx;
    s->up.y += dy;
    s->up.z += dz;
    VecCopy((Vec *)&up, (const Vec *)&s->up);
    if (vec_squared_length((u8 *)&s->up) == (*(const f32 *)&lbl_805DFDB8)) {
        up.y = 1.0f;
    } else {
        normalize_vector(&up);
    }
    TCameraCtrl::copy_vec_to_default((u8 *)&up);
    set_active_camera_pose((u8 *)&s->pos, (u8 *)&s->target);
}
#pragma pop

}
TAdFloorLoadCamGC::~TAdFloorLoadCamGC() {
    TCameraCtrl__sub_800687C8();
}
TAdFloorLoadCamGC::TAdFloorLoadCamGC(TObject *object, void *arg2) : TObject(object) {
    void *new_var;
    new_var = lbl_805D4340;
    *(void * *)&this->m_name = new_var;
    this->m_20 = 0;
    this->m_24 = 0;
    *((f32 *) (((s8 *) this) + 0x40)) = (*(const f32 *)&lbl_805DFDB8);
    *((f32 *) (((s8 *) this) + 0x44)) = (*(const f32 *)&lbl_805DFDB8);
    this->m_48 = (*(const f32 *)&lbl_805DFDB8);
    *((void **) (((s8 *) this) + 0x1C)) = arg2;
    set_default_camera__21TAdMultiChgGameModeGCFv(new_var);
}
