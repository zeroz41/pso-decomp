#include "types.h"
#include "pso/npc/TObjNpcAHM01.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {

void * TObjNpcAHM01__create(void *arg0);
void *__ct__11TObjControlFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);
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

extern void *tl_04;

void * TObjNpcAHM01__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcAHM01__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}
