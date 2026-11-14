#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/unk/text_80309890.h"
#include "pso/unk/text_803098DC.h"
#include "pso/ui/charcreate/TChCrTagInformation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TObjCMAssignMenu.h"

#pragma readonly_strings on

extern "C" {
extern vec2f lbl_8046638C[];
extern vec2f lbl_80466394[];
extern vec2f lbl_8046639C[];
extern vec2f lbl_804663A4[];
extern vec2f lbl_804663AC[];
extern vec2f lbl_804663B4[];
extern vec2f lbl_804663BC[];
extern vec2f lbl_804663C4[];
extern vec2f lbl_804663CC[];
extern vec2f lbl_804663D4[];
extern vec2f lbl_804663DC[];
extern vec2f lbl_804663E4[];
extern vec2f lbl_804663EC[];
extern int TChCrCharSelect__input_mode;
int TChCrCharSelect::get_selected_index() { return TChCrCharSelect__input_mode; }
void TChCrTagInformation::draw_char_info_sprites() {
    f32 alpha;
    s32 c;
    alpha = 0.0f;
    if (m_24 >= 0.5f) {
        alpha = (m_24 - 0.5f) / 0.5f;
    }
    vec2f a = lbl_8046638C[0];
    c = TChCrCharSelect::get_selected_char();
    if (c >= 0) {
        draw_ui_sprite(c + 0x87, &a, -1.8125f, alpha);
    }
    vec2f b = lbl_80466394[0];
    vec2f bs = lbl_8046639C[0];
    set_depth_buffer_settings_1();
    draw_ui_sprite_scaled(0x8A, &b, &bs, -1.8125f, 0.5f * alpha);
    restore_saved_depth_alpha_state();
    vec2f d = lbl_804663A4[0];
    draw_ui_sprite(0x47, &d, -1.8125f, alpha);
    vec2f e = lbl_804663AC[0];
    draw_ui_sprite(0x48, &e, -1.8125f, alpha);
    vec2f f = lbl_804663B4[0];
    draw_ui_sprite(0x45, &f, -1.8125f, alpha);
    vec2f g = lbl_804663BC[0];
    draw_ui_sprite(0x46, &g, -1.8125f, alpha);
    vec2f hs = lbl_804663C4[0];
    vec2f h = lbl_804663CC[0];
    draw_ui_sprite_scaled(0x41, &h, &hs, -1.8125f, alpha);
    vec2f i = lbl_804663D4[0];
    draw_ui_sprite_scaled(0x42, &i, &hs, -1.8125f, alpha);
    vec2f js = lbl_804663DC[0];
    vec2f j = lbl_804663E4[0];
    draw_ui_sprite_scaled(0x3F, &j, &js, -1.8125f, alpha);
    vec2f k = lbl_804663EC[0];
    draw_ui_sprite_scaled(0x40, &k, &js, -1.8125f, alpha);
}

s32 get_char_select_class_id();

void TChCrTagInformation::render() { draw_char_info_sprites(); }

void TChCrTagInformation::update_selected_char() {
    s32 c;
    if (m_24 < 1.0f) {
        fn_80309890(this, -1);
        return;
    }
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        c = TChCrCharSelect::get_selected_char();
        if (c >= 0) {
            fn_80309890(this, c);
        }
        break;
    default:
        TChCrCharSelect::get_instance();
        fn_80309890(this, get_char_select_class_id() + 3);
        break;
    }
}

void TChCrTagInformation::run_task() { update_fade__8TChCrTagFPv(this); update_selected_char(); }
s32 TChCrTagInformation::vt4() { return 0; }

TChCrTagInformation::~TChCrTagInformation() {
    fn_803098DC();
}

const char *TChCrTagInformation__class_name = "TChCrTagInformation";

}

TChCrTagInformation::TChCrTagInformation(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = TChCrTagInformation__class_name;
    m_28 = 0.06666667f;
    m_2c = -0.06666667f;
    m_34 = 0.06666667f;
    m_38 = -0.06666667f;
    fn_803098E8();
}

extern "C" {

void *TChCrTagInformation::create(void *arg0) {
    return new TChCrTagInformation(tl_03, arg0);
}

void *TChCrTagInformation::create_default() { return TChCrTagInformation::create(NULL); }

}
