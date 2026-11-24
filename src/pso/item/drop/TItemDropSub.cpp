#include "types.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

TItemDropSub *TItemDropSub::instance;

s32 TItemDropSub::get_box_drop_area() {
    if (instance != NULL) {
        return instance->box_drop_area;
    }
    return 10;
}

TItemDropSub::~TItemDropSub() {
    instance = NULL;
}

const char *item_drop_sub_class_name = "TItemDropSub";

TItemDropSub::TItemDropSub(TObject *parent) : TObject(parent) {
    m_name = item_drop_sub_class_name;
    instance = this;
    box_drop_area = 10;
}

void TItemDropSub::create_instance(s32 area) {
    if (instance == NULL) {
        new TItemDropSub(tl_05);
    }
    if (instance != NULL) {
        instance->box_drop_area = area;
    }
}
