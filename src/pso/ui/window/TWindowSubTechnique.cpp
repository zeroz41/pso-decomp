#include "pso/system/TLanguage.h"
#include "types.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubTradeMain.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/ControllerInput.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/HelpWindowToggle.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/technique/TechniqueParams.h"

s32 TWindowSubTechnique::category_changed() {
    if (category_menu == NULL) {
        return 0;
    }
    if (current_category == category_menu->get_selected_value()) {
        return 0;
    }
    current_category = category_menu->get_selected_value();
    return 1;
}

void TWindowSubTechnique::get_selection(s16 *tp, s32 *hold_status, s32 client) {
    TObjPlayer *player;

    player = get_player_by_client_id(client);
    if (player != NULL) {
        *tp = player->tp;
        *hold_status = player->update_action_hold_status();
    }
}

s32 TWindowSubTechnique::update_selection(s16 *tp, s32 *hold_status, s32 client) {
    s32 new_hold_status;
    s16 new_tp;

    TWindowSubTechnique::get_selection(&new_tp, &new_hold_status, client);
    if ((new_tp == *tp) && (new_hold_status == *hold_status)) {
        return 0;
    }
    *tp = new_tp;
    *hold_status = new_hold_status;
    return 1;
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

void TWindowSubTechnique::get_current_selection(s16 *tp, s32 *hold_status, s32 client) {
    TWindowSubTechnique::get_selection(tp, hold_status, client);
}

s32 TWindowSubTechnique::is_technique_available(s32 sub, s32 client) {
    TObjPlayer *player;
    player = get_player_by_client_id(client);
    if (player == NULL) {
        return 0;
    }
    if (is_current_area_item_enabled() == 0) {
        return 0;
    }
    if (TWindowSubTechnique::lookup_technique(sub, client) != 0) {
        return player->is_palette_entry_displayable(3, sub);
    }
    return 0;
}

s32 TWindowSubTechnique::lookup_technique(s32 technique, s32 client) {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player == NULL) {
        return 0;
    }
    return player->can_use_palette_action(3, technique);
}
// CodeWarrior: the original passes the technique id to these four callees as a short.
#ifdef __MWERKS__
extern "C" {
s32 add_text_entry__11TWindowMenuFPCclll(saddr, const char *, s32, s16, s32);
s32 add_text_entry__11TWindowMenuFPCcll(saddr, const char *, s32, s16);
const char *get_technique_name(s16);

void TWindowSubTechnique::draw_technique_row(s32 id, s32 client, saddr list) {
    const char *technique_name;
    void add_gray_text_entry(saddr, const char *, s32, s16);

    technique_name = get_technique_name(id);
    if (TWindowSubTechnique::lookup_technique(id, client) == 0) {
        add_gray_text_entry(list, technique_name, 6, id);
        return;
    }
    if (TWindowSubTechnique::is_technique_available(id, client) == 0) {
        add_text_entry__11TWindowMenuFPCclll(list, technique_name, 0x16, id, 0xFFFD3901);
        return;
    }
    add_text_entry__11TWindowMenuFPCcll(list, technique_name, 6, id);
}
}
#else
#include "pso/ui/chat/SymbolChatCommand.h"

void TWindowSubTechnique::draw_technique_row(s32 id, s32 client, saddr list) {
    const char *technique_name;

    technique_name = get_technique_name(id);
    if (TWindowSubTechnique::lookup_technique(id, client) == 0) {
        add_gray_text_entry((TWindowMenu *)list, technique_name, 6, id);
        return;
    }
    if (TWindowSubTechnique::is_technique_available(id, client) == 0) {
        ((TWindowMenu *)list)->add_text_entry(technique_name, 0x16, id, 0xFFFD3901);
        return;
    }
    ((TWindowMenu *)list)->add_text_entry(technique_name, 6, id);
}
#endif
#pragma fp_contract on

void TWindowSubTechnique::rebuildTechniqueList(saddr list, s32 category) {
    s16 selected;
    const s16 *entry;
    entry = technique_menu_category_lists[category];
    selected = ((TWindowMenu *)list)->get_cursor_pos();
    ((TWindowMenu *)list)->reset_entries();
    while (*entry != 19) {
        TWindowSubTechnique::draw_technique_row(*entry, playerIndex, list);
        ++entry;
    }
    ((TWindowMenu *)list)->update_layout_height(179.0f);
    (reinterpret_cast<TWindowMenu *>(list))->align_menu_entry_positions();
    ((TWindowMenu *)list)->set_selected_index(selected);
}

TWindowMenu *TWindowSubTechnique::create_title_window(s32 category) {
  TWindowMenu *titled_window_menu;
  titled_window_menu = create_titled_window_menu(get_window_layout_position(0x13), 5, TWindowSubStatusDisp::get_message_10(0x30), playerIndex);
  titled_window_menu->set_depth(get_main_menu_layer_depth((u8 *)parent_menu, 1));
  titled_window_menu->set_flag70_bit100();
  titled_window_menu->set_flag70_bit10();
  return titled_window_menu;
}


TWindowMenu *TWindowSubTechnique::open_menu() {
    TWindowMenu *titled_window_menu;

    titled_window_menu = create_titled_window_menu(get_window_layout_position(0x12), 5, TWindowSubStatusDisp::get_message_10(0x2F), this->playerIndex);
    titled_window_menu->set_depth(get_main_menu_layer_depth((u8 *)parent_menu, 0));
    titled_window_menu->set_flag70_bit100();
    titled_window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0x9C)), 6, 0);
    titled_window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0x9D)), 6, 1);
    titled_window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0x9E)), 6, 2);
    titled_window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0x9F)), 6, 3);
    titled_window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0xA0)), 6, 4);
    titled_window_menu->set_flag70_bit10();
    titled_window_menu->update_layout_height(179.0f);
    titled_window_menu->align_menu_entry_positions();
    return titled_window_menu;
}

static const char technique_empty_line[4] = "";

void TWindowSubTechnique::update_selected_help(s16 technique) {
  TObjPlayer *player;
  u8 cast_technique_level;
  toggle_help_window_on_button(help_window, playerIndex);
  player = get_player_by_client_id(this->playerIndex);
  if (player != NULL)
  {
    if (TObjPlayer::validate_and_clear_slot(&player->technique_state, technique) != 0)
    {
      technique = 0x13;
    }
    if (technique != ((s16) help_technique))
    {
      help_technique = technique;
      if (technique == 0x13)
      {
        help_window->append_line(technique_empty_line, 0x82);
        return;
      }
      text_builder_reset();
      if ((technique != 0x11) && (technique != 0xE))
      {
        cast_technique_level = player->technique_state.get_cast_technique_level(technique);
        text_builder_append((const char *)((saddr) get_technique_description_text(0x13)));
        text_builder_append_int(cast_technique_level + 1);
      }
      text_builder_append(get_help_text_string(0x2E));
      text_builder_append_int(calc_technique_parameters(technique, cast_technique_level, 0xFFFF)->tp_cost);
      text_builder_append((const char *)((saddr) get_technique_description_text(technique)));
      help_window->append_line(get_shared_text_buffer(), 0x82);
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
            technique_menu = create_title_window(category_menu->get_selected_value());
        }
        technique_menu->disable_input();
        technique_menu->set_status_flag_80();
        TWindowSubTechnique::get_current_selection(&shown_tp, &shown_hold_status, playerIndex);
        category_menu->clear_flag_and_release();
        state = 2;
    case 2: {
        s32 r = category_changed();
        if (r == 1 || TWindowSubTechnique::update_selection(&shown_tp, &shown_hold_status, playerIndex) != 0) {
            rebuildTechniqueList((saddr)technique_menu, (s32)(category_menu->get_selected_value()));
            if (r != 0) {
                technique_menu->set_selected_index(0);
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
        help_window = TWindowMessage::create(get_window_layout_position(0x14), technique_help_window_size, 1, (s32)playerIndex);
        help_window->set_depth(get_main_menu_layer_depth((u8 *)parent_menu, 2));
        call_if_split_screen(help_window, playerIndex);
        technique_menu->enable_input();
        technique_menu->show_selection_highlight();
        technique_menu->clear_flag_and_release();
        technique_menu->clear_cancelled();
        state = 4;
    case 4:
        player->update_cursor((s16)technique_menu->get_selected_value());
        if (TWindowSubTechnique::update_selection(&shown_tp, &shown_hold_status, playerIndex) != 0) {
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
        } else if (player->try_equip_item((s16)technique_menu->get_selected_value()) != 0) {
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
    category_menu = open_menu();
    technique_menu = NULL;
    help_window = NULL;
    current_category = -1;
    help_technique = 0x13;
    state = 0;
}

saddr get_technique_description_text(s32 technique) {
    return (saddr)text_language_group_table[5][technique];
}

void TWindowMenu::show_selection_highlight() { menu_flags &= ~0x80; }
void TWindowMenu::enable_input() { menu_flags &= ~0x40; }
