#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/unk/text_8029A97C.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TChCrEffWall.h"

struct A_8029A9B8 { u8 pad[0x20]; f32 f20; };


void draw_chcr_tag_heading_frame(void) {
    vec2f pos;
    pos.x = 62.0f;
    pos.y = 67.0f;
    TChCrEffWall::draw_default_sprite(0x36, &pos, -2.75f);
}
void TChCrEffTag::draw_chcr_tag_frame() {
    A_8029A9B8 *arg0 = (A_8029A9B8 *)this;
    vec2f position;
    vec2f scale;
    position.y = 37.0f;
    position.x = 0.0f;
    scale.x = arg0->f20 / 32.0f;
    scale.y = 1.0f;
    draw_ui_sprite_opaque(0x34, &position, &scale, -3.0625f);
    position.x = arg0->f20;
    TChCrEffWall::draw_default_sprite(0x35, &position, -3.0625f);
}

