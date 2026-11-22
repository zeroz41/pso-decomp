#include "pso/ui/window/TWindowCost.h"

#pragma readonly_strings on

const char *TWindowCost__class_name = "TWindowCost";

TWindowCost::~TWindowCost() {}

TWindowCost::TWindowCost(void *position, s32 client, s32 text)
    : TWindowMeseta(position, client, text) {
    m_name = TWindowCost__class_name;
    set_cost(0);
}
