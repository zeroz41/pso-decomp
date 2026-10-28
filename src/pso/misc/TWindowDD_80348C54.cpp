#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TWindowDD.h"

struct Pkt_80348C78 { u8 hdr[2]; u16 player; u8 body[0x1c]; };

extern "C" {
extern s32 local_client_id;
void copy_chat_entry__9TWindowDDFPvPv(void *, void *);
int bswap_word_select__9TWindowDDFv(void*);

int TWindowDD::handle_word_select() { return bswap_word_select__9TWindowDDFv((char*)this + 0x4); }

void TWindowDD::send_chat_packet(void *data) {
    Pkt_80348C78 pkt;
    ((TWindowDD *)(&pkt))->init_header();
    pkt.player = local_client_id;
    copy_chat_entry__9TWindowDDFPvPv(pkt.body, data);
    ((TWindowDD *)(&pkt))->update_and_send_lobby();
}

void TWindowDD::update_and_send_lobby() { handle_word_select(); send_subcommand((u8 *)this); }
void TWindowDD::init_header() { *(u8*)((char*)this + 0x0) = 116; *(u8*)((char*)this + 0x1) = 8; }

}
