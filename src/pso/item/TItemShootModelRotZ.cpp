#include "pso/TItemShootModelRotZ.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TItemShootModel.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

extern "C" {
void  push_matrix(void);
void  post_translate_matrix(Vec*);
void  rotate_matrix_by_node_angles(void*, s32);
extern const char* item_shoot_model_rot_z_class_name;
}

void TItemShootModelRotZ::render() {
    if (is_owner_alive()) {
        if (this->m_58 != NULL) {
            set_texlist((u32)this->m_5C);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&this->m_pos);
            rotate_matrix_by_node_angles(&this->m_28, 1);
            draw_ginja_object(this->m_58);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}

void TItemShootModelRotZ::hook() {
    this->m_30 += 0xCCC;
}

TItemShootModelRotZ::TItemShootModelRotZ(void* owner, const Vec* pos, const Vec* dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    this->m_name = item_shoot_model_rot_z_class_name;
}
