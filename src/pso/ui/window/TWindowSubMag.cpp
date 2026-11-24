#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/MagStats.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/unk/text_8025373C.h"
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
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
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
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowHelpItem_802540AC.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/unk/text_80263A20.h"

#pragma readonly_strings on

struct Item_8027B424 { u8 b[0x10]; };

extern u8 *text_language_group_table;
extern "C" {
s32 get_photon_blast_name(s32 arg0);
}
extern "C" {
s32 calc_text_width();
s32 text_builder_append();
s32 are_status_entries_ready__13TWindowSubMagFi(void *);
}

const char *TWindowSubMag::class_name = "TWindowSubMag";

extern "C" {
// Window positions (x, y): mag slot list, the two equip-kind lists, message window.
extern const f32 lbl_8044F9E8[2] = {144.0f, 68.0f};
extern const NJS_POINT2 lbl_8044F9F0 = {206.0f, 184.0f};
extern const NJS_POINT2 lbl_8044F9F8 = {308.0f, 124.0f};
extern const f32 lbl_8044FA00[2] = {214.0f, 184.0f};
}
void append_text_space(void);
void text_builder_reset(void);

extern "C" const char lbl_805DD648[] = "";
// Deferred code generation: the functions are written last to first (see configure.py).

TItemData *TWindowHelpItem::get_mag_state() { return active_item; }

void TWindowHelpItem::clear_flag60_bit8() { m_60 &= ~8; }

void TWindowHelpItem::set_flag60_bit8() { m_60 |= 8; }

bool is_mag_full(u8 *arg0) {
    return (*(f32 *)((s8 *)arg0 + 0x194) < 2.0f) == 0;
}

extern "C" {

int TWindowSubMagPhoton::is_cancelled() { return m_60 & 2; }

int TWindowSubMagPhoton::get_active_flag() { return this->m_60 & 0x1; }

s32 TWindowSubMagPhoton::get_selected_blast() {
    return photon_blasts[static_cast<s8>(selected_blast_index)];
}

s32 get_photon_blast_name(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x20)) + (arg0 * 4));
}

TWindowSubMag::TWindowSubMag(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    this->parent = parent;
    client_id = client;
    list = (void *)setup_list();
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
        ((TWindowBase *)list2)->close();
        list2 = 0U;
    }
    if (card != 0U) {
        ((TWindowBase *)card)->close();
        card = 0U;
    }
    if (slotwin != 0U) {
        ((TWindowBase *)slotwin)->close();
        slotwin = 0U;
    }
    if (help != 0U) {
        help->close();
        help = 0U;
    }
    if (list != 0U) {
        ((TWindowBase *)list)->close();
        list = 0U;
    }
}

void TWindowSubMag::run_task() {
    void *player;
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
            ((TWindowBase *)card)->close();
            card = NULL;
        }
        if (help == NULL) {
            help = new TWindowHelpItem((void *)get_window_layout_position(9), client_id);
            help->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 5));
        }
        if (slotwin == NULL) {
            slotwin = fn_802628C0((void *)get_window_layout_position(0xC), lbl_8044F9E8, client_id);
        }
        help->sub_80255E24();
        ((TWindowMenuIconLine *)list)->refresh_mag_item_list(2);
        ((TWindowMenuIconLine *)(list))->clear_decided();
        static_cast<TWindowMenuIconLine *>(list)->start_scroll(188.0f);
        state = 2;
    case 2:
        update_displayed_item();
        mag = help->get_mag_state();
        slotwin->set_mag_slot_state(help->get_mag_state());
        if (((TWindowMenuIconLine *)(list))->is_cancelled() != 0) {
            parent->on_submenu_closed();
            state = 0x11;
        } else if (((TWindowMenuIconLine *)(list))->is_decided() != 0) {
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
            ((TWindowBase *)list2)->close();
            list2 = NULL;
        }
        if (help != NULL) {
            window_request_show(help);
            help->sub_80255E24();
            help->clear_flag60_bit8();
            call_if_split_screen((uaddr)help, client_id);
        }
        static_cast<TWindowMenuIconLine *>(list)->start_scroll(188.0f);
        if (card == NULL) {
            card = create_action_menu(((TWindowMenuIconLine *)list)->get_cursor_value());
        }
        ((TWindowMenu *)(card))->clear_flag_and_release();
        state = 4;
    case 4:
        if (((TWindowMenu *)(card))->is_cancelled() != 0) {
            state = 1;
        } else if (((TWindowMenu *)(card))->is_decided() != 0) {
            set_mag_mode(((TWindowMenu *)card)->get_selected_value());
        }
        break;
    case 5:
        if (card != NULL) {
            ((TWindowBase *)card)->close();
            card = NULL;
        }
        ((TWindowSubStatusDisp *)(list))->init_scroll_pos();
        help->update_help_item(1);
        help->set_flag60_bit4();
        if (list2 == NULL) {
            list2 = (void *)create_list();
        }
        ((TWindowMenuIconLine *)(list2))->clear_decided();
        state = 6;
    case 6:
        if (((TWindowMenuIconLine *)(list2))->is_cancelled() != 0) {
            state = 3;
        } else if (((TWindowMenuIconLine *)(list2))->is_decided() != 0) {
            state = 7;
        }
        break;
    case 7:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            state = 5;
        } else if (TWindowSubItem::is_usable((saddr)player) != 0) {
            slots = count_slots();
            TWindowSubMag::feed_mag((void*)player, (void*)(((TWindowMenuIconLine *)list)->get_cursor_value()), (void*)(((TWindowMenuIconLine *)list2)->get_cursor_value()));
            state = 8;
        }
        break;
    case 8:
        window_request_show(help);
        window_request_refresh((u8 *)help);
        help->set_flag60_bit8();
        help->refresh_copied_items();
        ((TWindowMenuIconLine *)list)->refresh_mag_item_list(2);
        slotwin->set_mag_slot_state(help->get_mag_state());
        if (help->update_mag_status_gauges() != 0) {
            state = 9;
        } else {
            state = 3;
        }
        break;
    case 9:
        if (are_status_entries_ready__13TWindowSubMagFi(help) != 0) {
            state = 10;
        }
        break;
    case 10:
        if (fn_8025373C(help) != 0) {
            play_sound_effect(0x4002A80F, 0, 0, 0);
            timer = 0;
            state = 11;
        } else {
            state = 12;
            break;
        }
    case 11:
        if ((f32)timer++ > (3e+01f) && are_status_entries_ready__13TWindowSubMagFi(help) != 0) {
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
            ((TWindowBase *)card)->close();
            card = NULL;
        }
        if (help != NULL) {
            help->request_close();
            help->set_flag60_bit8();
            help->set_flag60_bit4();
        }
        photon = new TWindowSubMagPhoton(get_window_layout_position(0xA), mag, client_id);
        photon->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 3));
        message = create();
        m_1d = -1;
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
        if ((u32)((TObjPlayer *)player)->is_action_active() == 0) {
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
    s32 window_layout_position;

    window_layout_position = reinterpret_cast<saddr>(get_window_layout_position(7));
    equip_kind_window = create_equip_kind_window(window_layout_position, &lbl_8044F9F0, this->client_id);
    equip_kind_window->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x29));
    equip_kind_window->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 0));
    equip_kind_window->set_flag70_bit10();
    equip_kind_window->refresh_mag_item_list(2);
    return reinterpret_cast<saddr>(equip_kind_window);
}

saddr TWindowSubMag::create_list() {
    TWindowSubEquipKind *equip_kind_window;

    s32 window_layout_position = reinterpret_cast<saddr>(get_window_layout_position(0xD));
    equip_kind_window = create_equip_kind_window(window_layout_position, &lbl_8044F9F8, this->client_id);
    equip_kind_window->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0x24));
    equip_kind_window->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 2));
    equip_kind_window->set_flag70_bit10();
    equip_kind_window->refresh_usable_item_list();
    return reinterpret_cast<saddr>(equip_kind_window);
}

// dead-stripped: only its literals survive. 2.0f (.sdata2 0x805DD668) is pooled after create_action_menu's
// 172.0f and ahead of run_task's literals, but its one live user is_mag_full is generated last (deferred
// codegen runs this file bottom-up), so a function generated between create_action_menu and create_list
// used it first. Minimal body after is_mag_full's check; name inferred.
static int is_mag_fed_full(TItemMag *mag) {
    return mag->feeds_while_full >= 2.0f;
}

void *TWindowSubMag::create_action_menu(s32 id) {
    s32 stats[4];
    void *window;
    u8 *item;
    ((MagStats *)stats)->init();
    item = (u8 *)find_item_by_id(id);
    window = (void *)create_titled_window_menu(reinterpret_cast<saddr>(get_window_layout_position(8)), 2, (saddr)TWindowSubStatusDisp::get_message_10(0x1D), client_id);
    ((TWindowBase *)window)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 1));
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
    s32 window_layout_position;

    window_layout_position = reinterpret_cast<saddr>(get_window_layout_position(0xB));
    object = TWindowMessage::create(window_layout_position, lbl_8044FA00, 1, this->client_id);
    ((TWindowBase *)object)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 4));
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
    TWindowSubStatusDisp::get_message_10(0x64);
    text_builder_append();
    append_text_space();
    get_photon_blast_name(n);
    text_builder_append();
    TWindowSubStatusDisp::get_message_10(0x4C);
    text_builder_append();
    get_shared_text_buffer();
    n = calc_text_width();
    if (TCameraCtrl::get_camera_id() > 2) {
        scale = 0.85f;
    } else {
        scale = 1.0f;
    }
    copy_vec2((&pos), (void*)(get_window_layout_position(0xE)));
    pos.x -= (0.5f * n + 4.0f) * scale;
    size.x = 8.0f + n;
    size.y = 40.0f;
    win = TWindowMessage::create((saddr)&pos, &size.x, 1, this->client_id);
    ((TWindowBase *)win)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 6));
    ((TWindowMessage *)win)->append_line((saddr)((s32 *)get_shared_text_buffer()), (int)2);
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
    s32 temp_r3;

    temp_r3 = ((TWindowMenuIconLine *)this->list)->get_cursor_value();
    if (temp_r3 != (s32) this->displayed_item) {
        this->displayed_item = temp_r3;
        help->set_displayed_item_by_id(temp_r3);
    }
}

void TWindowSubMag::update_mag_help() {
    s32 selected_blast;

    toggle_help_window_on_button((uaddr)this->message, this->client_id);
    selected_blast = photon->get_selected_blast();
    if (selected_blast != (s8) this->m_1d) {
        this->m_1d = (u8) selected_blast;
        if (selected_blast == -1) {
            ((TWindowMessage *)(this->message))->append_line((saddr)((s32 *)lbl_805DD648), (int)0x80);
            return;
        }
        ((TWindowMessage *)(this->message))->append_line((int)(get_help_text_string(selected_blast + 0x27)), (int)0x80);
    }
}

}
