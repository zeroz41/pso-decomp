#include "types.h"
#include "pso/misc/TORevlightCave01_80173478.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TORevlightCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
struct TORevlightCave01Base_80173478 { char pad[0x18]; };
struct TORevlightCave01_80173478 : TORevlightCave01Base_80173478 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

s32 post_translate_matrix(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TORevlightCave01__sub_80173478(void * _w0) {  }

void TORevlightCave01::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TORevlightCave01__sub_80173478((arg0));
    }
    this->m_c8 = (s32) (this->m_c8 + this->m_cc);
}

void TORevlightCave01::render() {
    u8 *arg0 = (u8 *)this;
    if (((TORevlightCave01_80173478*)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_z(0, this->rotation_z);
        rotate_matrix_x(0, *(s32 *)&this->rotation_x);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_model(*(s32 *)((s8 *)(*(void * *)&this->model) + 4));
        rotate_matrix_y(0, *(s32 *)&this->m_c8);
        draw_ginja_model(*(s32 *)((s8 *)(*(void **)((s8 *)(*(void * *)&this->model) + 0x2C)) + 4));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model(*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void * *)&this->model) + 0x2C)) + 0x2C)) + 4));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

}
