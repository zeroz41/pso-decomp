#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/charcreate/TChCrTag.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

#pragma readonly_strings on

s32 TChCrTag::is_selected() { return 0; }
void TChCrTag::render() {  }

const char *chcr_tag_class_name = "TChCrTag";

#pragma push
#pragma opt_common_subs off
void TChCrTag::run_task() {
    f32 value;
    f32 highlight;
    f32 fade;
    if (is_selected() != 0) {
        value = m_highlight;
        if (value < 1.0f) {
            m_highlight = value + m_highlight_in_step;
            if (m_highlight > 1.0f) {
                m_highlight = 1.0f;
            }
        }
    } else {
        highlight = m_highlight;
        if (highlight > 0.0f) {
            m_highlight = highlight + m_highlight_out_step;
            if (m_highlight < 0.0f) {
                m_highlight = 0.0f;
            }
        }
    }
    switch (m_fade_state) {
    case 0:
        fade = m_fade;
        if (fade < 1.0f) {
            m_fade = fade + m_fade_in_step;
            if (m_fade > 1.0f) {
                m_fade = 1.0f;
            }
        }
        if (TChCrCharSelect::get_selected_index() == 2) {
            m_fade_state = 1;
            break;
        }
        break;
    case 1:
        m_fade = m_fade + m_fade_out_step;
        if (m_fade <= 0.0f) {
            m_fade = 0.0f;
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TChCrTag::~TChCrTag() {}

TChCrTag::TChCrTag(TObject *object, s32 index) : TObject(object) {
    m_name = chcr_tag_class_name;
    m_index = index;
    m_fade_state = 0;
    m_fade = 0.0f;
    m_highlight = 0.0f;
    m_highlight_in_step = 0.13333334f;
    m_fade_in_step = 0.13333334f;
    m_highlight_out_step = -0.13333334f;
    m_fade_out_step = -0.13333334f;
}

