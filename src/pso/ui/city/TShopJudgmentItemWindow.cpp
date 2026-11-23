#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlyDispData.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask_802156A0.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80222C28.h"
#include "pso/network/client_id.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TPlyItem.h"
#include "pso/object/base/TObjBase.h"

const char *TShopJudgmentItemWindow__class_name = "TShopJudgmentItemWindow";

TShopJudgmentItemWindow::TShopJudgmentItemWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player) : TShopWindowBase(parent) {
    m_name = TShopJudgmentItemWindow__class_name;
    this->pad_144 = 0;
    this->item_count = 0;
    this->pad_150 = 0;
    this->player = player;
    this->item_list = NULL;
    this->yes_no_menu = NULL;
    this->help_window = NULL;
    this->texture_window = NULL;
    this->result_item = NULL;
    this->sequence = sequence;
    this->m_16c = NULL;
    this->on_cancel = NULL;
    this->on_close = NULL;
}

TShopJudgmentItemWindow::~TShopJudgmentItemWindow() {
    if (item_list != NULL) { item_list->close(); item_list = NULL; }
    if (texture_window != NULL) { texture_window->close(); texture_window = NULL; }
    if (yes_no_menu != NULL) { yes_no_menu->close(); yes_no_menu = NULL; }
    if (result_item != NULL) { result_item->queue_destruction(); result_item = NULL; }
}

void TShopJudgmentItemWindow::update_state() {
    switch (this->state) {
    case 0:
        close();
        build_item_list();
        return;
    case 1:
        handle_input();
        return;
    case 2:
        handle_judge_confirm();
        return;
    case 3:
        create_result_windows();
        return;
    case 4:
        update_judge_confirm();
        return;
    case 5:
        update();
        return;
    case 6:
        handle_pay_confirm();
        return;
    case 7:
        handle_equip_prompt();
        return;
    case 10:
        invoke_callback_170_and_destroy();
        return;
    case 8:
        invoke_callback_16C_and_destroy();
        return;
    case 11:
        invoke_callback_174_and_destroy();
    default:
        return;
    }
}

void TShopJudgmentItemWindow::close() { if (this->result_item != NULL) { this->result_item->queue_destruction(); this->result_item = NULL; } }

void TShopJudgmentItemWindow::build_item_list() {
    TItem *items[32];
    s32 n;
    s32 i;
    TItem *it;
    s32 j;
    s32 k;
    memset(entries, 0, 0xF0);
    n = player->inventory_objects->apply_shop_judgment(items);
    item_count = 0;
    for (i = 0; i < n; i++) {
        it = items[i];
        if (it != NULL && it->is_identified() == 0) {
            entries[item_count++].set(items[i], i);
        }
    }
    if (item_count != 0) {
        set_state(1);
    } else {
        send_message(2, 1);
        set_state(0xB);
        return;
    }
    if (item_list == NULL) {
        item_list = create_item_list_window(get_appraisal_text(0), item_count, player->get_entity_id());
        for (j = 0; j < item_count; j++) {
            item_list->add_list_entry(entries[j].item, j);
        }
        item_list->calc_content_extent();
        return;
    }
    item_list->reset_list();
    for (k = 0; k < item_count; k++) {
        item_list->add_list_entry(entries[k].item, k);
    }
    item_list->calc_content_extent();
    item_list->clear_decided();
}

void TShopJudgmentItemWindow::handle_input() {

    if (is_cancel_pressed() != 0) {
        set_state(0xA);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (is_decide_pressed() != 0) {
        this->yes_no_menu = create_yes_no_window(get_window_layout_position(0x2B), this->player->get_entity_id(), NULL, NULL);
        this->yes_no_menu->set_position_xy(get_scale(), get_scale());
        send_message(3, 1);
        set_state(2);
        play_sound_effect(0x52D01, 0, 0, 0);
    }
}

#pragma push
#pragma fp_contract on

void TShopJudgmentItemWindow::handle_judge_confirm() {
    s32 selected_menu_value;
    s32 cursor;
    if (is_message_ready() != 0) {
        if ((yes_no_menu != NULL) && (yes_no_menu->is_decided() != 0)) {
            selected_menu_value = yes_no_menu->get_selected_value();
            if ((selected_menu_value == 0) && (item_list != NULL)) {
                if (obj_getPtr2B0_20((u8 *)this->player) < 0x64) {
                    yes_no_menu->close();
                    this->yes_no_menu = NULL;
                    send_message(5, 1);
                    set_state(0xB);
                    return;
                }
                cursor = item_list->get_cursor_value();
                if (entries[cursor].item->copy_to_item_data(&selected_item) != 0) {
                    this->at_tekker = entries[cursor].item->is_at_tekker();
                    judged_item.copy_from(&selected_item);
                    update_item_appraisal((saddr)&judged_item);
                    this->timer = 0x5F;
                    if (item_list != NULL) {
                        item_list->close();
                        this->item_list = NULL;
                    }
                    play_cue_stream_file("j_kantei.adx");
                }
                yes_no_menu->close();
                this->yes_no_menu = NULL;
                send_message(6, 1);
                set_state(3);
                return;
            }
            if (selected_menu_value == 1) {
                yes_no_menu->close();
                this->yes_no_menu = NULL;
                send_message(4, 1);
                set_state(1);
                item_list->clear_decided();
                return;
            }
            goto block_14;
        }
block_14:
        if ((yes_no_menu != NULL) && (yes_no_menu->is_cancelled() != 0)) {
            yes_no_menu->close();
            this->yes_no_menu = NULL;
            send_message(4, 1);
            set_state(1);
            item_list->clear_decided();
        }
    }
}

#pragma pop

void TShopJudgmentItemWindow::create_result_windows() {
    s32 frames;
    frames = this->timer - 1;
    this->timer = frames;
    if (frames <= 0) {
        if (this->item_list == NULL) {
            switch (current_language) {
            case LANGUAGE_JAPANESE:
                this->item_list = create_item_list_window((saddr)"\x8A\xD3\x92\xE8\x8C\x8B\x89\xCA", 1, this->player->get_entity_id());
                break;
            case LANGUAGE_ENGLISH:
            case LANGUAGE_GERMAN:
            case LANGUAGE_FRENCH:
            case LANGUAGE_SPANISH:
            default:
                this->item_list = create_item_list_window((saddr)"Result", 1, this->player->get_entity_id());
                break;
            }
            judged_item.clear_unidentified_flag();
            this->judged_item.id = advance_item_id_counter((u16)local_client_id);
            this->result_item = construct_item(&judged_item);
            this->item_list->add_list_entry(this->result_item, 0);
            ((TWindowSubShortCutList *)this->item_list)->set_flag70_bit10();
            ((TWindowSubTradeMain *)this->item_list)->set_visible();
            ((TWindowSubTradeMain *)this->item_list)->set_close_flag();
            this->item_list->calc_content_extent();
        }
        if (this->texture_window == NULL) {
            this->texture_window = TWindowLoadItemTexture::create((void *)get_window_layout_position(0x30), this->player->get_entity_id());
            this->texture_window->set_mag_slot_state(&judged_item);
        }
        if (this->help_window == NULL) {
            this->help_window = new TWindowHelpItem((void *)get_window_layout_position(0x27), this->player->get_entity_id());
            if ((this->help_window != NULL) && (TLobby::is_camera_ctrl_active() > 2)) {
                this->help_window->set_scale(0.75f, 0.75f);
            }
            this->help_window->set_displayed_item_colored((uaddr)&judged_item);
        }
        send_message(8, 1);
        set_state(4);
    }
}

void TShopJudgmentItemWindow::update_judge_confirm() {
    s32 selected_menu_value;
    if (is_message_ready() != 0) {
        if (yes_no_menu == NULL) {
            yes_no_menu = create_yes_no_window(get_window_layout_position(0x2B), player->get_entity_id(), NULL, NULL);
            yes_no_menu->set_position_xy(get_scale(), get_scale());
        }
        if ((yes_no_menu != NULL) && (yes_no_menu->is_decided() != 0)) {
            selected_menu_value = yes_no_menu->get_selected_value();
            if (selected_menu_value == 0) {
                if (texture_window != NULL) {
                    texture_window->close();
                    texture_window = NULL;
                }
                if (item_list != NULL) {
                    item_list->close();
                    item_list = NULL;
                }
                if (help_window != NULL) {
                    help_window->close();
                    help_window = NULL;
                }
                try_spend_actor_meseta(player, 0x64);
                if (check_equip_requirements(player, &judged_item, NULL) != 0) {
                    send_message(0xC, 1);
                    yes_no_menu->close();
                    yes_no_menu = NULL;
                    set_state(7);
                    return;
                }
                delete_item(player, selected_item.id, 1);
                judged_item.id = selected_item.id;
                player->request_inventory_item(&judged_item);
                set_judgment_target_flag(this, &judged_item);
                send_message(0xB, 1);
                yes_no_menu->close();
                yes_no_menu = NULL;
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file("miniclear.adx");
                }
                set_state(0);
                return;
            }
            if (selected_menu_value == 1) {
                yes_no_menu->close();
                yes_no_menu = NULL;
                send_message(9, 1);
                set_state(6);
                return;
            }
            goto block_19;
        }
block_19:
        if ((yes_no_menu != NULL) && (yes_no_menu->is_cancelled() != 0)) {
            yes_no_menu->close();
            yes_no_menu = NULL;
            send_message(9, 1);
            set_state(6);
        }
    }
}

void TShopJudgmentItemWindow::handle_equip_prompt() {
    f32 y;
    s32 sel;
    s32 id;
    TItem *item;
    TItem *equipped;

    if (this->is_message_ready() != 0) {
        if (yes_no_menu == NULL) {
            id = player->get_entity_id();
            yes_no_menu = create_yes_no_window(get_window_layout_position(0x2B), id, NULL, NULL);
            ((TWindowSubComCardList *)yes_no_menu)->set_selected_index(0);
            y = get_scale();
            yes_no_menu->set_position_xy(get_scale(), y);
        }
        if (yes_no_menu != NULL && yes_no_menu->is_decided() != 0) {
            sel = yes_no_menu->get_selected_value();
            if (sel == 0) {
                if (texture_window != NULL) {
                    texture_window->close();
                    texture_window = NULL;
                }
                if (item_list != NULL) {
                    item_list->close();
                    item_list = NULL;
                }
                if (help_window != NULL) {
                    help_window->close();
                    help_window = NULL;
                }
                yes_no_menu->close();
                yes_no_menu = NULL;
                delete_item(player, selected_item.id, 1);
                judged_item.id = selected_item.id;
                player->request_inventory_item(&judged_item);
                set_judgment_target_flag(this, &judged_item);
                item = find_item_by_id(judged_item.id);
                if (item != NULL && (equipped = player->get_equipped_item(item->get_attach_slot())) != NULL) {
                    TObjPlayer::send_6x26_unequip_item(player, equipped->get_item_id());
                }
                send_6x25_equip_item(player, judged_item.id, 0);
                send_message(0xB, 1);
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file("miniclear.adx");
                }
                set_state(0);
            }
            if (sel == 1) {
                yes_no_menu->close();
                yes_no_menu = NULL;
                delete_item(player, selected_item.id, 1);
                judged_item.id = selected_item.id;
                player->request_inventory_item(&judged_item);
                set_judgment_target_flag(this, &judged_item);
                send_message(0xB, 1);
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file("miniclear.adx");
                }
                set_state(0);
            }
        }
        if (yes_no_menu != NULL && yes_no_menu->is_cancelled() != 0) {
            yes_no_menu->close();
            yes_no_menu = NULL;
            delete_item(player, selected_item.id, 1);
            judged_item.id = selected_item.id;
            player->request_inventory_item(&judged_item);
            set_judgment_target_flag(this, &judged_item);
            send_message(0xB, 1);
            if (TLobby::get_shop_value() > 0) {
                play_cue_stream_file("miniclear.adx");
            }
            set_state(0);
        }
    }
}

void TShopJudgmentItemWindow::update() {
    s32 c = this->timer - 1;
    this->timer = c;
    if (c <= 0 && is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        send_message(0xB, 1);
        set_state(0);
    }
}

void TShopJudgmentItemWindow::handle_pay_confirm() {
    s32 selected_menu_value;

    if (this->is_message_ready() != 0) {
        if (this->yes_no_menu == NULL) {
            this->yes_no_menu = create_yes_no_window(get_window_layout_position(0x2B), this->player->get_entity_id(), NULL, NULL);
            ((TWindowSubComCardList *)this->yes_no_menu)->set_selected_index(0);
            this->yes_no_menu->set_position_xy(get_scale(), get_scale());
        }
        if ((this->yes_no_menu != NULL) && (this->yes_no_menu->is_decided() != 0)) {
            selected_menu_value = this->yes_no_menu->get_selected_value();
            if (selected_menu_value == 0) {
                if (this->texture_window != NULL) {
                    this->texture_window->close();
                    this->texture_window = NULL;
                }
                if (this->item_list != NULL) {
                    this->item_list->close();
                    this->item_list = NULL;
                }
                if (this->help_window != NULL) {
                    this->help_window->close();
                    this->help_window = NULL;
                }
                if (this->result_item != NULL) {
                    this->result_item->queue_destruction();
                    this->result_item = NULL;
                }
                this->timer = 3;
                this->yes_no_menu->close();
                this->yes_no_menu = NULL;
                try_spend_actor_meseta(reinterpret_cast<TObjChara *>(this->player), 0x64);
                send_message(0xA, 1);
                this->set_state(5);
                return;
            }
            if (selected_menu_value == 1) {
                this->yes_no_menu->close();
                this->yes_no_menu = NULL;
                send_message(8, 1);
                this->set_state(4);
                return;
            }
            goto block_17;
        }
block_17:
        if ((this->yes_no_menu != NULL) && (this->yes_no_menu->is_cancelled() != 0)) {
            this->yes_no_menu->close();
            this->yes_no_menu = NULL;
            send_message(8, 1);
            this->set_state(4);
        }
    }
}

void TShopJudgmentItemWindow::invoke_callback_170_and_destroy() {
    void (*callback)(TShopWindowBase *);

    callback = this->on_cancel;
    if (callback != NULL) {
        callback(this->sequence);
        queue_destruction();
    }
}

void TShopJudgmentItemWindow::invoke_callback_16C_and_destroy() {
    void (*callback)(TShopWindowBase *);

    callback = this->m_16c;
    if (callback != NULL) {
        callback(this->sequence);
        queue_destruction();
    }
}

void TShopJudgmentItemWindow::invoke_callback_174_and_destroy() {
    void (*callback)(TShopWindowBase *);

    callback = this->on_close;
    if (callback != NULL) {
        callback(this->sequence);
        queue_destruction();
    }
}

void TShopJudgmentItemWindow::send_message(s32 id, s32 flags) {
    TShopWindowBase *sequence;

    sequence = this->sequence;
    if (sequence != NULL) {
        sequence->send_message(id, flags);
    }
}

void TShopJudgmentItemWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence;

    sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
