#include "types.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/object/quest/TObjQuestCol2_80196E68.h"

#include "pso/system/task/TObject.h"

struct Obj_8019601C { u8 pad[0x6]; u16 id; };

struct Base_80195F50 { u8 pad[0x18]; };

struct Obj_80195F50 : Base_80195F50 { virtual ~Obj_80195F50(); };

extern "C" {
extern u32 quest_collision_task_root;
void *__nw__7TObjectFUl(int);
void *TObjQuestColApcINW__ct(void *self, void *parent, void *arg);
Obj_8019601C *create_quest_col_apc_inw__6TLobbyFPvPv(void *arg, s32 *out_id);
extern s32 __vt__13TQuestColCtrl[];
void *TQuestColCtrl__ct(void *arg0);
void __ct__7TObjectFP7TObject(void *);

void TQuestColCtrl::render() {  }

extern void *TQuestColCtrl__name;

void TQuestColCtrl::run_task() {
    TQuestColCtrl__sub_80196EC0();
    if ((u32) quest_collision_task_root != 0U) {
        ((TObject *)quest_collision_task_root)->run_tasks();
    }
}

}
TQuestColCtrl::~TQuestColCtrl() {
    if (quest_collision_task_root != 0U) {
        delete (Obj_80195F50 *)quest_collision_task_root;
        quest_collision_task_root = 0;
    }
}


void *TQuestColCtrl__ct(void *quest_col_ctrl) {
    __ct__7TObjectFP7TObject(quest_col_ctrl);
    *(s32 **)((s8 *)quest_col_ctrl + 0x18) = __vt__13TQuestColCtrl;
    *(void * *)&((TQuestColCtrl *)quest_col_ctrl)->m_name = TQuestColCtrl__name;
    return quest_col_ctrl;
}
Obj_8019601C *create_quest_col_apc_inw__6TLobbyFPvPv(void *arg, s32 *out_id) {
    Obj_8019601C *o = (Obj_8019601C *)__nw__7TObjectFUl(0xcc);
    if (o != 0) {
        o = (Obj_8019601C *)TObjQuestColApcINW__ct(o, (void *)quest_collision_task_root, arg);
    }
    if (o != 0) {
        *out_id = o->id;
        return o;
    } else {
        *out_id = -1;
        return 0;
    }
}

