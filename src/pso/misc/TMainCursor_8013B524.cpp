#include "types.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_8023601C.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TMainCursor_8013B524.h"
#include "pso/misc/TMainCursor_8013E1C8.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TPlyPhotonChair.h"

extern "C" {

struct VOff_8013B524_arg0_8013B524 { char pad_0[0x4C]; char f_4C[1]; };

s32 rotate_matrix_z(s32, s32);
void draw_chunk_object(void);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TMainCursor::update_chair() {
    struct VOff_8013B524_arg0_8013B524 *self = (struct VOff_8013B524_arg0_8013B524 *)this;
    save_model_draw_state(self->f_4C);
    begin_constant_color_draw_self((NJS_ARGB *)(self->f_4C));
    TMainCursor__sub_8013E2DC();
    draw_chunk_object();
    restore_model_draw_state(self->f_4C);
}

extern u8 *camera_ctrl_instance;
extern const f32 TMainCursor__data_805DB0C0;

void render__11TMainCursorFPv(TMainCursor *main_cursor) {
    s32 sp8;
    f32 temp_f31;

    TParticleCtrl::begin_effect_render();
    temp_f31 = *(f32 *)((s8 *)main_cursor + 0x30);
    push_matrix();
    offset_point_toward_camera((u8 *)main_cursor + 0x40, (u8 *)&sp8, main_cursor->m_2c);
    translate_matrix_vec3((u8 *)(0), (u8 *)&sp8);
    rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194));
    push_matrix();
    rotate_matrix_z(0, 0x2AAA);
    translate_matrix(0, TMainCursor__data_805DB0C0, temp_f31, TMainCursor__data_805DB0C0);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    push_matrix();
    rotate_matrix_z(0, 0x7FFF);
    translate_matrix(0, TMainCursor__data_805DB0C0, temp_f31, TMainCursor__data_805DB0C0);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    push_matrix();
    rotate_matrix_z(0, 0xD554);
    translate_matrix(0, TMainCursor__data_805DB0C0, temp_f31, TMainCursor__data_805DB0C0);
    main_cursor->update_photon_chair();
    main_cursor->update_chair();
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

}
