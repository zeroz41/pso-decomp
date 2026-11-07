#include "types.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/TLobby.h"

extern "C" {
extern s32 __vt__12TAdDialingGC[];
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern TAdDialingGC *TAdDialingGC__instance;
u8 *__dt__12TAdDialingGCFv(u8 *arg0, s16 arg1);
int TAdDialingGC__sub_80328B20(void*);

void TAdDialingGC::render() { TAdDialingGC__sub_80328B20(this); render_if_flag_set(); draw_if_flag_set(); update(); }

s32 update_dial_state__12TAdDialingGCFv();
s32 update_state__12TAdDialingGCFv();
s32 update_dial_state__12TAdDialingGCFl();

void TAdDialingGC::run_task() {

    switch (this->m_1c) {
    case 0:
        update_dial_state__12TAdDialingGCFl();
        break;
    case 1:
        update_state__12TAdDialingGCFv();
        break;
    case 2:
        update_dial_state__12TAdDialingGCFv();
        break;
    }
    update_selection();
    this->m_24 = (this->m_24 + 1);
}
u8 *__dt__12TAdDialingGCFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TAdDialingGC;
        TAdDialingGC__instance = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}

#pragma readonly_strings on

extern "C" {
const char *TAdDialingGC__name = "TAdDialingGC";
}

extern "C" {

s32 __ct__7TObjectFP7TObject();

extern const char *TAdDialingGC__name;

void *TAdDialingGC__ct(TAdDialingGC *ad_dialing_gc, TObject *parent) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)ad_dialing_gc + 0x18) = __vt__12TAdDialingGC;
    *(s32 *)((s8 *)ad_dialing_gc + 0) = (s32) ((s32)TAdDialingGC__name);
    TAdDialingGC__instance = ad_dialing_gc;
    if (TLobby::is_state_active() != 0) {
        ad_dialing_gc->m_1c = 1;
    } else if (TLobby__sub_8014618C() == 1) {
        ad_dialing_gc->m_1c = 2;
    } else {
        ad_dialing_gc->m_1c = 0;
    }
    ad_dialing_gc->m_20 = 0;
    ad_dialing_gc->m_24 = 0;
    ad_dialing_gc->m_28 = 0;
    ad_dialing_gc->m_30 = 0;
    ad_dialing_gc->m_68 = 0;
    ad_dialing_gc->m_a0 = 0;
    ad_dialing_gc->m_a4 = 0;
    return ad_dialing_gc;
}

}
