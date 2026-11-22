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

extern "C" {
const char *lbl_805D4200 = "TAdExNetConfirmGC";

void TAdExNetConfirmGC::render() {
    vfunc_9();
}

saddr TAdExNetConfirmGC::vfunc_7() {
    if (TAdExNetConfirmGC::is_confirmed() != 0) {
        return get_localized_text_entry(0x22, 1);
    }
    return get_localized_text_entry(0x22, 0);
}

void TAdExNetConfirmGC::vfunc_6() { TAdMultiChgGameModeGC::request_scene_change(); }

void TAdExNetConfirmGC::run_task() {
    vfunc_8();
}

}
TAdExNetConfirmGC::~TAdExNetConfirmGC() {

}

TAdExNetConfirmGC::TAdExNetConfirmGC(TObject *parent) : TAdWarningBaseGC(parent) {
    m_name = lbl_805D4200;
    if ((TLobby__sub_80145DB4(1) != 0) || (TLobby__sub_80145DB4(4) != 0)) {
        if (load_network_info() != 0) {
            TLobby::init_account_entries();
        } else {
            request_main_phase(0x13);
        }
        queue_destruction();
        TAdMultiChgGameModeGC::set_game_mode();
        return;
    }
}

