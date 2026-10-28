#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TUnk_804A4020.h"
#include "pso/player/TObjPlayer_8023E480.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_x(int, int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 is_owner_alive__15TItemShootModelFv();

#include "pso/player/TObjPlayer.h"

extern "C" {

void TUnk_804A4020::render() {
    u8 *arg0 = (u8 *)this;
    if ((is_owner_alive__15TItemShootModelFv() != 0) && ((u32) this->m_58 != 0U) && ((u32) this->m_5C != 0U)) {
        push_matrix();
        set_texlist((int)this->m_5C);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28 - 0x4000);
        draw_ginja_object(this->m_58);
        pop_matrix();
    }
}

}

}
