#include "types.h"
#include "pso/item/drop/TItemDropSub_80107B74.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

void *TItemDropSub__instance;

s32 TItemDropSub__sub_80107B74(void) {
    if ((void *) TItemDropSub__instance != NULL) {
        return *(s32 *)((s8 *)TItemDropSub__instance + 0x1C);
    }
    return 0xA;
}

TItemDropSub::~TItemDropSub() {
    TItemDropSub__instance = 0;
}

const char *TItemDropSub__class_name = "TItemDropSub";

TItemDropSub::TItemDropSub(TObject *parent) : TObject(parent) {
    m_name = TItemDropSub__class_name;
    TItemDropSub__instance = this;
    m_1c = 10;
}

void TItemDropSub::create_instance(s32 arg0) {
    if (TItemDropSub__instance == NULL) {
        new TItemDropSub(tl_05);
    }
    if (TItemDropSub__instance != NULL) {
        *(s32 *)((s8 *)TItemDropSub__instance + 0x1C) = arg0;
    }
}
