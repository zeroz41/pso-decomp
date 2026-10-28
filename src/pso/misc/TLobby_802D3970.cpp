#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_802D3970.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int reset_trade_state__6TLobbyFv(void*);
int close_trade_request__6TLobbyFv(void*);

void TLobby::update_game_modes() { TLobby::update_trade_partner(); TLobby::update_battle_mode(); TLobby::update_trade_proposal_state(); TLobby::update_trade_list_send(); }
int close_trade_request__6TLobbyFPv(void* p) { return close_trade_request__6TLobbyFv(p); }
int TLobby__sub_802D39BC(void* p) { return close_trade_request__6TLobbyFv(p); }
int TLobby__sub_802D39DC(void* p) { return reset_trade_state__6TLobbyFv(p); }
int TLobby__sub_802D39FC(void* p) { return reset_trade_state__6TLobbyFv(p); }
void TLobby::byteswap_trade_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }
void TLobby::prepare_and_send_trade_packet(void* a1) { this->prepare_trade_packet(); send_subcommand_to_client((u32)a1); }
}
void build_6xA6_modify_trade_proposal(void* p) { *(u8*)((char*)p + 0x0) = 166; *(u8*)((char*)p + 0x1) = 4; }

extern u16 lbl_805D63FC;

void TLobby__sub_802D3AA8(void) {
    lbl_805D63FC |= 8;
}
