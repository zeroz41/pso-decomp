#include "types.h"
#include "pso/boss/TBoss8Dragon_80065C90.h"
#include "pso/map/CsnQuery.h"
#include "pso/enemy/TObjEneMe3SinowZoa_80316690.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/TParticleCtrl.h"

struct Vec_80316690 { f32 x, y, z; };

struct Hit_80316690 { s32 flags; u8 *obj; };

extern "C" {
extern const f32 TObjEneMe3SinowZoa__data_805DF2FC;
extern const f32 lbl_805DF300;
void TObjEneGibbles__sub_800D8988(void *);
extern const f32 TObjEneMe3SinowZoa__data_805DF2F0;
extern const f32 TObjEneMe3SinowZoa__data_805DF2F4;
struct VOff_803167FC_arg0 { char pad_0[0x38]; char f_38[1]; };

#define DELL spawn_particle_effect
s32 TObjEneMe3SinowZoa::check_floor_contact(void *arg1) {
    u8 *arg0 = (u8 *)this;
    Vec_80316690 v;
    u8 pad[16];
    Hit_80316690 *hit;
    void *p;
    VecCopy((Vec *)&v, (const Vec *)arg1);
    v.y += TObjEneMe3SinowZoa__data_805DF2F0;
    hit = (Hit_80316690 *)csnVectorUnder((Vec *)&v, (u32 *)&this->m_120, 0x4007);
    if (hit != NULL) {
        *(s32 *)(arg0 + 0x3D0) = *(s32 *)(hit->obj + 0x18);
        if (*(s32 *)(arg0 + 0x3D0) & 0x4000) {
            VecCopy((Vec *)(arg0 + 0x3D4), (const Vec *)hit->obj);
        } else {
            VecCopy((Vec *)(arg0 + 0x3D4), (const Vec *)&this->position);
        }
        if (hit->flags & 4) {
            TObjEneGibbles__sub_800D8988((u8 *)&this->position);
            p = DELL(hit->obj + 0x38, 0x49);
            if (p != 0) {
                attach_particle_model((u8 *)p, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneMe3SinowZoa__data_805DF2F4);
            }
            spawn_particle_effect(hit->obj + 0x38, 0xA4);
            return 1;
        }
        if (hit->flags & 2) {
            TObjEneGibbles__sub_800D8988((u8 *)&this->position);
            p = DELL(hit->obj + 0x54, 0x49);
            if (p != 0) {
                attach_particle_model((u8 *)p, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneMe3SinowZoa__data_805DF2F4);
            }
            spawn_particle_effect(hit->obj + 0x54, 0xA4);
            return 1;
        }
    }
    return 0;
}

void TObjEneMe3SinowZoa::check_and_notify() {
    s32 x;
    struct VOff_803167FC_arg0 *self = (struct VOff_803167FC_arg0 *)this;
    x = check_floor_contact(self->f_38);
    if (x == 0) {
        spawn_particle_effect(self->f_38, 243);
    }
}
void TObjEneMe3SinowZoa__sub_80316840(u8 *arg0) {
    if ((((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneMe3SinowZoa__data_805DF2FC) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)((f32)lbl_805DF300)) != 0)) {
        ((TObjEneMe3SinowZoa *)arg0)->check_floor_contact(arg0 + 0x38);
    }
}

}
