#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/math/TMath.h"

const char *chcr_tag_occupation_class_name = "TChCrTagOccupation";
#pragma push
#pragma fp_contract on
void TChCrTagOccupation::draw_occupation() {
    f32 t;
    f32 s;
    f32 depth;
    s32 id = m_index + 0x39;
    vec2f pos = {33.0f, 100.0f};
    vec2f scale = {1.0f, 1.0f};
    if (m_fade > m_slide_start) {
        t = (m_fade - m_slide_start) / (m_slide_end - m_slide_start);
    } else {
        return;
    }
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        s = 0.4f * m_highlight + 0.6f;
        break;
    default:
        s = m_highlight;
        break;
    }
    if (is_selected() != 0) {
        depth = -3.375f;
    } else {
        depth = 0.3125f * s + -3.6875f;
    }
    pos.x = 25.0f * (1.0f - t) + pos.x;
    pos.y = 108.0f * (f32)m_index + pos.y;
    draw_ui_sprite_shaded(id, &pos, &scale, depth, 1.0f, 0.75f * (s * s) + 0.25f);
}
#pragma pop

void TChCrTagOccupation::render() { draw_occupation(); }

s32 TChCrTagOccupation::is_selected() {
    if (TChCrCharSelect::get_selected_char() == m_index) return 1;
    return 0;
}

TChCrTagOccupation::~TChCrTagOccupation() {}

#pragma push
#pragma fp_contract on
TChCrTagOccupation::TChCrTagOccupation(TObject *parent, s32 index) : TChCrTag(parent, index) {
    m_name = chcr_tag_occupation_class_name;
    m_fade_in_step = 0.033333335f;
    m_fade_out_step = -0.022222223f;
    m_highlight_in_step = 0.6666667f;
    m_highlight_out_step = -0.06666667f;
    m_slide_start = 0.053333331f * (f32)m_index + 0.8f;
    m_slide_end = 1.0f;
}
#pragma pop


TChCrTagOccupation *TChCrTagOccupation::create(s32 index) {
    return new TChCrTagOccupation(tl_03, index);
}

void TChCrTagOccupation::create_all() {
    saddr i;
    for (i = 0; i < 3; i++) {
        TChCrTagOccupation::create(i);
    }
}
