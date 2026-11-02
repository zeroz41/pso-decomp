#include "types.h"
#include "pso/misc/TWindowSubComCard_802A5748.h"
#include "pso/misc/TLobby_803382E4.h"
#include "pso/misc/TWindowOptionCtrl_8034C384.h"
#include "pso/misc/TUnk_804F01A8.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"

extern "C" {
s32 get_localized_text_entry(s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 TAdPlayerLoadGC__sub_801E24F8(int, int, int, int, int);
s32 play_sound_effect(int, int, int, int);
extern s32 controller_input_state[];
u32 create__19TWindowMessageYesNoFPvPvPvPv(s32, s32, s32, s32);
void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(u32, s32, s32, f32);
s32 get_option_entry__17TWindowOptionCtrlFi(s32);
int reset_info_board__6TLobbyFv(void*);

int TLobby__sub_8034C384(void* p) { return reset_info_board__6TLobbyFv(p); }
int TLobby__sub_8034C3A4(void* p) { return reset_info_board__6TLobbyFv(p); }
s32 TWindowOptionCtrl::get_field_24() { return this->m_24; }

extern s32 local_client_id;
extern s32 tl_01;

void TWindowOptionCtrl::open_confirm_dialog(s32 arg1, s32 arg2) {
    if ((u32) this->m_2c != 0U) {
        ((TWindowSubComCard *)(this->m_2c))->close();
        this->m_2c = 0U;
    }
    this->m_2c = create__19TWindowMessageYesNoFPvPvPvPv(tl_01, local_client_id, 0, 0);
    if (arg2 != 0) {
        forward_slot_selection__16TAdChrSelASlotGCFPvPv(this->m_2c, arg1, get_option_entry__17TWindowOptionCtrlFi(0xCF), 470.0f);
        return;
    }
    initialize_option_dialog((void *)this->m_2c, arg1, (get_option_entry__17TWindowOptionCtrlFi(0xCF)), 470.0f);
}

void TWindowOptionCtrl::set_option_and_confirm(s32 arg1, s32 arg2) {
    if (arg1 != (s32) this->m_28) {
        this->m_28 = arg1;
        open_confirm_dialog((s32)(get_localized_text_entry(0x24)), arg2);
    }
}

void TWindowOptionCtrl__sub_8034C4C4(void* p) { if (*(int*)((char*)p + 0x1c) == 6) { TLobby::update_pulse_colors((s32)((void*)1)); TLobby__sub_80338534(); } }

extern s32 lbl_804F01A8[];

void TWindowOptionCtrl::handle_save_result() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r0_2;
    if (!(*(s32 *)((s8 *)arg0 + 0x20) & 1)) {
        switch (TObjBoss2Tunnel::save_snapshot()) {
        case 1:
            *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | 2);
            this->m_24 = 1;
            *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
            break;
        case -4:
            if (*(s32 *)((s8 *)arg0 + 0x20) & 2) {
                this->m_24 = 0;
                *(s32 *)((s8 *)arg0 + 0x1C) = 3;
            }
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(1, 0);
            }
            break;
        case -3:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(2, 1);
                *(s32 *)((s8 *)arg0 + 0x1C) = 0xB;
            }
            break;
        case -2:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(3, 0);
            }
            break;
        case -9:
            temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C);
            if ((temp_r0 == 4) || (temp_r0 == 0)) {
                set_option_and_confirm(7, 1);
                *(s32 *)((s8 *)arg0 + 0x1C) = 9;
            }
            break;
        case -1:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(4, 1);
                *(s32 *)((s8 *)arg0 + 0x1C) = 7;
            }
            break;
        case -7:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(5, 1);
                *(s32 *)((s8 *)arg0 + 0x1C) = 7;
            }
            break;
        case 0:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(6, 0);
                *(s32 *)((s8 *)arg0 + 0x1C) = 5;
            }
            break;
        case -6:
            if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) {
                set_option_and_confirm(0xA, 0);
            }
            break;
        case -8:
            if (((s32) *(s32 *)((s8 *)arg0 + 0x1C) == 4) && ((s32) this->m_28 != 0xF)) {
                this->m_28 = 0xF;
                open_confirm_dialog((int) (((s32 (*)(int, int)) get_localized_text_entry)(0x16, 5)), 0);
            }
            break;
        }
    }
    temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x1C);
    {
        switch (temp_r0_2) {
        case 0:
        case 1:
            set_option_and_confirm(0, 1);
            *(s32 *)((s8 *)arg0 + 0x1C) = 2;
        case 2:
            if (((TWindowSubComCard *)(this->m_2c))->get_card_data() != 0) {
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->m_2c))->is_child_visible() != 0) {
                if (((TWindowSubComCard *)(this->m_2c))->get_slot_or_neg1() == 0) {
                    *(s32 *)((s8 *)arg0 + 0x1C) = 3;
                    return;
                }
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            break;
        case 3:
            *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
            *(s32 *)((s8 *)arg0 + 0x1C) = 4;
        case 4:
            if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 6) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 6) != 0)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            break;
        case 5:
            *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | 1);
            TObjBoss2Tunnel::save_snapshot_to_card();
            *(s32 *)((s8 *)arg0 + 0x1C) = 6;
        case 6:
            if (TObjBoss2Tunnel::load_snapshot() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFE);
                *(s32 *)((s8 *)arg0 + 0x1C) = 3;
                return;
            }
            break;
        case 7:
            *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | 2);
            *(s32 *)((s8 *)arg0 + 0x1C) = 8;
        case 8:
            if (((TWindowSubComCard *)(this->m_2c))->get_card_data() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->m_2c))->is_child_visible() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                if (((TWindowSubComCard *)(this->m_2c))->get_slot_or_neg1() == 0) {
                    this->m_24 = 3;
                    *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                    return;
                }
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            break;
        case 9:
            *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | 2);
            *(s32 *)((s8 *)arg0 + 0x1C) = 0xA;
        case 10:
            if (((TWindowSubComCard *)(this->m_2c))->get_card_data() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->m_2c))->is_child_visible() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                if (((TWindowSubComCard *)(this->m_2c))->get_slot_or_neg1() == 0) {
                    TObjBoss2Tunnel::poll_pso_screen_load();
                    this->m_24 = 2;
                    *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                    return;
                }
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            break;
        case 11:
            *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | 2);
            *(s32 *)((s8 *)arg0 + 0x1C) = 0xC;
        case 12:
            if (((TWindowSubComCard *)(this->m_2c))->get_card_data() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            if (((TWindowMessageYesNo *)(this->m_2c))->is_child_visible() != 0) {
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFD);
                if (((TWindowSubComCard *)(this->m_2c))->get_slot_or_neg1() == 0) {
                    *(s32 *)((s8 *)arg0 + 0x1C) = 0xD;
                    return;
                }
                this->m_24 = 2;
                *(s32 *)((s8 *)arg0 + 0x1C) = 0x10;
                return;
            }
            break;
        case 13:
            if (TAdPlayerLoadGC__sub_801E24F8(1, 0, 0, 0, 0) == 0) {
                set_option_and_confirm(8, 0);
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | 1);
                *(s32 *)((s8 *)arg0 + 0x1C) = 0xE;
                return;
            }
            set_option_and_confirm(9, 0);
            *(s32 *)((s8 *)arg0 + 0x1C) = 0xF;
            return;
        case 14:
            if (TAdPlayerLoadGC__sub_801E1B50(1) == 0) {
                if ((u32) TAdPlayerLoadGC::get_load_result((void *)1) == 0xFFFFFF81U) {
                    set_option_and_confirm(9, 0);
                    *(s32 *)((s8 *)arg0 + 0x1C) = 0xF;
                    return;
                }
                *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & 0xFFFFFFFE);
                *(s32 *)((s8 *)arg0 + 0x1C) = 0;
                return;
            }
            break;
        case 15:
            if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 6) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 6) != 0)) {
                play_sound_effect(0x52F16, 0, 0, 0);
                *(s32 *)((s8 *)arg0 + 0x1C) = 3;
            }
            break;
        case 16:
            break;
        }
    }
}

void *TUnk_804F01A8::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804F01A8;
        if (*(void * *)&(this->unk_2C) != NULL) { ((TWindowSubComCard *)(*(void * *)&(this->unk_2C)))->close(); *(s32 *)&(this->unk_2C) = 0; }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804F01A8::ct() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804F01A8;
    *(u32 *)((s8 *)this + 0x1C) = 0;
    this->m_20 = 0;
    (*(u32 *)((u8 *)this + 0x24)) = 0;
    (this->m_28) = 14;
    (*(u32 *)&this->unk_2C) = 0;
    return this;
}

}
