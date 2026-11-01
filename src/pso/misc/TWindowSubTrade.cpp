#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/protocol/TradeSession.h"
#include "pso/unk/text_802D298C.h"
#include "pso/misc/TWindowSubTrade.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

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
u32 TWindowSubComCard__sub_802B1C1C(void *);
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
            this->m_2c = TWindowSubComCard__sub_802B1C1C((void *)arg0);
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
