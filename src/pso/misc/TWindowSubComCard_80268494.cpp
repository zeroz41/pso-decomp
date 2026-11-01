#include "types.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

void set_string__20TWindowSubStatusDispFUl(u8 *, void *);
struct Ent_802684BC { u8 p0[0x1C]; s32 f1C; };
struct Win_802684BC { u8 p0[0x76]; s16 f76; };
s32 is_flag_4_set__17TWindowSubComCardFv(void *);
s32 get_array_entry__11TWindowBaseFi(void * a0 = 0, s16 a1 = 0);
s32 get_entry_id__17TWindowSubComCardFv();

void TWindowSubComCard::update_selected_entry() {
    get_array_entry__11TWindowBaseFi(this, *(s16 *)((s8 *)this + 0x74));
    get_entry_id__17TWindowSubComCardFv();
}

s32 TWindowSubComCard::find_entry_value_by_id(s32 arg1) {
    s32 i;
    Ent_802684BC *e;
    for (i = 0; i < ((Win_802684BC *)this)->f76; i++) {
        e = ((Ent_802684BC *(*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
        if (e != NULL && is_flag_4_set__17TWindowSubComCardFv(e) != 0 && arg1 == ((s32 (*)(void *))get_entry_id__17TWindowSubComCardFv)(e)) {
            return e->f1C;
        }
    }
    return 0;
}
void TWindowSubComCard::mark_entry_by_id(s32 arg1) {
    s32 i;
    u8 *e;
    for (i = 0; i < *(s16 *)(((u8 *)this) + 0x76); i++) {
        e = ((u8 *(*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
        if (e != 0 && ((s32 (*)(void))is_flag_4_set__17TWindowSubComCardFv)() != 0 && arg1 == ((s32 (*)(u8 *))get_entry_id__17TWindowSubComCardFv)(e)) {
            *(u16 *)e |= 1;
            *(s32 *)(e + 0x24) = -1;
        }
    }
}
void TWindowSubComCard::disable_entry_by_id(s32 arg1) {
    s32 i;
    u8 *e;
    for (i = 0; i < *(s16 *)(((u8 *)this) + 0x76); i++) {
        e = ((u8 *(*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
        if (e != 0 && ((s32 (*)(void))is_flag_4_set__17TWindowSubComCardFv)() != 0 && arg1 == ((s32 (*)(u8 *))get_entry_id__17TWindowSubComCardFv)(e)) {
            *(u16 *)e &= 0xFFFE;
            *(s32 *)(e + 0x24) = 0xFF909090;
        }
    }
}
void TWindowMakeTeam::set_entry_string_by_id(void *arg1, s32 arg2) {
    s32 i;
    u8 *e;
    for (i = 0; i < *(s16 *)(((u8 *)this) + 0x76); i++) {
        e = ((u8 *(*)(void *, s32))get_array_entry__11TWindowBaseFi)(this, i);
        if (e != 0 && ((s32 (*)(void))is_flag_4_set__17TWindowSubComCardFv)() != 0 && arg2 == ((s32 (*)(u8 *))get_entry_id__17TWindowSubComCardFv)(e)) {
            set_string__20TWindowSubStatusDispFUl(e, arg1);
        }
    }
}

void TWindowSubComCard::update_next_entry(s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_r4;

    temp_r4 = *(s16 *)((s8 *)this + 0x72);
    if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry__11TWindowBaseFi(this, temp_r4)))->set_text(arg1, arg2, arg3);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}

}
