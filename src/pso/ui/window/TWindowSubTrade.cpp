// ---- pso/ui/window/TWindowSubTrade_802B1AB4
#include "types.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowMessage.h"
class TChCrTagPlBack;
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

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
s32 text_builder_append();
}
void text_builder_reset(void);
extern "C" {
s32 get_window_layout_position(int);
s32 free_member__17TWindowSubComCardFv(int, int);
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 arg2, s32 arg3, f32 farg0);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, int, int, int);
s32 create__14TWindowMessageFlPCfUll(s32, void *, int, int);
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
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(TWindowSubStatusDisp::get_message_10(0x20)), (s32)(get_shared_text_buffer()), (s32)(get_window_layout_position(0x5B)), 384.0f);
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
    r = create__14TWindowMessageFlPCfUll(get_window_layout_position(0x5B), lbl_80470AA8, 1, this->m_20);
    ((TWindowMessage *)r)->append_line(get_shared_text_buffer(), 0x82);
    return r;
}
}

// ---- pso/unk/text_802B1C1C
#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
TWindowSubComCardList *draw_card_icon__17TWindowSubComCardFll(s32 layout, s32 kind, void *title);
extern s32 local_client_id;
s32 draw_text_gray__17TWindowSubComCardFllll(void *list, void *text, int kind, int id);
s32 is_trade_range_bit_set(s32 client);
s32 is_script_controlled__10TObjPlayerFv(TObjPlayer *player);
s32 obj_isState3_324__9TObjCharaFv(TObjPlayer *player);
extern const f32 lbl_805DE29C;
extern const f32 lbl_805DE2A0;

// The caller passes its TWindowSubTrade in r3; the body never reads it.
TWindowSubComCardList *TWindowSubComCard__sub_802B1C1C(TWindowSubTrade *) {
    s32 i;
    TObjPlayer *player;
    TWindowSubComCardList *list;

    list = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x5A), 4, TWindowSubStatusDisp::get_message_10(0x1F));
    for (i = 0; i < 4; i++) {
        if (i == local_client_id) {
            continue;
        }
        player = get_player_by_client_id(i);
        if (player == NULL) {
            continue;
        }
        if (is_script_controlled__10TObjPlayerFv(player) != 0) {
            continue;
        }
        if (obj_isState3_324__9TObjCharaFv(player) != 0) {
            continue;
        }
        if (is_trade_range_bit_set(i)) {
            forward_trade_action_default__16TObjCityMainWarpFPviii(list, (s32)player->get_name(), 7, i);
        } else {
            draw_text_gray__17TWindowSubComCardFllll(list, (void *)player->get_name(), 7, i);
        }
    }
    if (list->get_field_72() <= 0) {
        draw_text_gray__17TWindowSubComCardFllll(list, TWindowSubStatusDisp::get_message_10(0xD2), 7, 0);
    }
    list->set_flag70_bit10();
    list->set_scroll_target(lbl_805DE29C, lbl_805DE2A0);
    return list;
}

}

// ---- pso/ui/window/TWindowSubTrade
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/network/TradeSession.h"
#include "pso/unk/text_802D298C.h"
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct RecoveredGlobal_802B1F98___vt__15TWindowSubTrade { s32 value; u8 remaining[0x14]; };

struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

extern "C" {
void __dl__7TObjectFPv(s32);
s32 __dt__7TObjectFv(void *, int);
extern s32 __vt__15TWindowSubTrade[];
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int, int);
s32 play_sound_effect(int, int, int, int);
extern s32 controller_input_state[];

void TWindowSubTrade::render() {  }

extern void *lbl_805D3EA8;

void TWindowSubTrade::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    s32 temp_r5;
    temp_r30 = is_player_input_active((this->m_20));
    switch (this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->m_34 != 0U) {
            ((TWindowSubComCard *)(this->m_34))->close();
            this->m_34 = 0U;
        }
        if ((u32) this->m_30 != 0U) {
            ((TWindowBase *)this->m_30)->close();
            this->m_30 = 0U;
        }
        if ((u32) this->m_2c == 0U) {
            this->m_2c = (u32)TWindowSubComCard__sub_802B1C1C(this);
        }
        ((TWindowSubComCard *)(this->m_2c))->clear_flag_and_release();
        this->m_1c = 2U;
    case 2:
        if (((TWindowMenu *)(this->m_2c))->is_cancelled() != 0) {
            ((VObj_18_204a81 *)(this->m_28))->m7();
            this->m_1c = 7U;
        } else if (((TWindowMenu *)(this->m_2c))->is_decided() != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        if (this->m_2c != 0) {
            this->m_24 = ((TWindowMenu *)this->m_2c)->get_selected_value();
        }
        if ((u32) this->m_34 == 0U) {
            this->m_34 = ((TWindowSubTrade *)arg0)->open_trade_confirm_prompt(this->m_24);
        }
        this->m_1c = 4U;
    case 4:
        if (((TWindowSubComCard *)(this->m_34))->get_card_data() != 0) {
            this->m_1c = 1U;
        } else if (((TWindowMessageYesNo *)(this->m_34))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_34))->get_slot_or_neg1() == 0) {
                this->m_1c = 5U;
            } else {
                this->m_1c = 1U;
            }
        }
        break;
    case 5:
        if ((u32) this->m_34 != 0U) {
            ((TWindowSubComCard *)(this->m_34))->close();
            this->m_34 = 0U;
        }
        if ((u32) this->m_30 == 0U) {
            this->m_30 = ((TWindowSubTrade *)arg0)->open_player_message_window(this->m_24, (int) (TWindowSubStatusDisp::get_message_10(0xD7)));
        }
        send_modify_trade_proposal__6TLobbyFi((this->m_24));
        this->m_1c = 6U;
    case 6:
        temp_r5 = temp_r30 * 0x50;
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)(((u8 *)controller_input_state + temp_r5)) + 0x20), 2, (int)temp_r5) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TLobby::cancel_trade();
            this->m_1c = 1U;
        }
        break;
    case 7:
        break;
    }
}

u8 *__dt__15TWindowSubTradeFv(u8 *arg0, s16 arg1) {
    u8 *window_sub_com_card;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802B1F98___vt__15TWindowSubTrade *)&__vt__15TWindowSubTrade).value;
        TLobby__sub_802D2A2C((u32) arg0);
        TLobby::check_flags_and_proceed();
        window_sub_com_card = (u8 *)(*(u8 **)((s8 *)arg0 + 0x34));
        if (window_sub_com_card != NULL) {
            ((TWindowSubComCard *)window_sub_com_card)->close();
            *(u8 **)((s8 *)arg0 + 0x34) = NULL;
        }
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
        if (temp_r3_2 != NULL) {
            ((TWindowBase *)temp_r3_2)->close();
            *(u8 **)((s8 *)arg0 + 0x30) = NULL;
        }
        temp_r3_3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x2C));
        if (temp_r3_3 != NULL) {
            ((TWindowBase *)temp_r3_3)->close();
            *(u8 **)((s8 *)arg0 + 0x2C) = NULL;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}
TWindowSubTrade::TWindowSubTrade(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = lbl_805D3EA8;
    *(void **)((s8 *)this + 0x28) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_24 = 4;
    this->m_2c = 0;
    this->m_30 = 0;
    this->m_34 = 0;
    TLobby__sub_802D2A50((u32)this);
    this->m_1c = 0;
}
