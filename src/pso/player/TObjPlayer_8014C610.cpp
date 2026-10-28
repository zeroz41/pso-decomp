#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"

extern "C" {

s32 rotate_matrix_y(s32, s32);

extern s32 model_render_flags;

struct Base_8014C610 { char pad[0x18]; };
struct VObj_8014C610 : Base_8014C610 {
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

void TObjPlayer::draw_if_visible() {
    u8 *arg0 = (u8 *)this;
    if ((((VObj_8014C610 *)arg0)->m8(*(f32 *)&this->unk_398, *(f32 *)((s8 *)arg0 + 0x39C)) != 0) && ((s32) *(s32 *)&this->unk_390 == 1)) {
        model_render_flags |= 1;
        TObjFish::set_global_param(this->texlist);
        push_matrix_from(0);
        translate_matrix_vec3((u8 *)(0), (u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        ((TObjMotion *)arg0)->draw();
        pop_matrix();
        model_render_flags &= 0xFFFFFFFE;
        ((TObjEnemy *)arg0)->render_with_position_override(0, 0);
    }
}

}
