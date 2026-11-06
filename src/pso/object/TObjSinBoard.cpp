#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803DA798.h"

// The lobby signboard: a textured quad showing the picture load_memcard_file reads from memory card file PSO______099.

struct Pos_8019806C { f32 w[12]; };
struct Uv_8019806C { u32 w[4]; };
struct Desc_8019806C { Pos_8019806C *pos; Uv_8019806C *uv; s16 *col; s32 count; };

extern "C" {
extern u8 signboard_texture_list[];
extern u32 TObjSinBoard__texture_buffer;
}

const char *TObjSinBoard__class_name = "TObjSinBoard";

void TObjSinBoard::render() {
    if (TMainTask::get_render_pass() != 1 && TObjSinBoard__texture_buffer != 0) {
        Pos_8019806C pos = {
            -10.0f, -10.0f, 0.0f, 10.0f, -10.0f, 0.0f, 10.0f, 10.0f, 0.0f, -10.0f, 10.0f, 0.0f,
        };
        Uv_8019806C uv = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
        Desc_8019806C d;
        s16 col[8];
        col[0] = 0;
        col[1] = 0;
        col[2] = 0;
        col[3] = 0xFF;
        col[4] = 0xFF;
        col[5] = 0xFF;
        col[6] = 0xFF;
        col[7] = 0;
        d.pos = &pos;
        d.uv = &uv;
        d.col = col;
        d.count = 4;
        set_default_alpha_blend();
        TObjFish::set_global_param((int)signboard_texture_list);
        set_texture_num(0);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        translate_matrix(0, position.x, position.y, position.z);
        rotate_matrix_z(0, rotation_z);
        rotate_matrix_x(0, rotation_x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, scale.x, scale.y, scale.z);
        ((TObjPlayer *)(&d))->draw_tri_fan_3d(4, 0xE);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjSinBoard::run_task() {}

const char *memcard_file_099_name = "PSO______099";

TObjSinBoard::~TObjSinBoard() {}

TObjSinBoard::TObjSinBoard(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjSinBoard__class_name;
    apply_object_set_data(set_data);
}

void *TObjSinBoard__create(void *set_data) {
    return new TObjSinBoard(tl_05, set_data);
}
