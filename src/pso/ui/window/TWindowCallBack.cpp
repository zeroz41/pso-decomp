#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/WindowLayoutRecord.h"

#pragma readonly_strings on

WindowDescriptor window_callback_base_params = {
    {0.0f, 0.0f}, 50045.0f, NULL, 0x23,
};

extern "C" {
void set_field_60__15TWindowCallBackFPvi(void* p, s32 v);
extern s32 __vt__15TWindowCallBack[];
const char *lbl_805D3E58 = "TWindowCallBack";
u8 *TWindowCallBack__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
void fn_802ACD40(void* p);
void fn_802ACD60(void* p);
void run_task__15TWindowCallBackFv(void* p);

s32 TBoss6Type2::get_state() { return this->m_374; }
s32 TBoss6GravBall::get_state() { return *(s32*)((char*)this + 0x374); }
void TBoss6Type2::update_and_send() { handle_olga_action(); send_subcommand((u8 *)this); }
void TBoss6Type2::handle_olga_action() { ((G_ClientIDHeader *)this)->bswap(); }
void TBoss6Type2::init_packet() { *(u8*)((char*)this + 0x0) = 165; *(u8*)((char*)this + 0x1) = 5; }
void fn_802ACD40(void* p) { ((G_ClientIDHeader *)p)->bswap(); }
void fn_802ACD60(void* p) { fn_802ACD40(p); send_subcommand((u8 *)p); }
}
void build_6xA3_olga_flow_boss_actions(void* p);
void build_6xA3_olga_flow_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 163; *(u8*)((char*)p + 0x1) = 5; }
void set_field_60__15TWindowCallBackFPvi(void* p, s32 v) { *(s32*)((char*)p + 0x60) = v; }

void TWindowCallBack::render() {
    s32 r = TWindowDD::draw_default_entry((s32)this);
    if (callback != NULL) {
        callback(this, r);
    }
}

void run_task__15TWindowCallBackFv(void* p) { ((TWindowDD *)p)->initialize_subwindow(); ((TWindowBase *)p)->update_fade(); }

TWindowCallBack::~TWindowCallBack() {}
u8 *TWindowCallBack__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    __ct__11TWindowBaseFPUcsPUc(arg0, (u8 *)((s32) &window_callback_base_params), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowCallBack;
    *(const char **)((s8 *)arg0 + 0) = lbl_805D3E58;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x38))->copy_vec2(arg2);
    ((TWindowBase *)arg0)->save_position();
    set_field_60__15TWindowCallBackFPvi(arg0, arg3);
    return arg0;
}
