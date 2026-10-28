#include "pso/TItemShootGun.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/TItemShootModel.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

extern "C" {
void  push_matrix(void);
void  post_translate_matrix(Vec*);
void  rotate_matrix_by_node_angles(void*, s32);
}

void TItemShootGun::render() {
    if (is_owner_alive()) {
        if (this->m_58 != NULL) {
            ((TObjDoorJung *)(*(s32*)((u8*)this->m_58 + 4)))->free_children((void *)(this->m_70 & 0xFFFF));
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

void TItemShootGun::hook() {
    this->m_6C += 0x1999;
}

