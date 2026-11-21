#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/ui/frontend/TAdLoadQuestCellGC.h"
#include "pso/unk/text_8034960C.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

extern "C" {
__declspec(section ".data") TAdLoadQuestCellGC *ad_load_quest_cell_table[3] = { 0, 0, 0 };

void TAdLoadQuestCellGC::render_state() {

    switch (this->m_state) {
    case 0:
        fn_80349844();
        return;
    case 1:
        draw_quest_load_letterbox_bars();
        return;
    case 2:
        draw_quest_load_panel_overlays();
        return;
    }
}

}

void TAdLoadQuestCellGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        ++m_frameCount;
        if (m_frameCount >= 2) {
            render_state();
        }
    }
}

void TAdLoadQuestCellGC::run_task() {}

TAdLoadQuestCellGC::~TAdLoadQuestCellGC() {
    if (ad_load_quest_cell_table[m_state] != NULL) {
        ad_load_quest_cell_table[m_state] = NULL;
    }
}

extern const char *TAdLoadQuestCellGC__name;
TAdLoadQuestCellGC::TAdLoadQuestCellGC(TObject *parent, s32 state) : TObject(parent) {
    this->m_name = TAdLoadQuestCellGC__name;
    m_state = state;
    this->m_frameCount = -1;
}

TAdLoadQuestCellGC *TAdLoadQuestGC::get_or_create_cell(int slot) {
    if (ad_load_quest_cell_table[slot] == NULL) {
        ad_load_quest_cell_table[slot] = new TAdLoadQuestCellGC(this, slot);
    }
    return ad_load_quest_cell_table[slot];
}
