#include "types.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubTechnique.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/item/TItem.h"
#include "pso/misc/TWindowSubShortCutList.h"
#include "pso/misc/TUnk_804D0618.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/misc/TWindowActionPalette.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8026EA60_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredFields_8026EA60_arg0
{
  u8 unknown_0[0x1C];
  u8 field_1C;
  u8 unknown_1D[0x7];
  s32 field_24;
  u8 unknown_28[0xC];
  u32 field_34;
};

struct RecoveredFields_8026EA60_temp_r29
{
  u8 unknown_0[0x34];
  s32 field_34;
};

struct Sc_8026EBB0 { f32 x; f32 y; };

struct Tb_8026EBB0 { s16 e[0x13]; };

struct Wn_8026EBB0 { u8 pad[0x24]; s32 card; };

struct Ctrl_8026ECBC {
    u8 pad0[0x1D];
    u8 state;
    s16 timer;
    u8 sub20[4];
    s32 player_id;
    u8 sub28[4];
    void *tech_win;
    void *list_win;
    void *help_win;
    s32 help_item;
};

struct Buf_8026E884 { s16 h[19]; };

extern "C" {
s32 canSetMenuCursorAction(s32, s32, u8, u8);
s32 get_player_by_client_id(s32);
s32 TItemObject__sub_80115DE8(void *item);
void TMainCursor__sub_8013DFC4(u8 *arg0);
extern s32 lbl_805DD380;
s32 fn_8002AE08(int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 is_player_input_active(s32 param_1);
extern RecoveredGlobal_8026EA60_lbl_8050E208 controller_input_state;
s32 get_character_save_record(u32 arg0);
void align_menu_entry_positions(void *);
s32 TWindow__close(void *);
void queue_destruction__7TObjectFv(void *arg0);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 try_send_6x27_use_item(void *arg0, s32 arg1);
s32 decrement_clamped(s32 *arg0, s32 arg1);
s32 try_equip_item__10TObjPlayerFii(u8 *, s32);
void play_sound_effect(int, int, int, int);
void *__nw__7TObjectFUl(u32);
s32 TWindowCtrl__sub_8024A228(s32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, s32);
s16 get_selected_menu_value(void *);
s32 select_cursor_entry__22TWindowSubShortCutListFv(void *);
s32 get_window_layout_position(int);
void *create_equip_kind_window(s32, u8 *, s32);
s32 update_selection__19TWindowSubTechniqueFPsPl(void *, void *, s32);
void get_current_selection__19TWindowSubTechniqueFPv(void *, void *, s32);
extern u8 lbl_8044F5A0[];
void run_task__20TWindowShortListCtrlFv(TWindowShortListCtrl *arg0);
extern const Buf_8026E884 lbl_8044F5A8;
void TWindowShortListCtrl__sub_8026E884(s16 *dst);
void *__dt__20TWindowShortListCtrlFv(TWindowShortListCtrl *arg0, s16 arg1);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
s32 end_player_keyboard_hold(s32);
s32 TWindowCtrl__sub_8024A1A8();
s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 TWindowHelpItem__set_displayed_item_by_id(u32);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
s32 is_technique_ready__8TTecCtrlFv();
s32 set_flag70_bit10__21TWindowSubComCardListFv();

void TWindowShortListCtrl::set_displayed_item(s32 arg1) {
    if (((u32) this->m_34 != 0U) && (arg1 != (s32) this->m_38)) {
        this->m_38 = arg1;
        TWindowHelpItem__set_displayed_item_by_id(this->m_34);
    }
}

s32 TWindowShortListCtrl::is_technique_usable() {
    u32 player;
    u8 *temp_r31;

    player = get_player_by_client_id((s32)((int) (this->m_24)));
    if (player == 0U) {
        return 0;
    }
    temp_r31 = (unsigned char *) (player + 0x85C);
    if (temp_r31 == NULL) {
        return 0;
    }
    if (is_technique_ready__8TTecCtrlFv() != 0) {
        return 1;
    }
    return ((u32) *(u32 *)((s8 *)temp_r31 + 0x34) >> 4U) & 1;
}

void TWindowShortListCtrl__sub_8026E884(s16 *dst) {
    s32 i;
    Buf_8026E884 local = lbl_8044F5A8;
    for (i = 0; i < 19; i++) {
        dst[i] = local.h[i];
    }
}

void TWindowShortListCtrl::swap_card_entries(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s16 *p = (s16 *)(get_character_save_record(*(s32 *)(arg0 + 0x24)) + 0x22C4);
    s16 t = p[arg1];
    p[arg1] = p[arg2];
    p[arg2] = t;
}

void TWindowShortListCtrl::assign_item_to_palette(u32 arg0, u32 arg1) {
    s32 player;
    s32 var_r4;
    s32 var_r5;
    u32 item;
    u32 var_r29;
    u32 var_r31;
    u32 var_r3;
    u8 parameter;
    var_r31 = arg0;
    var_r3 = arg1;
    player = get_player_by_client_id(var_r3);
    if (player != 0) {
        var_r29 = *(u32 *)((s8 *)player + 0x424);
        if (var_r29 != 0U) {
            var_r3 = var_r31;
            item = (unsigned long) (find_item_by_id((s32) var_r3));
            var_r31 = item;
            if ((var_r31 != 0) && (((TItem *)item)->get_item_type() == 3)) {
                var_r3 = var_r31;
                var_r31 = TItemObject__sub_80115DE8((void *)var_r3);
                if ((s32) var_r31 != -1) {
                    var_r4 = player;
                    var_r3 = var_r29 + 0x520;
                    parameter = (u8) var_r31;
                    var_r5 = 4;
                    if (canSetMenuCursorAction((s32) var_r3, var_r4, 4U, parameter) != 0) {
                        var_r3 = var_r29 + 0x520;
                        var_r4 = 4;
                        ((TWindowActionPalette *)var_r3)->set_mode(4);
                        var_r3 = var_r29 + 0x520;
                        var_r4 = (s32) (u8) var_r31;
                        ((TWindowActionPalette *)var_r3)->set_slot(var_r4);
                        var_r3 = var_r29 + 0x520;
                        TMainCursor__sub_8013DFC4((u8 *)var_r3);
                    }
                }
            }
        }
    }
}

void TWindowShortListCtrl::destroy_children() {
    if ((u32) this->m_30 != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->m_30);
        this->m_30 = 0U;
    }
    if ((u32) this->m_2c != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->m_2c);
        this->m_2c = 0U;
    }
}

void TWindowShortListCtrl::sub_8026EA48() {
    this->m_1d = (u8) *(u8 *)((s8 *)((u8 *)(&lbl_805DD380) + (s8) this->m_1c) + 0);
}

typedef struct RecoveredFields_8026EA60_arg0 RecoveredFields_8026EA60_arg0;
typedef struct RecoveredFields_8026EA60_temp_r29 RecoveredFields_8026EA60_temp_r29;
typedef struct RecoveredGlobal_8026EA60_lbl_8050E208 RecoveredGlobal_8026EA60_lbl_8050E208;
void TWindowShortListCtrl::cycle_list_page() {
  s32 temp_r31;
  u32 player;
  u8 temp_r31_2;
  u8 temp_r3_2;
  u8 temp_r3_3;
  u8 temp_r3_4;
  u8 temp_r3_5;
  u8 temp_r3_6;
  u8 *temp_r29;
  temp_r31 = is_player_input_active((int) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_24);
  if (TWindowShortListCtrl__check_controller_button((void *) ((((u8 *) (&controller_input_state.value)) + (temp_r31 * 0x50)) + 0x20), (int) fn_8002AE08((int) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_24)) != 0)
  {
    temp_r31_2 = ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C;
    player = ((u32)get_player_by_client_id((s32)((int) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_24)));
    if (player != 0U)
    {
      temp_r29 = (u8 *) (player + 0x85C);
      if ((temp_r29 != 0) && (((u32) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_34) == 0U))
      {
        ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C = (u8) (((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C + 1);
        temp_r3_2 = ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C;
        if (((s8) temp_r3_2) >= 4)
        {
          ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C = (u8) (temp_r3_2 - 4);
        }
        if ((((s32) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C) == 2) && (((TWindowShortListCtrl *)((u8 *)this))->is_technique_usable() == 0))
        {
          ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C = (u8) (((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C + 1);
          temp_r3_3 = ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C;
          if (((s8) temp_r3_3) >= 4)
          {
            ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C = (u8) (temp_r3_3 - 4);
          }
        }
        if (((RecoveredFields_8026EA60_temp_r29 *) temp_r29)->field_34 & 0x10)
        {
          temp_r3_4 = ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C;
          if (((s32) temp_r3_4) == 3)
          {
            ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C = (u8) (temp_r3_4 + 1);
            temp_r3_5 = ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C;
            if (((s8) temp_r3_5) >= 4)
            {
              ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C = (u8) (temp_r3_5 - 4);
            }
          }
        }
        temp_r3_6 = ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C;
        if (((s8) temp_r31_2) != ((s8) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_1C))
        {
          TWindowShortListCtrl::set_card_window_flags((int) ((RecoveredFields_8026EA60_arg0 *) ((u8 *)this))->field_24, (s32)((int) ((s32) ((s8) temp_r3_6))));
          this->destroy_children();
          sub_8026EA48();
        }
      }
    }
  }
}

void TWindowShortListCtrl::refresh_technique_rows(s32 arg1, void *arg2_arg) {
    Sc_8026EBB0 *arg2 = (Sc_8026EBB0 *)arg2_arg;
    s32 i;
    s16 cur;
    Tb_8026EBB0 *tbl;
    tbl = (Tb_8026EBB0 *)(get_character_save_record(((Wn_8026EBB0 *)this)->card) + 0x22C4);
    cur = ((TWindowShortListCtrl *)arg1)->get_cursor_pos();
    ((TWindowSubComCardList *)arg1)->reset_entries();
    for (i = 0; i < 0x13; i++) {
        TWindowSubTechnique::draw_technique_row(tbl->e[i], ((Wn_8026EBB0 *)this)->card, arg1);
    }
    ((TWindowSubComCardList *)arg1)->set_scroll_target(arg2->x, arg2->y);
    align_menu_entry_positions((void *)arg1);
    ((TWindowSubComCardList *)arg1)->set_selected_index(cur);
}

void *TWindowShortListCtrl::create_window(s32 arg1, s32 arg2_arg) {
    void *window_menu;

    window_menu = (void *)create_window_menu(arg1, 0x13, this->m_24);
    set_flag70_bit10__21TWindowSubComCardListFv();
    ((TWindowSubComCardList *)window_menu)->m_5c = 0x01000000;
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit100();
    refresh_technique_rows((s32)((void*)(window_menu)), (Sc_8026EBB0 *)((void*)(arg2_arg)));
    return window_menu;
}
void TWindowShortListCtrl::render() {  }

extern void *__vt__20TWindowShortListCtrl[];

#define PAD(i) ((void *) ((((u8 *) (&controller_input_state.value)) + ((i) * 0x50)) + 0x20))
#define BACK_PRESSED(i) (TWindowShortListCtrl__check_controller_button(PAD(i), 2) != 0 || test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) (((u8 *) (&controller_input_state.value)) + 0x160), 2) != 0)
void run_task__20TWindowShortListCtrlFv(TWindowShortListCtrl *window_short_list_ctrl) {
    Ctrl_8026ECBC *self = (Ctrl_8026ECBC *) window_short_list_ctrl;
    s32 idx;
    u8 *player;
    s32 sel;
    idx = is_player_input_active(self->player_id);
    player = (u8 *) get_player_by_client_id(self->player_id);
    if ((self->timer > 2 && TWindowShortListCtrl__check_controller_button(PAD(idx), 0x200) != 0) || player == NULL) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    window_short_list_ctrl->cycle_list_page();
    switch (self->state) {
    case 0:
        if (self->list_win == NULL) {
            self->list_win = create_equip_kind_window(get_window_layout_position(1), lbl_8044F5A0, self->player_id);
            ((TWindowSubShortCutList *)(self->list_win))->set_flag70_bit10();
            ((TWindowShortListCtrl *)(self->list_win))->update_variant_c();
            *(s32 *) ((u8 *) self->list_win + 0x5C) = 0x01000000;
        }
        self->state = 1;
    case 1:
        if (TWindowShortListCtrl__check_controller_button(PAD(idx), 0x400) != 0) {
            if (self->help_win == NULL) {
                void *w = __nw__7TObjectFUl(0xBC);
                if (w != NULL) {
                    w = __ct__15TWindowHelpItemFPvUs(w, get_window_layout_position(2), self->player_id);
                }
                self->help_win = w;
                self->help_item = -1;
                TWindowCtrl::clear_flag_8();
            } else {
                TWindow__close(self->help_win);
                self->help_win = NULL;
                TWindowCtrl::set_flag_active();
            }
        }
        ((TWindowShortListCtrl *)self)->set_displayed_item(select_cursor_entry__22TWindowSubShortCutListFv(self->list_win));
        if (((TLobby *)(self->list_win))->get_flag_bit2() != 0) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (((TUnk_804D0618 *)(self->list_win))->get_status_flag() != 0) {
            self->state = 2;
        }
        break;
    case 2:
        if (BACK_PRESSED(idx)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (TWindowSubItem::is_usable((s32)player) == 0) {
            break;
        }
        TWindowShortListCtrl::assign_shortcut(6, select_cursor_entry__22TWindowSubShortCutListFv(self->list_win), self->player_id);
        queue_destruction__7TObjectFv(self);
        return;
    case 3:
        if (self->list_win == NULL) {
            self->list_win = create_equip_kind_window(get_window_layout_position(1), lbl_8044F5A0, self->player_id);
            ((TWindowSubShortCutList *)(self->list_win))->set_flag70_bit10();
            ((TWindowShortListCtrl *)(self->list_win))->update_variant_b();
            *(s32 *) ((u8 *) self->list_win + 0x5C) = 0x01000000;
        }
        self->state = 4;
    case 4:
        TWindowShortListCtrl::assign_item_to_palette(select_cursor_entry__22TWindowSubShortCutListFv(self->list_win), self->player_id);
        if (((TLobby *)(self->list_win))->get_flag_bit2() != 0) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (((TUnk_804D0618 *)(self->list_win))->get_status_flag() != 0) {
            self->state = 5;
        }
        break;
    case 5:
        TWindowShortListCtrl::assign_item_to_palette(select_cursor_entry__22TWindowSubShortCutListFv(self->list_win), self->player_id);
        if (BACK_PRESSED(idx)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (TWindowSubItem::is_usable((s32)player) == 0) {
            break;
        }
        sel = select_cursor_entry__22TWindowSubShortCutListFv(self->list_win);
        if (find_item_by_id(sel) == NULL) {
            return;
        }
        try_send_6x27_use_item(player, sel);
        queue_destruction__7TObjectFv(self);
        return;
    case 6:
        if (self->list_win == NULL) {
            self->list_win = create_equip_kind_window(get_window_layout_position(1), lbl_8044F5A0, self->player_id);
            ((TWindowSubShortCutList *)(self->list_win))->set_flag70_bit10();
            ((TWindowShortListCtrl *)(self->list_win))->update_variant_a();
            *(s32 *) ((u8 *) self->list_win + 0x5C) = 0x01000000;
        }
        self->state = 7;
    case 7:
        TWindowShortListCtrl::assign_item_to_palette(select_cursor_entry__22TWindowSubShortCutListFv(self->list_win), self->player_id);
        if (((TLobby *)(self->list_win))->get_flag_bit2() != 0) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (((TUnk_804D0618 *)(self->list_win))->get_status_flag() != 0) {
            self->state = 8;
        }
        break;
    case 8:
        if (BACK_PRESSED(idx)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (TWindowSubItem::is_usable((s32)player) == 0) {
            return;
        }
        sel = select_cursor_entry__22TWindowSubShortCutListFv(self->list_win);
        if ((sel & 0xF) == 4) {
            if (TAdSinglePlyChrSelectGC::create_if_key_pressed() == 0) {
                break;
            }
            decrement_clamped((s32 *)(player + 0x7C8), 1);
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (TWindowCtrl__sub_8024A228(self->player_id) == 0) {
            return;
        }
        ((TObjPlayer *)player)->send_trap_packet(sel & 0xF);
        queue_destruction__7TObjectFv(self);
        return;
    case 9:
        if (self->tech_win == NULL) {
            get_current_selection__19TWindowSubTechniqueFPv(self->sub20, self->sub28, self->player_id);
            self->tech_win = ((TWindowShortListCtrl *)self)->create_window(get_window_layout_position(1), (s32) lbl_8044F5A0);
        }
        ((TWindowSubComCard *)(self->tech_win))->clear_flag_and_release();
        self->state = 10;
    case 10:
        ((TObjPlayer *)player)->update_cursor(get_selected_menu_value(self->tech_win));
        if (update_selection__19TWindowSubTechniqueFPsPl(self->sub20, self->sub28, self->player_id) != 0) {
            ((TWindowShortListCtrl *)self)->refresh_technique_rows((s32) self->tech_win, (Sc_8026EBB0 *) lbl_8044F5A0);
        }
        if (TWindowShortListCtrl__check_controller_button(PAD(idx), 0x400) != 0) {
            if (((TWindowSubComCardList *)(self->tech_win))->get_selected_index() == -1) {
                ((TWindowShortListCtrl *)((u8 *) self->tech_win))->update_cursor_pos();
            } else {
                window_short_list_ctrl->swap_card_entries(((TWindowSubComCardList *)(self->tech_win))->get_selected_index(), ((TWindowShortListCtrl *)(self->tech_win))->get_cursor_pos());
                ((TWindowMenu *)(self->tech_win))->reset_selection();
                ((TWindowShortListCtrl *)self)->refresh_technique_rows((s32) self->tech_win, (Sc_8026EBB0 *) lbl_8044F5A0);
            }
        }
        if (((TWindowSubComCard *)(self->tech_win))->get_status_flag() != 0) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (((TWindowMenu *)(self->tech_win))->is_visible() != 0) {
            self->state = 11;
        }
        break;
    case 11:
        ((TObjPlayer *)player)->update_cursor(get_selected_menu_value(self->tech_win));
        if (BACK_PRESSED(idx)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (try_equip_item__10TObjPlayerFii(player, get_selected_menu_value(self->tech_win)) != 0) {
            queue_destruction__7TObjectFv(self);
            return;
        }
        if (TWindowSubTechnique::is_technique_available(get_selected_menu_value(self->tech_win), self->player_id) == 0) {
            ((TWindowShortListCtrl *)self)->refresh_technique_rows((s32) self->tech_win, (Sc_8026EBB0 *) lbl_8044F5A0);
            self->state = 9;
            return;
        }
        break;
    }
    self->timer++;
    if (self->timer < 0) {
        self->timer = 2;
    }
}

void *__dt__20TWindowShortListCtrlFv(TWindowShortListCtrl *arg0, s16 arg1) {
    s32 player;

    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = __vt__20TWindowShortListCtrl;
        player = get_player_by_client_id((s32)(arg0->m_24));
        if ((player != 0) && (has_player_active_menu__11TWindowCtrlFv(arg0->m_24) == 0) && (TWindowCtrl__sub_8024A1A8() == 0)) {
            ((TObjPlayer *)player)->init_parts();
        }
        end_player_keyboard_hold(arg0->m_24);
        TWindowCtrl::clear_flag_8();
        if ((u32) arg0->m_34 != 0U) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x34));
            arg0->m_34 = 0U;
        }
        if ((u32) arg0->m_30 != 0U) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x30));
            arg0->m_30 = 0U;
        }
        if ((u32) arg0->m_2c != 0U) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x2C));
            arg0->m_2c = 0U;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TWindowShortListCtrl::set_card_window_flags(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 0x10), (s32)0xFFFCFFFF);
}
s16 TWindowShortListCtrl::get_cursor_pos() { return *(s16*)((char*)this + 0x78); }

void TWindowShortListCtrl::update_cursor_pos() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x7A) = get_cursor_pos();
}

s16 TWindowSubComCardList::get_selected_index() { return *(s16 *)&this->unk_7A; }

}
