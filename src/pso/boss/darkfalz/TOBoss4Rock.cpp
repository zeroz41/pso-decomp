#include "types.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TObject.h"

extern "C" {
void mem_free(void *p);
void *mem_alloc(u32 size);
}

void xfree(void *p);
void *xmalloc(u32 size);

void mem_free(void *p) {
    if (p != NULL) {
        xfree(p);
    }
}
void *mem_alloc(u32 size) { return xmalloc(size); }

