#include "types.h"
#include "pso/render/render_util.h"

#include "pso/misc/TChCrTagInformation.h"
#include "pso/TChCrCharSelect.h"
#include "pso/TObjCMAssignMenu.h"

struct V2_802A1C04 { f32 x; f32 y; };

extern "C" {
void draw_ui_sprite_scaled(s32, V2_802A1C04 *, V2_802A1C04 *, f32, f32);
void draw_ui_sprite(s32, V2_802A1C04 *, f32, f32);
extern V2_802A1C04 lbl_8046638C[];
extern V2_802A1C04 lbl_80466394[];
extern V2_802A1C04 lbl_8046639C[];
extern V2_802A1C04 lbl_804663A4[];
extern V2_802A1C04 lbl_804663AC[];
extern V2_802A1C04 lbl_804663B4[];
extern V2_802A1C04 lbl_804663BC[];
extern V2_802A1C04 lbl_804663C4[];
extern V2_802A1C04 lbl_804663CC[];
extern V2_802A1C04 lbl_804663D4[];
extern V2_802A1C04 lbl_804663DC[];
extern V2_802A1C04 lbl_804663E4[];
extern V2_802A1C04 lbl_804663EC[];
extern const f32 lbl_805DDE10;
extern const f32 lbl_805DDE14;
extern const f32 lbl_805DDE18;
    extern int TChCrCharSelect__input_mode;
int TChCrCharSelect::get_selected_index() {  return TChCrCharSelect__input_mode; }
void TChCrTagInformation::draw_char_info_sprites() {
    TChCrTagInformation *self = this;
    f32 alpha;
    s32 c;
    alpha = lbl_805DDE10;
    if (self->m_24 >= lbl_805DDE14) {
        alpha = (self->m_24 - lbl_805DDE14) / lbl_805DDE14;
    }
    V2_802A1C04 a = lbl_8046638C[0];
    c = TChCrCharSelect::get_selected_char();
    if (c >= 0) {
        draw_ui_sprite(c + 0x87, &a, lbl_805DDE18, alpha);
    }
    V2_802A1C04 b = lbl_80466394[0];
    V2_802A1C04 bs = lbl_8046639C[0];
    set_depth_buffer_settings_1();
    draw_ui_sprite_scaled(0x8A, &b, &bs, lbl_805DDE18, lbl_805DDE14 * alpha);
    restore_saved_depth_alpha_state();
    V2_802A1C04 d = lbl_804663A4[0];
    draw_ui_sprite(0x47, &d, lbl_805DDE18, alpha);
    V2_802A1C04 e = lbl_804663AC[0];
    draw_ui_sprite(0x48, &e, lbl_805DDE18, alpha);
    V2_802A1C04 f = lbl_804663B4[0];
    draw_ui_sprite(0x45, &f, lbl_805DDE18, alpha);
    V2_802A1C04 g = lbl_804663BC[0];
    draw_ui_sprite(0x46, &g, lbl_805DDE18, alpha);
    V2_802A1C04 hs = lbl_804663C4[0];
    V2_802A1C04 h = lbl_804663CC[0];
    draw_ui_sprite_scaled(0x41, &h, &hs, lbl_805DDE18, alpha);
    V2_802A1C04 i = lbl_804663D4[0];
    draw_ui_sprite_scaled(0x42, &i, &hs, lbl_805DDE18, alpha);
    V2_802A1C04 js = lbl_804663DC[0];
    V2_802A1C04 j = lbl_804663E4[0];
    draw_ui_sprite_scaled(0x3F, &j, &js, lbl_805DDE18, alpha);
    V2_802A1C04 k = lbl_804663EC[0];
    draw_ui_sprite_scaled(0x40, &k, &js, lbl_805DDE18, alpha);
}

}
