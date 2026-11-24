#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"

extern "C" {
s32 TAdChrSelASlotGC::get_state() { return state; }
void TAdChrSelASlotGC::set_state(s32 value) { state = value; }

void TAdChrSelPlayerGC::set_field_100(s32 value) {
    pending_state = value;
}

void copy_vec2__FPvPv(NJS_POINT2 *target, const NJS_POINT2 *source);

void fn_802D50B8(TAdTitleTexGC *title, const NJS_POINT2 *first, const NJS_POINT2 *second, const NJS_POINT2 *third) {
    copy_vec2__FPvPv(&title->rest_pos[0], first);
    copy_vec2__FPvPv(&title->rest_pos[1], second);
    copy_vec2__FPvPv(&title->rest_pos[2], third);
}
}
