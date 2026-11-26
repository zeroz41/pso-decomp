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

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

ShortMailEntry short_mail_entries[8];
s32 short_mail_next_id;
int lobby_short_mail_entry_count;

void receive_short_mail(TChatMessage &message) { if (message.is_text_too_long() == 0) { store_short_mail(message); } }

void TLobby::send_simple_mail(s32 target_card_id, void *message) {
    TChatMessage mail;
    GuildCardEntry *own_card;
    if (protocol_instance != NULL) {
        own_card = TWindowSubComCard::get_own_guild_card();
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&mail.tag, &protocol_instance->m_guildcard_tag);
        strncpy(mail.name, own_card->get_name(), 0x17);
        mail.to_guildcard_number = target_card_id;
        // The game terminates the name as if it were 0x18 bytes long; the byte lands in the text.
        mail.name[0x17] = 0;
        strncpy(mail.text, (char *)message, 0xAB);
        mail.text[0xAB] = 0;
        protocol_instance->send_simple_mail(mail);
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

ShortMailEntry *find_short_mail_by_id(u32 id) {
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

s32 find_free_short_mail_slot() {
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


void store_short_mail(TChatMessage &message) {
    s32 slot = find_free_short_mail_slot();
    char *storage = reinterpret_cast<char *>(&short_mail_entries);
    storage += slot * sizeof(ShortMailEntry);
    reinterpret_cast<ShortMailEntry *>(storage)->fill_from_packet(message);
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

void clear_short_mails() {
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

s32 TChatMessage::is_text_too_long() {
    s32 i = 0;
    char *p = text;
    while (*p++ != 0) {
        if (i > 0xaa) {
            return 1;
        }
        i++;
    }
    return 0;
}

void ShortMailEntry::fill_from_packet(TChatMessage &message) {
    sender_card_id = message.tag.m_guildcard_number;
    u32 id = short_mail_next_id;
    short_mail_next_id = id + 1;
    sequence_id = id;
    flags = 0xB;
    strncpy(sender_name, message.name, 0x17);
    sender_name[0x17] = 0;
    strncpy(body, message.text, 0xAB);
    body[0xAB] = 0;
}

void clear_short_mail_on_unload() { clear_short_mails(); }
void clear_short_mail_on_load() { clear_short_mails(); }
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
