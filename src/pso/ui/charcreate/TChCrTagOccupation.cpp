#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/charcreate/TChCrTagOccHeader.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
extern "C" void render__18TChCrTagOccupationFv();
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {

int render__17TChCrTagOccHeaderFv(void* p);
int fn_802A2A00(void*);

void TChCrTagOccHeader::render() { fn_802A2A00(this); }

}

extern "C" {
s32 TChCrTagOccHeader__vt4(TChCrTagOccHeader *tag);
void run_task__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag);

void TChCrTagOccHeader::run_task() {
    update_fade__8TChCrTagFPv(this);
    m_3c = m_3c + 1;
}
s32 TChCrTagOccHeader__vt4(TChCrTagOccHeader *tag) {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (tag->m_20 < 3 && tag->m_20 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (tag->m_20 >= 3 && tag->m_20 - 3 == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void *__vt__17TChCrTagOccHeader[];
void __dl__7TObjectFPv(void *);
TChCrTagOccHeader *__dt__17TChCrTagOccHeaderFv(TChCrTagOccHeader *tag, s16 free) {
    if (tag != NULL) {
        *(void ***)((u8 *)tag + 0x18) = __vt__17TChCrTagOccHeader;
        __dt__8TChCrTagFv(tag, 0);
        if (free > 0) {
            __dl__7TObjectFPv(tag);
        }
    }
    return tag;
}

void render_shadows__7TObjectFv();
void *__vt__17TChCrTagOccHeader[] = {
    0, 0,
    (void *)__dt__17TChCrTagOccHeaderFv,
    (void *)run_task__17TChCrTagOccHeaderFv,
    (void *)render__17TChCrTagOccHeaderFv,
    (void *)render_shadows__7TObjectFv,
    (void *)TChCrTagOccHeader__vt4,
    0,
};


extern const f32 lbl_805DDECC;
extern const f32 lbl_805DDED0;
extern const char *chcr_tag_occ_header_class_name;

}

TChCrTagOccHeader::TChCrTagOccHeader(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = chcr_tag_occ_header_class_name;
    m_28 = lbl_805DDECC;
    m_2c = lbl_805DDED0;
    m_34 = lbl_805DDECC;
    m_38 = lbl_805DDED0;
}

void *create_ch_cr_tag_occ_header(void *arg0) {
    return new TChCrTagOccHeader(tl_03, arg0);
}

void create_all_ch_cr_tag_headers(void) {
    int i;
    for (i = 0; i < 15; i++) {
        create_ch_cr_tag_occ_header((void *)i);
    }
}

#include "pso/math/TMath.h"

extern "C" {
extern const f32 lbl_805DDED8;
extern const f32 lbl_805DDEDC;
extern const f32 lbl_805DDEE0;
extern const f32 lbl_805DDEE4;
extern const f32 lbl_805DDEE8;
extern const f32 lbl_805DDEEC;
extern const f32 lbl_805DDEF0;
extern const f32 lbl_805DDEF4;
extern const f32 lbl_805DDEF8;
extern const f32 lbl_805DDEFC;
extern void *__vt__18TChCrTagOccupation[];
const char *chcr_tag_occupation_class_name = "TChCrTagOccupation";
extern const f32 lbl_805DDF00;
extern const f32 lbl_805DDF04;
extern const f32 lbl_805DDF08;
extern const f32 lbl_805DDF0C;
extern const f32 lbl_805DDF10;
extern const f32 lbl_805DDF14;
int TChCrTagOccupation__vt4(TChCrTagOccupation *tag);
#pragma push
#pragma fp_contract on
void TChCrTagOccupation::sub_802A2DF4() {
    f32 t;
    f32 s;
    f32 depth;
    s32 id = m_20 + 0x39;
    vec2f pos = {33.0f, 100.0f};
    vec2f scale = {1.0f, 1.0f};
    if (m_24 > m_3c) {
        t = (m_24 - m_3c) / (m_40 - m_3c);
    } else {
        return;
    }
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        s = lbl_805DDEDC * m_30 + lbl_805DDED8;
        break;
    default:
        s = m_30;
        break;
    }
    if (vt4() != 0) {
        depth = lbl_805DDEE0;
    } else {
        depth = lbl_805DDEE8 * s + lbl_805DDEE4;
    }
    pos.x = lbl_805DDEEC * (lbl_805DDEF0 - t) + pos.x;
    pos.y = lbl_805DDEF4 * (f32)m_20 + pos.y;
    draw_ui_sprite_shaded(id, &pos, &scale, depth, lbl_805DDEF0, lbl_805DDEFC * (s * s) + lbl_805DDEF8);
}
#pragma pop

void TChCrTagOccupation::render() { sub_802A2DF4(); }

int TChCrTagOccupation__vt4(TChCrTagOccupation *tag) {
    if (TChCrCharSelect::get_selected_char() == tag->m_20) return 1;
    return 0;
}

TChCrTagOccupation *__dt__18TChCrTagOccupationFv(TChCrTagOccupation *tag, s16 free) {
    if (tag != NULL) {
        *(void ***)((u8 *)tag + 0x18) = __vt__18TChCrTagOccupation;
        __dt__8TChCrTagFv(tag, 0);
        if (free > 0) {
            __dl__7TObjectFPv(tag);
        }
    }
    return tag;
}
}

#pragma push
#pragma fp_contract on
TChCrTagOccupation::TChCrTagOccupation(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = chcr_tag_occupation_class_name;
    m_28 = lbl_805DDF00;
    m_2c = lbl_805DDF04;
    m_34 = lbl_805DDF08;
    m_38 = lbl_805DDF0C;
    m_3c = lbl_805DDF14 * (f32)m_20 + lbl_805DDF10;
    m_40 = lbl_805DDEF0;
}
#pragma pop

extern "C" {

void *TChCrTagOccupation::create(void *arg0) {
    return new TChCrTagOccupation(tl_03, arg0);
}

void TChCrTagOccupation::create_all() {
    int i;
    for (i = 0; i < 3; i++) {
        TChCrTagOccupation::create((void *)i);
    }
}

void *__vt__18TChCrTagOccupation[8] = {
    0,
    0,
    (void *)__dt__18TChCrTagOccupationFv,
    (void *)update_fade__8TChCrTagFPv,
    (void *)&render__18TChCrTagOccupationFv,
    (void *)render_shadows__7TObjectFv,
    (void *)TChCrTagOccupation__vt4,
    0,
};
}

