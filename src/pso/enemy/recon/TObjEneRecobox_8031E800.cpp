#include "pso/render/reflection.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/recon/TObjEneRecon_8029E89C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"

extern "C" {

s32 get_mode__11TCameraCtrlFPv(void *);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

s32 TObjEneRecobox::render_trap_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x3E4)) != 0) {
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
