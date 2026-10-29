#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjFish.h"

extern "C" void *__ct__13TUnk_804AFBF8FP7TObject(void *self);

extern "C" {

struct VBase18_80166970 { char pad[0x18]; };
struct VObj18_80166970 : VBase18_80166970 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 draw_ginja_model_with_motion(void *, int, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

void TObjPlayer::on_zone_exit() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;

    if (((VObj18_80166970 *) arg0)->m8(*(f32 *)&this->m_c0, *(f32 *)&this->unk_C4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param((int) (*(s32 *)&this->texlist));
        if ((s32) (*(s32 *)&this->m_d0) == 0) {
            draw_ginja_model_with_motion((void *) (*(void * *)&this->model), (int) (*(s32 *)&this->m_bc), (f32) (*(f32 *)&this->animationFlags));
        } else {
            temp_r31 = (unsigned char *) (*(void * *)&this->model);
            push_matrix();
            post_translate_matrix(temp_r31 + 8);
            rotate_matrix_z(0, (int) (*(s32 *)((s8 *)temp_r31 + 0x1C)));
            rotate_matrix_x(0, (int) (*(s32 *)((s8 *)temp_r31 + 0x14)));
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)temp_r31 + 0x18)));
            scale_current_matrix(temp_r31 + 0x20);
            ::draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
            pop_matrix();
        }
        pop_matrix();
    }
}

extern s32 lbl_804B1B80[];

void *TUnk_804B1B80::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B1B80;
        __dt__13TUnk_804AFBF8Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804B1B80::init_fields() {
    __ct__13TUnk_804AFBF8FP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804B1B80;
    this->m_ac = 0;
    this->m_cc = -1;
    *(u32 *)&this->unk_C8 = 0;
    *(u32 *)&this->unk_D0 = 0;
    this->m_d4 = 0;
    return this;
}

}
