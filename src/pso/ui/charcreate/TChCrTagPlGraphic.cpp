#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/charcreate/TChCrTagPlGraphic.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

extern "C" {
#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TChCrTagPlGraphic::draw_class_illustration() {
    vec2f position;
    vec2f size;
    f32 value;
    f32 alpha;
    s32 id;
    if (!(m_3c <= 0.0f)) {
        ((TWindowSubSymbolChatPartsSet *)&position)->copy_vec2(&pos);
        value = m_44;
        size.y = value;
        size.x = value;
        alpha = m_3c;
        id = m_20 * 2 + 0x66;
        draw_ui_sprite_shaded(id, &position, &size, m_40, alpha, alpha);
        position.y += 255.5f * m_44;
        draw_ui_sprite_shaded(id + 1, &position, &size, m_40, alpha, alpha);
    }
}
#pragma pop

}

#include "pso/ui/charcreate/TChCrCharSelect.h"

struct TChCrTagPlGraphicLayout {
    f32 m_44;
    f32 m_40;
    vec2f pos;
    vec2f selected_pos;
};

extern "C" {
void TChCrTagPlGraphic__sub_802A3230(TChCrTagPlGraphic *tag);
void restore_saved_depth_alpha_state(void);
int set_depth_buffer_settings_1__Fv(void*);

void TChCrTagPlGraphic::render() {
    set_depth_buffer_settings_1__Fv(this);
    draw_class_illustration();
    restore_saved_depth_alpha_state();
}

#pragma readonly_strings on
const char *ch_cr_tag_pl_graphic_class_name = "TChCrTagPlGraphic";
#pragma readonly_strings reset

const TChCrTagPlGraphicLayout TChCrTagPlGraphic__data_804664A4[12] = {
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
void TChCrTagPlGraphic__sub_802A3230(TChCrTagPlGraphic *tag) {
    const TChCrTagPlGraphicLayout *e;

    e = &TChCrTagPlGraphic__data_804664A4[tag->m_20];
    tag->m_3c = tag->m_24 * tag->m_30;
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        tag->m_40 += 0.25f * (e->m_40 - tag->m_40);
        tag->m_44 += 0.25f * (e->m_44 - tag->m_44);
        tag->pos.x += 0.25f * (e->pos.x - tag->pos.x);
        tag->pos.y += 0.25f * (e->pos.y - tag->pos.y);
        break;
    default:
        if (tag->vt4() != 0) {
            tag->m_40 += 0.25f * (-2.75f - tag->m_40);
            tag->m_44 += 0.25f * (1.0f - tag->m_44);
            tag->pos.x += 0.25f * (e->selected_pos.x - tag->pos.x);
            tag->pos.y += 0.25f * (e->selected_pos.y - tag->pos.y);
        }
        break;
    }
}
#pragma pop

void TChCrTagPlGraphic::run_task() {
    update_fade__8TChCrTagFPv(this);
    TChCrTagPlGraphic__sub_802A3230(this);
}

s32 TChCrTagPlGraphic::vt4() {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (m_20 / 4 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (m_20 == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

TChCrTagPlGraphic::~TChCrTagPlGraphic() {}

}

TChCrTagPlGraphic::TChCrTagPlGraphic(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    const TChCrTagPlGraphicLayout *e;
    m_name = ch_cr_tag_pl_graphic_class_name;
    m_28 = 0.13333334f;
    m_2c = -0.06666667f;
    m_34 = 0.13333334f;
    m_38 = -0.06666667f;
    m_3c = 0.0f;
    e = &TChCrTagPlGraphic__data_804664A4[m_20];
    m_40 = e->m_40;
    m_44 = e->m_44;
    ((TWindowSubSymbolChatPartsSet *)&pos)->copy_vec2((void *)&e->pos);
}

extern "C" {

void *TChCrTagPlGraphic::create(void *arg0) {
    return new TChCrTagPlGraphic(tl_03, arg0);
}


void TChCrTagPlGraphic::create_matching_tags() {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 12; j++) {
            if (TChCrTagPlGraphic__data_804664A4[j].m_40 == tag_player_graphic_match_value_table[i]) {
                TChCrTagPlGraphic::create((void *)j);
            }
        }
    }
}

}
