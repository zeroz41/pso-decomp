#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubTechnique_80286BD4.h"
#include "pso/ui/window/TWindowSubComCardList.h"

#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"


extern "C" {
void *get_player_by_client_id(s32 i);
s32 set_depth__11TWindowBaseFf(int);
}
saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr arg2, s32 arg3);
extern "C" {
saddr get_window_layout_position(int);
const char *TWindowSubTechnique__name = "TWindowSubTechnique";
static const f32 technique_help_window_size[2] = { 242.0f, 161.0f };
/* technique ids per menu page, each ended by 19 (no technique) */
static const s16 technique_menu_category_0[] = { 0, 6, 3, 19 };
static const s16 technique_menu_category_1[] = { 1, 7, 4, 19 };
static const s16 technique_menu_category_2[] = { 2, 8, 5, 9, 18, 19 };
static const s16 technique_menu_category_3[] = { 15, 16, 17, 19 };
static const s16 technique_menu_category_4[] = { 13, 10, 11, 12, 14, 19 };
const s16 *technique_menu_category_lists[5] = { technique_menu_category_0, technique_menu_category_1, technique_menu_category_2, technique_menu_category_3, technique_menu_category_4 };

s32 get_cursor_pos__20TWindowShortListCtrlFv(s32);
void set_selected_index__21TWindowSubComCardListFs(s32, s32);

s32 get_technique_name(s16);
s32 can_use_palette_action__10TObjPlayerFPvUcUc(u32, s32, u8);
s32 add_text_entry__19TWindowSubTradeMainFllll(s32, s32, s32, s16, s32);

s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s16);

void TWindowSubTechnique::get_current_selection(s16 *arg0, s32 *arg1, s32 client) { TWindowSubTechnique::get_selection(arg0, arg1, client); }

s32 TWindowSubTechnique::is_technique_available(s32 sub, s32 arg1) {
    saddr player;
    player = ((saddr)get_player_by_client_id(arg1));
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
    u32 temp = (uaddr)get_player_by_client_id(arg1);
    if (temp == 0U) {
        return 0;
    }
    return can_use_palette_action__10TObjPlayerFPvUcUc(temp, 3, (u8) arg0);
}
void TWindowSubTechnique::draw_technique_row(s32 id, s32 arg1, s32 list) {
    s32 technique_name;
    void add_gray_text_entry(s32, s32, s32, s16);

    technique_name = get_technique_name(id);
    if (TWindowSubTechnique::lookup_technique(id, arg1) == 0) {
        add_gray_text_entry(list, technique_name, 6, id);
        return;
    }
    if (TWindowSubTechnique::is_technique_available(id, arg1) == 0) {
        add_text_entry__19TWindowSubTradeMainFllll(list, technique_name, 0x16, id, 0xFFFD3901);
        return;
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(list, technique_name, 6, id);
}
#pragma fp_contract on

void TWindowSubTechnique::rebuildTechniqueList(saddr list, s32 category) {
    s32 selected;
    const s16 *entry;
    entry = technique_menu_category_lists[category];
    selected = get_cursor_pos__20TWindowShortListCtrlFv(list);
    ((TWindowSubComCardList *)list)->reset_entries();
    while (*entry != 19) {
        TWindowSubTechnique::draw_technique_row(*entry, playerIndex, list);
        ++entry;
    }
    ((TWindowMenu *)list)->update_layout_height(179.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    set_selected_index__21TWindowSubComCardListFs(list, selected);
}

s32 TWindowSubTechnique::create_title_window() {
  saddr titled_window_menu;
  titled_window_menu = create_titled_window_menu((int) get_window_layout_position(0x13), 5, (0, (saddr)TWindowSubStatusDisp::get_message_10(0x30)), (this->playerIndex));
  TWindowSubEquip__sub_80263AF8((u8 *)this->m_30, 1);
  set_depth__11TWindowBaseFf((int) titled_window_menu);
  ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit100();
  ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
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

extern u8 *text_language_group_table;
extern "C" {
saddr get_technique_description_text(s32 arg0);
u8 *calc_technique_parameters(s16, u8, s32);
s32 get_cast_technique_level(void *, int);
s32 validate_and_clear_slot__10TObjPlayerFPvs(void *, int);
}
saddr get_help_text_string(s32 arg0);
extern "C" {
s32 try_equip_item__10TObjPlayerFii(saddr, s32);
void play_sound_effect(s32, s32, s32, s32);
// set_depth__11TWindowBaseFf declared above
void *create_title_window__19TWindowSubTechniqueFv(void *, s32);
void *TWindowSubTechnique__ct(TWindowSubTechnique *arg0, s32 arg1, s32 arg2);
s32 __ct__7TObjectFP7TObject();
}
void text_builder_reset(void);
void toggle_help_window_on_button(uaddr arg0, s32 arg1);
saddr create_titled_window_menu(saddr, s32, saddr, s32);


s32 TWindowSubTechnique::open_menu() {
    saddr titled_window_menu;

    titled_window_menu = create_titled_window_menu(get_window_layout_position(0x12), 5, (saddr)TWindowSubStatusDisp::get_message_10(0x2F), this->playerIndex);
    TWindowSubEquip__sub_80263AF8((u8 *)this->m_30, 0);
    set_depth__11TWindowBaseFf(titled_window_menu);
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit100();
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)(TWindowSubStatusDisp::get_message_10(0x9C)), 6, 0);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)(TWindowSubStatusDisp::get_message_10(0x9D)), 6, 1);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)(TWindowSubStatusDisp::get_message_10(0x9E)), 6, 2);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)(TWindowSubStatusDisp::get_message_10(0x9F)), 6, 3);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)(TWindowSubStatusDisp::get_message_10(0xA0)), 6, 4);
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(179.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    return titled_window_menu;
}

static const char lbl_805DD83C[4] = "";

void TWindowSubTechnique::update_selected_help(s32 arg1) {
  s32 saved_reg_r30;
  saddr player;
  s32 tech;
  s32 cast_technique_level;
  tech = arg1;
  toggle_help_window_on_button((*(s32 *)&this->m_3c), (this->playerIndex));
  player = (saddr)get_player_by_client_id((this->playerIndex));
  if (player != 0)
  {
    if (validate_and_clear_slot__10TObjPlayerFPvs((void *)(player + 0x428), (int) tech) != 0)
    {
      tech = 0x13;
      cast_technique_level = saved_reg_r30;
    }
    if (((s16) tech) != ((s16) (*(s16 *)&this->m_1e)))
    {
      *(s16 *)&this->m_1e = (s16) tech;
      if (((s16) tech) == 0x13)
      {
        ((TWindowMessage *)(*(saddr *)&this->m_3c))->append_line((saddr)((void *)lbl_805DD83C), (int)0x82);
        return;
      }
      text_builder_reset();
      if ((((s16) tech) != 0x11) && (((s16) tech) != 0xE))
      {
        cast_technique_level = get_cast_technique_level((void *)(player + 0x428), (int) tech);
        text_builder_append((u8 *)((saddr) get_technique_description_text(0x13)));
        text_builder_append_int((((u8) cast_technique_level) + 1));
      }
      text_builder_append((u8 *)((saddr) get_help_text_string(0x2E)));
      text_builder_append_int(((s32) (*((s16 *) (((s8 *) calc_technique_parameters((s16) tech, (u8) cast_technique_level, 0xFFFF)) + 0x10)))));
      text_builder_append((u8 *)((saddr) get_technique_description_text((s32)((int) ((s32) ((s16) tech))))));
      ((TWindowMessage *)(*(saddr *)&this->m_3c))->append_line((saddr)((void *) get_shared_text_buffer()), (int)0x82);
    }
  }
}

void TWindowSubTechnique::render() {  }

extern s32 __vt__19TWindowSubTechnique[];

void TWindowSubTechnique::run_task() {
    Tech_802870C4 *self = (Tech_802870C4 *)this;
    s32 port = is_player_input_active(self->player);
    saddr ply = (saddr)get_player_by_client_id(self->player);
    switch (self->state) {
    case 0:
    case 1:
        if (self->help != 0) {
            ((TWindowBase *)self->help)->close();
            self->help = 0;
            self->f1E = 0x13;
        }
        if (self->sel == 0) {
            self->sel = create_title_window__19TWindowSubTechniqueFv(self, ((TWindowMenu *)self->list)->get_selected_value());
        }
        ((TAdChrSelASlotGC *)(self->sel))->set_flag_40();
        TQuestThread::set_status_flag_80(self->sel);
        TWindowSubTechnique::get_current_selection((s16 *)self->f20, (s32 *)self->f24, self->player);
        ((TWindowSubComCard *)(self->list))->clear_flag_and_release();
        self->state = 2;
    case 2: {
        s32 r = ((TWindowSubTechnique *)self)->sub_80286AA8();
        if (r == 1 || TWindowSubTechnique::update_selection((s16 *)self->f20, (s32 *)self->f24, self->player) != 0) {
            ((TWindowSubTechnique *)self)->rebuildTechniqueList((saddr)(self->sel), (s32)(((TWindowMenu *)self->list)->get_selected_value()));
            if (r != 0) {
                ((TWindowSubComCardList *)(self->sel))->set_selected_index(0);
            }
        }
        if (((TWindowMenu *)(self->list))->is_cancelled() != 0) {
            self->f30->m7();
            self->state = 6;
        } else if (((TWindowMenu *)(self->list))->is_decided() != 0) {
            self->state = 3;
        }
        break;
    }
    case 3:
        self->help = TWindowMessage::create((s32)(get_window_layout_position(0x14)), (const f32 *)technique_help_window_size, 1, (s32)self->player);
        TWindowSubEquip__sub_80263AF8((u8 *)self->f30, 2);
        set_depth__11TWindowBaseFf((saddr)self->help);
        call_if_split_screen((uaddr)self->help, self->player);
        ((TWindowSubTradeMain *)(self->sel))->clear_trade_flag();
        ((TWindowSubTechnique *)(self->sel))->clear_flag70_bit80();
        ((TWindowSubComCard *)(self->sel))->clear_flag_and_release();
        ((TWindowOptionCtrl *)(self->sel))->clear_flag70_bit4();
        self->state = 4;
    case 4:
        ((TObjPlayer *)ply)->update_cursor((s16)((TWindowMenu *)self->sel)->get_selected_value());
        if (TWindowSubTechnique::update_selection((s16 *)self->f20, (s32 *)self->f24, self->player) != 0) {
            ((TWindowSubTechnique *)self)->rebuildTechniqueList((saddr)(self->sel), (s32)(((TWindowMenu *)self->list)->get_selected_value()));
        }
        update_selected_help((s16)((TWindowMenu *)self->sel)->get_selected_value());
        if (((TWindowMenu *)(self->sel))->is_cancelled() != 0) {
            self->state = 1;
        }
        if (((TWindowMenu *)(self->sel))->is_decided() != 0) {
            self->state = 5;
        }
        break;
    case 5:
        ((TObjPlayer *)ply)->update_cursor((s16)((TWindowMenu *)self->sel)->get_selected_value());
        if (TWindowSubTechnique::is_technique_available((s16)((TWindowMenu *)self->sel)->get_selected_value(), self->player) == 0 ||
            test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            ((TWindowSubTechnique *)self)->rebuildTechniqueList((saddr)(self->sel), (s32)(((TWindowMenu *)self->list)->get_selected_value()));
            self->state = 1;
        } else if (try_equip_item__10TObjPlayerFii(ply, (s16)((TWindowMenu *)self->sel)->get_selected_value()) != 0) {
            self->state = 1;
        }
        break;
    case 6:
        break;
    }
}

TWindowSubTechnique::~TWindowSubTechnique() {
    if (*(void **)((s8 *)this + 0x3C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x3C)))->close(); this->m_3c = 0; }
    if (*(void **)((s8 *)this + 0x38) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close(); this->m_38 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close(); this->m_34 = 0; }
}



void *TWindowSubTechnique__ct(TWindowSubTechnique *window_sub_technique, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)window_sub_technique + 0x18) = __vt__19TWindowSubTechnique;
    *(s32 *)((s8 *)window_sub_technique + 0) = (saddr) TWindowSubTechnique__name;
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

saddr get_technique_description_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x14)) + (arg0 * 4));
}

void TWindowSubTechnique::clear_flag70_bit80() { *(u16*)((char*)this + 0x70) &= 0xffffff7f; }
void TWindowSubTradeMain::clear_trade_flag() { this->m_70 &= 0xffffffbf; }
