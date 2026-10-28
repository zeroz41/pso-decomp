#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/boss/TBoss6GravBall.h"
#include "pso/boss/TBoss6Type2.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct RecoveredGlobal_802ACE84_lbl_804DE360 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_802ACE84___vt__15TWindowCallBack {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
void set_field_60__15TWindowCallBackFPvi(void* p, s32 v);
extern RecoveredGlobal_802ACE84_lbl_804DE360 window_callback_base_params;
extern s32 __vt__15TWindowCallBack[];
extern s32 lbl_805D3E58;
u8 *TWindowCallBack__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
void *__dt__15TWindowCallBackFv(void *arg0, s16 arg1);
void fn_802ACD40(void* p);
void fn_802ACD60(void* p);
void run_task__15TWindowCallBackFv(void* p);
void __dl__7TObjectFPv(void *);

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

class TWindowCallBack {
public:
    u8 pad[0x60];
    void (*callback)(TWindowCallBack *, s32);
    void render();
};

void TWindowCallBack::render() {
    s32 r = TWindowDD::draw_default_entry((s32)this);
    if (callback != NULL) {
        callback(this, r);
    }
}

void run_task__15TWindowCallBackFv(void* p) { ((TWindowDD *)p)->initialize_subwindow(); ((TUnk_804CE018 *)p)->update_fade(); }

void *__dt__15TWindowCallBackFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowCallBack;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_802ACE84_lbl_804DE360_size[sizeof(RecoveredGlobal_802ACE84_lbl_804DE360) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_802ACE84___vt__15TWindowCallBack_size[sizeof(RecoveredGlobal_802ACE84___vt__15TWindowCallBack) == 0x1C ? 1 : -1];
u8 *TWindowCallBack__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TWindowDD *)arg0)->construct_base((u8 *)((s32) &window_callback_base_params.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802ACE84___vt__15TWindowCallBack *)&__vt__15TWindowCallBack).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3E58;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x38))->copy_vec2(arg2);
    ((TUnk_804CE018 *)arg0)->save_position();
    set_field_60__15TWindowCallBackFPvi(arg0, arg3);
    return arg0;
}
