#ifndef PSO_NETWORK_TRADESESSION_H
#define PSO_NETWORK_TRADESESSION_H
#include "types.h"
#include "pso/network/TradeItemEntry.h"

// [0] is the local player's side, [1] the trade partner's.
extern TradeSide trade_window_state[2];
// The trade session state (.sbss), defined in TradeSession.cpp.
extern u16 trade_protocol_flags;
extern s8 trade_partner_client_id;
extern u8 trade_proposal_state;
extern s32 trade_proposal_delay;
extern uaddr trade_main_window;

struct G_ModifyTradeProposal_6xA6;

typedef void (*TradeProposalHandler)(void* packet);
extern "C" TradeProposalHandler trade_proposal_state_handlers[10][8];

void cancel_trade_for_member_out_of_range(s32 client_id);
s32 format_trade_out_of_range_message(s32 client_id);
void handle_6xA6_modify_trade_proposal(u8 *message_window);
void handle_6xA7(void);
void handle_state_init(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_final_confirmation(void *packet);
void handle_trade_item_amount(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_item_move(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_request_state_a(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_request_state_b(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_offer_confirmation(void *packet);
void handle_trade_partner_cancel(void *packet);
void handle_trade_request_reply(void *packet);
void handle_trade_state_cancel(G_ModifyTradeProposal_6xA6 *proposal);
void ignore_trade_proposal_event(void);
extern "C" {
void reset__6TLobbyFi(saddr text_handle);
void reset__6TLobbyFv(void);
void send_6xA6_modify_trade_proposal(saddr client_id);
}
void send_trade_busy_reply(saddr client_id);
void update_status_message(G_ModifyTradeProposal_6xA6 *proposal);

// --- C functions defined in TradeSession.cpp ---
extern "C" {
void reset__6TLobbyFi(saddr text_handle);
saddr build_trade_partner_status_text(void);
}
// --- end of C functions

#endif
