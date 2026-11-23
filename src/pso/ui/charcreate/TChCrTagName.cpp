#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagName.h"
#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/math/TMath.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"

__declspec(section ".rodata") extern const char TChCrTagName__class_name_string[] = "TChCrTagName";
const char *TChCrTagName__class_name = TChCrTagName__class_name_string;
extern vec2f lbl_80466408[];
extern vec2f lbl_80466410[];
extern vec2f lbl_80466418[];
extern vec2f lbl_80466420[];
extern vec2f lbl_80466428[];
extern vec2f lbl_80466430[];


#pragma push
#pragma fp_contract on
void TChCrTagName::draw_tag_sprites() {
    s32 id;
    f32 s;
    f32 depth;
    f32 t;
    f32 bright;
    f32 t2;
    f32 alpha;
    vec2f pos;
    vec2f scale = lbl_80466430[0];
    if (this->m_fade > this->m_slide_end) {
        t = (this->m_fade - this->m_slide_end) / ((1.0f) - this->m_slide_end);
    } else {
        return;
    }
    s = calc_highlight_scale();
    if (is_selected() != 0) {
        depth = (-1.8125f);
    } else {
        depth = (0.3125f) * s + (-2.125f);
    }
    bright = (0.75f) * (s * s) + (0.25f);
    t2 = t * t;
    copy_vec2((&pos), &this->pos);
    pos.x += (5.0f);
    pos.y += (9.0f);
    alpha = t2;
    id = this->m_index + 0x4B;
    if (is_selected() != 0) {
        alpha = (0.25f) * sin_table_lookup(this->m_frame << 9) + t2;
        if (alpha < 0.0f) {
            alpha = 0.0f;
        } else if (alpha > (1.0f)) {
            alpha = (1.0f);
        }
    }
    draw_ui_sprite_shaded(id, &pos, &scale, depth, alpha, bright);
    copy_vec2((&pos), &this->pos);
    pos.x = (169.0f);
    pos.y += (3.0f);
    draw_ui_sprite_shaded(this->m_index + 0x57, &pos, &scale, depth, t2, bright);
}

void TChCrTagName::draw_tag_frame() {
    f32 s;
    f32 depth;
    f32 t = (1.0f);
    f32 bright;
    if (this->m_fade < this->m_slide_end) {
        t = (this->m_fade - this->m_slide_start) / (this->m_slide_end - this->m_slide_start);
    }
    s = calc_highlight_scale();
    if (is_selected() != 0) {
        depth = (-2.125f);
    } else {
        depth = (0.3125f) * s + (-2.4375f);
    }
    bright = (0.75f) * (s * s) + (0.25f);
    t = t * t;
    {
        vec2f scale = lbl_80466410[0];
        vec2f pos;
        copy_vec2((&pos), &this->pos);
        draw_ui_sprite_shaded(0x41, &pos, &scale, depth, t, bright);
        pos.y += (22.0f);
        draw_ui_sprite_shaded(0x42, &pos, &scale, depth, t, bright);
    }
    {
        vec2f scale = lbl_80466418[0];
        vec2f pos;
        copy_vec2((&pos), &this->pos);
        pos.x += (226.0f);
        draw_ui_sprite_shaded(this->m_index == 0 ? 0x44 : 0x48, &pos, &scale, depth, t, bright);
        pos.y += (22.0f);
        draw_ui_sprite_shaded(this->m_index == 11 ? 0x46 : 0x4A, &pos, &scale, depth, t, bright);
    }
    {
        vec2f scale = lbl_80466420[0];
        vec2f pos;
        copy_vec2((&pos), &this->pos);
        pos.x += (226.0f);
        pos.y += (8.0f);
        draw_ui_sprite_shaded(0x40, &pos, &scale, depth, t, bright);
    }
    if (this->m_fade < (1.0f)) {
        vec2f scale = lbl_80466428[0];
        vec2f pos;
        copy_vec2((&pos), &this->pos);
        pos.x -= (3.0f);
        draw_ui_sprite_shaded(0x3F, &pos, &scale, depth, t, bright);
    }
}

void TChCrTagName::draw_tag_sprite() {
    f32 s;
    f32 depth;
    f32 t;
    vec2f pos;
    s32 id = this->m_index / 4 + 0x3C;
    vec2f scale = lbl_80466408[0];
    t = (1.0f);
    if (this->m_fade < this->m_slide_end) {
        t = (this->m_fade - this->m_slide_start) / (this->m_slide_end - this->m_slide_start);
    }
    s = calc_highlight_scale();
    if (is_selected() != 0) {
        depth = (-2.4375f);
    } else {
        depth = (0.3125f) * s + (-2.75f);
    }
    copy_vec2((&pos), &this->pos);
    pos.y += (3.0f);
    draw_ui_sprite_shaded(id, &pos, &scale, depth, t * t, (0.75f) * (s * s) + (0.25f));
}
#pragma pop

__declspec(section ".rodata") vec2f lbl_80466408[1] = {{9.625f, 1.0f}};
__declspec(section ".rodata") vec2f lbl_80466410[1] = {{28.25f, 1.0f}};
__declspec(section ".rodata") vec2f lbl_80466418[1] = {{1.0f, 1.0f}};
__declspec(section ".rodata") vec2f lbl_80466420[1] = {{1.0f, 1.75f}};
__declspec(section ".rodata") vec2f lbl_80466428[1] = {{1.0f, 3.75f}};
__declspec(section ".rodata") vec2f lbl_80466430[1] = {{1.0f, 1.0f}};

void TChCrTagName::render() {
    draw_tag_sprite();
    draw_tag_frame();
    draw_tag_sprites();
}

#pragma push
#pragma fp_contract on
f32 TChCrTagName::calc_highlight_scale() {
    s32 r;
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        r = 0;
        break;
    default:
        if (this->m_index / 4 == TChCrCharSelect::get_selected_char()) {
            r = 0;
        } else {
            r = 1;
        }
        break;
    }
    if (r != 0) {
        return this->m_highlight;
    }
    return (0.4f) * this->m_highlight + (0.6f);
}

void TChCrTagName::update_slide_in() {
    f32 progress;
    f32 fade;
    f32 slide;
    f32 start;
    slide = (1.0f);
    this->pos.x = (58.0f);
    this->pos.y = (27.0f) * (f32)this->m_index + (1e+02f);
    fade = this->m_fade;
    progress = this->m_slide_end;
    if (fade < progress) {
        if (1) {
            start = this->m_slide_start;
            progress = (fade - start) / (progress - start);
            slide = (0.5f) * ((1.0f) - cos_table_lookup((s32)((32768.0f) * progress)));
        }
    }
    this->pos.x = this->pos.x + ((3e+02f) * slide + (-3e+02f));
}

void TChCrTagName::run_task() {
    TChCrTag::run_task();
    update_slide_in();
    m_frame = m_frame + 1;
}


s32 TChCrTagName::is_selected() {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (m_index / 4 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    case 1:
    case 2:
        if (m_index == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}
TChCrTagName::~TChCrTagName() {}

TChCrTagName::TChCrTagName(TObject *parent, s32 index) : TChCrTag(parent, index) {
    m_name = TChCrTagName__class_name;
    m_fade_in_step = (0.033333335f);
    m_fade_out_step = (-0.022222223f);
    m_highlight_in_step = (0.6666667f);
    m_highlight_out_step = (-0.06666667f);
    m_slide_start = (0.0f);
    m_slide_end = 0.8f - 0.053333335f * (f32)(0xC - m_index);
    update_slide_in();
    m_frame = 0;
}

#pragma pop

TChCrTagName *TChCrTagName::create(s32 index) {
    return new TChCrTagName(tl_03, index);
}

void TChCrTagName::create_all() {
    saddr i;
    for (i = 0; i < 12; i++) {
        TChCrTagName::create(i);
    }
}
