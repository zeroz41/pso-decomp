#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct VBase800AFB60_8031bd64 { char pad[0x18]; };
struct VObj800AFB60_8031bd64 : VBase800AFB60_8031bd64 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 update_player_state__9TObjEneDDFv(void *, s32, s32);

extern const f32 lbl_805DF3BC;
extern const f32 TObjEneRecon__data_805DF3C0;

void TObjEneRecon::vfunc_106() {
    u8 *arg0 = (u8 *)this;
    if (((VObj800AFB60_8031bd64 *) arg0)->m8(lbl_805DF3BC, TObjEneRecon__data_805DF3C0) != 0) {
        update_player_state__9TObjEneDDFv(arg0, 0, 0);
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(this->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

}
