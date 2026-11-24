#include "pso/system/memory.h"
#include "types.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include <string.h>
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/Language.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowGetComCard.h"

extern "C" {

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
u8 *TWindowSubComCard::get_card_entry_data() {
    GuildCardSlot *slot = TWindowSubComCard::get_card_entry(static_cast<s32>(reinterpret_cast<saddr>(this)));
    if (slot == NULL) {
        return NULL;
    }
    return reinterpret_cast<u8 *>(slot->note.text);
}

GuildCardSlot *TWindowSubComCard::find_card_by_id(u32 id) {
    s32 i;
    GuildCardSlot *slot = TWindowSubComCard::get_card_entry(0);
    for (i = 0; i < 0xD2; i++, slot++) {
        if (id == slot->entry.get_card_id()) {
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

}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
struct S_8007AA70;
s32 forward_return_arg__17TWindowSubComCardFi(saddr, S_8007AA70 *);

void TWindowSubComCard::swap_cards(s32 first_index, s32 second_index) {
    s32 src[64];
    GuildCardSlot *first_ptr;
    GuildCardSlot *second_ptr;

    ((s32 (*)(s32 *))reinit__17TWindowSubComCardFi)(src);
    first_ptr = TWindowSubComCard::get_card_entry(first_index);
    second_ptr = TWindowSubComCard::get_card_entry(second_index);
    copy_card__17TWindowSubComCardFiPv((saddr)src, (u8 *)first_ptr);
    copy_card__17TWindowSubComCardFiPv((saddr)first_ptr, (u8 *)second_ptr);
    copy_card__17TWindowSubComCardFiPv((saddr)second_ptr, (u8 *)src);
}
s32 copy_card__17TWindowSubComCardFiPv(saddr guild_card_slot, u8 *source) {
    GuildCardSlot *dest = reinterpret_cast<GuildCardSlot *>(guild_card_slot);
    GuildCardSlot *src = reinterpret_cast<GuildCardSlot *>(source);
    ((s32 (*)(s32))forward_return_arg__17TWindowSubComCardFi)(guild_card_slot);
    dest->pad_90[0] = src->pad_90[0];
    dest->pad_90[1] = src->pad_90[1];
    dest->pad_90[2] = src->pad_90[2];
    dest->pad_90[3] = src->pad_90[3];
    dest->note = src->note;
    return guild_card_slot;
}

}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct C18_8007AA70 { u8 bytes[0x18]; };

struct C6C_8007AA70 { u8 bytes[0x6c]; };

struct P_8007AA70 { u32 w[2]; };

struct S_8007AA70 {
    P_8007AA70 ab;
    C18_8007AA70 c;
    C6C_8007AA70 d;
    u8 e0, e1, e2, e3;
};

extern "C" {
int copy_struct__17TWindowSubComCardFPvPv(S_8007AA70 *, S_8007AA70 *);

s32 forward_return_arg__17TWindowSubComCardFi(saddr dest, S_8007AA70 * _w1) {
    copy_struct__17TWindowSubComCardFPvPv((S_8007AA70 *)(dest), (S_8007AA70 *)(_w1));
    return dest;
}
int copy_struct__17TWindowSubComCardFPvPv(S_8007AA70 *dst, S_8007AA70 *src) {
    *dst = *src;
    return (saddr)dst;
}

s32 reinit__17TWindowSubComCardFi(s32 object) {
    ((s32 (*)())init__17TWindowSubComCardFi)();
    return object;
}

s32 init__17TWindowSubComCardFi(s32 object) {
    ((s32 (*)())init_guild_card_tag__17TWindowSubComCardFi)();
    return object;
}

}

struct Card_8007AC7C {
    u8 pad[0x100];
};

extern "C" {
s32 has_inactive_card__17TWindowSubComCardFPvi(GuildCardSlot *cards, s32 n);
void TWindowSubComCard__sub_8007B26C(GuildCardEntry *entry);
s8 TWindowSubComCard__sub_8007B6EC(void *);
s32 TWindowSubComCard__sub_8007B6F4(void *);
s32 TWindowSubComCard__sub_8007AC7C(Card_8007AC7C *self, GuildCardSlot *cards, s32 count);
int __ct__16TPlyGuildCardTagFv();

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 ply_guild_card_tag) {
    __ct__16TPlyGuildCardTagFv();
    return ply_guild_card_tag;
}

s32 has_inactive_card__17TWindowSubComCardFPvi(GuildCardSlot *cards, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, cards++) {
        if (cards->entry.is_active() == 0) {
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
    TWindowSubComCard__sub_8007B26C(&slots[0xD1].entry);
    slots[0xD1].note.text[0] = 0;
}

s32 TWindowSubComCard__sub_8007AC7C(Card_8007AC7C *self, GuildCardSlot *cards, s32 count) {
    u32 id;
    s32 i;
    id = reinterpret_cast<const GuildCardEntry *>(self)->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (cards->entry.is_active() == 0) {
            return 0;
        }
        if (id == cards->entry.get_card_id()) {
            if (TWindowSubComCard__sub_8007B6F4(self) != 0) {
                ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(cards, self);
            } else if (TWindowSubComCard__sub_8007B6F4(cards) == 0) {
                if (TWindowSubComCard__sub_8007B6EC(self) < 12) {
                    ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(cards, self);
                } else {
                    TWindowSubComCard__sub_8007B6EC(cards);
                }
            }
            return 1;
        }
    }
    return 0;
}

s32 TWindowSubComCard::send_guild_card() {
    GuildCardSlot *temp;
    if (((s32 (*)())TWindowSubComCard__sub_8007B070)() != 0) {
        return 0;
    }
    temp = TWindowSubComCard::get_card_entry(0);
    return TWindowSubComCard__sub_8007AC7C((Card_8007AC7C *)this, temp, 0xD2);
}
void forward_to_matching_card__17TWindowSubComCardFPvPvi(void *card, u8 *slots, s32 count) {
    s32 i;
    u32 id = reinterpret_cast<const GuildCardEntry *>(card)->get_card_id();
    for (i = 0; i < count; i++, slots += 0x100) {
        if (reinterpret_cast<const GuildCardEntry *>(slots)->is_active() == 0) {
            break;
        }
        if (id == reinterpret_cast<const GuildCardEntry *>(slots)->get_card_id()) {
            break;
        }
    }
    if (i < count) {
        ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(slots, card);
    }
}

}

struct Card_8007B0D0;
extern "C" {
s32 TWindowSubComCard__sub_8007B0D0(Card_8007B0D0 *, Card_8007B0D0 *, s32);
s32 bswap_guild_card__17TWindowSubComCardFv();

void TWindowSubComCard::start_player_data_load(s32 ply_guild_card_tag) {
    u32 temp;
    if (((s32 (*)(int))TWindowSubComCard__sub_8007B070)(ply_guild_card_tag) == 0) {
        temp = reinterpret_cast<uaddr>(TWindowSubComCard::get_card_entry(0));
        ((s32 (*)(s32, s32, s32))forward_to_matching_card__17TWindowSubComCardFPvPvi)(ply_guild_card_tag, (s32) temp, 0xD2);
        TAdSinglePlyChrSelectGC::load_player_data();
    }
}
}
void handle_6x06_send_guild_card(s32 packet) {
    saddr card;
    bswap_guild_card__17TWindowSubComCardFv();
    card = packet + 4;
    if ((((s32 (*)(int))TWindowSubComCard__sub_8007B070)(card) == 0) && (((TWindowSubComCard *)card)->send_guild_card() == 0)) {
        set_guild_card_receive_active();
        if (((s32 (*)(int, void *, int))TWindowSubComCard__sub_8007B0D0)(card, TWindowGetComCard__received_guild_card_tags, 4) == 0) {
            ((s32 (*)(int, void *, int))TWindowSubComCard__sub_8007B1AC)(card, TWindowGetComCard__received_guild_card_tags, 4);
        }
    }
}

typedef struct Big { u8 b[144]; } Big;

struct Card_8007AF60 { u8 body[0x90]; };

struct Card_8007B010 { u8 body[0x90]; };

struct Card_8007AFB8 { u8 body[0x100]; };

struct Card_8007B0D0 {
    u8 pad[0x8F];
    s8 level;
};

extern "C" {
s32 count_leading_active__17TWindowSubComCardFPvi(Card_8007AF60 *p, s32 n);
s32 TWindowSubComCard__sub_8007B010(Card_8007B010 *p, s32 n);

#pragma push
#pragma fp_contract on
void TWindowSubComCard__sub_8007AF10(saddr client_id) {
    Big spC;
    s32 sp8;
    s32 temp;
    ((TWindowSubComCard *)(&sp8))->init_guild_card();
    temp = TWindowSubComCard::get_keyboard_mode();
    ((s32 (*)(Big *, s32))copy_struct__17TWindowSubComCardFPvPv)(&spC, temp);
    ((TWindowSubComCard *)(&sp8))->init_card((void*)client_id);
}
#pragma pop

s32 count_leading_active__17TWindowSubComCardFPvi(Card_8007AF60 *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, p++) {
        if (reinterpret_cast<const GuildCardEntry *>(p)->is_active() == 0) {
            break;
        }
    }
    return i;
}

s32 TWindowSubComCard::count_active_cards() {
    GuildCardSlot *p = TWindowSubComCard::get_card_entry(0);
    s32 i;
    for (i = 0; i < 0xD2; i++, p++) {
        if (p->entry.is_active() == 0) {
            break;
        }
    }
    return i;
}

s32 TWindowSubComCard__sub_8007B010(Card_8007B010 *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, p++) {
        if (reinterpret_cast<const GuildCardEntry *>(p)->is_active() == 0) {
            return 1;
        }
    }
    return 0;
}

u32 TWindowSubComCard__sub_8007B070(u8 *keyboard_mode) {
    if ((s8) *(u8 *)((s8 *)keyboard_mode + 0x87) != 0) {
        return 1U;
    }
    if ((s32) *(u8 *)((s8 *)keyboard_mode + 0x8C) != 1) {
        return 1U;
    }
    if ((s8) *(u8 *)((s8 *)keyboard_mode + 0x8D) < 0) {
        return 1U;
    }
    if ((s8) *(u8 *)((s8 *)keyboard_mode + 0x8E) < 0) {
        return 1U;
    }
    return (u32) (s8) *(u8 *)((s8 *)keyboard_mode + 0x8F) >> 0x1FU;
}

s32 TWindowSubComCard__sub_8007B0D0(Card_8007B0D0 *self, Card_8007B0D0 *cards, s32 count) {
    u32 id;
    s32 i;
    id = reinterpret_cast<const GuildCardEntry *>(self)->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (reinterpret_cast<const GuildCardEntry *>(cards)->is_active() == 0) {
            return 0;
        }
        if (id == reinterpret_cast<const GuildCardEntry *>(cards)->get_card_id()) {
            if (TWindowSubComCard__sub_8007B6F4(self) != 0) {
                ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(cards, self);
            } else if (TWindowSubComCard__sub_8007B6F4(cards) == 0) {
                if (self->level < 12) {
                    ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(cards, self);
                } else {
                    TWindowSubComCard__sub_8007B6EC(cards);
                }
            }
            return 1;
        }
    }
    return 0;
}

void TWindowSubComCard__sub_8007B1AC(void *ply_guild_card_tag, u8 *entries, s32 count) {
    s32 i;
    u32 id = reinterpret_cast<GuildCardEntry *>(ply_guild_card_tag)->get_card_id();
    for (i = 0; i < count; i++, entries += 0x90) {
        if (reinterpret_cast<const GuildCardEntry *>(entries)->is_active() == 0) {
            break;
        }
        if (id == reinterpret_cast<const GuildCardEntry *>(entries)->get_card_id()) {
            break;
        }
    }
    if (i < count) {
        ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(entries, ply_guild_card_tag);
    }
}

void TWindowSubComCard::set_text(void *text) {
    ((s32 (*)(void *, void *, int))strncpy)((void *) (((u8 *)this) + 0x20), text, 0x6B);
    *(s8 *)((s8 *)((u8 *)this) + 0x8B) = 0;
}

void TWindowSubComCard__sub_8007B26C(GuildCardEntry *entry) {
    entry->flags &= ~1;
}

int clear(void* p) { return (saddr)memset(p, 0, 144); }

void TWindowSubComCard::clear_and_init(void* local_client_id) { clear(this); ((TLobby *)this)->fill_guild_card_from_char((saddr)local_client_id); }
s32 fn_8007B2E0(u8 *ply_guild_card_tag, s32 id) {
    ShortMailEntry *mail;
    mail = TLobby::find_short_mail_by_id(id);
    if (mail == NULL) {
        return 0;
    }
    *(u8 *)((s8 *)ply_guild_card_tag + 0x8C) = (u8) (*(u8 *)((s8 *)ply_guild_card_tag + 0x8C) | 3);
    ((s32 (*)(void *, int, int))strncpy)(ply_guild_card_tag + 8, (saddr)mail->get_sender_name(), 0x17);
    *(s8 *)((s8 *)ply_guild_card_tag + 0x1F) = 0;
    *(s8 *)((s8 *)ply_guild_card_tag + 0x8F) = 0xC;
    *(s8 *)((s8 *)ply_guild_card_tag + 0x8E) = 0xA;
    *(s8 *)((s8 *)ply_guild_card_tag + 0x8D) = 5;
    *(s32 *)((s8 *)ply_guild_card_tag + 4) = mail->get_sender_card_id();
    return 1;
}

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
void TLobby::fill_guild_card_from_char(s32 index) {
    uaddr char_index;
    u8 *temp_r31;
    char_index = (uaddr)TAdSinglePlyChrSelectGC::get_char_index(index);
    if (char_index != 0U) {
        temp_r31 = (unsigned char *) (char_index + 0x370);
        if (temp_r31 != NULL) {
            *(u8 *)((s8 *)((u8 *)this) + 0x8C) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x8C) | 1);
            strncpy((char *)this + 8, (const char *)temp_r31, 0x17);
            *(s8 *)((s8 *)((u8 *)this) + 0x1F) = 0;
            *(u8 *)((s8 *)((u8 *)this) + 0x8F) = (u8) *(u8 *)((s8 *)temp_r31 + 0x31);
            *(u8 *)((s8 *)((u8 *)this) + 0x8E) = (u8) *(u8 *)((s8 *)temp_r31 + 0x30);
            *(s8 *)((s8 *)((u8 *)this) + 0x8D) = (s8) current_language;
            if (protocol_instance != NULL) {
                TPlyGuildCardTag *src = &protocol_instance->m_guildcard_tag;
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
            ((TLobby *)temp_r31)->fill_guild_card_from_char(client);
            com_card_keyboard_mode = temp_r31;
        }
    }
}

GuildCardEntry TWindowGetComCard__received_guild_card_tags[4];

extern "C" {
void TWindowSubComCard__sub_8007B26C(GuildCardEntry *entry);
void __construct_array(void *ptr, void *ctor, void *dtor, u32 size, u32 n);

void TWindowGetComCard__sub_8007B54C(void) {
    TWindowGetComCard::remove_entry(0, TWindowGetComCard__received_guild_card_tags, 4);
    if (TWindowGetComCard__received_guild_card_tags[0].is_active() == 0) {
        TWindowCtrl__sub_8024A08C();
    }
}

GuildCardEntry *TWindowGetComCard__sub_8007B594(void) {
    return TWindowGetComCard__received_guild_card_tags;
}

void TWindowGetComCard::remove_entry(s32 index, GuildCardEntry *entries, s32 count) {
    if (index < count - 1) {
        GuildCardEntry *entry = &entries[index];
        move_words(entry, entry + 1, (u32)((count - index - 1) * sizeof(GuildCardEntry)) >> 2);
    }
    entries += count - 1;
    TWindowSubComCard__sub_8007B26C(entries);
}

void TWindowGetComCard__sub_8007B60C(s32 _w0) {
    TWindowCtrl__sub_8024A08C();
    for (s32 i = 0; i < 4; i++) {
        TWindowSubComCard__sub_8007B26C(&TWindowGetComCard__received_guild_card_tags[i]);
    }
}

void TWindowGetComCard__sub_8007B65C(void* p) { TWindowGetComCard__sub_8007B60C((saddr)p); }
void TWindowGetComCard__sub_8007B67C(void* p) { TWindowGetComCard__sub_8007B60C((saddr)p); }
void TWindowGetComCard::construct_card_tags() {
    __construct_array(TWindowGetComCard__received_guild_card_tags, (void *)init_guild_card_tag__17TWindowSubComCardFi, 0, sizeof(GuildCardEntry), 4);
}

}

__declspec(section ".ctors") static void *const __sinit_TWindowGetComCard_8007B54C_cpp_ref = (void *)TWindowGetComCard::construct_card_tags;
