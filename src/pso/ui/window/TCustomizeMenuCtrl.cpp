#pragma defer_codegen on

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCardEntries.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/chat/SymbolChatCommand.h"
#include "pso/ui/window/HelpWindowToggle.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TCustomizeMenuCtrl.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/player/PlayerSlots.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/enemy/BattleParamTables.h"


extern "C" {
u8 get_cast_technique_level(void *, s16);
}

extern "C" {
extern const f32 customize_help_window_size[2] = {190.0f, 168.0f};
}

TCustomizeMenuCtrl::TCustomizeMenuCtrl(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    main_menu = parent;
    client_id = client;
    custom_equip = (uaddr)new TWindowSubCustomEquip(client_id);
    ((TWindowBase *)custom_equip)->set_depth(get_main_menu_layer_depth((u8 *)main_menu, 0));
    help_window = TWindowMessage::create(get_window_layout_position(0x11), customize_help_window_size, 1, client_id);
    help_window->set_depth(get_main_menu_layer_depth((u8 *)main_menu, 2));
    call_if_split_screen(help_window, client_id);
    custom_select = NULL;
    help_kind = 0;
    help_id = 0;
    state = 0;
}

TCustomizeMenuCtrl::~TCustomizeMenuCtrl() {
    if (custom_select != NULL) {
        custom_select->close();
        custom_select = NULL;
    }
    if (help_window != NULL) {
        help_window->close();
        help_window = NULL;
    }
    if ((void *)custom_equip != NULL) {
        ((TWindowBase *)custom_equip)->close();
        custom_equip = 0;
    }
}

void TCustomizeMenuCtrl::run_task() {
    PaletteAction ev;
    switch (state) {
    case 0:
    case 1:
        if (custom_select != NULL) {
            custom_select->close();
            custom_select = NULL;
        }
        ((TWindowSubCustomEquip *)(this->custom_equip))->clear_flag_and_set_entry_state();
        state = 2;
    case 2:
        ((TWindowSubCustomEquip *)(this->custom_equip))->get_cursor_pos(&ev);
        update_customize_help_text(&ev);
        if (is_custom_equip_cancelled((void *)this->custom_equip) != 0) {
            main_menu->on_submenu_closed();
            state = 5;
        } else if (((TWindowSubCustomEquip *)(this->custom_equip))->is_selected() != 0) {
            state = 3;
        }
        break;
    case 3:
        custom_select = new TWindowSubCustomSelect(client_id);
        custom_select->set_depth(get_main_menu_layer_depth((u8 *)main_menu, 1));
        state = 4;
    case 4:
        update_customize_help_text(custom_select->get_selected_action());
        if (custom_select->is_cancelled() != 0) {
            state = 1;
        }
        if (custom_select->is_active() != 0) {
            PaletteAction *e = const_cast<PaletteAction *>(custom_select->get_selected_action());
            ((TWindowSubCustomEquip *)(this->custom_equip))->toggle_action_binding(e);
            state = 1;
        }
        break;
    case 5:
        break;
    }
}

void TCustomizeMenuCtrl::render() {  }

void TCustomizeMenuCtrl::update_customize_help_text(const PaletteAction *ev) {
    TObjPlayer *pl;
    s32 lvl;
    toggle_help_window_on_button(help_window, client_id);
    if (ev == NULL) {
        return;
    }
    pl = get_player_by_client_id(client_id);
    if (pl == NULL) {
        return;
    }
    if (help_id == ev->slot && help_kind == ev->mode) {
        return;
    }
    help_kind = ev->mode;
    help_id = ev->slot;
    text_builder_reset();
    switch (ev->mode) {
    case 0:
        break;
    case 2:
        if (ev->slot == 2) {
            TItem *weapon = TObjPlayer::get_equipped_weapon(pl);
            if (weapon == NULL || weapon_has_extra_attack((TItemWeapon *)weapon) != 1) {
                break;
            }
        }
        text_builder_append(get_help_text_string(ev->slot + 0x13));
        break;
    case 3:
        if (TObjPlayer::validate_and_clear_slot(&pl->technique_state, ev->slot) != 0) {
            break;
        }
        text_builder_append(get_technique_name(ev->slot));
        if (ev->slot != 0x11 && ev->slot != 0xE) {
            lvl = get_cast_technique_level(&pl->technique_state, ev->slot);
            if (current_language != LANGUAGE_JAPANESE) {
                append_text_space();
            }
            text_builder_append(get_help_text_string(0x2D));
            text_builder_append_int(lvl + 1);
        }
        text_builder_append(get_help_text_string(0x2E));
        text_builder_append_int(calc_technique_parameters(ev->slot, lvl, 0xFFFF)->tp_cost);
        text_builder_append(get_help_text_string(ev->slot));
        break;
    case 4:
        if (get_palette_consumable_count(ev->slot, client_id) == -1) {
            break;
        }
        text_builder_append(get_help_text_string(ev->slot + 0x16));
        break;
    case 7:
        break;
    }
    help_window->append_line(get_shared_text_buffer(), 0x82);
}
