#include "types.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


extern void *TItemDropSub__instance;

void TItemDropSub::create_instance(s32 arg0) {
    if (TItemDropSub__instance == NULL) {
        new TItemDropSub(tl_05);
    }
    if (TItemDropSub__instance != NULL) {
        *(s32 *)((s8 *)TItemDropSub__instance + 0x1C) = arg0;
    }
}
