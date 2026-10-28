#include "types.h"
#include "pso/boss/TBoss8Dragon.h"

extern "C" {

s32 render_nodes__7TObjectFv(s32, s32);

extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void TBoss8Dragon::render_nodes_flagged() {
    s32 arg0 = (s32)this;
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x400;
    render_nodes__7TObjectFv(arg0 + 0x3C4, temp_r4);
    model_render_flags = saved_model_render_flags;
}

}
