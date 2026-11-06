#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemObject.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
s32 canSetMenuCursorAction(s32, s32, u8, u8);
void TMainCursor__sub_8013DFC4(u8 *arg0);
s32 fn_8002AE08(int);
s32 TWindowShortListCtrl__check_controller_button(ControllerInputContext *, int);
s32 is_player_input_active(s32 param_1);
s32 get_character_save_record(u32 arg0);
void align_menu_entry_positions(void *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(ControllerInputContext *, int);
s32 try_send_6x27_use_item(void *arg0, s32 arg1);
s32 decrement_clamped(s32 *arg0, s32 arg1);
s32 try_equip_item__10TObjPlayerFii(u8 *, s32);
void play_sound_effect(int, int, int, int);
void *__nw__7TObjectFUl(u32);
s32 TWindowCtrl__sub_8024A228(s32);
void *__ct__15TWindowHelpItemFPvUs(void *, s32, s32);
s32 get_cursor_value__19TWindowMenuIconLineFv(void *);
s32 get_window_layout_position(int);
void *create_equip_kind_window(s32, const NJS_POINT2 *, s32);
s32 update_selection__19TWindowSubTechniqueFPsPl(void *, void *, s32);
void get_current_selection__19TWindowSubTechniqueFPv(void *, void *, s32);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
s32 end_player_keyboard_hold(s32);
s32 TWindowCtrl__sub_8024A1A8();
s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 TWindowHelpItem__set_displayed_item_by_id(void *);
s32 is_technique_ready__8TTecCtrlFv();
s32 set_flag70_bit10__21TWindowSubComCardListFv();
void TWindowShortListCtrl__sub_8026E884(s16 *dst);
}

// The class name TObject::m_name points at.
const char *TWindowShortListCtrl__name = "TWindowShortListCtrl";

// Screen position of the list windows (inferred from create_equip_kind_window / set_scroll_target use).
static const NJS_POINT2 short_list_window_pos = {308.0f, 124.0f};

// First run_task state of each page (inferred from sub_8026EA48 and run_task's case labels).
static const u8 page_first_state[4] = {0, 3, 6, 9};

s16 TWindowSubComCardList::get_selected_index() { return *(s16 *)&this->unk_7A; }

void TWindowShortListCtrl::update_cursor_pos() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x7A) = get_cursor_pos();
}

s16 TWindowShortListCtrl::get_cursor_pos() { return *(s16*)((char*)this + 0x78); }

void TWindowShortListCtrl::set_card_window_flags(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 0x10), (s32)0xFFFCFFFF);
}

TWindowShortListCtrl::TWindowShortListCtrl(TObject *parent, s32 client_id) : TObject(parent) {
    m_name = TWindowShortListCtrl__name;
    this->client_id = client_id;
    TObjPlayer *player = get_player_by_client_id(this->client_id);
    if (player == NULL) {
        queue_destruction();
        return;
    }
    CharacterAppearanceFields *appearance = (CharacterAppearanceFields *)player->name;
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
    sub_8026EA48();
    timer = 0;
    tech_window = NULL;
    list_window = NULL;
    help_window = NULL;
    help_item_id = -1;
    begin_player_keyboard_hold(this->client_id);
    TWindowCtrl::set_flag_active();
    player->reset_equip_slots();
}

TWindowShortListCtrl::~TWindowShortListCtrl() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL && has_player_active_menu__11TWindowCtrlFv(client_id) == 0 && TWindowCtrl__sub_8024A1A8() == 0) {
        player->init_parts();
    }
    end_player_keyboard_hold(client_id);
    TWindowCtrl::clear_flag_8();
    if (help_window != NULL) {
        ((TWindowBase *)help_window)->close();
        help_window = NULL;
    }
    if (list_window != NULL) {
        ((TWindowBase *)list_window)->close();
        list_window = NULL;
    }
    if (tech_window != NULL) {
        ((TWindowBase *)tech_window)->close();
        tech_window = NULL;
    }
}

void TWindowShortListCtrl::run_task() {
    s32 idx;
    u8 *player;
    s32 sel;
    idx = is_player_input_active(client_id);
    player = (u8 *)get_player_by_client_id(client_id);
    if ((timer > 2 && TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 0x200) != 0) || player == NULL) {
        queue_destruction();
        return;
    }
    cycle_list_page();
    switch (state) {
    case 0:
        if (list_window == NULL) {
            list_window = create_equip_kind_window(get_window_layout_position(1), &short_list_window_pos, client_id);
            ((TWindowSubShortCutList *)list_window)->set_flag70_bit10();
            ((TWindowShortListCtrl *)list_window)->update_variant_c();
            ((TWindowSubComCardList *)list_window)->m_5c = 0x01000000;
        }
        state = 1;
    case 1:
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 0x400) != 0) {
            if (help_window == NULL) {
                void *w = __nw__7TObjectFUl(0xBC);
                if (w != NULL) {
                    w = __ct__15TWindowHelpItemFPvUs(w, get_window_layout_position(2), client_id);
                }
                help_window = w;
                help_item_id = -1;
                TWindowCtrl::clear_flag_8();
            } else {
                ((TWindowBase *)help_window)->close();
                help_window = NULL;
                TWindowCtrl::set_flag_active();
            }
        }
        set_displayed_item(get_cursor_value__19TWindowMenuIconLineFv(list_window));
        if (((TWindowMenuIconLine *)list_window)->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (((TWindowMenuIconLine *)list_window)->is_decided() != 0) {
            state = 2;
        }
        break;
    case 2:
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (TWindowSubItem::is_usable((s32)player) == 0) {
            break;
        }
        assign_shortcut(6, get_cursor_value__19TWindowMenuIconLineFv(list_window), client_id);
        queue_destruction();
        return;
    case 3:
        if (list_window == NULL) {
            list_window = create_equip_kind_window(get_window_layout_position(1), &short_list_window_pos, client_id);
            ((TWindowSubShortCutList *)list_window)->set_flag70_bit10();
            ((TWindowShortListCtrl *)list_window)->update_variant_b();
            ((TWindowSubComCardList *)list_window)->m_5c = 0x01000000;
        }
        state = 4;
    case 4:
        assign_item_to_palette(get_cursor_value__19TWindowMenuIconLineFv(list_window), client_id);
        if (((TWindowMenuIconLine *)list_window)->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (((TWindowMenuIconLine *)list_window)->is_decided() != 0) {
            state = 5;
        }
        break;
    case 5:
        assign_item_to_palette(get_cursor_value__19TWindowMenuIconLineFv(list_window), client_id);
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (TWindowSubItem::is_usable((s32)player) == 0) {
            break;
        }
        sel = get_cursor_value__19TWindowMenuIconLineFv(list_window);
        if (find_item_by_id(sel) == NULL) {
            return;
        }
        try_send_6x27_use_item(player, sel);
        queue_destruction();
        return;
    case 6:
        if (list_window == NULL) {
            list_window = create_equip_kind_window(get_window_layout_position(1), &short_list_window_pos, client_id);
            ((TWindowSubShortCutList *)list_window)->set_flag70_bit10();
            ((TWindowShortListCtrl *)list_window)->update_variant_a();
            ((TWindowSubComCardList *)list_window)->m_5c = 0x01000000;
        }
        state = 7;
    case 7:
        assign_item_to_palette(get_cursor_value__19TWindowMenuIconLineFv(list_window), client_id);
        if (((TWindowMenuIconLine *)list_window)->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (((TWindowMenuIconLine *)list_window)->is_decided() != 0) {
            state = 8;
        }
        break;
    case 8:
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (TWindowSubItem::is_usable((s32)player) == 0) {
            return;
        }
        sel = get_cursor_value__19TWindowMenuIconLineFv(list_window);
        if ((sel & 0xF) == 4) {
            if (TAdSinglePlyChrSelectGC::create_if_key_pressed() == 0) {
                break;
            }
            decrement_clamped((s32 *)(player + 0x7C8), 1);
            queue_destruction();
            return;
        }
        if (TWindowCtrl__sub_8024A228(client_id) == 0) {
            return;
        }
        ((TObjPlayer *)player)->send_trap_packet(sel & 0xF);
        queue_destruction();
        return;
    case 9:
        if (tech_window == NULL) {
            get_current_selection__19TWindowSubTechniqueFPv(&m_20, &m_28, client_id);
            tech_window = create_window(get_window_layout_position(1), (s32)&short_list_window_pos);
        }
        ((TWindowSubComCard *)tech_window)->clear_flag_and_release();
        state = 10;
    case 10:
        ((TObjPlayer *)player)->update_cursor((s16)((TWindowMenu *)tech_window)->get_selected_value());
        if (update_selection__19TWindowSubTechniqueFPsPl(&m_20, &m_28, client_id) != 0) {
            refresh_technique_rows((s32)tech_window, (void *)&short_list_window_pos);
        }
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 0x400) != 0) {
            if (((TWindowSubComCardList *)tech_window)->get_selected_index() == -1) {
                ((TWindowShortListCtrl *)tech_window)->update_cursor_pos();
            } else {
                swap_card_entries(((TWindowSubComCardList *)tech_window)->get_selected_index(), ((TWindowShortListCtrl *)tech_window)->get_cursor_pos());
                ((TWindowMenu *)tech_window)->reset_selection();
                refresh_technique_rows((s32)tech_window, (void *)&short_list_window_pos);
            }
        }
        if (((TWindowMenu *)tech_window)->is_cancelled() != 0) {
            queue_destruction();
            return;
        }
        if (((TWindowMenu *)tech_window)->is_decided() != 0) {
            state = 11;
        }
        break;
    case 11:
        ((TObjPlayer *)player)->update_cursor((s16)((TWindowMenu *)tech_window)->get_selected_value());
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[idx], 2) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            queue_destruction();
            return;
        }
        if (try_equip_item__10TObjPlayerFii(player, (s16)((TWindowMenu *)tech_window)->get_selected_value()) != 0) {
            queue_destruction();
            return;
        }
        if (TWindowSubTechnique::is_technique_available((s16)((TWindowMenu *)tech_window)->get_selected_value(), client_id) == 0) {
            refresh_technique_rows((s32)tech_window, (void *)&short_list_window_pos);
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

void *TWindowShortListCtrl::create_window(s32 arg1, s32 arg2_arg) {
    void *window_menu;

    window_menu = (void *)create_window_menu(arg1, 0x13, client_id);
    set_flag70_bit10__21TWindowSubComCardListFv();
    ((TWindowSubComCardList *)window_menu)->m_5c = 0x01000000;
    ((TWindowSubComCardList *)window_menu)->set_flag70_bit100();
    refresh_technique_rows((s32)window_menu, (void *)arg2_arg);
    return window_menu;
}

void TWindowShortListCtrl::refresh_technique_rows(s32 arg1, void *arg2_arg) {
    const NJS_POINT2 *pos = (const NJS_POINT2 *)arg2_arg;
    s32 i;
    s16 cur;
    s16 *order = (s16 *)(get_character_save_record(client_id) + 0x22C4);
    cur = ((TWindowShortListCtrl *)arg1)->get_cursor_pos();
    ((TWindowSubComCardList *)arg1)->reset_entries();
    for (i = 0; i < 0x13; i++) {
        TWindowSubTechnique::draw_technique_row(order[i], client_id, arg1);
    }
    ((TWindowSubComCardList *)arg1)->set_scroll_target(pos->x, pos->y);
    align_menu_entry_positions((void *)arg1);
    ((TWindowSubComCardList *)arg1)->set_selected_index(cur);
}

void TWindowShortListCtrl::cycle_list_page() {
    s32 port = is_player_input_active(client_id);
    if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[port], fn_8002AE08(client_id)) != 0) {
        s8 old_page = page;
        TObjPlayer *player = get_player_by_client_id(client_id);
        if (player != NULL) {
            CharacterAppearanceFields *appearance = (CharacterAppearanceFields *)player->name;
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
                    sub_8026EA48();
                }
            }
        }
    }
}

void TWindowShortListCtrl::sub_8026EA48() {
    state = page_first_state[page];
}

void TWindowShortListCtrl::destroy_children() {
    if (list_window != NULL) {
        ((TObject *)list_window)->queue_destruction();
        list_window = NULL;
    }
    if (tech_window != NULL) {
        ((TObject *)tech_window)->queue_destruction();
        tech_window = NULL;
    }
}

void TWindowShortListCtrl::assign_item_to_palette(u32 item_id, u32 client_id) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        // player+0x424 holds an object with a TWindowActionPalette at +0x520 (class not recovered yet).
        u8 *menu = (u8 *)player->m_424;
        if (menu != NULL) {
            TItem *item = find_item_by_id(item_id);
            if (item != NULL && item->get_item_type() == 3) {
                s32 slot = get_tool_palette_index(item);
                if (slot != -1) {
                    if (canSetMenuCursorAction((s32)(menu + 0x520), (s32)player, 4, slot) != 0) {
                        ((TWindowActionPalette *)(menu + 0x520))->set_mode(4);
                        ((TWindowActionPalette *)(menu + 0x520))->set_slot(slot);
                        TMainCursor__sub_8013DFC4(menu + 0x520);
                    }
                }
            }
        }
    }
}

void TWindowShortListCtrl::swap_card_entries(s32 arg1, s32 arg2) {
    s16 *p = (s16 *)(get_character_save_record(client_id) + 0x22C4);
    s16 t = p[arg1];
    p[arg1] = p[arg2];
    p[arg2] = t;
}

void TWindowShortListCtrl__sub_8026E884(s16 *dst) {
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
    CharacterAppearanceFields *appearance = (CharacterAppearanceFields *)player->name;
    if (appearance == NULL) {
        return 0;
    }
    if (is_technique_ready__8TTecCtrlFv() != 0) {
        return 1;
    }
    return (appearance->classFlags >> 4) & 1;
}

void TWindowShortListCtrl::set_displayed_item(s32 item_id) {
    if (help_window != NULL && item_id != help_item_id) {
        help_item_id = item_id;
        TWindowHelpItem__set_displayed_item_by_id(help_window);
    }
}
