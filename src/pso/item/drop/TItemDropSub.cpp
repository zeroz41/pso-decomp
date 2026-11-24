#include "pso/item/drop/TItemDropSub_80107BF0.h"
#include "pso/item/drop/TItemDropSub.h"
#include "types.h"

#pragma readonly_strings on

extern void * TItemDropSub__instance;

TItemDropSub::~TItemDropSub() {
    TItemDropSub__instance = 0;
}


const char *TItemDropSub__class_name = "TItemDropSub";

#define item_drop_sub ((u8 *)this)
TItemDropSub::TItemDropSub(TObject *parent) : TObject(parent) {
    ((TItemDropSub *)item_drop_sub)->m_name = TItemDropSub__class_name;
    TItemDropSub__instance = item_drop_sub;
    *(u32 *)((s8 *)item_drop_sub + 0x1C) = 10;
}
#undef item_drop_sub
