#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/render/render_util.h"
#include "pso/ui/UISprite.h"


#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"

#pragma readonly_strings on

const char *TChCrEffCtrlPl::name = "TChCrEffCtrlPl";
static const vec2f start_pos = {714.0f, 82.0f};
static const vec2f target_pos = {542.0f, 82.0f};

#pragma push
#pragma opt_common_subs off
void TChCrEffCtrlPl::render() {
    f32 alpha;
    set_depth_buffer_settings_1();
    alpha = (2.5f) * fade;
    if (alpha > (1.0f)) {
        alpha = (1.0f);
    }
    draw_ui_sprite(sprite_id, &pos, -1.8125f, alpha);
    draw_ui_sprite(overlay_sprite_id, &pos, -1.8125f, overlay_alpha);
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
    blink_angle += 0xB60;
    pos.x += (0.05f) * (target_pos.x - pos.x);
    pos.y += (0.05f) * (target_pos.y - pos.y);
    fade += (0.011111111f);
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    overlay_alpha = fade;
    if ((1.0f) == fade) {
        s = (1.0f);
        v = sin_table_lookup(blink_angle);
        if ((blink_angle & 0x20000) && v > (0.7f)) {
            s -= v - (0.7f);
        }
        overlay_alpha = s * fade;
    }
}
#pragma pop

TChCrEffCtrlPl::~TChCrEffCtrlPl() {}

TChCrEffCtrlPl::TChCrEffCtrlPl(TObject *parent) : TObject(parent) {
    m_name = name;
    sprite_id = get_clamped_player_index() + 0x8B;
    overlay_sprite_id = get_clamped_player_index() + 0xBC;
    copy_vec2(&pos, (void *)&start_pos);
    fade = 0.0f;
    blink_angle = 0;
}

TChCrEffCtrlPl *TChCrEffCtrlPl::create(TObject *parent) {
    return new TChCrEffCtrlPl(parent);
}
