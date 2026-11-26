#include "types.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/charcreate/TChCrTagPlGraphic.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TChCrTagPlGraphic::draw_class_illustration() {
    vec2f position;
    vec2f size;
    f32 value;
    f32 alpha;
    s32 id;
    if (!(m_alpha <= 0.0f)) {
        copy_vec2(&position, &pos);
        value = m_scale;
        size.y = value;
        size.x = value;
        alpha = m_alpha;
        id = m_index * 2 + 0x66;
        draw_ui_sprite_shaded(id, &position, &size, m_depth, alpha, alpha);
        position.y += 255.5f * m_scale;
        draw_ui_sprite_shaded(id + 1, &position, &size, m_depth, alpha, alpha);
    }
}
#pragma pop

#include "pso/ui/charcreate/TChCrCharSelect.h"


void TChCrTagPlGraphic::render() {
    set_depth_buffer_settings_1();
    draw_class_illustration();
    restore_saved_depth_alpha_state();
}

#pragma readonly_strings on
const char *ch_cr_tag_pl_graphic_class_name = "TChCrTagPlGraphic";
#pragma readonly_strings reset

const TChCrTagPlGraphicLayout tag_player_graphic_layout_table[12] = {
    {0.85f, -3.0625f, {337.0f, 158.0f}, {405.0f, 127.0f}},
    {0.8f, -3.140625f, {435.0f, 160.0f}, {448.0f, 128.0f}},
    {0.94f, -3.21875f, {343.0f, 125.0f}, {489.0f, 127.0f}},
    {0.88f, -3.296875f, {497.0f, 140.0f}, {476.0f, 128.0f}},
    {0.85f, -3.0625f, {467.0f, 168.0f}, {447.0f, 122.0f}},
    {0.8f, -3.140625f, {389.0f, 182.0f}, {457.0f, 129.0f}},
    {1.0f, -3.296875f, {317.0f, 117.0f}, {430.0f, 132.0f}},
    {0.75f, -3.21875f, {534.0f, 178.0f}, {488.0f, 128.0f}},
    {0.85f, -3.140625f, {447.0f, 130.0f}, {472.0f, 124.0f}},
    {0.83f, -3.296875f, {495.0f, 136.0f}, {465.0f, 124.0f}},
    {0.85f, -3.21875f, {327.0f, 142.0f}, {461.0f, 129.0f}},
    {0.85f, -3.0625f, {384.0f, 136.0f}, {458.0f, 117.0f}},
};

const f32 tag_player_graphic_match_value_table[4] = {-3.296875f, -3.21875f, -3.140625f, -3.0625f};

#pragma push
#pragma fp_contract on
void TChCrTagPlGraphic::update_layout() {
    const TChCrTagPlGraphicLayout *e;

    e = &tag_player_graphic_layout_table[this->m_index];
    this->m_alpha = this->m_fade * this->m_highlight;
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        this->m_depth += 0.25f * (e->m_depth - this->m_depth);
        this->m_scale += 0.25f * (e->m_scale - this->m_scale);
        this->pos.x += 0.25f * (e->pos.x - this->pos.x);
        this->pos.y += 0.25f * (e->pos.y - this->pos.y);
        break;
    default:
        if (this->is_selected() != 0) {
            this->m_depth += 0.25f * (-2.75f - this->m_depth);
            this->m_scale += 0.25f * (1.0f - this->m_scale);
            this->pos.x += 0.25f * (e->selected_pos.x - this->pos.x);
            this->pos.y += 0.25f * (e->selected_pos.y - this->pos.y);
        }
        break;
    }
}
#pragma pop

void TChCrTagPlGraphic::run_task() {
    TChCrTag::run_task();
    update_layout();
}

s32 TChCrTagPlGraphic::is_selected() {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (m_index / 4 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (m_index == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

TChCrTagPlGraphic::~TChCrTagPlGraphic() {}


TChCrTagPlGraphic::TChCrTagPlGraphic(TObject *parent, s32 index) : TChCrTag(parent, index) {
    const TChCrTagPlGraphicLayout *e;
    m_name = ch_cr_tag_pl_graphic_class_name;
    m_fade_in_step = 0.13333334f;
    m_fade_out_step = -0.06666667f;
    m_highlight_in_step = 0.13333334f;
    m_highlight_out_step = -0.06666667f;
    m_alpha = 0.0f;
    e = &tag_player_graphic_layout_table[m_index];
    m_depth = e->m_depth;
    m_scale = e->m_scale;
    copy_vec2(&pos, (void *)&e->pos);
}

TChCrTagPlGraphic *TChCrTagPlGraphic::create(s32 index) {
    return new TChCrTagPlGraphic(tl_03, index);
}

void TChCrTagPlGraphic::create_matching_tags() {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 12; j++) {
            if (tag_player_graphic_layout_table[j].m_depth == tag_player_graphic_match_value_table[i]) {
                TChCrTagPlGraphic::create(j);
            }
        }
    }
}

