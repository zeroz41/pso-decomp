#include "pso/ui/TAdLoadQuestGC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TCameraCtrl.h"

#include "types.h"
#include "pso/ui/TAdLoadQuestCellGC.h"
#include "pso/ui/TAdLoadQuestLineGC.h"
#include "pso/unk/text_8034A090.h"
#include "pso/ui/TAdLdQuestPrtGC.h"

extern "C" {

s32 TWindowCost__ct(s32, s32, s32, s32);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 __nw__7TObjectFUl(s32);
s32 get_window_layout_position(s32);

s32 create_cost_window(s32 arg0) {
    s32 var_r30;

    if (TCameraCtrl::get_camera_id() <= 2) {
        return 0;
    }
    var_r30 = __nw__7TObjectFUl(0x74);
    if (var_r30 != 0) {
        var_r30 = TWindowCost__ct(var_r30, get_window_layout_position(0x59), arg0, get_message_10__20TWindowSubStatusDispFl(0x109));
    }
    return var_r30;
}

}

void TAdLoadQuestGC::render() {}
void TAdLoadQuestGC::run_task() {}

TAdLoadQuestGC::~TAdLoadQuestGC() {
    TObject *arrows[3];
    TObject *cells[3];
    TObject *lines[2];
    if (quest_display != NULL) {
        queue_destruction__7TObjectFv(quest_display);
        quest_display = NULL;
    }
    for (u32 i = 0; i < 3; ++i) {
        arrows[i] = (TObject *)TAdLoadQuestGC__sub_8030987C(2 - i);
        if (arrows[i] != NULL) queue_destruction__7TObjectFv(arrows[i]);
    }
    for (u32 i = 0; i < 2; ++i) {
        lines[i] = (TObject *)TAdLoadQuestGC__sub_80309868(1 - i);
        if (lines[i] != NULL) queue_destruction__7TObjectFv(lines[i]);
    }
    for (u32 i = 0; i < 3; ++i) {
        cells[i] = (TObject *)TAdLoadQuestGC__sub_80309854(2 - i);
        if (cells[i] != NULL) queue_destruction__7TObjectFv(cells[i]);
    }
}

extern "C" {

void __ct__7TObjectFP7TObject(void *, TObject *);

extern s32 __vt__14TAdLoadQuestGC[];
extern void *TAdLoadQuestGC__class_name;

void *TAdLoadQuestGC__ct(void *ad_load_quest_gc, TObject *parent) {
    void *o;
    __ct__7TObjectFP7TObject(ad_load_quest_gc, parent);
    *(s32 **)((s8 *)ad_load_quest_gc + 0x18) = __vt__14TAdLoadQuestGC;
    *(void * *)&((TAdLoadQuestGC *)ad_load_quest_gc)->m_name = TAdLoadQuestGC__class_name;
    get_or_create_cell__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 0);
    get_or_create_prt_txt__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 0);
    get_or_create_cell__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 1);
    get_or_create_cell__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 2);
    get_or_create_line__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 0);
    get_or_create_line__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 1);
    get_or_create_prt_txt__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 1);
    get_or_create_prt_txt__14TAdLoadQuestGCFii((s32)ad_load_quest_gc, 2);
    o = new TAdLdQuestPrtGC((TObject *)ad_load_quest_gc);
    *(void * *)&((TAdLoadQuestGC *)ad_load_quest_gc)->quest_display = o;
    return ad_load_quest_gc;
}

void TAdLoadQuestGC__sub_8030984C(void) {  }
void TAdLoadQuestGC__sub_80309850(void) {  }

}

    extern int ad_load_quest_cell_table[];
int TAdLoadQuestGC__sub_80309854(int a0) {  return ad_load_quest_cell_table[a0]; }

    extern int ad_load_quest_line_instances[];
int TAdLoadQuestGC__sub_80309868(int a0) {  return ad_load_quest_line_instances[a0]; }

    extern int quest_load_prt_txt_by_slot[];
int TAdLoadQuestGC__sub_8030987C(int a0) {  return quest_load_prt_txt_by_slot[a0]; }
