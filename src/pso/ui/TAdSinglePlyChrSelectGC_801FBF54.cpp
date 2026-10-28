#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/system/date.h"
#include "pso/system/main_loop.h"
#include "pso/system/memory.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLanguage.h"
#include "pso/ui/Language.h"
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
struct Vec2_804C8A44 { f32 x, y; };
extern "C" {
CardFileInfo_804C88C0 lbl_804C88C0 = {
    "PSO_CHARACTER", "CHARACTER_FILE", 0,
    { 0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'T', 'T', 'T', 'U' },
};
char pso_system_card_filename[0x20] = "PSO_SYSTEM";
char lbl_804C8934[0x20] = "PSO3_SYSTEM";
char lbl_804C8954[0x20] = "PSO3_CHARACTER";
CardFileComment_804C8974 lbl_804C8974 = {
    "EPISODE I & II", "SYSTEM_FILE", 0,
    { 0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'U', 'T', 'T', 'T' },
};
GuildCardFile_804C89BC lbl_804C89BC = {
    "PSO_GUILDCARD", "GUILDCARD_FILE", 0, "PSO______000", "PSOV2/DOWNLOAD", 0,
};
u8 TQuestVmDownLoadServer__memcard_key[0x10] = {
    0x35, 0x04, 0x08, 0x1A, 0x0A, 0x07, 'V', 'T', 'T', 'T',
};
__declspec(section ".data") Vec2_804C8A44 lbl_804C8A44 = { 0.0f, 0.0f };
}
struct SubtractiveRng {
    SubtractiveRng();
    u32 state[58];
};

u32 lbl_805137C8[4];
u32 chr_select_buffer_ptr_table[8];
u32 chr_select_request_buffer[9];
SubtractiveRng chr_select_rng_state;

u32 char_select_date_stamp[3];
__declspec(section ".data") s32 chr_select_serial_seeds[2];
__declspec(section ".data") s32 lbl_80513918[2];

struct RecoveredGlobal_801FC564_lbl_804C89BC {
    s32 value;
    u8 remaining[0x74];
};

struct Slot_801FCB04 {
    u8 pad[0x428];
    u32 magic;
    u8 rest[0x2798 - 0x42C];
};

struct RecoveredGlobal_80202A40_lbl_8051381C {
    s32 value;
    u8 remaining[0xE4];
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
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, s32);
extern s32 lbl_805D49B4;
extern s32 card_load_channel;
extern s32 guild_card_save_file_buffer;
u32 CARDGetDiskID();
s32 strncpy(s32 *, s32 *, s32);
extern s32 lbl_8044A7E0[];
s32 TAdPlayerLoadGC__sub_801E1B50(void *);
s32 render_frame__23TAdSinglePlyChrSelectGCFv();
int memcpy(void*, void*, void*);
extern s32 system_save_payload;
extern s32 system_save_card_channel;
extern s32 system_save_file_buffer;
void __construct_array(void*, void*, void*, int, int);
void* init_char_data__23TAdSinglePlyChrSelectGCFPv(void* p);
s32 TAdSinglePlyChrSelectGC__sub_801FC8B4(s32 arg0, s16 arg1);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 arg0);
void *TAdSinglePlyChrSelectGC__sub_802115C0(void *p);
Buf_801FBFD0 *alloc__22TQuestVmDownLoadServerFv(u32);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *, u32);
s32 load_system_file__23TAdSinglePlyChrSelectGCFiPv(s32 arg0, s32 *arg1);
s32 TAdPlayerLoadGC__sub_801E1944(s32, char *, void *, s32);
s32 register_callback__23TAdSinglePlyChrSelectGCFis(s32 arg0, s16 arg1);
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(s32);
s32 get_field_118__22TAdEnterSerialAccessGCFv(void);
void *memset(void *, int, u32);
extern s32 chr_select_serial_seeds[];
extern int card_character_save_buffer;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
s32 TAdSinglePlyChrSelectGC__sub_80202B1C(s32, s32);
u8 TAdSinglePlyChrSelectGC__sub_80202B30();
void TAdSinglePlyChrSelectGC__sub_80203210(void *p);
int fn_8020325C(void *arg0);
u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int arg0);
void load_tables(int a0);
int TAdSinglePlyChrSelectGC__sub_801FCD04(void*);
int TAdSinglePlyChrSelectGC__sub_801FCD3C(void*);
s32 copy_item_to_bank_entry__18TCheckRoomSequenceFPvPv(int, void *);
s32 is_item_record_empty(int);
s32 TLobby__sub_8030A770();
s32 get_game_play_mode();
s32 item_identity_matches(s32, s32);
s32 __destroy_arr(s32, s32 *, s32, s32);
s32 __ct__12TPlyCharDataFv(s32 arg0);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void game_state_load(void);
void *get_character_save_record(u16);

extern s32 chr_select_game_name_buffer;

void TAdSinglePlyChrSelectGC::copy_name(s32 arg0) {
    u32 var_r3;
    if (arg0 >= 0) {
        var_r3 = CARDGetDiskID();
        if (var_r3 != 0U) {
            strncpy((s32 *)var_r3, &chr_select_game_name_buffer, 4);
        }
    }
}

void TAdSinglePlyChrSelectGC::set_card_disk_id(s32 arg0) {
    u32 var_r3;
    if (arg0 >= 0) {
        var_r3 = CARDGetDiskID();
        if (var_r3 != 0U) {
            strncpy((s32 *)((s32 *)var_r3), lbl_8044A7E0, 4);
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
    if (TAdPlayerLoadGC__sub_801E1B50((void *)chan) != 0) {
        return 0;
    }
    if (find_card_file__15TAdPlayerLoadGCFiPv(chan, (s32)lbl_804C8934) != 0) {
        return 0;
    }
    lbl_805D49B4 = 1;
    TAdSinglePlyChrSelectGC::set_card_disk_id(chan);
    ok = 0;
    buf = alloc__22TQuestVmDownLoadServerFv(0x6000);
    if (((TAdSinglePlyChrSelectGC *)chan)->load_player_slot((int)((int)lbl_804C8934), (int)((int)buf)) == 0 &&
        TAdSinglePlyChrSelectGC::wait_for_card_load(chan) == 1) {
        h = &buf->hdr;
        v = h->f118;
        ok = 1;
        *arg1 = v;
        sum = h->sum;
        h->sum = 0;
        r = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)h, (u32)(sizeof(Hdr_801FBFD0)));
        if (r != sum) {
            ok = 0;
        }
    }
    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
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
    s32 e;
    n = TAdSinglePlyChrSelectGC__sub_80202B30();
    for (i = 0; i < n; i++) {
        e = TAdSinglePlyChrSelectGC__sub_80202B1C(arg0, i);
        if (fn_8020325C((void *)(e + 8)) != 0) {
            TAdSinglePlyChrSelectGC__sub_80203210((void *)e);
        }
    }
}

u8 TAdSinglePlyChrSelectGC::is_level_capped() {
    return (u8) (*(s32 *)((s8 *)this + 0x248) >= 0xC8);
}

s32 TAdSinglePlyChrSelectGC::find_entry(s32 arg1) {
    s32 arg0 = (s32)this;
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

s32 TAdSinglePlyChrSelectGC::register_in_free_room_slot(s32 arg1) {
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

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x235A);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_window_status(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x2358);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC__sub_801FC36C(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x2356);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_state(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x2354);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_flag(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21B0);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_field(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21AE);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_status(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21AC);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_value(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21AA);
    }
    return 0U;
}

u16 TAdSinglePlyChrSelectGC::get_card_field_21a8(int arg0) {
    void *character_save_record;

    character_save_record = get_character_save_record(arg0);
    if (character_save_record != NULL) {
        return *(u16 *)((s8 *)character_save_record + 0x21A8);
    }
    return 0U;
}

s32 *TAdSinglePlyChrSelectGC__sub_80202B38(void *self, s32 i);

s32 TAdSinglePlyChrSelectGC::append_inventory_item(s32 arg1) {
#define arg0 ((u8 *)this)
    u8 n = *arg0;

    if (n < 0x1E) {
        ((TAdSinglePlyChrSelectGC *)arg0)->clear_inventory_slot_by_index(n);
        memcpy(TAdSinglePlyChrSelectGC__sub_80202B38(arg0, n), (void *)arg1, (void *)0x14);
        *arg0 += 1;
        return 1;
    }
    return 0;
#undef arg0
}

typedef char RecoveredGlobal_801FC564_lbl_804C89BC_size[sizeof(RecoveredGlobal_801FC564_lbl_804C89BC) == 0x78 ? 1 : -1];
s32 TAdSinglePlyChrSelectGC::load_player_by_slot(s32 chan) {
    s32 var_r0;
    var_r0 = -1;
    card_load_channel = chan;
    if ((chan >= 0) && (chan <= 7)) {
        var_r0 = find_card_file__15TAdPlayerLoadGCFiPv(chan, (s32) &lbl_804C89BC);
        if (var_r0 == 0) {
            TAdSinglePlyChrSelectGC::set_quest_download_server(card_load_channel);
            lbl_805D49B4 = 1;
            var_r0 = ((TAdSinglePlyChrSelectGC *)card_load_channel)->load_player_slot((int)((s32) &lbl_804C89BC), (int)guild_card_save_file_buffer);
        }
    }
    return var_r0;
}

s32 TAdSinglePlyChrSelectGC::verify_system_file(void* _w0) {
    s32 temp_r3;
    s32 var_r30;
    var_r30 = 0;
    temp_r3 = (s32)::operator new(0x11C);
    if (temp_r3 == 0) {
        return 0;
    }
    if (find_card_file__15TAdPlayerLoadGCFiPv((s32)system_save_card_channel, (s32)pso_system_card_filename) == 0) {
        lbl_805D49B4 = 1;
        ((TAdSinglePlyChrSelectGC *)system_save_card_channel)->load_player_slot((int)pso_system_card_filename, (int)system_save_file_buffer);
        stop_pad_rumble();
loop_4:
        if (TAdPlayerLoadGC__sub_801E1B50((void *)system_save_card_channel) != 0) {
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
            goto loop_4;
        }
        lbl_805D49B4 = 0;
        memcpy((void*)temp_r3, (void*)(system_save_file_buffer + 0x2048), (void*)(0x11C));
        var_r30 = ((TAdSinglePlyChrSelectGC *)temp_r3)->fields_equal((void *)system_save_payload);
    }
    ::operator delete((void *)temp_r3);
    return var_r30;
}

s32 TAdSinglePlyChrSelectGC::load_save_from_card() {
    u8 *buf;
    s32 size;
    s32 p;
    s32 g;
    if (find_card_file__15TAdPlayerLoadGCFiPv(character_save_card_slot, (s32)lbl_804C88C0.filename) == 0) {
    size = character_save_file_block_count << 13;
    buf = (u8 *)alloc__22TQuestVmDownLoadServerFv(size);
    if (buf == NULL) {
        return 0;
    }
    memset(buf, 0, size);
    while (TAdPlayerLoadGC__sub_801E1944(character_save_card_slot, lbl_804C88C0.filename, buf, character_save_file_block_count) != 0) {
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
            xfree(buf);
            return 0;
        }
    }
    while (TAdPlayerLoadGC__sub_801E1B50((void *)character_save_card_slot) != 0) {
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
            TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            return 0;
        }
    }
    g = get_field_118__22TAdEnterSerialAccessGCFv();
    chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = g;
    p = (s32)::operator new(0x1156C);
    if (p != 0) {
        p = init_char_slots__23TAdSinglePlyChrSelectGCFi(p);
    }
    if ((u32)p == 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        return 0;
    }
    memset((void *)p, 0, 0x1156C);
    memcpy((void *)p, buf + 0x2048, (void *)0x1156C);
    decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(p);
    if (*(u32 *)(card_character_save_buffer + 0x11564) != *(u32 *)(p + 0x11564)) {
        register_callback__23TAdSinglePlyChrSelectGCFis(p, 1);
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        return 0;
    }
    register_callback__23TAdSinglePlyChrSelectGCFis(p, 1);
    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
    return 1;
    }
    return 0;
}

s32 register_callback__23TAdSinglePlyChrSelectGCFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr(arg0 + 4, (s32 *)TAdSinglePlyChrSelectGC__sub_801FC8B4, 0x2798, 7);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

s32 TAdSinglePlyChrSelectGC__sub_801FC8B4(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__12TPlyCharDataFv(arg0, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    __construct_array((void*)(arg0 + 4), (void*)init_char_data__23TAdSinglePlyChrSelectGCFPv, (void*)TAdSinglePlyChrSelectGC__sub_801FC8B4, 0x2798, 7);
    return arg0;
}

void* init_char_data__23TAdSinglePlyChrSelectGCFPv(void* p) { __ct__12TPlyCharDataFv((s32)p); ((TAdSinglePlyChrSelectGC *)((char*)p + 0x41c))->init_char_record(); return p; }

typedef char RecoveredGlobal_80202A40_lbl_8051381C_size[sizeof(RecoveredGlobal_80202A40_lbl_8051381C) == 0xE8 ? 1 : -1];
u8 *TAdSinglePlyChrSelectGC::init_char_record() {
    __construct_array(((u8 *)this) + 0x250, (void*)((void *)TAdSinglePlyChrSelectGC__sub_802115C0), (void*)(0), 0x18, 0xc8);
    ((TAdSinglePlyChrSelectGC *)(((u8 *)this) + 0x1510))->init_guild_card_tag();
    return ((u8 *)this);
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
    buf = (u32 *)(s32)::operator new(0x11C);
    if (buf == NULL) {
        return -3;
    }
    if (find_card_file__15TAdPlayerLoadGCFiPv(system_save_card_channel, (s32)pso_system_card_filename) == 0) {
        lbl_805D49B4 = 1;
        ((TAdSinglePlyChrSelectGC *)system_save_card_channel)->load_player_slot((int)((int)pso_system_card_filename), (int)system_save_file_buffer);
        stop_pad_rumble();
        for (;;) {
            if (TAdPlayerLoadGC__sub_801E1B50((void *)system_save_card_channel) == 0) break;
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        lbl_805D49B4 = 0;
        memcpy(buf, (void*)(system_save_file_buffer + 0x2048), (void*)((void *)0x11C));
        sum = *buf;
        if (((TAdSinglePlyChrSelectGC *)buf)->fields_equal((void *)system_save_payload) == 0) {
            ret = -1;
        }
        *buf = 0;
        r = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)buf, (u32)(0x11C));
        if (r != sum) {
            ret = -2;
        }
    }
    ::operator delete(buf);
    return ret;
}

s32 TAdSinglePlyChrSelectGC::poll_memcard_status() { return TAdSinglePlyChrSelectGC::verify_system_file(this); }

    extern int selected_character_data;
    extern int active_character_save_record;
    extern int TAdSinglePlyChrSelectGC__selection_index;

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

void load_tables(int a0) { TAdSinglePlyChrSelectGC__selection_index = a0; memcpy((void*)selected_character_data, (void*)TAdSinglePlyChrSelectGC__sub_801FCD04((void*)card_character_save_buffer), (void*)1052); memcpy((void*)active_character_save_record, (void*)TAdSinglePlyChrSelectGC__sub_801FCD3C((void*)card_character_save_buffer), (void*)9072); game_state_load(); }

}

namespace P801FCBA0 {

struct VBase_18_4a87b2 { char pad[0x18]; };

struct VObj_18_4a87b2 : VBase_18_4a87b2 {
    virtual void m0();
    virtual s32 m1();
};

struct RecoveredGlobal_801FCD74_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_801FDA4C_lbl_804C88C0 {
    s32 value;
    u8 remaining[0x50];
};

struct RecoveredGlobal_801FDAAC_lbl_804C88C0 {
    s32 value;
    u8 remaining[0x50];
};

struct Ent_801FCD04 { u8 pad[0x41C]; s32 x; s32 v; u8 pad2[0x2798 - 0x424]; };

struct Obj_801FCD04 { s32 hdr; Ent_801FCD04 e[7]; };

struct Ent_801FCD3C { u8 pad[0x41C]; s32 x; s32 v; u8 pad2[0x2798 - 0x424]; };

struct Obj_801FCD3C { s32 hdr; Ent_801FCD3C e[7]; };

struct Ent_801FCCDC { u8 pad[0x41C]; s32 x; s32 v; u8 pad2[0x2798 - 0x424]; };

struct Obj_801FCCDC { s32 hdr; Ent_801FCCDC e[7]; };

struct Obj_801FCBA0 {
    void* a[4];
    void* b[4];
};

struct Ent_801FD668 { u8 pad[0x428]; u32 f428; u8 pad2[0x2798 - 0x42C]; };

struct Ent_801FD728 { u8 pad0[4]; u8 a[0x41C]; u8 b[0x2798 - 0x420]; };

struct A_801FD8B8 { u8 p0[4]; u32 f4; u32 f8; u8 pC[8]; u32 f14; };

struct C_801FD8B8 { u8 p[0x11564]; s32 f11564; };

struct Obj_801FCD04;
struct Obj_801FCD3C;
struct Ent_801FCD04;
struct Ent_801FD668;
struct A_801FD8B8;
struct C_801FD8B8;
struct RecoveredGlobal_801FDA4C_lbl_804C88C0;

struct Ent_801FD6B4 { u8 pad[0x420]; u8 sub[8]; u32 f428; u8 pad2[0x2790 - 0x42C]; u32 f2790; u32 f2794; };

extern "C" {
void TAdSinglePlyChrSelectGC__sub_801FCCB4(u8 *arg0, s32 arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FCCC0(u8 *arg0);
extern u8 *selected_character_data;
s32 forward_to_global_instance__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 __ct__12TPlyCharDataFv(s32);
s32 memset(int, int, int);
void alloc_char_records__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 get_fog_ctrl__16TKeyBoardControlFv();
s32 is_split_screen();
extern u8 *camera_ctrl_instance;
void render_frame__23TAdSinglePlyChrSelectGCFv(void);
u8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv(void);
int draw_window_bg__23TAdSinglePlyChrSelectGCFllll(void*, void*, void*, void*);
extern RecoveredGlobal_801FDA4C_lbl_804C88C0 lbl_804C88C0;
extern int lbl_805D49B4;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
extern s32 character_save_file_buffer;
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void);
u8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv(void);
int draw_window_bg__23TAdSinglePlyChrSelectGCFllll(void*, void*, void*, void*);
extern RecoveredGlobal_801FDA4C_lbl_804C88C0 lbl_804C88C0;
extern int lbl_805D49B4;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
extern s32 character_save_file_buffer;
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void);
int draw_window_bg__23TAdSinglePlyChrSelectGCFllll(void*, void*, void*, void*);
extern int lbl_805D49B4;
extern s32 system_save_card_channel;
extern s32 system_save_file_buffer;
extern s32 system_save_file_block_count;
extern s32 pso_system_card_filename[];
int TAdSinglePlyChrSelectGC__sub_801FD990(s32 a0);
s32 get_selection__23TAdSinglePlyChrSelectGCFv(void *self);
Ent_801FCD04 *TAdSinglePlyChrSelectGC__sub_801FCD04(Obj_801FCD04 *self);
s32 get_selection__23TAdSinglePlyChrSelectGCFv(void *self);
s32 *TAdSinglePlyChrSelectGC__sub_801FCD3C(Obj_801FCD3C *self);
bool is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(Obj_801FCCDC *self, s32 i);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void free_char_data_slots__23TAdSinglePlyChrSelectGCFPv(Obj_801FCBA0* arg0);
extern Ent_801FD668 *card_character_save_buffer;
s32 all_players_loaded__23TAdSinglePlyChrSelectGCFv(void);
int init_new_character_data(void *p);
extern Ent_801FD668 *card_character_save_buffer;
void init_fresh_character_slot(s32 arg0);
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(A_801FD8B8 *a, A_801FD8B8 *b, C_801FD8B8 *c, C_801FD8B8 *d);
s32 init_and_register__23TAdSinglePlyChrSelectGCFi(s32);
extern u32 secondary_card_character_save_buffer;
extern u8 *secondary_card_system_save_payload;
s32 TAdPlayerLoadGC__sub_801FD814(void);
s32 init_and_register__23TAdSinglePlyChrSelectGCFi(s32);
extern Ent_801FD668 *card_character_save_buffer;
extern u32 system_save_payload;
s32 TAdPlayerLoadGC__sub_801FD770(void);
s32 get_main_phase();
u8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv(void);
u32 alloc__22TQuestVmDownLoadServerFv(s32);
s32 is_technique_ready__8TTecCtrlFv();
s32 TAdPlayerLoadGC__sub_801E1944(s32, void *, u32, s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, s32 *);
void register_callback__23TAdSinglePlyChrSelectGCFis(s32, s32);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32);
Ent_801FCD04 *TAdSinglePlyChrSelectGC__sub_801FCD04(Obj_801FCD04 *self);
s32 *TAdSinglePlyChrSelectGC__sub_801FCD3C(Obj_801FCD3C *self);
void render_frame__23TAdSinglePlyChrSelectGCFv(void);
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(A_801FD8B8 *a, A_801FD8B8 *b, C_801FD8B8 *c, C_801FD8B8 *d);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void);
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(s32);
void encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(Ent_801FD668 *);
void save_character_file__23TAdSinglePlyChrSelectGCFi(s32);
void update_play_time__23TAdSinglePlyChrSelectGCFv();
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 get_character_save_record(u32);
s32 get_instance__23TAdSinglePlyChrSelectGCFv();
s32 memcpy(void *, void *, int);
s32 memset(int, int, int);
extern RecoveredGlobal_801FDA4C_lbl_804C88C0 lbl_804C88C0;
extern s32 chr_select_serial_seeds[];
extern s32 lbl_805D55C0;
extern Ent_801FD668 *card_character_save_buffer;
extern u8 *selected_character_data;
extern u32 active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void);
s32 get_main_phase();
u8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv(void);
u32 alloc__22TQuestVmDownLoadServerFv(s32);
s32 is_technique_ready__8TTecCtrlFv();
s32 fn_80203284();
s32 TAdPlayerLoadGC__sub_801E1944(s32, void *, u32, s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, s32 *);
void register_callback__23TAdSinglePlyChrSelectGCFis(s32, s32);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32);
Ent_801FCD04 *TAdSinglePlyChrSelectGC__sub_801FCD04(Obj_801FCD04 *self);
s32 *TAdSinglePlyChrSelectGC__sub_801FCD3C(Obj_801FCD3C *self);
void render_frame__23TAdSinglePlyChrSelectGCFv(void);
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(A_801FD8B8 *a, A_801FD8B8 *b, C_801FD8B8 *c, C_801FD8B8 *d);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void);
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(s32);
void encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(Ent_801FD668 *);
void save_character_file__23TAdSinglePlyChrSelectGCFi(s32);
void update_play_time__23TAdSinglePlyChrSelectGCFv();
void TAdSinglePlyChrSelectGC__sub_8028DC14();
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 get_character_save_record(u32);
s32 get_instance__23TAdSinglePlyChrSelectGCFv();
s32 memcpy(void *, void *, int);
s32 memset(int, int, int);
extern RecoveredGlobal_801FDA4C_lbl_804C88C0 lbl_804C88C0;
extern s32 chr_select_serial_seeds[];
extern s32 lbl_805D55C0;
extern Ent_801FD668 *card_character_save_buffer;
extern u8 *selected_character_data;
extern u32 active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFv(void);
void init_fresh_character_slot(s32 arg0);
extern Ent_801FD668 *card_character_save_buffer;
void refresh_char_slots__23TAdSinglePlyChrSelectGCFv(void);
s32 get_type__23TAdSinglePlyChrSelectGCFPv(void* p);
s32 pso_system_load_gc(void);
void set_id__23TAdSinglePlyChrSelectGCFPvi(void* p, s32 v);
void setup__23TAdSinglePlyChrSelectGCFi(int a0);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, s32 *);
int draw_window_bg__23TAdSinglePlyChrSelectGCFllll(void*, void*, void*, void*);
s32 try_confirm_selection__23TAdSinglePlyChrSelectGCFv();

void free_char_data_slots__23TAdSinglePlyChrSelectGCFPv(Obj_801FCBA0* arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->a[i] != NULL) {
            __dt__12TPlyCharDataFv((s32)arg0->a[i], 1);
        }
        if (arg0->b[i] != NULL) {
            ::operator delete(arg0->b[i]);
        }
        arg0->a[i] = NULL;
        arg0->b[i] = NULL;
    }
}

void alloc_char_records__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
  s32 temp_r3_2;
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
    temp_r3 = (s32)::operator new(0x41C);
    var_r0 = temp_r3;
    temp_r30 += 0;
    if (var_r0 != 0)
    {
      var_r0 = __ct__12TPlyCharDataFv(temp_r3);
    }
    temp_r30 = (u8 *) (arg0 + var_r31);
    *((s32 *) (((s8 *) temp_r30) + 0)) = var_r0;
    temp_r3_2 = (s32)::operator new(0x2370);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0)
    {
      var_r0_2 = (s32)((TAdSinglePlyChrSelectGC *)temp_r3_2)->init_char_record();
    }
    *((s32 *) (((s8 *) temp_r30) + 0x10)) = var_r0_2;
    memset((int) (*((s32 *) (((s8 *) temp_r30) + 0))), 0, 0x41C);
    memset((int) (*((s32 *) (((s8 *) temp_r30) + 0x10))), 0, 0x2370);
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

void set_id__23TAdSinglePlyChrSelectGCFPvi(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
s32 get_type__23TAdSinglePlyChrSelectGCFPv(void* p) { return *(s32*)((char*)p + 0x0); }

bool is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(Obj_801FCCDC *self, s32 i) {
    if (i >= 7) return 0;
    return self->e[i].v != 0;
}

Ent_801FCD04 *TAdSinglePlyChrSelectGC__sub_801FCD04(Obj_801FCD04 *self) {
    return &self->e[get_selection__23TAdSinglePlyChrSelectGCFv(self)];
}

    extern unsigned char lbl_804C89BC[];
    extern int lbl_805D49B4;
    extern int card_load_channel;
    extern int guild_card_save_file_block_count;
    extern int guild_card_save_file_buffer;

typedef char RecoveredGlobal_801FCD74_main_task_size[sizeof(RecoveredGlobal_801FCD74_main_task) == 0x34 ? 1 : -1];

s32 *TAdSinglePlyChrSelectGC__sub_801FCD3C(Obj_801FCD3C *self) {
    return &self->e[get_selection__23TAdSinglePlyChrSelectGCFv(self)].x;
}

void render_frame__23TAdSinglePlyChrSelectGCFv(void) {
    if ((void *) camera_ctrl_instance != NULL) {
        main_task.begin_frame();
        if (is_split_screen() != 0) {
            TCameraCtrl::set_mode(0);
            get_fog_ctrl__16TKeyBoardControlFv();
            if ((void *) camera_ctrl_instance != NULL) {
                ((VObj_18_4a87b2 *)(camera_ctrl_instance))->m1();
            }
            TCameraCtrl::set_split_viewport(1, 0);
            main_task.render();
            TCameraCtrl::set_mode(0x64);
            TCameraCtrl::set_fullscreen_viewport();
        } else {
            controller_stuff();
            ((TMainTask *)(&(*(RecoveredGlobal_801FCD74_main_task *)&main_task).value))->run_tl_camera_tasks();
            main_task.render();
        }
        main_task.render_screen_overlay();
    }
}

s32 forward_to_global_instance__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    if ((void *) selected_character_data != NULL) {
        ((TAdSinglePlyChrSelectGC *)selected_character_data)->append_inventory_item(arg0);
        return 1;
    }
    return 0;
}

s32 TAdSinglePlyChrSelectGC__sub_801FCE6C(void) {
    s32 cw;
    s32 ret;
    u32 obj;
    u32 buf;
    if (get_main_phase() == 0xE || lbl_805D55C0 == 1 || is_technique_ready__8TTecCtrlFv() == 0) {
        return 0xFFFF0000;
    }
    stop_pad_rumble();
    ret = 0xFFFF0000;
    if (selected_character_data != NULL && active_character_save_record != 0 && card_character_save_buffer != NULL) {
        character_save_card_slot = (s8)get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
            TLobby::disconnect_protocol();
            return 0xFFFF0000;
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        if ((obj = find_card_file__15TAdPlayerLoadGCFiPv(character_save_card_slot, (s32 *)&lbl_804C88C0)) != 0) {
            TLobby::disconnect_protocol();
            return obj;
        }
        obj = character_save_file_block_count << 13;
        buf = alloc__22TQuestVmDownLoadServerFv(obj);
        memset(buf, 0, obj);
        while (TAdPlayerLoadGC__sub_801E1944(character_save_card_slot, &lbl_804C88C0, buf, character_save_file_block_count) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                TLobby::disconnect_protocol();
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
        obj = (s32)::operator new(0x1156C);
        if (obj != 0) {
            obj = init_char_slots__23TAdSinglePlyChrSelectGCFi(obj);
        }
        memset(obj, 0, 0x1156C);
        memcpy((void *)obj, (void *)(buf + 0x2048), 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(obj);
        ret = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(
            (A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C((Obj_801FCD3C *)obj),
            (A_801FD8B8 *)get_character_save_record(0xFFFF),
            (C_801FD8B8 *)obj,
            (C_801FD8B8 *)get_instance__23TAdSinglePlyChrSelectGCFv());
        if (ret != 7) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            }
            if (obj != 0) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
            TLobby::disconnect_protocol();
            return ret;
        }
        memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04((Obj_801FCD04 *)card_character_save_buffer),
               TAdSinglePlyChrSelectGC__sub_801FCD04((Obj_801FCD04 *)obj), 0x41C);
        if (buf != 0) {
            TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        }
        if (obj != 0) {
            register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot)) == 0) {
            update_play_time__23TAdSinglePlyChrSelectGCFv();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C((Obj_801FCD3C *)card_character_save_buffer), (void *)active_character_save_record, 0x2370);
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
            encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(card_character_save_buffer);
            save_character_file__23TAdSinglePlyChrSelectGCFi(1);
            while (TAdSinglePlyChrSelectGC__sub_801FDA4C() != 0) {
                run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    TLobby::disconnect_protocol();
                    return 0xFFFF0000;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
                render_tick();
            }
            card_load_sequence_state = 6;
            while (TAdPlayerLoadGC::get_instance() != 0) {
                run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    TLobby::disconnect_protocol();
                    return 0xFFFF0000;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
                render_tick();
            }
            return 7;
        }
    }
    return ret;
}

s32 load_character_from_card__23TAdSinglePlyChrSelectGCFv(void) {
    s32 cw;
    s32 ret;
    u32 obj;
    u32 buf;
    if (get_main_phase() == 0xE || lbl_805D55C0 == 1 || is_technique_ready__8TTecCtrlFv() != 0 ||
        fn_80203284() == 1 || TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        return 0xFFFF0000;
    }
    stop_pad_rumble();
    ret = 0xFFFF0000;
    if (selected_character_data != NULL && active_character_save_record != 0 && card_character_save_buffer != NULL) {
        character_save_card_slot = (s8)get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0xFFFF0000;
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        if ((obj = find_card_file__15TAdPlayerLoadGCFiPv(character_save_card_slot, (s32 *)&lbl_804C88C0)) != 0) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return obj;
        }
        obj = character_save_file_block_count << 13;
        buf = alloc__22TQuestVmDownLoadServerFv(obj);
        memset(buf, 0, obj);
        while (TAdPlayerLoadGC__sub_801E1944(character_save_card_slot, &lbl_804C88C0, buf, character_save_file_block_count) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
        obj = (s32)::operator new(0x1156C);
        if (obj != 0) {
            obj = init_char_slots__23TAdSinglePlyChrSelectGCFi(obj);
        }
        memset(obj, 0, 0x1156C);
        memcpy((void *)obj, (void *)(buf + 0x2048), 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(obj);
        ret = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(
            (A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C((Obj_801FCD3C *)obj),
            (A_801FD8B8 *)get_character_save_record(0xFFFF),
            (C_801FD8B8 *)obj,
            (C_801FD8B8 *)get_instance__23TAdSinglePlyChrSelectGCFv());
        if (ret != 7) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            }
            if (obj != 0) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return ret;
        }
        if (((A_801FD8B8 *)active_character_save_record)->f14 != ((A_801FD8B8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C((Obj_801FCD3C *)obj))->f14) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            }
            if (obj != 0) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 2;
        }
        if (buf != 0) {
            TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        }
        if (obj != 0) {
            register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot)) == 0) {
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            update_play_time__23TAdSinglePlyChrSelectGCFv();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD04((Obj_801FCD04 *)card_character_save_buffer), selected_character_data, 0x41C);
            memcpy(TAdSinglePlyChrSelectGC__sub_801FCD3C((Obj_801FCD3C *)card_character_save_buffer), (void *)active_character_save_record, 0x2370);
            *(s32 *)((s8 *)(TAdSinglePlyChrSelectGC__sub_801FCD04((Obj_801FCD04 *)card_character_save_buffer)) + 0x36C) = 0;
            chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = get_field_118__22TAdEnterSerialAccessGCFv();
            encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(card_character_save_buffer);
            save_character_file__23TAdSinglePlyChrSelectGCFi(1);
            ret = TAdSinglePlyChrSelectGC__sub_801FDA4C();
            if (ret == 0) {
                card_load_sequence_state = 6;
            }
            for (;;) {
                run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
                if (TAdPlayerLoadGC::get_instance() == 0) {
                    break;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
                render_tick();
            }
        }
    }
    return ret;
}

s32 all_players_loaded__23TAdSinglePlyChrSelectGCFv(void) {
    s32 i;
    u32 v;
    if (card_character_save_buffer != 0) {
        for (i = 0; i < 7; i++) {
            v = card_character_save_buffer[i].f428;
            if (v != 0 && v + 0x5DFB0000 != 0xB064) return 0;
        }
    }
    return 1;
}

void refresh_char_slots__23TAdSinglePlyChrSelectGCFv(void) {
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

void init_fresh_character_slot(s32 arg0) {
    init_new_character_data((*(Ent_801FD728 * *)&card_character_save_buffer)[arg0].a);
    ((TAdSinglePlyChrSelectGC *)((*(Ent_801FD728 * *)&card_character_save_buffer)[arg0].b))->init_char_slot_record();
}

s32 TAdPlayerLoadGC__sub_801FD770(void) {
    u8 buf[8];
    s32 i;
    if (card_character_save_buffer == 0) return 0;
    if (init_and_register__23TAdSinglePlyChrSelectGCFi((s32)card_character_save_buffer) == 0) return 1;
    TAdPlayerLoadGC::reset_load_state((void *)0, (void *)buf);
    for (i = 0; i < 8; i++) {
        u8 b = buf[i];
        u8 a = ((u8 *)system_save_payload)[i + 0x110];
        if (a != b) return 1;
    }
    if (((TAdSinglePlyChrSelectGC *)card_character_save_buffer)->has_valid_slot() != 0) return 5;
    return 7;
}

s32 TAdPlayerLoadGC__sub_801FD814(void) {
    u8 buf[8];
    s32 i;
    u32 p = secondary_card_character_save_buffer;
    if (p == 0) return 0;
    if (init_and_register__23TAdSinglePlyChrSelectGCFi((s32)p) == 0) return 1;
    TAdPlayerLoadGC::reset_load_state((void *)1, (void *)buf);
    for (i = 0; i < 8; i++) {
        u8 b = buf[i];
        u8 a = secondary_card_system_save_payload[i + 0x110];
        if (a != b) return 1;
    }
    if (((TAdSinglePlyChrSelectGC *)secondary_card_character_save_buffer)->has_valid_slot() != 0) return 5;
    return 7;
}

s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(A_801FD8B8 *a, A_801FD8B8 *b, C_801FD8B8 *c, C_801FD8B8 *d) {
    if (a == NULL || b == NULL) return 0;
    if (a->f14 > b->f14) return 2;
    if (a->f4 != b->f4) return 4;
    if (a->f8 != 0xA205B064 || b->f8 != 0xA205B064) return 5;
    return c->f11564 != d->f11564 ? 6 : 7;
}

void setup__23TAdSinglePlyChrSelectGCFi(int a0) { card_load_channel = a0; TAdSinglePlyChrSelectGC::set_quest_download_server((int)a0); lbl_805D49B4 = 1; draw_window_bg__23TAdSinglePlyChrSelectGCFllll((void*)card_load_channel, lbl_804C89BC, (void*)guild_card_save_file_buffer, (void*)guild_card_save_file_block_count); }

extern s32 pso_system_card_filename[];
extern u32 system_save_payload;
extern s32 system_save_card_channel;

int TAdSinglePlyChrSelectGC__sub_801FD990(s32 a0) {
    system_save_card_channel = a0;
    lbl_805D49B4 = 1;
    return draw_window_bg__23TAdSinglePlyChrSelectGCFllll((void *)a0, ((s32 *)&pso_system_card_filename), (void *)system_save_file_buffer, (void *)system_save_file_block_count);
}

s32 pso_system_load_gc(void) {
    s32 var_r31;

    var_r31 = 0xFFFF0000;
    if (((u32) system_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        var_r31 = find_card_file__15TAdPlayerLoadGCFiPv(system_save_card_channel, pso_system_card_filename);
        if (var_r31 == 0) {
            if (try_confirm_selection__23TAdSinglePlyChrSelectGCFv() != 0) {
                var_r31 = TAdSinglePlyChrSelectGC__sub_801FD990(system_save_card_channel);
                if (var_r31 == 0) {
                    TAdSinglePlyChrSelectGC::set_player_index(0xF);
                }
            }
        }
    }
    return var_r31;
}
typedef char RecoveredGlobal_801FDA4C_lbl_804C88C0_size[sizeof(RecoveredGlobal_801FDA4C_lbl_804C88C0) == 0x54 ? 1 : -1];
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void) {
    s32 var_r0;
    s8 temp_r3;
    temp_r3 = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    var_r0 = -1;
    character_save_card_slot = (s32) temp_r3;
    if (temp_r3 < 2) {
        TAdSinglePlyChrSelectGC::set_quest_download_server((int)((int) ((s32) temp_r3)));
        (*(s32 *)&lbl_805D49B4) = 1;
        var_r0 = ((s32)draw_window_bg__23TAdSinglePlyChrSelectGCFllll((void*)character_save_card_slot, (void*)((void *)&lbl_804C88C0.value), (void*)character_save_file_buffer, (void*)character_save_file_block_count));
    }
    return var_r0;
}
typedef char RecoveredGlobal_801FDAAC_lbl_804C88C0_size[sizeof(RecoveredGlobal_801FDAAC_lbl_804C88C0) == 0x54 ? 1 : -1];
s32 TAdSinglePlyChrSelectGC__sub_801FDAAC(void) {
    s32 var_r4;
    s8 temp_r3;
    temp_r3 = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    var_r4 = -1;
    character_save_card_slot = (s32) temp_r3;
    if (temp_r3 < 2) {
        TAdSinglePlyChrSelectGC::set_quest_download_server((int) ((s32) temp_r3));
        (*(s32 *)&lbl_805D49B4) = 1;
        var_r4 = ((s32)draw_window_bg__23TAdSinglePlyChrSelectGCFllll((void*)character_save_card_slot, (void*)((void *) (&(*(RecoveredGlobal_801FDAAC_lbl_804C88C0 *)&lbl_804C88C0).value)), (void*)character_save_file_buffer, (void*)character_save_file_block_count));
    }
    card_load_sequence_state = 0x13;
    return var_r4;
}

}

}

namespace P801FDB14 {

struct RecoveredGlobal_801FDC14_lbl_804C88C0 {
    s32 value;
    u8 remaining[0x50];
};

struct RecoveredGlobal_801FE3E4_lbl_805137C8 {
    s32 value;
    u8 remaining[0xC];
};

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
s32 find_card_file__15TAdPlayerLoadGCFiPv(int, void *);
extern unsigned char lbl_804C88C0[];
extern int lbl_805D49B4;
extern int character_save_file_buffer;
void TAdSinglePlyChrSelectGC__sub_801FDC14(void);
s32 is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(void *, void *);
extern RecoveredGlobal_801FE3E4_lbl_805137C8 lbl_805137C8;
extern u32 secondary_card_character_save_buffer;
s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 arg0);
s32 find_card_file__15TAdPlayerLoadGCFiPv(int, void *);
extern unsigned char pso_system_card_filename[];
extern int lbl_805D49B4;
extern int system_save_file_buffer;
void load_pso_system_slot__23TAdSinglePlyChrSelectGCFv(void);
extern u32 card_character_save_buffer;
void clear_entry__23TAdSinglePlyChrSelectGCFi(s32 i);
extern u32 secondary_card_character_save_buffer;
void clear_slot_entry__23TAdSinglePlyChrSelectGCFi(s32 i);
s32 find_card_file__15TAdPlayerLoadGCFiPv(int, void *);
extern unsigned char pso_system_card_filename[];
extern int lbl_805D49B4;
extern s32 system_save_card_channel;
extern int system_save_file_buffer;
s32 load_pso_system__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FE380(P_801FE380 *arg0, s32 arg1, P_801FE380 *arg2, s32 arg3);
void *TAdSinglePlyChrSelectGC__sub_80202B1C(void *, s32);
s32 copy_character_to_slot__23TAdSinglePlyChrSelectGCFUiiUii(u32 arg0, s32 arg1, u32 arg2, s32 arg3);
s32 TAdSinglePlyChrSelectGC__sub_80076D9C(s32 arg0, s32 arg1);
S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *arg0, S_801FE010 *arg1);
s32 check_slot_swap_allowed__23TAdSinglePlyChrSelectGCFPviPvi(E_801FDDAC *arg0, s32 arg1, E_801FDDAC *arg2, s32 arg3);
s32 is_same_slot_entry__23TAdSinglePlyChrSelectGCFPviPvi(E_801FDE14 *arg0, s32 arg1, E_801FDE14 *arg2, s32 arg3);
void copy_player_data__9TProtocolFPvPv();
S_801FE010 *assign_char_data__23TAdSinglePlyChrSelectGCFPvPv(S_801FE010 *arg0, S_801FE010 *arg1);
void *copy_char_slot_data__23TAdSinglePlyChrSelectGCFPvPv(void *a0, void *a1);
void *memset(void *, int, unsigned long);
extern u32 card_character_save_buffer;
void clear_slot_body__23TAdSinglePlyChrSelectGCFi(s32 i);
s32 check_page_cross__23TAdSinglePlyChrSelectGCFiiii(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void open_confirm_window__23TAdSinglePlyChrSelectGCFv(void);
s32 swap_characters__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 try_move_char__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);
int draw_window_bg__23TAdSinglePlyChrSelectGCFllll(void*, void*, void*, void*);
void increment_counters__23TAdSinglePlyChrSelectGCFv(void);

    extern unsigned char lbl_804C88C0[];
    extern int lbl_805D49B4;
    extern int card_load_sequence_state;
    extern int character_save_file_block_count;
    extern int character_save_file_buffer;
void open_confirm_window__23TAdSinglePlyChrSelectGCFv(void) { lbl_805D49B4 = 1; draw_window_bg__23TAdSinglePlyChrSelectGCFllll((void*)1, lbl_804C88C0, (void*)character_save_file_buffer, (void*)character_save_file_block_count); card_load_sequence_state = 18; }

extern u32 card_character_save_buffer;
extern u32 secondary_card_character_save_buffer;

typedef char RecoveredGlobal_801FDC14_lbl_804C88C0_size[sizeof(RecoveredGlobal_801FDC14_lbl_804C88C0) == 0x54 ? 1 : -1];

s32 load_pso_system__23TAdSinglePlyChrSelectGCFi(s32 chan) {
    s32 r = -1;
    system_save_card_channel = chan;
    if (chan >= 0 && chan <= 7) {
        r = find_card_file__15TAdPlayerLoadGCFiPv(chan, (void *)(((u8 *)&pso_system_card_filename)));
        if (r == 0) {
            (*(s32 *)&lbl_805D49B4) = 1;
            r = ((s32)((TAdSinglePlyChrSelectGC *)system_save_card_channel)->load_player_slot((int)(((u8 *)&pso_system_card_filename)), (int)((void *)(*(s32 *)&system_save_file_buffer))));
        }
    }
    return r;
}

void load_pso_system_slot__23TAdSinglePlyChrSelectGCFv(void) {
    if (find_card_file__15TAdPlayerLoadGCFiPv(1, (void *) (&(*(RecoveredGlobal_801FDC14_lbl_804C88C0 *)&pso_system_card_filename).value)) == 0) {
        (*(s32 *)&lbl_805D49B4) = 1;
        ((TAdSinglePlyChrSelectGC *)1)->load_player_slot((int)((void *) (&(*(RecoveredGlobal_801FDC14_lbl_804C88C0 *)&pso_system_card_filename).value)), (int)((void *) ((*(s32 *)&system_save_file_buffer))));
    }
}

void TAdSinglePlyChrSelectGC__sub_801FDC14(void) {
    if (find_card_file__15TAdPlayerLoadGCFiPv(1, (void *) (&(*(RecoveredGlobal_801FDC14_lbl_804C88C0 *)&lbl_804C88C0).value)) == 0) {
        (*(s32 *)&lbl_805D49B4) = 1;
        ((TAdSinglePlyChrSelectGC *)1)->load_player_slot((int)((void *) (&(*(RecoveredGlobal_801FDC14_lbl_804C88C0 *)&lbl_804C88C0).value)), (int)((void *) ((*(s32 *)&character_save_file_buffer))));
    }
}

s32 swap_characters__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 i) {
    s32 result;
    if ((arg0 >= 7) || (i >= 7)) {
        return 0;
    }
    if ((u32) card_character_save_buffer == 0U) {
        goto return_zero;
    }
    if ((u32) secondary_card_character_save_buffer == 0U) {
        goto return_zero;
    }
    if (check_page_cross__23TAdSinglePlyChrSelectGCFiiii(secondary_card_character_save_buffer, arg0, card_character_save_buffer, i) == 0) {
        goto return_zero;
    }
    increment_counters__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC__sub_801FE380((P_801FE380 *)(secondary_card_character_save_buffer), arg0, (P_801FE380 *)(card_character_save_buffer), i);
    return 1;
return_zero:
    return 0;
}

extern u32 card_character_save_buffer;
extern u32 secondary_card_character_save_buffer;

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
    if ((card_character_save_buffer != 0U) && (secondary_card_character_save_buffer != 0U) && (check_page_cross__23TAdSinglePlyChrSelectGCFiiii(card_character_save_buffer, arg0, secondary_card_character_save_buffer, arg1) != 0)) {
        increment_counters__23TAdSinglePlyChrSelectGCFv();
        copy_character_to_slot__23TAdSinglePlyChrSelectGCFUiiUii(card_character_save_buffer, arg0, secondary_card_character_save_buffer, arg1);
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

s32 check_page_cross__23TAdSinglePlyChrSelectGCFiiii(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if ((arg2 >= 4) && (arg4 <= 3)) {
        return check_slot_swap_allowed__23TAdSinglePlyChrSelectGCFPviPvi((E_801FDDAC *)(arg1), arg2, (E_801FDDAC *)(arg3), arg4);
    }
    if ((arg2 <= 3) && (arg4 >= 4)) {
        return is_same_slot_entry__23TAdSinglePlyChrSelectGCFPviPvi((E_801FDE14 *)(arg1), arg2, (E_801FDE14 *)(arg3), arg4);
    }
    return 0;
}
typedef char RecoveredGlobal_801FE3E4_lbl_805137C8_size[sizeof(RecoveredGlobal_801FE3E4_lbl_805137C8) == 0x10 ? 1 : -1];

s32 copy_character_to_slot__23TAdSinglePlyChrSelectGCFUiiUii(u32 arg0, s32 arg1, u32 arg2, s32 arg3) {
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
    copy_char_slot_data__23TAdSinglePlyChrSelectGCFPvPv(src[arg1].chr, chr);
    for (i = 0; i < 30; i++) {
        ((TAdSinglePlyChrSelectGC *)(TAdSinglePlyChrSelectGC__sub_80202B1C(chr, i)))->clear_inventory_slot();
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

#define arg0 ((P_801FDFB8 *)a0)
#define arg1 ((P_801FDFB8 *)a1)
void *copy_char_slot_data__23TAdSinglePlyChrSelectGCFPvPv(void *a0, void *a1) {
    copy_player_data__9TProtocolFPvPv();
    assign_char_data__23TAdSinglePlyChrSelectGCFPvPv((S_801FE010 *)arg0->a, (S_801FE010 *)arg1->a);
    arg0->f278C = arg1->f278C;
    arg0->f2794 = arg1->f2794;
    return a0;
}
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
        TAdSinglePlyChrSelectGC__sub_80076D9C((s32)s, (s32)t);
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

void clear_slot_entry__23TAdSinglePlyChrSelectGCFi(s32 i) {
    if ((*(Ent_801FE304 * *)&secondary_card_character_save_buffer) == 0) return;
    if (i >= 4) return;
    (*(Ent_801FE304 * *)&secondary_card_character_save_buffer)[i].a = 0;
    (*(Ent_801FE304 * *)&secondary_card_character_save_buffer)[i].b = 0;
}

void clear_slot_body__23TAdSinglePlyChrSelectGCFi(s32 i) {
    if ((*(Ent_801FE338 **)&card_character_save_buffer) == 0) return;
    if (i < 4) return;
    memset((*(Ent_801FE338 **)&card_character_save_buffer)[i].body, 0, 0x2798);
}

s32 TAdSinglePlyChrSelectGC__sub_801FE380(P_801FE380 *arg0, s32 arg1, P_801FE380 *arg2, s32 i) {
    arg2[i].f2790 = 0;
    arg2[i].f2794 = 0;
    copy_char_slot_data__23TAdSinglePlyChrSelectGCFPvPv(arg0[arg1].a, arg2[i].a);
    clear_slot_body__23TAdSinglePlyChrSelectGCFi(i);
    return 1;
}

s32 *TAdSinglePlyChrSelectGC__sub_801FE3E4(u32 i) {
    u8 *temp_r4;
    if (i >= 7U) {
        return NULL;
    }
    if (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi((void *) ((*(s32 *)&secondary_card_character_save_buffer)), (void *)i) == 0) {
        return NULL;
    }
    temp_r4 = (u8 *)((*(s32 *)&secondary_card_character_save_buffer) + (i * 0x2798));
    *(s32 *)((s8 *)&lbl_805137C8.value + 0) = (s32)(temp_r4 + 0x374);
    *(s32 *)((s8 *)&lbl_805137C8.value + 4) = (s32) *(s32 *)((s8 *)temp_r4 + 0x368);
    *(s32 *)((s8 *)&lbl_805137C8.value + 8) = (s32) *(s32 *)((s8 *)temp_r4 + 0x2790);
    *(s32 *)((s8 *)&lbl_805137C8.value + 0xC) = (s32) *(s32 *)((s8 *)temp_r4 + 0x42C);
    return &lbl_805137C8.value;
}

}

}

namespace P801FE468 {

struct RecoveredGlobal_801FE4BC_lbl_805137C8 {
    s32 value;
    u8 remaining[0xC];
};

struct Req_801FE5F8 {
    s32 slot[4];
    s32 dest[4];
    u32 count;
};

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
s32 is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(s32, s32);
extern s32 secondary_card_character_save_buffer;
s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 arg0);
s32 is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(s32, s32);
extern RecoveredGlobal_801FE4BC_lbl_805137C8 lbl_805137C8;
extern u32 card_character_save_buffer;
s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 arg0);
void *memcpy(void *, const void *, u32);
void *memset(void *, int, u32);
extern int chr_select_buffer_ptr_table[];
extern u8 chr_select_request_buffer[];
extern u32 card_character_save_buffer;
void copy_selected_characters__23TAdSinglePlyChrSelectGCFPv(Req_801FE5F8 *arg0);
void *memcpy(void *, const void *, u32);
extern int chr_select_buffer_ptr_table[];
extern u8 chr_select_request_buffer[];
extern u32 card_character_save_buffer;
void copy_chr_slots_from_request__23TAdSinglePlyChrSelectGCFv(void);
void copy_request__23TAdSinglePlyChrSelectGCFPvPv(void *arg0, void *arg1);
struct Ent_801FE468_801FBF54 { char pad4[4]; char body[0x2798 - 4]; };

int get_split_screen_character_save_record(int a0);
int get_char_table_entry__23TAdSinglePlyChrSelectGCFi(int a0);
s32 get_entry__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
s32 load_player__23TAdSinglePlyChrSelectGCFv(void);
s32 load_player_data__23TAdSinglePlyChrSelectGCFv(void);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, s32 *);
struct RecoveredGlobal_801FE75C_lbl_804C88C0 {
    s32 value;
    u8 remaining[0x50];
};
typedef char RecoveredGlobal_801FE75C_lbl_804C88C0_size[sizeof(RecoveredGlobal_801FE75C_lbl_804C88C0) == 0x54 ? 1 : -1];
extern RecoveredGlobal_801FE75C_lbl_804C88C0 lbl_804C88C0;
extern s32 lbl_805D49B4;
extern s32 character_save_card_slot;
extern s32 character_save_file_buffer;
s32 load_chr_select_slot__23TAdSinglePlyChrSelectGCFv(void);
s32 is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(s32, s32);
s32 check_ready__23TAdSinglePlyChrSelectGCFv();
u8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
s32 setup__23TAdSinglePlyChrSelectGCFi(s32);

extern s32 secondary_card_character_save_buffer;

s32 get_entry__23TAdSinglePlyChrSelectGCFi(s32 i) {
    if (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(secondary_card_character_save_buffer, i) != 0) {
        return (s32) &((struct Ent_801FE468_801FBF54 *) secondary_card_character_save_buffer)[i].body[0];
    }
    return 0;
}

    extern int chr_select_buffer_ptr_table[];

typedef char RecoveredGlobal_801FE4BC_lbl_805137C8_size[sizeof(RecoveredGlobal_801FE4BC_lbl_805137C8) == 0x10 ? 1 : -1];
s32 *TAdSinglePlyChrSelectGC__sub_801FE4BC(u32 i) {
    u8 *temp_r4;
    if (i >= 7U) {
        return NULL;
    }
    if (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi((s32)((void *) ((*(s32 *)&card_character_save_buffer))), (s32)i) == 0) {
        return NULL;
    }
    temp_r4 = (u8 *)((*(s32 *)&card_character_save_buffer) + (i * 0x2798));
    *(s32 *)((s8 *)&lbl_805137C8.value + 0) = (s32)(temp_r4 + 0x374);
    *(s32 *)((s8 *)&lbl_805137C8.value + 4) = (s32) *(s32 *)((s8 *)temp_r4 + 0x368);
    *(s32 *)((s8 *)&lbl_805137C8.value + 8) = (s32) *(s32 *)((s8 *)temp_r4 + 0x2790);
    return &lbl_805137C8.value;
}

void copy_chr_slots_from_request__23TAdSinglePlyChrSelectGCFv(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        Req_801FE5F8 *r = (Req_801FE5F8 *)chr_select_request_buffer;
        if (r->slot[i] < 7 && r->slot[i] >= 0) {
            memcpy(((Slot_801FE5F8 *)card_character_save_buffer)[r->slot[i]].chr, (void *)chr_select_buffer_ptr_table[r->dest[i]], 0x41C);
            memcpy(((Slot_801FE5F8 *)card_character_save_buffer)[r->slot[i]].inv, (void *)chr_select_buffer_ptr_table[r->dest[i] + 4], 0x2370);
        }
    }
}

void copy_selected_characters__23TAdSinglePlyChrSelectGCFPv(Req_801FE5F8 *arg0) {
    s32 i;
    if (arg0->count <= 4) {
        copy_request__23TAdSinglePlyChrSelectGCFPvPv(chr_select_request_buffer, arg0);
        for (i = 0; i < 4; i++) {
            memset((void *)chr_select_buffer_ptr_table[i], 0, 0x41C);
            memset((void *)chr_select_buffer_ptr_table[i + 4], 0, 0x2370);
        }
        for (i = 0; i < 4; i++) {
            if (arg0->slot[i] < 7 && arg0->dest[i] != -1) {
                memcpy((void *)chr_select_buffer_ptr_table[arg0->dest[i]], ((Slot_801FE5F8 *)card_character_save_buffer)[arg0->slot[i]].chr, 0x41C);
                memcpy((void *)chr_select_buffer_ptr_table[arg0->dest[i] + 4], ((Slot_801FE5F8 *)card_character_save_buffer)[arg0->slot[i]].inv, 0x2370);
            }
        }
    }
}

void copy_request__23TAdSinglePlyChrSelectGCFPvPv(void *arg0, void *arg1) {
    *(Req_801FE5F8 *)arg0 = *(Req_801FE5F8 *)arg1;
}

s32 load_chr_select_slot__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r0;
    s8 temp_r3;
    temp_r3 = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    var_r0 = -1;
    character_save_card_slot = (s32) temp_r3;
    if ((temp_r3 >= 0) && (temp_r3 <= 7)) {
        var_r0 = find_card_file__15TAdPlayerLoadGCFiPv((s32) temp_r3, (s32 *) &lbl_804C88C0.value);
        if (var_r0 == 0) {
            TAdSinglePlyChrSelectGC::set_quest_download_server(character_save_card_slot);
            lbl_805D49B4 = 1;
            var_r0 = ((TAdSinglePlyChrSelectGC *)character_save_card_slot)->load_player_slot((int)((s32) &lbl_804C88C0.value), (int)character_save_file_buffer);
        }
    }
    return var_r0;
}

int get_split_screen_character_save_record(int a0) {  return chr_select_buffer_ptr_table[a0 + 4]; }

    extern int chr_select_buffer_ptr_table[];
int get_char_table_entry__23TAdSinglePlyChrSelectGCFi(int a0) {  return chr_select_buffer_ptr_table[a0]; }

extern u32 card_character_save_buffer;

s32 TAdSinglePlyChrSelectGC__sub_801FE800(u32 i) {
    if (i >= 7U) {
        return 0;
    }
    if (((u32) (*(u32 *)&secondary_card_character_save_buffer) != 0U) && (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi((s32) (*(u32 *)&secondary_card_character_save_buffer), (s32) i) != 0)) {
        return 1;
    }
    return 0;
}

s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi(u32 arg0) {
    u32 i = arg0;
    u32 var_r3;
    if (i >= 7U) {
        return 0;
    }
    var_r3 = card_character_save_buffer;
    if ((var_r3 != 0U) && (is_entry_valid__23TAdSinglePlyChrSelectGCFPvi(var_r3, i) != 0)) {
        return 1;
    }
    return 0;
}

extern s32 lbl_804C89BC[];
extern u32 guild_card_save_payload;
extern s32 card_load_channel;

s32 load_player_data__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r31;

    var_r31 = 0xFFFF0000;
    if (((u32) guild_card_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0) && (((TAdPlayerLoadGC *)card_load_channel)->probe_and_check_card() != 0)) {
        var_r31 = find_card_file__15TAdPlayerLoadGCFiPv(card_load_channel, lbl_804C89BC);
        if ((var_r31 == 0) && (check_ready__23TAdSinglePlyChrSelectGCFv() != 0)) {
            var_r31 = setup__23TAdSinglePlyChrSelectGCFi(card_load_channel);
            if (var_r31 == 0) {
                TAdSinglePlyChrSelectGC::set_player_index(0xC);
            }
        }
    }
    return var_r31;
}

extern s32 lbl_804C89BC[];
extern u32 guild_card_save_payload;
extern s32 card_load_sequence_state;
extern s32 card_load_channel;

s32 load_player__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r31;
    s32 var_r3;
    s8 temp_r3;

    TAdSinglePlyChrSelectGC::set_save_slot(0);
    var_r31 = 0xFFFF0000;
    if (((u32) guild_card_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        temp_r3 = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
        card_load_channel = temp_r3;
        var_r31 = TAdPlayerLoadGC__sub_801E1B50(card_load_channel);
        if (var_r31 == 0) {
            var_r31 = find_card_file__15TAdPlayerLoadGCFiPv(card_load_channel, lbl_804C89BC);
            if (var_r31 == 0) {
                var_r3 = TAdSinglePlyChrSelectGC::load_player_by_slot(card_load_channel);
                if (var_r3 == 0) {
                    card_load_sequence_state = 0xD;
                }
                return var_r3;
            }
        }
    }
    return var_r31;
}

}

}

namespace P801FE9D0 {

extern "C" {

s32 load_pso_system(void);
s32 load_system_file(s32 arg0);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, s32 *);
s32 load_pso_system__23TAdSinglePlyChrSelectGCFi(s32);
s32 load_pso_system_slot__23TAdSinglePlyChrSelectGCFv();
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();

extern s32 pso_system_card_filename[];
extern u32 system_save_payload;
extern s32 card_load_sequence_state;
extern s32 system_save_card_channel;

s32 load_system_file(s32 arg0) {
    s32 var_r31;
    s32 var_r3;
    s32 temp_r3;

    var_r31 = 0xFFFF0000;
    if (((u32) system_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        temp_r3 = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
        system_save_card_channel = temp_r3;
        var_r31 = TAdPlayerLoadGC__sub_801E1B50(temp_r3);
        if (var_r31 == 0) {
            var_r31 = find_card_file__15TAdPlayerLoadGCFiPv(system_save_card_channel, pso_system_card_filename);
            if (var_r31 == 0) {
                var_r3 = load_pso_system__23TAdSinglePlyChrSelectGCFi(system_save_card_channel);
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
    var_r3 = var_r31;
    return var_r3;
}

extern s32 pso_system_card_filename[];
extern u32 secondary_card_system_save_payload;
extern s32 card_load_sequence_state;

s32 load_pso_system(void) {
    s32 var_r31;
    s32 var_r3;

    var_r31 = 0xFFFF0000;
    if (((u32) secondary_card_system_save_payload != 0U) && (TAdPlayerLoadGC::get_instance() == 0)) {
        var_r31 = TAdPlayerLoadGC__sub_801E1B50(1);
        if (var_r31 == 0) {
            var_r31 = find_card_file__15TAdPlayerLoadGCFiPv(1, pso_system_card_filename);
            if (var_r31 == 0) {
                var_r3 = load_pso_system_slot__23TAdSinglePlyChrSelectGCFv();
                if (var_r3 == 0) {
                    card_load_sequence_state = 0x16;
                }
                return var_r3;
            }
        }
    }
    var_r3 = var_r31;
    return var_r3;
}

}

}

namespace P801FEAFC {

struct RecoveredGlobal_801FEBBC_lbl_80513904 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 TAdSinglePlyChrSelectGC__sub_801FDC14(int);
extern RecoveredGlobal_801FEBBC_lbl_80513904 char_select_date_stamp;
extern u32 secondary_card_character_save_buffer;
extern s32 card_load_sequence_state;
s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void);
s32 load_pso_system(void);
extern s32 card_load_followup_pending;
void check_system_load_result__23TAdSinglePlyChrSelectGCFv(void);
s32 check_ready__23TAdSinglePlyChrSelectGCFv(void);
s32 try_confirm_selection__23TAdSinglePlyChrSelectGCFv(void);
void TAdSinglePlyChrSelectGC__sub_801FFF14(void);
void create_instance__23TAdSinglePlyChrSelectGCFv(void);

extern u32 guild_card_save_payload;
extern u32 guild_card_save_file_buffer;

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

extern u32 system_save_payload;
extern u32 system_save_file_buffer;

s32 try_confirm_selection__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r3;

    stop_pad_rumble();
    var_r3 = 0;
    if (((u32) system_save_payload != 0U) && ((u32) system_save_file_buffer != 0U)) {
        create_instance__23TAdSinglePlyChrSelectGCFv();
        var_r3 = 1;
    }
    return var_r3;
}
typedef char RecoveredGlobal_801FEBBC_lbl_80513904_size[sizeof(RecoveredGlobal_801FEBBC_lbl_80513904) == 0xC ? 1 : -1];

void check_system_load_result__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = load_pso_system();
    card_load_followup_pending = 0;
    if (r == 0) card_load_followup_pending = 1;
}

s32 TAdSinglePlyChrSelectGC__sub_801FEBBC(void) {
    s32 var_r31;
    var_r31 = 0xFFFF0000;
    if (((u32) secondary_card_character_save_buffer != 0U) && (TAdPlayerLoadGC::get_instance() == 0x16)) {
        var_r31 = TAdPlayerLoadGC__sub_801E1B50(1);
        if (var_r31 == 0) {
            var_r31 = TAdSinglePlyChrSelectGC__sub_801FDC14(1);
            if (var_r31 == 0) {
                card_load_sequence_state = 0x14;
                getDateStamp((DateStamp *)(&char_select_date_stamp.value));
            }
        }
    }
    return var_r31;
}

}

}

namespace P801FEC34 {

struct RecoveredGlobal_801FF200_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

struct VBase_801FEE14 { u8 pad[0x18]; };

struct Win_801FEE14 : VBase_801FEE14 {
    virtual ~Win_801FEE14();
    virtual void v1();
};

struct V2_801FEE14 { f32 x, y; };

extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
s32 save_character_file__23TAdSinglePlyChrSelectGCFi(int);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
extern RecoveredGlobal_801FF200_lbl_80513910 chr_select_serial_seeds;
extern u32 card_character_save_buffer;
extern s32 card_load_sequence_state;
s32 encrypt_save_and_write__23TAdSinglePlyChrSelectGCFv(void);
s32 get_localized_text_entry(s32, s32);
s8 func_801A5E54__Fv(void);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void render_frame__23TAdSinglePlyChrSelectGCFv(void);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
void increment_counter__23TAdSinglePlyChrSelectGCFv(void);
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
s32 save_character_file__23TAdSinglePlyChrSelectGCFi(int);
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv(void);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
void TLobby__sub_80269C90(void);
void TLobby__sub_80269CA4(s32);
Win_801FEE14 *create_message_window__6TLobbyFllUls(V2_801FEE14 *, V2_801FEE14 *, s32, s32);
void TAdSinglePlyChrSelectGC__sub_8033B9EC(void);
s32 TAdSinglePlyChrSelectGC__sub_8033B9F8(Win_801FEE14 *);
Win_801FEE14 *create_check_memory_card__23TAdSinglePlyChrSelectGCFPvPvPv(void *, s32, s32);
void func_803DCDFC__Fv(void);
extern V2_801FEE14 lbl_8044A7D0[];
extern V2_801FEE14 lbl_8044A7D8[];
extern V2_801FEE14 lbl_804C8A44[];
extern u8 controller_input_state[];
extern RecoveredGlobal_801FF200_lbl_80513910 chr_select_serial_seeds;
extern u32 card_character_save_buffer;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s8 lbl_805D5FB4;
extern f32 lbl_805D5FB8;
extern s8 lbl_805D5FBC;
extern void *tl_01;
extern const f32 lbl_805DC5C0;
extern const f32 lbl_805DC5C4;
extern const f32 lbl_805DC5C8;
s32 save_character_to_card__23TAdSinglePlyChrSelectGCFv(void);
s32 load_selected_char__23TAdSinglePlyChrSelectGCFv(void);
s32 load_selected_character__23TAdSinglePlyChrSelectGCFv(void);
s32 start_load__23TAdSinglePlyChrSelectGCFv(void);
s32 TAdPlayerLoadGC__sub_801E1B50(void*);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 load_chr_select_slot__23TAdSinglePlyChrSelectGCFv();
void clear_load_buffers__23TAdSinglePlyChrSelectGCFv(void);
s32 prepare_save_data__23TAdSinglePlyChrSelectGCFv();
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();

extern s32 char_select_date_stamp[];
extern u32 card_character_save_buffer;
extern u32 selected_character_data;
extern u32 active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;

s32 load_selected_char__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r31;

    character_save_card_slot = (s32) get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    var_r31 = 0xFFFF0000;
    if (((u32) selected_character_data != 0U) && ((u32) active_character_save_record != 0U) && ((u32) card_character_save_buffer != 0U) && (TAdPlayerLoadGC::get_instance() == 0x10) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        var_r31 = TAdPlayerLoadGC__sub_801E1B50((void*)character_save_card_slot);
        if (var_r31 == 0) {
            var_r31 = load_chr_select_slot__23TAdSinglePlyChrSelectGCFv();
            if (var_r31 == 0) {
                card_load_sequence_state = 8;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return var_r31;
}

extern s32 char_select_date_stamp[];
extern u32 card_character_save_buffer;
extern u32 selected_character_data;
extern u32 active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;

s32 load_selected_character__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r31;

    character_save_card_slot = (s32) get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    var_r31 = 0xFFFF0000;
    if (((u32) selected_character_data != 0U) && ((u32) active_character_save_record != 0U) && ((u32) card_character_save_buffer != 0U) && (TAdPlayerLoadGC::get_instance() == 0) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        var_r31 = TAdPlayerLoadGC__sub_801E1B50((void*)character_save_card_slot);
        if (var_r31 == 0) {
            var_r31 = load_chr_select_slot__23TAdSinglePlyChrSelectGCFv();
            if (var_r31 == 0) {
                card_load_sequence_state = 8;
                getDateStamp((DateStamp *)char_select_date_stamp);
            }
        }
    }
    return var_r31;
}

s32 init_buffer();
extern u32 card_character_save_buffer;
extern u32 selected_character_data;
extern u32 active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;

s32 start_load__23TAdSinglePlyChrSelectGCFv(void) {
    character_save_card_slot = (s32) get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    if (((u32) selected_character_data != 0U) && ((u32) active_character_save_record != 0U) && ((u32) card_character_save_buffer != 0U) && (TAdPlayerLoadGC::get_instance() == 0) && ((s32) character_save_card_slot >= 0) && ((s32) character_save_card_slot <= 7)) {
        clear_load_buffers__23TAdSinglePlyChrSelectGCFv();
        init_buffer();
        prepare_save_data__23TAdSinglePlyChrSelectGCFv();
        TAdSinglePlyChrSelectGC__sub_801FDA4C();
        card_load_sequence_state = 6;
        return 7;
    }
    return 0xFFFF0000;
}
typedef char RecoveredGlobal_801FF200_lbl_80513910_size[sizeof(RecoveredGlobal_801FF200_lbl_80513910) == 0x10 ? 1 : -1];

s32 save_character_to_card__23TAdSinglePlyChrSelectGCFv(void) {
    Win_801FEE14 *w;
    s32 result;
    s32 v;
    w = create_check_memory_card__23TAdSinglePlyChrSelectGCFPvPvPv(tl_01, 0, 1);
    if (w == NULL) {
        return 0;
    }
    if (w != NULL) {
        TAdSinglePlyChrSelectGC__sub_8033B9EC();
        while (1) {
            func_803DCDFC__Fv();
            w->v1();
            if (TAdSinglePlyChrSelectGC__sub_8033B9F8(w) != 0) {
                break;
            }
            controller_stuff();
            TLobby::wait_ready_loop();
            render_frame__23TAdSinglePlyChrSelectGCFv();
            if (func_801A5E54__Fv() != 0 || TWindowShortListCtrl__check_controller_button(&controller_input_state[0x20], 8) != 0) {
                if (w != NULL) {
            delete w;
        }
                return 0;
            }
            render_tick();
        }
        if (w != NULL) {
            delete w;
        }
    }
    if (lbl_805D5FB4 == 0) {
        lbl_805D5FB4 = 1;
        lbl_804C8A44[0].x = lbl_805DC5C0 + lbl_8044A7D0[0].x;
        lbl_804C8A44[0].y = lbl_805DC5C4 + (lbl_8044A7D0[0].y + lbl_8044A7D8[0].y);
    }
    if (lbl_805D5FBC == 0) {
        lbl_805D5FBC = 1;
        lbl_805D5FB8 = lbl_8044A7D8[0].x - lbl_805DC5C8;
    }
    if (TAdSinglePlyChrSelectGC::load_save_from_card() == 0) {
        w = create_message_window__6TLobbyFllUls(lbl_8044A7D0, lbl_8044A7D8, 1, 4);
        if (w != NULL) {
            ((TLobby *)w)->send_and_handle(get_localized_text_entry(0x20, 4), 3);
            ((TWindowSubComCard *)w)->reparent_to_main_ctrl();
        }
        ((TWindowMessage *)w)->complete_reveal();
        while (1) {
            func_803DCDFC__Fv();
            controller_stuff();
            TLobby::wait_ready_loop();
            render_frame__23TAdSinglePlyChrSelectGCFv();
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
    increment_counter__23TAdSinglePlyChrSelectGCFv();
    v = get_field_118__22TAdEnterSerialAccessGCFv();
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 4) = v;
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 0) = v;
    encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *)card_character_save_buffer, &chr_select_serial_seeds.value);
    save_character_file__23TAdSinglePlyChrSelectGCFi(1);
    TAdSinglePlyChrSelectGC__sub_801FDA4C();
    card_load_sequence_state = 6;
    while (1) {
        func_803DCDFC__Fv();
        controller_stuff();
        run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
        render_frame__23TAdSinglePlyChrSelectGCFv();
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
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
    w = create_message_window__6TLobbyFllUls(lbl_8044A7D0, lbl_8044A7D8, 1, 4);
    TLobby__sub_80269C90();
    if (w != NULL) {
        if (TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF81 || TAdPlayerLoadGC::get_load_result(0) == 0xFFFFFF83) {
            ((TLobby *)w)->send_and_handle(get_localized_text_entry(0x1C, 1), 3);
        } else {
            ((TLobby *)w)->send_and_handle(get_localized_text_entry(0x20, 5), 3);
        }
        ((TWindowSubComCard *)w)->reparent_to_main_ctrl();
    }
    ((TWindowMessage *)w)->complete_reveal();
    if (result == 0) {
        while (1) {
            func_803DCDFC__Fv();
            controller_stuff();
            TLobby::wait_ready_loop();
            render_frame__23TAdSinglePlyChrSelectGCFv();
            if (func_801A5E54__Fv() != 0 || TWindowShortListCtrl__check_controller_button(&controller_input_state[0x20], 0x60E) != 0) {
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

s32 encrypt_save_and_write__23TAdSinglePlyChrSelectGCFv(void) {
    s32 temp_r3;
    temp_r3 = get_field_118__22TAdEnterSerialAccessGCFv();
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 4) = temp_r3;
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 0) = temp_r3;
    encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *) ((*(s32 *)&card_character_save_buffer)), (void *)&chr_select_serial_seeds.value);
    save_character_file__23TAdSinglePlyChrSelectGCFi(1);
    if (((s32)TAdSinglePlyChrSelectGC__sub_801FDA4C()) != 0) {
        return 0;
    }
    card_load_sequence_state = 6;
    return 1;
}

}

}

namespace P801FF260 {

extern "C" {
s32 load_system_file(s32);
extern s32 card_load_followup_pending;
void load_system_file_flag__23TAdSinglePlyChrSelectGCFv(void);
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 load_system_file(s32);
s32 verify_save_checksum__23TAdSinglePlyChrSelectGCFi(s32);
extern s32 card_load_followup_pending;
u8 load_system_file_blocking__23TAdSinglePlyChrSelectGCFv(void);
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 load_selected_character__23TAdSinglePlyChrSelectGCFv();
s32 apply_loaded_character__23TAdSinglePlyChrSelectGCFi(s32);
extern s32 card_load_followup_pending;
u8 load_character_and_wait__23TAdSinglePlyChrSelectGCFv(void);
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 load_player__23TAdSinglePlyChrSelectGCFv();
s32 load_and_verify_data(s32);
extern s32 card_load_followup_pending;
u8 load_player_and_wait__23TAdSinglePlyChrSelectGCFv(void);
void *get_instance__23TAdSinglePlyChrSelectGCFv();

void increment_counter__23TAdSinglePlyChrSelectGCFv(void) {
    void *temp_r3;

    temp_r3 = get_instance__23TAdSinglePlyChrSelectGCFv();
    if (temp_r3 != NULL) {
        *(s32 *)((s8 *)temp_r3 + 0x11564) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x11564) + 1);
    }
}

extern void *card_character_save_buffer;
extern void *secondary_card_character_save_buffer;

void increment_counters__23TAdSinglePlyChrSelectGCFv(void) {
    if ((void *) card_character_save_buffer != NULL) {
        *(s32 *)((s8 *)card_character_save_buffer + 0x11564) = (s32) (*(s32 *)((s8 *)card_character_save_buffer + 0x11564) + 1);
    }
    if ((void *) secondary_card_character_save_buffer != NULL) {
        *(s32 *)((s8 *)secondary_card_character_save_buffer + 0x11564) = (s32) (*(s32 *)((s8 *)secondary_card_character_save_buffer + 0x11564) + 1);
    }
}
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
        run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    }
    card_load_followup_pending = 0;
    return verify_save_checksum__23TAdSinglePlyChrSelectGCFi(1) == 0;
}
u8 load_character_and_wait__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = load_selected_character__23TAdSinglePlyChrSelectGCFv();
    card_load_followup_pending = 0;
    if (r == 0) {
        card_load_followup_pending = 1;
    } else {
        return 0;
    }
    for (;;) {
        if (TAdPlayerLoadGC::get_instance() == 0) break;
        run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    }
    card_load_followup_pending = 0;
    return apply_loaded_character__23TAdSinglePlyChrSelectGCFi(1) == 0;
}
u8 load_player_and_wait__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = load_player__23TAdSinglePlyChrSelectGCFv();
    card_load_followup_pending = 0;
    if (r == 0) {
        card_load_followup_pending = 1;
    } else {
        return 0;
    }
    for (;;) {
        if (TAdPlayerLoadGC::get_instance() == 0) break;
        run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    }
    card_load_followup_pending = 0;
    return load_and_verify_data(1) == 0;
}

}

}

namespace P801FF464 {

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
s32 is_technique_ready__8TTecCtrlFv();
s32 update_elapsed_time__23TAdSinglePlyChrSelectGCFPv(void *);
s32 get_character_save_record(u32);
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);
s32 try_assign_battle_ctrl__10TObjPlayerFiUs(s32, u16);
s32 TLobby__sub_8030A770(void);
s32 get_character_select_request_buffer();
u32 get_player_by_client_id(s32);
s32 setup_player_battle_ctrls__23TAdSinglePlyChrSelectGCFv(void);
s32 copy_card__17TWindowSubComCardFiPv(s32 arg0, u8 *arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FFCFC(s32 arg0, s32 arg1);
void *memset(void *, int, unsigned long);
extern u32 card_character_save_buffer;
extern u32 selected_character_data;
extern u32 active_character_save_record;
void clear_load_buffers__23TAdSinglePlyChrSelectGCFv(void);
s32 get_main_phase();
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
u32 alloc__22TQuestVmDownLoadServerFv(u32);
s32 is_technique_ready__8TTecCtrlFv();
s32 get_ptr_4__10TObjPlayerFv(void *);
s32 TAdPlayerLoadGC__sub_801E1944(s32, void *, u32, s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, void *);
s32 copy_card_window_data();
s32 register_callback__23TAdSinglePlyChrSelectGCFis(u8 *, s16);
u8 *init_char_slots__23TAdSinglePlyChrSelectGCFi();
u8 *TAdSinglePlyChrSelectGC__sub_801FCD04(u32);
u8 *TAdSinglePlyChrSelectGC__sub_801FCD3C(u32);
s32 render_frame__23TAdSinglePlyChrSelectGCFv();
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(u8 *, s32, u8 *, s32);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 increment_counter__23TAdSinglePlyChrSelectGCFv();
s32 decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(u8 *);
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
s32 save_character_file__23TAdSinglePlyChrSelectGCFi(int);
s32 update_play_time__23TAdSinglePlyChrSelectGCFv();
s32 run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 get_character_save_record(u32);
s32 get_instance__23TAdSinglePlyChrSelectGCFv();
s32 fn_80203284();
s32 TAdSinglePlyChrSelectGC__sub_8028DC14();
s32 memcpy(s32, s32, u32);
void *memset(void *, int, unsigned long);
extern u8 lbl_804C88C0[];
extern s32 chr_select_serial_seeds[];
extern s32 lbl_805D55C0;
extern u32 card_character_save_buffer;
extern u32 selected_character_data;
extern u32 active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 init__23TAdSinglePlyChrSelectGCFv(void);
s32 load_and_verify_data(s32 arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FFF98(void *arg0);
s32 prepare_save_data__23TAdSinglePlyChrSelectGCFv();
s32 update_play_time__23TAdSinglePlyChrSelectGCFv();
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
s32 TAdSinglePlyChrSelectGC__sub_8028DC14();
u32 get_player_by_client_id(s32);
s32 copy_card_window_data();
s32 fn_80203284();
s32 get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv();
void init_timestamped_data(void);
u32 *init_windows__23TAdSinglePlyChrSelectGCFi();
s32 is_technique_ready__8TTecCtrlFv();
s32 memcpy(s32, s32, u32);

extern s32 local_client_id;
extern u32 card_character_save_buffer;
extern u32 selected_character_data;
extern u32 active_character_save_record;

s32 init__23TAdSinglePlyChrSelectGCFv(void) {
    stop_pad_rumble();
    if (((u32) selected_character_data != 0U) && ((u32) active_character_save_record != 0U) && ((u32) card_character_save_buffer != 0U)) {
        if ((get_player_by_client_id(local_client_id) != 0U) && (is_technique_ready__8TTecCtrlFv() == 0) && (fn_80203284() != 1)) {
            TObjPlayer::init_battle_selection();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
        }
        TAdSinglePlyChrSelectGC::clear_flags(3);
        update_play_time__23TAdSinglePlyChrSelectGCFv();
        copy_card_window_data();
        prepare_save_data__23TAdSinglePlyChrSelectGCFv();
    }
    return 0xFFFF0000;
}

extern s32 chr_select_serial_seeds[];
extern s32 guild_card_save_payload;
extern s32 guild_card_save_file_buffer;

s32 setup_player_battle_ctrls__23TAdSinglePlyChrSelectGCFv(void) {
  u32 temp_r3;
  u32 var_r31;
  u8 *character_save_record;
  stop_pad_rumble();
  get_character_select_request_buffer();
  var_r31 = 0;
  do
  {
    if (((get_player_by_client_id((s32)((int) var_r31)) != 0U) && (((volatile long)is_technique_ready__8TTecCtrlFv()) == 0)) && (TLobby__sub_8030A770() == 0))
    {
      temp_r3 = get_char_index__23TAdSinglePlyChrSelectGCFUi(var_r31);
      if (temp_r3 != 0U)
      {
        try_assign_battle_ctrl__10TObjPlayerFiUs((s32) temp_r3, (u16) var_r31);
      }
      character_save_record = (u8 *) get_character_save_record(var_r31);
      if (character_save_record != 0)
      {
        update_elapsed_time__23TAdSinglePlyChrSelectGCFPv(character_save_record);
      }
    }
    TAdSinglePlyChrSelectGC::clear_flags(3);
    var_r31 += 1;
  }
  while (((s32) var_r31) < 4);
  return 0xFFFF0000;
}

void clear_load_buffers__23TAdSinglePlyChrSelectGCFv(void) {
    if (card_character_save_buffer != 0) {
        memset((void *)card_character_save_buffer, 0, 0x1156C);
        memset((void *)selected_character_data, 0, 0x41C);
        memset((void *)active_character_save_record, 0, 0x2370);
    }
}

s32 load_character_from_card__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    s32 ret;
    u8 *obj;
    u32 buf;
    s32 t;
    s32 i;
    s32 p;
    u32 size;
    if (get_main_phase() == 0xE || (TOKeyMachine01::get_global_state() == 0xF && arg0 != 1) ||
        lbl_805D55C0 == 1 || is_technique_ready__8TTecCtrlFv() != 0 || fn_80203284() == 1) {
        return 0xFFFF0000;
    }
    stop_pad_rumble();
    ret = 0xFFFF0000;
    if (selected_character_data != 0 && active_character_save_record != 0 && card_character_save_buffer != 0) {
        character_save_card_slot = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0xFFFF0000;
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0xFFFF0000;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        if (arg0 != 1) {
            arg0 = find_card_file__15TAdPlayerLoadGCFiPv(character_save_card_slot, lbl_804C88C0);
            if (arg0 != 0) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return arg0;
            }
            size = character_save_file_block_count << 13;
            buf = alloc__22TQuestVmDownLoadServerFv(size);
            memset((void *)buf, 0, size);
            while (TAdPlayerLoadGC__sub_801E1944(character_save_card_slot, lbl_804C88C0, buf, character_save_file_block_count) != 0) {
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    if (buf != 0) {
                        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                    }
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
                render_tick();
            }
            while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    if (buf != 0) {
                        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                    }
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
                render_tick();
            }
            t = get_field_118__22TAdEnterSerialAccessGCFv();
            chr_select_serial_seeds[1] = t;
            chr_select_serial_seeds[0] = t;
            obj = (u8 *)(s32)::operator new(0x1156C);
            if (obj != NULL) {
                obj = init_char_slots__23TAdSinglePlyChrSelectGCFi();
            }
            memset(obj, 0, 0x1156C);
            memcpy((s32)obj, buf + 0x2048, 0x1156C);
            decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(obj);
            ret = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(TAdSinglePlyChrSelectGC__sub_801FCD3C((u32)obj), get_character_save_record(0xFFFF), obj, get_instance__23TAdSinglePlyChrSelectGCFv());
            if (ret != 7) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                if (obj != NULL) {
                    register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return ret;
            }
            if (*(u32 *)(active_character_save_record + 0x14) != *(u32 *)(TAdSinglePlyChrSelectGC__sub_801FCD3C((u32)obj) + 0x14)) {
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                if (obj != NULL) {
                    register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
                }
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 2;
            }
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            }
            if (obj != NULL) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && (ret = TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot)) == 0) {
            TObjPlayer::sync_char_select_state();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            update_play_time__23TAdSinglePlyChrSelectGCFv();
            increment_counter__23TAdSinglePlyChrSelectGCFv();
            switch (get_main_phase()) {
            case 0xF:
                TAdSinglePlyChrSelectGC::set_global_flags(1);
                memcpy((s32)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), selected_character_data, 0x41C);
                memcpy((s32)TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), active_character_save_record, 0x2370);
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
                    p = get_ptr_4__10TObjPlayerFv(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer));
                    for (i = 0; i < 30; i++) {
                        ((TAdSinglePlyChrSelectGC *)p)->clear_inventory_slot();
                        p += 0x1C;
                    }
                    *TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer) = 0;
                    memset(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer) + 0x250, 0, 0x12C0);
                    *(s32 *)(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer) + 0x248) = 0;
                    *(s32 *)(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer) + 0x24C) = 0;
                }
                *(s32 *)(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer) + 0x36C) = 0;
                break;
            default:
                copy_card_window_data();
                memcpy((s32)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), selected_character_data, 0x41C);
                memcpy((s32)TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), active_character_save_record, 0x2370);
                break;
            }
            t = get_field_118__22TAdEnterSerialAccessGCFv();
            chr_select_serial_seeds[1] = t;
            chr_select_serial_seeds[0] = t;
            encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *)card_character_save_buffer, chr_select_serial_seeds);
            save_character_file__23TAdSinglePlyChrSelectGCFi(1);
            while (TAdSinglePlyChrSelectGC__sub_801FDA4C() != 0) {
                run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
                render_tick();
            }
            card_load_sequence_state = 6;
            while (TAdPlayerLoadGC::get_instance() != 0) {
                run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
                if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                    if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                        TLobby::disconnect_protocol();
                    }
                    return 0xFFFF0000;
                }
                render_frame__23TAdSinglePlyChrSelectGCFv();
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
    s32 temp_r3;
    u32 *var_r31;
    u32 temp_r30;

    TAdSinglePlyChrSelectGC::set_save_slot(0);
    temp_r3 = get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv();
    chr_select_serial_seeds[1] = temp_r3;
    chr_select_serial_seeds[0] = temp_r3;
    memcpy(guild_card_save_payload, guild_card_save_file_buffer + 0x2048, 0xE28C);
    TAdSinglePlyChrSelectGC__sub_801FFF98((void *)guild_card_save_payload);
    var_r31 = (u32 *)::operator new(0xE28C);
    if (var_r31 != NULL) {
        var_r31 = init_windows__23TAdSinglePlyChrSelectGCFi();
    }
    TAdSinglePlyChrSelectGC__sub_801FFC74((u8 *)var_r31, (u8 *)guild_card_save_payload);
    temp_r30 = *var_r31;
    *var_r31 = 0U;
    if (temp_r30 != TAdSinglePlyChrSelectGC__sub_80201204((u8 *)var_r31, (u32)(0xE28C))) {
        if (arg0 != 0) {
            ::operator delete(var_r31);
            return 0;
        }
        init_timestamped_data();
        goto block_9;
    }
    if (arg0 != 0) {
        ::operator delete(var_r31);
        return 1;
    }
    TAdSinglePlyChrSelectGC::set_save_slot(1);
block_9:
    ::operator delete(var_r31);
    return 1;
}
u8 *TAdSinglePlyChrSelectGC__sub_801FFC74(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    TAdSinglePlyChrSelectGC__sub_801FFCFC((s32)(arg0 + 4), (s32)(arg1 + 4));
    *(ByteBlock_FC0 *)((arg0 + 0xD2C0) + 4) = *(const ByteBlock_FC0 *)((arg1 + 0xD2C0) + 4);
    *(s32 *)((s8 *)arg0 + 0xE284) = (s32) *(s32 *)((s8 *)arg1 + 0xE284);
    *(s32 *)((s8 *)arg0 + 0xE288) = (s32) *(s32 *)((s8 *)arg1 + 0xE288);
    return arg0;
}
typedef struct ByteBlock_C0 ByteBlock_C0;
#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
s32 TAdSinglePlyChrSelectGC__sub_801FFCFC(s32 arg0, s32 arg1) {
  u32 end;
  u32 var_r30;
  s32 var_r29;
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

}

namespace P801FFD78 {

struct RecoveredGlobal_801FFF14_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_802004D8_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8020051C_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

struct Ser_80200418 { s32 a; s32 b; };

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

struct Ser_801FFF98 { s32 a; s32 b; };

struct Ser_802002E8 { s32 a; s32 b; };

struct Ser_80200560 { s32 a; s32 b; };

struct Ser_802000C8 { s32 a; s32 b; };

struct Ser_80200778 { s32 a; s32 b; };

struct Ser_80200470 { s32 a; s32 b; };

struct Str_80200A44 {
    u8 pad0[0x20];
    char title[0x24];
    u8 icon[0x70];
    char name[0x10];
};

struct File_80200A44 {
    char name[0x12];
    char title[0x22];
    u8 icon[0x18];
    s16 f4C;
    s16 f4E;
    s32 f50;
    s16 f54;
    s32 buf;
    s32 size;
};

extern "C" {
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
void reset_save_header__23TAdSinglePlyChrSelectGCFv(void);
s32 memcpy(void *, s32, s32);
extern s32 *system_save_payload;
extern s32 system_save_file_buffer;
s32 verify_save_checksum__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv();
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 guild_card_save_payload;
void TAdSinglePlyChrSelectGC__sub_801FFF14(void);
s32 get_serial_result__22TAdEnterSerialAccessGCFv();
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 secondary_card_character_save_buffer;
s32 encrypt_and_save__23TAdSinglePlyChrSelectGCFv(void);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 card_character_save_buffer;
s32 write_encrypted_save__23TAdSinglePlyChrSelectGCFv(void);
void __construct_array(void *, void *, void *, int, int);
s32 reinit__17TWindowSubComCardFi(s32 arg0);
u8 *construct_card_window_array__23TAdSinglePlyChrSelectGCFPv(u8 *arg0);
s32 get_serial_result__22TAdEnterSerialAccessGCFv();
s32 memcpy(void *, s32, s32);
s32 TAdPlayerLoadGC__sub_801FD814();
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 secondary_card_character_save_buffer;
extern s32 character_save_file_buffer;
void TAdSinglePlyChrSelectGC__sub_80200418(void);
void *copy_char_slot_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
s32 copy_save_data__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 get_ptr_4__10TObjPlayerFv();
s32 TAdSinglePlyChrSelectGC__sub_801FCD04(s32);
s32 init_character_stats_for_level(u8, void *, s32);
void init_class_starting_inventory(void *arg0);
s32 memset(void *, s32, s32);
extern s32 card_character_save_buffer;
extern void *selected_character_data;
void subtractive_rng_unshuffle(void *, s32, s32, s32);
void subtractive_rng_make_shuffle(void *);
s32 subtractive_rng_xor_buffer(void *, void *, s32);
void subtractive_rng_seed(void *, s32);
void TAdSinglePlyChrSelectGC__sub_801FFC74(s32, void *);
s32 init_windows__23TAdSinglePlyChrSelectGCFi(s32 arg0);
extern u8 chr_select_rng_state[];
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
s32 TAdSinglePlyChrSelectGC__sub_801FFF98(void *arg0);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 memcpy(void *, s32, s32);
s32 TAdPlayerLoadGC__sub_801FD770();
s32 TAdSinglePlyChrSelectGC__sub_801FCD04(s32);
s32 TAdSinglePlyChrSelectGC__sub_801FCD3C(s32);
void TLobby__sub_801F494C(u16 arg0);
u32 check_flag__23TAdSinglePlyChrSelectGCFl(s32);
void reset_character_data__23TAdSinglePlyChrSelectGCFv(void);
void init_class_starting_inventory(void *arg0);
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 card_character_save_buffer;
extern void *selected_character_data;
extern void *active_character_save_record;
extern s32 character_save_file_buffer;
s32 apply_loaded_character__23TAdSinglePlyChrSelectGCFi(s32 arg0);
void subtractive_rng_unshuffle(void *, s32, s32, s32);
void subtractive_rng_make_shuffle(void *);
s32 subtractive_rng_xor_buffer(void *, void *, s32);
void subtractive_rng_seed(void *, s32);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FCCC0(u8 *arg0);
s32 copy_save_data__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 register_callback__23TAdSinglePlyChrSelectGCFis(s32 arg0, s16 arg1);
extern u8 chr_select_rng_state[];
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(void *arg0);
void subtractive_rng_make_shuffle(void *);
s32 subtractive_rng_xor_buffer(void *, void *, s32);
s32 subtractive_rng_next(s32 *arg0);
void subtractive_rng_seed(void *, s32);
void TAdSinglePlyChrSelectGC__sub_801FFC74(s32, void *);
s32 init_windows__23TAdSinglePlyChrSelectGCFi(s32 arg0);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
extern u8 chr_select_rng_state[];
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
s32 TAdSinglePlyChrSelectGC__sub_802000C8(void *arg0_, void *arg1);
void subtractive_rng_make_shuffle(void *);
s32 subtractive_rng_xor_buffer(void *, void *, s32);
s32 subtractive_rng_next(s32 *arg0);
void subtractive_rng_seed(void *, s32);
s32 register_callback__23TAdSinglePlyChrSelectGCFis(s32 arg0, s16 arg1);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 arg0);
void TAdSinglePlyChrSelectGC__sub_801FCCB4(u8 *arg0, s32 arg1);
s32 TAdSinglePlyChrSelectGC__sub_801FCCC0(u8 *arg0);
void set_id__23TAdSinglePlyChrSelectGCFPvi(void *, s32);
s32 copy_save_data__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
extern u8 chr_select_rng_state[];
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *arg0);
s32 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
u32 alloc__22TQuestVmDownLoadServerFv(s32);
s32 get_ptr_4__10TObjPlayerFv();
s32 TAdPlayerLoadGC__sub_801E1944(s32, void *, u32, s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, void *);
s32 register_callback__23TAdSinglePlyChrSelectGCFis(s32 arg0, s16 arg1);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FCD04(s32);
s32 TAdSinglePlyChrSelectGC__sub_801FCD3C(s32);
void render_frame__23TAdSinglePlyChrSelectGCFv(void);
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(s32, s32, s32, s32);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C(void);
void increment_counter__23TAdSinglePlyChrSelectGCFv();
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(void *arg0);
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *arg0);
void update_play_time__23TAdSinglePlyChrSelectGCFv();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 get_character_save_record(u32);
s32 get_instance__23TAdSinglePlyChrSelectGCFv();
void TAdSinglePlyChrSelectGC__sub_8028DC14();
s32 memcpy(void *, s32, s32);
s32 memset(void *, s32, s32);
extern u8 lbl_804C88C0[];
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 lbl_805D55C0;
extern s32 card_character_save_buffer;
extern void *selected_character_data;
extern void *active_character_save_record;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 character_save_file_block_count;
s32 save_online_character__23TAdSinglePlyChrSelectGCFv(void);
s32 TAdSinglePlyChrSelectGC__sub_801FCD04(s32);
s32 TAdSinglePlyChrSelectGC__sub_801FCD3C(s32);
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *arg0);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 memcpy(void *, s32, s32);
extern RecoveredGlobal_801FFF14_lbl_80513910 chr_select_serial_seeds;
extern s32 card_character_save_buffer;
extern void *selected_character_data;
extern void *active_character_save_record;
void prepare_save_data__23TAdSinglePlyChrSelectGCFv(void);
void TAdPlayerLoadGC__sub_801E14E4(File_80200A44 *);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
void build_save_file_image__15TAdPlayerLoadGCFPvPv(s32, File_80200A44 *);
void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(void *arg0);
char *strcpy(char *, const char *);
s32 memcpy(void *, s32, s32);
s32 memset(void *, s32, s32);
extern u8 lbl_804C88C0[];
extern s32 card_character_save_buffer;
extern s32 secondary_card_character_save_buffer;
extern s32 character_save_file_buffer;
s32 save_character_file__23TAdSinglePlyChrSelectGCFi(int arg0);
void __construct_array(void *, void *, void *, int, int);
s32 init_guild_card_tag__17TWindowSubComCardFi(s32 arg0);
int construct_card_window_array__23TAdSinglePlyChrSelectGCFi(s32 arg0);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
s32 memcpy(void *, s32, s32);
extern s32 *secondary_card_system_save_payload;
extern s32 system_save_file_buffer;
void verify_save_checksum__23TAdSinglePlyChrSelectGCFv(void);
void TAdPlayerLoadGC__sub_801E14E4(File_80200A44 *);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
void build_save_file_image__15TAdPlayerLoadGCFPvPv(s32, File_80200A44 *);
char *strcpy(char *, const char *);
s32 memcpy(void *, s32, s32);
s32 memset(void *, s32, s32);
extern u8 lbl_804C88C0[];
extern s32 guild_card_save_payload;
extern s32 guild_card_save_file_buffer;
s32 build_save_file__23TAdSinglePlyChrSelectGCFv();
void TAdPlayerLoadGC__sub_801E14E4(File_80200A44 *);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
void build_save_file_image__15TAdPlayerLoadGCFPvPv(s32, File_80200A44 *);
char *strcpy(char *, const char *);
s32 memcpy(void *, s32, s32);
s32 memset(void *, s32, s32);
extern u8 lbl_804C88C0[];
extern s32 *system_save_payload;
extern s32 system_save_file_buffer;
s32 build_default_save_file__23TAdSinglePlyChrSelectGCFv();
void create_instance__23TAdSinglePlyChrSelectGCFv(void);
void game_state_load(void);
s32 init_windows__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 TAdSinglePlyChrSelectGC__sub_801FCD04(s32);
s32 TAdSinglePlyChrSelectGC__sub_801FCD3C(s32);
void reset_character_data__23TAdSinglePlyChrSelectGCFv(void);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
void init_class_starting_inventory(void *arg0);
void TLobby__sub_801F494C(u16 arg0);
u32 check_flag__23TAdSinglePlyChrSelectGCFl(s32);
s32 memcpy(void *, s32, s32);

s32 init_windows__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    construct_card_window_array__23TAdSinglePlyChrSelectGCFPv((u8 *)(arg0 + 4));
    construct_card_window_array__23TAdSinglePlyChrSelectGCFi(arg0 + 0xD2C4);
    return arg0;
}

extern s32 *system_save_payload;

int construct_card_window_array__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    __construct_array((void *)arg0, (void *)init_guild_card_tag__17TWindowSubComCardFi, 0, 0x90, 0x1C);
    return arg0;
}

u8 *construct_card_window_array__23TAdSinglePlyChrSelectGCFPv(u8 *arg0) {
    __construct_array(arg0 + 0xC0, (void *)reinit__17TWindowSubComCardFi, 0, 0x100, 0xD2);
    return arg0;
}

#pragma push
#pragma fp_contract on
s32 verify_save_checksum__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    u32 temp_r31;
    u32 temp_r3;
    memcpy((void *)((*(u32 * *)&system_save_payload)), system_save_file_buffer + 0x2048, 0x11C);
    temp_r31 = *(*(u32 * *)&system_save_payload);
    *(*(u32 * *)&system_save_payload) = 0U;
    temp_r3 = ((u32)TAdSinglePlyChrSelectGC__sub_80201204((u8 *)((s32 *)((*(u32 * *)&system_save_payload))), 0x11C));
    if (temp_r3 != temp_r31) {
        if (arg0 == 0) {
            reset_save_header__23TAdSinglePlyChrSelectGCFv();
        }
        return 0;
    }
    return 1;
}
#pragma pop

typedef char RecoveredGlobal_801FFF14_lbl_80513910_size[sizeof(RecoveredGlobal_801FFF14_lbl_80513910) == 0x10 ? 1 : -1];

void verify_save_checksum__23TAdSinglePlyChrSelectGCFv(void) {
    u32 sum;
    u32 r;
    memcpy((void *)((void *)secondary_card_system_save_payload), system_save_file_buffer + 0x2048, 0x11C);
    sum = *secondary_card_system_save_payload;
    *secondary_card_system_save_payload = 0;
    r = (u32)TAdSinglePlyChrSelectGC__sub_80201204((u8 *)secondary_card_system_save_payload, 0x11C);
    if (r != sum) {
        return;
    }
}

void TAdSinglePlyChrSelectGC__sub_801FFF14(void) {
    s32 temp_r3;
    temp_r3 = get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv();
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 4) = temp_r3;
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 0) = temp_r3;
    TAdSinglePlyChrSelectGC__sub_802000C8((void *)guild_card_save_payload, (void *)((void *)&chr_select_serial_seeds.value));
    build_save_file__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC__sub_801FFF98(((void *)guild_card_save_payload));
}

void create_instance__23TAdSinglePlyChrSelectGCFv(void) {
    *system_save_payload = 0;
    *system_save_payload = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)system_save_payload, 0x11C);
    build_default_save_file__23TAdSinglePlyChrSelectGCFv();
}

extern s32 card_character_save_buffer;
extern void *selected_character_data;
extern void *active_character_save_record;

s32 TAdSinglePlyChrSelectGC__sub_801FFF98(void *arg0) {
    s32 a;
    s32 b;
    a = (s32)::operator new(0xE28C);
    if (a != 0) {
        a = init_windows__23TAdSinglePlyChrSelectGCFi(a);
    }
    b = (s32)::operator new(0xE28C);
    if (b != 0) {
        b = init_windows__23TAdSinglePlyChrSelectGCFi(b);
    }
    TAdSinglePlyChrSelectGC__sub_801FFC74(a, arg0);
    TAdSinglePlyChrSelectGC__sub_801FFC74(b, arg0);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_801FFF98 *)&chr_select_serial_seeds)[0].b);
    subtractive_rng_make_shuffle(chr_select_rng_state);
    subtractive_rng_unshuffle(chr_select_rng_state, a, b, 0xE28C);
    TAdSinglePlyChrSelectGC__sub_801FFC74((s32)arg0, (void *)b);
    ::operator delete((void *)b);
    ::operator delete((void *)a);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_801FFF98 *)&chr_select_serial_seeds)[0].a);
    ((TAdSinglePlyChrSelectGC *)chr_select_rng_state)->apply_rng_cipher((u32 *)arg0, 0xE28C);
    subtractive_rng_seed(chr_select_rng_state, *(s32 *)((u8 *)arg0 + 0xE288));
    return subtractive_rng_xor_buffer(chr_select_rng_state, arg0, 0xE288);
}

#pragma push
#pragma opt_common_subs off
#define self ((s32 *)arg0_)
s32 TAdSinglePlyChrSelectGC__sub_802000C8(void *arg0_, void *arg1) {
    s32 a;
    s32 b;
    *(s32 *)((u8 *)self + 0xE288) = subtractive_rng_next((s32 *)chr_select_rng_state);
    self[0] = 0;
    self[0] = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)self, 0xE28C);
    subtractive_rng_seed(chr_select_rng_state, *(s32 *)((u8 *)self + 0xE288));
    subtractive_rng_xor_buffer(chr_select_rng_state, self, 0xE288);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_802000C8 *)&chr_select_serial_seeds)[0].a);
    ((TAdSinglePlyChrSelectGC *)chr_select_rng_state)->apply_rng_cipher((u32 *)self, 0xE28C);
    a = (s32)::operator new(0xE28C);
    if (a != 0) {
        a = init_windows__23TAdSinglePlyChrSelectGCFi(a);
    }
    b = (s32)::operator new(0xE28C);
    if (b != 0) {
        b = init_windows__23TAdSinglePlyChrSelectGCFi(b);
    }
    TAdSinglePlyChrSelectGC__sub_801FFC74(a, self);
    TAdSinglePlyChrSelectGC__sub_801FFC74(b, self);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_802000C8 *)&chr_select_serial_seeds)[0].b);
    subtractive_rng_make_shuffle(chr_select_rng_state);
    TAdSinglePlyChrSelectGC::permute_save_blocks((void*)chr_select_rng_state, (const u8*)a, (u8*)b, (u32)0xE28C);
    TAdSinglePlyChrSelectGC__sub_801FFC74((s32)self, (void *)b);
    ::operator delete((void *)b);
    ::operator delete((void *)a);
}
#undef self
#pragma pop

void game_state_load(void) {
    memcpy(selected_character_data, TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), 0x41C);
    memcpy(active_character_save_record, TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), 0x2370);
    TLobby__sub_801F494C(0);
    if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        if (check_flag__23TAdSinglePlyChrSelectGCFl(1) != 0U) {
            reset_character_data__23TAdSinglePlyChrSelectGCFv();
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
typedef char RecoveredGlobal_802004D8_lbl_80513910_size[sizeof(RecoveredGlobal_802004D8_lbl_80513910) == 0x10 ? 1 : -1];

s32 apply_loaded_character__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    s32 r = get_field_118__22TAdEnterSerialAccessGCFv();
    ((Ser_802002E8 *)&chr_select_serial_seeds)[0].b = r;
    ((Ser_802002E8 *)&chr_select_serial_seeds)[0].a = r;
    memcpy((void *)((void *)card_character_save_buffer), character_save_file_buffer + 0x2048, 0x1156C);
    decrypt_char_data__23TAdSinglePlyChrSelectGCFPv((void *)((void *)card_character_save_buffer));
    if (TAdPlayerLoadGC__sub_801FD770() != 7) {
        return 0;
    }
    if (arg0 != 0) {
        return 1;
    }
    memcpy(selected_character_data, (s32)(TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer)), 0x41C);
    memcpy((void *)((*(void *const *)&active_character_save_record)), (s32)(TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer)), 0x2370);
    TLobby__sub_801F494C(0);
    if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
        if (check_flag__23TAdSinglePlyChrSelectGCFl(1) != 0U) {
            reset_character_data__23TAdSinglePlyChrSelectGCFv();
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
    s32 r = get_serial_result__22TAdEnterSerialAccessGCFv();
    ((Ser_80200418 *)&chr_select_serial_seeds)[0].b = r;
    ((Ser_80200418 *)&chr_select_serial_seeds)[0].a = r;
    memcpy((void *)((void *)secondary_card_character_save_buffer), character_save_file_buffer + 0x2048, 0x1156C);
    decrypt_char_data__23TAdSinglePlyChrSelectGCFPv((void *)((void *)secondary_card_character_save_buffer));
    if (TAdPlayerLoadGC__sub_801FD814() == 7) {
        return;
    }
}

void prepare_save_data__23TAdSinglePlyChrSelectGCFv(void) {
    s32 r = get_field_118__22TAdEnterSerialAccessGCFv();
    ((Ser_80200470 *)&chr_select_serial_seeds)[0].b = r;
    ((Ser_80200470 *)&chr_select_serial_seeds)[0].a = r;
    memcpy((void *)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer), (s32)selected_character_data, 0x41C);
    memcpy((void *)TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (s32)active_character_save_record, 0x2370);
    encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *)card_character_save_buffer);
    save_character_file__23TAdSinglePlyChrSelectGCFi(1);
}

s32 encrypt_and_save__23TAdSinglePlyChrSelectGCFv(void) {
    s32 temp_r3;
    temp_r3 = get_serial_result__22TAdEnterSerialAccessGCFv();
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802004D8_lbl_80513910 *)&chr_select_serial_seeds).value) + 4) = temp_r3;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802004D8_lbl_80513910 *)&chr_select_serial_seeds).value) + 0) = temp_r3;
    encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *)secondary_card_character_save_buffer);
    save_character_file__23TAdSinglePlyChrSelectGCFi(0);
    return 1;
}
typedef char RecoveredGlobal_8020051C_lbl_80513910_size[sizeof(RecoveredGlobal_8020051C_lbl_80513910) == 0x10 ? 1 : -1];
s32 write_encrypted_save__23TAdSinglePlyChrSelectGCFv(void) {
    s32 temp_r3;
    temp_r3 = get_field_118__22TAdEnterSerialAccessGCFv();
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8020051C_lbl_80513910 *)&chr_select_serial_seeds).value) + 4) = temp_r3;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8020051C_lbl_80513910 *)&chr_select_serial_seeds).value) + 0) = temp_r3;
    encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *)card_character_save_buffer);
    save_character_file__23TAdSinglePlyChrSelectGCFi(1);
    return 1;
}

void decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    s32 a;
    s32 b;
    a = (s32)::operator new(0x1156C);
    if (a != 0) {
        a = init_char_slots__23TAdSinglePlyChrSelectGCFi(a);
    }
    b = (s32)::operator new(0x1156C);
    if (b != 0) {
        b = init_char_slots__23TAdSinglePlyChrSelectGCFi(b);
    }
    copy_save_data__23TAdSinglePlyChrSelectGCFii(a, (s32)arg0);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_80200560 *)&chr_select_serial_seeds)[0].b);
    subtractive_rng_make_shuffle(chr_select_rng_state);
    subtractive_rng_unshuffle(chr_select_rng_state, a, b, 0x1156C);
    copy_save_data__23TAdSinglePlyChrSelectGCFii((s32)arg0, b);
    register_callback__23TAdSinglePlyChrSelectGCFis(b, 1);
    register_callback__23TAdSinglePlyChrSelectGCFis(a, 1);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_80200560 *)&chr_select_serial_seeds)[0].a);
    ((TAdSinglePlyChrSelectGC *)chr_select_rng_state)->apply_rng_cipher((u32 *)arg0, 0x1156C);
    subtractive_rng_seed(chr_select_rng_state, TAdSinglePlyChrSelectGC__sub_801FCCC0((u8 *)arg0));
    subtractive_rng_xor_buffer(chr_select_rng_state, arg0, 0x11568);
}

s32 copy_save_data__23TAdSinglePlyChrSelectGCFii(s32 arg0, s32 arg1) {
    Save_80200690 *dst = (Save_80200690 *)arg0;
    Save_80200690 *src = (Save_80200690 *)arg1;
    Slot_80200690 *d;
    Slot_80200690 *s;
    dst->hdr = src->hdr;
    d = dst->slots;
    s = src->slots;
    do {
        copy_char_slot_data__23TAdSinglePlyChrSelectGCFPvPv(d, s);
        d++;
        s++;
    } while (d < &dst->slots[7]);
    dst->tail = src->tail;
    dst->x = src->x;
    dst->y = src->y;
    return arg0;
}

#define self ((s32 *)arg0)
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *arg0) {
    s32 a;
    s32 b;
    TAdSinglePlyChrSelectGC__sub_801FCCB4((u8 *)self, (s32)(subtractive_rng_next((s32 *)chr_select_rng_state)));
    set_id__23TAdSinglePlyChrSelectGCFPvi(self, 0);
    set_id__23TAdSinglePlyChrSelectGCFPvi((void *)self, (s32)(TAdSinglePlyChrSelectGC__sub_80201204((u8 *)self, 0x1156C)));
    subtractive_rng_seed(chr_select_rng_state, TAdSinglePlyChrSelectGC__sub_801FCCC0((u8 *)self));
    subtractive_rng_xor_buffer(chr_select_rng_state, self, 0x11568);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_80200778 *)&chr_select_serial_seeds)[0].a);
    ((TAdSinglePlyChrSelectGC *)chr_select_rng_state)->apply_rng_cipher((u32 *)self, 0x1156C);
    a = (s32)::operator new(0x1156C);
    if (a != 0) {
        a = init_char_slots__23TAdSinglePlyChrSelectGCFi(a);
    }
    b = (s32)::operator new(0x1156C);
    if (b != 0) {
        b = init_char_slots__23TAdSinglePlyChrSelectGCFi(b);
    }
    copy_save_data__23TAdSinglePlyChrSelectGCFii(a, (s32)self);
    subtractive_rng_seed(chr_select_rng_state, ((Ser_80200778 *)&chr_select_serial_seeds)[0].b);
    subtractive_rng_make_shuffle(chr_select_rng_state);
    TAdSinglePlyChrSelectGC::permute_save_blocks((void*)chr_select_rng_state, (const u8*)a, (u8*)b, (u32)0x1156C);
    copy_save_data__23TAdSinglePlyChrSelectGCFii((s32)self, b);
    register_callback__23TAdSinglePlyChrSelectGCFis(b, 1);
    register_callback__23TAdSinglePlyChrSelectGCFis(a, 1);
}
#undef self

s32 build_save_file__23TAdSinglePlyChrSelectGCFv() {
    s32 base = (s32)lbl_804C88C0;
    File_80200A44 f;
    memset(&f, 0, sizeof(f));
    strcpy(f.name, (char *)(base + 0xB4));
    strcpy(f.title, (char *)(base + 0x11C));
    memcpy(f.icon, base + 0xEC, 0x10);
    TAdPlayerLoadGC__sub_801E14E8((u8 *)&f, 1);
    f.f4C = 1;
    f.f4E = 1;
    f.f50 = 0;
    f.f54 = 0;
    f.buf = guild_card_save_payload;
    f.size = 0xE28C;
    build_save_file_image__15TAdPlayerLoadGCFPvPv(guild_card_save_file_buffer, &f);
    TAdPlayerLoadGC__sub_801E14E4(&f);
}

s32 build_default_save_file__23TAdSinglePlyChrSelectGCFv() {
    s32 base = (s32)lbl_804C88C0;
    File_80200A44 f;
    memset(&f, 0, sizeof(f));
    strcpy(f.name, (char *)(base + 0xB4));
    strcpy(f.title, (char *)(base + 0xC8));
    memcpy(f.icon, base + 0xEC, 0x10);
    TAdPlayerLoadGC__sub_801E14E8((u8 *)&f, 0);
    f.f4C = 1;
    f.f4E = 1;
    f.f50 = 0;
    f.f54 = 0;
    f.buf = (s32)system_save_payload;
    f.size = 0x11C;
    build_save_file_image__15TAdPlayerLoadGCFPvPv(system_save_file_buffer, &f);
    TAdPlayerLoadGC__sub_801E14E4(&f);
}

s32 save_character_file__23TAdSinglePlyChrSelectGCFi(int arg0) {
    s32 base = (s32)lbl_804C88C0;
    File_80200A44 f;
    memset(&f, 0, (s32)(sizeof(f)));
    strcpy(f.name, ((Str_80200A44 *)base)->name);
    strcpy(f.title, ((Str_80200A44 *)base)->title);
    memcpy(f.icon, (s32)((s32)((Str_80200A44 *)base)->icon), 0x10);
    TAdPlayerLoadGC__sub_801E14E8((u8 *)&f, 2);
    f.f4C = 1;
    f.f4E = 1;
    f.f50 = 0;
    f.f54 = 0;
    if (arg0 != 0) {
        f.buf = card_character_save_buffer;
    } else {
        f.buf = secondary_card_character_save_buffer;
    }
    f.size = 0x1156C;
    build_save_file_image__15TAdPlayerLoadGCFPvPv(character_save_file_buffer, &f);
    TAdPlayerLoadGC__sub_801E14E4(&f);
    if (arg0 != 0) {
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv((void *)card_character_save_buffer);
    } else {
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv((void *)secondary_card_character_save_buffer);
    }
}

void reset_character_data__23TAdSinglePlyChrSelectGCFv(void) {
    s32 var_r31;
    s32 var_r30;

    if ((void *) selected_character_data != NULL) {
        TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer);
        var_r30 = get_ptr_4__10TObjPlayerFv();
        var_r31 = 0;
        do {
            ((TAdSinglePlyChrSelectGC *)var_r30)->clear_inventory_slot();
            var_r31 += 1;
            var_r30 += 0x1C;
        } while (var_r31 < 0x1E);
        *(s8 *)((s8 *)selected_character_data + 0) = 0;
        init_class_starting_inventory(selected_character_data);
        init_character_stats_for_level(*(u8 *)((s8 *)selected_character_data + 0x3A1), selected_character_data, *(s32 *)((s8 *)selected_character_data + 0x364));
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
s32 save_online_character__23TAdSinglePlyChrSelectGCFv(void) {
    s32 cw;
    s32 inst;
    s32 obj;
    u32 buf;
    if (lbl_805D55C0 == 1) {
        if (active_character_save_record != NULL) {
            (*(s32 *)((s8 *)active_character_save_record + 0x14))++;
            return *(s32 *)((s8 *)active_character_save_record + 0x14);
        }
        return 0;
    }
    if (selected_character_data != NULL && active_character_save_record != NULL && (u32)card_character_save_buffer != 0) {
        stop_pad_rumble();
        character_save_card_slot = (s8)get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
        if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0;
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                return 0;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        if (find_card_file__15TAdPlayerLoadGCFiPv(character_save_card_slot, lbl_804C88C0) != 0) {
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0;
        }
        obj = character_save_file_block_count << 13;
        buf = alloc__22TQuestVmDownLoadServerFv(obj);
        memset((void *)buf, 0, obj);
        while (TAdPlayerLoadGC__sub_801E1944(character_save_card_slot, lbl_804C88C0, buf, character_save_file_block_count) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                return 0;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        while (TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) != 0) {
            if (((TAdPlayerLoadGC *)character_save_card_slot)->probe_card_slot() != 1) {
                if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                    TLobby::disconnect_protocol();
                }
                if (buf != 0) {
                    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                }
                return 0;
            }
            render_frame__23TAdSinglePlyChrSelectGCFv();
            render_tick();
        }
        ((s32 *)&chr_select_serial_seeds)[0] = ((s32 *)&chr_select_serial_seeds)[1] = get_field_118__22TAdEnterSerialAccessGCFv();
        obj = (s32)::operator new(0x1156C);
        if (obj != 0) {
            obj = init_char_slots__23TAdSinglePlyChrSelectGCFi(obj);
        }
        memset((void *)obj, 0, 0x1156C);
        memcpy((void *)obj, buf + 0x2048, 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv((void *)obj);
        if (compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(TAdSinglePlyChrSelectGC__sub_801FCD3C(obj),
                get_character_save_record(0xFFFF), obj, get_instance__23TAdSinglePlyChrSelectGCFv()) != 7) {
            if (buf != 0) {
                TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            }
            if ((u32)obj != 0) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 1) {
                TLobby::disconnect_protocol();
            }
            return 0;
        }
        if (buf != 0) {
            TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        }
        if ((u32)obj != 0) {
            register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
        }
        if (TAdPlayerLoadGC::get_instance() == 0 && TAdPlayerLoadGC__sub_801E1B50(character_save_card_slot) == 0) {
            TObjPlayer::sync_char_select_state();
            TAdSinglePlyChrSelectGC__sub_8028DC14();
            update_play_time__23TAdSinglePlyChrSelectGCFv();
            TAdSinglePlyChrSelectGC::set_global_flags(1);
            (*(s32 *)((s8 *)active_character_save_record + 0x14))++;
            increment_counter__23TAdSinglePlyChrSelectGCFv();
            memcpy((void *)((s32)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer)), (s32)selected_character_data, 0x41C);
            memcpy((void *)TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer), (s32)active_character_save_record, 0x2370);
            if (TAdSinglePlyChrSelectGC::get_game_mode() == 0) {
                s32 i;
                s32 p;
                TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer);
                p = get_ptr_4__10TObjPlayerFv();
                for (i = 0; i < 30; i++) {
                    ((TAdSinglePlyChrSelectGC *)p)->clear_inventory_slot();
                    p += 0x1C;
                }
                {
                    u8 *s = (u8 *)((s32)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer));
                    *s = 0;
                }
                {
                    u8 *q = (u8 *)TAdSinglePlyChrSelectGC__sub_801FCD3C(card_character_save_buffer);
                    memset(q + 0x250, 0, 0x12C0);
                    *(s32 *)((s8 *)q + 0x248) = 0;
                    *(s32 *)((s8 *)q + 0x24C) = 0;
                }
            }
            *(s32 *)((s8 *)((s32)TAdSinglePlyChrSelectGC__sub_801FCD04(card_character_save_buffer)) + 0x36C) = 0;
            ((s32 *)&chr_select_serial_seeds)[0] = ((s32 *)&chr_select_serial_seeds)[1] = get_field_118__22TAdEnterSerialAccessGCFv();
            encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv((void *)card_character_save_buffer);
            save_character_file__23TAdSinglePlyChrSelectGCFi(1);
            if (TAdSinglePlyChrSelectGC__sub_801FDA4C() == 0) {
                card_load_sequence_state = 6;
            }
        }
        return *(s32 *)((s8 *)active_character_save_record + 0x14);
    }
    return 0;
}

}

}

namespace P801FBF54 {

struct RecoveredGlobal_802010E8_lbl_80513904 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80201970_lbl_805137D8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80201970_lbl_805137F8 {
    s32 value;
    u8 remaining[0x20];
};

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
s32 memmove(void *, void *, int);
s32 memset(s32, s32, s32);
extern u8 *system_save_payload;
void reset_save_header__23TAdSinglePlyChrSelectGCFv(void);
s32 memset(s32, s32, s32);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 allocation);
extern u32 secondary_card_character_save_buffer;
extern u32 secondary_card_system_save_payload;
void alloc_char_buffers__23TAdSinglePlyChrSelectGCFv(void);
extern s32 char_select_date_stamp[];
extern void *active_character_save_record;
s32 update_play_time__23TAdSinglePlyChrSelectGCFv(void);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void register_callback__23TAdSinglePlyChrSelectGCFis(void*, int);
s32 free_char_data_slots__23TAdSinglePlyChrSelectGCFPv(void *);
s32 free_buffer__23TAdSinglePlyChrSelectGCFv(void);
s32 free_data__23TAdSinglePlyChrSelectGCFv(void);
s32 free__23TAdSinglePlyChrSelectGCFv(void);
extern RecoveredGlobal_80201970_lbl_805137D8 chr_select_buffer_ptr_table;
extern RecoveredGlobal_80201970_lbl_805137F8 chr_select_request_buffer;
extern u32 card_character_save_buffer;
extern u8 *selected_character_data;
extern void *active_character_save_record;
extern s32 guild_card_save_payload;
void release_all__23TAdSinglePlyChrSelectGCFv(void);
s32 TAdPlayerLoadGC__sub_801E1B50(void *);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();
s32 load_chr_select_slot__23TAdSinglePlyChrSelectGCFv();
s32 TAdSinglePlyChrSelectGC__sub_801FEBBC();
s32 load_selected_char__23TAdSinglePlyChrSelectGCFv();
s32 load_and_verify_data(s32 arg0);
s32 verify_save_checksum__23TAdSinglePlyChrSelectGCFi(s32 arg0);
void verify_save_checksum__23TAdSinglePlyChrSelectGCFv(void);
s32 apply_loaded_character__23TAdSinglePlyChrSelectGCFi(s32 arg0);
void TAdSinglePlyChrSelectGC__sub_80200418(void);
s32 prepare_save_data__23TAdSinglePlyChrSelectGCFv();
s32 TAdSinglePlyChrSelectGC__sub_8028DC14();
extern s32 lbl_805D49B4;
extern u32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 card_load_channel;
extern s32 system_save_card_channel;
extern s32 card_load_followup_pending;
void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv(void);
s32 TLobby__sub_80146D50(s32);
s32 TLobby__sub_80146D68(s32);
void set_fresh_card_flag(void *arg0);
void clear_all_story_flags();
Card_80201354 *get_character_save_record(u32);
void *get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);
void TWindowShortListCtrl__sub_8026E884(s16 *dst);
void TAdSinglePlyChrSelectGC__sub_8028DC1C();
void *memcpy(void *, s32, s32);
s32 memset(s32, s32, s32);
extern s32 char_select_date_stamp[];
s32 init_fresh_character_card(void);
s32 alloc_global_buffer(void);
s32 buffer_init(void);
s32 free__23TAdSinglePlyChrSelectGCFv(void);
s32 free_buffer__23TAdSinglePlyChrSelectGCFv(void);
void free_callbacks__23TAdSinglePlyChrSelectGCFv(void);
s32 free_data__23TAdSinglePlyChrSelectGCFv(void);
s32 get_player_count__23TAdSinglePlyChrSelectGCFv(void);
int get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv(void* p);
s32 increment_frame__23TAdSinglePlyChrSelectGCFv(void);
s32 init_and_register__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 init_buffer(void);
void init_timestamped_data(void);
s32 update_elapsed_time__23TAdSinglePlyChrSelectGCFPv(void *arg0);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32 allocation);
s32 copy_save_data__23TAdSinglePlyChrSelectGCFii(s32, s32);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *, u32);
u32 alloc__22TQuestVmDownLoadServerFv(s32);
int get_field_118__22TAdEnterSerialAccessGCFv(void*);
s32 get_type__23TAdSinglePlyChrSelectGCFPv(void *p);
s32 memset(s32, s32, s32);
void register_callback__23TAdSinglePlyChrSelectGCFis(void*, int);
void set_id__23TAdSinglePlyChrSelectGCFPvi(void *p, s32 v);

extern void *active_character_save_record;

s32 increment_frame__23TAdSinglePlyChrSelectGCFv(void) {
    if ((void *) active_character_save_record != NULL) {
        *(s32 *)((s8 *)active_character_save_record + 0x14) = (s32) (*(s32 *)((s8 *)active_character_save_record + 0x14) + 1);
        return *(s32 *)((s8 *)active_character_save_record + 0x14);
    }
    return 0;
}

extern void *active_character_save_record;

s32 get_player_count__23TAdSinglePlyChrSelectGCFv(void) {
    if ((void *) active_character_save_record != NULL) {
        return *(s32 *)((s8 *)active_character_save_record + 4);
    }
    return 0;
}

extern s32 char_select_date_stamp[];

s32 update_elapsed_time__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    s32 sp10[4];
    s32 spC;
    s32 sp8;

    if (arg0 != NULL) {
        DateToSeconds((DateStamp *)(char_select_date_stamp), (int *)(&spC));
        getDateStamp((DateStamp *)sp10);
        DateToSeconds((DateStamp *)(sp10), (int *)(&sp8));
        *(s32 *)((s8 *)arg0 + 0xC) = (s32) (*(s32 *)((s8 *)arg0 + 0xC) + (sp8 - spC));
        return *(s32 *)((s8 *)arg0 + 0xC);
    }
    return 0;
}

typedef char RecoveredGlobal_802010E8_lbl_80513904_size[sizeof(RecoveredGlobal_802010E8_lbl_80513904) == 0xC ? 1 : -1];
s32 update_play_time__23TAdSinglePlyChrSelectGCFv(void) {
    s32 spC;
    s32 sp8;
    if ((void *) (*(u8 * *)&active_character_save_record) != NULL) {
        DateToSeconds((DateStamp *)((s32 *)(&(*(RecoveredGlobal_802010E8_lbl_80513904 *)&char_select_date_stamp).value)), (int *)(&spC));
        getDateStamp((DateStamp *)((s32 *)(&(*(RecoveredGlobal_802010E8_lbl_80513904 *)&char_select_date_stamp).value)));
        DateToSeconds((DateStamp *)((s32 *)(&(*(RecoveredGlobal_802010E8_lbl_80513904 *)&char_select_date_stamp).value)), (int *)(&sp8));
        *(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC) = (s32) (*(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC) + (sp8 - spC));
        return *(s32 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0xC);
    }
    return 0;
}

s32 init_and_register__23TAdSinglePlyChrSelectGCFi(s32 arg0) {
    s32 var_r29;
    u32 temp_r30;
    u32 temp_r31;

    var_r29 = (s32)::operator new(0x1156C);
    if (var_r29 != 0) {
        var_r29 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r29);
    }
    copy_save_data__23TAdSinglePlyChrSelectGCFii(var_r29, arg0);
    temp_r30 = get_type__23TAdSinglePlyChrSelectGCFPv((void *)var_r29);
    set_id__23TAdSinglePlyChrSelectGCFPvi((void *)var_r29, 0);
    temp_r31 = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)var_r29, 0x1156C);
    register_callback__23TAdSinglePlyChrSelectGCFis((void*)var_r29, 1);
    if (temp_r30 == temp_r31) {
        return 1;
    }
    return 0;
}

u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1) {
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

extern s32 guild_card_save_payload;

void init_timestamped_data(void) {
    char sp8[0x18];

    stop_pad_rumble();
    memset(guild_card_save_payload, 0, 0xE28C);
    getDateStamp((DateStamp *)((s32 *) sp8));
    DateToSeconds((DateStamp *)((s32 *)((s32 *) sp8)), (int *)(guild_card_save_payload + 0xE284));
    TAdSinglePlyChrSelectGC::set_save_slot(0);
}

extern u32 guild_card_save_file_buffer;

void reset_save_header__23TAdSinglePlyChrSelectGCFv(void) {
  volatile unsigned long long sp10;
  s32 sp8;
  memset((s32)((void *) system_save_payload), 0, 0x11C);
  *((s16 *) (((s8 *) system_save_payload) + 4)) = -0x32;
  *((s8 *) (((s8 *) system_save_payload) + 6)) = 0;
  *((s8 *) (((s8 *) system_save_payload) + 7)) = TLanguage::get_default_language();
  *((s32 *) (((s8 *) system_save_payload) + 8)) = default_clock_offset_frames();
  *((s16 *) (((s8 *) system_save_payload) + 0xC)) = 0;
  *((s16 *) (((s8 *) system_save_payload) + 0xE)) = 0;
  TAdPlayerLoadGC::reset_load_state((void *)0, &sp8);
  memmove(system_save_payload + 0x110, &sp8, 8);
  getDateStamp((DateStamp *)(&sp10));
  DateToSeconds((DateStamp *)(&sp10), (int *)(system_save_payload + 0x118));
}

s32 init_fresh_character_card(void) {
    void *chr;
    Card_80201354 *card;
    s32 i;
    stop_pad_rumble();
    chr = get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF);
    card = get_character_save_record(0xFFFF);
    memset((s32)((s32)chr), 0, 0x41C);
    TAdSinglePlyChrSelectGC__sub_8028DC1C();
    TObjPlayer::begin_action_from_char_select();
    memset((s32)((s32)card), 0, 0x2370);
    getDateStamp((DateStamp *)((s32 *)(((s32 *)&char_select_date_stamp))));
    DateToSeconds((DateStamp *)((s32 *)(((s32 *)&char_select_date_stamp))), (int *)(&card->secs));
    card->magic = 0xA205B064;
    card->fC = 0;
    card->f0 = 0;
    card->f14 = 1;
    memcpy(card->f18, TLobby__sub_80146D68(0), 0x1C);
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

s32 free_buffer__23TAdSinglePlyChrSelectGCFv(void) {
    if ((u32) guild_card_save_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)guild_card_save_file_buffer));
        guild_card_save_file_buffer = 0U;
        return 1;
    }
    return 0;
}

extern u32 system_save_file_buffer;

s32 free_data__23TAdSinglePlyChrSelectGCFv(void) {
    if ((u32) system_save_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)system_save_file_buffer));
        system_save_file_buffer = 0U;
        return 1;
    }
    return 0;
}

extern s32 guild_card_save_file_block_count;
extern u32 guild_card_save_file_buffer;

s32 buffer_init(void) {
    s32 temp_r31;

    if ((u32) guild_card_save_file_buffer == 0U) {
        temp_r31 = guild_card_save_file_block_count << 0xD;
        guild_card_save_file_buffer = alloc__22TQuestVmDownLoadServerFv(temp_r31);
        memset(guild_card_save_file_buffer, 0, temp_r31);
        return 1;
    }
    return 0;
}

extern s32 system_save_file_block_count;
extern u32 system_save_file_buffer;

s32 alloc_global_buffer(void) {
    s32 temp_r31;

    if ((u32) system_save_file_buffer == 0U) {
        temp_r31 = system_save_file_block_count << 0xD;
        system_save_file_buffer = alloc__22TQuestVmDownLoadServerFv(temp_r31);
        memset(system_save_file_buffer, 0, temp_r31);
        return 1;
    }
    return 0;
}

extern u32 character_save_file_buffer;

s32 free__23TAdSinglePlyChrSelectGCFv(void) {
    if ((u32) character_save_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)character_save_file_buffer));
        character_save_file_buffer = 0U;
        return 1;
    }
    return 0;
}

extern s32 character_save_file_block_count;
extern u32 character_save_file_buffer;

s32 init_buffer(void) {
    s32 temp_r31;

    if ((u32) character_save_file_buffer == 0U) {
        temp_r31 = character_save_file_block_count << 0xD;
        character_save_file_buffer = alloc__22TQuestVmDownLoadServerFv(temp_r31);
        memset(character_save_file_buffer, 0, temp_r31);
        return 1;
    }
    return 0;
}

extern u32 secondary_card_character_save_buffer;
extern u32 secondary_card_system_save_payload;

typedef char RecoveredGlobal_80201970_lbl_805137D8_size[sizeof(RecoveredGlobal_80201970_lbl_805137D8) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80201970_lbl_805137F8_size[sizeof(RecoveredGlobal_80201970_lbl_805137F8) == 0x24 ? 1 : -1];

void run_save_load_sequence__23TAdSinglePlyChrSelectGCFv(void) {
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
        prepare_save_data__23TAdSinglePlyChrSelectGCFv();
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
        if (TAdPlayerLoadGC__sub_801E1B50((void *)character_save_card_slot) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 7:
        if (load_chr_select_slot__23TAdSinglePlyChrSelectGCFv() == 0) {
            card_load_sequence_state = 8;
            break;
        }
        break;
    case 8:
        stop_pad_rumble();
        if (TAdPlayerLoadGC__sub_801E1B50((void *)character_save_card_slot) == 0) {
            card_load_sequence_state = 9;
            break;
        }
        break;
    case 9:
        apply_loaded_character__23TAdSinglePlyChrSelectGCFi(0);
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
        if (TAdPlayerLoadGC__sub_801E1B50((void *)character_save_card_slot) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 13:
        stop_pad_rumble();
        if (TAdPlayerLoadGC__sub_801E1B50((void *)card_load_channel) == 0) {
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
        if (TAdPlayerLoadGC__sub_801E1B50((void *)card_load_channel) == 0) {
            card_load_sequence_state = 0;
            TAdSinglePlyChrSelectGC::reset_quest_id();
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 15:
        if (TAdPlayerLoadGC__sub_801E1B50((void *)system_save_card_channel) == 0) {
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 17:
        if (TAdPlayerLoadGC__sub_801E1B50((void *)system_save_card_channel) == 0) {
            verify_save_checksum__23TAdSinglePlyChrSelectGCFi(1);
            if ((s32) card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                load_selected_char__23TAdSinglePlyChrSelectGCFv();
                break;
            }
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 16:
        if (TAdPlayerLoadGC__sub_801E1B50((void *)system_save_card_channel) == 0) {
            verify_save_checksum__23TAdSinglePlyChrSelectGCFi(0);
            if ((s32) card_load_followup_pending != 0) {
                card_load_followup_pending = 0;
                load_selected_char__23TAdSinglePlyChrSelectGCFv();
                break;
            }
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 18:
        stop_pad_rumble();
        if (TAdPlayerLoadGC__sub_801E1B50((void *) (1)) == 0) {
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 19:
        stop_pad_rumble();
        if (TAdPlayerLoadGC__sub_801E1B50((void *) (0)) == 0) {
            card_load_sequence_state = 0;
            lbl_805D49B4 = 0;
            break;
        }
        break;
    case 20:
        stop_pad_rumble();
        if (TAdPlayerLoadGC__sub_801E1B50((void *) (1)) == 0) {
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
        if (TAdPlayerLoadGC__sub_801E1B50((void *) (1)) == 0) {
            verify_save_checksum__23TAdSinglePlyChrSelectGCFv();
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

void release_all__23TAdSinglePlyChrSelectGCFv(void) {
    free_char_data_slots__23TAdSinglePlyChrSelectGCFPv(&chr_select_buffer_ptr_table.value);
    ((TAdSinglePlyChrSelectGC *)(&chr_select_request_buffer.value))->clear_slot_lists();
    if ((void *) selected_character_data != NULL) {
        __dt__12TPlyCharDataFv((s32)selected_character_data, 1);
    }
    if ((void *) (*(u8 * *)&active_character_save_record) != NULL) {
        ::operator delete(((void *) ((*(u8 * *)&active_character_save_record))));
    }
    if ((void *) (*(u8 * *)&guild_card_save_payload) != NULL) {
        ::operator delete(((void *) ((*(u8 * *)&guild_card_save_payload))));
    }
    if ((u32) card_character_save_buffer != 0U) {
        register_callback__23TAdSinglePlyChrSelectGCFis((void*)((void *) ((s32) card_character_save_buffer)), 1);
    }
    free__23TAdSinglePlyChrSelectGCFv();
    free_buffer__23TAdSinglePlyChrSelectGCFv();
    free_data__23TAdSinglePlyChrSelectGCFv();
}

}

}

namespace P802019F8 {
extern "C" {

s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
s32 __ct__12TPlyCharDataFv(s32);
s32 init_char_slots__23TAdSinglePlyChrSelectGCFi(s32);
void alloc_char_records__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 init_windows__23TAdSinglePlyChrSelectGCFi(s32);
void init_timestamped_data(void);
void reset_save_header__23TAdSinglePlyChrSelectGCFv(void);
s32 buffer_init(void);
s32 alloc_global_buffer(void);
s32 init_buffer();
s32 get_field_118__22TAdEnterSerialAccessGCFv();
typedef struct DVDDiskID_802019F8 { char gameName[4]; char company[2]; u8 diskNumber; u8 gameVersion; } DVDDiskID_802019F8;
DVDDiskID_802019F8 *DVDGetCurrentDiskID(void);
s32 strncpy(void *, char *, int);
s32 memset(void *, int, int);
extern s32 card_character_save_buffer;
extern s32 selected_character_data;
extern s32 active_character_save_record;
extern s32 guild_card_save_payload;
extern s32 system_save_payload;
extern s32 TAdSinglePlyChrSelectGC__selection_index;
extern s32 card_load_sequence_state;
extern s32 character_save_card_slot;
extern s32 card_load_channel;
extern s32 character_save_file_block_count;
extern s32 guild_card_save_file_block_count;
extern s32 system_save_file_block_count;
extern s32 card_load_followup_pending;
extern s32 chr_select_game_name_buffer;

void init_char_select_globals__23TAdSinglePlyChrSelectGCFv(void) {
    s32 sp10;
    s32 sp11;
    s32 spD;
    s32 spE;
    s32 spF;
    u8 spC;
    u32 sp8;
    s32 temp_r10;
    s32 temp_r3;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 var_ctr;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_12;
    s32 var_r0_13;
    s32 var_r0_14;
    s32 var_r0_15;
    s32 var_r0_16;
    s32 var_r0_17;
    s32 var_r0_18;
    s32 var_r0_19;
    s32 var_r0_20;
    s32 var_r0_21;
    s32 var_r0_22;
    s32 var_r0_23;
    s32 var_r0_24;
    s32 var_r0_25;
    s32 var_r0_26;
    s32 var_r0_27;
    s32 var_r0_28;
    s32 var_r0_29;
    s32 var_r0_2;
    s32 var_r0_30;
    s32 var_r0_31;
    s32 var_r0_32;
    s32 var_r0_33;
    s32 var_r0_34;
    s32 var_r0_35;
    s32 var_r0_36;
    s32 var_r0_37;
    s32 var_r0_38;
    s32 var_r0_39;
    s32 var_r0_3;
    s32 var_r0_40;
    s32 var_r0_41;
    s32 var_r0_42;
    s32 var_r0_43;
    s32 var_r0_44;
    s32 var_r0_45;
    s32 var_r0_46;
    s32 var_r0_47;
    s32 var_r0_48;
    s32 var_r0_49;
    s32 var_r0_4;
    s32 var_r0_50;
    s32 var_r0_51;
    s32 var_r0_52;
    s32 var_r0_53;
    s32 var_r0_54;
    s32 var_r0_55;
    s32 var_r0_56;
    s32 var_r0_57;
    s32 var_r0_58;
    s32 var_r0_59;
    s32 var_r0_5;
    s32 var_r0_60;
    s32 var_r0_61;
    s32 var_r0_62;
    s32 var_r0_63;
    s32 var_r0_64;
    s32 var_r0_65;
    s32 var_r0_66;
    s32 var_r0_67;
    s32 var_r0_68;
    s32 var_r0_69;
    s32 var_r0_6;
    s32 var_r0_70;
    s32 var_r0_71;
    s32 var_r0_72;
    s32 var_r0_73;
    s32 var_r0_74;
    s32 var_r0_75;
    s32 var_r0_76;
    s32 var_r0_77;
    s32 var_r0_78;
    s32 var_r0_79;
    s32 var_r0_7;
    s32 var_r0_80;
    s32 var_r0_81;
    s32 var_r0_82;
    s32 var_r0_83;
    s32 var_r0_84;
    s32 var_r0_85;
    s32 var_r0_86;
    s32 var_r0_87;
    s32 var_r0_88;
    s32 var_r0_89;
    s32 var_r0_8;
    s32 var_r0_90;
    s32 var_r0_91;
    s32 var_r0_92;
    s32 var_r0_93;
    s32 var_r0_94;
    s32 var_r0_95;
    s32 var_r0_96;
    s32 var_r0_9;
    u32 temp_r0;
    u8 *var_r4;
    u8 *temp_r4;

    TAdSinglePlyChrSelectGC__selection_index = 0;
    card_load_followup_pending = 0;
    alloc_char_records__23TAdSinglePlyChrSelectGCFi((s32)chr_select_buffer_ptr_table);
    ((TAdSinglePlyChrSelectGC *)chr_select_request_buffer)->reset_slot_lists();
    {
        DVDDiskID_802019F8 *id = DVDGetCurrentDiskID();
        strncpy((void *)&chr_select_game_name_buffer, id->gameName, 4);
    }
    getDateStamp((DateStamp *)char_select_date_stamp);
    DateToSeconds((DateStamp *)char_select_date_stamp, (int *)&sp8);
    temp_r0 = sp8 % 24;
    switch (temp_r0) {
    default:
        var_r0 = (s32)::operator new(0x1156C);
        if (var_r0 != 0) {
            var_r0 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0);
        }
        card_character_save_buffer = var_r0;
        var_r0_2 = (s32)::operator new(0x41C);
        if (var_r0_2 != 0) {
            var_r0_2 = __ct__12TPlyCharDataFv(var_r0_2);
        }
        selected_character_data = var_r0_2;
        var_r0_3 = (s32)::operator new(0x2370);
        if (var_r0_3 != 0) {
            var_r0_3 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_3)->init_char_record();
        }
        active_character_save_record = var_r0_3;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_4 = (s32)::operator new(0xE28C);
        if (var_r0_4 != 0) {
            var_r0_4 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_4);
        }
        guild_card_save_payload = var_r0_4;
        break;
    case 1:
        var_r0_5 = (s32)::operator new(0x1156C);
        if (var_r0_5 != 0) {
            var_r0_5 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_5);
        }
        card_character_save_buffer = var_r0_5;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_6 = (s32)::operator new(0x41C);
        if (var_r0_6 != 0) {
            var_r0_6 = __ct__12TPlyCharDataFv(var_r0_6);
        }
        selected_character_data = var_r0_6;
        var_r0_7 = (s32)::operator new(0x2370);
        if (var_r0_7 != 0) {
            var_r0_7 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_7)->init_char_record();
        }
        active_character_save_record = var_r0_7;
        var_r0_8 = (s32)::operator new(0xE28C);
        if (var_r0_8 != 0) {
            var_r0_8 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_8);
        }
        guild_card_save_payload = var_r0_8;
        break;
    case 2:
        var_r0_9 = (s32)::operator new(0x1156C);
        if (var_r0_9 != 0) {
            var_r0_9 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_9);
        }
        card_character_save_buffer = var_r0_9;
        var_r0_10 = (s32)::operator new(0xE28C);
        if (var_r0_10 != 0) {
            var_r0_10 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_10);
        }
        guild_card_save_payload = var_r0_10;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_11 = (s32)::operator new(0x41C);
        if (var_r0_11 != 0) {
            var_r0_11 = __ct__12TPlyCharDataFv(var_r0_11);
        }
        selected_character_data = var_r0_11;
        var_r0_12 = (s32)::operator new(0x2370);
        if (var_r0_12 != 0) {
            var_r0_12 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_12)->init_char_record();
        }
        active_character_save_record = var_r0_12;
        break;
    case 3:
        var_r0_13 = (s32)::operator new(0x1156C);
        if (var_r0_13 != 0) {
            var_r0_13 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_13);
        }
        card_character_save_buffer = var_r0_13;
        var_r0_14 = (s32)::operator new(0xE28C);
        if (var_r0_14 != 0) {
            var_r0_14 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_14);
        }
        guild_card_save_payload = var_r0_14;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_15 = (s32)::operator new(0x41C);
        if (var_r0_15 != 0) {
            var_r0_15 = __ct__12TPlyCharDataFv(var_r0_15);
        }
        selected_character_data = var_r0_15;
        var_r0_16 = (s32)::operator new(0x2370);
        if (var_r0_16 != 0) {
            var_r0_16 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_16)->init_char_record();
        }
        active_character_save_record = var_r0_16;
        break;
    case 4:
        var_r0_17 = (s32)::operator new(0x1156C);
        if (var_r0_17 != 0) {
            var_r0_17 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_17);
        }
        card_character_save_buffer = var_r0_17;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_18 = (s32)::operator new(0xE28C);
        if (var_r0_18 != 0) {
            var_r0_18 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_18);
        }
        guild_card_save_payload = var_r0_18;
        var_r0_19 = (s32)::operator new(0x41C);
        if (var_r0_19 != 0) {
            var_r0_19 = __ct__12TPlyCharDataFv(var_r0_19);
        }
        selected_character_data = var_r0_19;
        var_r0_20 = (s32)::operator new(0x2370);
        if (var_r0_20 != 0) {
            var_r0_20 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_20)->init_char_record();
        }
        active_character_save_record = var_r0_20;
        break;
    case 5:
        var_r0_21 = (s32)::operator new(0x1156C);
        if (var_r0_21 != 0) {
            var_r0_21 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_21);
        }
        card_character_save_buffer = var_r0_21;
        var_r0_22 = (s32)::operator new(0xE28C);
        if (var_r0_22 != 0) {
            var_r0_22 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_22);
        }
        guild_card_save_payload = var_r0_22;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_23 = (s32)::operator new(0x41C);
        if (var_r0_23 != 0) {
            var_r0_23 = __ct__12TPlyCharDataFv(var_r0_23);
        }
        selected_character_data = var_r0_23;
        var_r0_24 = (s32)::operator new(0x2370);
        if (var_r0_24 != 0) {
            var_r0_24 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_24)->init_char_record();
        }
        active_character_save_record = var_r0_24;
        break;
    case 6:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_25 = (s32)::operator new(0xE28C);
        if (var_r0_25 != 0) {
            var_r0_25 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_25);
        }
        guild_card_save_payload = var_r0_25;
        var_r0_26 = (s32)::operator new(0x1156C);
        if (var_r0_26 != 0) {
            var_r0_26 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_26);
        }
        card_character_save_buffer = var_r0_26;
        var_r0_27 = (s32)::operator new(0x41C);
        if (var_r0_27 != 0) {
            var_r0_27 = __ct__12TPlyCharDataFv(var_r0_27);
        }
        selected_character_data = var_r0_27;
        var_r0_28 = (s32)::operator new(0x2370);
        if (var_r0_28 != 0) {
            var_r0_28 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_28)->init_char_record();
        }
        active_character_save_record = var_r0_28;
        break;
    case 7:
        var_r0_29 = (s32)::operator new(0xE28C);
        if (var_r0_29 != 0) {
            var_r0_29 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_29);
        }
        guild_card_save_payload = var_r0_29;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_30 = (s32)::operator new(0x1156C);
        if (var_r0_30 != 0) {
            var_r0_30 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_30);
        }
        card_character_save_buffer = var_r0_30;
        var_r0_31 = (s32)::operator new(0x41C);
        if (var_r0_31 != 0) {
            var_r0_31 = __ct__12TPlyCharDataFv(var_r0_31);
        }
        selected_character_data = var_r0_31;
        var_r0_32 = (s32)::operator new(0x2370);
        if (var_r0_32 != 0) {
            var_r0_32 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_32)->init_char_record();
        }
        active_character_save_record = var_r0_32;
        break;
    case 8:
        var_r0_33 = (s32)::operator new(0x1156C);
        if (var_r0_33 != 0) {
            var_r0_33 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_33);
        }
        card_character_save_buffer = var_r0_33;
        var_r0_34 = (s32)::operator new(0xE28C);
        if (var_r0_34 != 0) {
            var_r0_34 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_34);
        }
        guild_card_save_payload = var_r0_34;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_35 = (s32)::operator new(0x41C);
        if (var_r0_35 != 0) {
            var_r0_35 = __ct__12TPlyCharDataFv(var_r0_35);
        }
        selected_character_data = var_r0_35;
        var_r0_36 = (s32)::operator new(0x2370);
        if (var_r0_36 != 0) {
            var_r0_36 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_36)->init_char_record();
        }
        active_character_save_record = var_r0_36;
        break;
    case 9:
        var_r0_37 = (s32)::operator new(0x1156C);
        if (var_r0_37 != 0) {
            var_r0_37 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_37);
        }
        card_character_save_buffer = var_r0_37;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_38 = (s32)::operator new(0xE28C);
        if (var_r0_38 != 0) {
            var_r0_38 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_38);
        }
        guild_card_save_payload = var_r0_38;
        var_r0_39 = (s32)::operator new(0x41C);
        if (var_r0_39 != 0) {
            var_r0_39 = __ct__12TPlyCharDataFv(var_r0_39);
        }
        selected_character_data = var_r0_39;
        var_r0_40 = (s32)::operator new(0x2370);
        if (var_r0_40 != 0) {
            var_r0_40 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_40)->init_char_record();
        }
        active_character_save_record = var_r0_40;
        break;
    case 10:
        var_r0_41 = (s32)::operator new(0x1156C);
        if (var_r0_41 != 0) {
            var_r0_41 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_41);
        }
        card_character_save_buffer = var_r0_41;
        var_r0_42 = (s32)::operator new(0xE28C);
        if (var_r0_42 != 0) {
            var_r0_42 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_42);
        }
        guild_card_save_payload = var_r0_42;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_43 = (s32)::operator new(0x41C);
        if (var_r0_43 != 0) {
            var_r0_43 = __ct__12TPlyCharDataFv(var_r0_43);
        }
        selected_character_data = var_r0_43;
        var_r0_44 = (s32)::operator new(0x2370);
        if (var_r0_44 != 0) {
            var_r0_44 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_44)->init_char_record();
        }
        active_character_save_record = var_r0_44;
        break;
    case 11:
        var_r0_45 = (s32)::operator new(0x1156C);
        if (var_r0_45 != 0) {
            var_r0_45 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_45);
        }
        card_character_save_buffer = var_r0_45;
        var_r0_46 = (s32)::operator new(0xE28C);
        if (var_r0_46 != 0) {
            var_r0_46 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_46);
        }
        guild_card_save_payload = var_r0_46;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_47 = (s32)::operator new(0x41C);
        if (var_r0_47 != 0) {
            var_r0_47 = __ct__12TPlyCharDataFv(var_r0_47);
        }
        selected_character_data = var_r0_47;
        var_r0_48 = (s32)::operator new(0x2370);
        if (var_r0_48 != 0) {
            var_r0_48 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_48)->init_char_record();
        }
        active_character_save_record = var_r0_48;
        break;
    case 12:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_49 = (s32)::operator new(0xE28C);
        if (var_r0_49 != 0) {
            var_r0_49 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_49);
        }
        guild_card_save_payload = var_r0_49;
        var_r0_50 = (s32)::operator new(0x1156C);
        if (var_r0_50 != 0) {
            var_r0_50 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_50);
        }
        card_character_save_buffer = var_r0_50;
        var_r0_51 = (s32)::operator new(0x41C);
        if (var_r0_51 != 0) {
            var_r0_51 = __ct__12TPlyCharDataFv(var_r0_51);
        }
        selected_character_data = var_r0_51;
        var_r0_52 = (s32)::operator new(0x2370);
        if (var_r0_52 != 0) {
            var_r0_52 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_52)->init_char_record();
        }
        active_character_save_record = var_r0_52;
        break;
    case 13:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_53 = (s32)::operator new(0x1156C);
        if (var_r0_53 != 0) {
            var_r0_53 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_53);
        }
        card_character_save_buffer = var_r0_53;
        var_r0_54 = (s32)::operator new(0xE28C);
        if (var_r0_54 != 0) {
            var_r0_54 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_54);
        }
        guild_card_save_payload = var_r0_54;
        var_r0_55 = (s32)::operator new(0x41C);
        if (var_r0_55 != 0) {
            var_r0_55 = __ct__12TPlyCharDataFv(var_r0_55);
        }
        selected_character_data = var_r0_55;
        var_r0_56 = (s32)::operator new(0x2370);
        if (var_r0_56 != 0) {
            var_r0_56 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_56)->init_char_record();
        }
        active_character_save_record = var_r0_56;
        break;
    case 14:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_57 = (s32)::operator new(0x1156C);
        if (var_r0_57 != 0) {
            var_r0_57 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_57);
        }
        card_character_save_buffer = var_r0_57;
        var_r0_58 = (s32)::operator new(0xE28C);
        if (var_r0_58 != 0) {
            var_r0_58 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_58);
        }
        guild_card_save_payload = var_r0_58;
        var_r0_59 = (s32)::operator new(0x41C);
        if (var_r0_59 != 0) {
            var_r0_59 = __ct__12TPlyCharDataFv(var_r0_59);
        }
        selected_character_data = var_r0_59;
        var_r0_60 = (s32)::operator new(0x2370);
        if (var_r0_60 != 0) {
            var_r0_60 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_60)->init_char_record();
        }
        active_character_save_record = var_r0_60;
        break;
    case 15:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_61 = (s32)::operator new(0xE28C);
        if (var_r0_61 != 0) {
            var_r0_61 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_61);
        }
        guild_card_save_payload = var_r0_61;
        var_r0_62 = (s32)::operator new(0x1156C);
        if (var_r0_62 != 0) {
            var_r0_62 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_62);
        }
        card_character_save_buffer = var_r0_62;
        var_r0_63 = (s32)::operator new(0x41C);
        if (var_r0_63 != 0) {
            var_r0_63 = __ct__12TPlyCharDataFv(var_r0_63);
        }
        selected_character_data = var_r0_63;
        var_r0_64 = (s32)::operator new(0x2370);
        if (var_r0_64 != 0) {
            var_r0_64 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_64)->init_char_record();
        }
        active_character_save_record = var_r0_64;
        break;
    case 16:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_65 = (s32)::operator new(0x1156C);
        if (var_r0_65 != 0) {
            var_r0_65 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_65);
        }
        card_character_save_buffer = var_r0_65;
        var_r0_66 = (s32)::operator new(0xE28C);
        if (var_r0_66 != 0) {
            var_r0_66 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_66);
        }
        guild_card_save_payload = var_r0_66;
        var_r0_67 = (s32)::operator new(0x41C);
        if (var_r0_67 != 0) {
            var_r0_67 = __ct__12TPlyCharDataFv(var_r0_67);
        }
        selected_character_data = var_r0_67;
        var_r0_68 = (s32)::operator new(0x2370);
        if (var_r0_68 != 0) {
            var_r0_68 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_68)->init_char_record();
        }
        active_character_save_record = var_r0_68;
        break;
    case 17:
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_69 = (s32)::operator new(0xE28C);
        if (var_r0_69 != 0) {
            var_r0_69 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_69);
        }
        guild_card_save_payload = var_r0_69;
        var_r0_70 = (s32)::operator new(0x1156C);
        if (var_r0_70 != 0) {
            var_r0_70 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_70);
        }
        card_character_save_buffer = var_r0_70;
        var_r0_71 = (s32)::operator new(0x41C);
        if (var_r0_71 != 0) {
            var_r0_71 = __ct__12TPlyCharDataFv(var_r0_71);
        }
        selected_character_data = var_r0_71;
        var_r0_72 = (s32)::operator new(0x2370);
        if (var_r0_72 != 0) {
            var_r0_72 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_72)->init_char_record();
        }
        active_character_save_record = var_r0_72;
        break;
    case 18:
        var_r0_73 = (s32)::operator new(0xE28C);
        if (var_r0_73 != 0) {
            var_r0_73 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_73);
        }
        guild_card_save_payload = var_r0_73;
        var_r0_74 = (s32)::operator new(0x1156C);
        if (var_r0_74 != 0) {
            var_r0_74 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_74);
        }
        card_character_save_buffer = var_r0_74;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_75 = (s32)::operator new(0x41C);
        if (var_r0_75 != 0) {
            var_r0_75 = __ct__12TPlyCharDataFv(var_r0_75);
        }
        selected_character_data = var_r0_75;
        var_r0_76 = (s32)::operator new(0x2370);
        if (var_r0_76 != 0) {
            var_r0_76 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_76)->init_char_record();
        }
        active_character_save_record = var_r0_76;
        break;
    case 19:
        var_r0_77 = (s32)::operator new(0xE28C);
        if (var_r0_77 != 0) {
            var_r0_77 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_77);
        }
        guild_card_save_payload = var_r0_77;
        var_r0_78 = (s32)::operator new(0x1156C);
        if (var_r0_78 != 0) {
            var_r0_78 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_78);
        }
        card_character_save_buffer = var_r0_78;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_79 = (s32)::operator new(0x41C);
        if (var_r0_79 != 0) {
            var_r0_79 = __ct__12TPlyCharDataFv(var_r0_79);
        }
        selected_character_data = var_r0_79;
        var_r0_80 = (s32)::operator new(0x2370);
        if (var_r0_80 != 0) {
            var_r0_80 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_80)->init_char_record();
        }
        active_character_save_record = var_r0_80;
        break;
    case 20:
        var_r0_81 = (s32)::operator new(0xE28C);
        if (var_r0_81 != 0) {
            var_r0_81 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_81);
        }
        guild_card_save_payload = var_r0_81;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_82 = (s32)::operator new(0x1156C);
        if (var_r0_82 != 0) {
            var_r0_82 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_82);
        }
        card_character_save_buffer = var_r0_82;
        var_r0_83 = (s32)::operator new(0x41C);
        if (var_r0_83 != 0) {
            var_r0_83 = __ct__12TPlyCharDataFv(var_r0_83);
        }
        selected_character_data = var_r0_83;
        var_r0_84 = (s32)::operator new(0x2370);
        if (var_r0_84 != 0) {
            var_r0_84 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_84)->init_char_record();
        }
        active_character_save_record = var_r0_84;
        break;
    case 21:
        var_r0_85 = (s32)::operator new(0xE28C);
        if (var_r0_85 != 0) {
            var_r0_85 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_85);
        }
        guild_card_save_payload = var_r0_85;
        var_r0_86 = (s32)::operator new(0x1156C);
        if (var_r0_86 != 0) {
            var_r0_86 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_86);
        }
        card_character_save_buffer = var_r0_86;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_87 = (s32)::operator new(0x41C);
        if (var_r0_87 != 0) {
            var_r0_87 = __ct__12TPlyCharDataFv(var_r0_87);
        }
        selected_character_data = var_r0_87;
        var_r0_88 = (s32)::operator new(0x2370);
        if (var_r0_88 != 0) {
            var_r0_88 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_88)->init_char_record();
        }
        active_character_save_record = var_r0_88;
        break;
    case 22:
        var_r0_89 = (s32)::operator new(0xE28C);
        if (var_r0_89 != 0) {
            var_r0_89 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_89);
        }
        guild_card_save_payload = var_r0_89;
        system_save_payload = (s32)::operator new(0x11C);
        var_r0_90 = (s32)::operator new(0x1156C);
        if (var_r0_90 != 0) {
            var_r0_90 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_90);
        }
        card_character_save_buffer = var_r0_90;
        var_r0_91 = (s32)::operator new(0x41C);
        if (var_r0_91 != 0) {
            var_r0_91 = __ct__12TPlyCharDataFv(var_r0_91);
        }
        selected_character_data = var_r0_91;
        var_r0_92 = (s32)::operator new(0x2370);
        if (var_r0_92 != 0) {
            var_r0_92 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_92)->init_char_record();
        }
        active_character_save_record = var_r0_92;
        break;
    case 23:
        var_r0_93 = (s32)::operator new(0xE28C);
        if (var_r0_93 != 0) {
            var_r0_93 = init_windows__23TAdSinglePlyChrSelectGCFi(var_r0_93);
        }
        guild_card_save_payload = var_r0_93;
        var_r0_94 = (s32)::operator new(0x2370);
        if (var_r0_94 != 0) {
            var_r0_94 = (s32)((TAdSinglePlyChrSelectGC *)var_r0_94)->init_char_record();
        }
        active_character_save_record = var_r0_94;
        var_r0_95 = (s32)::operator new(0x41C);
        if (var_r0_95 != 0) {
            var_r0_95 = __ct__12TPlyCharDataFv(var_r0_95);
        }
        selected_character_data = var_r0_95;
        var_r0_96 = (s32)::operator new(0x1156C);
        if (var_r0_96 != 0) {
            var_r0_96 = init_char_slots__23TAdSinglePlyChrSelectGCFi(var_r0_96);
        }
        card_character_save_buffer = var_r0_96;
        system_save_payload = (s32)::operator new(0x11C);
        break;
    }
    memset((void *)selected_character_data, 0, 0x41C);
    memset((void *)active_character_save_record, 0, 0x2370);
    memset((void *)card_character_save_buffer, 0, 0x1156C);
    memset((void *)system_save_payload, 0, 0x11C);
    reset_save_header__23TAdSinglePlyChrSelectGCFv();
    init_timestamped_data();
    character_save_file_block_count = 0xB;
    guild_card_save_file_block_count = 0xA;
    system_save_file_block_count = 3;
    init_buffer();
    buffer_init();
    alloc_global_buffer();
    card_load_sequence_state = 0;
    character_save_card_slot = (s32) get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
    card_load_channel = (s32) get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
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

}
}

namespace P801FBF54 {
extern "C" {

void free_callbacks__23TAdSinglePlyChrSelectGCFv(void) {
    if ((u32) secondary_card_character_save_buffer != 0U) {
        register_callback__23TAdSinglePlyChrSelectGCFis((void*)((void*)secondary_card_character_save_buffer), 1);
        secondary_card_character_save_buffer = 0U;
    }
    if ((u32) secondary_card_system_save_payload != 0U) {
        ::operator delete((void *)secondary_card_system_save_payload);
        secondary_card_system_save_payload = 0U;
    }
}

void alloc_char_buffers__23TAdSinglePlyChrSelectGCFv(void) {
    s32 temp_r3;
    s32 var_r0;
    s32 var_r3;
    s32 var_r4;
    s32 var_r5;
    var_r3 = 0x10000;
    var_r3 = 0x1156C;
    temp_r3 = (s32)::operator new(0x1156C);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = init_char_slots__23TAdSinglePlyChrSelectGCFi(temp_r3);
    }
    (*(s32 *)&secondary_card_character_save_buffer) = var_r0;
    var_r3 = 0x11C;
    (*(s32 *)&secondary_card_system_save_payload) = (s32)::operator new(0x11C);
    var_r4 = 0x10000;
    var_r3 = (*(s32 *)&secondary_card_character_save_buffer);
    var_r5 = 0x1156C;
    var_r4 = 0;
    memset(var_r3, 0, 0x1156C);
    var_r3 = (*(s32 *)&secondary_card_system_save_payload);
    var_r4 = 0;
    var_r5 = 0x11C;
    memset(var_r3, 0, 0x11C);
}

int get_serial_access_field_118__23TAdSinglePlyChrSelectGCFPv(void* p) { return get_field_118__22TAdEnterSerialAccessGCFv(p); }

}

}

namespace P80202978 {
extern "C" {
extern u8 *secondary_card_system_save_payload;
extern void *system_save_payload;
extern s32 active_character_save_record;
extern s32 selected_character_data;
s32 is_split_screen();
s32 get_split_screen_character_save_record(u32);
s32 get_char_table_entry__23TAdSinglePlyChrSelectGCFi(u32);

s32 get_serial_result__22TAdEnterSerialAccessGCFv(void) {
    return *(s32 *)((s8 *)secondary_card_system_save_payload + 0x118);
}

s32 get_field_118__22TAdEnterSerialAccessGCFv(void) {
    return *(s32 *)((s8 *)system_save_payload + 0x118);
}

s32 get_character_save_record(u32 arg0) {
    if (is_split_screen() != 0) {
        if (arg0 == 0xFFFF) {
            return get_split_screen_character_save_record(0U);
        }
        return get_split_screen_character_save_record(arg0);
    }
    return active_character_save_record;
}

s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0) {
    if (is_split_screen() != 0) {
        if (arg0 == 0xFFFF) {
            return get_char_table_entry__23TAdSinglePlyChrSelectGCFi(0U);
        }
        return get_char_table_entry__23TAdSinglePlyChrSelectGCFi(arg0);
    }
    return selected_character_data;
}
}
}
