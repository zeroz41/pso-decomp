#include "types.h"
#include "pso/boss/TBoss5GryphonShockWave.h"
#include "pso/boss/Boss5GryphonBehavior.h"
#include "pso/object/TObject_80019A50.h"

#include "pso/system/vector.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TNowLoading.h"
#include "pso/TParticleCtrl.h"

extern "C" {
s32 TBoss8Dragon__sub_8005D700(void *self);
extern u8 lbl_80437F40[];
void *gryphon_shockwave_particle_ids_ptr;
s32 get_bml_motion(s32, s32);
s32 get_bml_model(s32, s32);
s32 attach_particle_model(s32, s32, s32, s32, s32, f32);
s32 spawn_particle_effect_with_flags(void *, s32, s32);
u32 spawn_continuous_particle_effect_with_flags(void *, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, s32, s32, void *, f32);
s32 spawn_gryphon_tornado(s32, s32, void *, u16);
extern s32 boss5_gryphon_bml_resource;
extern s32 boss5_gryphon_texture_list;
s32 vec3_add_to(void *, s32);
s32 subtract_vector(void *, void *);

void TBoss5GryphonShockWave::render() {  }


void TBoss5GryphonShockWave::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    s32 temp_r3;
    s32 particle_effect_with_flags;
    if (((TBoss8Dragon *)(*(s32 *)&this->m_38))->get_flag_bit6() != 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    switch (*(s32 *)&this->m_1c) {
    case 0:
        *(s32 *)&this->m_1c = 1;
    case 1:
        eval_bezier_curve__12TBoss8DragonFPviiPvf((u8 *)&this->m_40, 3, 0, (u8 *)&this->m_2c, (f32) *(s32 *)&this->m_20 / (f32) *(s32 *)&this->m_24);
        if ((u32) this->m_3c == 0U) {
            this->m_3c = spawn_continuous_particle_effect_with_flags((u8 *)&this->m_2c, *(s32 *)((s8 *)(*(u8 * *)&gryphon_shockwave_particle_ids_ptr) + 0), 0x40);
        }
        if ((u32) this->m_3c != 0U) {
            ((TParticleCtrl *)this->m_3c)->set_position((u8 *)&this->m_2c);
        }
        temp_r3 = *(s32 *)&this->m_20;
        *(s32 *)&this->m_20 = (temp_r3 + 1);
        if (temp_r3 > (s32) *(s32 *)&this->m_24) {
            *(s32 *)&this->m_20 = 0;
            *(s32 *)&this->m_1c = 2;
        }
        break;
    case 2:
        particle_effect_with_flags = spawn_particle_effect_with_flags((u8 *)&this->m_2c, *(s32 *)((s8 *)(*(u8 * *)&gryphon_shockwave_particle_ids_ptr) + 4), 0x40);
        if (particle_effect_with_flags != 0) {
            attach_particle_model(particle_effect_with_flags, get_bml_model(boss5_gryphon_bml_resource, 0), boss5_gryphon_texture_list, get_bml_motion(boss5_gryphon_bml_resource, 0), 0, 1.0f);
        }
        spawn_particle_effect_with_flags((u8 *)&this->m_2c, *(s32 *)((s8 *)(*(u8 * *)&gryphon_shockwave_particle_ids_ptr) + 8), 0x40);
        play_sound_effect(0x40033C13, (u8 *)&this->m_2c, 0, 0);
        TBoss8Dragon__sub_80064114(TBoss8Dragon::get_instance_count(), (s32)&this->m_2c);
        spawn_gryphon_tornado(*(s32 *)&this->m_up, *(s32 *)&this->m_38, (u8 *)&this->m_2c, this->m_28);
        *(s32 *)&this->m_1c = 3;
        queue_destruction__7TObjectFv(arg0);
        break;
    case 3:
        break;
    }
}

}
TBoss5GryphonShockWave::~TBoss5GryphonShockWave() {
    if (*(void **)((s8 *)this + 0x3C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x3C)); this->m_3c = 0; }
}
extern s32 lbl_805D2818;
TBoss5GryphonShockWave::TBoss5GryphonShockWave(TObject *arg1_parent, s32 arg2, u8 *arg3, u8 *arg4, s32 arg5, s16 arg6) : TObject(arg1_parent) {
    s32 sp8[4];
    *(s32 *)((s8 *)this + 0) = (s32) lbl_805D2818;
    VecCopy((Vec *)(((u8 *)this) + 0x40), (const Vec *)arg3);
    VecCopy((Vec *)(((u8 *)this) + 0x50), (const Vec *)arg3);
    vec3_add_to(((u8 *)this) + 0x50, arg5);
    VecCopy((Vec *)(((u8 *)this) + 0x60), (const Vec *)arg4);
    *(f32 *)((s8 *)this + 0x64) = 5.0f;
    VecCopy((Vec *)(((u8 *)this) + 0x2C), (const Vec *)(((u8 *)this) + 0x40));
    this->m_28 = arg6;
    this->m_38 = arg2;
    this->m_3c = 0;
    VecCopy((Vec *)sp8, (const Vec *)(((u8 *)this) + 0x2C));
    subtract_vector(sp8, arg4);
    this->m_24 = (s32) (0.07f * ((TObjBoss2Tunnel *)sp8)->update_scale());
    if ((s32) this->m_24 < 0x1E) {
        this->m_24 = 0x1E;
    }
    this->m_20 = 0;
    this->m_1c = 0;
}

void TBoss8Dragon__sub_80066A4C(void) {  }
void TBoss8Dragon::set_default_on_state0() {
    switch (TBoss8Dragon__sub_8005D700(this)) {
    case 0:
        gryphon_shockwave_particle_ids_ptr = lbl_80437F40;
        break;
    }
}
