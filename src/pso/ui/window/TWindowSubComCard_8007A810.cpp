#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/memory.h"
#include "types.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/network/protocol/SendGuildCardPacket.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowBreakIn.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include <string.h>
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/Language.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/player/TPlyCharData.h"


void TWindowSubComCard::set_card_text(saddr src) {
    GuildCardSlot *slot;

    if (src != 0) {
        slot = TWindowSubComCard::get_card_entry(static_cast<s32>(reinterpret_cast<saddr>(this)));
        if (slot != NULL) {
            strncpy(slot->note.text, reinterpret_cast<const char *>(src), 0x6B);
            slot->note.text[0x6B] = 0;
        }
    }
}
char *TWindowSubComCard::get_card_note_text(s32 index) {
    GuildCardSlot *slot = TWindowSubComCard::get_card_entry(index);
    if (slot == NULL) {
        return NULL;
    }
    return slot->note.text;
}

GuildCardSlot *TWindowSubComCard::find_card_by_id(u32 id) {
    s32 i;
    GuildCardSlot *slot = TWindowSubComCard::get_card_entry(0);
    for (i = 0; i < 0xD2; i++, slot++) {
        if (id == slot->get_card_id()) {
            return slot;
        }
    }
    return NULL;
}
GuildCardSlot *TWindowSubComCard::get_card_entry(s32 index) {
    if (index < 0) {
        return NULL;
    }
    if (index >= 0xD2) {
        return NULL;
    }
    saddr base = TAdSinglePlyChrSelectGC::get_state() + 0xC4;
    return reinterpret_cast<GuildCardSlot *>(base) + index;
}


// Uses the generated GuildCardSlot assignment and constructor, emitted after it with the bases'.
void TWindowSubComCard::swap_cards(s32 first_index, s32 second_index) {
    GuildCardSlot tmp;
    GuildCardSlot *first = TWindowSubComCard::get_card_entry(first_index);
    GuildCardSlot *second = TWindowSubComCard::get_card_entry(second_index);
    tmp = *first;
    *first = *second;
    *second = tmp;
}

void clear_entry_active_flag(GuildCardEntry *entry);
s32 has_inactive_card(GuildCardSlot *cards, s32 count) {
    s32 i;
    for (i = 0; i < count; i++, cards++) {
        if (cards->is_active() == 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" {

s32 TWindowSubComCard::init_com_card() {
    return has_inactive_card(TWindowSubComCard::get_card_entry(0), 0xD2);
}

void TWindowSubComCard::remove_card_at(s32 i) {
    GuildCardSlot *slots = TWindowSubComCard::get_card_entry(0);
    if (i < 0xD1) {
        GuildCardSlot *slot = &slots[i];
        move_words(slot, slot + 1, (0xD1 - i) * sizeof(*slot) / 4);
    }
    clear_entry_active_flag(&slots[0xD1]);
    slots[0xD1].note.text[0] = 0;
}

s32 update_matching_card(GuildCardSlotBase *card, GuildCardSlot *cards, s32 count) {
    u32 id;
    s32 i;
    id = card->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (cards->is_active() == 0) {
            return 0;
        }
        if (id == cards->get_card_id()) {
            if (card->is_own_card() != 0) {
                cards->GuildCardSlotBase::operator=(*card);
            } else if (cards->is_own_card() == 0) {
                if (card->get_char_class() < 12) {
                    cards->GuildCardSlotBase::operator=(*card);
                } else {
                    cards->get_char_class();
                }
            }
            return 1;
        }
    }
    return 0;
}

s32 GuildCardEntry::update_in_card_file() {
    GuildCardSlot *temp;
    if (is_guild_card_invalid(this) != 0) {
        return 0;
    }
    temp = TWindowSubComCard::get_card_entry(0);
    return update_matching_card(static_cast<GuildCardSlotBase *>(this), temp, 0xD2);
}
}

void copy_card_to_matching_slot(GuildCardSlotBase *card, GuildCardSlot *slots, s32 count) {
    s32 i;
    u32 id = card->get_card_id();
    for (i = 0; i < count; i++, slots++) {
        if (slots->is_active() == 0) {
            break;
        }
        if (id == slots->get_card_id()) {
            break;
        }
    }
    if (i < count) {
        slots->GuildCardSlotBase::operator=(*card);
    }
}

void TWindowSubComCard::start_player_data_load(GuildCardEntry *card) {
    GuildCardSlot *slots;
    if (is_guild_card_invalid(card) == 0) {
        slots = TWindowSubComCard::get_card_entry(0);
        copy_card_to_matching_slot(static_cast<GuildCardSlotBase *>(card), slots, 0xD2);
        TAdSinglePlyChrSelectGC::load_player_data();
    }
}
void handle_6x06_send_guild_card(G_SendGuildCard_6x06 *cmd) {
    GuildCardEntry *card;
    cmd->bswap();
    card = &cmd->card;
    if ((is_guild_card_invalid(card) == 0) && (card->update_in_card_file() == 0)) {
        set_guild_card_receive_active();
        if (update_matching_card_slot((GuildCardSlotBase *)card, (GuildCardSlotBase *)TWindowGetComCard::received_guild_card_tags, 4) == 0) {
            replace_matching_card((GuildCardSlotBase *)card, (GuildCardSlotBase *)TWindowGetComCard::received_guild_card_tags, 4);
        }
    }
}



extern "C" {

#pragma push
#pragma fp_contract on
}
void send_guild_card_to_client(saddr client_id) {
    G_SendGuildCard_6x06 cmd;
    const GuildCardEntry *card = TWindowSubComCard::get_own_guild_card();
    cmd.card = *card;
    cmd.send_to(client_id);
}
extern "C" {
#pragma pop

s32 TWindowSubComCard::count_leading_active(GuildCardEntry *cards, s32 count) {
    s32 i;
    for (i = 0; i < count; i++, cards++) {
        if (cards->is_active() == 0) {
            break;
        }
    }
    return i;
}

s32 TWindowSubComCard::count_active_cards() {
    GuildCardSlot *p = TWindowSubComCard::get_card_entry(0);
    s32 i;
    for (i = 0; i < 0xD2; i++, p++) {
        if (p->is_active() == 0) {
            break;
        }
    }
    return i;
}

}
s32 has_free_card_slot(GuildCardEntry *cards, s32 count) {
    s32 i;
    for (i = 0; i < count; i++, cards++) {
        if (cards->is_active() == 0) {
            return 1;
        }
    }
    return 0;
}
s32 is_guild_card_invalid(GuildCardEntry *card) {
    if (card->text[0x67] != 0) {
        return 1;
    }
    if (card->flags != 1) {
        return 1;
    }
    if (card->language < 0) {
        return 1;
    }
    if (card->section_id < 0) {
        return 1;
    }
    return card->char_class < 0;
}

s32 update_matching_card_slot(GuildCardSlotBase *card, GuildCardSlotBase *cards, s32 count) {
    u32 id;
    s32 i;
    id = card->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (cards->is_active() == 0) {
            return 0;
        }
        if (id == cards->get_card_id()) {
            if (card->is_own_card() != 0) {
                *cards = *card;
            } else if (cards->is_own_card() == 0) {
                if (card->char_class < 12) {
                    *cards = *card;
                } else {
                    cards->get_char_class();
                }
            }
            return 1;
        }
    }
    return 0;
}

void replace_matching_card(GuildCardSlotBase *card, GuildCardSlotBase *entries, s32 count) {
    s32 i;
    u32 id = card->get_card_id();
    for (i = 0; i < count; i++, entries++) {
        if (entries->is_active() == 0) {
            break;
        }
        if (id == entries->get_card_id()) {
            break;
        }
    }
    if (i < count) {
        *entries = *card;
    }
}
extern "C" {

void GuildCardEntry::set_text(const char *src) {
    strncpy(text, src, 0x6B);
    text[0x6B] = 0;
}

}
void clear_entry_active_flag(GuildCardEntry *entry) {
    entry->flags &= ~1;
}
void GuildCardEntry::clear() { memset(this, 0, sizeof(GuildCardEntry)); }

void GuildCardEntry::clear_and_fill_from_char(s32 index) { clear(); fill_from_char(index); }
s32 fill_guild_card_from_short_mail(GuildCardEntry *card, s32 id) {
    ShortMailEntry *mail;
    mail = find_short_mail_by_id(id);
    if (mail == NULL) {
        return 0;
    }
    card->flags |= 3;
    strncpy(card->name, mail->get_sender_name(), 0x17);
    card->name[0x17] = 0;
    card->char_class = 0xC;
    card->section_id = 0xA;
    card->language = 5;
    card->tag.m_guildcard_number = mail->get_sender_card_id();
    return 1;
}

s32 fill_guild_card_from_player(GuildCardEntry *card, u32 client) {
  unsigned char language;
  TObjPlayer *player;
  PlayerGuildCardTag *player_tag;
  player = get_player_by_client_id(client);
  if (player == NULL)
  {
    return 0;
  }
  card->flags |= 3;
  strncpy(card->name, (const char *)((TPlyPhotonChair *)(player))->get_name(), 0x17);
  card->name[0x17] = 0;
  card->char_class = player->appearance.classId;
  card->section_id = player->get_section_id();
  language = player->get_language();
  player_tag = &player->guild_card_tag;
  card->language = language;
  if (player_tag == 0)
  {
    return 0;
  }
  if (player_tag->guildcard_number == 0U)
  {
    return 0;
  }
  __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(card, player_tag);
  return 1;
}

void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *dst, void *src) {
    TPlyGuildCardTag *to = (TPlyGuildCardTag *)dst;
    TPlyGuildCardTag *from = (TPlyGuildCardTag *)src;
    to->m_tag0 = from->m_tag0;
    to->m_tag1 = from->m_tag1;
    to->m_tag2 = from->m_tag2;
    to->m_guildcard_number = from->m_guildcard_number;
}
void GuildCardEntry::fill_from_char(s32 index) {
    TPlyCharData *chr;
    disp_data_part2 *disp;
    chr = TAdSinglePlyChrSelectGC::get_char_index(index);
    if (chr != NULL) {
        disp = &chr->m_disp_part2;
        if (disp != NULL) {
            flags |= 1;
            strncpy(name, disp->name, 0x17);
            name[0x17] = 0;
            char_class = disp->char_class;
            section_id = disp->section_id;
            language = current_language;
            if (TLobby::protocol_instance != NULL) {
                TPlyGuildCardTag *src = &TLobby::protocol_instance->m_guildcard_tag;
                if (src->m_guildcard_number != 0) {
                    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(this, src);
                }
            }
        }
    }
}

GuildCardEntry *own_guild_card;

void TObjPlayer::set_com_card_window(s32 client) {
    GuildCardEntry *card;
    CharacterSaveRecord *record;

    own_guild_card = NULL;
    record = get_character_save_record((u32)client);
    if (record != NULL) {
        card = (GuildCardEntry *)record->guild_card;
        if (card != NULL) {
            card->fill_from_char(client);
            own_guild_card = card;
        }
    }
}

GuildCardEntry TWindowGetComCard::received_guild_card_tags[4];

void remove_first_received_card(void) {
    remove_guild_card_entry(0, TWindowGetComCard::received_guild_card_tags, 4);
    if (TWindowGetComCard::received_guild_card_tags[0].is_active() == 0) {
        destroy_com_card_window();
    }
}
GuildCardEntry *get_received_guild_card_tags(void) {
    return TWindowGetComCard::received_guild_card_tags;
}
void remove_guild_card_entry(s32 index, GuildCardEntry *entries, s32 count) {
    if (index < count - 1) {
        GuildCardEntry *entry = &entries[index];
        move_words(entry, entry + 1, (u32)((count - index - 1) * sizeof(GuildCardEntry)) >> 2);
    }
    entries += count - 1;
    clear_entry_active_flag(entries);
}
void clear_received_guild_cards(void) {
    destroy_com_card_window();
    for (s32 i = 0; i < 4; i++) {
        clear_entry_active_flag(&TWindowGetComCard::received_guild_card_tags[i]);
    }
}
void free_received_guild_cards(void) { clear_received_guild_cards(); }
void init_received_guild_cards(void) { clear_received_guild_cards(); }
