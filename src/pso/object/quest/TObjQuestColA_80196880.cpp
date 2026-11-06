#include "types.h"
#include "pso/object/quest/TObjQuestColA_80196880.h"

extern "C" {

void *TObjQuestColA__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);

extern void *quest_collision_task_root;

void *TObjQuestColA__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjQuestColA__ct(o, quest_collision_task_root, arg0);
    }
    return o;
}

}
