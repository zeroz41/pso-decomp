#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/subcmd_6x.h"


void TLobby::update_game_modes() { TLobby::update_trade_partner(); TLobby::update_battle_mode(); TLobby::update_trade_proposal_state(); TLobby::update_trade_list_send(); }
void close_trade_request__6TLobbyFPv(void* p) { ((TLobby *)p)->close_trade_request(); }
void TLobby__sub_802D39BC(void* p) { ((TLobby *)p)->close_trade_request(); }
void TLobby__sub_802D39DC(void* p) { ((TLobby *)p)->reset_trade_state(); }
void TLobby__sub_802D39FC(void* p) { ((TLobby *)p)->reset_trade_state(); }
void G_ModifyTradeProposal_6xA6::bswap() {
    header.bswap();
    bswap_32(&item_id);
    bswap_32(&amount);
}

void G_ModifyTradeProposal_6xA6::prepare_and_send(u32 client_id) {
    prepare();
    ((game_command *)this)->send_to_client(client_id);
}
void build_6xA6_modify_trade_proposal(void* p) { *(u8*)((char*)p + 0x0) = 166; *(u8*)((char*)p + 0x1) = 4; }


void TLobby__sub_802D3AA8(void) {
    lbl_805D63FC |= 8;
}
