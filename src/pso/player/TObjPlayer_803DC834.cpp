#include "types.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/player/TObjPlayer.h"

struct S_803DC83C { u8 pad[0x77]; u8 f; };

struct S_803DC850 { u8 pad[0x78]; u8 f; };

extern S_803DC83C ginja_material_cache;

s32 lbl_805D76E0;

void TObjPlayer::set_global_effect_state(s32 arg0) {
    lbl_805D76E0 = arg0;
}

extern s32 ginja_draw_end_callback;

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_post_texgen_count(s32 x) {
    ginja_material_cache.f = (u8)x;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_post_tev_stage_count(s32 x) {
    (*(S_803DC850 *)&ginja_material_cache).f = (u8)x;
}
#pragma pop

void set_ginja_draw_end_callback(s32 arg0) {
    ginja_draw_end_callback = arg0;
}
