#include "types.h"
#include "pso/misc/TWindowMessage.h"
class TChCrTagPlBack;
#include "pso/misc/TWindowSubTrade.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct VBase_18_f23ffb { char pad[0x18]; };

struct VObj_18_f23ffb : VBase_18_f23ffb {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

struct VBase_802B1B80 { char pad[0x18]; };

struct VObj_802B1B80 : VBase_802B1B80 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

extern "C" {
s32 get_shared_text_buffer();
void *get_player_by_client_id(s32 i);
s32 text_builder_append();
}
void text_builder_reset(void);
extern "C" {
s32 get_window_layout_position(int);
s32 free_member__17TWindowSubComCardFv(int, int);
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 arg2, s32 arg3, f32 farg0);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, int, int, int);
extern const f32 lbl_805DE298;
s32 create__14TWindowMessageFllUls(s32, void *, int, int);
extern u8 lbl_80470AA8[];
s32 TWindowSubTrade::open_trade_confirm_prompt(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r29;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(arg1));
    text_builder_reset();
    if (player != NULL) {
        ((VObj_18_f23ffb *)(player))->m10();
        text_builder_append();
    }
    TWindowSubStatusDisp::get_message_10(0xD6);
    text_builder_append();
    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(arg0, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(TWindowSubStatusDisp::get_message_10(0x20)), (s32)(get_shared_text_buffer()), (s32)(get_window_layout_position(0x5B)), (f32)((f32)lbl_805DE298));
    free_member__17TWindowSubComCardFv(temp_r29, 1);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}
s32 TWindowSubTrade::open_player_message_window(s32 arg1, s32 arg2) {
    s32 r;
    VObj_802B1B80 *p;
    p = (VObj_802B1B80 *)get_player_by_client_id(arg1);
    text_builder_reset();
    if (p != NULL) {
        ((s32 (*)(s32))text_builder_append)(p->m10());
    }
    ((s32 (*)(s32))text_builder_append)(arg2);
    r = create__14TWindowMessageFllUls(get_window_layout_position(0x5B), lbl_80470AA8, 1, this->m_20);
    ((TWindowMessage *)r)->append_line(get_shared_text_buffer(), 0x82);
    return r;
}
}
