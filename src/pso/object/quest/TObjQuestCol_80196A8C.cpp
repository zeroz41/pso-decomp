#include "types.h"
#include "pso/object/quest/TObjQuestCol_80196A8C.h"

extern "C" {

void *TObjQuestCol__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);

extern void *quest_collision_task_root;

void *TObjQuestCol__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjQuestCol__ct(o, quest_collision_task_root, arg0);
    }
    return o;
}

}
