#include "types.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/player/TPlyGuildCardTag_8007B7EC.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 strncpy(void *, s32, s32);

void TWindowSubComCard::set_card_text(s32 arg1) {
    s32 arg0 = (s32)this;
    u8 *temp_r3;

    if (arg1 != 0) {
        temp_r3 = ((u8 * (*)(void *))get_card_entry__17TWindowSubComCardFi)((void *)arg0);
        if (temp_r3 != NULL) {
            strncpy(temp_r3 + 0x94, arg1, 0x6B);
            *(s8 *)((s8 *)temp_r3 + 0xFF) = 0;
        }
    }
}
u8 *TWindowSubComCard::get_card_entry_data() {
    u8 *p = ((u8 * (*)(void *))get_card_entry__17TWindowSubComCardFi)(this);
    if (p == 0) {
        return 0;
    }
    return p + 0x94;
}

s32 TWindowSubComCard::find_card_by_id(u32 arg0) {
    s32 i;
    s32 acc;

    acc = get_card_entry__17TWindowSubComCardFi(0);
    for (i = 0; i < 0xD2; i++) {
        if (arg0 == ((TWindowSubComCard *)acc)->get_card_id()) {
            return acc;
        }
        acc += 0x100;
    }
    return 0;
}
s32 get_card_entry__17TWindowSubComCardFi(s32 arg0) {
    s32 var_r31;
    s32 var_r3;
    var_r31 = arg0;
    if (var_r31 < 0) {
        var_r3 = 0;
        return 0;
    }
    if (var_r31 >= 0xD2) {
        var_r3 = 0;
        return 0;
    }
    var_r3 = TAdSinglePlyChrSelectGC::get_state() + 0xC4;
    var_r3 += var_r31 << 8;
    return var_r3;
}

}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_6C { u8 bytes[0x6C]; };

extern "C" {
struct S_8007AA70;
s32 forward_return_arg__17TWindowSubComCardFi(s32, S_8007AA70 *);

void TWindowSubComCard::swap_cards(s32 arg0, s32 arg1) {
    s32 sp8[64];
    s32 *first_ptr;
    s32 *second_ptr;

    ((s32 (*)(s32 *))reinit__17TWindowSubComCardFi)(sp8);
    first_ptr = ((s32 * (*)(s32))get_card_entry__17TWindowSubComCardFi)(arg0);
    second_ptr = ((s32 * (*)(s32))get_card_entry__17TWindowSubComCardFi)(arg1);
    copy_card__17TWindowSubComCardFiPv((s32)sp8, (u8 *)first_ptr);
    copy_card__17TWindowSubComCardFiPv((s32)first_ptr, (u8 *)second_ptr);
    copy_card__17TWindowSubComCardFiPv((s32)second_ptr, (u8 *)sp8);
}
s32 copy_card__17TWindowSubComCardFiPv(s32 arg0, u8 *arg1) {
    s32 temp_r5;
    u8 *temp_r4;
    ((s32 (*)(s32))forward_return_arg__17TWindowSubComCardFi)(arg0);
    temp_r5 = arg0 + 0x90;
    temp_r4 = (arg1 + 0x90);
    *(u8 *)((s8 *)arg0 + 0x90) = (u8) *(u8 *)((s8 *)arg1 + 0x90);
    *(u8 *)((s8 *)arg0 + 0x91) = (u8) *(u8 *)((s8 *)arg1 + 0x91);
    *(u8 *)((s8 *)arg0 + 0x92) = (u8) *(u8 *)((s8 *)arg1 + 0x92);
    *(u8 *)((s8 *)arg0 + 0x93) = (u8) *(u8 *)((s8 *)arg1 + 0x93);
    *(ByteBlock_6C *)(temp_r5 + 4) = *(const ByteBlock_6C *)((s32) temp_r4 + 4);
    return arg0;
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

s32 forward_return_arg__17TWindowSubComCardFi(s32 arg0, S_8007AA70 * _w1) {
    copy_struct__17TWindowSubComCardFPvPv((S_8007AA70 *)(arg0), (S_8007AA70 *)(_w1));
    return arg0;
}
int copy_struct__17TWindowSubComCardFPvPv(S_8007AA70 *arg0, S_8007AA70 *arg1) {
    *arg0 = *arg1;
    return (int)arg0;
}

s32 reinit__17TWindowSubComCardFi(s32 arg0) {
    ((s32 (*)())init__17TWindowSubComCardFi)();
    return arg0;
}

s32 init__17TWindowSubComCardFi(s32 arg0) {
    ((s32 (*)())init_guild_card_tag__17TWindowSubComCardFi)();
    return arg0;
}

}

struct Card_8007AB84 { u8 data[0x100]; };

struct Card_8007AC10 { u8 body[0x94]; u8 used; u8 pad[0x100 - 0x95]; };

struct Box_8007AC10 { Card_8007AC10 cards[0xD2]; };

struct Card_8007AC7C {
    u8 pad[0x100];
};

extern "C" {
s32 has_inactive_card__17TWindowSubComCardFPvi(Card_8007AB84 *cards, s32 n);
struct O_8007B26C;
void TWindowSubComCard__sub_8007B26C(O_8007B26C *);
s8 TWindowSubComCard__sub_8007B6EC(void *);
s32 TWindowSubComCard__sub_8007B6F4(void *);
s32 TWindowSubComCard__sub_8007AC7C(Card_8007AC7C *self, Card_8007AC7C *cards, s32 count);
int __ct__16TPlyGuildCardTagFv();

s32 init_guild_card_tag__17TWindowSubComCardFi(s32 arg0) {
    __ct__16TPlyGuildCardTagFv();
    return arg0;
}

s32 has_inactive_card__17TWindowSubComCardFPvi(Card_8007AB84 *cards, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, cards++) {
        if (((TWindowSubComCard *)cards)->is_active() == 0) {
            return 1;
        }
    }
    return 0;
}

void TWindowSubComCard::init_com_card() {
    has_inactive_card__17TWindowSubComCardFPvi((Card_8007AB84 *)(((s32 (*)(s32))get_card_entry__17TWindowSubComCardFi)(0)), 0xD2);
}

void TWindowSubComCard::remove_card_at(s32 i) {
    Box_8007AC10 *box = ((Box_8007AC10 *)((s32 (*)(s32))get_card_entry__17TWindowSubComCardFi)(0));
    if (i < 0xD1) {
        Card_8007AC10 *p = &box->cards[i];
        ((TLobby *)p)->move_words((u32 *)(p + 1), (0xD1 - i) * sizeof(Card_8007AC10) / 4);
    }
    ((void (*)(Card_8007AC10 *))TWindowSubComCard__sub_8007B26C)(&box->cards[0xD1]);
    box->cards[0xD1].used = 0;
}

s32 TWindowSubComCard__sub_8007AC7C(Card_8007AC7C *self, Card_8007AC7C *cards, s32 count) {
    u32 id;
    s32 i;
    id = ((TWindowSubComCard *)self)->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (((TWindowSubComCard *)cards)->is_active() == 0) {
            return 0;
        }
        if (id == ((TWindowSubComCard *)cards)->get_card_id()) {
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
    s32 arg0 = (s32)this;
    s32 temp;
    if (((s32 (*)())TWindowSubComCard__sub_8007B070)() != 0) {
        return 0;
    }
    temp = ((s32 (*)(s32))get_card_entry__17TWindowSubComCardFi)(0);
    return TWindowSubComCard__sub_8007AC7C((Card_8007AC7C *)(arg0), (Card_8007AC7C *)(temp), 0xD2);
}
void forward_to_matching_card__17TWindowSubComCardFPvPvi(void *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    u32 id = ((TWindowSubComCard *)arg0)->get_card_id();
    for (i = 0; i < arg2; i++, arg1 += 0x100) {
        if (((TWindowSubComCard *)arg1)->is_active() == 0) {
            break;
        }
        if (id == ((TWindowSubComCard *)arg1)->get_card_id()) {
            break;
        }
    }
    if (i < arg2) {
        ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(arg1, arg0);
    }
}

}

struct RecoveredGlobal_8007AE8C_TWindowGetComCard__data_80500158 {
    s32 value;
    u8 remaining[0x23C];
};

struct Card_8007B0D0;
extern "C" {
s32 TWindowSubComCard__sub_8007B0D0(Card_8007B0D0 *, Card_8007B0D0 *, s32);
s32 bswap_guild_card__17TWindowSubComCardFv();
extern RecoveredGlobal_8007AE8C_TWindowGetComCard__data_80500158 TWindowGetComCard__received_guild_card_tags;

void TWindowSubComCard::start_player_data_load(s32 arg0) {
    u32 temp;
    if (((s32 (*)(int))TWindowSubComCard__sub_8007B070)(arg0) == 0) {
        temp = (u32) ((s32 (*)(s32))get_card_entry__17TWindowSubComCardFi)(0);
        ((s32 (*)(s32, s32, s32))forward_to_matching_card__17TWindowSubComCardFPvPvi)(arg0, (s32) temp, 0xD2);
        load_player_data__23TAdSinglePlyChrSelectGCFv();
    }
}
}
typedef char RecoveredGlobal_8007AE8C_TWindowGetComCard__data_80500158_size[sizeof(RecoveredGlobal_8007AE8C_TWindowGetComCard__data_80500158) == 0x240 ? 1 : -1];
void handle_6x06_send_guild_card(s32 arg0) {
    s32 temp_r31;
    bswap_guild_card__17TWindowSubComCardFv();
    temp_r31 = arg0 + 4;
    if ((((s32 (*)(int))TWindowSubComCard__sub_8007B070)(temp_r31) == 0) && (((TWindowSubComCard *)temp_r31)->send_guild_card() == 0)) {
        TWindowSubShortMail__sub_8007B824();
        if (((s32 (*)(int, void *, int))TWindowSubComCard__sub_8007B0D0)(temp_r31, &TWindowGetComCard__received_guild_card_tags.value, 4) == 0) {
            ((s32 (*)(int, void *, int))TWindowSubComCard__sub_8007B1AC)(temp_r31, &TWindowGetComCard__received_guild_card_tags.value, 4);
        }
    }
}

typedef struct Big { u8 b[144]; } Big;

struct O_8007B26C { u8 pad[0x8c]; s8 flags; };

struct Card_8007AF60 { u8 body[0x90]; };

struct Card_8007B010 { u8 body[0x90]; };

struct Card_8007AFB8 { u8 body[0x100]; };

struct Card_8007B0D0 {
    u8 pad[0x8F];
    s8 level;
};

extern "C" {
s32 init_card__17TWindowSubComCardFPv(s32 *, s32);
s32 count_leading_active__17TWindowSubComCardFPvi(Card_8007AF60 *p, s32 n);
s32 TWindowSubComCard__sub_8007B010(Card_8007B010 *p, s32 n);
int fill_guild_card_from_char__6TLobbyFl(void*, void*);
int memset(void*, int, int);

#pragma push
#pragma fp_contract on
void TWindowSubComCard__sub_8007AF10(s32 arg0) {
    Big spC;
    s32 sp8;
    s32 temp;
    ((TWindowSubComCard *)(&sp8))->init_guild_card();
    temp = TWindowSubComCard::get_keyboard_mode();
    ((s32 (*)(Big *, s32))copy_struct__17TWindowSubComCardFPvPv)(&spC, temp);
    init_card__17TWindowSubComCardFPv(&sp8, arg0);
}
#pragma pop

s32 count_leading_active__17TWindowSubComCardFPvi(Card_8007AF60 *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, p++) {
        if (((TWindowSubComCard *)p)->is_active() == 0) {
            break;
        }
    }
    return i;
}

s32 TWindowSubComCard::count_active_cards() {
    Card_8007AFB8 *p = ((Card_8007AFB8 * (*)(s32))get_card_entry__17TWindowSubComCardFi)(0);
    s32 i;
    for (i = 0; i < 0xD2; i++, p++) {
        if (((TWindowSubComCard *)p)->is_active() == 0) {
            break;
        }
    }
    return i;
}

s32 TWindowSubComCard__sub_8007B010(Card_8007B010 *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, p++) {
        if (((TWindowSubComCard *)p)->is_active() == 0) {
            return 1;
        }
    }
    return 0;
}

u32 TWindowSubComCard__sub_8007B070(u8 *arg0) {
    if ((s8) *(u8 *)((s8 *)arg0 + 0x87) != 0) {
        return 1U;
    }
    if ((s32) *(u8 *)((s8 *)arg0 + 0x8C) != 1) {
        return 1U;
    }
    if ((s8) *(u8 *)((s8 *)arg0 + 0x8D) < 0) {
        return 1U;
    }
    if ((s8) *(u8 *)((s8 *)arg0 + 0x8E) < 0) {
        return 1U;
    }
    return (u32) (s8) *(u8 *)((s8 *)arg0 + 0x8F) >> 0x1FU;
}

s32 TWindowSubComCard__sub_8007B0D0(Card_8007B0D0 *self, Card_8007B0D0 *cards, s32 count) {
    u32 id;
    s32 i;
    id = ((TWindowSubComCard *)self)->get_card_id();
    for (i = 0; i < count; i++, cards++) {
        if (((TWindowSubComCard *)cards)->is_active() == 0) {
            return 0;
        }
        if (id == ((TWindowSubComCard *)cards)->get_card_id()) {
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

void TWindowSubComCard__sub_8007B1AC(void *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    u32 id = ((TWindowSubComCard *)arg0)->get_card_id();
    for (i = 0; i < arg2; i++, arg1 += 0x90) {
        if (((TWindowSubComCard *)arg1)->is_active() == 0) {
            break;
        }
        if (id == ((TWindowSubComCard *)arg1)->get_card_id()) {
            break;
        }
    }
    if (i < arg2) {
        ((s32 (*)(void *, void *))forward_return_arg__17TWindowSubComCardFi)(arg1, arg0);
    }
}

void TWindowSubComCard::set_text(void *arg1) {
    ((s32 (*)(void *, void *, int))strncpy)((void *) (((u8 *)this) + 0x20), arg1, 0x6B);
    *(s8 *)((s8 *)((u8 *)this) + 0x8B) = 0;
}

void TWindowSubComCard__sub_8007B26C(O_8007B26C *self) {
    self->flags &= ~1;
}

int clear(void* p) { return memset(p, 0, 144); }

void TWindowSubComCard::clear_and_init(void* a1) { clear(this); fill_guild_card_from_char__6TLobbyFl(this, a1); }
s32 fn_8007B2E0(u8 *arg0, s32 id) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(find_short_mail_by_id__6TLobbyFUi(id));
    if (temp_r3 == NULL) {
        return 0;
    }
    *(u8 *)((s8 *)arg0 + 0x8C) = (u8) (*(u8 *)((s8 *)arg0 + 0x8C) | 3);
    ((s32 (*)(void *, int, int))strncpy)(arg0 + 8, (int) (fn_8007B83C(temp_r3)), 0x17);
    *(s8 *)((s8 *)arg0 + 0x1F) = 0;
    *(s8 *)((s8 *)arg0 + 0x8F) = 0xC;
    *(s8 *)((s8 *)arg0 + 0x8E) = 0xA;
    *(s8 *)((s8 *)arg0 + 0x8D) = 5;
    *(s32 *)((s8 *)arg0 + 4) = TWindowSubShortMail__sub_8007B834(temp_r3);
    return 1;
}

}
