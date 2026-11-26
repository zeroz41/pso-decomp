#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdExNetConfirmGC.h"
#include "pso/network/NetworkConnect.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/network/NetworkSettings.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

const char *TAdExNetConfirmGC_class_name = "TAdExNetConfirmGC";

void TAdExNetConfirmGC::render() {
    render_dialog();
}

saddr TAdExNetConfirmGC::get_message_text() {
    if (is_confirmed() != 0) {
        return get_localized_text_entry(0x22, 1);
    }
    return get_localized_text_entry(0x22, 0);
}

void TAdExNetConfirmGC::on_close() { TAdMultiChgGameModeGC::open_time_set_scene(); }

void TAdExNetConfirmGC::run_task() {
    update_state();
}

TAdExNetConfirmGC::~TAdExNetConfirmGC() {

}

TAdExNetConfirmGC::TAdExNetConfirmGC(TObject *parent) : TAdWarningBaseGC(parent) {
    m_name = TAdExNetConfirmGC_class_name;
    if ((adapter_supports_connection(1) != 0) || (adapter_supports_connection(4) != 0)) {
        if (load_network_info() != 0) {
            init_account_entries();
        } else {
            request_main_phase(0x13);
        }
        queue_destruction();
        TAdMultiChgGameModeGC::open_single_ply_chr_select_scene();
        return;
    }
}

