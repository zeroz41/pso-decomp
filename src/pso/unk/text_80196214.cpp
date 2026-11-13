#include "types.h"
#include "pso/system/task/TObject.h"

extern "C" {
void *__nw__7TObjectFUl(int);
void *TObjQuestColApcIN__ct(void *self, void *parent, void *arg);
extern void *quest_collision_task_root;
TObject *fn_80196214(void *arg, s32 *out_id);

TObject *fn_80196214(void *arg, s32 *out_id) {
    TObject *o = (TObject *)__nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = (TObject *)TObjQuestColApcIN__ct(o, quest_collision_task_root, arg);
    }
    if (o != NULL) {
        *out_id = o->m_id;
    } else {
        *out_id = -1;
    }
    return o;
}
}
