#define TOBJECT_OUT_OF_LINE_HELPERS
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TObject.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowSubComCard_80265410.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/Language.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"

// A file read from a memory card.
struct CardFileRead {
    u8 pad_0[0x58];
    u8 *data;
    s32 size;
};

// A window's width and height.
struct WindowSize {
    f32 width;
    f32 height;
};

extern "C" {
s32 TAdPlayerLoadGC__sub_801E1B50(s32 card_slot);
s32 TAdPlayerLoadGC__sub_801E1538(CardFileRead *file, void *buffer);
void *get_window_layout_position(s32 index);
extern s32 evt2_random_enemies_mode;
}

extern const char quest_file_prefix[] = "PSO______0";
extern const char quest_file_99_name[] = "PSO______099";
extern const s32 quest_file_first_index = 4;
extern const s32 quest_file_index_limit = 0x5F;

static const char download_list_title_jp[] = "\x83\x5F\x83\x45\x83\x93\x83\x8D\x81\x5B\x83\x68"; // ダウンロード
static const char download_list_title[] = "Down Load";
static const char tmp_buf_owner_name[] = "quest_vm_load";
const char *TQuestListVM_class_name = "TQuestListVM";
static const WindowSize description_window_size = {228.0f, 184.0f};
static const WindowSize detail_window_size = {332.0f, 210.0f};
static const char quest_file_name_format[] = "%s%02d";

u8 *decrypted_quest_buffer;
u32 decompression_capacity;
u8 *quest_data_output_cursor;
u32 quest_decrypt_result_size;
TQuestListVM *quest_list_vm_instance;

void seed_download_rng(s32 seed) {
    download_rng_seed_pair[1] = seed;
    download_rng_seed_pair[0] = seed;
}

void TWindowMenuIconLine::disable_cancel() {
    state_flags |= 8;
}

TQuestListVM::TQuestListVM(TObject *parent, TShopWindowBase *owner, TObjBase *player) {
    m_name = TQuestListVM_class_name;
    entry_count = 0;
    resume_state = 0;
    list_window = NULL;
    description_window = NULL;
    detail_window = NULL;
    confirm_window = NULL;
    tmp_buffer = NULL;
    card_buffer = TQuestVmDownLoadServer::alloc(0x20000);
    unk_2390 = 0;
    decrypted_quest_buffer = NULL;
    decompression_capacity = 0;
    quest_data_output_cursor = NULL;
    quest_decrypt_result_size = 0;
    scan_index = 4;
    scan_card_slot = 0;
    this->owner = owner;
    on_close = NULL;
    on_error = NULL;
    on_finish = NULL;
    set_field_20(0);
    quest_list_vm_instance = this;
    this->player = player;
    prev_card_mask = 0;
    card_mask = 0;
    update_load_status();
    scan_card_error = 0;
    scan_download_error = 0;
    deferred_state = 0;
}

TQuestListVM::~TQuestListVM() {
    if (detail_window != NULL) {
        detail_window->close();
        detail_window = NULL;
    }
    if (description_window != NULL) {
        description_window->close();
        description_window = NULL;
    }
    if (confirm_window != NULL) {
        confirm_window->close();
        confirm_window = NULL;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
    if (card_buffer != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((u32)card_buffer);
        card_buffer = NULL;
    }
    quest_list_vm_instance = NULL;
    TLobby::tmp_buf_release_if_owner(tmp_buf_owner_name);
}

void TQuestListVM::vfunc_11() {
    if (update_load_status() != 0) {
        display_message((const char *)TQuestVmDownLoadServer__sub_8006EF6C(0x44), 1);
        set_field_20(0x12);
    }
    switch (state) {
    case 0:
        init();
        return;
    case 1:
        load_quest_vm();
        return;
    case 2:
        scan_memcard_quest_files();
        return;
    case 3:
        load_selected_player_slot();
        return;
    case 4:
        process_download_entry();
        return;
    case 5:
        build_download_list();
        return;
    case 6:
        update_lobby_selection();
        return;
    case 7:
        quest_vm_load();
        return;
    case 8:
        load_selected_bin();
        return;
    case 9:
        poll_quest_download();
        return;
    case 15:
        open_confirm_window();
        return;
    case 10:
        handle_confirm_window();
        return;
    case 11:
        load_selected_slot();
        return;
    case 12:
        load_downloaded_quest();
        return;
    case 13:
        update_close();
        return;
    case 14:
        idle();
        return;
    case 16:
        close();
        return;
    case 18:
        close_and_destroy();
        return;
    case 17:
        invoke_callback_and_queue_destruction();
        return;
    case 20:
        wait_for_message();
    default:
        return;
    }
}

void TQuestListVM::init() {
    memset(entries, 0, sizeof(entries));
    scan_index = 4;
    entry_count = 0;
    scan_card_slot = 0;
    described_entry = 0;
    scan_card_error = 0;
    scan_download_error = 0;
    set_field_20(1);
}

void TQuestListVM::load_quest_vm() {
    if (TLobby::tmp_buf_is_free() != 0) {
        tmp_buffer = (u8 *)TLobby::tmp_buf_use_req(tmp_buf_owner_name);
        decrypted_quest_buffer = tmp_buffer;
        decompression_capacity = 0x40000;
        set_field_20(2);
        display_message((const char *)TQuestVmDownLoadServer__sub_8006EF6C(0x3F), 1);
    }
}

void TQuestListVM::scan_memcard_quest_files() {
    char file_name[13];
    s32 has_dat;
    while (scan_index < quest_file_index_limit) {
        memset(file_name, 0, 0xD);
        sprintf(file_name, quest_file_name_format, quest_file_prefix, scan_index + 1);
        switch (TAdPlayerLoadGC::find_card_file(scan_card_slot, file_name)) {
        case 0:
            has_dat = 1;
            break;
        case -191:
            has_dat = 0;
            scan_card_error = 1;
            break;
        case -255:
        case -253:
        case -251:
        case -1:
        default:
            has_dat = 0;
            break;
        }
        memset(file_name, 0, 0xD);
        sprintf(file_name, quest_file_name_format, quest_file_prefix, scan_index);
        switch (TAdPlayerLoadGC::find_card_file(scan_card_slot, file_name)) {
        case 0:
            if (has_dat == 0) {
                scan_card_error = 1;
                break;
            }
            strcpy(entries[entry_count].file_name, file_name);
            entries[entry_count].file_index = scan_index;
            entries[entry_count].card_slot = scan_card_slot;
            set_field_20(3);
            return;
        case -191:
            scan_card_error = 1;
            break;
        case -251:
            if (has_dat != 0) {
                scan_card_error = 1;
            }
            break;
        case -255:
        case -253:
        case -1:
        default:
            break;
        }
        scan_index += 2;
    }
    if (scan_card_slot < 7) {
        scan_card_slot++;
        scan_index = 0;
        return;
    }
    if (entry_count != 0) {
        if (scan_download_error != 0) {
            display_guild_message(0x1B, 1);
            set_state_after_message(5);
            return;
        }
        if (scan_card_error != 0) {
            display_message((const char *)TQuestVmDownLoadServer__sub_8006EF6C(0x66), 1);
            set_state_after_message(5);
            return;
        }
        display_guild_message(0x19, 1);
        set_field_20(5);
        return;
    }
    if (scan_download_error != 0) {
        display_guild_message(0x1B, 1);
        set_field_20(0x12);
        return;
    }
    if (scan_card_error != 0) {
        display_message((const char *)TQuestVmDownLoadServer__sub_8006EF6C(0x66), 1);
        set_field_20(0x12);
        return;
    }
    display_message((const char *)TQuestVmDownLoadServer__sub_8006EF6C(0x44), 1);
    set_field_20(0x12);
}

void TQuestListVM::load_selected_player_slot() {
    if (card_buffer != NULL) {
        if (TAdPlayerLoadGC__sub_801E1B50(entries[entry_count].card_slot) == 0) {
            if (TAdSinglePlyChrSelectGC::load_player_slot(entries[entry_count].card_slot,
                                                          entries[entry_count].file_name, card_buffer) == 0) {
                set_field_20(4);
                return;
            }
            scan_index += 2;
            set_field_20(2);
        }
    } else {
        set_field_20(0x12);
    }
}

void TQuestListVM::process_download_entry() {
    CardFileRead file;
    QuestBinHeader *header;

    if (TAdPlayerLoadGC__sub_801E1B50(entries[entry_count].card_slot) == 0) {
        switch (TAdPlayerLoadGC__sub_801E1538(&file, card_buffer)) {
        case 0:
            seed_download_rng(get_download_seed());
            TQuestVmDownLoadServer::unshuffle_and_decrypt(file.data, file.size);
            if (TQuestVmDownLoadServer::verify_checksum(file.data, file.size) == 0) {
                scan_download_error = 1;
                scan_index += 2;
                set_field_20(2);
            } else if (decrypt_quest_data(file.data + 8, file.size - 8, decrypted_quest_buffer,
                                          decompression_capacity) != 0) {
                header = (QuestBinHeader *)decrypted_quest_buffer;
                if (is_downloadable_new_entry(header) != 0) {
                    memcpy(entries[entry_count].title, header->name, 0x20);
                    memcpy(entries[entry_count].description, header->short_description, 0x80);
                    entries[entry_count].episode = header->episode;
                    entry_count++;
                }
                scan_index += 2;
                set_field_20(2);
            } else {
                scan_download_error = 1;
                scan_index += 2;
                set_field_20(2);
            }
            break;
        case -0xDF:
            scan_download_error = 1;
            scan_index += 2;
            set_field_20(2);
            break;
        case -0xE0:
            scan_download_error = 1;
            scan_index += 2;
            set_field_20(2);
            break;
        }
    }
}

s32 TQuestListVM::is_downloadable_new_entry(QuestBinHeader *header) {
    s32 i;
    if (header->language == -1 || header->quest_number == -1) {
        return 0;
    }
    if (header->language != current_language) {
        return 0;
    }
    if (header->unk_11 != 0 && header->unk_11 != 2) {
        return 0;
    }
    for (i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].title, header->name) == 0) {
            return 0;
        }
    }
    return 1;
}

void TQuestListVM::build_download_list() {
    s32 i;
    if (vfunc_10() != 0) {
        if (list_window != NULL) {
            list_window->reset_list();
        } else {
            switch (current_language) {
            case LANGUAGE_JAPANESE:
                list_window = (TWindowMenuIconLine *)create_item_list_window((s32)download_list_title_jp, 0x40, get_entity_id(player));
                break;
            case LANGUAGE_ENGLISH:
            case LANGUAGE_GERMAN:
            case LANGUAGE_FRENCH:
            case LANGUAGE_SPANISH:
            default:
                list_window = (TWindowMenuIconLine *)create_item_list_window((s32)download_list_title, 0x40, get_entity_id(player));
                break;
            }
        }
        if (list_window != NULL) {
            for (i = 0; i < entry_count; i++) {
                switch (entries[i].episode) {
                case 0:
                    list_window->add_list_entry(0x17, (s32)entries[i].title, i);
                    break;
                case 1:
                    list_window->add_list_entry(0x31, (s32)entries[i].title, i);
                    break;
                default:
                    list_window->add_list_entry(0x17, (s32)entries[i].title, i);
                    break;
                }
            }
            list_window->calc_content_extent();
            set_field_20(6);
        }
        if (description_window == NULL) {
            WindowSize size = description_window_size;
            description_window = (TWindowMessage *)TWindowMessage::create(get_window_layout_position(0x2D), (s32)&size, 1);
            description_window->append_line((int)entries[0].description, 0x80);
            described_entry = 0;
        }
    }
}

void TQuestListVM::update_lobby_selection() {
    s32 index;

    if (list_window != NULL && list_window->is_cancelled() != 0) {
        set_field_20(0x10);
        return;
    }
    if (list_window != NULL && list_window->is_decided() != 0) {
        resume_state = 0xA;
        set_field_20(8);
        return;
    }
    if (list_window != NULL && description_window != NULL) {
        index = list_window->get_cursor_value();
        if (index != described_entry) {
            description_window->append_line((int)entries[index].description, 0x80);
            described_entry = index;
            if (detail_window != NULL) {
                detail_window->close();
                detail_window = NULL;
            }
        }
    }
}

void TQuestListVM::quest_vm_load() {
    if (TLobby::tmp_buf_is_free() != 0) {
        tmp_buffer = (u8 *)TLobby::tmp_buf_use_req(tmp_buf_owner_name);
        set_field_20(resume_state);
    }
}

void TQuestListVM::load_selected_bin() {
    s32 index;
    if (list_window != NULL && card_buffer != NULL) {
        index = list_window->get_cursor_value();
        if (TAdPlayerLoadGC__sub_801E1B50(entries[index].card_slot) == 0) {
            if (TAdSinglePlyChrSelectGC::load_player_slot(entries[index].card_slot, entries[index].file_name,
                                                          card_buffer) == 0) {
                set_field_20(9);
                return;
            }
            display_guild_message(0x19, 1);
            close_windows();
            set_field_20(5);
        }
    }
}

void TQuestListVM::poll_quest_download() {
    CardFileRead file;
    u32 size;
    if (list_window != NULL) {
        if (TAdPlayerLoadGC__sub_801E1B50(entries[list_window->get_cursor_value()].card_slot) == 0) {
            switch (TAdPlayerLoadGC__sub_801E1538(&file, card_buffer)) {
            case 0:
                seed_download_rng(get_download_seed());
                TQuestVmDownLoadServer::unshuffle_and_decrypt(file.data, file.size);
                if (TQuestVmDownLoadServer::verify_checksum(file.data, file.size) == 0) {
                    scan_index += 2;
                    display_guild_message(0x1A, 1);
                    set_state_after_message(5);
                    close_windows();
                } else {
                    size = decrypt_quest_data(file.data + 8, file.size - 8, decrypted_quest_buffer,
                                              decompression_capacity);
                    if (size != 0) {
                        quest_data_output_cursor = decrypted_quest_buffer + size;
                        quest_decrypt_result_size = decompression_capacity - size;
                        set_field_20(0xF);
                    } else {
                        display_guild_message(0x1A, 1);
                        set_state_after_message(5);
                        close_windows();
                    }
                }
                break;
            case -0xDF:
                display_guild_message(0x1A, 1);
                close_windows();
                set_field_20(5);
                break;
            case -0xE0:
                display_guild_message(0x1A, 1);
                close_windows();
                set_field_20(5);
                break;
            }
        }
    }
}

void TQuestListVM::open_confirm_window() {
    if (detail_window == NULL) {
        WindowSize size = detail_window_size;
        detail_window = (TWindowMessage *)TWindowMessage::create((s32)get_window_layout_position(0x2E), (s32)&size, 1, get_entity_id(player));
        detail_window->append_line((int)((QuestBinHeader *)decrypted_quest_buffer)->long_description, 1);
        detail_window->set_depth(-13000.0f);
        if (TCameraCtrl::get_camera_id() >= 2) {
            detail_window->set_position_xy(0.75f, 0.75f);
        }
    }
    if (detail_window != NULL) {
        if (resume_state != 0xA) {
            set_field_20(resume_state);
            return;
        }
        confirm_window = (TWindowMenu *)create_yes_no_window((s32)get_window_layout_position(0x2B), get_entity_id(player), 0, 0);
        confirm_window->set_position_xy(get_scale(), get_scale());
        display_guild_message(5, 1);
        set_field_20(resume_state);
    }
}

void TQuestListVM::handle_confirm_window() {
    if (confirm_window != NULL) {
        if (confirm_window->is_decided() != 0) {
            switch (confirm_window->get_selected_value()) {
            case 0:
                confirm_window->close();
                confirm_window = NULL;
                set_field_20(0xB);
                return;
            case 1:
                confirm_window->close();
                confirm_window = NULL;
                if (detail_window != NULL) {
                    detail_window->close();
                    detail_window = NULL;
                }
                if (list_window != NULL) {
                    list_window->clear_decided();
                }
                decrypted_quest_buffer = tmp_buffer;
                decompression_capacity = 0x40000;
                display_guild_message(0x19, 1);
                close_windows();
                set_field_20(5);
                return;
            }
        }
        if (confirm_window->is_cancelled() != 0) {
            confirm_window->close();
            confirm_window = NULL;
            if (detail_window != NULL) {
                detail_window->close();
                detail_window = NULL;
            }
            if (list_window != NULL) {
                list_window->clear_decided();
            }
            decrypted_quest_buffer = tmp_buffer;
            decompression_capacity = 0x40000;
            display_guild_message(0x19, 1);
            close_windows();
            set_field_20(5);
        }
    }
}

void TQuestListVM::load_selected_slot() {
    char file_name[0xD];
    s32 index;
    memset(file_name, 0, 0xD);
    if (list_window != NULL && card_buffer != NULL) {
        index = list_window->get_cursor_value();
        if (TAdPlayerLoadGC__sub_801E1B50(entries[index].card_slot) == 0) {
            sprintf(file_name, quest_file_name_format, quest_file_prefix, entries[index].file_index + 1);
            if (TAdSinglePlyChrSelectGC::load_player_slot(entries[index].card_slot, file_name, card_buffer) == 0) {
                set_field_20(0xC);
                return;
            }
            display_guild_message(0x19, 1);
            close_windows();
            set_field_20(5);
        }
    }
}

void TQuestListVM::load_downloaded_quest() {
    CardFileRead file;
    u32 size;
    if (list_window != NULL) {
        if (TAdPlayerLoadGC__sub_801E1B50(entries[list_window->get_cursor_value()].card_slot) == 0) {
            switch (TAdPlayerLoadGC__sub_801E1538(&file, card_buffer)) {
            case 0:
                seed_download_rng(get_download_seed());
                TQuestVmDownLoadServer::unshuffle_and_decrypt(file.data, file.size);
                if (TQuestVmDownLoadServer::verify_checksum(file.data, file.size) == 0) {
                    scan_index += 2;
                    display_guild_message(0x1A, 1);
                    set_state_after_message(5);
                    close_windows();
                } else {
                    size = decrypt_quest_data(file.data + 8, file.size - 8, quest_data_output_cursor,
                                              quest_decrypt_result_size);
                    if (size != 0) {
                        quest_decrypt_result_size = size;
                        set_field_20(0xD);
                    } else {
                        display_guild_message(0x1A, 1);
                        set_state_after_message(5);
                        close_windows();
                    }
                }
                break;
            case -0xDF:
                display_guild_message(0x1A, 1);
                close_windows();
                set_field_20(5);
                break;
            case -0xE0:
                display_guild_message(0x1A, 1);
                close_windows();
                set_field_20(5);
                break;
            }
        }
    }
}

void TQuestListVM::update_close() {
    if (list_window != NULL && list_window->is_cancelled() != 0) {
        if (detail_window != NULL) {
            detail_window->close();
            detail_window = NULL;
        }
        if (list_window != NULL) {
            list_window->clear_decided();
            list_window->disable_cancel();
        }
        display_guild_message(0x19, 1);
        close_windows();
        set_field_20(5);
        return;
    }
    if (list_window != NULL && list_window->is_decided() != 0) {
        set_field_20(0x11);
    }
}

void TQuestListVM::idle() {}

void TQuestListVM::close() {
    void (*callback)() = on_close;
    if (callback != NULL) {
        callback();
    }
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release(tmp_buf_owner_name);
    }
    TQuestListVM::reset();
    queue_destruction();
}

void TQuestListVM::close_and_destroy() {
    void (*callback)() = on_error;
    if (callback != NULL) {
        callback();
    }
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release(tmp_buf_owner_name);
    }
    queue_destruction();
}

void TQuestListVM::invoke_callback_and_queue_destruction() {
    void (*callback)() = on_finish;
    if (callback != NULL) {
        callback();
    }
    queue_destruction();
}

void TQuestListVM::wait_for_message() {
    if (vfunc_10() != 0) {
        display_guild_message(0x19, 1);
        set_field_20(deferred_state);
    }
}

void TQuestListVM::load_vm() {
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release(tmp_buf_owner_name);
    }
    evt2_random_enemies_mode = 0;
}

void TQuestListVM::set_enemy_mode_3() {
    TLobby::set_enemy_mode_flag();
    evt2_random_enemies_mode = 3;
    TKeyBoardControl__sub_8000F950();
}

void TQuestListVM::close_windows() {
    if (confirm_window != NULL) {
        confirm_window->close();
        confirm_window = NULL;
    }
    if (detail_window != NULL) {
        detail_window->close();
        detail_window = NULL;
    }
    if (description_window != NULL) {
        description_window->close();
        description_window = NULL;
    }
    if (list_window != NULL) {
        list_window->close();
        list_window = NULL;
    }
}

s32 TQuestListVM::update_load_status() {
    s32 slot = 0;
    card_mask = 0;
    do {
        if (TAdPlayerLoadGC::probe_card_slot(slot) != 0) {
            card_mask = card_mask | (1 << slot);
        }
        slot += 1;
    } while (slot < 2);
    if (card_mask != prev_card_mask) {
        prev_card_mask = card_mask;
        return 1;
    }
    return 0;
}

void TQuestListVM::vfunc_6() {
    if (owner != NULL) {
        owner->vfunc_6();
    }
}

void TQuestListVM::display_message(const char *text, s32 flags) {
    if (owner != NULL) {
        owner->display_message(text, flags);
    }
}

void TQuestListVM::display_guild_message(s32 index, s32 flags) {
    if (owner != NULL) {
        owner->display_guild_message(index, flags);
    }
}

int TQuestListVM::vfunc_10() {
    if (owner != NULL) {
        if (owner->vfunc_10() == 0) {
            return 0;
        }
        return sub_80223A48() ? 1 : 0;
    }
    return 1;
}

u32 TQuestListVM::get_download_seed() {
    u32 seed = TQuestVmDownLoadServer::get_serial_access();
    if (seed == 0) {
        seed = TQuestVmDownLoadServer::poll_serial_access();
    }
    return seed;
}

void TQuestListVM::set_state_after_message(s32 state) {
    set_field_20(20);
    deferred_state = state;
}
