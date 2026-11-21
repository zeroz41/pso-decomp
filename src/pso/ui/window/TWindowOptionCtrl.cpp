#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/unk/TUnk_804F01A8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8023F160.h"
#include "pso/unk/text_8036A3CC.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/unk/text_8013ADE4.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/ui/window/TWindowSoundBalance.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/ui/window/TWindowOptionCtrl_8026C5D8.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/window/TWindowOptionCtrl_8026C52C.h"
#include "pso/math/TMath.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/unk/TLobby_80132ED0.h"

// The class name opens .rodata (0x8044F478), then the menu window positions
// (0x8044F48C..0x8044F4A4) in this order, ahead of the strings of the functions.
const char *TWindowOptionCtrl__name = "TWindowOptionCtrl";
const vec2f lbl_8044F48C = {470.0f, 124.0f};
const vec2f lbl_8044F494 = {470.0f, 80.0f};
const vec2f lbl_8044F49C = {470.0f, 80.0f};
const vec2f lbl_8044F4A4 = {470.0f, 80.0f};

extern "C" {
u8 *get_window_layout_position(s32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
s32 create_window_menu_default(s32, s32);
}

struct Opt_8026BCC0 {
    u8 pad0[0x1C];
    s8 state;
    u8 f1D;
    u8 pad1E[2];
    s16 f20;
    u8 pad22[2];
    s32 f24;
    void *f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *f48;
};

extern "C" {
void *ct__13TUnk_804F01A8Fv(void *arg0);
void play_sound_effect(int, int, int, int);
void set_field_value__17TWindowOptionCtrlFls(s32 arg0, s16 arg1);
extern u8 controller_input_state[];
extern s32 __vt__17TWindowOptionCtrl[];
void __ct__7TObjectFP7TObject(void *);
}

int TWindowOptionCtrl__sub_8026C658(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }

s16 TWindowOptionCtrl::get_field_62() { return *(s16*)((char*)this + 0x62); }

s32 TWindowOptionCtrl::get_field_64() { return (s16)(*(s16*)((char*)this + 0x64)); }

int TWindowSoundBalance::is_active() { return this->m_60 & 0x1; }

int TWindowOptionCtrl__sub_8026C630(void* p) { return *(u8*)((char*)p + 0x60) & 0x1; }

void TWindowOptionCtrl::clear_flag70_bit4() { *(u16*)((char*)this + 0x70) &= 0xfffffffb; }

void TWindowSubComCardList::set_flag70_bit100() { this->m_70 |= 0x100; }

void TWindowOptionCtrl::set_flag70_bit400() { *(u16*)((char*)this + 0x70) |= 0x400; }

saddr TWindowOptionCtrl::get_chr_select_base_plus_1154c() {
    return TAdSinglePlyChrSelectGC::get_instance() + 0x1154C;
}

extern "C" {
void *TWindowOptionCtrl__ct(TWindowOptionCtrl *window_option_ctrl) {
    __ct__7TObjectFP7TObject(window_option_ctrl);
    *(s32 **)((s8 *)window_option_ctrl + 0x18) = __vt__17TWindowOptionCtrl;
    window_option_ctrl->m_name = TWindowOptionCtrl__name;
    window_option_ctrl->m_28 = 0;
    window_option_ctrl->m_2c = 0;
    window_option_ctrl->m_30 = 0;
    window_option_ctrl->m_34 = 0;
    window_option_ctrl->m_38 = 0;
    window_option_ctrl->m_3c = 0;
    window_option_ctrl->m_40 = 0;
    window_option_ctrl->m_44 = 0;
    window_option_ctrl->m_48 = 0;
    window_option_ctrl->player_load = new TAdPlayerLoadGC(window_option_ctrl, 2);
    window_option_ctrl->init_selection_indices();
    window_option_ctrl->m_24 = 4;
    window_option_ctrl->m_1d = 0;
    *(u8 *)((s8 *)window_option_ctrl + 0x1C) = 0;
    return window_option_ctrl;
}

TWindowOptionCtrl::~TWindowOptionCtrl() {
    apply_selection_change();
    if ((u32) m_44 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x44)))->close();
        m_44 = 0U;
    }
    if ((u32) m_40 != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x40)))->close();
        m_40 = 0U;
    }
    if ((u32) m_3c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x3C)))->close();
        m_3c = 0U;
    }
    if ((u32) m_38 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close();
        m_38 = 0U;
    }
    if ((u32) m_34 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close();
        m_34 = 0U;
    }
    if ((u32) m_30 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close();
        m_30 = 0U;
    }
    if ((uaddr) m_2c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x2C)))->close();
        m_2c = 0U;
    }
    if ((u32) m_28 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x28)))->close();
        m_28 = 0U;
    }
}

void TWindowOptionCtrl::run_task() {
    Opt_8026BCC0 *self = (Opt_8026BCC0 *)this;
    switch (self->state) {
    case 0:
    case 1:
        if (self->f44 != NULL) {
            ((TWindowBase *)self->f44)->close();
            self->f44 = NULL;
        }
        if (self->f40 != NULL) {
            ((TWindowSubComCard *)(self->f40))->close();
            self->f40 = NULL;
        }
        if (self->f3C != NULL) {
            ((TWindowBase *)self->f3C)->close();
            self->f3C = NULL;
        }
        if (self->f38 != NULL) {
            ((TWindowBase *)self->f38)->close();
            self->f38 = NULL;
        }
        if (self->f34 != NULL) {
            ((TWindowBase *)self->f34)->close();
            self->f34 = NULL;
        }
        if (self->f2C != NULL) {
            ((TWindowBase *)self->f2C)->close();
            self->f2C = NULL;
        }
        if (self->f28 == NULL) {
            self->f28 = (void *)((TWindowOptionCtrl *)self)->create_menu();
        }
        ((TWindowMenu *)(self->f28))->clear_transition_flag();
        ((TWindowSubComCard *)(self->f28))->clear_flag_and_release();
        self->state = 2;
    case 2:
        if (((TWindowMenu *)(self->f28))->is_cancelled() != 0) {
            self->state = 0x1B;
        } else if (((TWindowMenu *)(self->f28))->is_decided() != 0) {
            self->state = ((TWindowMenu *)self->f28)->get_selected_value();
        }
        break;
    case 3:
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f34 == NULL) {
            self->f34 = (void *)((TWindowOptionCtrl *)self)->create_select_menu_window();
        }
        self->state = 4;
    case 4:
        if (((TWindowMenuIconLine *)(self->f34))->is_cancelled() != 0) {
            self->state = 1;
        }
        if (((TWindowOptionCtrl *)self)->handle_input(((TWindowOptionCtrl *)self->f34)->update_selected_item()) != 0) {
            self->state = 1;
        }
        break;
    case 5:
        TWindowOptionCtrl__sub_802273B4(0x1E);
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f2C == NULL) {
            self->f2C = (void *)((TWindowOptionCtrl *)self)->create_list_window();
        }
        self->state = 6;
    case 6:
        if (((TWindowMenu *)(self->f2C))->is_cancelled() != 0) {
            if (self->f1D & 2) {
                TWindowOptionCtrl__sub_802273B4(0x1E);
                self->f1D &= ~2;
                ((TWindowOptionCtrl *)(self->f2C))->clear_flag70_bit4();
            } else {
                TLobby::stop_audio_streams();
                TLobby::close_option_window();
                play_area_music("advr.adx");
                self->state = 1;
                break;
            }
        }
        if (((TWindowMenu *)(self->f2C))->is_decided() != 0) {
            ((TWindowOptionCtrl *)self)->apply_and_close(((TWindowMenu *)self->f2C)->get_selected_value());
            ((TWindowSubComCard *)(self->f2C))->clear_flag_and_release();
        }
        break;
    case 7:
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f34 == NULL) {
            self->f34 = (void *)((TWindowOptionCtrl *)self)->create_sound_mode_menu();
        }
        self->state = 8;
    case 8:
        self->f20 = ((TWindowOptionCtrl *)self->f34)->update_selected_item();
        if (((TWindowMenuIconLine *)(self->f34))->is_cancelled() != 0) {
            self->state = 1;
        }
        break;
    case 9:
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f38 == NULL) {
            self->f38 = (void *)((TWindowOptionCtrl *)self)->create_sound_balance_window();
        }
        self->state = 0xA;
    case 10:
        if (TWindowOptionCtrl__sub_8026C658(self->f38) != 0) {
            s16 b = ((TWindowOptionCtrl *)self->f38)->get_field_64();
            TWindowOptionCtrl::set_params(self, (s16)((TWindowOptionCtrl *)(self->f38))->get_field_62(), b);
            self->state = 1;
        } else if (((TWindowSoundBalance *)(self->f38))->is_active() != 0) {
            s16 b = ((TWindowOptionCtrl *)self->f38)->get_field_64();
            TWindowOptionCtrl::set_params(self, (s16)((TWindowOptionCtrl *)(self->f38))->get_field_62(), b);
            self->state = 1;
        }
        break;
    case 11:
        if (TObjBoss2Tunnel::save_snapshot() != 1) {
            self->state = 0xE;
        } else {
            save_screen_snapshot();
            self->state = 0xC;
        }
        break;
    case 12:
        if (TObjBoss2Tunnel::load_snapshot() != 0) {
            ((TWindowOptionCtrl *)(self->f28))->open();
            if (self->f3C == NULL) {
                self->f3C = (void *)((TWindowOptionCtrl *)self)->create_snap_shot_window();
            }
            self->state = 0xD;
        }
        break;
    case 13:
        if (TWindowOptionCtrl__sub_8026C630(self->f3C) != 0) {
            self->state = 1;
        }
        break;
    case 14:
        if (self->f48 == NULL) {
            void *p = TObject::operator new(0x30);
            if (p != NULL) {
                p = ((void *(*)(void *, void *)) ct__13TUnk_804F01A8Fv)(p, self);
            }
            self->f48 = p;
        }
        ((TWindowOptionCtrl *)(self->f28))->open();
        self->state = 0xF;
    case 15: {
        s32 r = ((TUnk_804F01A8 *)(self->f48))->get_field_24();
        if (r == 1 || r == 2) {
            ((TObject *)self->f48)->queue_destruction();
            self->f48 = NULL;
            if (r == 1) {
                self->state = 0xB;
            } else {
                self->state = 1;
            }
        } else if (r == 3) {
            request_main_phase(0);
        }
        break;
    }
    case 16:
        if (self->f40 != NULL) {
            ((TWindowSubComCard *)(self->f40))->close();
            self->f40 = NULL;
        }
        if (self->f34 != NULL) {
            ((TWindowBase *)self->f34)->close();
            self->f34 = NULL;
        }
        if (self->f30 != NULL) {
            ((TWindowBase *)self->f30)->close();
            self->f30 = NULL;
        }
        if (self->f2C == NULL) {
            self->f2C = (void *)((TWindowOptionCtrl *)self)->create_sub_menu_window();
        }
        ((TWindowOptionCtrl *)(self->f28))->open();
        ((TWindowMenu *)(self->f2C))->clear_transition_flag();
        ((TWindowSubComCard *)(self->f2C))->clear_flag_and_release();
        self->state = 0x11;
    case 17:
        if (((TWindowMenu *)(self->f2C))->is_cancelled() != 0) {
            self->state = 1;
        } else if (((TWindowMenu *)(self->f2C))->is_decided() != 0) {
            self->state = ((TWindowMenu *)self->f2C)->get_selected_value();
        }
        break;
    case 18:
        ((TWindowOptionCtrl *)(self->f2C))->open();
        if (self->f34 == NULL) {
            self->f34 = (void *)((TWindowOptionCtrl *)self)->create_option_menu();
        }
        self->state = 0x13;
    case 19:
        ((void (*)(void *, s32)) set_field_value__17TWindowOptionCtrlFls)(self, ((TWindowOptionCtrl *)self->f34)->update_selected_item());
        if (((TWindowMenuIconLine *)(self->f34))->is_cancelled() != 0) {
            self->state = 0x10;
        }
        break;
    case 20:
    case 21:
        self->state = 0x17;
        break;
    case 22:
        if (((TWindowMenu *)(self->f30))->is_cancelled() != 0) {
            self->state = 0x10;
        }
        if (((TWindowMenu *)(self->f30))->is_decided() != 0) {
            self->state = 0x17;
        }
        break;
    case 23:
        if (self->f40 == NULL) {
            switch (((TWindowMenu *)self->f2C)->get_selected_value()) {
            case 0x14:
                self->f40 = (void *)TWindowOptionCtrl::open_yes_no_window((saddr)self, 0x22, 0xD0);
                break;
            case 0x15:
                self->f40 = (void *)TWindowOptionCtrl::open_yes_no_window((saddr)self, 0x24, 0xD0);
                break;
            }
        }
        ((TWindowOptionCtrl *)(self->f2C))->open();
        self->state = 0x18;
    case 24:
        if (((TWindowSubComCard *)(self->f40))->get_card_data() != 0) {
            self->state = 0x10;
        } else if (((TWindowMessageYesNo *)(self->f40))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(self->f40))->get_slot_or_neg1() == 0) {
                if (((TWindowMenu *)self->f2C)->get_selected_value() == 0x14) {
                    self->f24 = 1;
                } else {
                    self->f24 = 3;
                }
                self->state = 0x1B;
            } else {
                self->state = 0x10;
            }
        }
        break;
    case 25:
        if (self->f44 == NULL) {
            self->f44 = (void *)TWindowOptionCtrl::create_serial_info_window(TWindowOptionCtrl::get_option_entry(0xCF), 1);
        }
        ((TWindowOptionCtrl *)(self->f28))->open();
        self->state = 0x1A;
    case 26:
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 6) != 0 ||
            test_controller_flag_4c_color(controller_input_state + 0x160, 6) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            self->state = 1;
        }
        break;
    case 27:
        self->f1D |= 1;
        break;
    }
}
}

void TWindowOptionCtrl::render() {  }

extern "C" {
saddr TWindowOptionCtrl::create_menu() {
    saddr temp_r31;

    temp_r31 = create_window_menu_default((saddr)TWindowOptionCtrl::get_option_entry(0xCE), 9);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 0), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 1), 6, 7);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 2), 6, 5);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 3), 6, 9);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 4), 6, 0xB);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 5), 6, 0x10);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 6), 6, 0x19);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 7), 6, 0x1B);
    ((TWindowMenu *)temp_r31)->update_layout_height(470.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(temp_r31));
    return temp_r31;
}

saddr TWindowOptionCtrl::create_select_menu_window() {
    saddr temp_r31;
    temp_r31 = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)TWindowOptionCtrl::get_option_entry(0xCF), &lbl_8044F48C);
    TWindowOptionCtrl::add_menu_item(temp_r31, (get_localized_text_entry(0xF, 8)), 0);
    TWindowOptionCtrl::add_menu_item(temp_r31, (get_localized_text_entry(0xF, 9)), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, (get_localized_text_entry(0xF, 0xA)), 2);
    TWindowOptionCtrl::add_menu_item(temp_r31, (get_localized_text_entry(0xF, 0xB)), 3);
    TWindowOptionCtrl::add_menu_item(temp_r31, (get_localized_text_entry(0xF, 0xC)), 4);
    ((TWindowSubStatusDisp *)temp_r31)->set_selected_index((s16)((s16) current_language));
    return temp_r31;
}

saddr TWindowOptionCtrl::create_list_window() {
    s32 idx;
    saddr list;

    unlock_music_flag(2);
    list = create_window_menu_default((saddr)TWindowOptionCtrl::get_option_entry(0xCF), 0x31);
    ((TWindowSubComCardList *)list)->set_flag70_bit100();
    idx = 0;
    do {
        if (is_music_flag_unlocked_stub(idx) != 0) {
            if (check_flag_index_set(idx) == 0) {
                add_gray_text_entry((TWindowSubTradeMain *)list, (const char *)("?????"), 0x26, idx);
            } else {
                forward_trade_action_default__16TObjCityMainWarpFPviii(list, get_option_table_entry(idx), 0x26, idx);
            }
        }
        idx += 1;
    } while (idx < 0x31);
    ((TWindowOptionCtrl *)list)->set_flag70_bit400();
    ((TWindowSubComCardList *)list)->set_scroll_target(470.0f, 124.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

saddr TWindowOptionCtrl::create_sound_mode_menu() {
    saddr temp_r31;

    saddr temp_r3_after_cba4 = (saddr)TWindowOptionCtrl::get_option_entry(0xCF);
    temp_r31 = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)temp_r3_after_cba4, &lbl_8044F494);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0xE), 0);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0xD), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0xF), 2);
    switch (*(s16 *)((s8 *)this + 0x20)) {
    case 0:
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(0);
        break;
    case 1:
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(1);
        break;
    case 2:
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(2);
        break;
    }
    return temp_r31;
}

saddr TWindowOptionCtrl::create_sound_balance_window() {
    s32 var_r31;

    var_r31 = (saddr)new TWindowSoundBalance((saddr)TWindowOptionCtrl::get_option_entry(0xCF));
    return var_r31;
}

saddr TWindowOptionCtrl::create_snap_shot_window() {
    s32 window_snap_shot;

    window_snap_shot = (saddr)new TWindowSnapShot((saddr)TWindowOptionCtrl::get_option_entry(0xCF));
    return window_snap_shot;
}

saddr TWindowOptionCtrl::create_sub_menu_window() {
    saddr temp_r31;
    temp_r31 = create_window_menu_default((saddr)TWindowOptionCtrl::get_option_entry(0xCF), 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 0x1A), 6, 0x12);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 0x1B), 6, 0x14);
    forward_trade_action_default__16TObjCityMainWarpFPviii(temp_r31, get_localized_text_entry(0xF, 0x1C), 6, 0x15);
    ((TWindowMenu *)temp_r31)->update_layout_height(470.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(temp_r31));
    return temp_r31;
}

saddr TWindowOptionCtrl::create_option_menu() {
    saddr temp_r31;

    temp_r31 = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)TWindowOptionCtrl::get_option_entry(0xD0), &lbl_8044F49C);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0x10), 0);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0x11), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0x12), 2);
    ((TWindowSubStatusDisp *)temp_r31)->set_selected_index((s16) TWindowOptionCtrl::get_option_field_C());
    return temp_r31;
}

saddr TWindowOptionCtrl::open_yes_no_window(saddr arg0, s32 arg1, s32 arg2) {
  saddr temp_r30;
  temp_r30 = (saddr)TWindowMessageYesNo::create((void *)(arg0), (void *)(6), (void *)(arg0 * 0), 0);
  open_yes_no_prompt_with_text((TChCrTagPlBack *)temp_r30, (s32)(get_localized_text_entry(0xF, arg1)), (saddr)(get_window_layout_position(arg2)), 470.0f);
  set_menu_selected_index((TWindowSubComCard *)temp_r30, 1);
  return temp_r30;
}

saddr TWindowOptionCtrl::create_serial_info_window(const NJS_POINT2 *pos, s32 kind) {
    saddr w;
    w = (saddr)TWindowMessage::create(pos, (const f32 *)(&lbl_8044F4A4), 3);
    switch (kind) {
    case 0:
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x16)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC__sub_80321874()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x17)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC__sub_803217B8()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x18)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterPasswordGC__sub_8013ADE4()))), (u32)0);
        break;
    case 1:
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x16)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC__sub_80321738()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x17)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)(TAdEnterSerialAccessGC::get_formatted_serial()))), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x18)), (const char *)((saddr)TWindowOptionCtrl::text_or_default((const char *)((void *)TWindowOptionCtrl::get_chr_select_base_plus_1154c()))), (u32)0);
        break;
    }
    ((TWindowMessage *)w)->complete_reveal();
    return w;
}
}

const char *TWindowOptionCtrl::text_or_default(const char *text) {
    if ((text == NULL) || ((s8) *text == 0)) {
        return (const char *)get_localized_text_entry(0xF, 0x19);
    }
    return text;
}

extern "C" {
s32 TWindowOptionCtrl::handle_input(s32 language) {
    if (TLanguage::set_language((s8) language) != 0) {
        unload_lobby_scene_resources();
        load_lobby_scene_resources();
        if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x34)))->queue_destruction();
            *(u32 *)((s8 *)this + 0x34) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)this + 0x28) != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x28)))->queue_destruction();
            *(u32 *)((s8 *)this + 0x28) = 0U;
        }
        *(void **)((s8 *)this + 0x28) = (void *)((TWindowOptionCtrl *)this)->create_menu();
        window_request_refresh((u8 *)(*(uaddr *)((s8 *)this + 0x28)));
        return 1;
    }
    return 0;
}

void TWindowOptionCtrl::apply_and_close(s32 arg1) {
    TLobby::stop_audio_streams();
    TLobby::stop_audio_streams();
    TLobby::close_option_window();
    play_area_music(get_bgm_filename(arg1));
    this->m_1d = (u8) (this->m_1d | 2);
}

void TWindowOptionCtrl::init_selection_indices() {
    s16 temp_r3;

    temp_r3 = TLobby::init_sound_mode();
    *(s16 *)((s8 *)this + 0x1E) = temp_r3;
    *(s16 *)((s8 *)this + 0x20) = temp_r3;
}

void TWindowOptionCtrl::apply_selection_change() {
    if ((s16) *(s16 *)((s8 *)this + 0x1E) != (s16) *(s16 *)((s8 *)this + 0x20)) {
        TLobby::stop_audio_streams();
        TLobby::set_sound_output_mode(*(s16 *)((s8 *)this + 0x20));
        TLobby::init_layout_positions();
    }
}

void TWindowOptionCtrl::set_params(void *arg0, s16 arg1, s16 arg2) {
    void *global_state;

    global_state = TAdSinglePlyChrSelectGC::get_global_state();
    if (global_state != NULL) {
        *(s16 *)((s8 *)global_state + 4) = arg1;
        *(s8 *)((s8 *)global_state + 6) = arg2;
    }
}
}

s32 TWindowOptionCtrl::get_option_field_C() {
    return (s16)(*(s16 *)((s8 *)(TAdSinglePlyChrSelectGC::get_global_state()) + 0xC));
}

void TWindowOptionCtrl::set_field_value(s32 arg0, s16 arg1) {
    *(s16 *)((s8 *)(TAdSinglePlyChrSelectGC::get_global_state()) + 0xC) = arg1;
}
