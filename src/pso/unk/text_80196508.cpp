#include "types.h"
#include "pso/object/quest/TObjQuestColALock.h"

extern "C" {
void *__nw__7TObjectFUl(int);
void *TObjQuestColALock__ct(void *self, void *parent, void *arg);
extern void *quest_collision_task_root;
TObjQuestColALock *create_quest_col_alock(void *arg, s32 *out_id);

TObjQuestColALock *create_quest_col_alock(void *arg, s32 *out_id) {
    TObjQuestColALock *o = (TObjQuestColALock *)__nw__7TObjectFUl(sizeof(TObjQuestColALock));
    if (o != NULL) {
        o = (TObjQuestColALock *)TObjQuestColALock__ct(o, quest_collision_task_root, arg);
    }
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}
}
