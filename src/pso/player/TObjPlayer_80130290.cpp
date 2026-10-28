#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TUnk_804A69C0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_x(s32, s32);
s32 is_owner_alive__15TItemShootModelFv();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *);

void TUnk_804A69C0::render() {
    u8 *arg0 = (u8 *)this;
    if ((is_owner_alive__15TItemShootModelFv() != 0) && ((u32) this->m_58 != 0U) && ((u32) this->m_5C != 0U)) {
        push_matrix();
        set_texlist(*(u32 *)&this->m_5C);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28);
        draw_ginja_object(this->m_58);
        pop_matrix();
    }
}

void TUnk_804A69C0::hook() {
    this->m_28 = (this->m_28 + 0xCCC);
}

extern s32 __vt__13TUnk_804A69C0[];

void *TUnk_804A69C0::init_shoot_model() {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A69C0;
    this->m_28 = 0;
    return this;
}

}
