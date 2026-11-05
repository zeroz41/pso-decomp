#include "pso/item/TItemDropSub_80107BF0.h"
#include "pso/TItemDropSub.h"
#include "types.h"

extern void * TItemDropSub__instance;

TItemDropSub::~TItemDropSub() {
    TItemDropSub__instance = 0;
}

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__12TItemDropSub[];
extern void *TItemDropSub__class_name;

void *TItemDropSub__ct(void *item_drop_sub) {
    __ct__7TObjectFP7TObject(item_drop_sub);
    *(s32 **)((s8 *)item_drop_sub + 0x18) = __vt__12TItemDropSub;
    *(void * *)&((TItemDropSub *)item_drop_sub)->m_name = TItemDropSub__class_name;
    TItemDropSub__instance = item_drop_sub;
    *(u32 *)((s8 *)item_drop_sub + 0x1C) = 10;
    return item_drop_sub;
}

}
