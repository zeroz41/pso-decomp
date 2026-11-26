#include "pso/render/ColorLineList.h"
#include "pso/ui/charcreate/TChCrEffWall.h"
#include "pso/render/render_util.h"

#include "pso/ui/window/TWindowCtrlMain.h"

#include "types.h"
#include "pso/math/TMath.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_801E2F94.h"

const char *TChCrEffWall::name = "TChCrEffWall";
extern const vec2f creation_effwall_sprite_position_table[6] = {
    {0.0f, 0.0f}, {0.0f, 256.0f}, {256.0f, 0.0f}, {256.0f, 128.0f}, {256.0f, 256.0f}, {256.0f, 384.0f},
};
extern const vec2f creation_effwall_sprite_size_table[2] = {
    {384.0f, 0.0f}, {384.0f, 256.0f},
};

u32 chcr_eff_wall_gradient_table[4] = {
    0x00000000, 0xFF181818, 0xFF181818, 0x00000000,
};
ColorLineVertex chcr_eff_wall_left_strip[4] = {
    {140.0f, 0.0f}, {384.0f, 0.0f}, {384.0f, 600.0f}, {140.0f, 600.0f},
};
ColorLineVertex chcr_eff_wall_right_strip[4] = {
    {640.0f, 0.0f}, {384.0f, 0.0f}, {384.0f, 600.0f}, {640.0f, 600.0f},
};
u32 chcr_eff_wall_right_gradient_table[4] = {
    0xEC181818, 0xFF181818, 0xFF181818, 0xEC181818,
};
void TChCrEffWall::render() {
    ColorLineList args;
    s32 i;
    set_depth_buffer_settings_1();
    for (i = 0; i < 6; i++) {
        draw_default_sprite(i + 10, &creation_effwall_sprite_position_table[i], -9935.0f);
    }
    for (i = 0; i < 2; i++) {
        draw_default_sprite(i + 10, &creation_effwall_sprite_size_table[i], -9935.0f);
    }
    TCameraCtrl::restore_full_screen_view();
    args.colors = chcr_eff_wall_gradient_table;
    args.tex = 0;
    args.count = 4;
    args.verts = chcr_eff_wall_left_strip;
    args.draw_strip_swap_color(4, 6, -9934.0f);
    args.colors = chcr_eff_wall_right_gradient_table;
    args.verts = chcr_eff_wall_right_strip;
    args.draw_strip_swap_color(4, 6, -9934.0f);
    TCameraCtrl::restore_saved_view();
    restore_saved_depth_alpha_state();
}

TChCrEffWall::~TChCrEffWall() {}
TChCrEffWall::TChCrEffWall(TObject *object) : TObject(object) {
    m_name = name;
}

TChCrEffWall *create_TChCrEffWall(TObject *parent) {
    return new TChCrEffWall(parent);
}
