#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemObject.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/unk/TBattleProximitySound.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/charcreate/PaletteCursorAction.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowLayout.h"


// Compared as a signed word here (cmpwi) while TWindowCtrl.cpp defines it as bool.
s32 is_com_card_window_open();

// The class name TObject::m_name points at.
const char *TWindowShortListCtrl::class_name = "TWindowShortListCtrl";

// Screen position of the list windows (from create_equip_kind_window / set_scroll_target use).
static const NJS_POINT2 short_list_window_pos = {308.0f, 124.0f};

// First run_task state of each page (from enter_page_first_state and run_task's case labels).
static const u8 page_first_state[4] = {0, 3, 6, 9};

s16 TWindowMenu::get_selected_index() { return marked_row; }

void TWindowMenu::update_cursor_pos() {
    marked_row = get_cursor_pos();
}

s16 TWindowMenu::get_cursor_pos() { return selected_row; }

void TWindowShortListCtrl::set_card_window_flags(saddr client_id, s32 page) {
    TWindowKeyBoardHard::set_card_window_flags(client_id, (s32)(page << 0x10), (s32)0xFFFCFFFF);
}

TWindowShortListCtrl::TWindowShortListCtrl(TObject *parent, s32 client_id) : TObject(parent) {
    m_name = TWindowShortListCtrl::class_name;
    this->client_id = client_id;
    TObjPlayer *player = get_player_by_client_id(this->client_id);
    if (player == NULL) {
        queue_destruction();
        return;
    }
    CharacterAppearanceFields *appearance = &player->appearance;
    if (appearance == NULL) {
        queue_destruction();
        return;
    }
    page = get_card_window_flags(this->client_id);
    if (page == 2 && is_technique_usable() == 0) {
        page++;
        if (page >= 4) {
            page -= 4;
        }
    }
    if ((appearance->classFlags & 0x10) && page == 3) {
        page++;
        if (page >= 4) {
            page -= 4;
        }
    }
    enter_page_first_state();
    timer = 0;
    tech_window = NULL;
    list_window = NULL;
    help_window = NULL;
    help_item_id = -1;
    TWindowCtrl::begin_client_keyboard_hold(this->client_id);
    TWindowCtrl::set_flag_active();
    player->reset_equip_slots();
}

TWindowShortListCtrl::~TWindowShortListCtrl() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL && TWindowCtrl::has_player_active_menu(client_id) == 0 && is_com_card_window_open() == 0) {
        player->init_parts();
    }
    TWindowCtrl::end_client_keyboard_hold(client_id);
    TWindowCtrl::clear_flag_8();
    if (help_window != NULL) {
        help_window->close();
        help_window = NULL;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
    if (tech_window != NULL) {
        tech_window->close();
        tech_window = NULL;
    }
}

void TWindowShortListCtrl::run_task() {
    s32 idx;
    TObjPlayer *player;
    s32 sel;
    idx = is_player_input_active(client_id);
    player = get_player_by_client_id(client_id);
    if ((timer > 2 && test_pressed_buttons_packed(&controller_input_state.controllers[idx], 0x200) != 0) || player == NULL) {
        queue_destruction();
        return;
    }
    cycle_list_page();
    switch (state) {
    case 0:
        if (list_window == NULL) {
            list_window = create_equip_kind_window(get_window_layout_position(1), &short_list_window_pos, client_id);
            list_window->set_flag70_bit10();
            list_window->refresh_weapon_shortcut_list();
            list_window->open_tick = 0x01000000;
        }
        state = 1;
    case 1:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 0x400) != 0) {
            if (help_window == NULL) {
                help_window = new TWindowHelpItem(get_window_layout_position(2), client_id);
                help_item_id = -1;
                TWindowCtrl::clear_flag_8();
            } else {
                help_window->close();
                help_window = NULL;
                TWindowCtrl::set_flag_active();
            }
        }
        set_displayed_item(list_window->get_cursor_value());
        if (list_window->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (list_window->is_decided() != 0) {
            state = 2;
        }
        break;
    case 2:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (TWindowSubItem::is_usable(player) == 0) {
            break;
        }
        assign_shortcut(6, list_window->get_cursor_value(), client_id);
        queue_destruction();
        return;
    case 3:
        if (list_window == NULL) {
            list_window = create_equip_kind_window(get_window_layout_position(1), &short_list_window_pos, client_id);
            list_window->set_flag70_bit10();
            list_window->refresh_item_shortcut_list();
            list_window->open_tick = 0x01000000;
        }
        state = 4;
    case 4:
        assign_item_to_palette(list_window->get_cursor_value(), client_id);
        if (list_window->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (list_window->is_decided() != 0) {
            state = 5;
        }
        break;
    case 5:
        assign_item_to_palette(list_window->get_cursor_value(), client_id);
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (TWindowSubItem::is_usable(player) == 0) {
            break;
        }
        sel = list_window->get_cursor_value();
        if (find_item_by_id(sel) == NULL) {
            return;
        }
        try_send_6x27_use_item(player, sel);
        queue_destruction();
        return;
    case 6:
        if (list_window == NULL) {
            list_window = create_equip_kind_window(get_window_layout_position(1), &short_list_window_pos, client_id);
            list_window->set_flag70_bit10();
            list_window->refresh_battle_stat_list();
            list_window->open_tick = 0x01000000;
        }
        state = 7;
    case 7:
        assign_item_to_palette(list_window->get_cursor_value(), client_id);
        if (list_window->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (list_window->is_decided() != 0) {
            state = 8;
        }
        break;
    case 8:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (TWindowSubItem::is_usable(player) == 0) {
            return;
        }
        sel = list_window->get_cursor_value();
        if ((sel & 0xF) == 4) {
            if (TBattleProximitySound::create() == 0) {
                break;
            }
            player->sonar_stock.consume(1);
            queue_destruction();
            return;
        }
        if (TWindowCtrl::is_client_countdown_done(client_id) == 0) {
            return;
        }
        player->send_trap_packet(sel & 0xF);
        queue_destruction();
        return;
    case 9:
        if (tech_window == NULL) {
            TWindowSubTechnique::get_current_selection(&shown_tp, &shown_hold_status, client_id);
            tech_window = create_window(get_window_layout_position(1), &short_list_window_pos);
        }
        tech_window->clear_flag_and_release();
        state = 10;
    case 10:
        player->update_cursor((s16)tech_window->get_selected_value());
        if (TWindowSubTechnique::update_selection(&shown_tp, &shown_hold_status, client_id) != 0) {
            refresh_technique_rows((saddr)tech_window, &short_list_window_pos);
        }
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 0x400) != 0) {
            if (tech_window->get_selected_index() == -1) {
                tech_window->update_cursor_pos();
            } else {
                swap_card_entries(tech_window->get_selected_index(), tech_window->get_cursor_pos());
                tech_window->reset_selection();
                refresh_technique_rows((saddr)tech_window, &short_list_window_pos);
            }
        }
        if (tech_window->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (tech_window->is_decided() != 0) {
            state = 11;
        }
        break;
    case 11:
        player->update_cursor((s16)tech_window->get_selected_value());
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (player->try_equip_item((s16)tech_window->get_selected_value()) != 0) {
            queue_destruction();
            return;
        }
        if (TWindowSubTechnique::is_technique_available((s16)tech_window->get_selected_value(), client_id) == 0) {
            refresh_technique_rows((saddr)tech_window, &short_list_window_pos);
            state = 9;
            return;
        }
        break;
    }
    timer++;
    if (timer < 0) {
        timer = 2;
    }
}

void TWindowShortListCtrl::render() {}

TWindowMenu *TWindowShortListCtrl::create_window(const NJS_POINT2 *position, const NJS_POINT2 *list_position) {
    TWindowMenu *window_menu;

    window_menu = (TWindowMenu *)create_window_menu(position, 0x13, client_id);
    window_menu->set_flag70_bit10();
    ((TWindowSubComCardList *)window_menu)->open_tick = 0x01000000;
    window_menu->set_flag70_bit100();
    refresh_technique_rows((saddr)window_menu, list_position);
    return window_menu;
}

void TWindowShortListCtrl::refresh_technique_rows(saddr tech_window, const NJS_POINT2 *position) {
    const NJS_POINT2 *pos = position;
    s32 i;
    s16 cur;
    s16 *order = get_character_save_record(client_id)->short_list_order;
    cur = ((TWindowMenu *)tech_window)->get_cursor_pos();
    ((TWindowMenu *)tech_window)->reset_entries();
    for (i = 0; i < 0x13; i++) {
        TWindowSubTechnique::draw_technique_row(order[i], client_id, tech_window);
    }
    ((TWindowMenu *)tech_window)->set_scroll_target(pos->x, pos->y);
    (reinterpret_cast<TWindowMenu *>(tech_window))->align_menu_entry_positions();
    ((TWindowMenu *)tech_window)->set_selected_index(cur);
}

void TWindowShortListCtrl::cycle_list_page() {
    s32 port = is_player_input_active(client_id);
    if (test_pressed_buttons_packed(&controller_input_state.controllers[port], get_control_button_mask(client_id)) != 0) {
        s8 old_page = page;
        TObjPlayer *player = get_player_by_client_id(client_id);
        if (player != NULL) {
            CharacterAppearanceFields *appearance = &player->appearance;
            if (appearance != NULL && help_window == NULL) {
                page++;
                if (page >= 4) {
                    page -= 4;
                }
                if (page == 2 && is_technique_usable() == 0) {
                    page++;
                    if (page >= 4) {
                        page -= 4;
                    }
                }
                if ((appearance->classFlags & 0x10) && page == 3) {
                    page++;
                    if (page >= 4) {
                        page -= 4;
                    }
                }
                if (old_page != page) {
                    set_card_window_flags(client_id, page);
                    destroy_children();
                    enter_page_first_state();
                }
            }
        }
    }
}

void TWindowShortListCtrl::enter_page_first_state() {
    state = page_first_state[page];
}

void TWindowShortListCtrl::destroy_children() {
    if (list_window != NULL) {
        list_window->queue_destruction();
        list_window = NULL;
    }
    if (tech_window != NULL) {
        tech_window->queue_destruction();
        tech_window = NULL;
    }
}

void TWindowShortListCtrl::assign_item_to_palette(u32 item_id, u32 client_id) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        TLockOnCursor *cursor = player->lock_on_cursor;
        if (cursor != NULL) {
            TItem *item = find_item_by_id(item_id);
            if (item != NULL && item->get_item_type() == 3) {
                s32 slot = get_tool_palette_index(item);
                if (slot != -1) {
                    if (canSetMenuCursorAction((PaletteCursorOverride *)&cursor->palette_override, player, 4, slot) != 0) {
                        set_action_palette_tag_mode(&cursor->palette_override, 4);
                        set_action_palette_tag_slot(&cursor->palette_override, slot);
                        set_action_channel_active(&cursor->palette_override);
                    }
                }
            }
        }
    }
}

void TWindowShortListCtrl::swap_card_entries(s32 index_a, s32 index_b) {
    s16 *p = get_character_save_record(client_id)->short_list_order;
    s16 t = p[index_a];
    p[index_a] = p[index_b];
    p[index_b] = t;
}

void init_default_short_list_order(s16 *dst) {
    s32 i;
    s16 order[19] = {0, 6, 3, 1, 7, 4, 2, 8, 5, 9, 0x12, 0xF, 0x10, 0x11, 0xD, 0xA, 0xB, 0xC, 0xE};
    for (i = 0; i < 19; i++) {
        dst[i] = order[i];
    }
}

s32 TWindowShortListCtrl::is_technique_usable() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    CharacterAppearanceFields *appearance = &player->appearance;
    if (appearance == NULL) {
        return 0;
    }
    if (TTecCtrl::is_technique_ready() != 0) {
        return 1;
    }
    return (appearance->classFlags >> 4) & 1;
}

void TWindowShortListCtrl::set_displayed_item(s32 item_id) {
    if (help_window != NULL && item_id != help_item_id) {
        help_item_id = item_id;
        help_window->set_displayed_item_by_id(item_id);
    }
}
