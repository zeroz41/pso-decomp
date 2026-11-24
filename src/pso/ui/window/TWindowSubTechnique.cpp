#include "pso/system/SoundEffect.h"
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
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/unk/text_80263A20.h"


extern "C" {
saddr get_window_layout_position(int);
}

const char *TWindowSubTechnique::class_name = "TWindowSubTechnique";
static const f32 technique_help_window_size[2] = { 242.0f, 161.0f };
/* technique ids per menu page, each ended by 19 (no technique) */
static const s16 technique_menu_category_0[] = { 0, 6, 3, 19 };
static const s16 technique_menu_category_1[] = { 1, 7, 4, 19 };
static const s16 technique_menu_category_2[] = { 2, 8, 5, 9, 18, 19 };
static const s16 technique_menu_category_3[] = { 15, 16, 17, 19 };
static const s16 technique_menu_category_4[] = { 13, 10, 11, 12, 14, 19 };
const s16 *technique_menu_category_lists[5] = { technique_menu_category_0, technique_menu_category_1, technique_menu_category_2, technique_menu_category_3, technique_menu_category_4 };

extern "C" {
s32 get_cursor_pos__20TWindowShortListCtrlFv(s32);
void set_selected_index__21TWindowSubComCardListFs(s32, s32);

s32 get_technique_name(s16);
s32 can_use_palette_action__10TObjPlayerFPvUcUc(u32, s32, u8);
s32 add_text_entry__11TWindowMenuFllll(s32, s32, s32, s16, s32);
s32 add_text_entry__11TWindowMenuFlll(s32, s32, s32, s16);

void TWindowSubTechnique::get_current_selection(s16 *arg0, s32 *arg1, s32 client) { TWindowSubTechnique::get_selection(arg0, arg1, client); }

s32 TWindowSubTechnique::is_technique_available(s32 sub, s32 client) {
    saddr player;
    player = (saddr)get_player_by_client_id(client);
    if (player == 0) {
        return 0;
    }
    if (is_current_area_item_enabled() == 0) {
        return 0;
    }
    if (TWindowSubTechnique::lookup_technique(sub, client) != 0) {
        return is_palette_entry_displayable__10TObjPlayerFv((u8 *)player, (u8)(3), (u8)((u8) sub));
    }
    return 0;
}

s32 TWindowSubTechnique::lookup_technique(s32 arg0, s32 client) {
    u32 temp = (uaddr)get_player_by_client_id(client);
    if (temp == 0U) {
        return 0;
    }
    return can_use_palette_action__10TObjPlayerFPvUcUc(temp, 3, (u8) arg0);
}
void TWindowSubTechnique::draw_technique_row(s32 id, s32 client, s32 list) {
    s32 technique_name;
    void add_gray_text_entry(s32, s32, s32, s16);

    technique_name = get_technique_name(id);
    if (TWindowSubTechnique::lookup_technique(id, client) == 0) {
        add_gray_text_entry(list, technique_name, 6, id);
        return;
    }
    if (TWindowSubTechnique::is_technique_available(id, client) == 0) {
        add_text_entry__11TWindowMenuFllll(list, technique_name, 0x16, id, 0xFFFD3901);
        return;
    }
    add_text_entry__11TWindowMenuFlll(list, technique_name, 6, id);
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

s32 TWindowSubTechnique::create_title_window(s32 category) {
  saddr titled_window_menu;
  titled_window_menu = create_titled_window_menu(get_window_layout_position(0x13), 5, (saddr)TWindowSubStatusDisp::get_message_10(0x30), playerIndex);
  ((TWindowBase *)titled_window_menu)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent_menu, 1));
  ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit100();
  ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
  return titled_window_menu;
}
}

extern u8 *text_language_group_table;
extern "C" {
saddr get_technique_description_text(s32 arg0);
u8 *calc_technique_parameters(s16, u8, s32);
s32 get_cast_technique_level(void *, int);
s32 validate_and_clear_slot__10TObjPlayerFPvs(void *, int);
}
extern "C" {
s32 try_equip_item__10TObjPlayerFii(saddr, s32);
}
void text_builder_reset(void);


s32 TWindowSubTechnique::open_menu() {
    saddr titled_window_menu;

    titled_window_menu = create_titled_window_menu(get_window_layout_position(0x12), 5, (saddr)TWindowSubStatusDisp::get_message_10(0x2F), this->playerIndex);
    ((TWindowBase *)titled_window_menu)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent_menu, 0));
    ((TWindowSubComCardList *)titled_window_menu)->set_flag70_bit100();
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x9C)), 6, 0);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x9D)), 6, 1);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x9E)), 6, 2);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x9F)), 6, 3);
    ((TWindowMenu *)titled_window_menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xA0)), 6, 4);
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
  toggle_help_window_on_button((uaddr)help_window, playerIndex);
  player = (saddr)get_player_by_client_id((this->playerIndex));
  if (player != 0)
  {
    if (validate_and_clear_slot__10TObjPlayerFPvs((void *)(player + 0x428), (int) tech) != 0)
    {
      tech = 0x13;
      cast_technique_level = saved_reg_r30;
    }
    if (((s16) tech) != ((s16) help_technique))
    {
      help_technique = (s16) tech;
      if (((s16) tech) == 0x13)
      {
        help_window->append_line((saddr)((void *)lbl_805DD83C), (int)0x82);
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
      help_window->append_line((saddr)((void *) get_shared_text_buffer()), (int)0x82);
    }
  }
}

void TWindowSubTechnique::render() {  }

void TWindowSubTechnique::run_task() {
    s32 port = is_player_input_active(playerIndex);
    TObjPlayer *player = get_player_by_client_id(playerIndex);
    switch (state) {
    case 0:
    case 1:
        if (help_window != NULL) {
            help_window->close();
            help_window = NULL;
            help_technique = 0x13;
        }
        if (technique_menu == 0) {
            technique_menu = (TWindowMenu *)create_title_window(category_menu->get_selected_value());
        }
        ((TWindowMenu *)technique_menu)->set_flag_40();
        TQuestThread::set_status_flag_80(technique_menu);
        TWindowSubTechnique::get_current_selection(&m_20, &m_24, playerIndex);
        category_menu->clear_flag_and_release();
        state = 2;
    case 2: {
        s32 r = category_changed();
        if (r == 1 || TWindowSubTechnique::update_selection(&m_20, &m_24, playerIndex) != 0) {
            rebuildTechniqueList((saddr)technique_menu, (s32)(category_menu->get_selected_value()));
            if (r != 0) {
                ((TWindowSubComCardList *)technique_menu)->set_selected_index(0);
            }
        }
        if (category_menu->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            state = 6;
        } else if (category_menu->is_decided() != 0) {
            state = 3;
        }
        break;
    }
    case 3:
        help_window = (TWindowMessage *)TWindowMessage::create((s32)(get_window_layout_position(0x14)), (const f32 *)technique_help_window_size, 1, (s32)playerIndex);
        ((TWindowBase *)help_window)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent_menu, 2));
        call_if_split_screen((uaddr)help_window, playerIndex);
        ((TWindowSubTradeMain *)technique_menu)->clear_trade_flag();
        ((TWindowSubTechnique *)technique_menu)->clear_flag70_bit80();
        technique_menu->clear_flag_and_release();
        ((TWindowOptionCtrl *)technique_menu)->clear_flag70_bit4();
        state = 4;
    case 4:
        player->update_cursor((s16)technique_menu->get_selected_value());
        if (TWindowSubTechnique::update_selection(&m_20, &m_24, playerIndex) != 0) {
            rebuildTechniqueList((saddr)technique_menu, (s32)(category_menu->get_selected_value()));
        }
        update_selected_help((s16)technique_menu->get_selected_value());
        if (technique_menu->is_cancelled() != 0) {
            state = 1;
        }
        if (technique_menu->is_decided() != 0) {
            state = 5;
        }
        break;
    case 5:
        player->update_cursor((s16)technique_menu->get_selected_value());
        if (TWindowSubTechnique::is_technique_available((s16)technique_menu->get_selected_value(), playerIndex) == 0 ||
            test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            rebuildTechniqueList((saddr)technique_menu, (s32)(category_menu->get_selected_value()));
            state = 1;
        } else if (try_equip_item__10TObjPlayerFii((saddr)player, (s16)technique_menu->get_selected_value()) != 0) {
            state = 1;
        }
        break;
    case 6:
        break;
    }
}

TWindowSubTechnique::~TWindowSubTechnique() {
    if (help_window != NULL) {
        help_window->close();
        help_window = NULL;
    }
    if (technique_menu != NULL) {
        technique_menu->close();
        technique_menu = NULL;
    }
    if (category_menu != NULL) {
        category_menu->close();
        category_menu = NULL;
    }
}



TWindowSubTechnique::TWindowSubTechnique(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    parent_menu = parent;
    playerIndex = client;
    category_menu = (TWindowMenu *)open_menu();
    technique_menu = NULL;
    help_window = NULL;
    current_category = -1;
    help_technique = 0x13;
    state = 0;
}

saddr get_technique_description_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x14)) + (arg0 * 4));
}

void TWindowSubTechnique::clear_flag70_bit80() { *(u16*)((char*)this + 0x70) &= 0xffffff7f; }
void TWindowSubTradeMain::clear_trade_flag() { this->m_70 &= 0xffffffbf; }
