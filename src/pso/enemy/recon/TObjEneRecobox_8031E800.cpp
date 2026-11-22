#include "pso/render/reflection.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

s32 post_translate_matrix(void *);

s32 TObjEneRecobox::render_trap_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x3E4)) != 0) {
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
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
