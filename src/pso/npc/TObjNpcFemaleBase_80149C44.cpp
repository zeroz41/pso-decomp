#include "types.h"
#include "pso/npc/TObjNpcFemaleBase_80149C44.h"
#include "pso/npc/TObjNpcFemaleBase.h"

void TObjNpcFemaleBase::request_action(s32 arg1) {
    if (arg1 != 1) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

extern u32 lbl_805D5758;

void TObjNpcFemaleBase__sub_80149C64(void) {
    if ((u32) lbl_805D5758 != 0U) {
        lbl_805D5758 = 0U;
    }
}
