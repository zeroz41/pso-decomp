#include "pso/network/protocol/packet_classes.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/system/memory.h"
#include "types.h"
#include <string.h>
#include "pso/network/TProtocol.h"
#include "pso/audio/SoundRequestVoice.h"
#include "pso/unk/GuildCardRecord.h"
#include "pso/network/TLobby.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/unk/TLobby_80242910.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "dolphin/mtx.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/AngleLookup.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include <dolphin/os/OSInterrupt.h>
#include "pso/unk/TLobby_8001D6A0.h"


typedef struct Src_8024220C
{
  s32 id;
  char name[0x30];
  char list[0x30];
  u8 f64[0xC];
  u8 ext[0x64];
} Src_8024220C;

// Their constructors run from __sinit_GuildCardRecord_cpp, spelled out below because the
// original's static initializer precedes this file's inline copies.
#pragma push
#pragma suppress_init_code on
GuildCardRecord selected_guild_card_record;
// inferred: the com-card list; init_player_entry fills it, com_card_entry_count records are live
GuildCardRecord com_card_entries[8];
#pragma pop

extern "C" {
s32 __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(void *, void *);
}

#pragma push

typedef struct Tag_802421C4 { s32 a; s32 b; } Tag_802421C4;

#pragma inline_depth(1)
#pragma dont_inline off
struct Pair_80242380 {
    u8 c[8];
};

struct Ext_80242380 {
    u8 bytes[0x64];
};

typedef struct Entry_80242380 {
    s32 id;
    s32 f4;
    char name[0x11];
    char s19[0x11];
    char s2A[0x11];
    char s3B[0x11];
    Pair_80242380 f4C;
    s32 f54;
    Ext_80242380 ext;
} Entry_80242380;

s32 lbl_805D63D8;
int com_card_entry_count;
extern "C" {
void __copy(void *, void *, int);
}

void handle_user_search_answer(TUserAns &response) { add_found_user_com_card(response); }

void TLobby::send_find_user_self_tag(s32 gc_num) {
    if (protocol_instance != NULL) {
        Tag_802421C4 tag = *(Tag_802421C4 *)((u8 *)protocol_instance + 0x1900);
        protocol_instance->send_find_user(*(TPlyGuildCardTag *)&tag, gc_num);
    }
}

typedef struct Src_8024220C Src_8024220C;
extern "C" {
void load_selected_guild_card_record(Src_8024220C *src) {
  char *list;
  char *cursor;
  selected_guild_card_record.id = src->id;
  selected_guild_card_record.serial = 0;
  memset(selected_guild_card_record.name, 0, 0x11);
  strncpy(selected_guild_card_record.name, src->name, 0x10);
  selected_guild_card_record.name[0x10] = 0;
  list = src->list;
  list = build_text_from_comma_list(list);
  cursor = list;
  cursor = parse_csv_token(cursor, selected_guild_card_record.s19);
  cursor = parse_csv_token(cursor, selected_guild_card_record.s2A);
  cursor = parse_csv_token(cursor, selected_guild_card_record.s2A);
  parse_csv_token(cursor, selected_guild_card_record.s3B);
  TLobby__sub_802422EC(selected_guild_card_record.f4C, src->f64);
  __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(&selected_guild_card_record.ext, &src->ext);
}
}

void TLobby__sub_802422EC(void *dst, void *src) {
    *(s32 *)((s8 *)dst + 0) = (s32) *(s32 *)((s8 *)src + 0);
    *(s32 *)((s8 *)dst + 4) = (s32) *(s32 *)((s8 *)src + 4);
    *(s16 *)((s8 *)dst + 8) = (s16) *(s16 *)((s8 *)src + 8);
}

void find_and_load_com_card(u32 serial) {
    s32 n;
    s32 i;
    n = TLobby::get_com_card_data();
    for (i = 0; i < n; i++) {
        if (serial == ((GuildCardRecord *)TLobby::get_com_card_entry(i))->get_serial()) break;
    }
    if (i < n) {
        TLobby::copy_com_card_entry((Entry_80242380 *)&selected_guild_card_record, (Entry_80242380 *)(TLobby::get_com_card_entry(i)));
    }
}

extern "C" {
Entry_80242380 *copy_com_card_entry__6TLobbyFPvPv(Entry_80242380 *dst, Entry_80242380 *src) {
    dst->id = src->id;
    dst->f4 = src->f4;
    __copy(dst->name, src->name, 0x11);
    __copy(dst->s19, src->s19, 0x11);
    __copy(dst->s2A, src->s2A, 0x11);
    __copy(dst->s3B, src->s3B, 0x11);
    dst->f4C = src->f4C;
    dst->f54 = src->f54;
    dst->ext = src->ext;
    return dst;
}
}

void*TLobby::get_com_card_entry(int a0) { return &com_card_entries[a0]; }

char *parse_csv_token(char *src, char *dst) {
    s32 i;
    for (i = 0x10; i != 0; i--) {
        char c = *src;
        if (c == 0) break;
        src++;
        if (c == ',') break;
        *dst = c;
        dst++;
    }
    if (*src == ',') {
        src++;
    }
    *dst = 0;
    return src;
}

char *skip_to_comma_field(char *s, s32 a, s32 b) {
    s32 i;
    for (i = a + 1; i < b;) {
        if (*s == '\0') return s;
        if (*s++ == ',') i++;
    }
    return s;
}

char *build_text_from_comma_list(char *list) {
    char buf[0x11];
    char *s;
    char *d;
    s32 i;
    s32 count;
    text_builder_reset();
    s = list;
    count = 1;
    while (*s != '\0') {
        if (*s++ == ',') {
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        TWindowSubStatusDisp::append_comma();
        s = skip_to_comma_field(list, i, count);
        d = buf;
        while (*s != '\0' && *s != ',') {
            *d++ = *s++;
        }
        *d = '\0';
        text_builder_append(buf);
    }
    return get_shared_text_buffer();
}

void jump_to_guild_card_owner(GuildCardRecord *entry) {
    if (TLobby::protocol_instance != NULL) {
        memset(lobby_ship_name, 0, 0x11);
        strncpy(lobby_ship_name, entry->s19, 0x10);
        lobby_ship_name[0x10] = 0;
        TLobby::protocol_instance->seq_jump(entry->f4C, entry->ext);
    }
}
#pragma pop


void init_player_entry(GuildCardRecord *entry, u8 *response) {
    s32 serial_no;
    char *p;

    entry->id = *(s32 *)((s8 *)response + 0xC);
    serial_no = lbl_805D63D8;
    lbl_805D63D8 = serial_no + 1;
    entry->serial = serial_no;
    ((s32 (*)(void*, void*, int))TLobby__sub_802422EC)(entry->f4C, response + 0x10, serial_no);
    __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(&entry->ext, response + 0x60);
    GuildCardSlot *card = TWindowSubComCard::find_card_by_id(entry->get_id());
    if (card == NULL) {
        strncpy(entry->name, entry->get_sub_disp_ptr(), 0x10);
    } else {
        strncpy(entry->name, card->get_name(), 0x10);
    }
    entry->name[0x10] = 0;
    p = build_text_from_comma_list((char *)(response + 0x1C));
    p = parse_csv_token(p, entry->s19);
    p = parse_csv_token(p, entry->s2A);
    p = parse_csv_token(p, entry->s2A);
    parse_csv_token(p, entry->s3B);
}

void remove_com_card_entry(s32 index) {
    u8 *lobby;
    if (index < 7) {
        lobby = (u8 *)&com_card_entries[index];
        move_words(reinterpret_cast<void *>(lobby), reinterpret_cast<const void *>(lobby + 0xBC), static_cast<u32>((7 - index) * 0xBC) >> 2);
    }
    (com_card_entry_count) -= 1;
}

void add_found_user_com_card(TUserAns &response) {
    GuildCardRecord *entry;
    s32 slot = remove_com_card_by_id(response.found_guildcard);
    entry = com_card_entries;
    entry += slot;
    init_player_entry(entry, reinterpret_cast<u8 *>(&response));
    com_card_entry_count++;
    set_short_mail_flag_bit2();
}

s32 remove_com_card_by_id(u32 id) {
    s32 i;
    s32 n;
    n = TLobby::get_com_card_data();
    for (i = 0; i < n; i++) {
        if (id == ((u32)reinterpret_cast<GuildCardRecord *>(TLobby::get_com_card_entry(i))->get_id())) {
            remove_com_card_entry(i);
            n -= 1;
        }
    }
    if (n < 8) {
        return n;
    }
    remove_com_card_entry(0);
    return 7;
}

void TLobby::reset_com_card_list() { com_card_entry_count = 0; TLobby::clear_flag_bit2(); }

void TLobby::reset_state() { TLobby::reset_com_card_list(); }
void reset_com_card_list_callback(void) { TLobby::reset_com_card_list(); }


extern "C" {
GuildCardRecord *__ct__15GuildCardRecordFv(void *p);
void *__construct_array(void *ptr, GuildCardRecord *(*ctor)(void *), void *dtor, u32 size, u32 n);
static void __sinit_GuildCardRecord_cpp();
}
__declspec(section ".ctors") static void *const com_card_global_initializer = (void *)__sinit_GuildCardRecord_cpp;

static void __sinit_GuildCardRecord_cpp() {
    __ct__15GuildCardRecordFv(&selected_guild_card_record);
    __construct_array(com_card_entries, __ct__15GuildCardRecordFv, NULL, sizeof(GuildCardRecord), 8);
}

GuildCardRecord::GuildCardRecord() {}

s32 GuildCardRecord::get_serial() const { return serial; }

int TLobby::get_com_card_data() { return com_card_entry_count; }

char *GuildCardRecord::get_sub_disp_ptr() { return ext.player_name; }

s32 GuildCardRecord::get_id() { return id; }



void set_short_mail_flag_bit2(void) {
    short_mail_flags |= 4;
}

void TLobby::clear_flag_bit2() {
    short_mail_flags &= 0xFFFFFFFB;
}
