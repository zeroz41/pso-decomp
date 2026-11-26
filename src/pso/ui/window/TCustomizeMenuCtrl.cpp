#pragma defer_codegen on

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubCustomEquip_80275D9C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/unk/text_80076E84.h"
#include "pso/unk/text_80263A20.h"
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
#include "pso/unk/TLobby_8001D6A0.h"


struct RunTaskEv {
    u16 kind;
    u16 id;
};

extern "C" {
u8 get_cast_technique_level(void *, s16);
void text_builder_append_int(s32);
void text_builder_append();
}

void text_builder_reset();

extern "C" {
extern const f32 lbl_8044F718[2] = {190.0f, 168.0f};
}

TCustomizeMenuCtrl::TCustomizeMenuCtrl(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    main_menu = parent;
    client_id = client;
    custom_equip = (uaddr)new TWindowSubCustomEquip(client_id);
    ((TWindowBase *)custom_equip)->set_depth(get_main_menu_layer_depth((u8 *)main_menu, 0));
    help_window = (uaddr)TWindowMessage::create(get_window_layout_position(0x11), lbl_8044F718, 1, client_id);
    ((TWindowBase *)help_window)->set_depth(get_main_menu_layer_depth((u8 *)main_menu, 2));
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
    if ((void *)help_window != NULL) {
        ((TWindowBase *)help_window)->close();
        help_window = 0;
    }
    if ((void *)custom_equip != NULL) {
        ((TWindowBase *)custom_equip)->close();
        custom_equip = 0;
    }
}

void TCustomizeMenuCtrl::run_task() {
    RunTaskEv ev;
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
        if (TWindowSubCustomEquip__sub_80275DA8((void *)this->custom_equip) != 0) {
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
            void *e = custom_select->get_selected_action();
            ((TWindowSubCustomEquip *)(this->custom_equip))->toggle_action_binding(e);
            state = 1;
        }
        break;
    case 5:
        break;
    }
}

void TCustomizeMenuCtrl::render() {  }

void TCustomizeMenuCtrl::update_customize_help_text(void *ev_arg) {
    RunTaskEv *ev = (RunTaskEv *)ev_arg;
    u8 *pl;
    s32 lvl;
    toggle_help_window_on_button(help_window, client_id);
    if (ev == NULL) {
        return;
    }
    pl = (u8 *)get_player_by_client_id(client_id);
    if (pl == NULL) {
        return;
    }
    if (help_id == ev->id && help_kind == ev->kind) {
        return;
    }
    help_kind = ev->kind;
    help_id = ev->id;
    text_builder_reset();
    switch (ev->kind) {
    case 0:
        break;
    case 2:
        if (ev->id == 2) {
            TItem *weapon = TObjPlayer::get_equipped_weapon(pl);
            if (weapon == NULL || weapon_has_extra_attack((TItemWeapon *)weapon) != 1) {
                break;
            }
        }
        get_help_text_string(ev->id + 0x13);
        text_builder_append();
        break;
    case 3:
        if (TObjPlayer::validate_and_clear_slot(pl + 0x428, ev->id) != 0) {
            break;
        }
        get_technique_name(ev->id);
        text_builder_append();
        if (ev->id != 0x11 && ev->id != 0xE) {
            lvl = get_cast_technique_level(pl + 0x428, ev->id);
            if (current_language != LANGUAGE_JAPANESE) {
                append_text_space();
            }
            get_help_text_string(0x2D);
            text_builder_append();
            text_builder_append_int(lvl + 1);
        }
        get_help_text_string(0x2E);
        text_builder_append();
        text_builder_append_int(calc_technique_parameters(ev->id, lvl, 0xFFFF)->tp_cost);
        get_help_text_string(ev->id);
        text_builder_append();
        break;
    case 4:
        if (get_palette_consumable_count(ev->id, client_id) == -1) {
            break;
        }
        get_help_text_string(ev->id + 0x16);
        text_builder_append();
        break;
    case 7:
        break;
    }
    ((TWindowMessage *)(help_window))->append_line((saddr)get_shared_text_buffer(), 0x82);
}
