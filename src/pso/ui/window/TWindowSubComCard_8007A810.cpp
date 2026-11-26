#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/memory.h"
#include "types.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/network/protocol/SendGuildCardPacket.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
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
extern "C" {

s32 has_inactive_card__17TWindowSubComCardFPvi(GuildCardSlot *cards, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, cards++) {
        if (cards->is_active() == 0) {
            return 1;
        }
    }
    return 0;
}

s32 TWindowSubComCard::init_com_card() {
    return has_inactive_card__17TWindowSubComCardFPvi(TWindowSubComCard::get_card_entry(0), 0xD2);
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
            if (card->sub_8007B6F4() != 0) {
                cards->GuildCardSlotBase::operator=(*card);
            } else if (cards->sub_8007B6F4() == 0) {
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

s32 TWindowSubComCard::send_guild_card() {
    GuildCardSlot *temp;
    if (((s32 (*)())is_guild_card_invalid)() != 0) {
        return 0;
    }
    temp = TWindowSubComCard::get_card_entry(0);
    return update_matching_card(reinterpret_cast<GuildCardSlotBase *>(this), temp, 0xD2);
}
void forward_to_matching_card__17TWindowSubComCardFPvPvi(GuildCardSlotBase *card, GuildCardSlot *slots, s32 count) {
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

}

extern "C" {
s32 update_matching_card_slot(GuildCardSlotBase *card, GuildCardSlotBase *cards, s32 count);

void TWindowSubComCard::start_player_data_load(s32 ply_guild_card_tag) {
    u32 temp;
    if (is_guild_card_invalid(reinterpret_cast<GuildCardEntry *>(ply_guild_card_tag)) == 0) {
        temp = reinterpret_cast<uaddr>(TWindowSubComCard::get_card_entry(0));
        ((s32 (*)(s32, s32, s32))forward_to_matching_card__17TWindowSubComCardFPvPvi)(ply_guild_card_tag, (s32) temp, 0xD2);
        TAdSinglePlyChrSelectGC::load_player_data();
    }
}
}
void handle_6x06_send_guild_card(G_SendGuildCard_6x06 *cmd) {
    saddr card;
    cmd->bswap();
    card = reinterpret_cast<saddr>(&cmd->card);
    if ((is_guild_card_invalid(&cmd->card) == 0) && (((TWindowSubComCard *)card)->send_guild_card() == 0)) {
        set_guild_card_receive_active();
        if (((s32 (*)(int, void *, int))update_matching_card_slot)(card, TWindowGetComCard::received_guild_card_tags, 4) == 0) {
            ((s32 (*)(int, void *, int))replace_matching_card)(card, TWindowGetComCard::received_guild_card_tags, 4);
        }
    }
}



extern "C" {

#pragma push
#pragma fp_contract on
}
void send_guild_card_to_client(saddr client_id) {
    G_SendGuildCard_6x06 cmd;
    const GuildCardEntry *card = reinterpret_cast<const GuildCardEntry *>(TWindowSubComCard::get_keyboard_mode());
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
extern "C" {

s32 update_matching_card_slot(GuildCardSlotBase *card, GuildCardSlotBase *cards, s32 count) {
    u32 id;
    s32 i;
    id = card->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (cards->is_active() == 0) {
            return 0;
        }
        if (id == cards->get_card_id()) {
            if (card->sub_8007B6F4() != 0) {
                *cards = *card;
            } else if (cards->sub_8007B6F4() == 0) {
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
extern "C" {

int clear(void* p) { return (saddr)memset(p, 0, 144); }

void TWindowSubComCard::clear_and_init(void* local_client_id) { clear(this); ((GuildCardEntry *)this)->fill_guild_card_from_char((saddr)local_client_id); }
}
s32 fill_guild_card_from_short_mail(GuildCardEntry *card, s32 id) {
    ShortMailEntry *mail;
    mail = TLobby::find_short_mail_by_id(id);
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

s32 fill_guild_card_from_player(u8 *ply_guild_card_tag, u32 client) {
  unsigned char new_var;
  saddr player;
  u8 *temp_r4;
  player = (saddr)get_player_by_client_id(client);
  if (player == 0)
  {
    return 0;
  }
  *((u8 *) (((s8 *) ply_guild_card_tag) + 0x8C)) = (u8) ((*((u8 *) (((s8 *) ply_guild_card_tag) + 0x8C))) | 3);
  strncpy((char *)(ply_guild_card_tag + 8), (const char *)((TPlyPhotonChair *)(player))->get_name(), 0x17);
  *((s8 *) (((s8 *) ply_guild_card_tag) + 0x1F)) = 0;
  *((u8 *) (((s8 *) ply_guild_card_tag) + 0x8F)) = (u8) (*((u8 *) (((s8 *) player) + 0x88D)));
  *((s8 *) (((s8 *) ply_guild_card_tag) + 0x8E)) = ((TObjPlayer *)player)->get_section_id();
  new_var = ((TObjPlayer *)player)->get_language();
  temp_r4 = (u8 *)(player + 0xDAC);
  *((s8 *) (((s8 *) ply_guild_card_tag) + 0x8D)) = new_var;
  if (temp_r4 == 0)
  {
    return 0;
  }
  if (((u32) (*((u32 *) (((s8 *) temp_r4) + 4)))) == 0U)
  {
    return 0;
  }
  __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(ply_guild_card_tag, temp_r4);
  return 1;
}

void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *dst, void *src) {
    *(u8 *)((s8 *)dst + 0) = (u8) *(u8 *)((s8 *)src + 0);
    *(u8 *)((s8 *)dst + 1) = (u8) *(u8 *)((s8 *)src + 1);
    *(u16 *)((s8 *)dst + 2) = (u16) *(u16 *)((s8 *)src + 2);
    *(s32 *)((s8 *)dst + 4) = (s32) *(s32 *)((s8 *)src + 4);
}
void GuildCardEntry::fill_guild_card_from_char(s32 index) {
    uaddr char_index;
    u8 *temp_r31;
    char_index = (uaddr)TAdSinglePlyChrSelectGC::get_char_index(index);
    if (char_index != 0U) {
        temp_r31 = (unsigned char *) (char_index + 0x370);
        if (temp_r31 != NULL) {
            flags |= 1;
            strncpy(name, (const char *)temp_r31, 0x17);
            name[0x17] = 0;
            char_class = *(u8 *)((s8 *)temp_r31 + 0x31);
            section_id = *(u8 *)((s8 *)temp_r31 + 0x30);
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

s32 com_card_keyboard_mode;

void TObjPlayer::set_com_card_window(s32 client) {
    saddr temp_r31;
    u32 character_save_record;

    com_card_keyboard_mode = 0;
    character_save_record = ((u32)get_character_save_record((u32)client));
    if (character_save_record != 0U) {
        temp_r31 = character_save_record + 0x1510;
        if (temp_r31 != 0) {
            ((GuildCardEntry *)temp_r31)->fill_guild_card_from_char(client);
            com_card_keyboard_mode = temp_r31;
        }
    }
}

GuildCardEntry TWindowGetComCard::received_guild_card_tags[4];

void remove_first_received_card(void) {
    TWindowGetComCard::remove_entry(0, TWindowGetComCard::received_guild_card_tags, 4);
    if (TWindowGetComCard::received_guild_card_tags[0].is_active() == 0) {
        destroy_com_card_window();
    }
}
GuildCardEntry *get_received_guild_card_tags(void) {
    return TWindowGetComCard::received_guild_card_tags;
}
extern "C" {

void TWindowGetComCard::remove_entry(s32 index, GuildCardEntry *entries, s32 count) {
    if (index < count - 1) {
        GuildCardEntry *entry = &entries[index];
        move_words(entry, entry + 1, (u32)((count - index - 1) * sizeof(GuildCardEntry)) >> 2);
    }
    entries += count - 1;
    clear_entry_active_flag(entries);
}

}
void clear_received_guild_cards(s32 _w0) {
    destroy_com_card_window();
    for (s32 i = 0; i < 4; i++) {
        clear_entry_active_flag(&TWindowGetComCard::received_guild_card_tags[i]);
    }
}
void TWindowGetComCard__sub_8007B65C(void* p) { clear_received_guild_cards((saddr)p); }
void TWindowGetComCard__sub_8007B67C(void* p) { clear_received_guild_cards((saddr)p); }
