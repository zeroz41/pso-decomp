#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneRecon_8029E89C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/enemy/TObjEneRecobox.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"

extern "C" {

s32 get_mode__11TCameraCtrlFPv(void *);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

s32 TObjEneRecobox::render_trap_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (((TObjEneRecon *)(((u8 *)this) + 0x3E4))->push_reflect_matrix() != 0) {
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix((void *) (((u8 *)this) + 0x38));
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

}
