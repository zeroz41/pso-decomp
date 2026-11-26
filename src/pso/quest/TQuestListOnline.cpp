#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowShop.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/OnlineQuestMenuRecords.h"
#include "pso/quest/OnlineQuestDownloadState.h"
#include <stddef.h>
#include "pso/network/TProtocol.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/text_80222C28.h"


// A window's width and height.
struct WindowSize {
    f32 width;
    f32 height;
};

// Owner token for TLobby::tmp_buf_use_req/tmp_buf_release_if_owner, like TQuestListVM's tmp_buf_owner_name
static const char online_tmp_buf_owner_name[] = "quest_online";
const char *quest_list_online_class_name = "TQuestListOnline";
// Size of the description window build_list_window creates (TQuestListVM's description window uses the same size)
static const WindowSize online_description_window_size = {228.0f, 184.0f};
// Size of the info window show_info_window creates (TQuestListVM's detail window uses the same size)
static const WindowSize online_info_window_size = {332.0f, 210.0f};

TQuestListOnline *quest_list_online_instance;
u8 *quest_list_online_decompression_cursor;
u8 *online_quest_bin_data;
u8 *online_quest_dat_buffer;
s32 quest_bin_decompressed_size;
s32 online_quest_list_decompressed_size;
s32 online_quest_list_state;








struct UpdateStateObject { u8 pad[0x20]; u32 state; };

extern s32 __vt__16TQuestListOnline[];

void TWindowMenu::clear_flag_and_release() {
    uaddr temp;
    m_70 &= ~2;
    temp = reinterpret_cast<uaddr>(heading);
    if (temp != 0U) {
        ((TWindowSubStatusDisp *)temp)->set_entry_state(1);
    }
}

s32 TQuestListOnline::get_selection_stage() { return selection_stage; }

TQuestListOnline *TQuestListOnline__ct(TQuestListOnline *quest_list_online, TObject *parent,
                                     TShopWindowBase *sequence, TObjPlayer *player) {
    __ct__15TShopWindowBaseFP7TObject(quest_list_online, parent);
    *(s32 **)((s8 *)quest_list_online + 0x18) = __vt__16TQuestListOnline;
    __ct__13GameListEntryFv(&quest_list_online->selected_entry);
    quest_list_online->m_name = quest_list_online_class_name;
    quest_list_online->list_window = NULL;
    quest_list_online->description_window = NULL;
    quest_list_online->info_window = NULL;
    quest_list_online->confirm_window = NULL;
    quest_list_online->sequence = sequence;
    quest_list_online->selected_index = 0;
    quest_list_online->callback28 = NULL;
    quest_list_online->callback2c = NULL;
    quest_list_online->callback34 = NULL;
    quest_list_online->selection_stage = 0;
    quest_list_online->player = player;
    memset(&quest_list_online->selected_entry, 0, sizeof(quest_list_online->selected_entry));
    quest_list_online->set_state(0);
    quest_list_online_instance = quest_list_online;
    return quest_list_online;
}

TQuestListOnline::~TQuestListOnline() {
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
    if (description_window != NULL) {
        description_window->close();
        description_window = NULL;
    }
    if (info_window != NULL) {
        info_window->close();
        info_window = NULL;
    }
    if (confirm_window != NULL) {
        confirm_window->close();
        confirm_window = NULL;
    }
    quest_list_online_instance = 0;
}

void TQuestListOnline::update_state() {
    UpdateStateObject *arg0 = (UpdateStateObject *)this;
    switch (this->state) {
    case 0: ((TQuestListOnline*)arg0)->request_menu(); break;
    case 1: ((TQuestListOnline*)arg0)->build_list_window(); break;
    case 2: ((TQuestListOnline*)arg0)->show_info_window(); break;
    case 3: ((TQuestListOnline*)arg0)->handle_list_selection(); break;
    case 8: ((TQuestListOnline*)arg0)->handle_quest_confirm(); break;
    case 4: ((TQuestListOnline*)arg0)->begin_buffer_request(); break;
    case 5: ((TQuestListOnline*)arg0)->request_download_buffer(); break;
    case 6: ((TQuestListOnline*)arg0)->decompress_quest_list_buffers(); break;
    case 9: ((TQuestListOnline*)arg0)->invoke_callback_28_and_queue_destruction(); break;
    case 10: ((TQuestListOnline*)arg0)->invoke_callback_2c_and_queue_destruction(); break;
    case 7: ((TQuestListOnline*)arg0)->invoke_callback_30_and_queue_destruction(); break;
    case 11: ((TQuestListOnline*)arg0)->invoke_callback_34_and_queue_destruction(); break;
    case 12: return;
    }
}

void TQuestListOnline::request_menu() { TLobby::protocol_instance->send_quest_menu_request(); online_quest_bin_data = NULL; quest_bin_decompressed_size = 0; online_quest_dat_buffer = NULL; online_quest_list_decompressed_size = 0; set_state((saddr)((void*)12)); }

void TQuestListOnline::build_list_window() {
    s32 id;
    s32 off;
    s32 i;
    QuestListEntry *entry;
    if (sequence->is_message_ready() != 0) {
        if (list_window == NULL) {
            id = player->get_entity_id();
            list_window = create_item_list_window(get_guild_text(0), 0x40, id);
        } else {
            list_window->reset_list();
        }
        if (quest_list_online_quest_list_buffer != NULL && quest_list_online_quest_list_buffer->header.flags == 0) {
            set_state(0xB);
            return;
        }
        if (quest_list_online_quest_list_buffer != NULL) {
            for (i = 0, off = 0; i < quest_list_online_quest_list_buffer->header.flags; i++, off += sizeof(QuestListEntry)) {
                entry = (QuestListEntry *)((u8 *)&quest_list_online_quest_list_buffer->entries + off);
                switch (entry->tag.m_tag1) {
                case 0:
                    list_window->add_list_entry(0x2C, (saddr)entry->name, i);
                    break;
                case 1:
                    list_window->add_list_entry(0x17, (saddr)entry->name, i);
                    break;
                case 2:
                    list_window->add_list_entry(0x31, (saddr)entry->name, i);
                    break;
                default:
                    list_window->add_list_entry(0x17, (saddr)entry->name, i);
                    break;
                }
            }
            list_window->calc_content_extent();
        }
        if (description_window == NULL) {
            WindowSize size = online_description_window_size;
            description_window = TWindowMessage::create(get_window_layout_position(0x2D), (const f32 *)&size, 1);
            description_window->append_line((saddr)quest_list_online_quest_list_buffer->entries[0].short_description, (int)0x80);
        } else {
            description_window->append_line((saddr)quest_list_online_quest_list_buffer->entries[0].short_description, (int)0x80);
        }
        selected_index = 0;
        set_state(3);
    }
}

void TQuestListOnline::show_info_window() {
    s32 entity_id;
    if (info_window == NULL) {
        WindowSize size = online_info_window_size;
        entity_id = player->get_entity_id();
        info_window = TWindowMessage::create(get_window_layout_position(0x2E), (const f32 *)&size, 1, entity_id);
        info_window->set_depth(37000.0f);
        if (TCameraCtrl::get_camera_id() >= 2) {
            info_window->set_position_xy(0.75f, 0.75f);
        }
    }
    if (quest_list_online_selected_quest_info != NULL) {
        info_window->append_line((saddr)quest_list_online_selected_quest_info->text, (int)0x80);
    }
    this->set_state(3);
}

void TQuestListOnline::handle_list_selection() {
    if (sequence->is_message_ready() == 0) {
        return;
    }
    if (list_window != NULL) {
        s32 sel = list_window->get_cursor_value();
        if (description_window != NULL && sel != selected_index) {
            description_window->append_line((saddr)(quest_list_online_quest_list_buffer->entries[sel].short_description), (int)0x80);
        }
        if (info_window != NULL && sel != selected_index) {
            info_window->close();
            info_window = NULL;
        }
        selected_index = sel;
    }
    if (list_window != NULL && list_window->is_decided() != 0) {
        if (selection_stage == 0) {
            s32 idx = list_window->get_cursor_value();
            __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&selected_entry.tag, &quest_list_online_quest_list_buffer->entries[idx].tag);
            switch (quest_list_online_quest_list_buffer->entries[idx].tag.m_tag0) {
            case 1:
                online_quest_list_state = 0;
                break;
            case 2:
                online_quest_list_state = 1;
                break;
            default:
                online_quest_list_state = 0;
                break;
            }
            TLobby::protocol_instance->send_action(selected_entry, get_unlocked_tier(), "", "");
            if (description_window != NULL) {
                description_window->close();
                description_window = NULL;
            }
            list_window->close();
            list_window = NULL;
            set_state(0xC);
            selection_stage++;
            return;
        } else if (selection_stage == 1) {
            s32 idx = list_window->get_cursor_value();
            __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&selected_entry.tag, &quest_list_online_quest_list_buffer->entries[idx].tag);
            TLobby::protocol_instance->send_info(selected_entry.tag);
            set_state(0xC);
            selection_stage++;
            return;
        } else if (selection_stage == 2) {
            if (confirm_window == NULL) {
                s32 id = player->get_entity_id();
                confirm_window = create_yes_no_window(get_window_layout_position(0x2B), id, NULL, NULL);
                confirm_window->set_position_xy(get_scale(), get_scale());
                if (sequence != NULL) {
                    sequence->display_guild_message(5, 1);
                }
                set_state(8);
            }
        }
    }
    if (list_window != NULL && list_window->is_cancelled() != 0) {
        set_state(9);
    }
}

void TQuestListOnline::begin_buffer_request() { set_state(5); }

void TQuestListOnline::request_download_buffer() {
    if (TLobby::tmp_buf_is_free() != 0) {
        quest_list_online_decompression_cursor = TLobby::tmp_buf_use_req(online_tmp_buf_owner_name);
        set_state(6);
    }
}

#pragma push
#pragma optimization_level 2
#pragma dont_inline on
void TQuestListOnline::decompress_quest_list_buffers() {
    quest_bin_decompressed_size = prs_decompress_buffer(quest_list_online_bin_download_state.buffer, quest_list_online_decompression_cursor);
    online_quest_bin_data = quest_list_online_decompression_cursor;
    quest_list_online_decompression_cursor += quest_bin_decompressed_size;
    online_quest_list_decompressed_size = prs_decompress_buffer(quest_list_online_dat_download_state.buffer, quest_list_online_decompression_cursor);
    online_quest_dat_buffer = quest_list_online_decompression_cursor;
    set_state((saddr)((void *)7));
}
#pragma pop

void TQuestListOnline::handle_quest_confirm() {
    s32 v;
    s32 n;
    if (this->confirm_window != NULL && this->confirm_window->is_decided() != 0) {
        v = this->confirm_window->get_selected_value();
        if (v == 0) {
            if (THunterGuildSeqOffline::check_party_gathered() == 1) {
                if (this->sequence != NULL) {
                    sequence->display_guild_message(0x14, 1);
                }
                TLobby::protocol_instance->send_action(selected_entry, 0, "", "");
                this->confirm_window->queue_destruction();
                this->confirm_window = NULL;
                if (this->info_window != NULL) {
                    this->info_window->queue_destruction();
                    this->info_window = NULL;
                }
                if (this->description_window != NULL) {
                    this->description_window->queue_destruction();
                    this->description_window = NULL;
                }
                if (this->list_window != NULL) {
                    this->list_window->queue_destruction();
                    this->list_window = NULL;
                }
                set_state(0xC);
                return;
            }
            if (this->sequence != NULL) {
                sequence->display_guild_message(0x10, 1);
            }
            ((TWindowMenu *)(this->confirm_window))->clear_flag_and_release();
            return;
        }
        if (v == 1) {
            this->confirm_window->close();
            this->confirm_window = NULL;
            if (this->info_window != NULL) {
                this->info_window->close();
                this->info_window = NULL;
            }
            if (this->list_window != NULL) {
                this->list_window->clear_decided();
            }
            n = selection_stage;
            selection_stage = n - 1;
            close_windows();
            if (this->sequence != NULL) {
                sequence->display_guild_message(0x19, 1);
            }
            set_state(1);
            return;
        }
    }
    if (this->confirm_window != NULL && this->confirm_window->is_cancelled() != 0) {
        this->confirm_window->close();
        this->confirm_window = NULL;
        if (this->info_window != NULL) {
            this->info_window->close();
            this->info_window = NULL;
        }
        if (this->list_window != NULL) {
            this->list_window->clear_decided();
        }
        n = selection_stage;
        selection_stage = n - 1;
        close_windows();
        if (this->sequence != NULL) {
            sequence->display_guild_message(0x19, 1);
        }
        set_state(1);
    }
}

void TQuestListOnline::invoke_callback_30_and_queue_destruction() {
    void (*callback)();

    callback = callback30;
    if (callback != NULL) {
        callback();
    }
    queue_destruction();
}

void TQuestListOnline::ensure_online_quests_loaded() {
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release_if_owner(online_tmp_buf_owner_name);
    }
}

void TQuestListOnline::invoke_callback_28_and_queue_destruction() {
    void (*callback)();

    callback = callback28;
    if (callback != NULL) {
        callback();
    }
    queue_destruction();
}

void TQuestListOnline::invoke_callback_34_and_queue_destruction() {
    void (*callback)();

    callback = callback34;
    if (callback != NULL) {
        callback();
    }
    queue_destruction();
}

void TQuestListOnline::invoke_callback_2c_and_queue_destruction() {
    void (*callback)();

    callback = callback2c;
    if (callback != NULL) {
        callback();
    }
    queue_destruction();
}

s32 TQuestListOnline::init() {
    quest_list_online_decompression_cursor = NULL;
    if (TLobby::tmp_buf_is_free() != 0) {
        quest_list_online_decompression_cursor = TLobby::tmp_buf_use_req(online_tmp_buf_owner_name);
        return 1;
    }
    return 0;
}

void TQuestListOnline::decompress_quest_buffer(const u8 *data, s32) {
    s32 decompressed_size;
    if (quest_list_online_decompression_cursor != NULL) {
        decompressed_size = prs_decompress_buffer(data, quest_list_online_decompression_cursor);
        quest_bin_decompressed_size = decompressed_size;
        online_quest_bin_data = quest_list_online_decompression_cursor;
        quest_list_online_decompression_cursor += decompressed_size;
    }
}

extern "C" void TQuestListOnline__sub_802176DC(const u8 *data, s32) {
    if (quest_list_online_decompression_cursor != NULL) {
        online_quest_list_decompressed_size = prs_decompress_buffer(data, quest_list_online_decompression_cursor);
        online_quest_dat_buffer = quest_list_online_decompression_cursor;
    }
}

void TQuestListOnline::close_windows() {
    if (confirm_window != NULL) {
        this->confirm_window->close();
        confirm_window = NULL;
    }
    if (info_window != NULL) {
        this->info_window->close();
        info_window = NULL;
    }
    if (description_window != NULL) {
        this->description_window->close();
        description_window = NULL;
    }
    if (list_window != NULL) {
        this->list_window->close();
        list_window = NULL;
    }
}

u8 TQuestListOnline::get_unlocked_tier() {
    if (is_challenge_mode() != 0) {
        switch (online_quest_list_state) {
        case 0:
            return (u8) party_min_cleared_stages(0);
        case 1:
            return (u8) party_min_cleared_stages(1);
        default:
            return 0U;
        }
    } else {
        if (get_story_flag(0x33) != 0) {
            return 4U;
        }
        if (get_story_flag(0x2A) != 0) {
            return 3U;
        }
        if (get_story_flag(0x20) != 0) {
            return 2U;
        }
        return (u8) (get_story_flag(0x17) != 0);
    }
}

int TQuestListOnline::get_selected_quest_id() {
    if (quest_list_online_instance != NULL && quest_list_online_instance->info_window != NULL) {
        return quest_list_online_selected_quest_info->header.flags;
    }
    return -1;
}

#pragma push
#pragma fp_contract on
const char *TQuestListOnline::get_selected_entry() {
    TQuestListOnline *list = quest_list_online_instance;
    if (list != NULL) {
        TWindowMenuIconLine *window = list->list_window;
        if (window != NULL && quest_list_online_quest_list_buffer != NULL) {
            return quest_list_online_quest_list_buffer->entries[window->get_cursor_value()].name;
        }
    }
    return NULL;
}
#pragma pop

s32 TQuestListOnline::get_list_state() {
    if ((void *) quest_list_online_instance == NULL) {
        return 0;
    }
    if (quest_list_online_instance->list_window == NULL) {
        return 0;
    }
    switch (quest_list_online_instance->get_selection_stage()) {
    case 0:
        return 1;
    case 1:
    case 2:
        switch (online_quest_list_state) {
        case 0:
            return 2;
        case 1:
            return 3;
        default:
            return 2;
        }
    default:
        return 0;
    }
}
