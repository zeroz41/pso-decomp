#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowSubComCard_8007B6D8.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/TLobby.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"

struct O_8007B6F4 { u8 pad[0x8c]; u8 flags; };

extern "C" {
int bswap__16TPlyGuildCardTagFv(void*);

s32 GuildCardEntry::get_card_id() const { return id; }
int GuildCardEntry::is_active() const { return flags & 1; }
u8 TWindowSubComCard__sub_8007B6EC(void* p) { return ((GuildCardEntry *)p)->char_class; }

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

int TAdSinglePlyChrSelectGC::get_state() {  return guild_card_save_payload; }

void TPlyGuildCardTag::bswap() {
    bswap_32(&m_guildcard_number);
    bswap_16(&m_tag2);
}

void set_guild_card_receive_active() {
    lbl_805D63FC |= 2;
}

s32 ShortMailEntry::get_sender_card_id() { return sender_card_id; }

char *ShortMailEntry::get_sender_name() { return sender_name; }

s32 TObjPlayer::get_section_id() {
    s8 id = *((s8 *)this + 0x88C);
    return id;
}

const char *TObjPlayer::get_name() { return name; }
