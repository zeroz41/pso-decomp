#include "types.h"
#include "pso/object/quest/TObjQuestCol.h"

extern "C" {
void *__nw__7TObjectFUl(int);
void *TObjQuestCol__ct(void *self, void *parent, void *arg);
extern void *quest_collision_task_root;
TObjQuestCol *create_quest_col(void *arg, s32 *out_id);

TObjQuestCol *create_quest_col(void *arg, s32 *out_id) {
    TObjQuestCol *o = (TObjQuestCol *)__nw__7TObjectFUl(sizeof(TObjQuestCol));
    if (o != NULL) {
        o = (TObjQuestCol *)TObjQuestCol__ct(o, quest_collision_task_root, arg);
    }
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}
}
