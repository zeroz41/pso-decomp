#include "types.h"
#include "pso/object/quest/TObjQuestColA.h"

extern "C" {
void *__nw__7TObjectFUl(int);
void *TObjQuestColA__ct(void *self, void *parent, void *arg);
extern void *quest_collision_task_root;
TObjQuestColA *fn_80196814(void *arg, s32 *out_id);

TObjQuestColA *fn_80196814(void *arg, s32 *out_id) {
    TObjQuestColA *o = (TObjQuestColA *)__nw__7TObjectFUl(sizeof(TObjQuestColA));
    if (o != NULL) {
        o = (TObjQuestColA *)TObjQuestColA__ct(o, quest_collision_task_root, arg);
    }
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}
}
