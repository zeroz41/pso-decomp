#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOMonumentAncient01.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"

extern "C" {

struct Base1_8017262C { char pad[0x18]; };
struct VObj1_8017262C : Base1_8017262C { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 get_bml_model(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TOMonumentAncient01::vfunc_16() {  }

extern s32 TOMonumentAncient01__resource_bundle;

void TOMonumentAncient01::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj1_8017262C*)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) == 1) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        get_bml_model(TOMonumentAncient01__resource_bundle, 2);
        draw_ginja_object();
        TParticleCtrl::begin_effect_render();
        get_bml_model(TOMonumentAncient01__resource_bundle, 1);
        draw_ginja_object();
        get_bml_model(TOMonumentAncient01__resource_bundle, 0);
        draw_ginja_object();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

}
