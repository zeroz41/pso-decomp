#include "types.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TSaveChCr_80339B64.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TSaveChCr.h"

extern "C" {
int close_and_advance__9TSaveChCrFPv(void*, int);
int close_window__9TSaveChCrFv(void*);
extern s32 lbl_804C88C0[];
extern s32 pso_system_card_filename[];
extern s32 lbl_804C89BC[];
int TSaveChCr__sub_80339F30(void*);
s32 TSaveChCr__sub_8033A138(void *);
s32 poll_memcard_status__9TSaveChCrFv();
s32 save_character__9TSaveChCrFv(void *);

void TSaveChCr::destroy_if_keyboard_idle() { if (this->timer == 0) { queue_destruction__7TObjectFv(this); request_queued_main_phase(); } }
void TSaveChCr::sub_80339B94() { close_window(); }
void TSaveChCr::save_if_dirty() { if (TSaveChCr__sub_80339F30(this) != 0) { set_state((s32)((void*)4)); } }
void TSaveChCr::close_and_advance_to_3() { close_and_advance__9TSaveChCrFPv(this, 3); }
void TSaveChCr::update_save_status() {
    s32 var_r3;

    if ((s32) this->timer <= 0) {
        this->m_28 = 0;
        this->card_status = poll_memcard_status__9TSaveChCrFv();
        if ((s32) this->card_status != 0) {
            set_state((s32)((void*)(1)));
            return;
        }
        if ((s32) *(s32 *)((s8 *)this + 0x20) == 0) {
            var_r3 = save_character__9TSaveChCrFv(this);
        } else {
            var_r3 = TSaveChCr__sub_8033A138(this);
        }
        if (var_r3 == 7) {
            set_state((s32)((void*)(4)));
            return;
        }
        queue_destruction__7TObjectFv((this));
        TKeyBoardControl__sub_8000F9CC(9);
    }
}
void TSaveChCr::close_and_advance_step2() { close_and_advance__9TSaveChCrFPv(this, 2); }
void TSaveChCr::sub_80339CE4() {}
void TSaveChCr::save_1() { close_and_advance__9TSaveChCrFPv(this, 1); }
void TSaveChCr::update_save_state() {
    s32 temp_r4;

    temp_r4 = this->card_status;
    if (!(temp_r4 & 2)) {
        if (temp_r4 & 1) {
            if ((u32) this->owned_window == 0U) {
                close_and_advance__9TSaveChCrFPv(this, 0);
            }
        } else {
            if (temp_r4 & 4) {
                set_state((s32)((void*)(1)));
                return;
            }
            if (temp_r4 == 0) {
                set_state((s32)((void*)(2)));
            }
        }
    }
}
void TSaveChCr::fn_80339D78() {
    close_window();
    if (card_status & 1) {
        close_and_advance__9TSaveChCrFPv(this, 0);
    }
}
s32 TAdSinglePlyChrSelectGC__sub_80339DBC(void) {
    if ((TAdPlayerLoadGC::find_card_file(0, (const char *)(pso_system_card_filename)) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)(lbl_804C88C0)) != 0) || (TAdPlayerLoadGC::find_card_file(0, (const char *)(lbl_804C89BC)) != 0)) {
        return 0;
    }
    return 1;
}

}
