#include "pso/ui/window/TWindowCost.h"
#include "types.h"

void TWindowCost::set_cost(s32 cost) {
    set_value(cost);
}

void TWindowCost::run_task() {
    update_window();
    update_window_entry_list(&entry_list);
}

#pragma readonly_strings on

const char *TWindowCost::class_name = "TWindowCost";

TWindowCost::~TWindowCost() {}

TWindowCost::TWindowCost(void *position, s32 client, s32 text)
    : TWindowMeseta(position, client, text) {
    m_name = TWindowCost::class_name;
    set_cost(0);
}
