#include "pso/ui/charcreate/TChCrEffWall.h"
#include "pso/render/render_util.h"

#include "pso/ui/window/TWindowCtrlMain.h"

#include "types.h"
#include "pso/math/TMath.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_801E2F94.h"

extern "C" {
void TCameraCtrl__sub_80068EF0(void);
void draw_default_sprite__12TChCrEffWallFv(s32, const vec2f *, f32);
const char *TChCrEffWall__name = "TChCrEffWall";
extern const vec2f creation_effwall_sprite_position_table[6] = {
    {0.0f, 0.0f}, {0.0f, 256.0f}, {256.0f, 0.0f}, {256.0f, 128.0f}, {256.0f, 256.0f}, {256.0f, 384.0f},
};
extern const vec2f creation_effwall_sprite_size_table[2] = {
    {384.0f, 0.0f}, {384.0f, 256.0f},
};

u32 chcr_eff_wall_gradient_table[4] = {
    0x00000000, 0xFF181818, 0xFF181818, 0x00000000,
};
ColorLineVertex lbl_804DBF68[4] = {
    {140.0f, 0.0f}, {384.0f, 0.0f}, {384.0f, 600.0f}, {140.0f, 600.0f},
};
ColorLineVertex lbl_804DBF88[4] = {
    {640.0f, 0.0f}, {384.0f, 0.0f}, {384.0f, 600.0f}, {640.0f, 600.0f},
};
u32 lbl_804DBFA8[4] = {
    0xEC181818, 0xFF181818, 0xFF181818, 0xEC181818,
};
void TChCrEffWall::render() {
    ColorLineList args;
    s32 i;
    set_depth_buffer_settings_1();
    for (i = 0; i < 6; i++) {
        draw_default_sprite__12TChCrEffWallFv(i + 10, &creation_effwall_sprite_position_table[i], -9935.0f);
    }
    for (i = 0; i < 2; i++) {
        draw_default_sprite__12TChCrEffWallFv(i + 10, &creation_effwall_sprite_size_table[i], -9935.0f);
    }
    TCameraCtrl::restore_full_screen_view();
    args.colors = chcr_eff_wall_gradient_table;
    args.unk_8 = 0;
    args.count = 4;
    args.verts = lbl_804DBF68;
    ((TWindowCtrlMain *)(&args))->draw_strip_swap_color(4, 6, -9934.0f);
    args.colors = lbl_804DBFA8;
    args.verts = lbl_804DBF88;
    ((TWindowCtrlMain *)(&args))->draw_strip_swap_color(4, 6, -9934.0f);
    TCameraCtrl__sub_80068EF0();
    restore_saved_depth_alpha_state();
}

TChCrEffWall::~TChCrEffWall() {}
}
TChCrEffWall::TChCrEffWall(TObject *object) : TObject(object) {
    m_name = TChCrEffWall__name;
}

void *fn_8029AE88(void *arg0) {
    return new TChCrEffWall((TObject *)arg0);
}
