#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubComCard_8007B6D8.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/TLobby.h"
#include "pso/network/protocol/packet_classes.h"

struct O_8007B6F4 { u8 pad[0x8c]; u8 flags; };

extern "C" {
s32 TWindowSubComCard__sub_8007B6F4(O_8007B6F4 *self);
int bswap__16TPlyGuildCardTagFv(void*);

s32 GuildCardEntry::get_card_id() const { return id; }
int GuildCardEntry::is_active() const { return flags & 1; }
u8 TWindowSubComCard__sub_8007B6EC(void* p) { return *(u8*)((char*)p + 0x8f); }

s32 TWindowSubComCard__sub_8007B6F4(O_8007B6F4 *self) {
    if (self->flags & 2) {
        return 0;
    }
    return 1;
}

void TWindowSubComCard::bswap_guild_card() { ((G_ClientIDHeader *)this)->bswap(); ((TWindowSubComCard *)((char*)this + 0x4))->bswap_guild_card_tag(); }
int TWindowSubComCard::bswap_guild_card_tag() { return bswap__16TPlyGuildCardTagFv(this); }
void TWindowSubComCard::init_card(void* client_id) { bswap_guild_card(); ((game_command *)this)->send_to_client((uaddr)client_id); }

    extern int com_card_keyboard_mode;
int TWindowSubComCard::get_keyboard_mode() {  return com_card_keyboard_mode; }

void *TWindowSubComCard::init_guild_card() {
    init_guild_card_tag__17TWindowSubComCardFi((saddr)((char *)this + 4));
    *(u8 *)&this->m_name = 6;
    *(u8 *)((s8 *)this + 0x1) = 37;
    return this;
}

}
