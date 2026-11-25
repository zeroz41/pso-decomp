#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/item/item_create.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/system/save/CardFileInfo.h"
#include <string.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/card.h>
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/player/TObjPlayer_802C367C.h"
#include "pso/player/TPlyCharData.h"
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/ui/window/TWindowShortListCtrl_8026E7DC.h"
#include "pso/unk/text_801F498C.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/system/date.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"
#include "pso/map/FloorArea.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/network/NetworkConnect.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_802C3AC0.h"
CharacterFile *card_character_save_buffer;
CharacterFile *secondary_card_character_save_buffer;
TPlyCharData *selected_character_data;
CharacterSaveRecord *active_character_save_record;
GuildCardSaveData *guild_card_save_payload;
SystemSaveData *system_save_payload;
SystemSaveData *secondary_card_system_save_payload;
s32 TAdSinglePlyChrSelectGC::selection_index;
s32 card_load_sequence_state;
saddr character_save_card_slot;
saddr card_load_channel;
saddr character_save_file_block_count;
saddr guild_card_save_file_block_count;
saddr system_save_card_channel;
saddr system_save_file_block_count;
u8 *character_save_file_buffer;
u8 *guild_card_save_file_buffer;
u8 *system_save_file_buffer;
s32 chr_select_scene_state;
s32 chr_select_game_mode;
s32 card_load_followup_pending;
s32 chr_select_save_slot;
char chr_select_game_name_buffer[4];
CharacterCardMetadata pso_character_card_filename = {
    "PSO_CHARACTER", "CHARACTER_FILE", 0,
    { 0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'T', 'T', 'T', 'U' },
};
char pso_system_card_filename[0x20] = "PSO_SYSTEM";
char memory_card_system_dir_name[0x20] = "PSO3_SYSTEM";
char memory_card_character_dir_name[0x20] = "PSO3_CHARACTER";
EpisodeCardMetadata episode_i_and_ii_card_filename = {
    "EPISODE I & II", "SYSTEM_FILE", 0,
    { 0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'U', 'T', 'T', 'T' },
};
GuildCardFile_804C89BC pso_guildcard_card_filename = {
    "PSO_GUILDCARD", "GUILDCARD_FILE", 0, "PSO______000", "PSOV2/DOWNLOAD", 0,
};
u8 quest_memcard_key[0x10] = {
    0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'V', 'T', 'T', 'T',
};
const char memcard_default_banner[4] = "\xF0\x04";
const char memcard_default_icon[4] = "\x04";

s32 lbl_805137C8[4];
uaddr chr_select_buffer_ptr_table[8];
CharacterSelectionRequest chr_select_request_buffer;
SubtractiveRng chr_select_rng_state;

u32 char_select_date_stamp[3];
s32 chr_select_serial_seeds[2];
s32 lbl_80513918[2];

struct Obj_801FCBA0 {
    void* a[4];
    void* b[4];
};

struct Hdr_801FBFD0 {
    u32 sum;
    u8 pad4[0x118 - 0x4];
    s32 f118;
    u8 pad11C[0x12C - 0x11C];
};

struct Buf_801FBFD0 {
    u8 pad0[0x2048];
    Hdr_801FBFD0 hdr;
};

struct Buf_801FBFD0;

extern "C" {
extern s32 memcard_access_active;

// Save-message window position and size (the same rect as TSaveChCr's message window).
static const NJS_POINT2 chr_select_save_message_window_pos = { 46.0f, 131.0f };
static const NJS_POINT2 chr_select_save_message_window_size = { 548.0f, 220.0f };
// Game code written over the memory card disk ID.
static const char card_disk_game_code[] = "GPSE";

void __construct_array(void*, void*, void*, int, int);
s32 start_memcard_read(s32, char *, void *, s32);
void clear_equipped_flag(void *item);
int is_unit_item_data(void *entry);
s32 TLobby__sub_8030A770();
}


void TAdSinglePlyChrSelectGC::copy_name(s32 chan) {
    if (chan >= 0) {
        // The character screen replaces the game code in the active disk ID.
        DVDDiskID *disk_id = const_cast<DVDDiskID *>(CARDGetDiskID(chan));
        if (disk_id != NULL) {
            strncpy(disk_id->gameName, chr_select_game_name_buffer, sizeof(disk_id->gameName));
        }
    }
}

void TAdSinglePlyChrSelectGC::set_card_disk_id(s32 chan) {
    if (chan >= 0) {
        // The character screen replaces the game code in the active disk ID.
        DVDDiskID *disk_id = const_cast<DVDDiskID *>(CARDGetDiskID(chan));
        if (disk_id != NULL) {
            strncpy(disk_id->gameName, card_disk_game_code, sizeof(disk_id->gameName));
        }
    }
}

s32 TAdSinglePlyChrSelectGC::load_system_file(s32 chan, s32 *out_value) {
    s32 ok;
    Buf_801FBFD0 *buf;
    u32 sum;
    s32 v;
    u32 r;
    Hdr_801FBFD0 *h;
    if (poll_memcard_result(chan) != 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::find_card_file(chan, memory_card_system_dir_name) != 0) {
        return 0;
    }
    memcard_access_active = 1;
    TAdSinglePlyChrSelectGC::set_card_disk_id(chan);
    ok = 0;
    buf = (Buf_801FBFD0 *)TQuestVmDownLoadServer::alloc(0x6000);
    if (TAdSinglePlyChrSelectGC::load_player_slot(chan, memory_card_system_dir_name, buf) == 0 &&
        TAdSinglePlyChrSelectGC::wait_for_card_load(chan) == 1) {
        h = &buf->hdr;
        v = h->f118;
        ok = 1;
        *out_value = v;
        sum = h->sum;
        h->sum = 0;
        r = calc_crc32_bitwise((u8 *)h, (u32)(sizeof(Hdr_801FBFD0)));
        if (r != sum) {
            ok = 0;
        }
    }
    safe_free(buf);
    TAdSinglePlyChrSelectGC::copy_name(chan);
    memcard_access_active = 0;
    return ok;
}

s32 TAdSinglePlyChrSelectGC::init_char_slot_record() {
    CharacterSaveRecord *record = (CharacterSaveRecord *)this;
    s32 i;
    if (record == NULL) {
        return 0;
    }
    record->magic = 0xA205B064;
    record->bank_item_count = 0;
    record->pad_24C = 0;
    for (i = 0; i < 200; i++) {
        record->bank_items[i].init();
    }
    return 1;
}

void TPlyInventory::unequip_units() {
    s32 i;
    s32 n;
    TPlyInventoryItem *e;
    n = get_item_count();
    for (i = 0; i < n; i++) {
        e = get_item(i);
        if (is_unit_item_data(&e->m_data) != 0) {
            clear_equipped_flag(e);
        }
    }
}

s32 CharacterSaveRecord::is_bank_full() {
    return (u8)(bank_item_count >= 200);
}

s32 CharacterSaveRecord::find_bank_item(saddr item) {
    BankItemRecord *entry;
    s32 i;

    entry = bank_items;
    i = 0;
    do {
        if ((entry->is_empty() == 0) && (item_identity_matches((u8 *)item, (u8 *)entry->item.data1.data_u8) != 0)) {
            return 1;
        }
        i++;
        entry++;
    } while (i < 200);
    return 0;
}

s32 CharacterSaveRecord::register_in_free_room_slot(TItemData *item) {
    BankItemRecord *entry;
    s32 i;

    i = 0;
    entry = bank_items;
    do {
        if (entry->is_empty() != 0) {
            TCheckRoomSequence::copy_item_to_bank_entry(entry, item);
            bank_item_count++;
            return 1;
        }
        i++;
        entry++;
    } while (i < 200);
    return 0;
}

s32 TAdSinglePlyChrSelectGC::is_ready() {
    if (get_game_play_mode() == 0) {
        return 1;
    }
    if (TLobby__sub_8030A770() != 0) {
        return 0;
    }
    return (u32) __cntlzw(TLobby::is_ready()) >> 5;
}

u16 TAdSinglePlyChrSelectGC::get_card_window_field(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->battle_place_counts[3];
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_window_status(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->battle_place_counts[2];
    }
    return 0U;
}
extern "C" {

u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->battle_place_counts[1];
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_state(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->battle_place_counts[0];
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_flag(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->online_battle.disconnect_count;
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_field(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->online_battle.place_counts[3];
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_status(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->online_battle.place_counts[2];
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_value(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->online_battle.place_counts[1];
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_field_21a8(int client) {
    CharacterSaveRecord *character_save_record;

    character_save_record = (CharacterSaveRecord *)get_character_save_record((u16)client);
    if (character_save_record != NULL) {
        return character_save_record->online_battle.place_counts[0];
    }
    return 0U;
}

}

s32 TPlyInventory::append_item(TItemData *item) {
    u8 n = m_num_items;

    if (n < 0x1E) {
        clear_item(n);
        memcpy(get_item_data(n), item, sizeof(TItemData));
        m_num_items += 1;
        return 1;
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC::load_player_by_slot(s32 chan) {
    s32 card_file;
    card_file = -1;
    card_load_channel = chan;
    if ((chan >= 0) && (chan <= 7)) {
        card_file = TAdPlayerLoadGC::find_card_file(chan, (const char *)&pso_guildcard_card_filename);
        if (card_file == 0) {
            TAdSinglePlyChrSelectGC::set_quest_download_server(card_load_channel);
            memcard_access_active = 1;
            card_file = TAdSinglePlyChrSelectGC::load_player_slot(card_load_channel, (const char *)&pso_guildcard_card_filename, (void *)guild_card_save_file_buffer);
        }
    }
    return card_file;
}

s32 TAdSinglePlyChrSelectGC::verify_system_file() {
    saddr buffer;
    s32 equal;
    equal = 0;
    buffer = (saddr)::operator new(0x11C);
    if (buffer == 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::find_card_file((s32)system_save_card_channel, pso_system_card_filename) == 0) {
        memcard_access_active = 1;
        TAdSinglePlyChrSelectGC::load_player_slot(system_save_card_channel, pso_system_card_filename, (void *)system_save_file_buffer);
        stop_pad_rumble();
loop_4:
        if (poll_memcard_result(system_save_card_channel) != 0) {
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
            goto loop_4;
        }
        memcard_access_active = 0;
        memcpy((void*)buffer, system_save_file_buffer + sizeof(CardSaveHeader), 0x11C);
        equal = ((TAdSinglePlyChrSelectGC *)buffer)->fields_equal(system_save_payload);
    }
    ::operator delete((void *)buffer);
    return equal;
}

s32 TAdSinglePlyChrSelectGC::load_save_from_card() {
    u8 *buf;
    s32 size;
    CharacterFile *p;
    s32 g;
    if (TAdPlayerLoadGC::find_card_file(character_save_card_slot, pso_character_card_filename.filename) == 0) {
    size = character_save_file_block_count << 13;
    buf = (u8 *)TQuestVmDownLoadServer::alloc(size);
    if (buf == NULL) {
        return 0;
    }
    memset(buf, 0, size);
    while (start_memcard_read(character_save_card_slot, pso_character_card_filename.filename, buf, character_save_file_block_count) != 0) {
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            xfree(buf);
            return 0;
        }
    }
    while (poll_memcard_result(character_save_card_slot) != 0) {
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            safe_free(buf);
            return 0;
        }
    }
    g = TAdEnterSerialAccessGC::get_serial_seed();
    chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = g;
    p = new CharacterFile;
    if (p == NULL) {
        safe_free(buf);
        return 0;
    }
    memset(p, 0, 0x1156C);
    memcpy(p, buf + 0x2048, 0x1156C);
    TAdSinglePlyChrSelectGC::decrypt_char_data(p);
    if (card_character_save_buffer->pad_11564 != p->pad_11564) {
        delete p;
        safe_free(buf);
        return 0;
    }
    delete p;
    safe_free(buf);
    return 1;
    }
    return 0;
}

CharacterFile::~CharacterFile() {}

CharacterFileSlot::~CharacterFileSlot() {}

CharacterFile::CharacterFile() {}

CharacterFileSlot::CharacterFileSlot() {}

CharacterSaveRecord::CharacterSaveRecord() {
    ((TAdSinglePlyChrSelectGC *)guild_card)->init_guild_card_tag();
}

s32 TAdSinglePlyChrSelectGC::fields_equal(void *other) {
    return (u32) __cntlzw((u32) (*(s32 *)((s8 *)other + 0x118) - *(s32 *)((s8 *)this + 0x118))) >> 5;
}

s32 TAdSinglePlyChrSelectGC::verify_card_player_data() {
    u32 *buf;
    s32 ret;
    u32 sum;
    u32 r;
    ret = 0;
    buf = (u32 *)(saddr)::operator new(0x11C);
    if (buf == NULL) {
        return -3;
    }
    if (TAdPlayerLoadGC::find_card_file(system_save_card_channel, pso_system_card_filename) == 0) {
        memcard_access_active = 1;
        TAdSinglePlyChrSelectGC::load_player_slot(system_save_card_channel, pso_system_card_filename, (void *)system_save_file_buffer);
        stop_pad_rumble();
        for (;;) {
            if (poll_memcard_result(system_save_card_channel) == 0) break;
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        memcard_access_active = 0;
        memcpy(buf, system_save_file_buffer + sizeof(CardSaveHeader), 0x11C);
        sum = *buf;
        if (((TAdSinglePlyChrSelectGC *)buf)->fields_equal(system_save_payload) == 0) {
            ret = -1;
        }
        *buf = 0;
        r = calc_crc32_bitwise((u8 *)buf, (u32)(0x11C));
        if (r != sum) {
            ret = -2;
        }
    }
    ::operator delete(buf);
    return ret;
}

s32 TAdSinglePlyChrSelectGC::poll_memcard_status() { return verify_system_file(); }


s32 TAdSinglePlyChrSelectGC::has_valid_slot() {
    CharacterFile *file = (CharacterFile *)this;
    s32 i;
    if (file != NULL) {
        for (i = 0; i < 7; i++) {
            u32 m = file->slots[i].record.magic;
            if (m != 0 && m != 0xA205B064) {
                return 1;
            }
        }
    }
    return 0;
}

void load_tables(int a0) { TAdSinglePlyChrSelectGC::selection_index = a0; memcpy((void*)selected_character_data, (void*)get_selected_character_slot(card_character_save_buffer), 0x41C); memcpy((void*)active_character_save_record, (void*)get_selected_save_record(card_character_save_buffer), 0x2370); game_state_load(); }


extern "C" {
s32 __ct__12TPlyCharDataFv(s32);
s32 __dt__12TPlyCharDataFv(s32 obj, s16 flags);
extern s32 lbl_805D55C0;
s32 fn_80203284();
s32 TAdSinglePlyChrSelectGC__sub_8028DC14();
}

void TAdSinglePlyChrSelectGC::free_char_data_slots(void *table) {
    Obj_801FCBA0 *slots = (Obj_801FCBA0 *)table;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (slots->a[i] != NULL) {
            __dt__12TPlyCharDataFv((saddr)slots->a[i], 1);
        }
        if (slots->b[i] != NULL) {
            ::operator delete(slots->b[i]);
        }
        slots->a[i] = NULL;
        slots->b[i] = NULL;
    }
}

void TAdSinglePlyChrSelectGC::alloc_char_records(void *table) {
  s32 char_data;
  s32 raw;
  s32 offset;
  u8 *entry;

  s32 i;
  i = 0;
  offset = 0;
  do
  {
    raw = (saddr)::operator new(0x41C);
    char_data = raw;
    entry += 0;
    if (char_data != 0)
    {
      char_data = __ct__12TPlyCharDataFv(raw);
    }
    entry = (u8 *)table + offset;
    *((s32 *) (((s8 *) entry) + 0)) = char_data;
    *((s32 *) (((s8 *) entry) + 0x10)) = ((saddr)new CharacterSaveRecord);
    memset(*(void **)entry, 0, 0x41C);
    memset(*(void **)(entry + 0x10), 0, 0x2370);

    i += 1;
    offset += 4;
  }
  while (i < 4);
}

void set_character_file_seed(u8 *file, s32 value) {
    *(s32 *)((s8 *)file + 0x11568) = value;
}

s32 get_character_file_seed(u8 *file) {
    return *(s32 *)((s8 *)file + 0x11568);
}

void TAdSinglePlyChrSelectGC::set_id(void* p, int v) { *(s32*)((char*)p + 0x0) = v; }


s32 TAdSinglePlyChrSelectGC::get_type(void* p) { return *(s32*)((char*)p + 0x0); }


s32 TAdSinglePlyChrSelectGC::is_entry_valid(CharacterFile *self, int i) {
    if (i >= 7) return 0;
    return self->slots[i].record.creation_seconds ? 1 : 0;
}

CharacterFileSlot *get_selected_character_slot(CharacterFile *self) {
    return &self->slots[TAdSinglePlyChrSelectGC::get_selection()];
}


CharacterSaveRecord *get_selected_save_record(CharacterFile *self) {
    return &self->slots[TAdSinglePlyChrSelectGC::get_selection()].record;
}


void TAdSinglePlyChrSelectGC::render_frame() {
    if (camera_ctrl_instance != NULL) {
        main_task.begin_frame();
        if (is_split_screen() != 0) {
            TCameraCtrl::set_mode(0);
            forward_clear_split_screen_fog();
            if (camera_ctrl_instance != NULL) {
                camera_ctrl_instance->run_task();
            }
            TCameraCtrl::set_split_viewport(1, 0);
            main_task.render();
            TCameraCtrl::set_mode(0x64);
            TCameraCtrl::set_fullscreen_viewport();
        } else {
            controller_stuff();
            main_task.run_tl_camera_tasks();
            main_task.render();
        }
        main_task.render_screen_overlay();
    }
}


s32 TAdSinglePlyChrSelectGC::forward_to_global_instance(TItemData *item) {
    if ((void *) selected_character_data != NULL) {
        ((TPlyInventory *)selected_character_data)->append_item(item);
        return 1;
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void) {
    CharacterFile *file;
    s32 cw;
    s32 ret;
    uaddr obj;
    u8 *buf;
    if (get_main_phase() == 0xE || lbl_805D55C0 == 1 || TTecCtrl::is_technique_ready() == 0) {
        return 0xFFFF0000;
    }
    stop_pad_rumble();
    ret = 0xFFFF0000;
    if (selected_character_data != NULL && active_character_save_record != NULL && card_character_save_buffer != NULL) {
        character_save_card_slot = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            TLobby::disconnect_protocol();
            return 0xFFFF0000;
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        if ((obj = TAdPlayerLoadGC::find_card_file(character_save_card_slot, (const char *)&pso_character_card_filename)) != 0) {
            TLobby::disconnect_protocol();
            return obj;
        }
        obj = character_save_file_block_count << 13;
        buf = (u8 *)TQuestVmDownLoadServer::alloc(obj);
        memset(buf, 0, obj);
        while (start_memcard_read(character_save_card_slot, pso_character_card_filename.filename, buf, character_save_file_block_count) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (buf != 0) {
                    safe_free(buf);
                }
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (buf != 0) {
                    safe_free(buf);
                }
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = TAdEnterSerialAccessGC::get_serial_seed();
        file = new CharacterFile;
        memset(file, 0, 0x1156C);
        memcpy(file, buf + 0x2048, 0x1156C);
        TAdSinglePlyChrSelectGC::decrypt_char_data(file);
        ret = TAdSinglePlyChrSelectGC::compare_save_headers(
            get_selected_save_record(file),
            (CharacterSaveRecord *)get_character_save_record(0xFFFF),
            file,
            (CharacterFile *)TAdSinglePlyChrSelectGC::get_instance());
        if (ret != 7) {
            if (buf != 0) {
                safe_free(buf);
            }
            if (file != NULL) {
                delete file;
            }
            TLobby::disconnect_protocol();
            return ret;
        }
        memcpy(get_selected_character_slot(card_character_save_buffer),
               get_selected_character_slot(file), 0x41C);
        if (buf != 0) {
            safe_free(buf);
        }
        if (file != NULL) {
            delete file;
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = poll_memcard_result(character_save_card_slot)) == 0) {
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            memcpy(get_selected_save_record(card_character_save_buffer), active_character_save_record, 0x2370);
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = TAdEnterSerialAccessGC::get_serial_seed();
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            while (start_character_file_write() != 0) {
                TAdSinglePlyChrSelectGC::run_save_load_sequence();
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    TLobby::disconnect_protocol();
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            card_load_sequence_state = 6;
            while (TAdPlayerLoadGC::get_instance() != 0) {
                TAdSinglePlyChrSelectGC::run_save_load_sequence();
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    TLobby::disconnect_protocol();
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            return 7;
        }
    }
    return ret;
}


s32 TAdSinglePlyChrSelectGC::load_character_from_card() {
    CharacterFile *file;
    s32 cw;
    s32 ret;
    uaddr obj;
    u8 *buf;
    if (get_main_phase() == 0xE || lbl_805D55C0 == 1 || TTecCtrl::is_technique_ready() != 0 ||
        fn_80203284() == 1 || TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        return 0xFFFF0000;
    }
    stop_pad_rumble();
    ret = 0xFFFF0000;
    if (selected_character_data != NULL && active_character_save_record != NULL && card_character_save_buffer != NULL) {
        character_save_card_slot = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0xFFFF0000;
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        if ((obj = TAdPlayerLoadGC::find_card_file(character_save_card_slot, (const char *)&pso_character_card_filename)) != 0) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return obj;
        }
        obj = character_save_file_block_count << 13;
        buf = (u8 *)TQuestVmDownLoadServer::alloc(obj);
        memset(buf, 0, obj);
        while (start_memcard_read(character_save_card_slot, pso_character_card_filename.filename, buf, character_save_file_block_count) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (buf != 0) {
                    safe_free(buf);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (buf != 0) {
                    safe_free(buf);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = TAdEnterSerialAccessGC::get_serial_seed();
        file = new CharacterFile;
        memset(file, 0, 0x1156C);
        memcpy(file, buf + 0x2048, 0x1156C);
        TAdSinglePlyChrSelectGC::decrypt_char_data(file);
        ret = TAdSinglePlyChrSelectGC::compare_save_headers(
            get_selected_save_record(file),
            (CharacterSaveRecord *)get_character_save_record(0xFFFF),
            file,
            (CharacterFile *)TAdSinglePlyChrSelectGC::get_instance());
        if (ret != 7) {
            if (buf != 0) {
                safe_free(buf);
            }
            if (file != NULL) {
                delete file;
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return ret;
        }
        if (active_character_save_record->save_count != get_selected_save_record(file)->save_count) {
            if (buf != 0) {
                safe_free(buf);
            }
            if (file != NULL) {
                delete file;
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 2;
        }
        if (buf != 0) {
            safe_free(buf);
        }
        if (file != NULL) {
            delete file;
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = poll_memcard_result(character_save_card_slot)) == 0) {
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            memcpy(get_selected_character_slot(card_character_save_buffer), selected_character_data, 0x41C);
            memcpy(get_selected_save_record(card_character_save_buffer), active_character_save_record, 0x2370);
            *(s32 *)((s8 *)(get_selected_character_slot(card_character_save_buffer)) + 0x36C) = 0;
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = TAdEnterSerialAccessGC::get_serial_seed();
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            ret = start_character_file_write();
            if (ret == 0) {
                card_load_sequence_state = 6;
            }
            for (;;) {
                TAdSinglePlyChrSelectGC::run_save_load_sequence();
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::run_save_load_sequence();
                if (TAdPlayerLoadGC::get_instance() == 0) {
                    break;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
        }
    }
    return ret;
}


s32 TAdSinglePlyChrSelectGC::all_players_loaded() {
    s32 i;
    u32 v;
    if (card_character_save_buffer != 0) {
        for (i = 0; i < 7; i++) {
            v = card_character_save_buffer->slots[i].record.magic;
            if (v != 0 && v + 0x5DFB0000 != 0xB064) return 0;
        }
    }
    return 1;
}


void TAdSinglePlyChrSelectGC::refresh_char_slots() {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (card_character_save_buffer->slots[i].record.magic == 0xA205B064) {
            if (card_character_save_buffer->slots[i].copied == 0) {
                init_fresh_character_slot(i);
            } else {
                ((TAdSinglePlyChrSelectGC *)&card_character_save_buffer->slots[i].record)->init_char_slot_record();
            }
        }
    }
}

void init_fresh_character_slot(s32 slot) {
    init_new_character_data(&card_character_save_buffer->slots[slot].chardata);
    ((TAdSinglePlyChrSelectGC *)&card_character_save_buffer->slots[slot].record)->init_char_slot_record();
}

s32 check_slot_a_card_save(void) {
    u64 serial_number;
    s32 i;
    if (card_character_save_buffer == 0) return 0;
    if (TAdSinglePlyChrSelectGC::init_and_register(card_character_save_buffer) == 0) return 1;
    TAdPlayerLoadGC::reset_load_state(0, &serial_number);
    for (i = 0; i < 8; i++) {
        u8 b = ((u8 *)&serial_number)[i];
        u8 a = ((u8 *)system_save_payload)[i + 0x110];
        if (a != b) return 1;
    }
    if (((TAdSinglePlyChrSelectGC *)card_character_save_buffer)->has_valid_slot() != 0) return 5;
    return 7;
}

s32 check_slot_b_card_save(void) {
    u64 serial_number;
    s32 i;
    CharacterFile *p = secondary_card_character_save_buffer;
    if (p == 0) return 0;
    if (TAdSinglePlyChrSelectGC::init_and_register(p) == 0) return 1;
    TAdPlayerLoadGC::reset_load_state(1, &serial_number);
    for (i = 0; i < 8; i++) {
        u8 b = ((u8 *)&serial_number)[i];
        u8 a = ((u8 *)secondary_card_system_save_payload)[i + 0x110];
        if (a != b) return 1;
    }
    if (((TAdSinglePlyChrSelectGC *)secondary_card_character_save_buffer)->has_valid_slot() != 0) return 5;
    return 7;
}

s32 TAdSinglePlyChrSelectGC::compare_save_headers(CharacterSaveRecord *record_a, CharacterSaveRecord *record_b, CharacterFile *file_a, CharacterFile *file_b) {
    if (record_a == NULL || record_b == NULL) return 0;
    if (record_a->save_count > record_b->save_count) return 2;
    if ((u32)record_a->creation_seconds != (u32)record_b->creation_seconds) return 4;
    if (record_a->magic != 0xA205B064 || record_b->magic != 0xA205B064) return 5;
    return file_a->pad_11564 != file_b->pad_11564 ? 6 : 7;
}

s32 TAdSinglePlyChrSelectGC::setup(int quest_download_server) { card_load_channel = quest_download_server; TAdSinglePlyChrSelectGC::set_quest_download_server((int)quest_download_server); memcard_access_active = 1; return TAdSinglePlyChrSelectGC::draw_window_bg((saddr)card_load_channel, (saddr)pso_guildcard_card_filename.filename, (saddr)guild_card_save_file_buffer, (saddr)guild_card_save_file_block_count); }


int start_system_file_write(s32 chan) {
    system_save_card_channel = chan;
    memcard_access_active = 1;
    return TAdSinglePlyChrSelectGC::draw_window_bg((s32)chan, (saddr)&pso_system_card_filename, (saddr)system_save_file_buffer, (s32)system_save_file_block_count);
}

s32 pso_system_load_gc(void) {
    s32 card_file;

    card_file = 0xFFFF0000;
    if ((system_save_payload != NULL) && (TAdPlayerLoadGC::get_instance() == 0)) {
        card_file = TAdPlayerLoadGC::find_card_file(system_save_card_channel, pso_system_card_filename);
        if (card_file == 0) {
            if (TAdSinglePlyChrSelectGC::try_confirm_selection() != 0) {
                card_file = start_system_file_write(system_save_card_channel);
                if (card_file == 0) {
                    TAdSinglePlyChrSelectGC::set_player_index(0xF);
                }
            }
        }
    }
    return card_file;
}
s32 start_character_file_write(void) {
    s32 result;
    s8 chr_select_state;
    chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
    result = -1;
    character_save_card_slot = (s32) chr_select_state;
    if (chr_select_state < 2) {
        TAdSinglePlyChrSelectGC::set_quest_download_server((int)((int) ((s32) chr_select_state)));
        memcard_access_active = 1;
        result = ((s32)TAdSinglePlyChrSelectGC::draw_window_bg((s32)character_save_card_slot, (s32)((saddr)pso_character_card_filename.filename), (saddr)character_save_file_buffer, (s32)character_save_file_block_count));
    }
    return result;
}
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void) {
    s32 result;
    s8 chr_select_state;
    chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
    result = -1;
    character_save_card_slot = (s32) chr_select_state;
    if (chr_select_state < 2) {
        TAdSinglePlyChrSelectGC::set_quest_download_server((int) ((s32) chr_select_state));
        memcard_access_active = 1;
        result = ((s32)TAdSinglePlyChrSelectGC::draw_window_bg((s32)character_save_card_slot, (s32)((saddr)pso_character_card_filename.filename), (saddr)character_save_file_buffer, (s32)character_save_file_block_count));
    }
    card_load_sequence_state = 0x13;
    return result;
}


struct Slot_801FDEE4 {
    u8 pad0[4];
    u8 chr[0x370 - 4];
    s32 f370;
    u8 pad374[0x668 - 0x374];
    s32 f668;
    s32 f66C;
    BankItemRecord items[200];
    u8 pad1930[0x2790 - 0x1930];
    s32 f2790;
    s32 f2794;
};

struct E_801FDDAC { u8 pad[0x424]; u32 f424; u8 pad2[0x2790 - 0x428]; s32 f2790; s32 f2794; };

struct E_801FDE14 { u8 pad[0x424]; u32 f424; u8 pad2[0x2794 - 0x428]; u32 f2794; };

struct DateStamp_801FDEE4 { u8 pad[0xC]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct B1C_801FE010 { u32 w[7]; };

struct B10_801FE010 { u32 w[4]; };

struct B200_801FE010 { u32 w[0x80]; };

struct B90_801FE010 { u32 w[0x24]; };

struct B420_801FE010 { u32 w[0x108]; };

struct I54_801FE010 { u8 b[0x54]; };

struct BAC_801FE010 { u32 w[0x2B]; };

struct B100_801FE010 { u32 w[0x40]; };

struct B28_801FE010 { u32 w[0xA]; };

struct B40_801FE010 { u32 w[0x10]; };

struct S_801FE010 {
    u32 a0, a4, a8, aC, a10, a14;
    B1C_801FE010 b18;
    B10_801FE010 b34;
    B200_801FE010 b44;
    u32 c244, c248, c24C;
    BankItemRecord items[200];
    B90_801FE010 d1510;
    B420_801FE010 d15A0;
    I54_801FE010 slots[20];
    BAC_801FE010 e2050;
    BAC_801FE010 e20FC;
    B1C_801FE010 e21A8;
    B100_801FE010 e21C4;
    B28_801FE010 e22C4;
    B28_801FE010 e22EC;
    B40_801FE010 e2314;
    B1C_801FE010 e2354;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct S_801FE010;
struct B8_801FDFB8 { u32 w[2]; };

struct P_801FDFB8 { TPlyCharData char_data; u8 a[0x278C - 0x41C]; B8_801FDFB8 f278C; s32 f2794; };

extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_801FE380(CharacterFile *src_file, s32 src_slot, CharacterFile *dst_file, s32 dst_slot);
saddr TAdSinglePlyChrSelectGC__sub_80076D9C(saddr arg0, saddr arg1);
S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *dest, S_801FE010 *source);

}

void TAdSinglePlyChrSelectGC::open_confirm_window() { memcard_access_active = 1; TAdSinglePlyChrSelectGC::draw_window_bg((saddr)1, (saddr)pso_character_card_filename.filename, (saddr)character_save_file_buffer, (saddr)character_save_file_block_count); card_load_sequence_state = 18; }


s32 TAdSinglePlyChrSelectGC::load_pso_system(int chan) {
    s32 r = -1;
    system_save_card_channel = chan;
    if (chan >= 0 && chan <= 7) {
        r = TAdPlayerLoadGC::find_card_file(chan, (const char *)&pso_system_card_filename);
        if (r == 0) {
            memcard_access_active = 1;
            r = ((s32)TAdSinglePlyChrSelectGC::load_player_slot(system_save_card_channel, (const char *)&pso_system_card_filename, (void *)(*(saddr *)&system_save_file_buffer)));
        }
    }
    return r;
}


s32 TAdSinglePlyChrSelectGC::load_pso_system_slot() {
    s32 r = TAdPlayerLoadGC::find_card_file(1, pso_system_card_filename);
    if (r == 0) {
        memcard_access_active = 1;
        r = TAdSinglePlyChrSelectGC::load_player_slot(1, pso_system_card_filename, (void *)system_save_file_buffer);
    }
    return r;
}


s32 TAdSinglePlyChrSelectGC__sub_801FDC14(s32) {
    s32 r = TAdPlayerLoadGC::find_card_file(1, pso_character_card_filename.filename);
    if (r == 0) {
        memcard_access_active = 1;
        r = TAdSinglePlyChrSelectGC::load_player_slot(1, pso_character_card_filename.filename, (void *)character_save_file_buffer);
    }
    return r;
}

s32 TAdSinglePlyChrSelectGC::swap_characters(s32 src_slot, s32 i) {
    s32 result;
    if ((src_slot >= 7) || (i >= 7)) {
        return 0;
    }
    if (card_character_save_buffer == NULL) {
        goto return_zero;
    }
    if (secondary_card_character_save_buffer == NULL) {
        goto return_zero;
    }
    if (TAdSinglePlyChrSelectGC::check_page_cross(secondary_card_character_save_buffer, src_slot, card_character_save_buffer, i) == 0) {
        goto return_zero;
    }
    TAdSinglePlyChrSelectGC::increment_counters();
    TAdSinglePlyChrSelectGC__sub_801FE380(secondary_card_character_save_buffer, src_slot, card_character_save_buffer, i);
    return 1;
return_zero:
    return 0;
}


s32 TAdSinglePlyChrSelectGC::try_move_char(int src_slot, int dst_slot) {
    if ((src_slot >= 7) || (dst_slot >= 7)) {
        return 0;
    }
    if (dst_slot > 3) {
        return 0;
    }
    if (src_slot <= 3) {
        return 0;
    }
    if ((card_character_save_buffer != 0U) && (secondary_card_character_save_buffer != 0U) && (TAdSinglePlyChrSelectGC::check_page_cross(card_character_save_buffer, src_slot, secondary_card_character_save_buffer, dst_slot) != 0)) {
        TAdSinglePlyChrSelectGC::increment_counters();
        TAdSinglePlyChrSelectGC::copy_character_to_slot(card_character_save_buffer, src_slot, secondary_card_character_save_buffer, dst_slot);
        return 1;
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC::check_slot_swap_allowed(void *src_file, int src_slot, void *dst_file, int dst_slot) {
    E_801FDDAC *src = (E_801FDDAC *)src_file;
    E_801FDDAC *dst = (E_801FDDAC *)dst_file;
    E_801FDDAC *e;
    if (src_slot < 4) {
        return 0;
    }
    if (src[src_slot].f424 != 0U) {
        return 0;
    }
    if (dst_slot >= 4) {
        return 0;
    }
    e = &dst[dst_slot];
    if (e->f424 == 0U) {
        return 0;
    }
    return (u32)__cntlzw(e->f2790) >> 5;
}

s32 TAdSinglePlyChrSelectGC::is_same_slot_entry(void *src_file, int src_slot, void *dst_file, int dst_slot) {
    E_801FDE14 *src = (E_801FDE14 *)src_file;
    E_801FDE14 *dst = (E_801FDE14 *)dst_file;
    E_801FDE14 *b;
    E_801FDE14 *a;
    u32 vb;
    u32 va;
    u32 kb;
    if (dst_slot <= 3) {
        return 0;
    }
    b = &dst[dst_slot];
    vb = b->f424;
    if (vb == 0) {
        return 0;
    }
    kb = b->f2794;
    if (src_slot > 3) {
        return 0;
    }
    a = &src[src_slot];
    va = a->f424;
    if (va == 0) {
        return 0;
    }
    if (a->f2794 != kb) {
        return 0;
    }
    return (u32)__cntlzw(vb - va) >> 5;
}


s32 TAdSinglePlyChrSelectGC::check_page_cross(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot) {
    if ((src_slot >= 4) && (dst_slot <= 3)) {
        return TAdSinglePlyChrSelectGC::check_slot_swap_allowed(src_file, src_slot, dst_file, dst_slot);
    }
    if ((src_slot <= 3) && (dst_slot >= 4)) {
        return TAdSinglePlyChrSelectGC::is_same_slot_entry(src_file, src_slot, dst_file, dst_slot);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::copy_character_to_slot(CharacterFile *src_file, int src_slot, CharacterFile *dst_file, int dst_slot) {
    s32 secs;
    DateStamp_801FDEE4 ds;
    Slot_801FDEE4 *src = (Slot_801FDEE4 *)src_file;
    Slot_801FDEE4 *dst = (Slot_801FDEE4 *)dst_file;
    void *chr;
    s32 i;
    s32 j;
    getDateStamp((DateStamp *)&ds);
    DateToSeconds((DateStamp *)&ds, (int *)&secs);
    dst[dst_slot].f2794 = secs;
    chr = dst[dst_slot].chr;
    TAdSinglePlyChrSelectGC::copy_char_slot_data(src[src_slot].chr, chr);
    for (i = 0; i < 30; i++) {
        ((TAdSinglePlyChrSelectGC *)((TPlyInventory *)chr)->get_item(i))->clear_inventory_slot();
    }
    dst[dst_slot].f370 = 0;
    dst[dst_slot].f668 = 0;
    dst[dst_slot].f66C = 0;
    for (j = 0; j < 200; j++) {
        dst[dst_slot].items[j].init();
    }
    dst[dst_slot].f2790 = 1;
    return 1;
}

#define dst ((P_801FDFB8 *)a0)
#define src ((P_801FDFB8 *)a1)
void *TAdSinglePlyChrSelectGC::copy_char_slot_data(void *a0, void *a1) {
    TProtocol::copy_player_data(&dst->char_data, &src->char_data);
    assign_char_data__23TAdSinglePlyChrSelectGCFPvPv((S_801FE010 *)dst->a, (S_801FE010 *)src->a);
    dst->f278C = src->f278C;
    dst->f2794 = src->f2794;
    return a0;
}
#undef dst
#undef src


S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *dest, S_801FE010 *source) {
    BankItemRecord *p;
    BankItemRecord *q;
    I54_801FE010 *s;
    I54_801FE010 *t;
    dest->a0 = source->a0;
    dest->a4 = source->a4;
    dest->a8 = source->a8;
    dest->aC = source->aC;
    dest->a10 = source->a10;
    dest->a14 = source->a14;
    dest->b18 = source->b18;
    dest->b34 = source->b34;
    dest->b44 = source->b44;
    dest->c244 = source->c244;
    dest->c248 = source->c248;
    dest->c24C = source->c24C;
    p = dest->items;
    q = source->items;
    do {
        *p = *q;
        p++;
        q++;
    } while (p < dest->items + 200);
    dest->d1510 = source->d1510;
    dest->d15A0 = source->d15A0;
    s = dest->slots;
    t = source->slots;
    do {
        TAdSinglePlyChrSelectGC__sub_80076D9C((saddr)s, (saddr)t);
        s++;
        t++;
    } while (s < dest->slots + 20);
    dest->e2050 = source->e2050;
    dest->e20FC = source->e20FC;
    dest->e21A8 = source->e21A8;
    dest->e21C4 = source->e21C4;
    dest->e22C4 = source->e22C4;
    dest->e22EC = source->e22EC;
    dest->e2314 = source->e2314;
    dest->e2354 = source->e2354;
    return dest;
}

void TAdSinglePlyChrSelectGC::clear_entry(int i) {
    if (card_character_save_buffer == NULL) return;
    if (i >= 4) return;
    card_character_save_buffer->slots[i].copied = 0;
    card_character_save_buffer->slots[i].copy_time = 0;
}


void TAdSinglePlyChrSelectGC::clear_slot_entry(int i) {
    if (secondary_card_character_save_buffer == NULL) return;
    if (i >= 4) return;
    secondary_card_character_save_buffer->slots[i].copied = 0;
    secondary_card_character_save_buffer->slots[i].copy_time = 0;
}


void TAdSinglePlyChrSelectGC::clear_slot_body(int i) {
    if (card_character_save_buffer == NULL) return;
    if (i < 4) return;
    memset(&card_character_save_buffer->slots[i], 0, 0x2798);
}


s32 TAdSinglePlyChrSelectGC__sub_801FE380(CharacterFile *src_file, s32 src_slot, CharacterFile *dst_file, s32 dst_slot) {
    dst_file->slots[dst_slot].copied = 0;
    dst_file->slots[dst_slot].copy_time = 0;
    TAdSinglePlyChrSelectGC::copy_char_slot_data(&src_file->slots[src_slot], &dst_file->slots[dst_slot]);
    TAdSinglePlyChrSelectGC::clear_slot_body(dst_slot);
    return 1;
}

s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i) {
    u8 *slot;
    if (i >= 7U) {
        return NULL;
    }
    if (TAdSinglePlyChrSelectGC::is_entry_valid(secondary_card_character_save_buffer, i) == 0) {
        return NULL;
    }
    slot = (u8 *)((*(saddr *)&secondary_card_character_save_buffer) + (i * 0x2798));
    lbl_805137C8[0] = (saddr)(slot + 0x374);
    lbl_805137C8[1] = (s32) *(s32 *)((s8 *)slot + 0x368);
    lbl_805137C8[2] = (s32) *(s32 *)((s8 *)slot + 0x2790);
    lbl_805137C8[3] = (s32) *(s32 *)((s8 *)slot + 0x42C);
    return lbl_805137C8;
}


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


TPlyCharData *TAdSinglePlyChrSelectGC::get_entry(int i) {
    if (TAdSinglePlyChrSelectGC::is_entry_valid(secondary_card_character_save_buffer, i) != 0) {
        return &secondary_card_character_save_buffer->slots[i].chardata;
    }
    return 0;
}


s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 i) {
    u8 *slot;
    if (i >= 7U) {
        return NULL;
    }
    if (TAdSinglePlyChrSelectGC::is_entry_valid(card_character_save_buffer, (s32)i) == 0) {
        return NULL;
    }
    slot = (u8 *)((*(saddr *)&card_character_save_buffer) + (i * 0x2798));
    lbl_805137C8[0] = (saddr)(slot + 0x374);
    lbl_805137C8[1] = (s32) *(s32 *)((s8 *)slot + 0x368);
    lbl_805137C8[2] = (s32) *(s32 *)((s8 *)slot + 0x2790);
    return lbl_805137C8;
}

void TAdSinglePlyChrSelectGC::copy_chr_slots_from_request() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (chr_select_request_buffer.card_slots[i] < 7 && chr_select_request_buffer.card_slots[i] >= 0) {
            memcpy(&card_character_save_buffer->slots[chr_select_request_buffer.card_slots[i]].chardata, (void *)chr_select_buffer_ptr_table[chr_select_request_buffer.player_ids[i]], 0x41C);
            memcpy(&card_character_save_buffer->slots[chr_select_request_buffer.card_slots[i]].record, (void *)chr_select_buffer_ptr_table[chr_select_request_buffer.player_ids[i] + 4], 0x2370);
        }
    }
}


void copy_selected_characters(const CharacterSelectionRequest *request) {
    s32 i;
    if (request->count <= 4) {
        copy_character_selection_request(&chr_select_request_buffer, request);
        for (i = 0; i < 4; i++) {
            memset((void *)chr_select_buffer_ptr_table[i], 0, 0x41C);
            memset((void *)chr_select_buffer_ptr_table[i + 4], 0, 0x2370);
        }
        for (i = 0; i < 4; i++) {
            if (request->card_slots[i] < 7 && request->player_ids[i] != -1) {
                memcpy((void *)chr_select_buffer_ptr_table[request->player_ids[i]], &card_character_save_buffer->slots[request->card_slots[i]].chardata, 0x41C);
                memcpy((void *)chr_select_buffer_ptr_table[request->player_ids[i] + 4], &card_character_save_buffer->slots[request->card_slots[i]].record, 0x2370);
            }
        }
    }
}

void copy_character_selection_request(CharacterSelectionRequest *destination, const CharacterSelectionRequest *source) {
    *destination = *source;
}


s32 TAdSinglePlyChrSelectGC::load_chr_select_slot() {
    s32 card_file;
    s8 chr_select_state;
    chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
    card_file = -1;
    character_save_card_slot = (s32) chr_select_state;
    if ((chr_select_state >= 0) && (chr_select_state <= 7)) {
        card_file = TAdPlayerLoadGC::find_card_file((s32) chr_select_state, pso_character_card_filename.filename);
        if (card_file == 0) {
            TAdSinglePlyChrSelectGC::set_quest_download_server(character_save_card_slot);
            memcard_access_active = 1;
            card_file = TAdSinglePlyChrSelectGC::load_player_slot(character_save_card_slot, pso_character_card_filename.filename, (void *)character_save_file_buffer);
        }
    }
    return card_file;
}

int get_split_screen_character_save_record(int a0) {  return chr_select_buffer_ptr_table[a0 + 4]; }

TPlyCharData *TAdSinglePlyChrSelectGC::get_char_table_entry(int index) {  return (TPlyCharData *)chr_select_buffer_ptr_table[index]; }


s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i) {
    if (i >= 7U) {
        return 0;
    }
    if ((secondary_card_character_save_buffer != NULL) && (TAdSinglePlyChrSelectGC::is_entry_valid(secondary_card_character_save_buffer, (s32) i) != 0)) {
        return 1;
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC::is_slot_active(unsigned int slot) {
    u32 i = slot;
    CharacterFile *result;
    if (i >= 7U) {
        return 0;
    }
    result = card_character_save_buffer;
    if ((result != 0U) && (TAdSinglePlyChrSelectGC::is_entry_valid(result, i) != 0)) {
        return 1;
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC::load_player_data() {
    s32 card_file;

    card_file = 0xFFFF0000;
    if ((guild_card_save_payload != NULL) && (TAdPlayerLoadGC::get_instance() == 0) && (TAdPlayerLoadGC::probe_and_check_card(card_load_channel) != 0)) {
        card_file = TAdPlayerLoadGC::find_card_file(card_load_channel, pso_guildcard_card_filename.filename);
        if ((card_file == 0) && (TAdSinglePlyChrSelectGC::check_ready() != 0)) {
            card_file = TAdSinglePlyChrSelectGC::setup(card_load_channel);
            if (card_file == 0) {
                TAdSinglePlyChrSelectGC::set_player_index(0xC);
            }
        }
    }
    return card_file;
}

s32 load_guild_card_save(void) {
    s32 card_file;
    s32 result;
    s8 chr_select_state;

    TAdSinglePlyChrSelectGC::set_save_slot(0);
    card_file = 0xFFFF0000;
    if ((guild_card_save_payload != NULL) && (TAdPlayerLoadGC::get_instance() == 0)) {
        chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
        card_load_channel = chr_select_state;
        card_file = poll_memcard_result(card_load_channel);
        if (card_file == 0) {
            card_file = TAdPlayerLoadGC::find_card_file(card_load_channel, pso_guildcard_card_filename.filename);
            if (card_file == 0) {
                result = TAdSinglePlyChrSelectGC::load_player_by_slot(card_load_channel);
                if (result == 0) {
                    card_load_sequence_state = 0xD;
                }
                return result;
            }
        }
    }
    return card_file;
}


s32 load_system_file(s32 mode) {
    s32 card_file;
    s32 result;
    s32 chr_select_state;

    card_file = 0xFFFF0000;
    if ((system_save_payload != NULL) && (TAdPlayerLoadGC::get_instance() == 0)) {
        chr_select_state = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
        system_save_card_channel = chr_select_state;
        card_file = poll_memcard_result(chr_select_state);
        if (card_file == 0) {
            card_file = TAdPlayerLoadGC::find_card_file(system_save_card_channel, pso_system_card_filename);
            if (card_file == 0) {
                result = TAdSinglePlyChrSelectGC::load_pso_system(system_save_card_channel);
                if (result == 0) {
                    if (mode != 0) {
                        card_load_sequence_state = 0x11;
                    } else {
                        card_load_sequence_state = 0x10;
                    }
                }
                return result;
            }
        }
    }
    result = card_file;
    return result;
}


s32 load_pso_system(void) {
    s32 card_file;
    s32 result;

    card_file = 0xFFFF0000;
    if ((secondary_card_system_save_payload != NULL) && (TAdPlayerLoadGC::get_instance() == 0)) {
        card_file = poll_memcard_result(1);
        if (card_file == 0) {
            card_file = TAdPlayerLoadGC::find_card_file(1, pso_system_card_filename);
            if (card_file == 0) {
                result = TAdSinglePlyChrSelectGC::load_pso_system_slot();
                if (result == 0) {
                    card_load_sequence_state = 0x16;
                }
                return result;
            }
        }
    }
    result = card_file;
    return result;
}


s32 TAdSinglePlyChrSelectGC::check_ready() {
    s32 result;

    stop_pad_rumble();
    result = 0;
    if ((guild_card_save_payload != NULL) && (guild_card_save_file_buffer != NULL)) {
        TAdSinglePlyChrSelectGC__sub_801FFF14();
        result = 1;
    }
    return result;
}


s32 TAdSinglePlyChrSelectGC::try_confirm_selection() {
    s32 result;

    stop_pad_rumble();
    result = 0;
    if ((system_save_payload != NULL) && (system_save_file_buffer != NULL)) {
        TAdSinglePlyChrSelectGC::create_instance();
        result = 1;
    }
    return result;
}

s32 TAdSinglePlyChrSelectGC::check_system_load_result() {
    s32 r = ::load_pso_system();
    card_load_followup_pending = 0;
    if (r == 0) card_load_followup_pending = 1;
    return r;
}

s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void) {
    s32 result;
    result = 0xFFFF0000;
    if ((secondary_card_character_save_buffer != NULL) && (TAdPlayerLoadGC::get_instance() == 0x16)) {
        result = poll_memcard_result(1);
        if (result == 0) {
            result = TAdSinglePlyChrSelectGC__sub_801FDC14(1);
            if (result == 0) {
                card_load_sequence_state = 0x14;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return result;
}


extern "C" {
saddr get_localized_text_entry(s32, s32);
s8 poll_reset_request__Fv(void);
void TLobby__sub_80269C90(void);
void TLobby__sub_80269CA4(s32);


}

s32 TAdSinglePlyChrSelectGC::load_selected_char() {
    s32 result;

    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    result = 0xFFFF0000;
    if ((selected_character_data != NULL) && (active_character_save_record != NULL) && (card_character_save_buffer != 0) && (TAdPlayerLoadGC::get_instance() == 0x10) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        result = poll_memcard_result(character_save_card_slot);
        if (result == 0) {
            result = TAdSinglePlyChrSelectGC::load_chr_select_slot();
            if (result == 0) {
                card_load_sequence_state = 8;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return result;
}


s32 TAdSinglePlyChrSelectGC::load_selected_character() {
    s32 result;

    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    result = 0xFFFF0000;
    if ((selected_character_data != NULL) && (active_character_save_record != NULL) && (card_character_save_buffer != 0) && (TAdPlayerLoadGC::get_instance() == 0) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        result = poll_memcard_result(character_save_card_slot);
        if (result == 0) {
            result = TAdSinglePlyChrSelectGC::load_chr_select_slot();
            if (result == 0) {
                card_load_sequence_state = 8;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return result;
}


s32 TAdSinglePlyChrSelectGC::start_load() {
    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    if ((selected_character_data != NULL) && (active_character_save_record != NULL) && (card_character_save_buffer != 0) && (TAdPlayerLoadGC::get_instance() == 0) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        TAdSinglePlyChrSelectGC::clear_load_buffers();
        init_buffer();
        TAdSinglePlyChrSelectGC::prepare_save_data();
        start_character_file_write();
        card_load_sequence_state = 6;
        return 7;
    }
    return 0xFFFF0000;
}

s32 TAdSinglePlyChrSelectGC::save_character_to_card() {
    TCheckMemoryCard *check;
    TWindowMessage *w;
    s32 result;
    s32 v;
    check = TCheckMemoryCard::create((TObject *)tl_01, NULL, 1);
    if (check == NULL) {
        return 0;
    }
    if (check != NULL) {
        check->select_main_window_controller();
        while (1) {
            begin_gx_frame();
            check->run_task();
            if (check->is_card_ready() != 0) {
                break;
            }
            controller_stuff();
            TLobby::wait_ready_loop();
            TAdSinglePlyChrSelectGC::render_frame();
            if (poll_reset_request__Fv() != 0 || test_pressed_buttons_packed(&controller_input_state.controllers[0], 8) != 0) {
                if (check != NULL) {
            delete check;
        }
                return 0;
            }
            render_tick();
        }
        if (check != NULL) {
            delete check;
        }
    }
    // Message text origin and width inside the save message window; the original computes them and never
    // reads them.
    static NJS_POINT2 message_text_pos = {
        20.0f + chr_select_save_message_window_pos.x,
        10.0f + (chr_select_save_message_window_pos.y + chr_select_save_message_window_size.y)
    };
    static f32 message_text_width = chr_select_save_message_window_size.x - 40.0f;
    if (TAdSinglePlyChrSelectGC::load_save_from_card() == 0) {
        w = TWindowMessage::create(&chr_select_save_message_window_pos, &chr_select_save_message_window_size.x, 1, 4);
        if (w != NULL) {
            w->append_line(get_localized_text_entry(0x20, 4), 3);
            w->reparent_to_main_ctrl();
        }
        w->complete_reveal();
        while (1) {
            begin_gx_frame();
            controller_stuff();
            TLobby::wait_ready_loop();
            TAdSinglePlyChrSelectGC::render_frame();
            if (poll_reset_request__Fv() != 0) {
                break;
            }
            render_tick();
        }
        if (w != NULL) {
            delete w;
        }
        return 0;
    }
    TAdSinglePlyChrSelectGC::increment_counter();
    v = TAdEnterSerialAccessGC::get_serial_seed();
    chr_select_serial_seeds[1] = v;
    chr_select_serial_seeds[0] = v;
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
    start_character_file_write();
    card_load_sequence_state = 6;
    while (1) {
        begin_gx_frame();
        controller_stuff();
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
        TAdSinglePlyChrSelectGC::render_frame();
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            result = 0;
            break;
        }
        if (TAdPlayerLoadGC::get_instance() == 0) {
            result = 1;
            if (TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF81 || TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF83) {
                result = 0;
            }
            break;
        }
        render_tick();
    }
    TLobby__sub_80269CA4(0x23);
    w = TWindowMessage::create(&chr_select_save_message_window_pos, &chr_select_save_message_window_size.x, 1, 4);
    TLobby__sub_80269C90();
    if (w != NULL) {
        if (TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF81 || TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF83) {
            w->append_line(get_localized_text_entry(0x1C, 1), 3);
        } else {
            w->append_line(get_localized_text_entry(0x20, 5), 3);
        }
        w->reparent_to_main_ctrl();
    }
    w->complete_reveal();
    if (result == 0) {
        while (1) {
            begin_gx_frame();
            controller_stuff();
            TLobby::wait_ready_loop();
            TAdSinglePlyChrSelectGC::render_frame();
            if (poll_reset_request__Fv() != 0 || test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x60E) != 0) {
                break;
            }
            render_tick();
        }
    }
    if (w != NULL) {
            delete w;
        }
    return result;
}


s32 TAdSinglePlyChrSelectGC::encrypt_save_and_write() {
    s32 seed;
    seed = TAdEnterSerialAccessGC::get_serial_seed();
    chr_select_serial_seeds[1] = seed;
    chr_select_serial_seeds[0] = seed;
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
    if (((s32)start_character_file_write()) != 0) {
        return 0;
    }
    card_load_sequence_state = 6;
    return 1;
}


void TAdSinglePlyChrSelectGC::increment_counter() {
    CharacterFile *instance;

    instance = (CharacterFile *)TAdSinglePlyChrSelectGC::get_instance();
    if (instance != NULL) {
        instance->pad_11564++;
    }
}


void TAdSinglePlyChrSelectGC::increment_counters() {
    if ((void *) card_character_save_buffer != NULL) {
        card_character_save_buffer->pad_11564++;
    }
    if ((void *) secondary_card_character_save_buffer != NULL) {
        secondary_card_character_save_buffer->pad_11564++;
    }
}

s32 TAdSinglePlyChrSelectGC::load_system_file_flag() {
    s32 r = ::load_system_file(0);
    card_load_followup_pending = 0;
    if (r == 0) card_load_followup_pending = 1;
    return r;
}
s32 TAdSinglePlyChrSelectGC::load_system_file_blocking() {
    s32 r = ::load_system_file(1);
    card_load_followup_pending = 0;
    if (r == 0) {
        card_load_followup_pending = 1;
    } else {
        return 0;
    }
    for (;;) {
        if (TAdPlayerLoadGC::get_instance() == 0) break;
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
    }
    card_load_followup_pending = 0;
    return TAdSinglePlyChrSelectGC::verify_save_checksum(1) == 0;
}
s32 TAdSinglePlyChrSelectGC::load_character_and_wait() {
    s32 r = TAdSinglePlyChrSelectGC::load_selected_character();
    card_load_followup_pending = 0;
    if (r == 0) {
        card_load_followup_pending = 1;
    } else {
        return 0;
    }
    for (;;) {
        if (TAdPlayerLoadGC::get_instance() == 0) break;
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
    }
    card_load_followup_pending = 0;
    return TAdSinglePlyChrSelectGC::apply_loaded_character(1) == 0;
}
s32 TAdSinglePlyChrSelectGC::load_player_and_wait() {
    s32 r = load_guild_card_save();
    card_load_followup_pending = 0;
    if (r == 0) {
        card_load_followup_pending = 1;
    } else {
        return 0;
    }
    for (;;) {
        if (TAdPlayerLoadGC::get_instance() == 0) break;
        TAdSinglePlyChrSelectGC::run_save_load_sequence();
    }
    card_load_followup_pending = 0;
    return load_and_verify_data(1) == 0;
}


struct ByteBlock_FC0 { u8 bytes[0xfc0]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off

struct ByteBlock_C0
{
  u8 bytes[0xc0];
};

extern "C" {
s32 __as__13GuildCardSlotFRC13GuildCardSlot(saddr arg0, u8 *arg1);
}


s32 TAdSinglePlyChrSelectGC::init(void) {
    stop_pad_rumble();
    if ((selected_character_data != NULL) && (active_character_save_record != NULL) && (card_character_save_buffer != 0)) {
        if ((get_player_by_client_id(local_client_id) != NULL) && (TTecCtrl::is_technique_ready() == 0) && (fn_80203284() != 1)) {
            TObjPlayer::init_battle_selection();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
        }
        TAdSinglePlyChrSelectGC::clear_flags(3);
        TAdSinglePlyChrSelectGC::update_play_time();
        copy_card_window_data();
        TAdSinglePlyChrSelectGC::prepare_save_data();
    }
    return 0xFFFF0000;
}


s32 TAdSinglePlyChrSelectGC::setup_player_battle_ctrls(void) {
  TPlyCharData *char_data;
  u32 i;
  CharacterSaveRecord *character_save_record;
  stop_pad_rumble();
  get_character_select_request_buffer();
  i = 0;
  do
  {
    if (((get_player_by_client_id((s32)((int) i)) != NULL) && (((volatile long)TTecCtrl::is_technique_ready()) == 0)) && (TLobby__sub_8030A770() == 0))
    {
      char_data = TAdSinglePlyChrSelectGC::get_char_index(i);
      if (char_data != NULL)
      {
        char_data->capture_client_player((u16) i);
      }
      character_save_record = (CharacterSaveRecord *) get_character_save_record(i);
      if (character_save_record != 0)
      {
        TAdSinglePlyChrSelectGC::update_elapsed_time(character_save_record);
      }
    }
    TAdSinglePlyChrSelectGC::clear_flags(3);
    i += 1;
  }
  while (((s32) i) < 4);
  return 0xFFFF0000;
}

void TAdSinglePlyChrSelectGC::clear_load_buffers(void) {
    if (card_character_save_buffer != 0) {
        memset(card_character_save_buffer, 0, 0x1156C);
        memset(selected_character_data, 0, 0x41C);
        memset(active_character_save_record, 0, 0x2370);
    }
}

s32 TAdSinglePlyChrSelectGC::load_character_from_card(int card_file) {
    CharacterFile *file;
    s32 ret;
    u8 *buf;
    s32 t;
    s32 i;
    saddr p;
    u32 size;
    if (get_main_phase() == 0xE || (get_current_floor_area() == AREA_LOBBY && card_file != 1) ||
        lbl_805D55C0 == 1 || TTecCtrl::is_technique_ready() != 0 || fn_80203284() == 1) {
        return 0xFFFF0000;
    }
    stop_pad_rumble();
    ret = 0xFFFF0000;
    if (selected_character_data != 0 && active_character_save_record != NULL && card_character_save_buffer != 0) {
        character_save_card_slot = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0xFFFF0000;
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        if (card_file != 1) {
            card_file = TAdPlayerLoadGC::find_card_file(character_save_card_slot, pso_character_card_filename.filename);
            if (card_file != 0) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return card_file;
            }
            size = character_save_file_block_count << 13;
            buf = (u8 *)TQuestVmDownLoadServer::alloc(size);
            memset(buf, 0, size);
            while (start_memcard_read(character_save_card_slot, pso_character_card_filename.filename, buf, character_save_file_block_count) != 0) {
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    if (buf != 0) {
                        safe_free(buf);
                    }
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            while (poll_memcard_result(character_save_card_slot) != 0) {
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    if (buf != 0) {
                        safe_free(buf);
                    }
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            t = TAdEnterSerialAccessGC::get_serial_seed();
            chr_select_serial_seeds[1] = t;
            chr_select_serial_seeds[0] = t;
            file = new CharacterFile;
            memset(file, 0, 0x1156C);
            memcpy(file, buf + 0x2048, 0x1156C);
            TAdSinglePlyChrSelectGC::decrypt_char_data(file);
            ret = TAdSinglePlyChrSelectGC::compare_save_headers(get_selected_save_record(file), (CharacterSaveRecord *)get_character_save_record(0xFFFF), file, (CharacterFile *)TAdSinglePlyChrSelectGC::get_instance());
            if (ret != 7) {
                if (buf != 0) {
                    safe_free(buf);
                }
                if (file != NULL) {
                    delete file;
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return ret;
            }
            if (active_character_save_record->save_count != get_selected_save_record(file)->save_count) {
                if (buf != 0) {
                    safe_free(buf);
                }
                if (file != NULL) {
                    delete file;
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 2;
            }
            if (buf != 0) {
                safe_free(buf);
            }
            if (file != NULL) {
                delete file;
            }
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = poll_memcard_result(character_save_card_slot)) == 0) {
            TObjPlayer::sync_char_select_state();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::increment_counter();
            switch (get_main_phase()) {
            case 0xF:
                TAdSinglePlyChrSelectGC::set_global_flags(1);
                memcpy(get_selected_character_slot(card_character_save_buffer), selected_character_data, 0x41C);
                memcpy(get_selected_save_record(card_character_save_buffer), active_character_save_record, 0x2370);
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
                    p = reinterpret_cast<saddr>(reinterpret_cast<TPlyCharData *>(get_selected_character_slot(card_character_save_buffer))->m_inventory.get_items());
                    for (i = 0; i < 30; i++) {
                        ((TAdSinglePlyChrSelectGC *)p)->clear_inventory_slot();
                        p += 0x1C;
                    }
                    *(u8 *)get_selected_character_slot(card_character_save_buffer) = 0;
                    memset(get_selected_save_record(card_character_save_buffer)->bank_items, 0, 0x12C0);
                    get_selected_save_record(card_character_save_buffer)->bank_item_count = 0;
                    get_selected_save_record(card_character_save_buffer)->pad_24C = 0;
                }
                *(s32 *)((u8 *)get_selected_character_slot(card_character_save_buffer) + 0x36C) = 0;
                break;
            default:
                copy_card_window_data();
                memcpy(get_selected_character_slot(card_character_save_buffer), selected_character_data, 0x41C);
                memcpy(get_selected_save_record(card_character_save_buffer), active_character_save_record, 0x2370);
                break;
            }
            t = TAdEnterSerialAccessGC::get_serial_seed();
            chr_select_serial_seeds[1] = t;
            chr_select_serial_seeds[0] = t;
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            while (start_character_file_write() != 0) {
                TAdSinglePlyChrSelectGC::run_save_load_sequence();
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            card_load_sequence_state = 6;
            while (TAdPlayerLoadGC::get_instance() != 0) {
                TAdSinglePlyChrSelectGC::run_save_load_sequence();
                if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            if (TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF81 || TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF83) {
                ret = 1;
            } else {
                ret = 7;
            }
        }
    }
    return ret;
}

s32 load_and_verify_data(s32 verify_only) {
    s32 serial;
    GuildCardSaveData *copy;
    u32 sum;

    TAdSinglePlyChrSelectGC::set_save_slot(0);
    serial = TAdSinglePlyChrSelectGC::get_serial_seed();
    chr_select_serial_seeds[1] = serial;
    chr_select_serial_seeds[0] = serial;
    memcpy(guild_card_save_payload, guild_card_save_file_buffer + sizeof(CardSaveHeader), 0xE28C);
    decrypt_guild_card_payload(guild_card_save_payload);
    copy = (GuildCardSaveData *)::operator new(0xE28C);
    if (copy != NULL) {
        copy = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(copy);
    }
    copy_guild_card_payload(copy, guild_card_save_payload);
    sum = copy->checksum;
    copy->checksum = 0U;
    if (sum != calc_crc32_bitwise((u8 *)copy, (u32)(0xE28C))) {
        if (verify_only != 0) {
            ::operator delete(copy);
            return 0;
        }
        init_timestamped_data();
        goto block_9;
    }
    if (verify_only != 0) {
        ::operator delete(copy);
        return 1;
    }
    TAdSinglePlyChrSelectGC::set_save_slot(1);
block_9:
    ::operator delete(copy);
    return 1;
}
GuildCardSaveData *copy_guild_card_payload(GuildCardSaveData *dest, GuildCardSaveData *source) {
    dest->checksum = source->checksum;
    copy_guild_card_entries((saddr)&dest->list, (saddr)&source->list);
    dest->tags = source->tags;
    dest->timestamp_seconds = source->timestamp_seconds;
    dest->cipher_seed = source->cipher_seed;
    return dest;
}
typedef struct ByteBlock_C0 ByteBlock_C0;
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
s32 copy_guild_card_entries(saddr dest, saddr source) {
  u32 end;
  u32 card_dest;
  saddr card_source;
  *((ByteBlock_C0 *) dest) = *((const ByteBlock_C0 *) source);
  card_dest = dest + 0xC0;
  end = dest;
  end = end + 0xD2C0;
  card_source = source + 0xC0;
  do
  {
    __as__13GuildCardSlotFRC13GuildCardSlot(card_dest, (u8 *)card_source);
    card_dest += 0x100;
    card_source += 0x100;
  }
  while (card_dest < end);
  return dest;
}


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Slot_80200690 { u8 data[0x2798]; };

struct Pair_80200690 { u32 a; u32 b; };

struct Tail_80200690 { Pair_80200690 p0, p1, p2, p3, p4, p5, p6; };

struct Save_80200690 {
    s32 hdr;
    Slot_80200690 slots[7];
    Tail_80200690 tail;
    u32 x;
    u32 y;
};


extern "C" {
s32 __ct__13GuildCardSlotFv(s32 object);
}
extern "C" {
void TLobby__sub_801F494C(u16 client);
s32 __ct__14GuildCardEntryFv(s32 ply_guild_card_tag);

void *TAdSinglePlyChrSelectGC::init_windows(void *file) {
    TAdSinglePlyChrSelectGC::construct_card_window_array(&((GuildCardSaveData *)file)->list);
    TAdSinglePlyChrSelectGC::construct_guild_card_tag_array(&((GuildCardSaveData *)file)->tags);
    return file;
}


void *TAdSinglePlyChrSelectGC::construct_guild_card_tag_array(void *array) {
    __construct_array(array, (void *)__ct__14GuildCardEntryFv, 0, 0x90, 0x1C);
    return array;
}

u8 *TAdSinglePlyChrSelectGC::construct_card_window_array(void *list) {
    __construct_array(((GuildCardList *)list)->entries, (void *)__ct__13GuildCardSlotFv, 0, 0x100, 0xD2);
    return (u8 *)list;

}

#pragma push
#pragma fp_contract on
s32 TAdSinglePlyChrSelectGC::verify_save_checksum(int keep_on_mismatch) {
    u32 stored_sum;
    u32 actual_sum;
    memcpy(system_save_payload, system_save_file_buffer + sizeof(CardSaveHeader), 0x11C);
    stored_sum = system_save_payload->checksum;
    system_save_payload->checksum = 0U;
    actual_sum = ((u32)calc_crc32_bitwise((u8 *)system_save_payload, 0x11C));
    if (actual_sum != stored_sum) {
        if (keep_on_mismatch == 0) {
            TAdSinglePlyChrSelectGC::reset_save_header();
        }
        return 0;
    }
    return 1;
}
#pragma pop


void TAdSinglePlyChrSelectGC::verify_save_checksum(void) {
    u32 sum;
    u32 r;
    memcpy(secondary_card_system_save_payload, system_save_file_buffer + sizeof(CardSaveHeader), 0x11C);
    sum = secondary_card_system_save_payload->checksum;
    secondary_card_system_save_payload->checksum = 0;
    r = (u32)calc_crc32_bitwise((u8 *)secondary_card_system_save_payload, 0x11C);
    if (r != sum) {
        return;
    }
}

void TAdSinglePlyChrSelectGC__sub_801FFF14(void) {
    s32 serial_seed;
    serial_seed = TAdSinglePlyChrSelectGC::get_serial_seed();
    chr_select_serial_seeds[1] = serial_seed;
    chr_select_serial_seeds[0] = serial_seed;
    encrypt_guild_card_payload(guild_card_save_payload, chr_select_serial_seeds);
    TAdSinglePlyChrSelectGC::build_save_file();
    decrypt_guild_card_payload(guild_card_save_payload);
}

void TAdSinglePlyChrSelectGC::create_instance(void) {
    system_save_payload->checksum = 0;
    system_save_payload->checksum = calc_crc32_bitwise((u8 *)system_save_payload, 0x11C);
    TAdSinglePlyChrSelectGC::build_default_save_file();
}


void decrypt_guild_card_payload(GuildCardSaveData *data) {
    GuildCardSaveData *a;
    GuildCardSaveData *b;
    a = (GuildCardSaveData *)::operator new(0xE28C);
    if (a != 0) {
        a = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(a);
    }
    b = (GuildCardSaveData *)::operator new(0xE28C);
    if (b != 0) {
        b = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(b);
    }
    copy_guild_card_payload(a, data);
    copy_guild_card_payload(b, data);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle(&chr_select_rng_state);
    subtractive_rng_unshuffle(&chr_select_rng_state, (const u8 *)a, (u8 *)b, 0xE28C);
    copy_guild_card_payload(data, b);
    ::operator delete(b);
    ::operator delete(a);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    chr_select_rng_state.apply_rng_cipher((u32 *)data, 0xE28C);
    subtractive_rng_seed(&chr_select_rng_state, data->cipher_seed);
    subtractive_rng_xor_buffer(&chr_select_rng_state, (u32 *)data, 0xE288);
}

#pragma push
#pragma opt_common_subs off
void encrypt_guild_card_payload(GuildCardSaveData *data, void *arg1) {
    GuildCardSaveData *a;
    GuildCardSaveData *b;
    data->cipher_seed = subtractive_rng_next(&chr_select_rng_state);
    data->checksum = 0;
    data->checksum = calc_crc32_bitwise((u8 *)data, 0xE28C);
    subtractive_rng_seed(&chr_select_rng_state, data->cipher_seed);
    subtractive_rng_xor_buffer(&chr_select_rng_state, (u32 *)data, 0xE288);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    chr_select_rng_state.apply_rng_cipher((u32 *)data, 0xE28C);
    a = (GuildCardSaveData *)::operator new(0xE28C);
    if (a != 0) {
        a = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(a);
    }
    b = (GuildCardSaveData *)::operator new(0xE28C);
    if (b != 0) {
        b = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(b);
    }
    copy_guild_card_payload(a, data);
    copy_guild_card_payload(b, data);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle(&chr_select_rng_state);
    chr_select_rng_state.permute_save_blocks((const u8*)a, (u8*)b, (u32)0xE28C);
    copy_guild_card_payload(data, b);
    ::operator delete(b);
    ::operator delete(a);
}
}
#pragma pop

void game_state_load(void) {
    memcpy(selected_character_data, get_selected_character_slot(card_character_save_buffer), 0x41C);
    memcpy(active_character_save_record, get_selected_save_record(card_character_save_buffer), 0x2370);
    TLobby__sub_801F494C(0);
    if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        if (TAdSinglePlyChrSelectGC::check_flag(1) != 0U) {
            TAdSinglePlyChrSelectGC::reset_character_data();
        } else {
            void *a = selected_character_data;
            void *b;
            if (((u8) *(u8 *)((s8 *)a + 0) == 0) && ((s32) *(s32 *)((s8 *)a + 0x36C) == 0) && ((b = active_character_save_record, (s32) *(s32 *)((s8 *)b + 0x248)) == 0) && ((s32) *(s32 *)((s8 *)b + 0x24C) == 0)) {
                init_class_starting_inventory(a);
            }
        }
    }
    *(s8 *)((s8 *)selected_character_data + 3) = (s8) current_language;
}

s32 TAdSinglePlyChrSelectGC::apply_loaded_character(int verify_only) {
    s32 r = TAdEnterSerialAccessGC::get_serial_seed();
    chr_select_serial_seeds[1] = r;
    chr_select_serial_seeds[0] = r;
    memcpy(card_character_save_buffer, character_save_file_buffer + sizeof(CardSaveHeader), 0x1156C);
    TAdSinglePlyChrSelectGC::decrypt_char_data(card_character_save_buffer);
    if (check_slot_a_card_save() != 7) {
        return 0;
    }
    if (verify_only != 0) {
        return 1;
    }
    memcpy(selected_character_data, get_selected_character_slot(card_character_save_buffer), 0x41C);
    memcpy(active_character_save_record, get_selected_save_record(card_character_save_buffer), 0x2370);
    TLobby__sub_801F494C(0);
    if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        if (TAdSinglePlyChrSelectGC::check_flag(1) != 0U) {
            TAdSinglePlyChrSelectGC::reset_character_data();
        } else {
            void *a = selected_character_data;
            void *b;
            if (*(u8 *)a == 0 && *(s32 *)((u8 *)a + 0x36C) == 0 &&
                (b = (*(void *const *)&active_character_save_record), *(s32 *)((u8 *)b + 0x248) == 0) && *(s32 *)((u8 *)b + 0x24C) == 0) {
                init_class_starting_inventory(a);
            }
        }
    }
    *((s8 *)selected_character_data + 3) = (s8)current_language;
    TAdSinglePlyChrSelectGC::set_state(0);
    return 1;
}

void TAdSinglePlyChrSelectGC__sub_80200418(void) {
    s32 r = TAdEnterSerialAccessGC::get_serial_result();
    chr_select_serial_seeds[1] = r;
    chr_select_serial_seeds[0] = r;
    memcpy(secondary_card_character_save_buffer, character_save_file_buffer + sizeof(CardSaveHeader), 0x1156C);
    TAdSinglePlyChrSelectGC::decrypt_char_data(secondary_card_character_save_buffer);
    if (check_slot_b_card_save() == 7) {
        return;
    }
}

void TAdSinglePlyChrSelectGC::prepare_save_data(void) {
    s32 r = TAdEnterSerialAccessGC::get_serial_seed();
    chr_select_serial_seeds[1] = r;
    chr_select_serial_seeds[0] = r;
    memcpy(get_selected_character_slot(card_character_save_buffer), selected_character_data, 0x41C);
    memcpy(get_selected_save_record(card_character_save_buffer), active_character_save_record, 0x2370);
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
}

s32 TAdSinglePlyChrSelectGC::encrypt_and_save(void) {
    s32 seed;
    seed = TAdEnterSerialAccessGC::get_serial_result();
    chr_select_serial_seeds[1] = seed;
    chr_select_serial_seeds[0] = seed;
    TAdSinglePlyChrSelectGC::encrypt_save_data(secondary_card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(0);
    return 1;
}
s32 TAdSinglePlyChrSelectGC::write_encrypted_save(void) {
    s32 seed;
    seed = TAdEnterSerialAccessGC::get_serial_seed();
    chr_select_serial_seeds[1] = seed;
    chr_select_serial_seeds[0] = seed;
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
    return 1;
}

void TAdSinglePlyChrSelectGC::decrypt_char_data(void *file) {
    CharacterFile *a = new CharacterFile;
    CharacterFile *b = new CharacterFile;
    TAdSinglePlyChrSelectGC::copy_save_data(a, (CharacterFile *)file);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle(&chr_select_rng_state);
    subtractive_rng_unshuffle(&chr_select_rng_state, (const u8 *)a, (u8 *)b, 0x1156C);
    TAdSinglePlyChrSelectGC::copy_save_data((CharacterFile *)file, b);
    delete b;
    delete a;
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    chr_select_rng_state.apply_rng_cipher((u32 *)file, 0x1156C);
    subtractive_rng_seed(&chr_select_rng_state, get_character_file_seed((u8 *)file));
    subtractive_rng_xor_buffer(&chr_select_rng_state, (u32 *)file, 0x11568);
}

CharacterFile *TAdSinglePlyChrSelectGC::copy_save_data(CharacterFile *to, CharacterFile *from) {
    Save_80200690 *dst = (Save_80200690 *)to;
    Save_80200690 *src = (Save_80200690 *)from;
    Slot_80200690 *d;
    Slot_80200690 *s;
    dst->hdr = src->hdr;
    d = dst->slots;
    s = src->slots;
    do {
        TAdSinglePlyChrSelectGC::copy_char_slot_data(d, s);
        d++;
        s++;
    } while (d < &dst->slots[7]);
    dst->tail = src->tail;
    dst->x = src->x;
    dst->y = src->y;
    return to;
}

#define self ((s32 *)file)
void TAdSinglePlyChrSelectGC::encrypt_save_data(void *file) {
    CharacterFile *a;
    CharacterFile *b;
    set_character_file_seed((u8 *)self, (s32)(subtractive_rng_next(&chr_select_rng_state)));
    TAdSinglePlyChrSelectGC::set_id(self, 0);
    TAdSinglePlyChrSelectGC::set_id((void *)self, (s32)(calc_crc32_bitwise((u8 *)self, 0x1156C)));
    subtractive_rng_seed(&chr_select_rng_state, get_character_file_seed((u8 *)self));
    subtractive_rng_xor_buffer(&chr_select_rng_state, (u32 *)self, 0x11568);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    chr_select_rng_state.apply_rng_cipher((u32 *)self, 0x1156C);
    a = new CharacterFile;
    b = new CharacterFile;
    TAdSinglePlyChrSelectGC::copy_save_data(a, (CharacterFile *)self);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle(&chr_select_rng_state);
    chr_select_rng_state.permute_save_blocks((const u8*)a, (u8*)b, (u32)0x1156C);
    TAdSinglePlyChrSelectGC::copy_save_data((CharacterFile *)self, b);
    delete b;
    delete a;
}
#undef self

// The save writers address the neighboring card records relative to the character record.
struct CardSaveMetadataBlock {
    CharacterCardMetadata character;
    char system_filename[0x20];
    char system_dir_name[0x20];
    char character_dir_name[0x20];
    EpisodeCardMetadata episode;
    GuildCardFile_804C89BC guild_card;
};

void TAdSinglePlyChrSelectGC::build_save_file() {
    const CardSaveMetadataBlock *metadata = reinterpret_cast<const CardSaveMetadataBlock *>(&pso_character_card_filename);
    CardSaveDescriptor f;
    memset(&f, 0, sizeof(f));
    strcpy(f.filename, metadata->episode.game_name);
    strcpy(f.title, metadata->guild_card.comment);
    memcpy(f.key, metadata->episode.icon, 0x10);
    set_card_banner_and_icon(&f, 1);
    f.field_4c = 1;
    f.field_4e = 1;
    f.field_50 = 0;
    f.omit_title_space = 0;
    f.data = (u8 *)guild_card_save_payload;
    f.size = 0xE28C;
    TAdPlayerLoadGC::build_save_file_image((void *)guild_card_save_file_buffer, &f);
    release_card_banner_and_icon(&f);
}

void TAdSinglePlyChrSelectGC::build_default_save_file() {
    const CardSaveMetadataBlock *metadata = reinterpret_cast<const CardSaveMetadataBlock *>(&pso_character_card_filename);
    CardSaveDescriptor f;
    memset(&f, 0, sizeof(f));
    strcpy(f.filename, metadata->episode.game_name);
    strcpy(f.title, metadata->episode.comment);
    memcpy(f.key, metadata->episode.icon, 0x10);
    set_card_banner_and_icon(&f, 0);
    f.field_4c = 1;
    f.field_4e = 1;
    f.field_50 = 0;
    f.omit_title_space = 0;
    f.data = (u8 *)system_save_payload;
    f.size = 0x11C;
    TAdPlayerLoadGC::build_save_file_image((void *)system_save_file_buffer, &f);
    release_card_banner_and_icon(&f);
}

void TAdSinglePlyChrSelectGC::save_character_file(int use_primary) {
    const CardSaveMetadataBlock *metadata = reinterpret_cast<const CardSaveMetadataBlock *>(&pso_character_card_filename);
    CardSaveDescriptor f;
    memset(&f, 0, sizeof(f));
    strcpy(f.filename, metadata->episode.game_name);
    strcpy(f.title, metadata->character.comment);
    memcpy(f.key, metadata->character.icon, 0x10);
    set_card_banner_and_icon(&f, 2);
    f.field_4c = 1;
    f.field_4e = 1;
    f.field_50 = 0;
    f.omit_title_space = 0;
    if (use_primary != 0) {
        f.data = (u8 *)card_character_save_buffer;
    } else {
        f.data = (u8 *)secondary_card_character_save_buffer;
    }
    f.size = 0x1156C;
    TAdPlayerLoadGC::build_save_file_image((void *)character_save_file_buffer, &f);
    release_card_banner_and_icon(&f);
    if (use_primary != 0) {
        TAdSinglePlyChrSelectGC::decrypt_char_data(card_character_save_buffer);
    } else {
        TAdSinglePlyChrSelectGC::decrypt_char_data(secondary_card_character_save_buffer);
    }
}

void TAdSinglePlyChrSelectGC::reset_character_data(void) {
    s32 i;
    saddr result;

    if ((void *) selected_character_data != NULL) {
        result = reinterpret_cast<saddr>(reinterpret_cast<TPlyCharData *>(get_selected_character_slot(card_character_save_buffer))->m_inventory.get_items());
        i = 0;
        do {
            ((TAdSinglePlyChrSelectGC *)result)->clear_inventory_slot();
            i += 1;
            result += 0x1C;
        } while (i < 0x1E);
        *(s8 *)((s8 *)selected_character_data + 0) = 0;
        init_class_starting_inventory(selected_character_data);
        TPlyCharData *character = selected_character_data;
        init_character_stats_for_level(character->m_disp_part2.char_class, character, character->m_stats.level);
        selected_character_data->reset_technique_levels();
        ((TObjPlayer *)selected_character_data)->return_city_window = 0;
    }
    if (active_character_save_record != NULL) {
        memset((u8 *)active_character_save_record + 0x250, 0, 0x12C0);
        active_character_save_record->bank_item_count = 0;
        active_character_save_record->pad_24C = 0;
        memset((u8 *)active_character_save_record + 0x21C4, 0, 0x100);
    }
}
s32 TAdSinglePlyChrSelectGC::save_online_character(void) {
    CharacterFile *file;
    s32 cw;
    s32 inst;
    saddr obj;
    u8 *buf;
    if (lbl_805D55C0 == 1) {
        if (active_character_save_record != NULL) {
            active_character_save_record->save_count++;
            return active_character_save_record->save_count;
        }
        return 0;
    }
    if (selected_character_data != NULL && active_character_save_record != NULL && card_character_save_buffer != NULL) {
        stop_pad_rumble();
        character_save_card_slot = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
        if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0;
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        if (TAdPlayerLoadGC::find_card_file(character_save_card_slot, pso_character_card_filename.filename) != 0) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0;
        }
        obj = character_save_file_block_count << 13;
        buf = (u8 *)TQuestVmDownLoadServer::alloc(obj);
        memset(buf, 0, obj);
        while (start_memcard_read(character_save_card_slot, pso_character_card_filename.filename, buf, character_save_file_block_count) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                if (buf != 0) {
                    safe_free(buf);
                }
                return 0;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        while (poll_memcard_result(character_save_card_slot) != 0) {
            if (TAdPlayerLoadGC::probe_card_slot(character_save_card_slot) != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                if (buf != 0) {
                    safe_free(buf);
                }
                return 0;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = TAdEnterSerialAccessGC::get_serial_seed();
        file = new CharacterFile;
        memset(file, 0, 0x1156C);
        memcpy(file, buf + 0x2048, 0x1156C);
        TAdSinglePlyChrSelectGC::decrypt_char_data(file);
        if (TAdSinglePlyChrSelectGC::compare_save_headers(get_selected_save_record(file), (CharacterSaveRecord *)get_character_save_record(0xFFFF), file, (CharacterFile *)TAdSinglePlyChrSelectGC::get_instance()) != 7) {
            if (buf != 0) {
                safe_free(buf);
            }
            if (file != NULL) {
                delete file;
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0;
        }
        if (buf != 0) {
            safe_free(buf);
        }
        if (file != NULL) {
            delete file;
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && poll_memcard_result(character_save_card_slot) == 0) {
            TObjPlayer::sync_char_select_state();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            active_character_save_record->save_count++;
            TAdSinglePlyChrSelectGC::increment_counter();
            memcpy(get_selected_character_slot(card_character_save_buffer), selected_character_data, 0x41C);
            memcpy(get_selected_save_record(card_character_save_buffer), active_character_save_record, 0x2370);
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
                s32 i;
                saddr p;
                p = reinterpret_cast<saddr>(reinterpret_cast<TPlyCharData *>(get_selected_character_slot(card_character_save_buffer))->m_inventory.get_items());
                for (i = 0; i < 30; i++) {
                    ((TAdSinglePlyChrSelectGC *)p)->clear_inventory_slot();
                    p += 0x1C;
                }
                {
                    u8 *s = (u8 *)get_selected_character_slot(card_character_save_buffer);
                    *s = 0;
                }
                {
                    CharacterSaveRecord *q = get_selected_save_record(card_character_save_buffer);
                    memset(q->bank_items, 0, 0x12C0);
                    q->bank_item_count = 0;
                    q->pad_24C = 0;
                }
            }
            *(s32 *)((u8 *)get_selected_character_slot(card_character_save_buffer) + 0x36C) = 0;
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = TAdEnterSerialAccessGC::get_serial_seed();
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            if (start_character_file_write() == 0) {
                card_load_sequence_state = 6;
            }
        }
        return active_character_save_record->save_count;
    }
    return 0;
}


extern "C" {
void TAdSinglePlyChrSelectGC__sub_8028DC1C();
}

s32 TAdSinglePlyChrSelectGC::increment_frame() {
    if (active_character_save_record != NULL) {
        active_character_save_record->save_count = (s32) (active_character_save_record->save_count + 1);
        return active_character_save_record->save_count;
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::get_player_count() {
    if (active_character_save_record != NULL) {
        return *(s32 *)((s8 *)active_character_save_record + 4);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::update_elapsed_time(CharacterSaveRecord *record) {
    s32 date[4];
    s32 start_seconds;
    s32 end_seconds;

    if (record != NULL) {
        DateToSeconds((DateStamp *)(char_select_date_stamp), (int *)(&start_seconds));
        getDateStamp((DateStamp *)date);
        DateToSeconds((DateStamp *)(date), (int *)(&end_seconds));
        record->play_time += end_seconds - start_seconds;
        return record->play_time;
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::update_play_time() {
    s32 start_seconds;
    s32 end_seconds;
    if ((void *) (*(u8 * *)&active_character_save_record) != NULL) {
        DateToSeconds((DateStamp *)char_select_date_stamp, (int *)(&start_seconds));
        getDateStamp((DateStamp *)char_select_date_stamp);
        DateToSeconds((DateStamp *)char_select_date_stamp, (int *)(&end_seconds));
        *(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC) = (s32) (*(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC) + (end_seconds - start_seconds));
        return *(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::init_and_register(CharacterFile *source) {
    CharacterFile *allocation;
    u32 type;
    u32 actual_sum;

    allocation = new CharacterFile;
    TAdSinglePlyChrSelectGC::copy_save_data(allocation, source);
    type = TAdSinglePlyChrSelectGC::get_type(allocation);
    TAdSinglePlyChrSelectGC::set_id(allocation, 0);
    actual_sum = calc_crc32_bitwise((u8 *)allocation, 0x1156C);
    delete allocation;
    if (type == actual_sum) {
        return 1;
    }
    return 0;
}

u32 calc_crc32_bitwise(u8 *data, u32 size) {
    u32 crc = -1;
    u32 i;
    for (i = 0; i < size; i++) {
        s32 j;
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            u32 bit0 = crc & 1;
            crc >>= 1;
            if (bit0 != 0) {
                crc ^= 0xEDB88320;
            }
        }
    }
    return crc ^ 0xFFFFFFFF;
}


void init_timestamped_data(void) {
    char date[0x18];

    stop_pad_rumble();
    memset(guild_card_save_payload, 0, 0xE28C);
    getDateStamp((DateStamp *)((s32 *) date));
    DateToSeconds((DateStamp *)((s32 *)((s32 *) date)), (int *)&guild_card_save_payload->timestamp_seconds);
    TAdSinglePlyChrSelectGC::set_save_slot(0);
}

void TAdSinglePlyChrSelectGC::reset_save_header() {
  volatile unsigned long long now;
  u64 serial_number;
  memset(system_save_payload, 0, 0x11C);
  system_save_payload->version_4 = -0x32;
  system_save_payload->flags_6 = 0;
  system_save_payload->language = TLanguage::get_default_language();
  system_save_payload->clock_offset_frames = default_clock_offset_frames();
  system_save_payload->field_c = 0;
  system_save_payload->field_e = 0;
  TAdPlayerLoadGC::reset_load_state(0, &serial_number);
  memmove((void *)&system_save_payload->serial_number, &serial_number, sizeof(serial_number));
  getDateStamp((DateStamp *)(&now));
  DateToSeconds((DateStamp *)(&now), (int *)&system_save_payload->serial_seed);
}

void init_fresh_character_card(void) {
    TPlyCharData *chr;
    CharacterSaveRecord *card;
    s32 i;
    stop_pad_rumble();
    chr = TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
    card = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
    memset(chr, 0, 0x41C);
    TAdSinglePlyChrSelectGC__sub_8028DC1C();
    TObjPlayer::begin_action_from_char_select();
    memset(card, 0, 0x2370);
    getDateStamp((DateStamp *)char_select_date_stamp);
    DateToSeconds((DateStamp *)char_select_date_stamp, (int *)(&card->creation_seconds));
    card->magic = 0xA205B064;
    card->play_time = 0;
    card->flags = 0;
    card->save_count = 1;
    memcpy(card->account, get_account_entry(0), 0x1C);
    memcpy(card->user_name, get_account_user_name(0), 0x10);
    clear_all_story_flags();
    card->bank_item_count = 0;
    card->pad_24C = 0;
    for (i = 0; i < 200; i++) {
        card->bank_items[i].init();
    }
    ((SavedSymbolChatPresets *)card)->load_symbol_chat_data();
    set_fresh_card_flag(card);
    TWindowShortListCtrl__sub_8026E884((s16 *)((u8 *)card + 0x22C4));
}

s32 TAdSinglePlyChrSelectGC::free_buffer() {
    if (guild_card_save_file_buffer != NULL) {
        safe_free(guild_card_save_file_buffer);
        guild_card_save_file_buffer = NULL;
        return 1;
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::free_data() {
    if (system_save_file_buffer != NULL) {
        safe_free(system_save_file_buffer);
        system_save_file_buffer = NULL;
        return 1;
    }
    return 0;
}

s32 buffer_init(void) {
    s32 size;

    if (guild_card_save_file_buffer == NULL) {
        size = guild_card_save_file_block_count << 0xD;
        guild_card_save_file_buffer = (u8 *)TQuestVmDownLoadServer::alloc(size);
        memset((void *)guild_card_save_file_buffer, 0, size);
        return 1;
    }
    return 0;
}


s32 alloc_global_buffer(void) {
    s32 size;

    if (system_save_file_buffer == NULL) {
        size = system_save_file_block_count << 0xD;
        system_save_file_buffer = (u8 *)TQuestVmDownLoadServer::alloc(size);
        memset((void *)system_save_file_buffer, 0, size);
        return 1;
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC::free() {
    if (character_save_file_buffer != NULL) {
        safe_free(character_save_file_buffer);
        character_save_file_buffer = NULL;
        return 1;
    }
    return 0;
}

s32 init_buffer(void) {
    s32 size;

    if (character_save_file_buffer == NULL) {
        size = character_save_file_block_count << 0xD;
        character_save_file_buffer = (u8 *)TQuestVmDownLoadServer::alloc(size);
        memset((void *)character_save_file_buffer, 0, size);
        return 1;
    }
    return 0;
}


void TAdSinglePlyChrSelectGC::run_save_load_sequence(void) {
    switch (card_load_sequence_state) {
    case 2:
        init_fresh_character_card();
        card_load_sequence_state = 4;
        break;
    case 3:
        TObjPlayer::init_battle_selection();
        TAdSinglePlyChrSelectGC__sub_8028DC14();
        card_load_sequence_state = 4;
        break;
    case 4:
        TAdSinglePlyChrSelectGC::prepare_save_data();
        card_load_sequence_state = 5;
        break;
    case 5:
        if (start_character_file_write() == 0) {
            card_load_sequence_state = 6;
            break;
        }
    default:
        break;
    case 6:
        stop_pad_rumble();
        if (poll_memcard_result(character_save_card_slot) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            memcard_access_active = 0;
            break;
        }
        break;
    case 7:
        if (TAdSinglePlyChrSelectGC::load_chr_select_slot() == 0) {
            card_load_sequence_state = 8;
            break;
        }
        break;
    case 8:
        stop_pad_rumble();
        if (poll_memcard_result(character_save_card_slot) == 0) {
            card_load_sequence_state = 9;
            break;
        }
        break;
    case 9:
        TAdSinglePlyChrSelectGC::apply_loaded_character(0);
        card_load_sequence_state = 0;
        TAdSinglePlyChrSelectGC::reset_quest_id();
        memcard_access_active = 0;
        break;
    case 10:
        if (start_character_file_write() == 0) {
            card_load_sequence_state = 6;
            break;
        }
        break;
    case 11:
        stop_pad_rumble();
        if (poll_memcard_result(character_save_card_slot) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            memcard_access_active = 0;
            break;
        }
        break;
    case 13:
        stop_pad_rumble();
        if (poll_memcard_result(card_load_channel) == 0) {
            card_load_sequence_state = 0xE;
            break;
        }
        break;
    case 14:
        load_and_verify_data(0);
        card_load_sequence_state = 0;
        TAdSinglePlyChrSelectGC::reset_quest_id();
        memcard_access_active = 0;
        break;
    case 12:
        stop_pad_rumble();
        if (poll_memcard_result(card_load_channel) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            memcard_access_active = 0;
            break;
        }
        break;
    case 15:
        if (poll_memcard_result(system_save_card_channel) == 0) {
            card_load_sequence_state = 0;
            memcard_access_active = 0;
            break;
        }
        break;
    case 17:
        if (poll_memcard_result(system_save_card_channel) == 0) {
            TAdSinglePlyChrSelectGC::verify_save_checksum(1);
            if (card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                TAdSinglePlyChrSelectGC::load_selected_char();
                break;
            }
            card_load_sequence_state = 0;
            memcard_access_active = 0;
            break;
        }
        break;
    case 16:
        if (poll_memcard_result(system_save_card_channel) == 0) {
            TAdSinglePlyChrSelectGC::verify_save_checksum(0);
            if (card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                TAdSinglePlyChrSelectGC::load_selected_char();
                break;
            }
            card_load_sequence_state = 0;
            memcard_access_active = 0;
            break;
        }
        break;
    case 18:
        stop_pad_rumble();
        if (poll_memcard_result(1) == 0) {
            card_load_sequence_state = 0;
            memcard_access_active = 0;
            break;
        }
        break;
    case 19:
        stop_pad_rumble();
        if (poll_memcard_result(0) == 0) {
            card_load_sequence_state = 0;
            memcard_access_active = 0;
            break;
        }
        break;
    case 20:
        stop_pad_rumble();
        if (poll_memcard_result(1) == 0) {
            card_load_sequence_state = 0x15;
            break;
        }
        break;
    case 21:
        TAdSinglePlyChrSelectGC__sub_80200418();
        card_load_sequence_state = 0;
        memcard_access_active = 0;
        break;
    case 22:
        if (poll_memcard_result(1) == 0) {
            TAdSinglePlyChrSelectGC::verify_save_checksum();
            if (card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                TAdSinglePlyChrSelectGC__sub_801FEBBC();
                break;
            }
            card_load_sequence_state = 0;
            memcard_access_active = 0;
        }
        break;
    }
}

void TAdSinglePlyChrSelectGC::release_all() {
    TAdSinglePlyChrSelectGC::free_char_data_slots(chr_select_buffer_ptr_table);
    chr_select_request_buffer.clear_slot_lists();
    if (selected_character_data != NULL) {
        delete selected_character_data;
    }
    if ((void *) (*(u8 * *)&active_character_save_record) != NULL) {
        ::operator delete(((void *) ((*(u8 * *)&active_character_save_record))));
    }
    if ((void *) (*(u8 * *)&guild_card_save_payload) != NULL) {
        ::operator delete(((void *) ((*(u8 * *)&guild_card_save_payload))));
    }
    if (card_character_save_buffer != NULL) {
        delete card_character_save_buffer;
    }
    TAdSinglePlyChrSelectGC::free();
    TAdSinglePlyChrSelectGC::free_buffer();
    TAdSinglePlyChrSelectGC::free_data();
}


void TAdSinglePlyChrSelectGC::init_char_select_globals() {
    u32 seconds;
    CharacterFile *card;
    CharacterSaveRecord *record;
    GuildCardSaveData *guild;

    TAdSinglePlyChrSelectGC::selection_index = 0;
    card_load_followup_pending = 0;
    TAdSinglePlyChrSelectGC::alloc_char_records(chr_select_buffer_ptr_table);
    chr_select_request_buffer.reset_slot_lists();
    {
        DVDDiskID *id = DVDGetCurrentDiskID();
        strncpy(chr_select_game_name_buffer, id->gameName, 4);
    }
    getDateStamp((DateStamp *)char_select_date_stamp);
    DateToSeconds((DateStamp *)char_select_date_stamp, (int *)&seconds);
    switch (seconds % 24) {
    default:
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        break;
    case 1:
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        break;
    case 2:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 3:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 4:
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 5:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 6:
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 7:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 8:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 9:
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 10:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 11:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 12:
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 13:
        system_save_payload = new SystemSaveData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 14:
        system_save_payload = new SystemSaveData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 15:
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 16:
        system_save_payload = new SystemSaveData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 17:
        system_save_payload = new SystemSaveData;
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 18:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 19:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 20:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 21:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 22:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = new SystemSaveData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 23:
        guild = (GuildCardSaveData *)::operator new(0xE28C);
        if (guild != 0) {
            guild = (GuildCardSaveData *)TAdSinglePlyChrSelectGC::init_windows(guild);
        }
        guild_card_save_payload = guild;
        record = new CharacterSaveRecord;
        active_character_save_record = record;
        selected_character_data = new TPlyCharData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = new SystemSaveData;
        break;
    }
    memset(selected_character_data, 0, 0x41C);
    memset(active_character_save_record, 0, 0x2370);
    memset(card_character_save_buffer, 0, 0x1156C);
    memset(system_save_payload, 0, 0x11C);
    TAdSinglePlyChrSelectGC::reset_save_header();
    init_timestamped_data();
    character_save_file_block_count = 0xB;
    guild_card_save_file_block_count = 0xA;
    system_save_file_block_count = 3;
    init_buffer();
    buffer_init();
    alloc_global_buffer();
    card_load_sequence_state = 0;
    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    card_load_channel = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    {
        s32 g = TAdEnterSerialAccessGC::get_serial_seed();
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = g;
    }
    {
        s8 buf[6];
        s32 i;
        for (i = 0; i < 6; i++) {
            buf[i] = 0;
        }
        lbl_80513918[0] = buf[3] | ((buf[2] << 8) | ((buf[0] << 24) | (buf[1] << 16)));
        lbl_80513918[1] = buf[5] | ((buf[4] << 8) | ((buf[2] << 24) | (buf[3] << 16)));
    }
    TAdSinglePlyChrSelectGC::set_state(0);
    TAdSinglePlyChrSelectGC::set_chr_select_state(1);
    TAdSinglePlyChrSelectGC::set_save_slot(0);
}


void TAdSinglePlyChrSelectGC::free_callbacks() {
    if (secondary_card_character_save_buffer != NULL) {
        delete secondary_card_character_save_buffer;
        secondary_card_character_save_buffer = NULL;
    }
    if (secondary_card_system_save_payload != NULL) {
        ::operator delete(secondary_card_system_save_payload);
        secondary_card_system_save_payload = NULL;
    }
}


void TAdSinglePlyChrSelectGC::alloc_char_buffers() {
    s32 buffer;
    s32 dst;
    s32 fill;
    s32 length;
    dst = 0x10000;
    dst = 0x1156C;
    buffer = (saddr)new CharacterFile;
    secondary_card_character_save_buffer = (CharacterFile *)buffer;
    dst = 0x11C;
    (*(s32 *)&secondary_card_system_save_payload) = (saddr)::operator new(0x11C);
    fill = 0x10000;
    dst = (*(s32 *)&secondary_card_character_save_buffer);
    length = 0x1156C;
    fill = 0;
    memset((void *)(saddr)dst, 0, 0x1156C);
    dst = (*(s32 *)&secondary_card_system_save_payload);
    fill = 0;
    length = 0x11C;
    memset((void *)(saddr)dst, 0, 0x11C);
}


int TAdSinglePlyChrSelectGC::get_serial_seed() { return TAdEnterSerialAccessGC::get_serial_seed(); }


s32 TAdEnterSerialAccessGC::get_serial_result() {
    return secondary_card_system_save_payload->serial_seed;
}

s32 TAdEnterSerialAccessGC::get_serial_seed() {
    return system_save_payload->serial_seed;
}

saddr get_character_save_record(u32 client) {
    if (is_split_screen() != 0) {
        if (client == 0xFFFF) {
            return get_split_screen_character_save_record(0U);
        }
        return get_split_screen_character_save_record(client);
    }
    return (saddr)active_character_save_record;
}

TPlyCharData *TAdSinglePlyChrSelectGC::get_char_index(unsigned int index) {
    if (is_split_screen() != 0) {
        if (index == 0xFFFF) {
            return get_char_table_entry(0);
        }
        return get_char_table_entry(index);
    }
    return selected_character_data;
}
