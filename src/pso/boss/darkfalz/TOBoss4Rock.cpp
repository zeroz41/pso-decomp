#include "types.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TObject.h"
#include "pso/system/memory.h"

void operator delete[](void *allocation) {
    if (allocation != NULL) {
        xfree(allocation);
    }
}

void *operator new[](size_t size) { return xmalloc(size); }

