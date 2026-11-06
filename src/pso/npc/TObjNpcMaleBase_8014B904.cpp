#include "types.h"
#include "pso/npc/TObjNpcMaleBase_8014B904.h"

extern "C" {

void *__ct__11TObjControlFP7TObject(void *, void *);
u8 *TObjNpcMaleBase__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__nw__7TObjectFUl(int);

extern void *tl_04;

void * TObjNpcMaleBase__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcMaleBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
