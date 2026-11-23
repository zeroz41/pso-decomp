#ifndef PSO_NETWORK_TRADESESSION_H
#define PSO_NETWORK_TRADESESSION_H
#include "types.h"
#include "pso/network/TradeItemEntry.h"

// One side of the trade window state: two 31-entry item lists.
struct Half_802D38B4 { TradeItemEntry lists[2][0x1F]; };

extern "C" Half_802D38B4 trade_window_state[2];
// The trade session state (.sbss), defined in TradeSession.cpp.
extern u16 trade_protocol_flags;
extern s8 trade_partner_client_id;
extern u8 trade_proposal_state;
extern s32 trade_proposal_delay;
extern uaddr trade_main_window;

typedef void (*TradeProposalHandler)(void* packet);
extern "C" TradeProposalHandler trade_proposal_state_handlers[10][8];

void cancel_trade_for_member_out_of_range(s32 client_id);
s32 format_trade_out_of_range_message(s32 client_id);
void handle_6xA6_modify_trade_proposal(u8 *message_window);
void handle_6xA7(void);
void handle_trade_final_confirmation(void *arg0);
void handle_trade_offer_confirmation(void *arg0);
void handle_trade_partner_cancel(void *arg0);
void handle_trade_request_reply(void *arg0);
void ignore_trade_proposal_event(void);
extern "C" {
void reset__6TLobbyFi(saddr text_handle);
void reset__6TLobbyFv(void);
void send_6xA6_modify_trade_proposal(saddr client_id);
}
void send_trade_busy_reply(saddr client_id);

// --- C functions defined in TradeSession.cpp ---
extern "C" {
void reset__6TLobbyFi(saddr text_handle);
saddr build_trade_partner_status_text(void);
u8 *copy_struct_f8__6TLobbyFii(saddr arg0, saddr arg1);
}
// --- end of C functions

#endif
