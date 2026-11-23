#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/network/protocol/packet_classes.h"


void TLobby::update_game_modes() { TLobby::update_trade_partner(); TLobby::update_battle_mode(); TLobby::update_trade_proposal_state(); TLobby::update_trade_list_send(); }
void close_trade_request__6TLobbyFPv(void* p) { ((TLobby *)p)->close_trade_request(); }
void TLobby__sub_802D39BC(void* p) { ((TLobby *)p)->close_trade_request(); }
void TLobby__sub_802D39DC(void* p) { ((TLobby *)p)->reset_trade_state(); }
void TLobby__sub_802D39FC(void* p) { ((TLobby *)p)->reset_trade_state(); }
void TLobby::byteswap_trade_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }
void TLobby::prepare_and_send_trade_packet(u32 client_id) { this->prepare_trade_packet(); ((game_command *)this)->send_to_client(client_id); }
void build_6xA6_modify_trade_proposal(void* p) { *(u8*)((char*)p + 0x0) = 166; *(u8*)((char*)p + 0x1) = 4; }


void TLobby__sub_802D3AA8(void) {
    lbl_805D63FC |= 8;
}
