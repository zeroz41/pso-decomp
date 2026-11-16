#include "types.h"
#include "pso/object/quest/TObjQuestCol_80196A8C.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TObjQuestCol__ct(void *, void *, void *);

extern void *quest_collision_task_root;

void *TObjQuestCol__create(void *arg0) {
    void *o = TObject::operator new(0xBC);
    if (o != NULL) {
        o = TObjQuestCol__ct(o, quest_collision_task_root, arg0);
    }
    return o;
}

}
