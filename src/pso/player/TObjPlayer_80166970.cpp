#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjFish.h"

extern "C" {

s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 draw_ginja_model_with_motion(void *, int, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

}

void TUnk_804B1B80::render() {
    u8 *temp_r31;

    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(texlist);
        if (m_d0 == 0) {
            draw_ginja_model_with_motion(model, (int)m_bc, m_b0);
        } else {
            temp_r31 = (u8 *)model;
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

TUnk_804B1B80::~TUnk_804B1B80() {}

TUnk_804B1B80::TUnk_804B1B80(TObject *parent) : TUnk_804AFBF8(parent) {
    m_ac = 0;
    m_cc = -1;
    trigger_mode = 0;
    m_d0 = 0;
    m_d4 = 0;
}

