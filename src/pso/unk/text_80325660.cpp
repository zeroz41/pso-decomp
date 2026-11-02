#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
struct Ent_80325660 { u8 b[0x20]; };

struct Obj_80325660 { u8 pad[0x20]; u32 count; u8 pad2[4]; Ent_80325660 ents[12]; u32 col[4]; };

extern "C" {
extern s32 chr_sel_move_plate_texture;
void draw_move_plate_quads(Obj_80325660 *arg0);
void draw_move_plate_quads(Obj_80325660 *arg0) {
    u32 i;
    for (i = 0; i < arg0->count; i++) {
        begin_screen_draw(1);
        TObjFish::set_global_param(chr_sel_move_plate_texture);
        set_draw_texture_and_color(0, (arg0->col[i] << 24) | 0xFFFFFF);
        draw_textured_quad_at_depth((f32 *)&arg0->ents[i], 0.52f);
        TWindowSubStatusDisp::get_player();
    }
}

}
