#include "types.h"
#include "pso/ui/window/TWindowSubGameEnd.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"

#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"

#pragma readonly_strings on


const char *TWindowSubGameEnd__class_name = "TWindowSubGameEnd";
int window_sub_game_end_active_flag;


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
extern saddr tl_00;
s32 get_main_phase();
s32 __ct__7TObjectFP7TObject();
saddr get_window_layout_position(s32);
extern s32 __vt__17TWindowSubGameEnd[];
s32 set_queued_main_phase(s32);
s32 request_main_phase(s32);

void TKeyBoardControl::init_char_select() {
    if (is_split_screen() != 0) {
        setup_player_battle_ctrls__23TAdSinglePlyChrSelectGCFv();
        request_main_phase(7);
        return;
    }
    TAdSinglePlyChrSelectGC::init();
    set_queued_main_phase(9);
    request_main_phase(0x12);
}
void TWindowSubGameEnd::render() {  }

void TWindowSubGameEnd::run_task() {
    s32 slot;
    void *obj;
    switch (this->m_1c) {
    case 0:
    case 1:
        if (((TWindowSubComCard *)(this->m_28))->get_card_data() != 0) {
            (*(VObj_18_204a81 * *)&this->m_24)->m7();
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_28))->is_child_visible() != 0) {
            slot = ((TWindowSubComCard *)(this->m_28))->get_slot_or_neg1();
            if (slot == 0) {
                if (window_sub_game_end_active_flag != 1) {
                    obj = (void *)TObject::operator new(0x28);
                    if (obj != NULL) {
                        ((THunterGuildSeqOffline *)obj)->init((void *)tl_00, (void *)((void *)TKeyBoardControl::init_char_select));
                    }
                    fn_8024AB54(this->m_20);
                    send_logout__6TLobbyFv();
                    window_sub_game_end_active_flag = 1;
                }
                this->m_1c = 2;
            }
            if (slot == 1) {
                (*(VObj_18_204a81 * *)&this->m_24)->m7();
            }
        }
        break;
    case 2:
        break;
    }
}

}
TWindowSubGameEnd::~TWindowSubGameEnd() {
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x28)))->close(); this->m_28 = 0; }
}


void *TWindowSubGameEnd__ct(TWindowSubGameEnd *window_sub_game_end, s32 arg1, s32 arg2) {
    f32 var_f31;
    s32 var_r31;
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_game_end + 0x18) = __vt__17TWindowSubGameEnd;
    *(s32 *)((s8 *)window_sub_game_end + 0) = (s32) ((saddr)TWindowSubGameEnd__class_name);
    window_sub_game_end->m_24 = arg1;
    window_sub_game_end->m_20 = arg2;
    if (get_main_phase() == 0xF) {
        var_r31 = (saddr)TWindowSubStatusDisp::get_message_10(0x3B);
        var_f31 = 469.0f;
    } else if (is_split_screen() != 0) {
        var_r31 = (saddr)TWindowSubStatusDisp::get_message_10(0x3C);
        var_f31 = 312.0f;
    } else {
        var_r31 = (saddr)TWindowSubStatusDisp::get_message_10(0x3A);
        var_f31 = 469.0f;
    }
    window_sub_game_end->m_28 = (saddr)TWindowMessageYesNo::create((void *)(window_sub_game_end), (void *)(window_sub_game_end->m_20), 0, 0);
    open_yes_no_prompt_with_text((TChCrTagPlBack *)window_sub_game_end->m_28, (s32)var_r31, (s32)(get_window_layout_position(0x17)), var_f31);
    set_menu_selected_index((TWindowSubComCard *)window_sub_game_end->m_28, 1);
    ((TWindowMessageYesNo *)(window_sub_game_end->m_28))->set_choice_menu_flag70_bit10();
    window_sub_game_end->m_1c = 0;
    return window_sub_game_end;
}

void TLobby__sub_802796FC(void) { window_sub_game_end_active_flag = 0; }

void TLobby__sub_80279708(void) { window_sub_game_end_active_flag = 0; }

