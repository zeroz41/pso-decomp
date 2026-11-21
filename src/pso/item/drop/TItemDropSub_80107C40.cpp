#include "types.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/system/task/TObject.h"

extern "C" {

extern void *TItemDropSub__instance;
extern s32 tl_05;

void TItemDropSub::create_instance(s32 arg0) {
    if (TItemDropSub__instance == NULL) {
        new TItemDropSub((TObject *)tl_05);
    }
    if (TItemDropSub__instance != NULL) {
        *(s32 *)((s8 *)TItemDropSub__instance + 0x1C) = arg0;
    }
}

}
