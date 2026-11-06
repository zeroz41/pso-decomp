#include "types.h"
#include "pso/npc/TObjNpcGovernorBase.h"
#include "pso/npc/TObjNpcGovernorBase_8014AB24.h"

extern "C" {

void *__ct__11TObjControlFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);

extern void *tl_04;

void * TObjNpcGovernorBase__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcGovernorBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
