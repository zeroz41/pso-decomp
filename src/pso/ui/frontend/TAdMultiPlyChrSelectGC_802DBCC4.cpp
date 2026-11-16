#include "types.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DBCC4.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802DC3D4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"

typedef struct S_802DC294 { u8 pad0[0x5C]; s32 f5C; } S_802DC294;

struct Info_802DC024 {
    s32 val[4];
    s32 idx[4];
    s32 count;
};

struct Sel_802DC118 { u8 pad[0x64]; u32 win; };

extern "C" {
s32 get_localized_text_entry(s32 arg0, s32 arg1);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
s32 free_member__17TWindowSubComCardFv(int, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(int, int, void *, f32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, int, int, int);
extern s32 lbl_804728A8[];
extern s32 lbl_804728A0[];
s32 align_menu_entry_positions(int);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
extern s32 lbl_80472890[];
extern u8 lbl_80472898[];
extern u8 player_number_text_buffer[];
void *memset(void *, int, u32);
s32 sprintf(void *, const void *, ...);
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(s32);
s32 TAdMultiPlyChrSelectGC__sub_802DC294(S_802DC294 *arg0, s32 arg1);
s32 copy_selected_characters__23TAdSinglePlyChrSelectGCFPv(void *);
}

s32 is_multiplayer_character_slot_selected(s32 arg0);
extern "C" {
s32 TAdMultiPlyChrSelectGC__sub_802C6558();
s32 TAdMultiPlyChrSelectGC__sub_802C658C(s32 arg0);
s32 set_entry_value__22TAdMultiPlyChrSelectGCFlUl(int, int, void *);
extern s32 TAdMultiPlyChrSelectGC__data_805DE898;
s32 clear_entries__18TAdChrMoveEffectGCFv();
s32 get_instance__22TAdMultiPlyChrSelectGCFv(s32);
void queue_destruction__7TObjectFv(void *arg0);
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);
}

u8 player_number_text_buffer[0x80];
extern "C" {
s32 play_sound_effect(s32, Vec *, s32, s32);
s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *);
extern s8 lbl_80472880[];
extern s8 lbl_80472888[];
extern s8 controller_physical_port_bank[];
void TAdMultiPlyChrSelectGC__sub_802DC5CC(void *arg0) {
    u32 var_r30;
    u32 gs;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x94) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x94)))->close();
        *(u32 *)((s8 *)arg0 + 0x94) = 0U;
    }
    if (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0) {
        play_sound_effect(0x52F16, (Vec *)(0), 0, 0);
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1B;
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1A;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    var_r30 = 0U;
loop_9:
    if (swap_characters__23TAdSinglePlyChrSelectGCFii(var_r30, *(s32 *)((s8 *)arg0 + 0x38)) != 0) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x84) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x84)))->close();
            *(u32 *)((s8 *)arg0 + 0x84) = 0U;
        }
        gs = TAdMultiPlyChrSelectGC::get_global_state();
        if (gs != 0U) {
            ((TAdChrMoveEffectGC *)gs)->setup_move_effect_params(*(s32 *)((s8 *)arg0 + 0x38) - 4, var_r30 + 3);
        }
        load_tables(*(s32 *)((s8 *)arg0 + 0x38));
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_status_value(var_r30);
        *(s32 *)((s8 *)arg0 + 0x80) = TAdMultiPlyChrSelectGC__sub_802DBEC4(arg0, (s32*)lbl_80472880);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(1);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->set_cursor_index(0x11);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x23;
        return;
    }
    var_r30 += 1;
    if (var_r30 >= 4U) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(1);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x84) == 0U) {
            *(u32 *)((s8 *)arg0 + 0x84) = TAdMultiPlyChrSelectGC__sub_802DBE4C(arg0, (s32*)lbl_80472888);
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x22;
        return;
    }
    goto loop_9;
}

void TAdMultiPlyChrSelectGC::handle_input() {
    void *context;

    if ((u32) this->m_94 != 0U) {
        ((TWindowSubComCard *)(*(void * *)&this->m_94))->close();
        this->m_94 = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)&this->unk_68))->get_player_index() < 0xE) {
            *(s32 *)&this->unk_58 = 0;
        }
        *(s32 *)&this->m_20 = 0x1D;
        return;
    }
    context = controller_physical_port_bank + 0x20;
    if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (TWindowShortListCtrl__check_controller_button(context, 2) != 0)) {
        *(s32 *)&this->m_20 = 0x1F;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DC440(void *arg0) {
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x14) {
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->set_field_1c(0x1B);
        *(s32 *)((s8 *)arg0 + 0x20) = 0x25;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0x13) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x80));
            *(u32 *)((s8 *)arg0 + 0x80) = 0U;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->reset_cursor_state();
        *(s32 *)((s8 *)arg0 + 0x20) = 0x24;
    }
}

void TAdMultiPlyChrSelectGC::check_cancel_input() {
    if ((((TAdMultiPlyChrSelectGC *)(this->m_6c))->get_mode() < 0x14) || (TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2) != 0)) {
        TAdPlayerLoadGC::set_state(1);
        *(s32 *)&this->unk_58 = 0;
        this->m_20 = 0x1D;
    }
}

void TAdMultiPlyChrSelectGC__sub_802DC310(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x88) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x88));
        *(u32 *)((s8 *)arg0 + 0x88) = 0U;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() < 0x14) {
        if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() < 0xE) {
            *(s32 *)((s8 *)arg0 + 0x58) = 0;
        }
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        return;
    }
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->get_mode() == 0x1D) {
        if (TAdMultiPlyChrSelectGC::get_global_state() != 0U) {
            clear_entries__18TAdChrMoveEffectGCFv();
        }
        *(s32 *)((s8 *)arg0 + 0x20) = 0x1D;
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->set_cursor_index(1);
        ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x6C)))->set_field_1c(1);
    }
}

int TAdMultiPlyChrSelectGC::request_scene_change() { return request_scene_change__21TAdMultiChgGameModeGCFv(this); }

s32 TAdMultiPlyChrSelectGC__sub_802DC294(S_802DC294 *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
    case 2:
        return TAdMultiPlyChrSelectGC__sub_802DFFE8(arg0->f5C);
    case 1:
        return TAdMultiPlyChrSelectGC__sub_802DFFE8(arg0->f5C) + 4;
    default:
        return -1;
    }
}

u8 *TAdMultiPlyChrSelectGC::format_player_number_text(s32 arg0, s32 arg1) {
    memset(player_number_text_buffer, 0, 0x80);
    sprintf(player_number_text_buffer, (const void *)get_localized_text_entry(0x1F, 0), arg1 + 1);
    return player_number_text_buffer;
}

void TAdMultiPlyChrSelectGC::sub_802DC118(s32 arg1) {
    Sel_802DC118 *s = (Sel_802DC118 *)this;
    if (s->win != 0) {
        switch (arg1) {
        case -1:
            if (TAdMultiPlyChrSelectGC__sub_802C6558() == TAdMultiPlyChrSelectGC::count_ready()) {
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
                return;
            }
            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 0, TAdMultiPlyChrSelectGC::format_player_number_text((s32)this, TAdMultiPlyChrSelectGC::get_clamped_cursor()));
            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
            break;
        default:
            if (TAdMultiPlyChrSelectGC__sub_802C6558() == TAdMultiPlyChrSelectGC::count_ready()) {
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
                return;
            }
            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 0, TAdMultiPlyChrSelectGC::format_player_number_text((s32)this, arg1));
            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(s->win, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
            break;
        }
    }
}

s32 TAdMultiPlyChrSelectGC::get_state_result() {
    s32 temp_r0;
    s32 var_r4;

    var_r4 = -1;
    temp_r0 = this->m_20;
    switch (temp_r0) {
    case 0:
        var_r4 = 0;
        break;
    case 12:
        var_r4 = get_instance__22TAdMultiPlyChrSelectGCFv(this->m_5c);
        break;
    case 29:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

void TAdMultiPlyChrSelectGC::collect_player_slots() {
    Info_802DC024 info;
    u32 i;
    info.count = TAdMultiPlyChrSelectGC__sub_802C6558();
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            info.val[i] = TAdMultiPlyChrSelectGC__sub_802C658C(i);
            info.idx[i] = i;
        } else {
            info.val[i] = -1;
            info.idx[i] = -1;
        }
    }
    copy_selected_characters__23TAdSinglePlyChrSelectGCFPv(&info);
}

s32 TAdMultiPlyChrSelectGC::create_choice_menu() {
    s32 window_menu;
    window_menu = create_window_menu((s32)lbl_80472890, 4, (TAdMultiPlyChrSelectGC::get_clamped_cursor()));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 2)), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 3)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 4)), 6, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)window_menu, (int)(get_localized_text_entry(0x1F, 5)), 6, 3);
    ((TWindowSubComCardList *)window_menu)->update_layout_height(224.0f);
    ((TWindowSubComCardList *)window_menu)->set_selected_index(0);
    align_menu_entry_positions(window_menu);
    return window_menu;
}

s32 TAdMultiPlyChrSelectGC__sub_802DBEC4(void *, s32 *desc) {
  s32 temp_r31;
  temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl((void *)desc, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) get_localized_text_entry(0x1F, 6)), 0x21, 0);
  ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
  TQuestThread::set_status_flag_80((void *)temp_r31);
  ((TWindowSubComCard *)temp_r31)->calc_layout_height(190.0f);
  return temp_r31;
}

s32 TAdMultiPlyChrSelectGC__sub_802DBE4C(void *, s32 *desc) {
  s32 temp_r31;
  temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl((void *)desc, 1);
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) get_localized_text_entry(0x1F, 7)), 0x21, 0);
  ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
  TQuestThread::set_status_flag_80((void *)temp_r31);
  ((TWindowSubComCard *)temp_r31)->calc_layout_height(190.0f);
  return temp_r31;
}

s32 TAdMultiPlyChrSelectGC::create_confirm_window() {
    void *u1;
    int u2;
    s32 r = create__19TWindowMessageYesNoFPvPvPvPv(u1, u2, 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(r, get_localized_text_entry(0x1F, 8), lbl_80472898, 196.0f);
    free_member__17TWindowSubComCardFv(r, 1);
    return r;
}

s32 TAdMultiPlyChrSelectGC__sub_802DBD64(s32 arg0) {
    s32 temp_r31;
    temp_r31 = create__19TWindowMessageYesNoFPvPvPvPv((void *)arg0, (int) (TAdMultiPlyChrSelectGC::get_clamped_cursor()), 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r31, (int) (get_localized_text_entry(0x1F, 9)), lbl_804728A0, 196.0f);
    free_member__17TWindowSubComCardFv(temp_r31, 1);
    return temp_r31;
}

s32 TAdMultiPlyChrSelectGC__sub_802DBCE8(s32 arg0) {
    s32 temp_r31;
    temp_r31 = create__19TWindowMessageYesNoFPvPvPvPv((void *)arg0, (int) (TAdMultiPlyChrSelectGC::get_clamped_cursor()), 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r31, (int) (get_localized_text_entry(0x1F, 0xA)), lbl_804728A8, 209.0f);
    free_member__17TWindowSubComCardFv(temp_r31, 1);
    return temp_r31;
}

void TAdMultiPlyChrSelectGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}

}
