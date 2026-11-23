#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdTrialAgreementGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_8033573C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/unk/TLobby_80335E08.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_80335958.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804EE470.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#pragma readonly_strings on

extern "C" {


void TAdTrialAgreementGC::render() {
    check_main_task_state();
}

void TAdTrialAgreementGC::vfunc_8() { request_main_phase((saddr)((void*)0)); }
void TAdTrialAgreementGC::vfunc_7() { TAdMultiChgGameModeGC::request_scene_change(); }
void TAdTrialAgreementGC::vfunc_6() { if (scroll_window != NULL) { scroll_window->close_window(); scroll_window = NULL; } }
void TAdTrialAgreementGC::wait_for_load() {
loop_1:
    if ((TAdPlayerLoadGC::probe_card_slot(0) != 0) && (poll_memcard_result(0) != 0)) {
        render_tick();
        goto loop_1;
    }
}

}

extern "C" {

const char *TAdTrialAgreementGC__name = "TAdTrialAgreementGC";


s32 TAdTrialAgreementGC::check_card_file(saddr arg0) {
    s32 card_file;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        return 0;
    }
    ((TAdTrialAgreementGC *)arg0)->wait_for_load();
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        return 0;
    }
    ((TAdTrialAgreementGC *)arg0)->wait_for_load();
    card_file = TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename);
    if ((card_file == 0) || ((card_file + 0x10000) == 0xFF41U)) {
        return 1;
    }
    return 0;
}

void TAdTrialAgreementGC::run_task() {
    update_state();
}

}
TAdTrialAgreementGC::~TAdTrialAgreementGC() {

}

TAdTrialAgreementGC::TAdTrialAgreementGC(TObject *parent) : TAdAgreementBaseGC(parent) {
    m_name = TAdTrialAgreementGC__name;
    scroll_window = NULL;
    if (TAdTrialAgreementGC::check_card_file((saddr)this) != 0) {
        vfunc_7();
        queue_destruction();
        return;
    }
    scroll_window = new TAdScrollWinGC(this, 1, 0);
}
