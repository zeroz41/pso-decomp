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
u8 *__dt__12TAdDialingGCFv(u8 *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = __vt__12TAdDialingGC;
        TAdDialingGC__instance = 0;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) object);
        }
    }
    return object;
}

#pragma readonly_strings on
const char *TAdDialingGC__name = "TAdDialingGC";

extern const char *TAdDialingGC__name;

}
TAdDialingGC::TAdDialingGC(TObject *parent) : TObject(parent) {
    *(s32 *)((s8 *)this + 0) = (s32) ((s32)TAdDialingGC__name);
    TAdDialingGC__instance = this;
    if (TLobby::is_state_active() != 0) {
        this->m_1c = 1;
    } else if (TLobby__sub_8014618C() == 1) {
        this->m_1c = 2;
    } else {
        this->m_1c = 0;
    }
    this->m_20 = 0;
    this->m_24 = 0;
    this->m_28 = 0;
    this->m_30 = 0;
    this->m_68 = 0;
    this->m_a0 = 0;
    this->m_a4 = 0;
}
