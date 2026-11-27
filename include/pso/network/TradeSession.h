#ifndef PSO_NETWORK_TRADESESSION_H
#define PSO_NETWORK_TRADESESSION_H
#include "types.h"
#include "pso/network/TradeItemEntry.h"

struct G_ModifyTradeProposal_6xA6;
struct TTradeList;
struct TWindowSubTrade;
struct TWindowSubTradeMain;
class TWindowSubTradeMessage;

// [0] is the local player's side, [1] the trade partner's.
extern TradeSide trade_window_state[2];
// The trade session state (.sbss), defined in TradeSession.cpp.
extern u16 trade_protocol_flags;
extern s8 trade_partner_client_id;
extern u8 trade_proposal_state;
extern s32 trade_proposal_delay;
extern TWindowSubTradeMain *trade_main_window;

// Handlers of a 6xA6 trade proposal, by trade state and proposal type (what).
typedef void (*TradeProposalHandler)(G_ModifyTradeProposal_6xA6 *proposal);
extern "C" TradeProposalHandler trade_proposal_state_handlers[10][8];

TradeItemList *get_trade_list_items(void);
TradeItemList *get_trade_offer_items(void);
TradeItemList *get_trade_window_state(void);

// The open trade windows register here; each call returns 1 when it changed the slot.
s32 clear_trade_message_controller_if_owner(TWindowSubTradeMessage *window);
s32 set_trade_message_controller(TWindowSubTradeMessage *window);
s32 release_trade_main_window(TWindowSubTradeMain *window);
s32 claim_trade_main_window(TWindowSubTradeMain *window);
s32 release_trade_sub_window(TWindowSubTrade *window);
s32 claim_trade_sub_window(TWindowSubTrade *window);

void cancel_trade_for_member_out_of_range(s32 client_id);
const char *format_trade_out_of_range_message(s32 client_id);
void handle_6xA6_modify_trade_proposal(G_ModifyTradeProposal_6xA6 *packet);
void handle_6xA7(void);
void handle_state_init(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_final_confirmation(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_item_amount(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_item_move(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_request_state_a(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_request_state_b(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_offer_confirmation(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_partner_cancel(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_request_reply(G_ModifyTradeProposal_6xA6 *proposal);
void handle_trade_state_cancel(G_ModifyTradeProposal_6xA6 *proposal);
void ignore_trade_proposal_event(G_ModifyTradeProposal_6xA6 *proposal);
void reset_trade_session(void);
// Resets the trade state and shows message in the trade message window.
void reset_trade_session(const char *message);
void send_trade_busy_reply(saddr client_id);
void update_status_message(G_ModifyTradeProposal_6xA6 *proposal);

const char *build_trade_partner_status_text(void);
void send_6xA6_modify_trade_proposal(saddr client_id);

void snapshot_trade_inventories(void);
// Buys the partner's traded items (the D3 list) once the trade reached state 8.
void handle_trade_received_items(TTradeList *trade_list);
s32 are_both_trade_offers_confirmed(void);
void clear_local_trade_final_confirmation(void);
void clear_local_trade_offer_confirmation(void);
s32 is_local_trade_offer_confirmation_requested(void);
void set_local_trade_final_confirmation(void);
void set_local_trade_offer_confirmation(void);

// One bit per client id: set while that player stands in the trade range.
s32 is_trade_range_bit_set(s32 client_id);
void clear_trade_range_bit(s32 client_id);
void set_trade_range_bit(s32 client_id);

// Per-frame steps of the trade session update_game_modes runs.
void update_trade_list_send();
void update_trade_partner();
void update_battle_mode();
void update_trade_proposal_state();


// Trade window steps the lobby and the trade windows run.
void cancel_trade();
void close_trade_request();
void reset_trade_state();
void check_flags_and_proceed();
void handle_reset_choice(s32 choice);
const char *check_trade_items_and_show_error();
void send_trade_proposal_modify();
const char *show_event_message(s32 client_id, s32 result, s32 item_id);

#endif
