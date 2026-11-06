#include "pso/ui/frontend/TAdLoadQuestLineGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
s32 __nw__7TObjectFUl(int);
void *__ct__18TAdLoadQuestLineGCFP7TObjectPv(void *arg0, void *arg1, void *arg2);
extern TAdLoadQuestLineGC *ad_load_quest_line_instances[3];
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

extern void *lbl_805D4300;
TAdLoadQuestLineGC::TAdLoadQuestLineGC(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = lbl_805D4300;
    *(void **)((s8 *)this + 0x1C) = arg2;
    this->m_frameCount = -1;
}

s32 get_or_create_line__14TAdLoadQuestGCFii(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r0;
    temp_r30 = arg1 * 4;
    if ((u32) *(s32 *)((s8 *)((s32 *)ad_load_quest_line_instances) + temp_r30) == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x24);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = ((s32)__ct__18TAdLoadQuestLineGCFP7TObjectPv((void *)temp_r3, (void *)arg0, (void *)arg1));
        }
        *(s32 *)((s8 *)((s32 *)ad_load_quest_line_instances) + temp_r30) = var_r0;
    }
    return *(s32 *)((s8 *)((s32 *)ad_load_quest_line_instances) + temp_r30);
}
