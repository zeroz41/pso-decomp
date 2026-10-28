#include "types.h"
#include "pso/player/TObjPlayer_80083594.h"

void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
extern "C" {
s32 is_split_screen();

extern s32 model_render_flags;
}

void reset_particle_tev() {
    if (is_split_screen() == 0) {
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
        model_render_flags &= 0xFFF7FFFF;
    }
}
