#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/ui/frontend/TAdLoadQuestLineGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 init_quest_line_draw_colors();
s32 fn_80349E5C();

void TAdLoadQuestLineGC::render_by_state() {

    switch (this->m_state) {
    case 0:
        fn_80349E5C();
        return;
    case 1:
        init_quest_line_draw_colors();
        return;
    }
}

}

void TAdLoadQuestLineGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        ++m_frameCount;
        if (m_frameCount >= 2) {
            render_by_state();
        }
    }
}

void TAdLoadQuestLineGC::run_task() {}

TAdLoadQuestLineGC::~TAdLoadQuestLineGC() {
    if (ad_load_quest_line_instances[m_state] != NULL) {
        ad_load_quest_line_instances[m_state] = NULL;
    }
}

extern "C" { extern char TAdLoadQuestLineGC__class_name_string[]; }
const char *lbl_805D4300 = TAdLoadQuestLineGC__class_name_string;
TAdLoadQuestLineGC::TAdLoadQuestLineGC(TObject *parent, s32 state) : TObject(parent) {
    this->m_name = lbl_805D4300;
    m_state = state;
    this->m_frameCount = -1;
}

TAdLoadQuestLineGC *TAdLoadQuestGC::get_or_create_line(int slot) {
    if (ad_load_quest_line_instances[slot] == NULL) {
        ad_load_quest_line_instances[slot] = new TAdLoadQuestLineGC(this, slot);
    }
    return ad_load_quest_line_instances[slot];
}

__declspec(section ".data") TAdLoadQuestLineGC *ad_load_quest_line_instances[2] = { NULL, NULL };
