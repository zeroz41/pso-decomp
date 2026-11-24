#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/item/TItemData.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include <string.h>
#include "pso/ui/window/TWindowCtrl.h"

struct SRock_80224544_8022448C;

struct O_80225B90 { u8 pad[0x20]; char name[1]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct Item_8022525C
{
  u8 b0;
  u8 b1;
  u8 b2;
  u8 pad3[7];
  u8 b12;
  u8 b13;
  u8 padC[8];
} Item_8022525C;

typedef struct Pool_8022525C
{
  u8 b[0x68];
} Pool_8022525C;

typedef struct Pair_8022525C
{
  s32 a;
  s32 b;
} Pair_8022525C;

typedef struct Ent_8022525C
{
  u8 id;
  u8 count;
} Ent_8022525C;

typedef struct Tier_8022525C
{
  Ent_8022525C *ents;
  u8 n;
} Tier_8022525C;

typedef struct Hdr_8022525C
{
  Tier_8022525C *tiers;
} Hdr_8022525C;

extern "C" {

ShortMailEntry lbl_80513F70[8];
s32 lbl_805D6270;
int lobby_short_mail_entry_count;

void try_close__6TLobbyFPv(void* p) { if (((TLobby *)p)->is_name_too_long() == 0) { TLobby__sub_80225A08(p); } }

void TLobby::send_simple_mail(s32 arg0, void *src) {
    union {
        ShortMailPacketBuffer pkt;
        u8 b[0x228];
    } t;
    saddr mode;
    ((TLobby *)(&t))->init_guild_card_tag();
    if (protocol_instance != NULL) {
        mode = TWindowSubComCard::get_keyboard_mode();
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&t.b[4], &protocol_instance->m_guildcard_tag);
        strncpy((char *)&t.b[0xC], reinterpret_cast<GuildCardEntry *>(mode)->get_name(), 0x17);
        t.pkt.target_card_id = arg0;
        t.b[0x23] = 0;
        strncpy((char *)&t.b[0x20], (char *)src, 0xAB);
        t.b[0xCB] = 0;
        protocol_instance->send_simple_mail(*(TChatMessage *)&t);
    }
}

void TLobby__sub_802258C8(void) {
  s32 i;
  ShortMailEntry *entry;
  i = 0;
  entry = lbl_80513F70;
  do
  {
    if (entry->is_active() != 0)
    {
      entry->clear_unread();
    }
    i += 1;
    entry++;
  }
  while (i < 8);
}

ShortMailEntry *TLobby::find_short_mail_by_id(u32 id) {
    s32 count = ((s32)TLobby::get_short_mail_ctrl());
    s32 i;
    for (i = 0; i < count; i++) {
        ShortMailEntry *entry = get_short_mail_entry(i);
        if (id == entry->get_id()) {
            return entry;
        }
    }
    return 0;
}

}

ShortMailEntry *get_short_mail_entry(int index) {
    char *storage = reinterpret_cast<char *>(&lbl_80513F70);
    // Retain retail register allocation for the backing array address.
    if ((!storage) && (!storage)) {
    }
    return reinterpret_cast<ShortMailEntry *>(storage + index * sizeof(ShortMailEntry));
}

s32 TLobby::find_free_slot() {
  s32 var_r31;
  ShortMailEntry *entry;
  var_r31 = 0;
  entry = lbl_80513F70;
  loop_1:
  if (entry->is_active() == 0)
  {
    return var_r31;
  }
  var_r31 += 1;
  entry++;
  if (var_r31 >= 8)
  {
    TLobby::remove_entry_at(0);
    return 7;
  }
  goto loop_1;
}


void TLobby__sub_80225A08(void *p) {
    s32 slot = TLobby::find_free_slot();
    char *storage = reinterpret_cast<char *>(&lbl_80513F70);
    storage += slot * sizeof(ShortMailEntry);
    reinterpret_cast<ShortMailEntry *>(storage)->fill_from_packet(static_cast<u8 *>(p));
    lobby_short_mail_entry_count++;
    TLobby__sub_80225CB8();
    play_sound_effect(0x52D17, 0, 0, 0);
}

void remove_short_mail_by_id(u32 id) {
    s32 count = TLobby::get_short_mail_ctrl();
    s32 i;
    for (i = 0; i < count; i++) {
        if (id == get_short_mail_entry(i)->get_id()) {
            TLobby::remove_entry_at(i);
            return;
        }
    }
}

void TLobby::remove_entry_at(s32 idx) {
    if (idx < 7) {
        ShortMailEntry *entry = &lbl_80513F70[idx];
        move_words(entry, entry + 1, (7 - idx) * sizeof(ShortMailEntry) / sizeof(u32));
    }
    lbl_80513F70[7].flags &= ~1;
    lobby_short_mail_entry_count--;
}

void TLobby::clear_all_entries(void* _w0) {
    s32 i;
    ShortMailEntry *entry;
    lbl_805D6270 = 0;
    lobby_short_mail_entry_count = 0;
    TLobby::clear_lobby_flag();
    entry = lbl_80513F70;
    for (i = 0; i < 8; i++) {
        entry->flags &= ~1;
        entry++;
    }
}

s32 TLobby::is_name_too_long() {
    s32 i = 0;
    char *p = ((O_80225B90 *)this)->name;
    while (*p++ != 0) {
        if (i > 0xaa) {
            return 1;
        }
        i++;
    }
    return 0;
}

void ShortMailEntry::fill_from_packet(u8 *packet) {
    sender_card_id = *reinterpret_cast<s32 *>(packet + 8);
    u32 id = lbl_805D6270;
    lbl_805D6270 = id + 1;
    sequence_id = id;
    flags = 0xB;
    strncpy(sender_name, (const char *)packet + 0xC, 0x17);
    sender_name[0x17] = 0;
    strncpy(body, (const char *)packet + 0x20, 0xAB);
    body[0xAB] = 0;
}

void TLobby__sub_80225C44(void* p) { TLobby::clear_all_entries(p); }
void TLobby__sub_80225C64(void* p) { TLobby::clear_all_entries(p); }
char *GuildCardEntry::get_name() { return name; }
void ShortMailEntry::clear_unread() { flags &= ~2; }
int ShortMailEntry::is_active() { return flags & 1; }
u32 ShortMailEntry::get_id() { return sequence_id; }

int TLobby::get_short_mail_ctrl() {  return lobby_short_mail_entry_count; }


void TLobby__sub_80225CB8(void) {
    lbl_805D63FC |= 1;
}

void TLobby::clear_lobby_flag() {
    lbl_805D63FC &= 0xFFFE;
}
