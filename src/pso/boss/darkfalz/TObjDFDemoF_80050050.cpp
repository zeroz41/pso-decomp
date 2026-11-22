#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"

extern "C" {
extern Vec three_part_model_translate_offset;

void TObjDFDemoF::render() {
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&three_part_model_translate_offset.x);
    s32 i = 0;
    do {
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(textures[i]));
        AnimationMotion *motion = motions[i];
        if (motion == NULL) {
            draw_chunk_object(models[i]);
        } else {
            draw_model_motion(models[i], motion, frame);
        }
        i++;
    } while (i < 3);
    clear_motion_packed_rotation();
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
void TObjDFDemoF::run_task() {
    s32 count;
    if ((frame += 1.0f) >= 120.0f) {
        frame = 120.0f;
    }
    count = timer + 1;
    timer = count;
    if (count >= 120) {
        queue_destruction();
    }
}
#pragma pop

}
