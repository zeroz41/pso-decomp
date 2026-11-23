#include "pso/network/protocol/protocol_types.h"
#include "pso/boss/olgaflow/OlgaFlowActions.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/vector.h"

#pragma readonly_strings on

WindowDescriptor window_callback_base_params = {
    {0.0f, 0.0f}, 50045.0f, NULL, 0x23,
};

extern "C" {
const char *TWindowCallBack__name = "TWindowCallBack";

s32 TBoss6Type2::get_state() { return this->action_state; }
s32 TBoss6Type1::get_gravity_attack_state() { return action_state; }
void OlgaFlowType2ActionMsg::send() { swap_entity_id(); send_subcommand(this); }
void OlgaFlowType2ActionMsg::swap_entity_id() { header.bswap(); }
void OlgaFlowType2ActionMsg::initialize() {
    header.subcommand = 0xA5;
    header.size = 5;
}
void OlgaFlowPlotActionMsg::swap_entity_id() { header.bswap(); }
void OlgaFlowPlotActionMsg::send() { swap_entity_id(); send_subcommand(this); }
}
void OlgaFlowPlotActionMsg::initialize() {
    header.subcommand = 0xA3;
    header.size = 5;
}
void TWindowCallBack::set_field_60(WindowCallback callback_function) { callback = callback_function; }

void TWindowCallBack::render() {
    WindowDrawContext *context = draw_default_entry();
    if (callback != NULL) {
        callback(this, context);
    }
}

void TWindowCallBack::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_fade(); }

TWindowCallBack::~TWindowCallBack() {}
TWindowCallBack::TWindowCallBack(u8 *position, u8 *scale, WindowCallback callback_function)
    : TWindowBase((u8 *)&window_callback_base_params, 4, position) {
    m_name = TWindowCallBack__name;
    copy_vec2(target_size, scale);
    save_position();
    set_field_60(callback_function);
}
