#include "types.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TObject.h"

extern "C" {

void * TObjNpcAHM01__create(void *set_data);
}

void mem_free(void *allocation) {
    if (allocation != NULL) {
        xfree(allocation);
    }
}
void *mem_alloc(u32 bytes) { return xmalloc(bytes); }

extern void *tl_04;

void *TObjNpcAHM01__create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjNpcAHM01(control, set_data);
}
