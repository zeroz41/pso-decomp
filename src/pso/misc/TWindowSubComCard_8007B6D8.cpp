#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TWindowSubComCard_8007A810.h"
#include "pso/misc/TWindowSubComCard_8007B6D8.h"
#include "pso/misc/TWindowSubComCard.h"

struct O_8007B6F4 { u8 pad[0x8c]; u8 flags; };

extern "C" {
s32 TWindowSubComCard__sub_8007B6F4(O_8007B6F4 *self);
int send_subcommand_to_client__6TLobbyFUl(void*, void*);
int bswap__16TPlyGuildCardTagFv(void*);

s32 TWindowSubComCard::get_card_id() { return *(s32 *)&this->m_flags; }
int TWindowSubComCard::is_active() { return *(u8*)((char*)this + 0x8c) & 0x1; }
u8 TWindowSubComCard__sub_8007B6EC(void* p) { return *(u8*)((char*)p + 0x8f); }

s32 TWindowSubComCard__sub_8007B6F4(O_8007B6F4 *self) {
    if (self->flags & 2) {
        return 0;
    }
    return 1;
}

void TWindowSubComCard::bswap_guild_card() { ((G_ClientIDHeader *)this)->bswap(); ((TWindowSubComCard *)((char*)this + 0x4))->bswap_guild_card_tag(); }
int TWindowSubComCard::bswap_guild_card_tag() { return bswap__16TPlyGuildCardTagFv(this); }
void TWindowSubComCard::init_card(void* a1) { bswap_guild_card(); send_subcommand_to_client__6TLobbyFUl(this, a1); }

    extern int com_card_keyboard_mode;
int TWindowSubComCard::get_keyboard_mode() {  return com_card_keyboard_mode; }

void *TWindowSubComCard::init_guild_card() {
    init_guild_card_tag__17TWindowSubComCardFi((s32)((char *)this + 4));
    *(u8 *)&this->m_name = 6;
    *(u8 *)((s8 *)this + 0x1) = 37;
    return this;
}

}
