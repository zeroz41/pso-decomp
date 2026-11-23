#define PSO_SDK_COMPACT_MATH
#include <string.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/card.h>
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/frontend/CharacterSelectionRequest.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/unk/text_8007C0CC.h"
#include "types.h"
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
#include "pso/system/task/TMainTask.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/Language.h"
#include "pso/map/FloorArea.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/unk/TLobby_801461EC.h"
struct CardFileInfo_804C88C0 {
    char filename[0x20];
    char comment[0x20];
    u32 flags;
    u8 icon[0x10];
};
struct CardFileComment_804C8974 {
    char game_name[0x14];
    char comment[0x20];
    u32 flags;
    u8 icon[0x10];
};
struct GuildCardFile_804C89BC {
    char filename[0x20];
    char comment[0x20];
    u32 flags;
    char download_name[0x10];
    char download_dir[0x20];
    u32 download_flags;
};
CharacterFile *card_character_save_buffer;
CharacterFile *secondary_card_character_save_buffer;
TPlyCharData *selected_character_data;
uaddr active_character_save_record;
uaddr guild_card_save_payload;
uaddr system_save_payload;
uaddr secondary_card_system_save_payload;
s32 TAdSinglePlyChrSelectGC__selection_index;
s32 card_load_sequence_state;
saddr character_save_card_slot;
saddr card_load_channel;
saddr character_save_file_block_count;
saddr guild_card_save_file_block_count;
saddr system_save_card_channel;
saddr system_save_file_block_count;
uaddr character_save_file_buffer;
uaddr guild_card_save_file_buffer;
uaddr system_save_file_buffer;
s32 chr_select_scene_state;
s32 chr_select_game_mode;
s32 card_load_followup_pending;
s32 chr_select_save_slot;
char chr_select_game_name_buffer[4];
extern "C" {
CardFileInfo_804C88C0 pso_character_card_filename = {
    "PSO_CHARACTER", "CHARACTER_FILE", 0,
    { 0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'T', 'T', 'T', 'U' },
};
char pso_system_card_filename[0x20] = "PSO_SYSTEM";
char memory_card_system_dir_name[0x20] = "PSO3_SYSTEM";
char memory_card_character_dir_name[0x20] = "PSO3_CHARACTER";
CardFileComment_804C8974 episode_i_and_ii_card_filename = {
    "EPISODE I & II", "SYSTEM_FILE", 0,
    { 0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'U', 'T', 'T', 'T' },
};
GuildCardFile_804C89BC pso_guildcard_card_filename = {
    "PSO_GUILDCARD", "GUILDCARD_FILE", 0, "PSO______000", "PSOV2/DOWNLOAD", 0,
};
u8 TQuestVmDownLoadServer__memcard_key[0x10] = {
    0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'V', 'T', 'T', 'T',
};
const char memcard_default_banner[4] = "\xF0\x04";
const char memcard_default_icon[4] = "\x04";
}

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

struct Ent_801FD668 { u8 pad[0x428]; u32 f428; u8 pad2[0x2798 - 0x42C]; };

struct Ent_801FD728 { u8 pad0[4]; u8 a[0x41C]; u8 b[0x2798 - 0x420]; };

struct A_801FD8B8 { u8 p0[4]; u32 f4; u32 f8; u8 pC[8]; u32 f14; };

struct C_801FD8B8 { u8 p[0x11564]; s32 f11564; };

struct Ent_801FD6B4 { u8 pad[0x420]; u8 sub[8]; u32 f428; u8 pad2[0x2790 - 0x42C]; u32 f2790; u32 f2794; };

struct Slot_801FCB04 {
    u8 pad[0x428];
    u32 magic;
    u8 rest[0x2798 - 0x42C];
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

struct It_801FC0C8 { u8 b[0x18]; };

struct S_801FC0C8 { u8 pad[8]; s32 magic; u8 pad2[0x248 - 0xC]; s32 f248; s32 f24C; It_801FC0C8 items[200]; };

extern "C" {
extern s32 lbl_805D49B4;
char *strncpy(char *, const char *, size_t);

// Save-message window position and size (the same rect as TSaveChCr's message window).
static const NJS_POINT2 chr_select_save_message_window_pos = { 46.0f, 131.0f };
static const NJS_POINT2 chr_select_save_message_window_size = { 548.0f, 220.0f };
// Game code written over the memory card disk ID.
static const char card_disk_game_code[] = "GPSE";

s32 poll_memcard_result(saddr);
void __construct_array(void*, void*, void*, int, int);
void *TAdSinglePlyChrSelectGC__sub_802115C0(void *p);
u32 calc_crc32_bitwise(u8 *, u32);
s32 load_system_file__23TAdSinglePlyChrSelectGCFiPv(s32 arg0, s32 *arg1);
s32 start_memcard_read(s32, char *, void *, s32);
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(void *arg0);
s32 get_field_118__22TAdEnterSerialAccessGCFv(void);
s32 TAdSinglePlyChrSelectGC__sub_80202B1C(s32, s32);
u8 TAdSinglePlyChrSelectGC__sub_80202B30();
void TAdSinglePlyChrSelectGC__sub_80203210(void *p);
int fn_8020325C(void *arg0);
u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int arg0);
void load_tables(int a0);
CharacterFileSlot *TAdSinglePlyChrSelectGC__sub_801FCD04(CharacterFile *self);
CharacterSaveRecord *TAdSinglePlyChrSelectGC__sub_801FCD3C(CharacterFile *self);
int get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv(void);
s32 get_serial_result__22TAdEnterSerialAccessGCFv(void);
void init_timestamped_data(void);
saddr init_windows__23TAdSinglePlyChrSelectGCFi(saddr arg0);
s32 copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv(int, void *);
s32 is_item_record_empty(int);
s32 TLobby__sub_8030A770();
s32 get_game_play_mode();
s32 item_identity_matches(s32, s32);
s32 __destroy_arr(s32, s32 *, s32, s32);
s32 __ct__12TPlyCharDataFv(s32 arg0);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void game_state_load(void);


void TAdSinglePlyChrSelectGC::copy_name(s32 arg0) {
    if (arg0 >= 0) {
        // The character screen replaces the game code in the active disk ID.
        DVDDiskID *disk_id = const_cast<DVDDiskID *>(CARDGetDiskID(arg0));
        if (disk_id != NULL) {
            strncpy(disk_id->gameName, chr_select_game_name_buffer, sizeof(disk_id->gameName));
        }
    }
}

void TAdSinglePlyChrSelectGC::set_card_disk_id(s32 arg0) {
    if (arg0 >= 0) {
        // The character screen replaces the game code in the active disk ID.
        DVDDiskID *disk_id = const_cast<DVDDiskID *>(CARDGetDiskID(arg0));
        if (disk_id != NULL) {
            strncpy(disk_id->gameName, card_disk_game_code, sizeof(disk_id->gameName));
        }
    }
}

s32 load_system_file__23TAdSinglePlyChrSelectGCFiPv(s32 chan, s32 *arg1) {
    s32 ok;
    Buf_801FBFD0 *buf;
    u32 sum;
    s32 v;
    u32 r;
    Hdr_801FBFD0 *h;
    if (poll_memcard_result(chan) != 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::find_card_file(chan, (const char *)memory_card_system_dir_name) != 0) {
        return 0;
    }
    lbl_805D49B4 = 1;
    TAdSinglePlyChrSelectGC::set_card_disk_id(chan);
    ok = 0;
    buf = (Buf_801FBFD0 *)TQuestVmDownLoadServer::alloc(0x6000);
    if (TAdSinglePlyChrSelectGC::load_player_slot(chan, memory_card_system_dir_name, buf) == 0 &&
        TAdSinglePlyChrSelectGC::wait_for_card_load(chan) == 1) {
        h = &buf->hdr;
        v = h->f118;
        ok = 1;
        *arg1 = v;
        sum = h->sum;
        h->sum = 0;
        r = calc_crc32_bitwise((u8 *)h, (u32)(sizeof(Hdr_801FBFD0)));
        if (r != sum) {
            ok = 0;
        }
    }
    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
    TAdSinglePlyChrSelectGC::copy_name(chan);
    lbl_805D49B4 = 0;
    return ok;
}

s32 TAdSinglePlyChrSelectGC::init_char_slot_record() {
    S_801FC0C8 *arg0 = (S_801FC0C8 *)this;
    s32 i;
    if (arg0 == NULL) {
        return 0;
    }
    arg0->magic = 0xA205B064;
    arg0->f248 = 0;
    arg0->f24C = 0;
    for (i = 0; i < 200; i++) {
        ((TAdSinglePlyChrSelectGC *)(&arg0->items[i]))->init_item_entry();
    }
    return 1;
}

void TAdSinglePlyChrSelectGC::remove_matching_entries(s32 arg0) {
    s32 i;
    s32 n;
    saddr e;
    n = TAdSinglePlyChrSelectGC__sub_80202B30();
    for (i = 0; i < n; i++) {
        e = TAdSinglePlyChrSelectGC__sub_80202B1C(arg0, i);
        if (fn_8020325C((void *)(e + 8)) != 0) {
            TAdSinglePlyChrSelectGC__sub_80203210((void *)e);
        }
    }
}

s32 TAdSinglePlyChrSelectGC::is_level_capped() {
    return (u8) (*(s32 *)((s8 *)this + 0x248) >= 0xC8);
}

s32 TAdSinglePlyChrSelectGC::find_entry(s32 arg1) {
    s32 arg0 = (saddr)this;
    s32 var_r31;
    s32 var_r30;

    var_r31 = arg0 + 0x250;
    var_r30 = 0;
loop_1:
    if ((is_item_record_empty(var_r31) == 0) && (item_identity_matches(arg1, var_r31) != 0)) {
        return 1;
    }
    var_r30 += 1;
    var_r31 += 0x18;
    if (var_r30 >= 0xC8) {
        return 0;
    }
    goto loop_1;
}

s32 TAdSinglePlyChrSelectGC::register_in_free_room_slot(saddr arg1) {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;
    s32 var_r30;

    var_r30 = 0;
    var_r31 = (long) (arg0 + 0x250);
loop_1:
    if (is_item_record_empty(var_r31) != 0) {
        copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv((int)var_r31, (void *)arg1);
        *(s32 *)((s8 *)arg0 + 0x248) = (s32) (*(s32 *)((s8 *)arg0 + 0x248) + 1);
        return 1;
    }
    var_r30 += 1;
    var_r31 += 0x18;
    if (var_r30 >= 0xC8) {
        return 0;
    }
    goto loop_1;
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

u16 TAdSinglePlyChrSelectGC::get_card_window_field(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x235A);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_window_status(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x2358);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x2356);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_state(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x2354);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_flag(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21B0);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_field(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21AE);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_status(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21AC);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_value(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21AA);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_field_21a8(int arg0) {
    void *character_save_record;

    character_save_record = (void *)get_character_save_record((u16)arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21A8);
    }
    return 0U;
}

s32 *TAdSinglePlyChrSelectGC__sub_80202B38(void *self, s32 i);

s32 TAdSinglePlyChrSelectGC::append_inventory_item(saddr arg1) {
#define arg0 ((u8 *)this)
    u8 n = *arg0;

    if (n < 0x1E) {
        ((TAdSinglePlyChrSelectGC *)arg0)->clear_inventory_slot_by_index(n);
        memcpy(TAdSinglePlyChrSelectGC__sub_80202B38(arg0, n), (void *)arg1, 0x14);
        *arg0 += 1;
        return 1;
    }
    return 0;
#undef arg0
}

s32 TAdSinglePlyChrSelectGC::load_player_by_slot(s32 chan) {
    s32 card_file;
    card_file = -1;
    card_load_channel = chan;
    if ((chan >= 0) && (chan <= 7)) {
        card_file = TAdPlayerLoadGC::find_card_file(chan, (const char *)&pso_guildcard_card_filename);
        if (card_file == 0) {
            TAdSinglePlyChrSelectGC::set_quest_download_server(card_load_channel);
            lbl_805D49B4 = 1;
            card_file = TAdSinglePlyChrSelectGC::load_player_slot(card_load_channel, (const char *)&pso_guildcard_card_filename, (void *)guild_card_save_file_buffer);
        }
    }
    return card_file;
}

s32 TAdSinglePlyChrSelectGC::verify_system_file(void* _w0) {
    saddr temp_r3;
    s32 var_r30;
    var_r30 = 0;
    temp_r3 = (saddr)::operator new(0x11C);
    if (temp_r3 == 0) {
        return 0;
    }
    if (TAdPlayerLoadGC::find_card_file((s32)system_save_card_channel, (const char *)pso_system_card_filename) == 0) {
        lbl_805D49B4 = 1;
        TAdSinglePlyChrSelectGC::load_player_slot(system_save_card_channel, (const char *)pso_system_card_filename, (void *)system_save_file_buffer);
        stop_pad_rumble();
loop_4:
        if (poll_memcard_result(system_save_card_channel) != 0) {
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
            goto loop_4;
        }
        lbl_805D49B4 = 0;
        memcpy((void*)temp_r3, (void*)(system_save_file_buffer + 0x2048), 0x11C);
        var_r30 = ((TAdSinglePlyChrSelectGC *)temp_r3)->fields_equal((void *)system_save_payload);
    }
    ::operator delete((void *)temp_r3);
    return var_r30;
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
            TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
            return 0;
        }
    }
    g = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = g;
    p = new CharacterFile;
    if (p == NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
        return 0;
    }
    memset(p, 0, 0x1156C);
    memcpy(p, buf + 0x2048, 0x1156C);
    decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(p);
    if (card_character_save_buffer->pad_11564 != p->pad_11564) {
        delete p;
        TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
        return 0;
    }
    delete p;
    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
    return 1;
    }
    return 0;
}

CharacterFile::~CharacterFile() {}

CharacterFileSlot::~CharacterFileSlot() {}

CharacterFile::CharacterFile() {}

}

CharacterFileSlot::CharacterFileSlot() {}

extern "C" {

CharacterSaveRecord::CharacterSaveRecord() {
    __construct_array(bank_items, (void *)TAdSinglePlyChrSelectGC__sub_802115C0, NULL, 0x18, 200);
    ((TAdSinglePlyChrSelectGC *)guild_card)->init_guild_card_tag();
}

s32 TAdSinglePlyChrSelectGC::fields_equal(void *arg1) {
    return (u32) __cntlzw((u32) (*(s32 *)((s8 *)arg1 + 0x118) - *(s32 *)((s8 *)this + 0x118))) >> 5;
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
    if (TAdPlayerLoadGC::find_card_file(system_save_card_channel, (const char *)pso_system_card_filename) == 0) {
        lbl_805D49B4 = 1;
        TAdSinglePlyChrSelectGC::load_player_slot(system_save_card_channel, (const char *)pso_system_card_filename, (void *)system_save_file_buffer);
        stop_pad_rumble();
        for (;;) {
            if (poll_memcard_result(system_save_card_channel) == 0) break;
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        lbl_805D49B4 = 0;
        memcpy(buf, (void*)(system_save_file_buffer + 0x2048), 0x11C);
        sum = *buf;
        if (((TAdSinglePlyChrSelectGC *)buf)->fields_equal((void *)system_save_payload) == 0) {
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

s32 TAdSinglePlyChrSelectGC::poll_memcard_status() { return TAdSinglePlyChrSelectGC::verify_system_file(this); }


s32 TAdSinglePlyChrSelectGC::has_valid_slot() {
    Slot_801FCB04*arg0 = (Slot_801FCB04*)this;
    s32 i;
    if (arg0 != NULL) {
        for (i = 0; i < 7; i++) {
            u32 m = arg0[i].magic;
            if (m != 0 && m != 0xA205B064) {
                return 1;
            }
        }
    }
    return 0;
}

void load_tables(int a0) { TAdSinglePlyChrSelectGC__selection_index = a0; memcpy((void*)selected_character_data, (void*)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), 0x41C); memcpy((void*)active_character_save_record, (void*)TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), 0x2370); game_state_load(); }

}



extern "C" {
void TAdSinglePlyChrSelectGC__sub_801FCCB4(u8 *arg0, s32 arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FCCC0(u8 *arg0);
s32 __ct__12TPlyCharDataFv(s32);
void alloc_char_records__23TAdSinglePlyChrSelectGCFi(saddr arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void);
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void);
int TAdSinglePlyChrSelectGC__sub_801FD990(s32 a0);
s32 is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(CharacterFile *self, s32 i);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void free_char_data_slots__23TAdSinglePlyChrSelectGCFPv(Obj_801FCBA0* arg0);
int init_new_character_data(void *p);
void init_fresh_character_slot(s32 arg0);
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(A_801FD8B8 *a, A_801FD8B8 *b, C_801FD8B8 *c, C_801FD8B8 *d);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
extern s32 lbl_805D55C0;
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void);
s32 fn_80203284();
s32 TAdSinglePlyChrSelectGC__sub_8028DC14();
s32 pso_system_load_gc(void);
s32 setup__23TAdSinglePlyChrSelectGCFi(int a0);
s32 try_confirm_selection__23TAdSinglePlyChrSelectGCFv();

void free_char_data_slots__23TAdSinglePlyChrSelectGCFPv(Obj_801FCBA0* arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->a[i] != NULL) {
            __dt__12TPlyCharDataFv((saddr)arg0->a[i], 1);
        }
        if (arg0->b[i] != NULL) {
            ::operator delete(arg0->b[i]);
        }
        arg0->a[i] = NULL;
        arg0->b[i] = NULL;
    }
}

void alloc_char_records__23TAdSinglePlyChrSelectGCFi(saddr arg0) {
  s32 var_r0;
  s32 temp_r3;
  s32 var_r0_2;
  s32 var_r31;
  u8 *temp_r30;
  s32 var_r29;
  var_r29 = 0;
  var_r31 = 0;
  do
  {
    temp_r3 = (saddr)::operator new(0x41C);
    var_r0 = temp_r3;
    temp_r30 += 0;
    if (var_r0 != 0)
    {
      var_r0 = __ct__12TPlyCharDataFv(temp_r3);
    }
    temp_r30 = (u8 *) (arg0 + var_r31);
    *((s32 *) (((s8 *) temp_r30) + 0)) = var_r0;
    var_r0_2 = (saddr)new CharacterSaveRecord;
    *((s32 *) (((s8 *) temp_r30) + 0x10)) = var_r0_2;
    memset(*(void **)temp_r30, 0, 0x41C);
    memset(*(void **)(temp_r30 + 0x10), 0, 0x2370);
    var_r29 += 1;
    var_r31 += 4;
  }
  while (var_r29 < 4);
}

void TAdSinglePlyChrSelectGC__sub_801FCCB4(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x11568) = arg1;
}

s32 TAdSinglePlyChrSelectGC__sub_801FCCC0(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x11568);
}

}

void TAdSinglePlyChrSelectGC::set_id(void* p, int v) { *(s32*)((char*)p + 0x0) = v; }


s32 TAdSinglePlyChrSelectGC::get_type(void* p) { return *(s32*)((char*)p + 0x0); }

extern "C" {

s32 is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(CharacterFile *self, s32 i) {
    if (i >= 7) return 0;
    return self->slots[i].record.pad_4 ? 1 : 0;
}

CharacterFileSlot *TAdSinglePlyChrSelectGC__sub_801FCD04(CharacterFile *self) {
    return &self->slots[TAdSinglePlyChrSelectGC::get_selection()];
}


CharacterSaveRecord *TAdSinglePlyChrSelectGC__sub_801FCD3C(CharacterFile *self) {
    return &self->slots[TAdSinglePlyChrSelectGC::get_selection()].record;
}

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


s32 TAdSinglePlyChrSelectGC::forward_to_global_instance(int arg0) {
    if ((void *) selected_character_data != NULL) {
        ((TAdSinglePlyChrSelectGC *)selected_character_data)->append_inventory_item(arg0);
        return 1;
    }
    return 0;
}

extern "C" {

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
    if (selected_character_data != NULL && active_character_save_record != 0 && card_character_save_buffer != NULL) {
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
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
                }
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
        file = new CharacterFile;
        memset(file, 0, 0x1156C);
        memcpy(file, buf + 0x2048, 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(file);
        ret = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(
            (A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C(file),
            (A_801FD8B8 *)get_character_save_record(0xFFFF),
            (C_801FD8B8 *)file,
            (C_801FD8B8 *)TAdSinglePlyChrSelectGC::get_instance());
        if (ret != 7) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
            }
            if (file != NULL) {
                delete file;
            }
            TLobby::disconnect_protocol();
            return ret;
        }
        memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer),
               TAdSinglePlyChrSelectGC__sub_801FCD04(file), 0x41C);
        if (buf != 0) {
            TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
        }
        if (file != NULL) {
            delete file;
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = poll_memcard_result(character_save_card_slot)) == 0) {
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (void *)active_character_save_record, 0x2370);
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            while (TAdSinglePlyChrSelectGC__sub_801FDA4C() != 0) {
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
    if (selected_character_data != NULL && active_character_save_record != 0 && card_character_save_buffer != NULL) {
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
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
        file = new CharacterFile;
        memset(file, 0, 0x1156C);
        memcpy(file, buf + 0x2048, 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(file);
        ret = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(
            (A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C(file),
            (A_801FD8B8 *)get_character_save_record(0xFFFF),
            (C_801FD8B8 *)file,
            (C_801FD8B8 *)TAdSinglePlyChrSelectGC::get_instance());
        if (ret != 7) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
            }
            if (file != NULL) {
                delete file;
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return ret;
        }
        if (((CharacterSaveRecord *)active_character_save_record)->pad_14 != TAdSinglePlyChrSelectGC__sub_801FCD3C(file)->pad_14) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
            TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
        }
        if (file != NULL) {
            delete file;
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = poll_memcard_result(character_save_card_slot)) == 0) {
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), (void *)selected_character_data, 0x41C);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (void *)active_character_save_record, 0x2370);
            *(s32 *)((s8 *)(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer)) + 0x36C) = 0;
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            ret = TAdSinglePlyChrSelectGC__sub_801FDA4C();
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
            v = ((Ent_801FD668 *)card_character_save_buffer)[i].f428;
            if (v != 0 && v + 0x5DFB0000 != 0xB064) return 0;
        }
    }
    return 1;
}


void TAdSinglePlyChrSelectGC::refresh_char_slots() {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (((Ent_801FD6B4 *)card_character_save_buffer)[i].f428 == 0xA205B064) {
            if (((Ent_801FD6B4 *)card_character_save_buffer)[i].f2790 == 0) {
                init_fresh_character_slot(i);
            } else {
                ((TAdSinglePlyChrSelectGC *)(((Ent_801FD6B4 *)card_character_save_buffer)[i].sub))->init_char_slot_record();
            }
        }
    }
}

extern "C" {

void init_fresh_character_slot(s32 arg0) {
    init_new_character_data((*(Ent_801FD728 * *)&card_character_save_buffer)[arg0].a);
    ((TAdSinglePlyChrSelectGC *)((*(Ent_801FD728 * *)&card_character_save_buffer)[arg0].b))->init_char_slot_record();
}
}

s32 check_slot_a_card_save(void) {
    u64 serial_number;
    s32 i;
    if (card_character_save_buffer == 0) return 0;
    if (TAdSinglePlyChrSelectGC::init_and_register((saddr)card_character_save_buffer) == 0) return 1;
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
    if (TAdSinglePlyChrSelectGC::init_and_register((saddr)p) == 0) return 1;
    TAdPlayerLoadGC::reset_load_state(1, &serial_number);
    for (i = 0; i < 8; i++) {
        u8 b = ((u8 *)&serial_number)[i];
        u8 a = ((u8 *)secondary_card_system_save_payload)[i + 0x110];
        if (a != b) return 1;
    }
    if (((TAdSinglePlyChrSelectGC *)secondary_card_character_save_buffer)->has_valid_slot() != 0) return 5;
    return 7;
}

extern "C" {
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(A_801FD8B8 *a, A_801FD8B8 *b, C_801FD8B8 *c, C_801FD8B8 *d) {
    if (a == NULL || b == NULL) return 0;
    if (a->f14 > b->f14) return 2;
    if (a->f4 != b->f4) return 4;
    if (a->f8 != 0xA205B064 || b->f8 != 0xA205B064) return 5;
    return c->f11564 != d->f11564 ? 6 : 7;
}

s32 setup__23TAdSinglePlyChrSelectGCFi(int a0) { card_load_channel = a0; TAdSinglePlyChrSelectGC::set_quest_download_server((int)a0); lbl_805D49B4 = 1; return TAdSinglePlyChrSelectGC::draw_window_bg((saddr)card_load_channel, (saddr)pso_guildcard_card_filename.filename, (saddr)guild_card_save_file_buffer, (saddr)guild_card_save_file_block_count); }


int TAdSinglePlyChrSelectGC__sub_801FD990(s32 a0) {
    system_save_card_channel = a0;
    lbl_805D49B4 = 1;
    return TAdSinglePlyChrSelectGC::draw_window_bg((s32)a0, (saddr)&pso_system_card_filename, (s32)system_save_file_buffer, (s32)system_save_file_block_count);
}

s32 pso_system_load_gc(void) {
    s32 card_file;

    card_file = 0xFFFF0000;
    if (((u32) system_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        card_file = TAdPlayerLoadGC::find_card_file(system_save_card_channel, (const char *)pso_system_card_filename);
        if (card_file == 0) {
            if (try_confirm_selection__23TAdSinglePlyChrSelectGCFv() != 0) {
                card_file = TAdSinglePlyChrSelectGC__sub_801FD990(system_save_card_channel);
                if (card_file == 0) {
                    TAdSinglePlyChrSelectGC::set_player_index(0xF);
                }
            }
        }
    }
    return card_file;
}
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void) {
    s32 var_r0;
    s8 chr_select_state;
    chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
    var_r0 = -1;
    character_save_card_slot = (s32) chr_select_state;
    if (chr_select_state < 2) {
        TAdSinglePlyChrSelectGC::set_quest_download_server((int)((int) ((s32) chr_select_state)));
        (*(s32 *)&lbl_805D49B4) = 1;
        var_r0 = ((s32)TAdSinglePlyChrSelectGC::draw_window_bg((s32)character_save_card_slot, (s32)((saddr)pso_character_card_filename.filename), (s32)character_save_file_buffer, (s32)character_save_file_block_count));
    }
    return var_r0;
}
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void) {
    s32 var_r4;
    s8 chr_select_state;
    chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
    var_r4 = -1;
    character_save_card_slot = (s32) chr_select_state;
    if (chr_select_state < 2) {
        TAdSinglePlyChrSelectGC::set_quest_download_server((int) ((s32) chr_select_state));
        (*(s32 *)&lbl_805D49B4) = 1;
        var_r4 = ((s32)TAdSinglePlyChrSelectGC::draw_window_bg((s32)character_save_card_slot, (s32)((saddr)pso_character_card_filename.filename), (s32)character_save_file_buffer, (s32)character_save_file_block_count));
    }
    card_load_sequence_state = 0x13;
    return var_r4;
}

}





struct Ent_801FE2D0 { u8 pad[0x2790]; s32 a; s32 b; };

struct Ent_801FE304 { u8 pad[0x2790]; s32 a; s32 b; };

struct P_801FE380 { u8 pad[4]; u8 a[0x278C - 4]; s32 f278C; s32 f2790; s32 f2794; };

struct Item_801FDEE4 { u8 pad[0x18]; };

struct Slot_801FDEE4 {
    u8 pad0[4];
    u8 chr[0x370 - 4];
    s32 f370;
    u8 pad374[0x668 - 0x374];
    s32 f668;
    s32 f66C;
    Item_801FDEE4 items[200];
    u8 pad1930[0x2790 - 0x1930];
    s32 f2790;
    s32 f2794;
};

struct DateStamp_801FDEE4 { u8 pad[0xC]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct B1C_801FE010 { u32 w[7]; };

struct B10_801FE010 { u32 w[4]; };

struct B200_801FE010 { u32 w[0x80]; };

struct I18_801FE010 { u8 b[0x18]; };

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
    I18_801FE010 items[200];
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

struct E_801FDDAC { u8 pad[0x424]; u32 f424; u8 pad2[0x2790 - 0x428]; s32 f2790; s32 f2794; };

struct E_801FDE14 { u8 pad[0x424]; u32 f424; u8 pad2[0x2794 - 0x428]; u32 f2794; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct S_801FE010;
struct B8_801FDFB8 { u32 w[2]; };

struct P_801FDFB8 { u8 pad[0x41C]; u8 a[0x278C - 0x41C]; B8_801FDFB8 f278C; s32 f2794; };

typedef struct Ent_801FE338 {
    u32 f0;
    u8 body[0x2794];
} Ent_801FE338;

extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_801FDC14(s32);
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 arg0);
void clear_entry__23TAdSinglePlyChrSelectGCFi(s32 i);
s32 TAdSinglePlyChrSelectGC__sub_801FE380(P_801FE380 *arg0, s32 arg1, P_801FE380 *arg2, s32 arg3);
saddr TAdSinglePlyChrSelectGC__sub_80076D9C(saddr arg0, saddr arg1);
S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *arg0, S_801FE010 *arg1);
s32 check_slot_swap_allowed__23TAdSinglePlyChrSelectGCFPviPvi(E_801FDDAC *arg0, s32 arg1, E_801FDDAC *arg2, s32 arg3);
s32 is_same_slot_entry__23TAdSinglePlyChrSelectGCFPviPvi(E_801FDE14 *arg0, s32 arg1, E_801FDE14 *arg2, s32 arg3);
void copy_player_data__9TProtocolFPvPv();
S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *arg0, S_801FE010 *arg1);
void *memset(void *, int, unsigned long);
s32 swap_characters__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 try_move_char__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);

}

void TAdSinglePlyChrSelectGC::open_confirm_window() { lbl_805D49B4 = 1; TAdSinglePlyChrSelectGC::draw_window_bg((saddr)1, (saddr)pso_character_card_filename.filename, (saddr)character_save_file_buffer, (saddr)character_save_file_block_count); card_load_sequence_state = 18; }


s32 TAdSinglePlyChrSelectGC::load_pso_system(int chan) {
    s32 r = -1;
    system_save_card_channel = chan;
    if (chan >= 0 && chan <= 7) {
        r = TAdPlayerLoadGC::find_card_file(chan, (const char *)&pso_system_card_filename);
        if (r == 0) {
            (*(s32 *)&lbl_805D49B4) = 1;
            r = ((s32)TAdSinglePlyChrSelectGC::load_player_slot(system_save_card_channel, (const char *)&pso_system_card_filename, (void *)(*(saddr *)&system_save_file_buffer)));
        }
    }
    return r;
}


s32 TAdSinglePlyChrSelectGC::load_pso_system_slot() {
    s32 r = TAdPlayerLoadGC::find_card_file(1, pso_system_card_filename);
    if (r == 0) {
        lbl_805D49B4 = 1;
        r = TAdSinglePlyChrSelectGC::load_player_slot(1, pso_system_card_filename, (void *)system_save_file_buffer);
    }
    return r;
}

extern "C" {

s32 TAdSinglePlyChrSelectGC__sub_801FDC14(s32) {
    s32 r = TAdPlayerLoadGC::find_card_file(1, pso_character_card_filename.filename);
    if (r == 0) {
        lbl_805D49B4 = 1;
        r = TAdSinglePlyChrSelectGC::load_player_slot(1, pso_character_card_filename.filename, (void *)character_save_file_buffer);
    }
    return r;
}

s32 swap_characters__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 i) {
    s32 result;
    if ((arg0 >= 7) || (i >= 7)) {
        return 0;
    }
    if (card_character_save_buffer == NULL) {
        goto return_zero;
    }
    if (secondary_card_character_save_buffer == NULL) {
        goto return_zero;
    }
    if (TAdSinglePlyChrSelectGC::check_page_cross(secondary_card_character_save_buffer, arg0, card_character_save_buffer, i) == 0) {
        goto return_zero;
    }
    TAdSinglePlyChrSelectGC::increment_counters();
    TAdSinglePlyChrSelectGC__sub_801FE380((P_801FE380 *)(secondary_card_character_save_buffer), arg0, (P_801FE380 *)(card_character_save_buffer), i);
    return 1;
return_zero:
    return 0;
}


s32 try_move_char__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1) {
    if ((arg0 >= 7) || (arg1 >= 7)) {
        return 0;
    }
    if (arg1 > 3) {
        return 0;
    }
    if (arg0 <= 3) {
        return 0;
    }
    if ((card_character_save_buffer != 0U) && (secondary_card_character_save_buffer != 0U) && (TAdSinglePlyChrSelectGC::check_page_cross(card_character_save_buffer, arg0, secondary_card_character_save_buffer, arg1) != 0)) {
        TAdSinglePlyChrSelectGC::increment_counters();
        TAdSinglePlyChrSelectGC::copy_character_to_slot(card_character_save_buffer, arg0, secondary_card_character_save_buffer, arg1);
        return 1;
    }
    return 0;
}

s32 check_slot_swap_allowed__23TAdSinglePlyChrSelectGCFPviPvi(E_801FDDAC *arg0, s32 arg1, E_801FDDAC *arg2, s32 arg3) {
    E_801FDDAC *e;
    if (arg1 < 4) {
        return 0;
    }
    if (arg0[arg1].f424 != 0U) {
        return 0;
    }
    if (arg3 >= 4) {
        return 0;
    }
    e = &arg2[arg3];
    if (e->f424 == 0U) {
        return 0;
    }
    return (u32)__cntlzw(e->f2790) >> 5;
}

s32 is_same_slot_entry__23TAdSinglePlyChrSelectGCFPviPvi(E_801FDE14 *arg0, s32 arg1, E_801FDE14 *arg2, s32 arg3) {
    E_801FDE14 *b;
    E_801FDE14 *a;
    u32 vb;
    u32 va;
    u32 kb;
    if (arg3 <= 3) {
        return 0;
    }
    b = &arg2[arg3];
    vb = b->f424;
    if (vb == 0) {
        return 0;
    }
    kb = b->f2794;
    if (arg1 > 3) {
        return 0;
    }
    a = &arg0[arg1];
    va = a->f424;
    if (va == 0) {
        return 0;
    }
    if (a->f2794 != kb) {
        return 0;
    }
    return (u32)__cntlzw(vb - va) >> 5;
}

}

s32 TAdSinglePlyChrSelectGC::check_page_cross(CharacterFile *arg1, int arg2, CharacterFile *arg3, int arg4) {
    if ((arg2 >= 4) && (arg4 <= 3)) {
        return check_slot_swap_allowed__23TAdSinglePlyChrSelectGCFPviPvi((E_801FDDAC *)arg1, arg2, (E_801FDDAC *)arg3, arg4);
    }
    if ((arg2 <= 3) && (arg4 >= 4)) {
        return is_same_slot_entry__23TAdSinglePlyChrSelectGCFPviPvi((E_801FDE14 *)arg1, arg2, (E_801FDE14 *)arg3, arg4);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::copy_character_to_slot(CharacterFile *arg0, int arg1, CharacterFile *arg2, int arg3) {
    s32 secs;
    DateStamp_801FDEE4 ds;
    Slot_801FDEE4 *src = (Slot_801FDEE4 *)arg0;
    Slot_801FDEE4 *dst = (Slot_801FDEE4 *)arg2;
    void *chr;
    s32 i;
    s32 j;
    getDateStamp((DateStamp *)&ds);
    DateToSeconds((DateStamp *)&ds, (int *)&secs);
    dst[arg3].f2794 = secs;
    chr = dst[arg3].chr;
    TAdSinglePlyChrSelectGC::copy_char_slot_data(src[arg1].chr, chr);
    for (i = 0; i < 30; i++) {
        ((TAdSinglePlyChrSelectGC *)(saddr)TAdSinglePlyChrSelectGC__sub_80202B1C((saddr)chr, i))->clear_inventory_slot();
    }
    dst[arg3].f370 = 0;
    dst[arg3].f668 = 0;
    dst[arg3].f66C = 0;
    for (j = 0; j < 200; j++) {
        ((TAdSinglePlyChrSelectGC *)(&dst[arg3].items[j]))->init_item_entry();
    }
    dst[arg3].f2790 = 1;
    return 1;
}

extern "C" {

#define arg0 ((P_801FDFB8 *)a0)
#define arg1 ((P_801FDFB8 *)a1)
}

void *TAdSinglePlyChrSelectGC::copy_char_slot_data(void * a0, void * a1) {
    copy_player_data__9TProtocolFPvPv();
    assign_char_data__23TAdSinglePlyChrSelectGCFPvPv((S_801FE010 *)arg0->a, (S_801FE010 *)arg1->a);
    arg0->f278C = arg1->f278C;
    arg0->f2794 = arg1->f2794;
    return a0;
}

extern "C" {
#undef arg0
#undef arg1

S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *arg0, S_801FE010 *arg1) {
    I18_801FE010 *p;
    I18_801FE010 *q;
    I54_801FE010 *s;
    I54_801FE010 *t;
    arg0->a0 = arg1->a0;
    arg0->a4 = arg1->a4;
    arg0->a8 = arg1->a8;
    arg0->aC = arg1->aC;
    arg0->a10 = arg1->a10;
    arg0->a14 = arg1->a14;
    arg0->b18 = arg1->b18;
    arg0->b34 = arg1->b34;
    arg0->b44 = arg1->b44;
    arg0->c244 = arg1->c244;
    arg0->c248 = arg1->c248;
    arg0->c24C = arg1->c24C;
    p = arg0->items;
    q = arg1->items;
    do {
        ((TAdSinglePlyChrSelectGC *)p)->copy_item_data(q);
        p++;
        q++;
    } while (p < arg0->items + 200);
    arg0->d1510 = arg1->d1510;
    arg0->d15A0 = arg1->d15A0;
    s = arg0->slots;
    t = arg1->slots;
    do {
        TAdSinglePlyChrSelectGC__sub_80076D9C((saddr)s, (saddr)t);
        s++;
        t++;
    } while (s < arg0->slots + 20);
    arg0->e2050 = arg1->e2050;
    arg0->e20FC = arg1->e20FC;
    arg0->e21A8 = arg1->e21A8;
    arg0->e21C4 = arg1->e21C4;
    arg0->e22C4 = arg1->e22C4;
    arg0->e22EC = arg1->e22EC;
    arg0->e2314 = arg1->e2314;
    arg0->e2354 = arg1->e2354;
    return arg0;
}

void clear_entry__23TAdSinglePlyChrSelectGCFi(s32 i) {
    if ((*(Ent_801FE2D0 * *)&card_character_save_buffer) == 0) return;
    if (i >= 4) return;
    (*(Ent_801FE2D0 * *)&card_character_save_buffer)[i].a = 0;
    (*(Ent_801FE2D0 * *)&card_character_save_buffer)[i].b = 0;
}

}

void TAdSinglePlyChrSelectGC::clear_slot_entry(int i) {
    if ((*(Ent_801FE304 * *)&secondary_card_character_save_buffer) == 0) return;
    if (i >= 4) return;
    (*(Ent_801FE304 * *)&secondary_card_character_save_buffer)[i].a = 0;
    (*(Ent_801FE304 * *)&secondary_card_character_save_buffer)[i].b = 0;
}


void TAdSinglePlyChrSelectGC::clear_slot_body(int i) {
    if ((*(Ent_801FE338 **)&card_character_save_buffer) == 0) return;
    if (i < 4) return;
    memset((*(Ent_801FE338 **)&card_character_save_buffer)[i].body, 0, 0x2798);
}

extern "C" {

s32 TAdSinglePlyChrSelectGC__sub_801FE380(P_801FE380 *arg0, s32 arg1, P_801FE380 *arg2, s32 i) {
    arg2[i].f2790 = 0;
    arg2[i].f2794 = 0;
    TAdSinglePlyChrSelectGC::copy_char_slot_data(arg0[arg1].a, arg2[i].a);
    TAdSinglePlyChrSelectGC::clear_slot_body(i);
    return 1;
}

s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i) {
    u8 *temp_r4;
    if (i >= 7U) {
        return NULL;
    }
    if (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(secondary_card_character_save_buffer, i) == 0) {
        return NULL;
    }
    temp_r4 = (u8 *)((*(saddr *)&secondary_card_character_save_buffer) + (i * 0x2798));
    lbl_805137C8[0] = (saddr)(temp_r4 + 0x374);
    lbl_805137C8[1] = (s32) *(s32 *)((s8 *)temp_r4 + 0x368);
    lbl_805137C8[2] = (s32) *(s32 *)((s8 *)temp_r4 + 0x2790);
    lbl_805137C8[3] = (s32) *(s32 *)((s8 *)temp_r4 + 0x42C);
    return lbl_805137C8;
}

}




struct Slot_801FE5F8 {
    u8 pad0[4];
    u8 chr[0x41C];
    u8 inv[0x2370];
    u8 tail[8];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 arg0);
s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 arg0);


struct Ent_801FE468_801FBF54 { char pad4[4]; char body[0x2798 - 4]; };

int get_split_screen_character_save_record(int a0);
s32 get_entry__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
s32 load_guild_card_save(void);
s32 poll_memcard_result(saddr);
extern s32 lbl_805D49B4;
s32 check_ready__23TAdSinglePlyChrSelectGCFv();


s32 get_entry__23TAdSinglePlyChrSelectGCFi(s32 i) {
    if (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(secondary_card_character_save_buffer, i) != 0) {
        return (saddr) &((struct Ent_801FE468_801FBF54 *) secondary_card_character_save_buffer)[i].body[0];
    }
    return 0;
}


s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 i) {
    u8 *temp_r4;
    if (i >= 7U) {
        return NULL;
    }
    if (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(card_character_save_buffer, (s32)i) == 0) {
        return NULL;
    }
    temp_r4 = (u8 *)((*(saddr *)&card_character_save_buffer) + (i * 0x2798));
    lbl_805137C8[0] = (saddr)(temp_r4 + 0x374);
    lbl_805137C8[1] = (s32) *(s32 *)((s8 *)temp_r4 + 0x368);
    lbl_805137C8[2] = (s32) *(s32 *)((s8 *)temp_r4 + 0x2790);
    return lbl_805137C8;
}

}

void TAdSinglePlyChrSelectGC::copy_chr_slots_from_request() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (chr_select_request_buffer.card_slots[i] < 7 && chr_select_request_buffer.card_slots[i] >= 0) {
            memcpy(((Slot_801FE5F8 *)card_character_save_buffer)[chr_select_request_buffer.card_slots[i]].chr, (void *)chr_select_buffer_ptr_table[chr_select_request_buffer.player_ids[i]], 0x41C);
            memcpy(((Slot_801FE5F8 *)card_character_save_buffer)[chr_select_request_buffer.card_slots[i]].inv, (void *)chr_select_buffer_ptr_table[chr_select_request_buffer.player_ids[i] + 4], 0x2370);
        }
    }
}

extern "C" {

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
                memcpy((void *)chr_select_buffer_ptr_table[request->player_ids[i]], ((Slot_801FE5F8 *)card_character_save_buffer)[request->card_slots[i]].chr, 0x41C);
                memcpy((void *)chr_select_buffer_ptr_table[request->player_ids[i] + 4], ((Slot_801FE5F8 *)card_character_save_buffer)[request->card_slots[i]].inv, 0x2370);
            }
        }
    }
}

void copy_character_selection_request(CharacterSelectionRequest *destination, const CharacterSelectionRequest *source) {
    *destination = *source;
}

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
            lbl_805D49B4 = 1;
            card_file = TAdSinglePlyChrSelectGC::load_player_slot(character_save_card_slot, pso_character_card_filename.filename, (void *)character_save_file_buffer);
        }
    }
    return card_file;
}

extern "C" {

int get_split_screen_character_save_record(int a0) {  return chr_select_buffer_ptr_table[a0 + 4]; }

TPlyCharData *TAdSinglePlyChrSelectGC::get_char_table_entry(int index) {  return (TPlyCharData *)chr_select_buffer_ptr_table[index]; }


s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i) {
    if (i >= 7U) {
        return 0;
    }
    if ((secondary_card_character_save_buffer != NULL) && (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(secondary_card_character_save_buffer, (s32) i) != 0)) {
        return 1;
    }
    return 0;
}

s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi(u32 arg0) {
    u32 i = arg0;
    CharacterFile *var_r3;
    if (i >= 7U) {
        return 0;
    }
    var_r3 = card_character_save_buffer;
    if ((var_r3 != 0U) && (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(var_r3, i) != 0)) {
        return 1;
    }
    return 0;
}


}

s32 TAdSinglePlyChrSelectGC::load_player_data() {
    s32 card_file;

    card_file = 0xFFFF0000;
    if (((u32) guild_card_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0) && (TAdPlayerLoadGC::probe_and_check_card(card_load_channel) != 0)) {
        card_file = TAdPlayerLoadGC::find_card_file(card_load_channel, pso_guildcard_card_filename.filename);
        if ((card_file == 0) && (check_ready__23TAdSinglePlyChrSelectGCFv() != 0)) {
            card_file = setup__23TAdSinglePlyChrSelectGCFi(card_load_channel);
            if (card_file == 0) {
                TAdSinglePlyChrSelectGC::set_player_index(0xC);
            }
        }
    }
    return card_file;
}

extern "C" {


s32 load_guild_card_save(void) {
    s32 card_file;
    s32 var_r3;
    s8 chr_select_state;

    TAdSinglePlyChrSelectGC::set_save_slot(0);
    card_file = 0xFFFF0000;
    if (((u32) guild_card_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        chr_select_state = TAdSinglePlyChrSelectGC::get_chr_select_state();
        card_load_channel = chr_select_state;
        card_file = poll_memcard_result(card_load_channel);
        if (card_file == 0) {
            card_file = TAdPlayerLoadGC::find_card_file(card_load_channel, pso_guildcard_card_filename.filename);
            if (card_file == 0) {
                var_r3 = TAdSinglePlyChrSelectGC::load_player_by_slot(card_load_channel);
                if (var_r3 == 0) {
                    card_load_sequence_state = 0xD;
                }
                return var_r3;
            }
        }
    }
    return card_file;
}

}



extern "C" {

s32 load_pso_system(void);
s32 load_system_file(s32 arg0);
s32 poll_memcard_result(saddr);


s32 load_system_file(s32 arg0) {
    s32 card_file;
    s32 var_r3;
    s32 chr_select_state;

    card_file = 0xFFFF0000;
    if (((u32) system_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        chr_select_state = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
        system_save_card_channel = chr_select_state;
        card_file = poll_memcard_result(chr_select_state);
        if (card_file == 0) {
            card_file = TAdPlayerLoadGC::find_card_file(system_save_card_channel, (const char *)pso_system_card_filename);
            if (card_file == 0) {
                var_r3 = TAdSinglePlyChrSelectGC::load_pso_system(system_save_card_channel);
                if (var_r3 == 0) {
                    if (arg0 != 0) {
                        card_load_sequence_state = 0x11;
                    } else {
                        card_load_sequence_state = 0x10;
                    }
                }
                return var_r3;
            }
        }
    }
    var_r3 = card_file;
    return var_r3;
}


s32 load_pso_system(void) {
    s32 card_file;
    s32 var_r3;

    card_file = 0xFFFF0000;
    if (((u32) secondary_card_system_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        card_file = poll_memcard_result(1);
        if (card_file == 0) {
            card_file = TAdPlayerLoadGC::find_card_file(1, (const char *)pso_system_card_filename);
            if (card_file == 0) {
                var_r3 = TAdSinglePlyChrSelectGC::load_pso_system_slot();
                if (var_r3 == 0) {
                    card_load_sequence_state = 0x16;
                }
                return var_r3;
            }
        }
    }
    var_r3 = card_file;
    return var_r3;
}

}



struct RecoveredGlobal_801FEBBC_lbl_80513904 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s32 poll_memcard_result(saddr);
s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void);
s32 load_pso_system(void);
void check_system_load_result__23TAdSinglePlyChrSelectGCFv(void);
s32 check_ready__23TAdSinglePlyChrSelectGCFv(void);
s32 try_confirm_selection__23TAdSinglePlyChrSelectGCFv(void);
void TAdSinglePlyChrSelectGC__sub_801FFF14(void);


s32 check_ready__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r3;

    stop_pad_rumble();
    var_r3 = 0;
    if (((u32) guild_card_save_payload != 0U) && ((u32) guild_card_save_file_buffer != 0U)) {
        TAdSinglePlyChrSelectGC__sub_801FFF14();
        var_r3 = 1;
    }
    return var_r3;
}


s32 try_confirm_selection__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r3;

    stop_pad_rumble();
    var_r3 = 0;
    if (((u32) system_save_payload != 0U) && ((u32) system_save_file_buffer != 0U)) {
        TAdSinglePlyChrSelectGC::create_instance();
        var_r3 = 1;
    }
    return var_r3;
}
LAYOUT_ASSERT(RecoveredGlobal_801FEBBC_lbl_80513904_size, sizeof(RecoveredGlobal_801FEBBC_lbl_80513904) == 0xC);

void check_system_load_result__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = load_pso_system();
    card_load_followup_pending = 0;
    if (r == 0) card_load_followup_pending = 1;
}

s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void) {
    s32 var_r31;
    var_r31 = 0xFFFF0000;
    if ((secondary_card_character_save_buffer != NULL) && (TAdPlayerLoadGC::get_instance() == 0x16)) {
        var_r31 = poll_memcard_result(1);
        if (var_r31 == 0) {
            var_r31 = TAdSinglePlyChrSelectGC__sub_801FDC14(1);
            if (var_r31 == 0) {
                card_load_sequence_state = 0x14;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return var_r31;
}

}




extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
saddr get_localized_text_entry(s32, s32);
s8 func_801A5E54__Fv(void);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
void TLobby__sub_80269C90(void);
void TLobby__sub_80269CA4(s32);
void func_803DCDFC__Fv(void);
s32 start_load__23TAdSinglePlyChrSelectGCFv(void);
s32 poll_memcard_result(saddr);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();


}

s32 TAdSinglePlyChrSelectGC::load_selected_char() {
    s32 var_r31;

    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    var_r31 = 0xFFFF0000;
    if ((selected_character_data != NULL) && (active_character_save_record != 0) && (card_character_save_buffer != 0) && (TAdPlayerLoadGC::get_instance() == 0x10) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        var_r31 = poll_memcard_result(character_save_card_slot);
        if (var_r31 == 0) {
            var_r31 = TAdSinglePlyChrSelectGC::load_chr_select_slot();
            if (var_r31 == 0) {
                card_load_sequence_state = 8;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return var_r31;
}


s32 TAdSinglePlyChrSelectGC::load_selected_character() {
    s32 var_r31;

    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    var_r31 = 0xFFFF0000;
    if ((selected_character_data != NULL) && (active_character_save_record != 0) && (card_character_save_buffer != 0) && (TAdPlayerLoadGC::get_instance() == 0) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        var_r31 = poll_memcard_result(character_save_card_slot);
        if (var_r31 == 0) {
            var_r31 = TAdSinglePlyChrSelectGC::load_chr_select_slot();
            if (var_r31 == 0) {
                card_load_sequence_state = 8;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return var_r31;
}

extern "C" {

s32 init_buffer();

s32 start_load__23TAdSinglePlyChrSelectGCFv(void) {
    character_save_card_slot = (s32) (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    if ((selected_character_data != NULL) && (active_character_save_record != 0) && (card_character_save_buffer != 0) && (TAdPlayerLoadGC::get_instance() == 0) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        TAdSinglePlyChrSelectGC::clear_load_buffers();
        init_buffer();
        TAdSinglePlyChrSelectGC::prepare_save_data();
        TAdSinglePlyChrSelectGC__sub_801FDA4C();
        card_load_sequence_state = 6;
        return 7;
    }
    return 0xFFFF0000;
}

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
            func_803DCDFC__Fv();
            check->run_task();
            if (check->is_card_ready() != 0) {
                break;
            }
            controller_stuff();
            TLobby::wait_ready_loop();
            TAdSinglePlyChrSelectGC::render_frame();
            if (func_801A5E54__Fv() != 0 || test_pressed_buttons_packed(&controller_input_state.controllers[0], 8) != 0) {
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
        w = reinterpret_cast<TWindowMessage *>(TWindowMessage::create((saddr)&chr_select_save_message_window_pos, &chr_select_save_message_window_size.x, 1, 4));
        if (w != NULL) {
            w->append_line(get_localized_text_entry(0x20, 4), 3);
            w->reparent_to_main_ctrl();
        }
        w->complete_reveal();
        while (1) {
            func_803DCDFC__Fv();
            controller_stuff();
            TLobby::wait_ready_loop();
            TAdSinglePlyChrSelectGC::render_frame();
            if (func_801A5E54__Fv() != 0) {
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
    v = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = v;
    chr_select_serial_seeds[0] = v;
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
    TAdSinglePlyChrSelectGC__sub_801FDA4C();
    card_load_sequence_state = 6;
    while (1) {
        func_803DCDFC__Fv();
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
    w = reinterpret_cast<TWindowMessage *>(TWindowMessage::create((saddr)&chr_select_save_message_window_pos, &chr_select_save_message_window_size.x, 1, 4));
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
            func_803DCDFC__Fv();
            controller_stuff();
            TLobby::wait_ready_loop();
            TAdSinglePlyChrSelectGC::render_frame();
            if (func_801A5E54__Fv() != 0 || test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x60E) != 0) {
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
    s32 temp_r3;
    temp_r3 = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = temp_r3;
    chr_select_serial_seeds[0] = temp_r3;
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
    if (((s32)TAdSinglePlyChrSelectGC__sub_801FDA4C()) != 0) {
        return 0;
    }
    card_load_sequence_state = 6;
    return 1;
}




extern "C" {
s32 load_system_file(s32);
void load_system_file_flag__23TAdSinglePlyChrSelectGCFv(void);
s32 load_system_file(s32);
u8 load_system_file_blocking__23TAdSinglePlyChrSelectGCFv(void);
u8 load_character_and_wait__23TAdSinglePlyChrSelectGCFv(void);
s32 load_guild_card_save();
s32 load_and_verify_data(s32);
u8 load_player_and_wait__23TAdSinglePlyChrSelectGCFv(void);

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

extern "C" {
void load_system_file_flag__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = load_system_file(0);
    card_load_followup_pending = 0;
    if (r == 0) card_load_followup_pending = 1;
}
u8 load_system_file_blocking__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = load_system_file(1);
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
u8 load_character_and_wait__23TAdSinglePlyChrSelectGCFv(void) {
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
u8 load_player_and_wait__23TAdSinglePlyChrSelectGCFv(void) {
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
u8 *TAdSinglePlyChrSelectGC__sub_801FFC74(u8 *arg0, u8 *arg1);
s32 try_assign_battle_ctrl__10TObjPlayerFiUs(saddr, u16);
u32 get_player_by_client_id(s32);
s32 copy_card__17TWindowSubComCardFiPv(saddr arg0, u8 *arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FFCFC(saddr arg0, saddr arg1);
s32 copy_card_window_data();
void TAdSinglePlyChrSelectGC__sub_801FFF98(void *arg0);

extern s32 local_client_id;

s32 TAdSinglePlyChrSelectGC::init(void) {
    stop_pad_rumble();
    if ((selected_character_data != NULL) && (active_character_save_record != 0) && (card_character_save_buffer != 0)) {
        if ((get_player_by_client_id(local_client_id) != 0U) && (TTecCtrl::is_technique_ready() == 0) && (fn_80203284() != 1)) {
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
  u32 var_r31;
  u8 *character_save_record;
  stop_pad_rumble();
  get_character_select_request_buffer();
  var_r31 = 0;
  do
  {
    if (((get_player_by_client_id((s32)((int) var_r31)) != 0U) && (((volatile long)TTecCtrl::is_technique_ready()) == 0)) && (TLobby__sub_8030A770() == 0))
    {
      char_data = TAdSinglePlyChrSelectGC::get_char_index(var_r31);
      if (char_data != NULL)
      {
        try_assign_battle_ctrl__10TObjPlayerFiUs((saddr) char_data, (u16) var_r31);
      }
      character_save_record = (u8 *) get_character_save_record(var_r31);
      if (character_save_record != 0)
      {
        TAdSinglePlyChrSelectGC::update_elapsed_time(character_save_record);
      }
    }
    TAdSinglePlyChrSelectGC::clear_flags(3);
    var_r31 += 1;
  }
  while (((s32) var_r31) < 4);
  return 0xFFFF0000;
}

void TAdSinglePlyChrSelectGC::clear_load_buffers(void) {
    if (card_character_save_buffer != 0) {
        memset(card_character_save_buffer, 0, 0x1156C);
        memset((void *)selected_character_data, 0, 0x41C);
        memset((void *)active_character_save_record, 0, 0x2370);
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
    if (selected_character_data != 0 && active_character_save_record != 0 && card_character_save_buffer != 0) {
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
                        TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
                        TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
                    }
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                TAdSinglePlyChrSelectGC::render_frame();
                render_tick();
            }
            t = get_field_118__22TAdEnterSerialAccessGCFv();
            chr_select_serial_seeds[1] = t;
            chr_select_serial_seeds[0] = t;
            file = new CharacterFile;
            memset(file, 0, 0x1156C);
            memcpy(file, buf + 0x2048, 0x1156C);
            decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(file);
            ret = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv((A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C(file), (A_801FD8B8 *)get_character_save_record(0xFFFF), (C_801FD8B8 *)file, (C_801FD8B8 *)TAdSinglePlyChrSelectGC::get_instance());
            if (ret != 7) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
                }
                if (file != NULL) {
                    delete file;
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return ret;
            }
            if (((CharacterSaveRecord *)active_character_save_record)->pad_14 != TAdSinglePlyChrSelectGC__sub_801FCD3C(file)->pad_14) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
                TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
                memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), selected_character_data, 0x41C);
                memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (void *)active_character_save_record, 0x2370);
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
                    p = (saddr)((TObjPlayer *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer))->get_ptr_4();
                    for (i = 0; i < 30; i++) {
                        ((TAdSinglePlyChrSelectGC *)p)->clear_inventory_slot();
                        p += 0x1C;
                    }
                    *(u8 *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer) = 0;
                    memset(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer)->bank_items, 0, 0x12C0);
                    TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer)->pad_248 = 0;
                    TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer)->pad_24C = 0;
                }
                *(s32 *)((u8 *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer) + 0x36C) = 0;
                break;
            default:
                copy_card_window_data();
                memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), selected_character_data, 0x41C);
                memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (void *)active_character_save_record, 0x2370);
                break;
            }
            t = get_field_118__22TAdEnterSerialAccessGCFv();
            chr_select_serial_seeds[1] = t;
            chr_select_serial_seeds[0] = t;
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            while (TAdSinglePlyChrSelectGC__sub_801FDA4C() != 0) {
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

s32 load_and_verify_data(s32 arg0) {
    s32 serial;
    u32 *copy;
    u32 sum;

    TAdSinglePlyChrSelectGC::set_save_slot(0);
    serial = get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv();
    chr_select_serial_seeds[1] = serial;
    chr_select_serial_seeds[0] = serial;
    memcpy((void *)guild_card_save_payload, (void *)(guild_card_save_file_buffer + 0x2048), 0xE28C);
    TAdSinglePlyChrSelectGC__sub_801FFF98((void *)guild_card_save_payload);
    copy = (u32 *)::operator new(0xE28C);
    if (copy != NULL) {
        copy = (u32 *)init_windows__23TAdSinglePlyChrSelectGCFi((saddr)copy);
    }
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)copy, (u8 *)guild_card_save_payload);
    sum = *copy;
    *copy = 0U;
    if (sum != calc_crc32_bitwise((u8 *)copy, (u32)(0xE28C))) {
        if (arg0 != 0) {
            ::operator delete(copy);
            return 0;
        }
        init_timestamped_data();
        goto block_9;
    }
    if (arg0 != 0) {
        ::operator delete(copy);
        return 1;
    }
    TAdSinglePlyChrSelectGC::set_save_slot(1);
block_9:
    ::operator delete(copy);
    return 1;
}
u8 *TAdSinglePlyChrSelectGC__sub_801FFC74(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    TAdSinglePlyChrSelectGC__sub_801FFCFC((saddr)(arg0 + 4), (saddr)(arg1 + 4));
    *(ByteBlock_FC0 *)((arg0 + 0xD2C0) + 4) = *(const ByteBlock_FC0 *)((arg1 + 0xD2C0) + 4);
    *(s32 *)((s8 *)arg0 + 0xE284) = (s32) *(s32 *)((s8 *)arg1 + 0xE284);
    *(s32 *)((s8 *)arg0 + 0xE288) = (s32) *(s32 *)((s8 *)arg1 + 0xE288);
    return arg0;
}
typedef struct ByteBlock_C0 ByteBlock_C0;
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
s32 TAdSinglePlyChrSelectGC__sub_801FFCFC(saddr arg0, saddr arg1) {
  u32 end;
  u32 var_r30;
  saddr var_r29;
  *((ByteBlock_C0 *) arg0) = *((const ByteBlock_C0 *) arg1);
  var_r30 = arg0 + 0xC0;
  end = arg0;
  end = end + 0xD2C0;
  var_r29 = arg1 + 0xC0;
  do
  {
    copy_card__17TWindowSubComCardFiPv(var_r30, (u8 *)var_r29);
    var_r30 += 0x100;
    var_r29 += 0x100;
  }
  while (var_r30 < end);
  return arg0;
}

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

struct Str_80200A44 {
    u8 pad0[0x20];
    char title[0x24];
    u8 icon[0x70];
    char name[0x10];
};

extern "C" {
s32 reinit__17TWindowSubComCardFi(s32 arg0);
u8 *construct_card_window_array__23TAdSinglePlyChrSelectGCFPv(u8 *arg0);
s32 init_character_stats_for_level(u8, void *, s32);
void init_class_starting_inventory(void *arg0);
void TLobby__sub_801F494C(u16 arg0);
void TAdSinglePlyChrSelectGC__sub_802000C8(void *arg0_, void *arg1);
s32 init_guild_card_tag__17TWindowSubComCardFi(s32 arg0);

saddr init_windows__23TAdSinglePlyChrSelectGCFi(saddr arg0) {
    construct_card_window_array__23TAdSinglePlyChrSelectGCFPv((u8 *)(arg0 + 4));
    TAdSinglePlyChrSelectGC::construct_card_window_array(arg0 + 0xD2C4);
    return arg0;
}


saddr construct_card_window_array__23TAdSinglePlyChrSelectGCFi(saddr arg0) {
    __construct_array((void *)arg0, (void *)init_guild_card_tag__17TWindowSubComCardFi, 0, 0x90, 0x1C);
    return arg0;
}

u8 *construct_card_window_array__23TAdSinglePlyChrSelectGCFPv(u8 *arg0) {
    __construct_array(arg0 + 0xC0, (void *)reinit__17TWindowSubComCardFi, 0, 0x100, 0xD2);
    return arg0;
}

#pragma push
#pragma fp_contract on
s32 TAdSinglePlyChrSelectGC::verify_save_checksum(int arg0) {
    u32 temp_r31;
    u32 temp_r3;
    memcpy((void *)((*(u32 * *)&system_save_payload)), (void *)(system_save_file_buffer + 0x2048), 0x11C);
    temp_r31 = *(*(u32 * *)&system_save_payload);
    *(*(u32 * *)&system_save_payload) = 0U;
    temp_r3 = ((u32)calc_crc32_bitwise((u8 *)((s32 *)((*(u32 * *)&system_save_payload))), 0x11C));
    if (temp_r3 != temp_r31) {
        if (arg0 == 0) {
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
    memcpy((void *)((void *)secondary_card_system_save_payload), (void *)(system_save_file_buffer + 0x2048), 0x11C);
    sum = *(u32 *)secondary_card_system_save_payload;
    *(u32 *)secondary_card_system_save_payload = 0;
    r = (u32)calc_crc32_bitwise((u8 *)secondary_card_system_save_payload, 0x11C);
    if (r != sum) {
        return;
    }
}

void TAdSinglePlyChrSelectGC__sub_801FFF14(void) {
    s32 temp_r3;
    temp_r3 = get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv();
    chr_select_serial_seeds[1] = temp_r3;
    chr_select_serial_seeds[0] = temp_r3;
    TAdSinglePlyChrSelectGC__sub_802000C8((void *)guild_card_save_payload, chr_select_serial_seeds);
    TAdSinglePlyChrSelectGC::build_save_file();
    TAdSinglePlyChrSelectGC__sub_801FFF98(((void *)guild_card_save_payload));
}

void TAdSinglePlyChrSelectGC::create_instance(void) {
    *(u32 *)system_save_payload = 0;
    *(u32 *)system_save_payload = calc_crc32_bitwise((u8 *)system_save_payload, 0x11C);
    TAdSinglePlyChrSelectGC::build_default_save_file();
}


void TAdSinglePlyChrSelectGC__sub_801FFF98(void *arg0) {
    saddr a;
    saddr b;
    a = (saddr)::operator new(0xE28C);
    if (a != 0) {
        a = init_windows__23TAdSinglePlyChrSelectGCFi(a);
    }
    b = (saddr)::operator new(0xE28C);
    if (b != 0) {
        b = init_windows__23TAdSinglePlyChrSelectGCFi(b);
    }
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)a, (u8 *)arg0);
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)b, (u8 *)arg0);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle((s32 *)&chr_select_rng_state);
    subtractive_rng_unshuffle(&chr_select_rng_state, (const u8 *)a, (u8 *)b, 0xE28C);
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)arg0, (u8 *)b);
    ::operator delete((void *)b);
    ::operator delete((void *)a);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    ((TAdSinglePlyChrSelectGC *)&chr_select_rng_state)->apply_rng_cipher((u32 *)arg0, 0xE28C);
    subtractive_rng_seed(&chr_select_rng_state, *(s32 *)((u8 *)arg0 + 0xE288));
    subtractive_rng_xor_buffer((s32 *)&chr_select_rng_state, (u32 *)arg0, 0xE288);
}

#pragma push
#pragma opt_common_subs off
#define self ((s32 *)arg0_)
void TAdSinglePlyChrSelectGC__sub_802000C8(void *arg0_, void *arg1) {
    saddr a;
    saddr b;
    *(s32 *)((u8 *)self + 0xE288) = subtractive_rng_next((s32 *)&chr_select_rng_state);
    self[0] = 0;
    self[0] = calc_crc32_bitwise((u8 *)self, 0xE28C);
    subtractive_rng_seed(&chr_select_rng_state, *(s32 *)((u8 *)self + 0xE288));
    subtractive_rng_xor_buffer((s32 *)&chr_select_rng_state, (u32 *)self, 0xE288);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    ((TAdSinglePlyChrSelectGC *)&chr_select_rng_state)->apply_rng_cipher((u32 *)self, 0xE28C);
    a = (saddr)::operator new(0xE28C);
    if (a != 0) {
        a = init_windows__23TAdSinglePlyChrSelectGCFi(a);
    }
    b = (saddr)::operator new(0xE28C);
    if (b != 0) {
        b = init_windows__23TAdSinglePlyChrSelectGCFi(b);
    }
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)a, (u8 *)self);
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)b, (u8 *)self);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle((s32 *)&chr_select_rng_state);
    TAdSinglePlyChrSelectGC::permute_save_blocks(&chr_select_rng_state, (const u8*)a, (u8*)b, (u32)0xE28C);
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)self, (u8 *)b);
    ::operator delete((void *)b);
    ::operator delete((void *)a);
}
#undef self
#pragma pop

void game_state_load(void) {
    memcpy((void *)selected_character_data, TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), 0x41C);
    memcpy((void *)active_character_save_record, TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), 0x2370);
    TLobby__sub_801F494C(0);
    if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        if (TAdSinglePlyChrSelectGC::check_flag(1) != 0U) {
            TAdSinglePlyChrSelectGC::reset_character_data();
        } else {
            void *a = (void *)selected_character_data;
            void *b;
            if (((u8) *(u8 *)((s8 *)a + 0) == 0) && ((s32) *(s32 *)((s8 *)a + 0x36C) == 0) && ((b = (void *)active_character_save_record, (s32) *(s32 *)((s8 *)b + 0x248)) == 0) && ((s32) *(s32 *)((s8 *)b + 0x24C) == 0)) {
                init_class_starting_inventory(a);
            }
        }
    }
    *(s8 *)((s8 *)selected_character_data + 3) = (s8) current_language;
}

s32 TAdSinglePlyChrSelectGC::apply_loaded_character(int arg0) {
    s32 r = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = r;
    chr_select_serial_seeds[0] = r;
    memcpy(card_character_save_buffer, (void *)(character_save_file_buffer + 0x2048), 0x1156C);
    decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(card_character_save_buffer);
    if (check_slot_a_card_save() != 7) {
        return 0;
    }
    if (arg0 != 0) {
        return 1;
    }
    memcpy((void *)selected_character_data, TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), 0x41C);
    memcpy((void *)((*(void *const *)&active_character_save_record)), TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), 0x2370);
    TLobby__sub_801F494C(0);
    if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        if (TAdSinglePlyChrSelectGC::check_flag(1) != 0U) {
            TAdSinglePlyChrSelectGC::reset_character_data();
        } else {
            void *a = (void *)selected_character_data;
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
    s32 r = get_serial_result__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = r;
    chr_select_serial_seeds[0] = r;
    memcpy(secondary_card_character_save_buffer, (void *)(character_save_file_buffer + 0x2048), 0x1156C);
    decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(secondary_card_character_save_buffer);
    if (check_slot_b_card_save() == 7) {
        return;
    }
}

void TAdSinglePlyChrSelectGC::prepare_save_data(void) {
    s32 r = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = r;
    chr_select_serial_seeds[0] = r;
    memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), selected_character_data, 0x41C);
    memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (void *)active_character_save_record, 0x2370);
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
}

s32 TAdSinglePlyChrSelectGC::encrypt_and_save(void) {
    s32 temp_r3;
    temp_r3 = get_serial_result__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = temp_r3;
    chr_select_serial_seeds[0] = temp_r3;
    TAdSinglePlyChrSelectGC::encrypt_save_data(secondary_card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(0);
    return 1;
}
s32 TAdSinglePlyChrSelectGC::write_encrypted_save(void) {
    s32 temp_r3;
    temp_r3 = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[1] = temp_r3;
    chr_select_serial_seeds[0] = temp_r3;
    TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
    TAdSinglePlyChrSelectGC::save_character_file(1);
    return 1;
}

void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    CharacterFile *a = new CharacterFile;
    CharacterFile *b = new CharacterFile;
    TAdSinglePlyChrSelectGC::copy_save_data((saddr)a, (saddr)arg0);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle((s32 *)&chr_select_rng_state);
    subtractive_rng_unshuffle(&chr_select_rng_state, (const u8 *)a, (u8 *)b, 0x1156C);
    TAdSinglePlyChrSelectGC::copy_save_data((saddr)arg0, (saddr)b);
    delete b;
    delete a;
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    ((TAdSinglePlyChrSelectGC *)&chr_select_rng_state)->apply_rng_cipher((u32 *)arg0, 0x1156C);
    subtractive_rng_seed(&chr_select_rng_state, TAdSinglePlyChrSelectGC__sub_801FCCC0((u8 *)arg0));
    subtractive_rng_xor_buffer((s32 *)&chr_select_rng_state, (u32 *)arg0, 0x11568);
}

s32 copy_save_data__23TAdSinglePlyChrSelectGCFii(saddr arg0, saddr arg1) {
    Save_80200690 *dst = (Save_80200690 *)arg0;
    Save_80200690 *src = (Save_80200690 *)arg1;
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
    return arg0;
}

#define self ((s32 *)arg0)
void TAdSinglePlyChrSelectGC::encrypt_save_data(void *arg0) {
    CharacterFile *a;
    CharacterFile *b;
    TAdSinglePlyChrSelectGC__sub_801FCCB4((u8 *)self, (s32)(subtractive_rng_next((s32 *)&chr_select_rng_state)));
    TAdSinglePlyChrSelectGC::set_id(self, 0);
    TAdSinglePlyChrSelectGC::set_id((void *)self, (s32)(calc_crc32_bitwise((u8 *)self, 0x1156C)));
    subtractive_rng_seed(&chr_select_rng_state, TAdSinglePlyChrSelectGC__sub_801FCCC0((u8 *)self));
    subtractive_rng_xor_buffer((s32 *)&chr_select_rng_state, (u32 *)self, 0x11568);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    ((TAdSinglePlyChrSelectGC *)&chr_select_rng_state)->apply_rng_cipher((u32 *)self, 0x1156C);
    a = new CharacterFile;
    b = new CharacterFile;
    TAdSinglePlyChrSelectGC::copy_save_data((saddr)a, (saddr)self);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle((s32 *)&chr_select_rng_state);
    TAdSinglePlyChrSelectGC::permute_save_blocks(&chr_select_rng_state, (const u8*)a, (u8*)b, (u32)0x1156C);
    TAdSinglePlyChrSelectGC::copy_save_data((saddr)self, (saddr)b);
    delete b;
    delete a;
}
#undef self

void TAdSinglePlyChrSelectGC::build_save_file() {
    char *base = (char *)&pso_character_card_filename;
    CardSaveDescriptor f;
    memset(&f, 0, sizeof(f));
    strcpy(f.filename, base + 0xB4);
    strcpy(f.title, base + 0x11C);
    memcpy(f.key, base + 0xEC, 0x10);
    set_card_banner_and_icon(&f, 1);
    f.field_4c = 1;
    f.field_4e = 1;
    f.field_50 = 0;
    f.omit_title_space = 0;
    f.data = (u8 *)guild_card_save_payload;
    f.size = 0xE28C;
    TAdPlayerLoadGC::build_save_file_image((void *)guild_card_save_file_buffer, &f);
    fn_801E14E4(&f);
}

void TAdSinglePlyChrSelectGC::build_default_save_file() {
    char *base = (char *)&pso_character_card_filename;
    CardSaveDescriptor f;
    memset(&f, 0, sizeof(f));
    strcpy(f.filename, base + 0xB4);
    strcpy(f.title, base + 0xC8);
    memcpy(f.key, base + 0xEC, 0x10);
    set_card_banner_and_icon(&f, 0);
    f.field_4c = 1;
    f.field_4e = 1;
    f.field_50 = 0;
    f.omit_title_space = 0;
    f.data = (u8 *)system_save_payload;
    f.size = 0x11C;
    TAdPlayerLoadGC::build_save_file_image((void *)system_save_file_buffer, &f);
    fn_801E14E4(&f);
}

void TAdSinglePlyChrSelectGC::save_character_file(int arg0) {
    char *base = (char *)&pso_character_card_filename;
    CardSaveDescriptor f;
    memset(&f, 0, sizeof(f));
    strcpy(f.filename, ((Str_80200A44 *)base)->name);
    strcpy(f.title, ((Str_80200A44 *)base)->title);
    memcpy(f.key, ((Str_80200A44 *)base)->icon, 0x10);
    set_card_banner_and_icon(&f, 2);
    f.field_4c = 1;
    f.field_4e = 1;
    f.field_50 = 0;
    f.omit_title_space = 0;
    if (arg0 != 0) {
        f.data = (u8 *)card_character_save_buffer;
    } else {
        f.data = (u8 *)secondary_card_character_save_buffer;
    }
    f.size = 0x1156C;
    TAdPlayerLoadGC::build_save_file_image((void *)character_save_file_buffer, &f);
    fn_801E14E4(&f);
    if (arg0 != 0) {
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(card_character_save_buffer);
    } else {
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(secondary_card_character_save_buffer);
    }
}

void TAdSinglePlyChrSelectGC::reset_character_data(void) {
    s32 var_r31;
    saddr var_r30;

    if ((void *) selected_character_data != NULL) {
        var_r30 = (saddr)((TObjPlayer *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer))->get_ptr_4();
        var_r31 = 0;
        do {
            ((TAdSinglePlyChrSelectGC *)var_r30)->clear_inventory_slot();
            var_r31 += 1;
            var_r30 += 0x1C;
        } while (var_r31 < 0x1E);
        *(s8 *)((s8 *)selected_character_data + 0) = 0;
        init_class_starting_inventory((void *)selected_character_data);
        init_character_stats_for_level(*(u8 *)((s8 *)selected_character_data + 0x3A1), (void *)selected_character_data, *(s32 *)((s8 *)selected_character_data + 0x364));
        ((TObjPlayer *)selected_character_data)->reset_action_palette();
        ((TObjPlayer *)selected_character_data)->m_36c = 0;
    }
    if ((void *) active_character_save_record != NULL) {
        memset((u8 *)active_character_save_record + 0x250, 0, 0x12C0);
        *(s32 *)((s8 *)active_character_save_record + 0x248) = 0;
        *(s32 *)((s8 *)active_character_save_record + 0x24C) = 0;
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
            (*(s32 *)((s8 *)active_character_save_record + 0x14))++;
            return *(s32 *)((s8 *)active_character_save_record + 0x14);
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
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
                    TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
                }
                return 0;
            }
            TAdSinglePlyChrSelectGC::render_frame();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
        file = new CharacterFile;
        memset(file, 0, 0x1156C);
        memcpy(file, buf + 0x2048, 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(file);
        if (compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv((A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C(file), (A_801FD8B8 *)get_character_save_record(0xFFFF), (C_801FD8B8 *)file, (C_801FD8B8 *)TAdSinglePlyChrSelectGC::get_instance()) != 7) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
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
            TAdSinglePlyChrSelectGC::safe_free((uaddr)buf);
        }
        if (file != NULL) {
            delete file;
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && poll_memcard_result(character_save_card_slot) == 0) {
            TObjPlayer::sync_char_select_state();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            TAdSinglePlyChrSelectGC::update_play_time();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            (*(s32 *)((s8 *)active_character_save_record + 0x14))++;
            TAdSinglePlyChrSelectGC::increment_counter();
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), selected_character_data, 0x41C);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (void *)active_character_save_record, 0x2370);
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
                s32 i;
                saddr p;
                p = (saddr)((TObjPlayer *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer))->get_ptr_4();
                for (i = 0; i < 30; i++) {
                    ((TAdSinglePlyChrSelectGC *)p)->clear_inventory_slot();
                    p += 0x1C;
                }
                {
                    u8 *s = (u8 *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer);
                    *s = 0;
                }
                {
                    CharacterSaveRecord *q = TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer);
                    memset(q->bank_items, 0, 0x12C0);
                    q->pad_248 = 0;
                    q->pad_24C = 0;
                }
            }
            *(s32 *)((u8 *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer) + 0x36C) = 0;
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
            TAdSinglePlyChrSelectGC::encrypt_save_data(card_character_save_buffer);
            TAdSinglePlyChrSelectGC::save_character_file(1);
            if (TAdSinglePlyChrSelectGC__sub_801FDA4C() == 0) {
                card_load_sequence_state = 6;
            }
        }
        return *(s32 *)((s8 *)active_character_save_record + 0x14);
    }
    return 0;
}

}





struct Item_80201354 { u8 pad[0x18]; };

struct Card_80201354 {
    s32 f0;
    s32 secs;
    u32 magic;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 f18[0x1C];
    u8 f34[0x10];
    u8 pad44[0x248 - 0x44];
    s32 f248;
    s32 f24C;
    Item_80201354 items[200];
    u8 pad1510[0x22C4 - 0x1510];
    u8 f22C4[0x2370 - 0x22C4];
};

extern "C" {
s32 default_clock_offset_frames(void);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);

s32 poll_memcard_result(saddr);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 TAdSinglePlyChrSelectGC__sub_801FEBBC();
s32 load_and_verify_data(s32 arg0);
void TAdSinglePlyChrSelectGC__sub_80200418(void);
s32 TAdSinglePlyChrSelectGC__sub_8028DC14();
void TAdSinglePlyChrSelectGC__sub_8028DC1C();
void init_fresh_character_card(void);
s32 alloc_global_buffer(void);
s32 buffer_init(void);
s32 init_buffer(void);
u32 calc_crc32_bitwise(u8 *, u32);


}

s32 TAdSinglePlyChrSelectGC::increment_frame() {
    if ((void *) active_character_save_record != NULL) {
        *(s32 *)((s8 *)active_character_save_record + 0x14) = (s32) (*(s32 *)((s8 *)active_character_save_record + 0x14) + 1);
        return *(s32 *)((s8 *)active_character_save_record + 0x14);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::get_player_count() {
    if ((void *) active_character_save_record != NULL) {
        return *(s32 *)((s8 *)active_character_save_record + 4);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::update_elapsed_time(void * arg0) {
    s32 date[4];
    s32 spC;
    s32 sp8;

    if (arg0 != NULL) {
        DateToSeconds((DateStamp *)(char_select_date_stamp), (int *)(&spC));
        getDateStamp((DateStamp *)date);
        DateToSeconds((DateStamp *)(date), (int *)(&sp8));
        *(s32 *)((s8 *)arg0 + 0xC) = (s32) (*(s32 *)((s8 *)arg0 + 0xC) + (sp8 - spC));
        return *(s32 *)((s8 *)arg0 + 0xC);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::update_play_time() {
    s32 spC;
    s32 sp8;
    if ((void *) (*(u8 * *)&active_character_save_record) != NULL) {
        DateToSeconds((DateStamp *)char_select_date_stamp, (int *)(&spC));
        getDateStamp((DateStamp *)char_select_date_stamp);
        DateToSeconds((DateStamp *)char_select_date_stamp, (int *)(&sp8));
        *(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC) = (s32) (*(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC) + (sp8 - spC));
        return *(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC);
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::init_and_register(int arg0) {
    saddr allocation;
    u32 temp_r30;
    u32 temp_r31;

    allocation = (saddr)new CharacterFile;
    TAdSinglePlyChrSelectGC::copy_save_data(allocation, arg0);
    temp_r30 = TAdSinglePlyChrSelectGC::get_type((void *)allocation);
    TAdSinglePlyChrSelectGC::set_id((void *)allocation, 0);
    temp_r31 = calc_crc32_bitwise((u8 *)allocation, 0x1156C);
    delete (CharacterFile *)allocation;
    if (temp_r30 == temp_r31) {
        return 1;
    }
    return 0;
}

extern "C" {

u32 calc_crc32_bitwise(u8 *arg0, u32 arg1) {
    u32 crc = -1;
    u32 i;
    for (i = 0; i < arg1; i++) {
        s32 j;
        crc ^= arg0[i];
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
    memset((void *)guild_card_save_payload, 0, 0xE28C);
    getDateStamp((DateStamp *)((s32 *) date));
    DateToSeconds((DateStamp *)((s32 *)((s32 *) date)), (int *)(guild_card_save_payload + 0xE284));
    TAdSinglePlyChrSelectGC::set_save_slot(0);
}


}

void TAdSinglePlyChrSelectGC::reset_save_header() {
  volatile unsigned long long sp10;
  u64 serial_number;
  memset((void *)system_save_payload, 0, 0x11C);
  *((s16 *) (((s8 *) system_save_payload) + 4)) = -0x32;
  *((s8 *) (((s8 *) system_save_payload) + 6)) = 0;
  *((s8 *) (((s8 *) system_save_payload) + 7)) = TLanguage::get_default_language();
  *((s32 *) (((s8 *) system_save_payload) + 8)) = default_clock_offset_frames();
  *((s16 *) (((s8 *) system_save_payload) + 0xC)) = 0;
  *((s16 *) (((s8 *) system_save_payload) + 0xE)) = 0;
  TAdPlayerLoadGC::reset_load_state(0, &serial_number);
  memmove((void *)(system_save_payload + 0x110), &serial_number, sizeof(serial_number));
  getDateStamp((DateStamp *)(&sp10));
  DateToSeconds((DateStamp *)(&sp10), (int *)(system_save_payload + 0x118));
}

extern "C" {

void init_fresh_character_card(void) {
    TPlyCharData *chr;
    Card_80201354 *card;
    s32 i;
    stop_pad_rumble();
    chr = TAdSinglePlyChrSelectGC::get_char_index(0xFFFF);
    card = (Card_80201354 *)get_character_save_record(0xFFFF);
    memset(chr, 0, 0x41C);
    TAdSinglePlyChrSelectGC__sub_8028DC1C();
    TObjPlayer::begin_action_from_char_select();
    memset(card, 0, 0x2370);
    getDateStamp((DateStamp *)char_select_date_stamp);
    DateToSeconds((DateStamp *)char_select_date_stamp, (int *)(&card->secs));
    card->magic = 0xA205B064;
    card->fC = 0;
    card->f0 = 0;
    card->f14 = 1;
    memcpy(card->f18, get_account_entry(0), 0x1C);
    memcpy(card->f34, TLobby__sub_80146D50(0), 0x10);
    clear_all_story_flags();
    card->f248 = 0;
    card->f24C = 0;
    for (i = 0; i < 200; i++) {
        ((TAdSinglePlyChrSelectGC *)(&card->items[i]))->init_item_entry();
    }
    ((TWindowSubSymbolChat *)card)->load_symbol_chat_data();
    set_fresh_card_flag(card);
    TWindowShortListCtrl__sub_8026E884((s16 *)card->f22C4);
}

}

s32 TAdSinglePlyChrSelectGC::free_buffer() {
    if ((u32) guild_card_save_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)((void*)guild_card_save_file_buffer));
        guild_card_save_file_buffer = 0U;
        return 1;
    }
    return 0;
}


s32 TAdSinglePlyChrSelectGC::free_data() {
    if ((u32) system_save_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)((void*)system_save_file_buffer));
        system_save_file_buffer = 0U;
        return 1;
    }
    return 0;
}

extern "C" {


s32 buffer_init(void) {
    s32 temp_r31;

    if ((u32) guild_card_save_file_buffer == 0U) {
        temp_r31 = guild_card_save_file_block_count << 0xD;
        guild_card_save_file_buffer = (saddr)TQuestVmDownLoadServer::alloc(temp_r31);
        memset((void *)guild_card_save_file_buffer, 0, temp_r31);
        return 1;
    }
    return 0;
}


s32 alloc_global_buffer(void) {
    s32 temp_r31;

    if ((u32) system_save_file_buffer == 0U) {
        temp_r31 = system_save_file_block_count << 0xD;
        system_save_file_buffer = (saddr)TQuestVmDownLoadServer::alloc(temp_r31);
        memset((void *)system_save_file_buffer, 0, temp_r31);
        return 1;
    }
    return 0;
}


}

s32 TAdSinglePlyChrSelectGC::free() {
    if ((u32) character_save_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)((void*)character_save_file_buffer));
        character_save_file_buffer = 0U;
        return 1;
    }
    return 0;
}

extern "C" {


s32 init_buffer(void) {
    s32 temp_r31;

    if ((u32) character_save_file_buffer == 0U) {
        temp_r31 = character_save_file_block_count << 0xD;
        character_save_file_buffer = (saddr)TQuestVmDownLoadServer::alloc(temp_r31);
        memset((void *)character_save_file_buffer, 0, temp_r31);
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
        if (TAdSinglePlyChrSelectGC__sub_801FDA4C() == 0) {
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
            lbl_805D49B4 = 0;
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
        lbl_805D49B4 = 0;
        break;
    case 10:
        if (TAdSinglePlyChrSelectGC__sub_801FDA4C() == 0) {
            card_load_sequence_state = 6;
            break;
        }
        break;
    case 11:
        stop_pad_rumble();
        if (poll_memcard_result(character_save_card_slot) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            lbl_805D49B4 = 0;
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
        lbl_805D49B4 = 0;
        break;
    case 12:
        stop_pad_rumble();
        if (poll_memcard_result(card_load_channel) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 15:
        if (poll_memcard_result(system_save_card_channel) == 0) {
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 17:
        if (poll_memcard_result(system_save_card_channel) == 0) {
            TAdSinglePlyChrSelectGC::verify_save_checksum(1);
            if ((s32) card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                TAdSinglePlyChrSelectGC::load_selected_char();
                break;
            }
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 16:
        if (poll_memcard_result(system_save_card_channel) == 0) {
            TAdSinglePlyChrSelectGC::verify_save_checksum(0);
            if ((s32) card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                TAdSinglePlyChrSelectGC::load_selected_char();
                break;
            }
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 18:
        stop_pad_rumble();
        if (poll_memcard_result(1) == 0) {
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 19:
        stop_pad_rumble();
        if (poll_memcard_result(0) == 0) {
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
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
        lbl_805D49B4 = 0;
        break;
    case 22:
        if (poll_memcard_result(1) == 0) {
            TAdSinglePlyChrSelectGC::verify_save_checksum();
            if ((s32) card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                TAdSinglePlyChrSelectGC__sub_801FEBBC();
                break;
            }
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
        }
        break;
    }
}

}

void TAdSinglePlyChrSelectGC::release_all() {
    free_char_data_slots__23TAdSinglePlyChrSelectGCFPv((Obj_801FCBA0 *)chr_select_buffer_ptr_table);
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



extern "C" {

s32 __ct__12TPlyCharDataFv(s32);
void alloc_char_records__23TAdSinglePlyChrSelectGCFi(saddr arg0);
s32 buffer_init(void);
s32 alloc_global_buffer(void);
s32 init_buffer();
s32 get_field_118__22TAdEnterSerialAccessGCFv();

}

void TAdSinglePlyChrSelectGC::init_char_select_globals() {
    u32 seconds;
    CharacterFile *card;
    saddr record;
    saddr guild;

    TAdSinglePlyChrSelectGC__selection_index = 0;
    card_load_followup_pending = 0;
    alloc_char_records__23TAdSinglePlyChrSelectGCFi((saddr)chr_select_buffer_ptr_table);
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
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        break;
    case 1:
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        break;
    case 2:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 3:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 4:
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 5:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 6:
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 7:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 8:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 9:
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 10:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 11:
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 12:
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 13:
        system_save_payload = (saddr)::operator new(0x11C);
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 14:
        system_save_payload = (saddr)::operator new(0x11C);
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 15:
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 16:
        system_save_payload = (saddr)::operator new(0x11C);
        card = new CharacterFile;
        card_character_save_buffer = card;
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 17:
        system_save_payload = (saddr)::operator new(0x11C);
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 18:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 19:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 20:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 21:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 22:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        system_save_payload = (saddr)::operator new(0x11C);
        card = new CharacterFile;
        card_character_save_buffer = card;
        selected_character_data = new TPlyCharData;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        break;
    case 23:
        guild = (saddr)::operator new(0xE28C);
        if (guild != 0) {
            guild = init_windows__23TAdSinglePlyChrSelectGCFi(guild);
        }
        guild_card_save_payload = guild;
        record = (saddr)new CharacterSaveRecord;
        active_character_save_record = record;
        selected_character_data = new TPlyCharData;
        card = new CharacterFile;
        card_character_save_buffer = card;
        system_save_payload = (saddr)::operator new(0x11C);
        break;
    }
    memset((void *)selected_character_data, 0, 0x41C);
    memset((void *)active_character_save_record, 0, 0x2370);
    memset(card_character_save_buffer, 0, 0x1156C);
    memset((void *)system_save_payload, 0, 0x11C);
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
        s32 g = get_field_118__22TAdEnterSerialAccessGCFv();
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
    if ((u32) secondary_card_system_save_payload != 0U) {
        ::operator delete((void *)secondary_card_system_save_payload);
        secondary_card_system_save_payload = 0U;
    }
}


void TAdSinglePlyChrSelectGC::alloc_char_buffers() {
    s32 var_r0;
    s32 dst;
    s32 var_r4;
    s32 var_r5;
    dst = 0x10000;
    dst = 0x1156C;
    var_r0 = (saddr)new CharacterFile;
    (*(s32 *)&secondary_card_character_save_buffer) = var_r0;
    dst = 0x11C;
    (*(s32 *)&secondary_card_system_save_payload) = (saddr)::operator new(0x11C);
    var_r4 = 0x10000;
    dst = (*(s32 *)&secondary_card_character_save_buffer);
    var_r5 = 0x1156C;
    var_r4 = 0;
    memset((void *)(saddr)dst, 0, 0x1156C);
    dst = (*(s32 *)&secondary_card_system_save_payload);
    var_r4 = 0;
    var_r5 = 0x11C;
    memset((void *)(saddr)dst, 0, 0x11C);
}

extern "C" {

int get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv(void) { return get_field_118__22TAdEnterSerialAccessGCFv(); }

}


extern "C" {

s32 get_serial_result__22TAdEnterSerialAccessGCFv(void) {
    return *(s32 *)((s8 *)secondary_card_system_save_payload + 0x118);
}

s32 get_field_118__22TAdEnterSerialAccessGCFv(void) {
    return *(s32 *)((s8 *)system_save_payload + 0x118);
}

saddr get_character_save_record(u32 arg0) {
    if (is_split_screen() != 0) {
        if (arg0 == 0xFFFF) {
            return get_split_screen_character_save_record(0U);
        }
        return get_split_screen_character_save_record(arg0);
    }
    return active_character_save_record;
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
}
