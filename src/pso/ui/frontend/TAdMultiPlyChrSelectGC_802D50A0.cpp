#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"

extern "C" {
void copy_vec2__FPvPv(void *);
s32 TAdChrSelASlotGC::get_state() { return state; }
void TAdChrSelASlotGC::set_state(s32 value) { state = value; }
void TAdMultiPlyChrSelectGC::set_field_100(s32 v) { *(s32*)((char*)this + 0x100) = v; }

void fn_802D50B8(void *arg0, void *arg1, void *arg2, void *arg3) {
    copy_vec2__FPvPv((void *)((char *)arg0 + 132));
    ((void (*)(void *, void *))copy_vec2__FPvPv)((void *)((char *)arg0 + 140), arg2);
    ((void (*)(void *, void *))copy_vec2__FPvPv)((void *)((char *)arg0 + 148), arg3);
}

}
