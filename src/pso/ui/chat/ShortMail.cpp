#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/item/TItemData.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include <string.h>
#include "pso/ui/window/TWindowCtrl.h"

struct NamedEntryView { u8 pad[0x20]; char name[1]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

ShortMailEntry short_mail_entries[8];
s32 short_mail_next_id;
int lobby_short_mail_entry_count;

void receive_short_mail(void* p) { if (((TLobby *)p)->is_name_too_long() == 0) { store_short_mail(p); } }

void TLobby::send_simple_mail(s32 target_card_id, void *message) {
    union {
        ShortMailPacketBuffer pkt;
        u8 b[0x228];
    } t;
    GuildCardEntry *own_card;
    ((TLobby *)(&t))->init_guild_card_tag();
    if (protocol_instance != NULL) {
        own_card = TWindowSubComCard::get_own_guild_card();
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&t.b[4], &protocol_instance->m_guildcard_tag);
        strncpy((char *)&t.b[0xC], own_card->get_name(), 0x17);
        t.pkt.target_card_id = target_card_id;
        t.b[0x23] = 0;
        strncpy((char *)&t.b[0x20], (char *)message, 0xAB);
        t.b[0xCB] = 0;
        protocol_instance->send_simple_mail(*(TChatMessage *)&t);
    }
}

void clear_unread_flags(void) {
  s32 i;
  ShortMailEntry *entry;
  i = 0;
  entry = short_mail_entries;
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


ShortMailEntry *get_short_mail_entry(int index) {
    char *storage = reinterpret_cast<char *>(&short_mail_entries);
    // Retain retail register allocation for the backing array address.
    if ((!storage) && (!storage)) {
    }
    return reinterpret_cast<ShortMailEntry *>(storage + index * sizeof(ShortMailEntry));
}

s32 TLobby::find_free_slot() {
  s32 slot;
  ShortMailEntry *entry;
  slot = 0;
  entry = short_mail_entries;
  do
  {
    if (entry->is_active() == 0)
    {
      return slot;
    }
    slot += 1;
    entry++;
  } while (slot < 8);
  TLobby::remove_entry_at(0);
  return 7;
}


void store_short_mail(void *p) {
    s32 slot = TLobby::find_free_slot();
    char *storage = reinterpret_cast<char *>(&short_mail_entries);
    storage += slot * sizeof(ShortMailEntry);
    reinterpret_cast<ShortMailEntry *>(storage)->fill_from_packet(static_cast<u8 *>(p));
    lobby_short_mail_entry_count++;
    set_new_mail_flag();
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
        ShortMailEntry *entry = &short_mail_entries[idx];
        move_words(entry, entry + 1, (7 - idx) * sizeof(ShortMailEntry) / sizeof(u32));
    }
    short_mail_entries[7].flags &= ~1;
    lobby_short_mail_entry_count--;
}

void TLobby::clear_all_entries(void* _w0) {
    s32 i;
    ShortMailEntry *entry;
    short_mail_next_id = 0;
    lobby_short_mail_entry_count = 0;
    TLobby::clear_lobby_flag();
    entry = short_mail_entries;
    for (i = 0; i < 8; i++) {
        entry->flags &= ~1;
        entry++;
    }
}

s32 TLobby::is_name_too_long() {
    s32 i = 0;
    char *p = ((NamedEntryView *)this)->name;
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
    u32 id = short_mail_next_id;
    short_mail_next_id = id + 1;
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


void set_new_mail_flag(void) {
    short_mail_flags |= 1;
}

void TLobby::clear_lobby_flag() {
    short_mail_flags &= 0xFFFE;
}
