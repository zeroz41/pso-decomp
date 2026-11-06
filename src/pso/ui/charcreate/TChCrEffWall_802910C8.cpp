#include "pso/ui/UISpriteConstants.h"
#include "types.h"
#include "pso/ui/charcreate/TChCrEffWall.h"

extern "C" {
s32 draw_ui_sprite(f32, f32);
#pragma push
#pragma fp_contract on
void TChCrEffWall::draw_default_sprite() {
    f32 unused;
    draw_ui_sprite(unused, ui_sprite_unit_scale);
}
#pragma pop

}
