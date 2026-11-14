#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/math/TMath.h"

extern "C" void render__18TChCrTagOccupationFv();

extern "C" {
void render_shadows__7TObjectFv();
}

extern "C" {
extern void *__vt__18TChCrTagOccupation[];
const char *chcr_tag_occupation_class_name = "TChCrTagOccupation";
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
        s = 0.4f * m_30 + 0.6f;
        break;
    default:
        s = m_30;
        break;
    }
    if (vt4() != 0) {
        depth = -3.375f;
    } else {
        depth = 0.3125f * s + -3.6875f;
    }
    pos.x = 25.0f * (1.0f - t) + pos.x;
    pos.y = 108.0f * (f32)m_20 + pos.y;
    draw_ui_sprite_shaded(id, &pos, &scale, depth, 1.0f, 0.75f * (s * s) + 0.25f);
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
            TObject::operator delete(tag);
        }
    }
    return tag;
}
}

#pragma push
#pragma fp_contract on
TChCrTagOccupation::TChCrTagOccupation(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = chcr_tag_occupation_class_name;
    m_28 = 0.033333335f;
    m_2c = -0.022222223f;
    m_34 = 0.6666667f;
    m_38 = -0.06666667f;
    m_3c = 0.053333331f * (f32)m_20 + 0.8f;
    m_40 = 1.0f;
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

