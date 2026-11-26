#include "pso/ui/frontend/TAdTitleGC.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSnAkPassConfirmGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

const char *lbl_805D41F0 = "TAdSnAkPassConfirmGC";
// Serial info window position, then the message window position and size given to init_parts.
static const NJS_POINT2 sn_ak_pass_confirm_info_window_pos = {85.0f, 131.0f};
static const NJS_POINT2 sn_ak_pass_confirm_message_pos = {44.0f, 231.0f};
static const NJS_POINT2 sn_ak_pass_confirm_message_size = {552.0f, 140.0f};

void TAdSnAkPassConfirmGC::render() {
    render_dialog();
}

saddr TAdSnAkPassConfirmGC::get_message_text() { return get_localized_text_entry(39, 0); }
void TAdSnAkPassConfirmGC::on_no_chosen() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::on_yes_chosen() { if (this->m_48 != 0) { ((TWindowBase *)this->m_48)->close(); this->m_48 = 0; } }
void TAdSnAkPassConfirmGC::on_cancel() { TAdMultiChgGameModeGC::open_lic_agreement_scene(); }
void TAdSnAkPassConfirmGC::on_accept() { TAdMultiChgGameModeGC::open_pso_pass_save_scene(); }

void TAdSnAkPassConfirmGC::run_task() {
    run_dialog();
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

void TAdYesNoBaseGC::render_dialog() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

