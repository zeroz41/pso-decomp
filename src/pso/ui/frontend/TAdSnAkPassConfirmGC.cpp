#include "pso/ui/frontend/TAdTitleGC.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSnAkPassConfirmGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

extern "C" {
const char *lbl_805D41F0 = "TAdSnAkPassConfirmGC";
// Serial info window position, then the message window position and size given to init_parts.
static const NJS_POINT2 sn_ak_pass_confirm_info_window_pos = {85.0f, 131.0f};
static const NJS_POINT2 sn_ak_pass_confirm_message_pos = {44.0f, 231.0f};
static const NJS_POINT2 sn_ak_pass_confirm_message_size = {552.0f, 140.0f};

void TAdSnAkPassConfirmGC::render() {
    vfunc_12();
}

saddr TAdSnAkPassConfirmGC::vfunc_10() { return get_localized_text_entry(39, 0); }
void TAdSnAkPassConfirmGC::vfunc_9() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::vfunc_8() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::vfunc_7() { TAdMultiChgGameModeGC::request_transition(); }
void TAdSnAkPassConfirmGC::vfunc_6() { ((TAdMultiChgGameModeGC *)this)->set_state_0x1a(); }

void TAdSnAkPassConfirmGC::run_task() {
    vfunc_11();
}

TAdSnAkPassConfirmGC::~TAdSnAkPassConfirmGC() {
    if (m_48 != 0) {
        ((TObject *)m_48)->queue_destruction();
        m_48 = 0;
    }
}

TAdSnAkPassConfirmGC::TAdSnAkPassConfirmGC(TObject *parent) : TAdYesNoBaseGC(parent) {
    m_name = lbl_805D41F0;
    new TAdTitleGC(this, 0x11);
    m_48 = TWindowOptionCtrl::create_serial_info_window(&sn_ak_pass_confirm_info_window_pos, 0);
    init_parts((void *)&sn_ak_pass_confirm_message_pos, (void *)&sn_ak_pass_confirm_message_size);
}

void TAdYesNoBaseGC::vfunc_12() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

}
