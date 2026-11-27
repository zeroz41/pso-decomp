#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/network/TradeProposalCmd.h"
#include "pso/system/byteswap.h"
#include "pso/network/TLobby.h"
#include "pso/network/TradeSession.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/subcmd_6x.h"


void update_game_modes() { update_trade_partner(); update_battle_mode(); update_trade_proposal_state(); update_trade_list_send(); }
void close_trade_request_on_floor_unload() { close_trade_request(); }
void close_trade_request_on_floor_load() { close_trade_request(); }
void reset_trade_state_on_scene_unload() { reset_trade_state(); }
void reset_trade_state_on_scene_load() { reset_trade_state(); }
void G_ModifyTradeProposal_6xA6::bswap() {
    header.bswap();
    bswap_32(&item_id);
    bswap_32(&amount);
}

void G_ModifyTradeProposal_6xA6::prepare_and_send(u32 client_id) {
    prepare();
    ((game_command *)this)->send_to_client(client_id);
}
void build_6xA6_modify_trade_proposal(G_ModifyTradeProposal_6xA6 *cmd) {
    cmd->header.subcommand = 0xA6;
    cmd->header.size = sizeof(G_ModifyTradeProposal_6xA6) / 4;
}


void set_trade_active(void) {
    short_mail_flags |= 8;
}
