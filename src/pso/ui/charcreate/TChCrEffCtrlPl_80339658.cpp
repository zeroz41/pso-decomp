#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/render/render_util.h"
#include "pso/ui/UISprite.h"


#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

#pragma readonly_strings on

extern "C" {
const char *TChCrEffCtrlPl__name = "TChCrEffCtrlPl";
}


extern "C" {
const vec2f lbl_80477C70 = {714.0f, 82.0f};
const vec2f lbl_80477C78 = {542.0f, 82.0f};
f32 sin_table_lookup(s32);

#pragma push
#pragma opt_common_subs off
void TChCrEffCtrlPl::render() {
    f32 var_f2;
    set_depth_buffer_settings_1();
    var_f2 = (2.5f) * fade;
    if (var_f2 > (1.0f)) {
        var_f2 = (1.0f);
    }
    draw_ui_sprite(sprite_id, &pos, -1.8125f, var_f2);
    draw_ui_sprite(m_20, &pos, -1.8125f, m_30);
    restore_saved_depth_alpha_state();
}
#pragma pop

#pragma push
#pragma fp_contract on
void TChCrEffCtrlPl::run_task() {
    f32 s;
    f32 v;
    f32 x;
    f32 y;
    m_34 += 0xB60;
    pos.x += (0.05f) * (lbl_80477C78.x - pos.x);
    pos.y += (0.05f) * (lbl_80477C78.y - pos.y);
    fade += (0.011111111f);
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    m_30 = fade;
    if ((1.0f) == fade) {
        s = (1.0f);
        v = sin_table_lookup(m_34);
        if ((m_34 & 0x20000) && v > (0.7f)) {
            s -= v - (0.7f);
        }
        m_30 = s * fade;
    }
}
#pragma pop

TChCrEffCtrlPl::~TChCrEffCtrlPl() {}

}
TChCrEffCtrlPl::TChCrEffCtrlPl(TObject *object) : TObject(object) {
    m_name = TChCrEffCtrlPl__name;
    sprite_id = get_clamped_player_index() + 0x8B;
    m_20 = get_clamped_player_index() + 0xBC;
    ((TWindowSubSymbolChatPartsSet *)&pos)->copy_vec2((void *)&lbl_80477C70);
    fade = 0.0f;
    m_34 = 0;
}

void *TChCrEffCtrlPl::create() {
    return new TChCrEffCtrlPl((TObject *)this);
}
