#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdExNetConfirmGC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdExNetConfirmGC_8032C504.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/unk/text_80145A94.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct Base_8032C504 { char pad[0x18]; };
struct VObj_8032C504 : Base_8032C504 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
struct Base_8032C594_8032C504 { char pad[0x18]; };
struct VObj_8032C594_8032C504 : Base_8032C594_8032C504 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

extern "C" {
const char *lbl_805D4200 = "TAdExNetConfirmGC";

void TAdExNetConfirmGC::render() {
    struct VObj_8032C504 *o = (struct VObj_8032C504 *)this;
    o->m7();
}

void TAdExNetConfirmGC::vfunc_7() {
    if (TAdExNetConfirmGC::is_confirmed() != 0) {
        get_localized_text_entry(0x22, 1);
        return;
    }
    get_localized_text_entry(0x22, 0);
}

int TAdExNetConfirmGC::vfunc_6() { TAdMultiChgGameModeGC::request_scene_change(); }

void TAdExNetConfirmGC::run_task() {
    struct VObj_8032C594_8032C504 *o = (struct VObj_8032C594_8032C504 *)this;
    o->m6();
}

}
TAdExNetConfirmGC::~TAdExNetConfirmGC() {

}

TAdExNetConfirmGC::TAdExNetConfirmGC(TObject *parent) : TAdWarningBaseGC(parent) {
    m_name = lbl_805D4200;
    if ((TLobby__sub_80145DB4(1) != 0) || (TLobby__sub_80145DB4(4) != 0)) {
        if (TLobby__sub_80145A94() != 0) {
            TLobby::init_account_entries();
        } else {
            request_main_phase(0x13);
        }
        queue_destruction();
        TAdMultiChgGameModeGC::set_game_mode();
        return;
    }
}

