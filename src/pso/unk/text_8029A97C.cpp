#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/unk/text_8029A97C.h"
#include "pso/ui/charcreate/TChCrEffTag.h"

struct Stack_8029A97C {
    f32 sp8;
    f32 spC;
};

struct A_8029A9B8 { u8 pad[0x20]; f32 f20; };

extern "C" {
s32 draw_default_sprite__12TChCrEffWallFv(s32, f32 *, f32);
void draw_chcr_tag_heading_frame(void) {
    Stack_8029A97C stack;
    stack.sp8 = 62.0f;
    stack.spC = 67.0f;
    draw_default_sprite__12TChCrEffWallFv(0x36, &stack.sp8, -2.75f);
}
void TChCrEffTag::draw_chcr_tag_frame() {
    A_8029A9B8 *arg0 = (A_8029A9B8 *)this;
    vec2f sp10;
    vec2f sp8;
    sp10.y = 37.0f;
    sp10.x = 0.0f;
    sp8.x = arg0->f20 / 32.0f;
    sp8.y = 1.0f;
    draw_ui_sprite_opaque(0x34, &sp10, &sp8, -3.0625f);
    sp10.x = arg0->f20;
    draw_default_sprite__12TChCrEffWallFv(0x35, &sp10.x, -3.0625f);
}

}
