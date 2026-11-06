#ifndef PSO_NETWORK_TRADESESSION_H
#define PSO_NETWORK_TRADESESSION_H
typedef void (*TradeProposalHandler)(void* packet);
extern "C" TradeProposalHandler trade_proposal_state_handlers[10][8];

void cancel_trade_for_member_out_of_range(s32 arg0);
s32 format_trade_out_of_range_message(s32 arg0);
void handle_6xA6_modify_trade_proposal(u8 *arg0);
void handle_6xA7(void);
void handle_trade_final_confirmation(void *arg0);
void handle_trade_offer_confirmation(void *arg0);
void handle_trade_partner_cancel(void *arg0);
void handle_trade_request_reply(void *arg0);
void ignore_trade_proposal_event(void);
extern "C" {
void reset__6TLobbyFi(s32 arg0);
void reset__6TLobbyFv(void);
void send_modify_trade_proposal__6TLobbyFi(s32 arg0);
}
void send_trade_busy_reply(s32 arg0);

// --- C functions defined in TradeSession.cpp ---
extern "C" {
void reset__6TLobbyFi(s32 arg0);
}
// --- end of C functions

#endif
