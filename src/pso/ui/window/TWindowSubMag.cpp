#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/MagStats.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubMagPhoton.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/item/TItemData.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/network/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubEquipKind.h"

#pragma readonly_strings on

struct Item_8027B424 { u8 b[0x10]; };

extern u8 *text_language_group_table;

const char *TWindowSubMag::class_name = "TWindowSubMag";

// Window positions (x, y): mag slot list, the two equip-kind lists, message window.
extern const f32 mag_texture_window_extent[2] = {144.0f, 68.0f};
extern const NJS_POINT2 mag_equip_kind_window_size = {206.0f, 184.0f};
extern const NJS_POINT2 mag_feed_equip_kind_window_size = {308.0f, 124.0f};
extern const f32 mag_message_window_size[2] = {214.0f, 184.0f};

extern "C" const char mag_empty_line[] = "";
// Deferred code generation: the functions are written last to first (see configure.py).

TItemData *TWindowHelpItem::get_mag_state() { return active_item; }

void TWindowHelpItem::enable_help_toggle() { help_flags &= ~8; }

void TWindowHelpItem::disable_help_toggle() { help_flags |= 8; }

bool is_mag_full(u8 *arg0) {
    return (*(f32 *)((s8 *)arg0 + 0x194) < 2.0f) == 0;
}

int TWindowSubMagPhoton::is_cancelled() { return state_flags & 2; }

int TWindowSubMagPhoton::get_active_flag() { return this->state_flags & 0x1; }

s32 TWindowSubMagPhoton::get_selected_blast() {
    return photon_blasts[static_cast<s8>(selected_blast_index)];
}

const char *get_photon_blast_name(s32 blast) {
    return ((const char ***)text_language_group_table)[8][blast];
}

TWindowSubMag::TWindowSubMag(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    this->parent = parent;
    client_id = client;
    list = (TWindowMenuIconLine *)setup_list();
    help = NULL;
    slotwin = NULL;
    card = NULL;
    list2 = NULL;
    photon = NULL;
    message = NULL;
    mag = NULL;
    displayed_item = -1;
    state = 0;
    timer = 0;
}

TWindowSubMag::~TWindowSubMag() {
    if (message != 0U) {
        ((TObject *)message)->queue_destruction();
        message = 0U;
    }
    if (photon != 0U) {
        photon->close();
        photon = 0U;
    }
    if (list2 != 0U) {
        list2->close();
        list2 = 0U;
    }
    if (card != 0U) {
        card->close();
        card = 0U;
    }
    if (slotwin != 0U) {
        slotwin->close();
        slotwin = 0U;
    }
    if (help != 0U) {
        help->close();
        help = 0U;
    }
    if (list != 0U) {
        list->close();
        list = 0U;
    }
}

void TWindowSubMag::run_task() {
    TObjPlayer *player;
    s32 port;
    player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return;
    }
    port = is_player_input_active(client_id);
    switch (state) {
    case 0:
    case 1:
        if (card != NULL) {
            card->close();
            card = NULL;
        }
        if (help == NULL) {
            help = new TWindowHelpItem((void *)get_window_layout_position(9), client_id);
            help->set_depth(get_main_menu_layer_depth((u8 *)parent, 5));
        }
        if (slotwin == NULL) {
            slotwin = create_load_item_texture_window((void *)get_window_layout_position(0xC), mag_texture_window_extent, client_id);
        }
        help->unlock_page_flip();
        list->refresh_mag_item_list(2);
        list->clear_decided();
        list->start_scroll(188.0f);
        state = 2;
    case 2:
        update_displayed_item();
        mag = help->get_mag_state();
        slotwin->set_mag_slot_state(help->get_mag_state());
        if (list->is_cancelled() != 0) {
            parent->on_submenu_closed();
            state = 0x11;
        } else if (list->is_decided() != 0) {
            state = 3;
        }
        break;
    case 3:
        if (message != NULL) {
            ((TObject *)(message))->queue_destruction();
            message = NULL;
        }
        if (photon != NULL) {
            photon->close();
            photon = NULL;
        }
        if (list2 != NULL) {
            list2->close();
            list2 = NULL;
        }
        if (help != NULL) {
            window_request_show(help);
            help->unlock_page_flip();
            help->enable_help_toggle();
            call_if_split_screen((uaddr)help, client_id);
        }
        list->start_scroll(188.0f);
        if (card == NULL) {
            card = (TWindowMenu *)create_action_menu(list->get_cursor_value());
        }
        card->clear_flag_and_release();
        state = 4;
    case 4:
        if (card->is_cancelled() != 0) {
            state = 1;
        } else if (card->is_decided() != 0) {
            set_mag_mode(card->get_selected_value());
        }
        break;
    case 5:
        if (card != NULL) {
            card->close();
            card = NULL;
        }
        ((TWindowSubStatusDisp *)(list))->init_scroll_pos();
        help->update_help_item(1);
        help->lock_page_flip();
        if (list2 == NULL) {
            list2 = (TWindowMenuIconLine *)create_list();
        }
        list2->clear_decided();
        state = 6;
    case 6:
        if (list2->is_cancelled() != 0) {
            state = 3;
        } else if (list2->is_decided() != 0) {
            state = 7;
        }
        break;
    case 7:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            state = 5;
        } else if (TWindowSubItem::is_usable(player) != 0) {
            slots = count_slots();
            TWindowSubMag::feed_mag((void*)player, (void*)(list->get_cursor_value()), (void*)(list2->get_cursor_value()));
            state = 8;
        }
        break;
    case 8:
        window_request_show(help);
        window_request_refresh((u8 *)help);
        help->disable_help_toggle();
        help->refresh_copied_items();
        list->refresh_mag_item_list(2);
        slotwin->set_mag_slot_state(help->get_mag_state());
        if (help->update_mag_status_gauges() != 0) {
            state = 9;
        } else {
            state = 3;
        }
        break;
    case 9:
        if (help->are_status_entries_ready() != 0) {
            state = 10;
        }
        break;
    case 10:
        if (help->advance_mag_levels() != 0) {
            play_sound_effect(0x4002A80F, 0, 0, 0);
            timer = 0;
            state = 11;
        } else {
            state = 12;
            break;
        }
    case 11:
        if ((f32)timer++ > (3e+01f) && help->are_status_entries_ready() != 0) {
            state = 10;
        }
        break;
    case 12:
        if (slots != count_slots()) {
            timer = 0;
            help->update_help_item(2);
            message = create_learned_blast_toast();
            state = 13;
        } else {
            state = 3;
            break;
        }
    case 13:
        if ((f32)timer++ > (9e+01f) && message != NULL) {
            ((TWindowBase *)message)->close();
            message = NULL;
            state = 3;
        }
        break;
    case 14:
        if (card != NULL) {
            card->close();
            card = NULL;
        }
        if (help != NULL) {
            help->request_close();
            help->disable_help_toggle();
            help->lock_page_flip();
        }
        photon = new TWindowSubMagPhoton(get_window_layout_position(0xA), mag, client_id);
        photon->set_depth(get_main_menu_layer_depth((u8 *)parent, 3));
        message = create();
        shown_blast = -1;
        state = 15;
    case 15:
        update_mag_help();
        if (photon->is_cancelled() != 0) {
            state = 3;
        } else if (photon->get_active_flag() != 0) {
            state = 3;
        }
        break;
    case 16:
        if ((u32)player->is_action_active() == 0) {
            state = 1;
        }
        break;
    case 17:
        break;
    }
}

void TWindowSubMag::render() {  }

saddr TWindowSubMag::setup_list() {
    TWindowSubEquipKind *equip_kind_window;
    const NJS_POINT2 *window_layout_position;

    window_layout_position = get_window_layout_position(7);
    equip_kind_window = create_equip_kind_window(window_layout_position, &mag_equip_kind_window_size, this->client_id);
    equip_kind_window->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x29));
    equip_kind_window->set_depth(get_main_menu_layer_depth((u8 *)parent, 0));
    equip_kind_window->set_flag70_bit10();
    equip_kind_window->refresh_mag_item_list(2);
    return reinterpret_cast<saddr>(equip_kind_window);
}

saddr TWindowSubMag::create_list() {
    TWindowSubEquipKind *equip_kind_window;

    const NJS_POINT2 *window_layout_position = get_window_layout_position(0xD);
    equip_kind_window = create_equip_kind_window(window_layout_position, &mag_feed_equip_kind_window_size, this->client_id);
    equip_kind_window->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    equip_kind_window->set_depth(get_main_menu_layer_depth((u8 *)parent, 2));
    equip_kind_window->set_flag70_bit10();
    equip_kind_window->refresh_usable_item_list();
    return reinterpret_cast<saddr>(equip_kind_window);
}
extern "C" {

// dead-stripped: only its literals survive. 2.0f (.sdata2 0x805DD668) is pooled after create_action_menu's
// 172.0f and ahead of run_task's literals, but its one live user is_mag_full is generated last (deferred
// codegen runs this file bottom-up), so a function generated between create_action_menu and create_list
// used it first. Minimal body after is_mag_full's check; name inferred.
static int is_mag_fed_full(TItemMag *mag) {
    return mag->feeds_while_full >= 2.0f;
}
}

void *TWindowSubMag::create_action_menu(s32 id) {
    s32 stats[4];
    void *window;
    u8 *item;
    ((MagStats *)stats)->init();
    item = (u8 *)find_item_by_id(id);
    window = (void *)create_titled_window_menu(get_window_layout_position(8), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x1D), client_id);
    ((TWindowBase *)window)->set_depth(get_main_menu_layer_depth((u8 *)parent, 1));
    if (((s32 (*)(u8 *))is_mag_full)(item) != 0) {
        add_gray_text_entry((TWindowMenu *)window, (const char *)(TWindowSubStatusDisp::get_message_10(0x65)), 6, 1);
    } else {
        ((TWindowMenu *)window)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x65)), 6, 1);
    }
    TItemData::deserialize_mag(mag, (void *)stats);
    if (((MagStats *)stats)->get_photon_blast(0) != -1) {
        ((TWindowMenu *)window)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x64)), 6, 0);
    } else {
        add_gray_text_entry((TWindowMenu *)window, (const char *)(TWindowSubStatusDisp::get_message_10(0x64)), 6, 0);
    }
    ((TWindowMenu *)window)->set_flag70_bit10();
    ((TWindowMenu *)window)->update_layout_height((172.0f));
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(window));
    return window;
}

void *TWindowSubMag::create() {
    void *object;
    const NJS_POINT2 *window_layout_position;

    window_layout_position = get_window_layout_position(0xB);
    object = TWindowMessage::create(window_layout_position, mag_message_window_size, 1, this->client_id);
    ((TWindowBase *)object)->set_depth(get_main_menu_layer_depth((u8 *)parent, 4));
    *(s32 *)((s8 *)object + 0x5C) = 0x186A0;
    call_if_split_screen((uaddr)object, this->client_id);
    return object;
}

#pragma push
#pragma fp_contract on
void *TWindowSubMag::create_learned_blast_toast() {
    Item_8027B424 item;
    NJS_POINT2 pos;
    NJS_POINT2 size;
    f32 scale;
    s32 n;
    void *win;
    ((MagStats *)((s32 *)&item))->init();
    TItemData::deserialize_mag(mag, (void *)((s32 *)&item));
    n = ((MagStats *)((s32 *)&item))->get_photon_blast(this->slots);
    if (n == -1) {
        return 0;
    }
    text_builder_reset();
    text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0x64));
    append_text_space();
    text_builder_append(get_photon_blast_name(n));
    text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0x4C));
    n = calc_text_width((char *)get_shared_text_buffer());
    if (TCameraCtrl::get_camera_id() > 2) {
        scale = 0.85f;
    } else {
        scale = 1.0f;
    }
    copy_vec2((&pos), (void*)(get_window_layout_position(0xE)));
    pos.x -= (0.5f * n + 4.0f) * scale;
    size.x = 8.0f + n;
    size.y = 40.0f;
    win = TWindowMessage::create(&pos, &size.x, 1, this->client_id);
    ((TWindowBase *)win)->set_depth(get_main_menu_layer_depth((u8 *)parent, 6));
    ((TWindowMessage *)win)->append_line((saddr)((s32 *)get_shared_text_buffer()), 2);
    ((TWindowAddition *)win)->set_position_xy(scale, scale);
    return win;
}
#pragma pop

void TWindowSubMag::set_mag_mode(s32 mag_mode) {
    switch (mag_mode) {
    case 1:
        this->state = 5;
        return;
    case 0:
        this->state = 0xE;
        return;
    }
}

s32 TWindowSubMag::count_slots() {
    MagStats stats;
    s32 slot;

    stats.init();
    TItemData::deserialize_mag(mag, &stats);
    slot = 0;
loop_1:
    if (stats.get_photon_blast(slot) == -1) {
        return slot;
    }
    slot += 1;
    if (slot >= 3) {
        return slot;
    }
    goto loop_1;
}

void TWindowSubMag::update_displayed_item() {
    s32 cursor_value;

    cursor_value = this->list->get_cursor_value();
    if (cursor_value != (s32) this->displayed_item) {
        this->displayed_item = cursor_value;
        help->set_displayed_item_by_id(cursor_value);
    }
}

void TWindowSubMag::update_mag_help() {
    s32 selected_blast;

    toggle_help_window_on_button((uaddr)this->message, this->client_id);
    selected_blast = photon->get_selected_blast();
    if (selected_blast != (s8) this->shown_blast) {
        this->shown_blast = (u8) selected_blast;
        if (selected_blast == -1) {
            ((TWindowMessage *)(this->message))->append_line((saddr)((s32 *)mag_empty_line), 0x80);
            return;
        }
        ((TWindowMessage *)(this->message))->append_line((saddr)get_help_text_string(selected_blast + 0x27), 0x80);
    }
}
