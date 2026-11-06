#include "types.h"
#include "pso/item/drop/TItemDropSub.h"

extern "C" {

s32 TItemDropSub__ct(void *, s32);
void *__nw__7TObjectFUl(u32);

extern void *TItemDropSub__instance;
extern s32 tl_05;

void TItemDropSub::create_instance(s32 arg0) {
    void *obj;
    if (TItemDropSub__instance == NULL) {
        obj = __nw__7TObjectFUl(0x20);
        if (obj != NULL) {
            TItemDropSub__ct(obj, tl_05);
        }
    }
    if (TItemDropSub__instance != NULL) {
        *(s32 *)((s8 *)TItemDropSub__instance + 0x1C) = arg0;
    }
}

}
