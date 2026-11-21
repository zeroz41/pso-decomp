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
void set_field_60__15TWindowCallBackFPvi(void* p, s32 v);
const char *lbl_805D3E58 = "TWindowCallBack";
void run_task__15TWindowCallBackFv(void* p);

s32 TBoss6Type2::get_state() { return this->m_374; }
s32 TBoss6Type1::get_gravity_attack_state() { return m_374; }
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
void set_field_60__15TWindowCallBackFPvi(void* p, s32 v) { *(s32*)((char*)p + 0x60) = v; }

void TWindowCallBack::render() {
    s32 r = TWindowDD::draw_default_entry((s32)this);
    if (callback != NULL) {
        callback(this, r);
    }
}

void run_task__15TWindowCallBackFv(void* p) { ((TWindowDD *)p)->initialize_subwindow(); ((TWindowBase *)p)->update_fade(); }

TWindowCallBack::~TWindowCallBack() {}
#define self ((u8 *)this)
TWindowCallBack::TWindowCallBack(s32 arg1, u8 *arg2, s32 arg3) : TWindowBase((u8 *)((s32) &window_callback_base_params), (s16)4, (u8 *)arg1) {
    m_name = lbl_805D3E58;
    copy_vec2((self + 0x38), arg2);
    ((TWindowBase *)self)->save_position();
    set_field_60__15TWindowCallBackFPvi(self, arg3);
}
#undef self
