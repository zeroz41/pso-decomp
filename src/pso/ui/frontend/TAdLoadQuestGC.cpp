#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowCost.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/camera/TCameraCtrl.h"

#include "types.h"
#include "pso/ui/frontend/TAdLoadQuestCellGC.h"
#include "pso/ui/frontend/TAdLoadQuestLineGC.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
#include "pso/ui/frontend/TAdLdQuestPrtGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#pragma readonly_strings on

extern "C" TWindowCost *create_cost_window(s32 client) {
    if (TCameraCtrl::get_camera_id() <= 2) {
        return NULL;
    }
    return new TWindowCost(const_cast<NJS_POINT2 *>(get_window_layout_position(0x59)), client,
        reinterpret_cast<saddr>(TWindowSubStatusDisp::get_message_10(0x109)));
}

void TAdLoadQuestGC::render() {}
void TAdLoadQuestGC::run_task() {}

TAdLoadQuestGC::~TAdLoadQuestGC() {
    TObject *arrows[3];
    TObject *cells[3];
    TObject *lines[2];
    if (quest_display != NULL) {
        quest_display->queue_destruction();
        quest_display = NULL;
    }
    for (u32 i = 0; i < 3; ++i) {
        arrows[i] = TAdLoadQuestGC::get_text(2 - i);
        if (arrows[i] != NULL) arrows[i]->queue_destruction();
    }
    for (u32 i = 0; i < 2; ++i) {
        lines[i] = TAdLoadQuestGC::get_line(1 - i);
        if (lines[i] != NULL) lines[i]->queue_destruction();
    }
    for (u32 i = 0; i < 3; ++i) {
        cells[i] = TAdLoadQuestGC::get_cell(2 - i);
        if (cells[i] != NULL) cells[i]->queue_destruction();
    }
}

const char *TAdLoadQuestGC__class_name = "TAdLoadQuestGC";

TAdLoadQuestGC::TAdLoadQuestGC(TObject *parent) : TObject(parent) {
    m_name = TAdLoadQuestGC__class_name;
    get_or_create_cell(0);
    get_or_create_prt_txt(0);
    get_or_create_cell(1);
    get_or_create_cell(2);
    get_or_create_line(0);
    get_or_create_line(1);
    get_or_create_prt_txt(1);
    get_or_create_prt_txt(2);
    quest_display = new TAdLdQuestPrtGC(this);
}

void TAdLoadQuestGC::cleanup() {}
void TAdLoadQuestGC::setup() {}

TAdLoadQuestCellGC *TAdLoadQuestGC::get_cell(int slot) {
    return ad_load_quest_cell_table[slot];
}

TAdLoadQuestLineGC *TAdLoadQuestGC::get_line(int slot) {
    return ad_load_quest_line_instances[slot];
}

TAdLoadQuestPrtTxtGC *TAdLoadQuestGC::get_text(int slot) {
    return quest_load_prt_txt_by_slot[slot];
}
