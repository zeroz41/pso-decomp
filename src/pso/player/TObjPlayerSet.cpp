#include "types.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/quest/TQuestThread.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/object/TObjQuestCol2.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/TObject.h"

struct RecoveredGlobal_80195720___vt__13TObjPlayerSet {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
void *__nw__7TObjectFUl(int);
extern s32 tl_00;
u8 *TObjQuestCol2__vt14(TObjQuestCol2 *arg0);
u8 * __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__13TObjPlayerSet[];
extern s32 TObjPlayer__player_set_class_name;
extern const f32 lbl_805DBEF0;
u8 *TObjPlayerSet__ct(TObjPlayerSet *arg0, s32 arg1, s32 arg2);
void *TObjQuestCol2__create(void *arg0);
void *__dt__13TObjPlayerSetFv(void *arg0, s16 arg1);
void *TObjQuestCol2__ct(void *, void *, void *);
void __dl__7TObjectFPv(void *);

void TObjPlayerSet::render() {  }
void TObjPlayerSet::run_task() {  }

extern void *tl_06;

void *TObjPlayerSet::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = TObjPlayerSet__ct((TObjPlayerSet *)((u8 *)o), (s32)tl_06, (s32)arg0);
    }
    return o;
}

}
TObjPlayerSet::~TObjPlayerSet() {

}
extern "C" {

extern void *quest_collision_task_root;

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80195720___vt__13TObjPlayerSet_size[sizeof(RecoveredGlobal_80195720___vt__13TObjPlayerSet) == 0x38 ? 1 : -1];
u8 *TObjPlayerSet__ct(TObjPlayerSet *player_set, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(player_set);
    *(s32 **)((s8 *)player_set + 0x18) = &(*(RecoveredGlobal_80195720___vt__13TObjPlayerSet *)&__vt__13TObjPlayerSet).value;
    *(s32 *)((s8 *)player_set + 0) = (s32) TObjPlayer__player_set_class_name;
    ((TObjPlayerSet *)(player_set))->apply_object_set_data((void *)arg2);
    if (player_set->scale.x < lbl_805DBEF0) {
        player_set->scale.x = (f32) lbl_805DBEF0;
    }
    if ((s32) player_set->set_params[0] < 0) {
        player_set->set_params[0] = 0;
    }
    disallow_rendering__7TObjectFv((TObject *)player_set);
    return (u8 *)player_set;
}
#pragma pop

void *TObjQuestCol2__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC4);
    if (o != NULL) {
        o = TObjQuestCol2__ct(o, quest_collision_task_root, arg0);
    }
    return o;
}
u8 *TObjQuestCol2__vt14(TObjQuestCol2 *quest_col2) {
    TQuestThread *thread;
    TQuestThreadBoard::destroy_board();
    thread = NULL;
    if ((u32) *(u32 *)((s8 *)quest_col2 + 0xBC) != 0U) {
        thread = new TQuestThread(*(TObject **)((s8 *)quest_col2 + 0xBC), quest_col2->m_b0);
        if (thread != NULL) {
            thread->set_parent((TObject *)tl_00);
        }
    }
    return (u8 *)thread;
}

}
