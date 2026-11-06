#include "pso/ui/frontend/TAdLoadQuestCellGC.h"
#include "pso/unk/text_8034960C.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
s32 __nw__7TObjectFUl(int);
void *__ct__18TAdLoadQuestCellGCFP7TObjectPv(void *arg0, void *arg1, void *arg2);
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

extern void *lbl_805D42F8;
TAdLoadQuestCellGC::TAdLoadQuestCellGC(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = lbl_805D42F8;
    *(void **)((s8 *)this + 0x1C) = arg2;
    this->m_frameCount = -1;
}

s32 get_or_create_cell__14TAdLoadQuestGCFii(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r0;
    temp_r30 = arg1 * 4;
    if ((u32) *(s32 *)((s8 *)((s32 *)ad_load_quest_cell_table) + temp_r30) == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x24);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = ((s32)__ct__18TAdLoadQuestCellGCFP7TObjectPv((void *)temp_r3, (void *)arg0, (void *)arg1));
        }
        *(s32 *)((s8 *)((s32 *)ad_load_quest_cell_table) + temp_r30) = var_r0;
    }
    return *(s32 *)((s8 *)((s32 *)ad_load_quest_cell_table) + temp_r30);
}
