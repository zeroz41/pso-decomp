#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/UISprite.h"
#include "pso/math/TMath.h"
#include "pso/system/vector.h"

#pragma push
#pragma readonly_strings on
const char *TChCrTagPlBack::name = "TChCrTagPlBack";
#pragma pop

extern const vec2f plback_top_left_pos;
extern const vec2f plback_top_right_pos;
extern const vec2f plback_bottom_left_pos;
extern const vec2f plback_bottom_right_pos;
extern const vec2f plback_edge_scale;
extern const vec2f plback_top_edge_pos;
extern const vec2f plback_bottom_edge_pos;
extern const vec2f plback_side_start_pos;

void TChCrTagPlBack::draw_frame() {
    f32 a;
    a = 1.0f;
    if (m_fade < 0.5f) {
        a = m_fade / 0.5f;
    }
    vec2f p1 = plback_top_left_pos;
    draw_ui_sprite(0x7E, &p1, -3.375f, a);
    vec2f p2 = plback_top_right_pos;
    draw_ui_sprite(0x80, &p2, -3.375f, a);
    vec2f p3 = plback_bottom_left_pos;
    draw_ui_sprite(0x84, &p3, -3.375f, a);
    vec2f p4 = plback_bottom_right_pos;
    draw_ui_sprite(0x86, &p4, -3.375f, a);
    vec2f scale = plback_edge_scale;
    vec2f p5 = plback_top_edge_pos;
    draw_ui_sprite_scaled(0x7F, &p5, &scale, -3.375f, a);
    vec2f p6 = plback_bottom_edge_pos;
    draw_ui_sprite_scaled(0x85, &p6, &scale, -3.375f, a);
    vec2f base = plback_side_start_pos;
    vec2f cur;
    for (; base.y <= 396.0f; base.y += 8.0f) {
        copy_vec2((&cur), &base);
        draw_ui_sprite(0x81, &cur, -3.375f, a);
        cur.x += 32.0f;
        draw_ui_sprite_scaled(0x82, &cur, &scale, -3.375f, a);
        cur.x = 575.0f;
        draw_ui_sprite(0x83, &cur, -3.375f, a);
    }
}

void TChCrTagPlBack::render() { draw_frame(); }
s32 TChCrTagPlBack::is_selected() { return 0; }
TChCrTagPlBack::~TChCrTagPlBack() {}

TChCrTagPlBack::TChCrTagPlBack(TObject *parent, s32 index) : TChCrTag(parent, index) {
    m_name = name;
    m_fade_in_step = 0.06666667f;
    m_fade_out_step = -0.06666667f;
    m_highlight_in_step = 0.06666667f;
    m_highlight_out_step = -0.06666667f;
}


TChCrTagPlBack *TChCrTagPlBack::create(s32 index) {
    return new TChCrTagPlBack(tl_03, index);
}

TChCrTagPlBack *TChCrTagPlBack::create_default() { return TChCrTagPlBack::create(0); }


// The frame sprites' positions (and the edge scale), defined after their use so
// draw_frame addresses each one on its own.
__declspec(section ".rodata") const vec2f plback_top_left_pos = {307.0f, 100.0f};
__declspec(section ".rodata") const vec2f plback_top_right_pos = {575.0f, 100.0f};
__declspec(section ".rodata") const vec2f plback_bottom_left_pos = {307.0f, 396.0f};
__declspec(section ".rodata") const vec2f plback_bottom_right_pos = {575.0f, 396.0f};
__declspec(section ".rodata") const vec2f plback_edge_scale = {7.375f, 1.0f};
__declspec(section ".rodata") const vec2f plback_top_edge_pos = {339.0f, 100.0f};
__declspec(section ".rodata") const vec2f plback_bottom_edge_pos = {339.0f, 396.0f};
__declspec(section ".rodata") const vec2f plback_side_start_pos = {307.0f, 132.0f};
