#include "types.h"
#include "pso/ui/TAdLoadQuestCellGC.h"
#include "pso/ui/TAdLoadQuestLineGC.h"
#include "pso/unk/text_8034A090.h"
#include "pso/ui/TAdLoadQuestGC_80309788.h"
#include "pso/ui/TAdLoadQuestGC.h"
#include "pso/ui/TAdLdQuestPrtGC.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);
void *__nw__7TObjectFUl(int);

extern s32 __vt__14TAdLoadQuestGC[];
extern void *TAdLoadQuestGC__class_name;

void *TAdLoadQuestGC__ct(void *ad_load_quest_gc) {
    void *o;
    __ct__7TObjectFP7TObject(ad_load_quest_gc);
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
