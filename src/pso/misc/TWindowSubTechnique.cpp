#include "types.h"
#include "pso/misc/TWindowSubTechnique_80286BD4.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubTechnique.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

extern "C" f32 TWindowSubEquip__sub_80263AF8(u8 *arg0, u32 arg1);

extern "C" {
int get_selection__19TWindowSubTechniqueFPsPll(void*, void* a1);
void *get_player_by_client_id(s32 i);
s32 is_palette_entry_displayable__10TObjPlayerFv(u8 *arg0, u8 kind, u8 sub);
s32 get_message_10__20TWindowSubStatusDispFl(int);
s32 set_field_1c__6TLobbyFf(int);
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
s32 get_window_layout_position(int);
extern s16 *technique_menu_category_lists[];

s32 get_cursor_pos__20TWindowShortListCtrlFv(s32);
void align_menu_entry_positions(s32);
void set_selected_index__21TWindowSubComCardListFs(s32, s32);

s32 get_technique_name(s16);
s32 can_use_palette_action__10TObjPlayerFPvUcUc(u32, s32, u8);
s32 add_text_entry__19TWindowSubTradeMainFllll(s32, s32, s32, s16, s32);
s32 draw_text_gray__17TWindowSubComCardFllll(s32, s32, s32, s16);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s16);

int TWindowSubTechnique::get_current_selection(void* _w1) { return get_selection__19TWindowSubTechniqueFPsPll(this, _w1); }

s32 TWindowSubTechnique::is_technique_available(s32 sub, s32 arg1) {
    s32 player;
    player = ((s32)get_player_by_client_id(arg1));
    if (player == 0) {
        return 0;
    }
    if (is_current_area_item_enabled() == 0) {
        return 0;
    }
    if (TWindowSubTechnique::lookup_technique(sub, arg1) != 0) {
        return is_palette_entry_displayable__10TObjPlayerFv((u8 *)player, (u8)(3), (u8)((u8) sub));
    }
    return 0;
}

s32 TWindowSubTechnique::lookup_technique(s32 arg0, s32 arg1) {
    u32 temp = (u32)get_player_by_client_id(arg1);
    if (temp == 0U) {
        return 0;
    }
    return can_use_palette_action__10TObjPlayerFPvUcUc(temp, 3, (u8) arg0);
}
void TWindowSubTechnique::draw_technique_row(s32 id, s32 arg1, s32 arg2) {
    s32 technique_name;

    technique_name = get_technique_name(id);
    if (TWindowSubTechnique::lookup_technique(id, arg1) == 0) {
        draw_text_gray__17TWindowSubComCardFllll(arg2, technique_name, 6, id);
        return;
    }
    if (TWindowSubTechnique::is_technique_available(id, arg1) == 0) {
        add_text_entry__19TWindowSubTradeMainFllll(arg2, technique_name, 0x16, id, 0xFFFD3901);
        return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(arg2, technique_name, 6, id);
}
#pragma fp_contract on

void TWindowSubTechnique::rebuildTechniqueList(s32 list, s32 category) {
    s32 selected;
    s16 *entry;
    entry = technique_menu_category_lists[category];
    selected = get_cursor_pos__20TWindowShortListCtrlFv(list);
    ((TWindowSubComCardList *)list)->reset_entries();
    while (*entry != 19) {
        TWindowSubTechnique::draw_technique_row(*entry, playerIndex, list);
        ++entry;
    }
    ((TWindowSubComCardList *)list)->update_layout_height(179.0f);
    align_menu_entry_positions(list);
    set_selected_index__21TWindowSubComCardListFs(list, selected);
}

s32 TWindowSubTechnique::create_title_window() {
  s32 titled_window_menu;
  titled_window_menu = create_titled_window_menu((int) get_window_layout_position(0x13), 5, (0, get_message_10__20TWindowSubStatusDispFl(0x30)), (this->playerIndex));
  TWindowSubEquip__sub_80263AF8((u8 *)this->m_30, 1);
  set_field_1c__6TLobbyFf((int) titled_window_menu);
  ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit100();
  ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit10();
  return titled_window_menu;
}
}

struct Base_802870C4 { char pad[0x18]; };

struct VObj_802870C4 : Base_802870C4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
};

struct Tech_802870C4 {
    u8 pad0[0x1C];
    u8 state;
    u8 pad1D;
    s16 f1E;
    u8 f20[4];
    u8 f24[4];
    s32 player;
    u8 pad2C[4];
    VObj_802870C4 *f30;
    void *list;
    void *sel;
    void *help;
};

struct Pad_802870C4 { u8 pad[0x20]; u8 m20[0x30]; };

extern u8 *text_language_group_table;
extern "C" {
s32 TWindowSubTechnique__sub_8028753C(s32 arg0);
u8 *calc_technique_parameters(s16, u8, s32);
s32 *get_shared_text_buffer();
void *get_player_by_client_id(s32 i);
s32 get_cast_technique_level(void *, int);
s32 validate_and_clear_slot__10TObjPlayerFv(void *, int);
void TWindowSubStatusDisp__sub_80228F5C(s32 arg0);
void text_builder_append(u8 *str);
s32 get_help_text_string(s32 arg0);
s32 send_and_handle__6TLobbyFii(int, void *, int);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 try_equip_item__10TObjPlayerFii(s32, s32);
void play_sound_effect(s32, s32, s32, s32);
void TWindow__close(u8 *arg0);
// set_field_1c__6TLobbyFf declared above
s32 is_player_input_active(s32);
void call_if_split_screen(void *, s32);
f32 TWindowSubEquip__sub_80263AF8(u8 *arg0, u32 arg1);
s16 get_selected_menu_value(void *);
void *create_message_window__6TLobbyFllUls(s32, void *, s32, s32);
s32 update_selection__19TWindowSubTechniqueFPsPl(void *, void *, s32);
void get_current_selection__19TWindowSubTechniqueFPv(void *, void *, s32);
void rebuildTechniqueList__19TWindowSubTechniqueFll(void *, void *, s16);
void *create_title_window__19TWindowSubTechniqueFv(void *, s16);
extern u8 lbl_8044FC54[];
extern Pad_802870C4 controller_input_state[];
void *TWindowSubTechnique__ct(TWindowSubTechnique *arg0, s32 arg1, s32 arg2);
void *__dt__19TWindowSubTechniqueFv(TWindowSubTechnique *arg0, s16 arg1);
s32 __ct__7TObjectFP7TObject();
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
}
void text_builder_reset(void);
void toggle_help_window_on_button(u32 arg0, s32 arg1);
s32 create_titled_window_menu(s32, s32, s32, s32);
extern "C" {

s32 TWindowSubTechnique::open_menu() {
    s32 titled_window_menu;

    titled_window_menu = create_titled_window_menu(get_window_layout_position(0x12), 5, get_message_10__20TWindowSubStatusDispFl(0x2F), this->playerIndex);
    TWindowSubEquip__sub_80263AF8((u8 *)this->m_30, 0);
    set_field_1c__6TLobbyFf(titled_window_menu);
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit100();
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (int)(get_message_10__20TWindowSubStatusDispFl(0x9C)), 6, 0);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (int)(get_message_10__20TWindowSubStatusDispFl(0x9D)), 6, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (int)(get_message_10__20TWindowSubStatusDispFl(0x9E)), 6, 2);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (int)(get_message_10__20TWindowSubStatusDispFl(0x9F)), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii(titled_window_menu, (int)(get_message_10__20TWindowSubStatusDispFl(0xA0)), 6, 4);
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)titled_window_menu)->update_layout_height(179.0f);
    align_menu_entry_positions(titled_window_menu);
    return titled_window_menu;
}

static const char lbl_805DD83C[4] = "";

void TWindowSubTechnique::update_selected_help(s32 arg1) {
  s32 saved_reg_r30;
  s32 player;
  s32 tech;
  s32 cast_technique_level;
  tech = arg1;
  toggle_help_window_on_button((*(s32 *)&this->m_3c), (this->playerIndex));
  player = (s32)get_player_by_client_id((this->playerIndex));
  if (player != 0)
  {
    if (validate_and_clear_slot__10TObjPlayerFv((void *)(player + 0x428), (int) tech) != 0)
    {
      tech = 0x13;
      cast_technique_level = saved_reg_r30;
    }
    if (((s16) tech) != ((s16) (*(s16 *)&this->m_1e)))
    {
      *(s16 *)&this->m_1e = (s16) tech;
      if (((s16) tech) == 0x13)
      {
        send_and_handle__6TLobbyFii((int) (*(s32 *)&this->m_3c), (void *)lbl_805DD83C, 0x82);
        return;
      }
      text_builder_reset();
      if ((((s16) tech) != 0x11) && (((s16) tech) != 0xE))
      {
        cast_technique_level = get_cast_technique_level((void *)(player + 0x428), (int) tech);
        text_builder_append((u8 *)((int) TWindowSubTechnique__sub_8028753C(0x13)));
        TWindowSubStatusDisp__sub_80228F5C((((u8) cast_technique_level) + 1));
      }
      text_builder_append((u8 *)((int) get_help_text_string(0x2E)));
      TWindowSubStatusDisp__sub_80228F5C(((s32) (*((s16 *) (((s8 *) calc_technique_parameters((s16) tech, (u8) cast_technique_level, 0xFFFF)) + 0x10)))));
      text_builder_append((u8 *)((int) TWindowSubTechnique__sub_8028753C((s32)((int) ((s32) ((s16) tech))))));
      send_and_handle__6TLobbyFii((int) (*(s32 *)&this->m_3c), (void *) get_shared_text_buffer(), 0x82);
    }
  }
}

void TWindowSubTechnique::render() {  }

extern s32 __vt__19TWindowSubTechnique[];

void TWindowSubTechnique::run_task() {
    Tech_802870C4 *self = (Tech_802870C4 *)this;
    s32 port = is_player_input_active(self->player);
    s32 ply = (s32)get_player_by_client_id(self->player);
    switch (self->state) {
    case 0:
    case 1:
        if (self->help != 0) {
            TWindow__close((u8 *)self->help);
            self->help = 0;
            self->f1E = 0x13;
        }
        if (self->sel == 0) {
            self->sel = create_title_window__19TWindowSubTechniqueFv(self, get_selected_menu_value(self->list));
        }
        ((TAdChrSelASlotGC *)(self->sel))->set_flag_40();
        TQuestThread::set_status_flag_80(self->sel);
        get_current_selection__19TWindowSubTechniqueFPv(self->f20, self->f24, self->player);
        ((TWindowSubComCard *)(self->list))->clear_flag_and_release();
        self->state = 2;
    case 2: {
        s32 r = ((TWindowSubTechnique *)self)->sub_80286AA8();
        if (r == 1 || update_selection__19TWindowSubTechniqueFPsPl(self->f20, self->f24, self->player) != 0) {
            rebuildTechniqueList__19TWindowSubTechniqueFll(self, self->sel, get_selected_menu_value(self->list));
            if (r != 0) {
                ((TWindowSubComCardList *)(self->sel))->set_selected_index(0);
            }
        }
        if (((TWindowSubComCard *)(self->list))->get_status_flag() != 0) {
            self->f30->m7();
            self->state = 6;
        } else if (((TWindowMenu *)(self->list))->is_visible() != 0) {
            self->state = 3;
        }
        break;
    }
    case 3:
        self->help = create_message_window__6TLobbyFllUls(get_window_layout_position(0x14), lbl_8044FC54, 1, self->player);
        TWindowSubEquip__sub_80263AF8((u8 *)self->f30, 2);
        set_field_1c__6TLobbyFf((s32)self->help);
        call_if_split_screen(self->help, self->player);
        ((TWindowSubTradeMain *)(self->sel))->clear_trade_flag();
        ((TWindowSubTechnique *)(self->sel))->clear_flag70_bit80();
        ((TWindowSubComCard *)(self->sel))->clear_flag_and_release();
        ((TWindowOptionCtrl *)(self->sel))->clear_flag70_bit4();
        self->state = 4;
    case 4:
        ((TObjPlayer *)ply)->update_cursor(get_selected_menu_value(self->sel));
        if (update_selection__19TWindowSubTechniqueFPsPl(self->f20, self->f24, self->player) != 0) {
            rebuildTechniqueList__19TWindowSubTechniqueFll(self, self->sel, get_selected_menu_value(self->list));
        }
        update_selected_help(get_selected_menu_value(self->sel));
        if (((TWindowSubComCard *)(self->sel))->get_status_flag() != 0) {
            self->state = 1;
        }
        if (((TWindowMenu *)(self->sel))->is_visible() != 0) {
            self->state = 5;
        }
        break;
    case 5:
        ((TObjPlayer *)ply)->update_cursor(get_selected_menu_value(self->sel));
        if (TWindowSubTechnique::is_technique_available(get_selected_menu_value(self->sel), self->player) == 0 ||
            TWindowShortListCtrl__check_controller_button(controller_input_state[port].m20, 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].m20, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            rebuildTechniqueList__19TWindowSubTechniqueFll(self, self->sel, get_selected_menu_value(self->list));
            self->state = 1;
        } else if (try_equip_item__10TObjPlayerFii(ply, get_selected_menu_value(self->sel)) != 0) {
            self->state = 1;
        }
        break;
    case 6:
        break;
    }
}

void *__dt__19TWindowSubTechniqueFv(TWindowSubTechnique *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowSubTechnique;
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x3C))); arg0->m_3c = 0; }
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x38))); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)arg0 + 0x34))); arg0->m_34 = 0; }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TWindowSubTechnique__name;

void *TWindowSubTechnique__ct(TWindowSubTechnique *window_sub_technique, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_technique + 0x18) = __vt__19TWindowSubTechnique;
    *(s32 *)((s8 *)window_sub_technique + 0) = (s32) TWindowSubTechnique__name;
    window_sub_technique->m_30 = arg1;
    window_sub_technique->playerIndex = arg2;
    window_sub_technique->m_34 = window_sub_technique->open_menu();
    window_sub_technique->m_38 = 0;
    window_sub_technique->m_3c = 0;
    window_sub_technique->m_2c = -1;
    window_sub_technique->m_1e = 0x13;
    window_sub_technique->m_1c = 0;
    return window_sub_technique;
}

s32 TWindowSubTechnique__sub_8028753C(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x14)) + (arg0 * 4));
}

void TWindowSubTechnique::clear_flag70_bit80() { *(u16*)((char*)this + 0x70) &= 0xffffff7f; }
void TWindowSubTradeMain::clear_trade_flag() { this->m_70 &= 0xffffffbf; }
}
