#include "types.h"
#include "pso/ui/window/TWindowCost.h"

#pragma readonly_strings on


TWindowCost::~TWindowCost() {

}


const char *TWindowCost__class_name = "TWindowCost";

TWindowCost::TWindowCost(s32 arg1, s32 arg2, s32 str) : TWindowMeseta(arg1, arg2, str) {
    this->m_name = TWindowCost__class_name;
    set_cost(0);
}
