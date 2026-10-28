#include "pso/TItemShootModel.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

extern "C" {
void* get_texture_id__10TObjPlayerFv(void*);
f32   newton_sqrtf(f32);
f32 atan2_float(f32 y, f32 x);
void  push_matrix(void);
void  post_translate_matrix(Vec*);
void  rotate_matrix_by_node_angles(void*, s32);
void  draw_ginja_object(void*);
s32 pop_matrix(void);
extern const char* TItemShootModel__class_name;
extern const f32   lbl_805DAC60;
extern const f64   lbl_8043E7A0[];
}

void TItemShootModel::render() {
    if (is_owner_alive()) {
        if (this->m_58 != NULL) {
            set_texlist((u32)this->m_5C);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&this->m_pos);
            rotate_matrix_by_node_angles(&this->m_28, 1);
            rotate_matrix_by_node_angles(&this->m_60, 1);
            draw_ginja_object(this->m_58);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}

TItemShootModel::TItemShootModel(void* owner, const Vec* pos, const Vec* dir, f32 life)
    : TItemShoot(owner, pos, dir, life) {
    this->m_name = TItemShootModel__class_name;
    this->m_58 = *(void**)((u8*)owner + 0x188);
    this->m_5C = get_texture_id__10TObjPlayerFv(owner);
    if (lbl_805DAC60 != this->m_dir.y) {
        f32 horiz = newton_sqrtf(this->m_dir.x * this->m_dir.x + this->m_dir.z * this->m_dir.z);
        this->m_28 = -(s32)(lbl_8043E7A0[0] * atan2_float(this->m_dir.y, horiz));
        this->m_30 = 0;
    } else {
        this->m_30 = 0;
        this->m_28 = 0;
    }
    this->m_68 = 0;
    this->m_64 = 0;
    this->m_60 = 0;
}
