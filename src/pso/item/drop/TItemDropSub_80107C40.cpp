#include "types.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/system/task/TObject.h"

extern "C" {

s32 TItemDropSub__ct(void *, s32);

extern void *TItemDropSub__instance;
extern s32 tl_05;

void TItemDropSub::create_instance(s32 arg0) {
    void *obj;
    if (TItemDropSub__instance == NULL) {
        obj = TObject::operator new(0x20);
        if (obj != NULL) {
            TItemDropSub__ct(obj, tl_05);
        }
    }
    if (TItemDropSub__instance != NULL) {
        *(s32 *)((s8 *)TItemDropSub__instance + 0x1C) = arg0;
    }
}

}
