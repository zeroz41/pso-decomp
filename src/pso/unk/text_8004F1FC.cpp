#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjDFDemo4.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 clear_render_callback__8TObjFishFv(int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void TObjDFDemo4::sub_8004F1FC() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;
    u8 *temp_r30;
    s32 var_r29;
    if ((s32) this->m_f8 >= 0x44) {
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix((u8 *)&this->m_e8);
        rotate_matrix_y(0, this->m_f4);
        var_r29 = 0;
        var_r31 = 0;
        do {
            temp_r30 = arg0 + var_r31;
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)temp_r30 + 0xC8)));
            if (var_r29 == 0) {
                ((TObjFish *)(this->m_100))->set_draw_callback_list();
            }
            draw_model_motion((void *)(*(s32 *)((s8 *)temp_r30 + 0xC4)), (void *)(*(s32 *)((s8 *)temp_r30 + 0xCC)), (f32) (*(f32 *)&this->_padFC));
            if (var_r29 == 0) {
                clear_render_callback__8TObjFishFv(this->m_100);
            }
            var_r29 += 1;
            var_r31 += 0xC;
        } while (var_r29 < 3);
        clear_motion_packed_rotation();
        pop_matrix();
    }
}

}
