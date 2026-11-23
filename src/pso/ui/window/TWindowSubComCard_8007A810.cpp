#include "pso/system/memory.h"
#include "types.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/player/TPlyGuildCardTag_8007B7EC.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include <string.h>

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
s32 copy_card__17TWindowSubComCardFiPv(saddr guild_card_slot, u8 *arg1) {
    GuildCardSlot *dest = reinterpret_cast<GuildCardSlot *>(guild_card_slot);
    GuildCardSlot *src = reinterpret_cast<GuildCardSlot *>(arg1);
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
int copy_struct__17TWindowSubComCardFPvPv(S_8007AA70 *arg0, S_8007AA70 *arg1) {
    *arg0 = *arg1;
    return (saddr)arg0;
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
    saddr arg0 = (saddr)this;
    GuildCardSlot *temp;
    if (((s32 (*)())TWindowSubComCard__sub_8007B070)() != 0) {
        return 0;
    }
    temp = TWindowSubComCard::get_card_entry(0);
    return TWindowSubComCard__sub_8007AC7C((Card_8007AC7C *)(arg0), temp, 0xD2);
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
        TWindowSubShortMail__sub_8007B824();
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

void TWindowSubComCard__sub_8007B1AC(void *ply_guild_card_tag, u8 *arg1, s32 count) {
    s32 i;
    u32 id = reinterpret_cast<GuildCardEntry *>(ply_guild_card_tag)->get_card_id();
    for (i = 0; i < count; i++, arg1 += 0x90) {
        if (reinterpret_cast<const GuildCardEntry *>(arg1)->is_active() == 0) {
            break;
        }
        if (id == reinterpret_cast<const GuildCardEntry *>(arg1)->get_card_id()) {
            break;
        }
    }
    if (i < count) {
        ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(arg1, ply_guild_card_tag);
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
