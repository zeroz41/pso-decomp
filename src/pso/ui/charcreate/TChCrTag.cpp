#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"

extern "C" void render__8TChCrTagFv();
#include "pso/ui/charcreate/TChCrCharSelect.h"

#pragma readonly_strings on

extern "C" {
void __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(void *);
void render_shadows__7TObjectFv(void);

int TChCrTag__vt4(void) { return 0; }
void TChCrTag::render() {  }

extern void *__vt__8TChCrTag[];
const char *lbl_805D3D90 = "TChCrTag";

#pragma push
#pragma opt_common_subs off
void update_fade__8TChCrTagFPv(TChCrTag *tag) {
    f32 value;
    f32 highlight;
    f32 fade;
    if (tag->vt4() != 0) {
        value = tag->m_30;
        if (value < 1.0f) {
            tag->m_30 = value + tag->m_34;
            if (tag->m_30 > 1.0f) {
                tag->m_30 = 1.0f;
            }
        }
    } else {
        highlight = tag->m_30;
        if (highlight > 0.0f) {
            tag->m_30 = highlight + tag->m_38;
            if (tag->m_30 < 0.0f) {
                tag->m_30 = 0.0f;
            }
        }
    }
    switch (tag->m_1c) {
    case 0:
        fade = tag->m_24;
        if (fade < 1.0f) {
            tag->m_24 = fade + tag->m_28;
            if (tag->m_24 > 1.0f) {
                tag->m_24 = 1.0f;
            }
        }
        if (TChCrCharSelect::get_selected_index() == 2) {
            tag->m_1c = 1;
            break;
        }
        break;
    case 1:
        tag->m_24 = tag->m_24 + tag->m_2c;
        if (tag->m_24 <= 0.0f) {
            tag->m_24 = 0.0f;
            queue_destruction__7TObjectFv(tag);
        }
        break;
    }
}
#pragma pop

void *__dt__8TChCrTagFv(void *self, s16 arg1) {
    if (self != NULL) {
        *(void ***)((s8 *)self + 0x18) = __vt__8TChCrTag;
        __dt__7TObjectFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

}
TChCrTag::TChCrTag(TObject *object, void *arg2) : TObject(object) {
    m_name = lbl_805D3D90;
    m_20 = (s32)arg2;
    m_1c = 0;
    m_24 = 0.0f;
    m_30 = 0.0f;
    m_34 = 0.13333334f;
    m_28 = 0.13333334f;
    m_38 = -0.13333334f;
    m_2c = -0.13333334f;
}


void *__vt__8TChCrTag[7] = {
    0, 0, (void *)__dt__8TChCrTagFv, (void *)update_fade__8TChCrTagFPv,
    (void *)&render__8TChCrTagFv, (void *)render_shadows__7TObjectFv,
    (void *)TChCrTag__vt4,
};

