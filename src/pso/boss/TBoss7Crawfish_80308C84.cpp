#include "types.h"
#include "pso/boss/TBoss7Crawfish.h"
#include "pso/misc/TNowLoading.h"
#include "pso/TParticleCtrl.h"

struct Craw_80308D1C {
    u8 pad0[0x60];
    s32 angle;
    u8 pad64[0x308 - 0x64];
    f32 vx, vy, vz;
    u8 pad314[0x3A0 - 0x314];
    f32 *speed;
};

extern "C" {
u16 find_nearest_visible_player(void *, void *, f32);
f32 atan2_float(f32 y, f32 x);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void normalize_vector(void *);
extern const f64 lbl_804755B0[];
extern const f32 lbl_805DF0D0;
extern const f32 TBoss7Crawfish__data_805DF0D8;
extern const f32 TBoss7Crawfish__data_805DF0DC;
s32 register_attack_hits__14TBoss7CrawfishFv(void *, void *, f32, f32);
void TBoss7Crawfish__sub_803087D4(s32 arg0, s32 arg1);
s32 TBoss7Crawfish__sub_80308ED8(void *, void *);

extern const f32 lbl_805DF0F4;

void TBoss7Crawfish::update_motion_and_release() {
    u8 *arg0 = (u8 *)this;
    f32 *temp_r4;

    temp_r4 = *(f32 * *)&this->m_3a0;
    this->play_speed = (f32) (lbl_805DF0F4 * (TBoss7Crawfish__data_805DF0DC + *temp_r4));
    register_attack_hits__14TBoss7CrawfishFv(arg0, temp_r4, TBoss7Crawfish__data_805DF0DC, lbl_805DF0F4);
    {
        void *temp_ptr = (void *) this->m_3cc;
        if (temp_ptr != NULL) {
            ((TParticleCtrl *)temp_ptr)->set_position((u8 *)&this->position);
        }
    }
    if (TBoss7Crawfish__sub_80308ED8(arg0, (u8 *)&this->unk_308) == 0) {
        ((TBoss7Crawfish *)arg0)->free_child();
        ((TBoss7Crawfish *)arg0)->change_state(3);
        return;
    }
    TBoss7Crawfish__sub_803087D4((s32)arg0, 0x3A80C);
}
void TBoss7Crawfish::aim_at_nearest_player() {
    Craw_80308D1C *o = (Craw_80308D1C *)this;
    u16 r = find_nearest_visible_player(o, &o->vx, lbl_805DF0D0);
    f32 s = TBoss7Crawfish__data_805DF0DC + *o->speed;
    if (r != 0xFFFF) {
        normalize_vector(&o->vx);
        o->vx *= s;
        o->vy *= s;
        o->vz *= s;
    } else {
        o->vx = s * sin_table_lookup(o->angle);
        o->vy = TBoss7Crawfish__data_805DF0D8;
        o->vz = s * cos_table_lookup(o->angle);
    }
    o->angle = lbl_804755B0[0] * atan2_float(o->vx, o->vz);
    ((TBoss7Crawfish *)o)->change_state(2);
}

}
