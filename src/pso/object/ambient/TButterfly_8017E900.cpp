#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TButterfly.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"

struct Self_8017E900 { u8 pad[0x38]; u8 pos[0x60 - 0x38]; s32 f60; u8 pad64[0xA8 - 0x64]; f32 fa8; };

extern "C" {
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 get_bml_motion(void *, s32);
s32 get_bml_model(void *, s32);
s32 draw_ginja_model_with_motion(s32, s32, f32);
extern void *butterfly_bml_resource;
void TButterfly::draw_model() {
    Self_8017E900 *self = (Self_8017E900 *)this;
    push_matrix();
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, -0x2000);
    draw_ginja_model_with_motion(get_bml_model(butterfly_bml_resource, 0), get_bml_motion(butterfly_bml_resource, 0), self->fa8);
    pop_matrix();
}

}
