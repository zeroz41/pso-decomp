#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TUnk_804B6C24.h"

struct Obj_80195CF0 { u8 pad0[6]; u16 f6; u8 pad8[4]; Obj_80195CF0 *next; u8 pad10[4]; Obj_80195CF0 *child; };

struct Obj_80195DE0 { u8 pad0[6]; u16 f6; u8 pad8[4]; Obj_80195DE0 *next; u8 pad10[4]; Obj_80195DE0 *child; };

extern "C" {
u16 get_entity_id(void *);
extern s32 TObjQuestCol__class_name;
extern s32 TObjQuestColA__class_name;
extern s32 obj_quest_col_alock_class_name;
extern s32 obj_quest_col_apc_class_name;
extern s32 TObjQuestColApcIN__name;
extern s32 TObjQuestColApcINW__name;
extern u32 quest_collision_task_root;
Obj_80195CF0 *find_by_id__13TQuestColCtrlFUs(u16 arg0);
s32 TQuestColCtrl__ct(s32, s32);
u32 __ct__7TObjectFP7TObject(s32, s32);
u32 __nw__7TObjectFUl(s32);

extern s32 tl_05;

Obj_80195CF0 *find_by_id__13TQuestColCtrlFUs(u16 arg0) {
    Obj_80195CF0 *next;
    Obj_80195CF0 *cur;
    next = (*(Obj_80195CF0 * *)&quest_collision_task_root)->child;
    while ((*(Obj_80195CF0 * *)&quest_collision_task_root)->child != 0 && next != 0) {
        cur = next;
        next = cur->next;
        if ((((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestCol__class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestColA__class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(obj_quest_col_alock_class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(obj_quest_col_apc_class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestColApcIN__name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestColApcINW__name) != 0)
            && arg0 == get_entity_id(cur)) {
            return cur;
        }
    }
    return 0;
}

void TQuestColCtrl::delete_by_param(s32 arg0) {
    Obj_80195DE0 *next;
    Obj_80195DE0 *cur;
    if (arg0 < 0) {
        return;
    }
    next = (*(Obj_80195DE0 * *)&quest_collision_task_root)->child;
    while ((*(Obj_80195DE0 * *)&quest_collision_task_root)->child != 0 && next != 0) {
        cur = next;
        next = cur->next;
        if ((((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestCol__class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestColA__class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(obj_quest_col_alock_class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(obj_quest_col_apc_class_name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestColApcIN__name) != 0
             || ((TUnk_804B6C24 *)cur)->check_value_equals(TObjQuestColApcINW__name) != 0)
            && cur->f6 == arg0) {
            ((TObject *)cur)->queue_destruction();
            return;
        }
    }
}

void TQuestColCtrl::init() {
    u32 var_r3;

    var_r3 = __nw__7TObjectFUl(0x1C);
    if (var_r3 != 0U) {
        var_r3 = __ct__7TObjectFP7TObject(var_r3, 0);
    }
    quest_collision_task_root = var_r3;
    var_r3 = __nw__7TObjectFUl(0x1C);
    if (var_r3 != 0U) {
        TQuestColCtrl__ct(var_r3, tl_05);
    }
}

}
