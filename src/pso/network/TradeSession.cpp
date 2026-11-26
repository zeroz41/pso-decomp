#include "pso/player/TPlyDispData.h"
#include "pso/player/PlayerStatusRefresh.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/network/client_id.h"
#include "pso/network/TradeSession.h"

#include "pso/network/TProtocol.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/network/TradeProposalCmd.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/TWindowSubTradeMessage.h"
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TPlyItem.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/enemy/BattleParamTables.h"

void TWindowTradeRequest::reset_trade() {
    if ((s32) trade_proposal_state == 2) {
        TLobby::send_trade_proposal_result(0, 3);
        TWindowTradeRequest::close_request_window();
        reset_trade_session();
    }
}


void TLobby::send_trade_proposal_modify() {
  G_ModifyTradeProposal_6xA6 packet;
  TObjPlayer *player;
  player_stats *stats;
  build_6xA6_modify_trade_proposal(&packet.header);
  if (((s32) trade_proposal_state) == 2)
  {
    player = get_player_by_client_id(local_client_id);
    if (player)
    {
      stats = player->get_stats();
      if (stats != 0)
      {
        packet.what = 0;
        packet.result = 2;
        packet.amount = stats->meseta;
        packet.prepare_and_send(trade_partner_client_id);
        trade_proposal_state = 3;
      }
    }
  }
}

void TLobby::update_trade_list_send() {
    TTradeList list;
    switch ((s8) trade_proposal_state) {
    case 5:
        if ((trade_protocol_flags & 0x100) && (trade_protocol_flags & 0x200)) {
            trade_proposal_state = 6;
        }
        break;
    case 6:
        list.build_from_trade_window();
        protocol_instance->send_trade_list(&list);
        trade_protocol_flags |= 0x400;
        if (trade_main_window != NULL) {
            trade_main_window->show_trade_status();
        }
        trade_proposal_state = 7;
        break;
    case 7:
    case 8:
        if (!(trade_protocol_flags & 0x100) || !(trade_protocol_flags & 0x200)) {
            TLobby::clear_flag400();
        }
        break;
    }
}

void TLobby::update_trade_proposal_state() {
    if (!(trade_protocol_flags & 0x10)) {
        trade_proposal_delay = 0;
        if (trade_protocol_flags & 0x20) {
            TLobby::send_trade_proposal_result(3, 4);
            trade_protocol_flags &= 0xFFFFFFDF;
            if (trade_main_window != NULL) {
                trade_main_window->forward_to_child(0);
            }
            trade_proposal_state = 3;
        }
    } else if (!(trade_protocol_flags & 0x20)) {
        if (trade_proposal_delay++ >= 0x1E) {
            TLobby::send_trade_proposal_result(3, 0);
            trade_protocol_flags |= 0x20;
            if (trade_main_window != NULL) {
                trade_main_window->forward_to_child(1);
            }
            trade_proposal_delay = 0;
            trade_proposal_state = 4;
        }
    } else if (!(trade_protocol_flags & 0x80)) {
        trade_proposal_delay = 0;
        if (trade_protocol_flags & 0x100) {
            TLobby::send_trade_proposal_result(4, 4);
            if (trade_main_window != NULL) {
                trade_main_window->forward_to_child(1);
            }
            trade_protocol_flags &= 0xFFFFFEFF;
            trade_proposal_state = 4;
        }
    } else if (!(trade_protocol_flags & 0x100)) {
        if (trade_proposal_delay++ >= 0x1E) {
            TLobby::send_trade_proposal_result(4, 0);
            trade_protocol_flags |= 0x100;
            if (trade_main_window != NULL) {
                trade_main_window->forward_to_child(2);
            }
            trade_proposal_delay = 0;
            trade_proposal_state = 5;
        }
    }
}

#pragma push
#pragma scheduling off
saddr build_trade_partner_status_text(void) {
    text_builder_reset();
    refresh_player_status(trade_partner_client_id);
    text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xF6));
    return (saddr)get_shared_text_buffer();
}
#pragma pop

s32 TLobby::check_trade_items_and_show_error() {
    s32 code;
    TradeSide buf;
    s32 r;
    s32 flag = 0;
    buf.clear();
    buf.lists[0] = trade_window_state[1].lists[0];
    buf.lists[1] = trade_window_state[0].lists[1];
    r = check_trade_offer_inventory(&buf, &code);
    if (r == 4) {
        flag = 1;
    } else if (r != 0) {
        return TLobby::show_event_message(local_client_id, r, code);
    }
    buf.clear();
    buf.lists[0] = trade_window_state[0].lists[0];
    buf.lists[1] = trade_window_state[1].lists[1];
    r = check_trade_offer_inventory(&buf, &code);
    if (r == 4) {
        if (flag) {
            return TLobby::show_event_message(trade_partner_client_id, 4, code);
        }
    } else if (r != 0) {
        return TLobby::show_event_message(trade_partner_client_id, r, code);
    }
    return 0;
}

// The trade session state (.sbss).
u16 trade_protocol_flags;
s8 trade_partner_client_id;
u8 trade_proposal_state;
s32 trade_partner_meseta;
s32 trade_proposal_delay;
TWindowSubTrade *trade_sub_window;
TWindowSubTradeMain *trade_main_window;
TWindowSubTradeMessage *trade_message_controller;

// The trade window's side: the offer/final confirmation flags, the inventory snapshot and the item moves.

s32 are_both_trade_offers_confirmed(void) {
    u16 v = trade_protocol_flags;
    if (!(v & 0x20)) {
        return 0;
    }
    return (v & 0x40) ? 1 : 0;
}

void clear_local_trade_final_confirmation(void) {
    trade_protocol_flags &= 0xFFFFFF7F;
}

void set_local_trade_final_confirmation(void) {
    trade_protocol_flags |= 0x80;
}

s32 is_local_trade_offer_confirmation_requested(void) {
    return (trade_protocol_flags >> 4U) & 1;
}

void clear_local_trade_offer_confirmation(void) {
    trade_protocol_flags &= 0xFFFFFFEF;
}

void set_local_trade_offer_confirmation(void) {
    trade_protocol_flags |= 0x10;
}

void snapshot_trade_inventories(void) {
  snapshot_player_trade_inventory(&trade_window_state[0], local_client_id);
  snapshot_player_trade_inventory(&trade_window_state[1], trade_partner_client_id);
  trade_window_state[1].set_inventory_meseta(trade_partner_meseta);
}

void TWindowSubTradeMain::draw_offer(u32 item_id, s32 amount) {
    TLobby::send_modify_trade_proposal(2, item_id, amount);
    trade_window_state[0].transfer_trade_item_amount(item_id, amount);
    if (trade_main_window != NULL) {
        trade_main_window->draw_item_slot();
    }
}

void TWindowSubTradeMain::draw_request(u32 item_id, s32 amount) {
    TLobby::send_modify_trade_proposal(1, item_id, amount);
    trade_window_state[0].move_trade_item_amount(item_id, amount);
    if (trade_main_window != NULL) {
        trade_main_window->draw_item_slot();
    }
}

TradeSide trade_window_state[2];

TradeItemList *get_trade_list_items(void) {
    return &trade_window_state[0].lists[1];
}

TradeItemList *get_trade_offer_items(void) {
    return &trade_window_state[1].lists[0];
}

TradeItemList *get_trade_window_state(void) {
    return &trade_window_state[0].lists[0];
}

s32 clear_trade_message_controller_if_owner(TWindowSubTradeMessage *window) {
    if (trade_message_controller != window) {
        return 0;
    }
    trade_message_controller = NULL;
    return 1;
}

s32 set_trade_message_controller(TWindowSubTradeMessage *window) {
    trade_message_controller = window;
    return 1;
}

s32 release_trade_main_window(TWindowSubTradeMain *window) {
    if (trade_main_window != window) {
        return 0;
    }
    trade_main_window = NULL;
    return 1;
}

s32 claim_trade_main_window(TWindowSubTradeMain *window) {
    if (trade_main_window != NULL) {
        return 0;
    }
    trade_main_window = window;
    return 1;
}


s32 release_trade_sub_window(TWindowSubTrade *window) {
    if (trade_sub_window != window) {
        return 0;
    }
    trade_sub_window = NULL;
    return 1;
}

s32 claim_trade_sub_window(TWindowSubTrade *window) {
    if (trade_sub_window != NULL) {
        return 0;
    }
    trade_sub_window = window;
    return 1;
}

void TLobby::apply_trade_items() {
    s32 allowed;
    struct TradeItemEntry *list;
    u32 id;
    TObjPlayer *player;
    struct TradeItemEntry *p;
    s32 i;
    s32 count;
    s32 flag;
    if ((s32) trade_proposal_state == 7) {
        player = get_player_by_client_id(local_client_id);
        if (player != NULL) {
            list = get_trade_window_state()->entries;
            if (list != NULL) {
                allowed = check_player_action_allowed();
                p = list;
                flag = 0;
                for (i = 0; i < 0x1F; i++, p++) {
                    count = p->count;
                    id = p->id;
                    if (count > 0) {
                        if (id == 0xFFFFFF01) {
                            player->try_spend_actor_meseta(count);
                        } else {
                            if ((allowed != 0) && (selected_character_has_item(id) != 0)) {
                                remove_list_entry_by_id(id);
                                flag = 1;
                            }
                            TObjPlayer::send_6x29_delete_item(player, id, count);
                        }
                    }
                }
                if ((flag == 0) || (TAdSinglePlyChrSelectGC::load_character_from_card() == 0)) {
                    trade_proposal_state = 8;
                    protocol_instance->send_trade_ready();
                }
            }
        }
    }
}

void TLobby::handle_reset_choice(s32 choice) {
    if ((s8) trade_proposal_state != 0) {
        switch (choice) {
        case 0:
            reset_trade_session((const char *)TWindowSubStatusDisp::get_message_10(0xEC));
            return;
        case 1:
            reset_trade_session((const char *)TWindowSubStatusDisp::get_message_10(0xEB));
            break;
        }
    }
}

extern "C" void handle_trade_received_items(TTradeList *trade_list) {
    s32 i;
    TItemData *item;
    if ((s32)trade_proposal_state == 8 && trade_list != 0) {
        item = trade_list->items;
        for (i = 0; i < trade_list->item_count; i++, item++) {
            buy_item_for_client(item, local_client_id);
        }
        trade_proposal_state = 9;
    }
}

void handle_6xA7(void) {  }


LAYOUT_ASSERT(TradeProposalStateHandlersSize, sizeof(trade_proposal_state_handlers) == 0x140);
void handle_6xA6_modify_trade_proposal(G_ModifyTradeProposal_6xA6 *packet) {
    TradeProposalHandler handler;
    u16 client_id;
    u8 what;
    packet->bswap();
    client_id = packet->header.client_id;
    if (client_id < 4U && (what = packet->what, what < 8U)) {
        if (trade_partner_client_id != 4 && (s32)client_id != trade_partner_client_id) {
            if (what == 0 && packet->result == 0) {
                send_trade_busy_reply(client_id);
            }
        } else {
            handler = trade_proposal_state_handlers[(s8)trade_proposal_state][what];
            if (handler != NULL) {
                handler(packet);
            }
        }
    }
}

void TLobby::clear_flag400() {
    if (trade_protocol_flags & 0x400) {
        protocol_instance->send_cancel_trade();
        trade_protocol_flags &= 0xFFFFFBFF;
    }
}


void TLobby::check_flags_and_proceed() {
    if ((trade_sub_window == NULL) && (trade_main_window == NULL) && (trade_message_controller == NULL)) {
        TLobby::cancel_trade();
    }
}
void TLobby::cancel_trade() {
    s8 s = trade_proposal_state;
    switch (s) {
    case 0:
        break;
    case 1: case 2: case 3: case 4: case 5: case 6:
        TLobby::send_trade_proposal_result(5, 4);
        reset_trade_session();
        break;
    case 7:
    case 8:
        protocol_instance->send_cancel_trade();
        break;
    case 9:
        break;
    }
}


const char *format_trade_out_of_range_message(s32 client_id) {
    if ((s32) local_client_id == client_id) {
        return (const char *)TWindowSubStatusDisp::get_message_10(0xF0);
    }
    text_builder_reset();
    refresh_player_status(client_id);
    text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xEF));
    return get_shared_text_buffer();
}

s32 TLobby::show_event_message(s32 client_id, s32 result, s32 item_id) {
    TItem *item;

    switch (result) {
    case 0:
        return 0;
    case 1:
        if (client_id == (s32) local_client_id) {
            return (saddr)TWindowSubStatusDisp::get_message_10(0xF4);
        }
        text_builder_reset();
        refresh_player_status(client_id);
        text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xEA));
        return (saddr)get_shared_text_buffer();
    case 2:
        item = find_item_by_id(item_id);
        if (item == NULL) {
            return 0;
        }
        text_builder_reset();
        if (client_id == (s32) local_client_id) {
            text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xF3));
        } else {
            refresh_player_status(client_id);
            text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xE8));
        }
        text_builder_append(item->get_name());
        text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xE9));
        return (saddr)get_shared_text_buffer();
    case 3:
        if (client_id == (s32) local_client_id) {
            return (saddr)TWindowSubStatusDisp::get_message_10(0xF2);
        }
        text_builder_reset();
        refresh_player_status(client_id);
        text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xE7));
        return (saddr)get_shared_text_buffer();
    case 4:
        return (saddr)TWindowSubStatusDisp::get_message_10(0xEE);
    default:
        return 0;
    }
}


void reset_trade_session() {
    if (is_trade_active() == 0) {
        trade_partner_client_id = 4;
        trade_proposal_state = 0;
        trade_partner_meseta = 0;
        trade_proposal_delay = 0;
        trade_protocol_flags &= 0xFFFFF80F;
        if (trade_message_controller != NULL) {
            trade_message_controller->finish();
        }
        if (trade_main_window != NULL) {
            trade_main_window->finish();
        }
        if (trade_sub_window != NULL) {
            trade_sub_window->finish();
        }
    }
}

LAYOUT_ASSERT(TradeProposalSize, sizeof(G_ModifyTradeProposal_6xA6) == 0x10);
LAYOUT_ASSERT(TradeProposalAmountOffset, offsetof(G_ModifyTradeProposal_6xA6, amount) == 0xC);

void reset_trade_session(const char *message) {
    if (is_trade_active() == 0) {
        trade_proposal_state = 0;
        trade_partner_client_id = 4;
        trade_partner_meseta = 0;
        trade_proposal_delay = 0;
        trade_protocol_flags &= 0xFFFFF80F;
        TWindowCtrl::replace_submenu(local_client_id, 0x1E);
        TWindowSubTradeMessage *controller = trade_message_controller;
        if (controller != NULL) {
            controller->show_message(message);
        }
    }
}

void cancel_trade_for_member_out_of_range(s32 client_id) {
    G_ModifyTradeProposal_6xA6 packet;
    build_6xA6_modify_trade_proposal(&packet.header);
    packet.what = 7;
    packet.result = 0;
    packet.out_of_range_client_id = client_id;
    packet.prepare_and_send(trade_partner_client_id);
    if ((s8)trade_proposal_state == 2) {
        TWindowTradeRequest::close_request_window();
        reset_trade_session();
        return;
    }
    reset_trade_session(format_trade_out_of_range_message(client_id));
}

void send_trade_busy_reply(saddr client_id) {
    G_ModifyTradeProposal_6xA6 packet;
    build_6xA6_modify_trade_proposal((&packet.header));
    packet.what = 6;
    packet.result = 0;
    packet.prepare_and_send(client_id);
}

void TTradeList::build_from_trade_window() {
    TItemData item;
    TradeItemEntry *list;
    target_client_id = trade_partner_client_id;
    item_count = 0;
    list = get_trade_window_state()->entries;
    if (list != NULL) {
        u32 i;
        s32 n;
        TradeItemEntry *e;
        u32 id;
        TItem *found;
        e = list;
        for (i = 0; i < 31; i++, e++) {
            n = e->count;
            id = e->id;
            if (n > 0) {
                if (id == 0xFFFFFF01) {
                    ((&item))->init_meseta(n);
                    items[item_count++].copy_from(&item);
                } else if ((found = find_item_by_id(id)) != NULL) {
                    found->copy_to_item_data(&item);
                    item.id = 0xFFFFFFFF;
                    item.set_stack_count(n);
                    items[item_count++].copy_from(&item);
                }
            }
        }
    }
}

void TLobby::send_modify_trade_proposal(s8 what, s32 item_id, s32 amount) {
  G_ModifyTradeProposal_6xA6 packet;
  build_6xA6_modify_trade_proposal(&packet.header);
  packet.what = what;
  packet.result = 0;
  packet.item_id = item_id;
  packet.amount = amount;
  packet.prepare_and_send(trade_partner_client_id);
}

void TLobby::send_trade_proposal_result(s8 what, s8 result) {
  G_ModifyTradeProposal_6xA6 packet;
  build_6xA6_modify_trade_proposal(&packet.header);
  packet.what = what;
  packet.result = result;
  packet.prepare_and_send(trade_partner_client_id);
}

void send_6xA6_modify_trade_proposal(saddr client_id) {
    G_ModifyTradeProposal_6xA6 packet;
    TObjPlayer *player;
    player_stats *stats;
    build_6xA6_modify_trade_proposal((&packet.header));
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (stats = player->get_stats(), stats != NULL)) {
        if ((s32) (u8)trade_partner_client_id != 4) {
            TWindowTradeRequest::close_request_window();
            if (trade_partner_client_id == client_id) {
                TLobby::send_trade_proposal_modify();
                TWindowCtrl::replace_submenu(local_client_id, 0x1D);
                return;
            }
            send_trade_busy_reply(trade_partner_client_id);
        }
        packet.what = 0;
        packet.result = 0;
        packet.amount = stats->meseta;
        packet.prepare_and_send(client_id);
        trade_partner_client_id = (s8) client_id;
        trade_proposal_state = 1;
    }
}

void ignore_trade_proposal_event(G_ModifyTradeProposal_6xA6 *proposal) {  }

extern "C" void handle_trade_member_out_of_range(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 0:
        reset_trade_session(format_trade_out_of_range_message(proposal->out_of_range_client_id));
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_state_cancel(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 3:
        break;
    case 4:
        TLobby::protocol_instance->send_cancel_trade();
        break;
    }
}
void handle_trade_partner_cancel(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 4:
        text_builder_reset();
        refresh_player_status(trade_partner_client_id);
        text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xED));
        reset_trade_session(get_shared_text_buffer());
        break;
    case 3:
        break;
    }
}

void handle_trade_final_confirmation(G_ModifyTradeProposal_6xA6 *proposal) {

    switch ((s32) proposal->result) {
    case 0:
        trade_protocol_flags |= 0x200;
        if (trade_main_window != NULL) {
            trade_main_window->notify_child_if_present(2);
        }
        break;
    case 4:
        trade_protocol_flags &= 0xFFFFFDFF;
        if (trade_main_window != NULL) {
            trade_main_window->notify_child_if_present(1);
        }
        break;
    }
}

void handle_trade_offer_confirmation(G_ModifyTradeProposal_6xA6 *proposal) {

    switch ((s32) proposal->result) {
    case 0:
        trade_protocol_flags |= 0x40;
        if (trade_main_window != NULL) {
            trade_main_window->notify_child_if_present(1);
        }
        break;
    case 4:
        trade_protocol_flags &= 0xFFFFFFBF;
        if (trade_main_window != NULL) {
            trade_main_window->notify_child_if_present(0);
        }
        break;
    }
}

void handle_trade_item_amount(G_ModifyTradeProposal_6xA6 *proposal) {
    s32 t = proposal->result;
    switch (t) {
    case 0:
        if (proposal->header.client_id == trade_partner_client_id) {
            trade_window_state[1].transfer_trade_item_amount(proposal->item_id, proposal->amount);
            if (trade_main_window != 0) {
                trade_main_window->update_trade_window();
            }
        }
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_item_move(G_ModifyTradeProposal_6xA6 *proposal) {
    s32 t = proposal->result;
    switch (t) {
    case 0:
        if (proposal->header.client_id == trade_partner_client_id) {
            trade_window_state[1].move_trade_item_amount(proposal->item_id, proposal->amount);
            if (trade_main_window != 0) {
                trade_main_window->update_trade_window();
            }
        }
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_request_state_a(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 0:
        TWindowTradeRequest::close_request_window();
        reset_trade_session();
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_request_state_b(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 3:
        break;
    case 4:
        TWindowTradeRequest::close_request_window();
        reset_trade_session();
        break;
    }
}

void update_status_message(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 0:
        text_builder_reset();
        refresh_player_status(trade_partner_client_id);
        text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xF1));
        reset_trade_session(get_shared_text_buffer());
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_request_reply(G_ModifyTradeProposal_6xA6 *proposal) {
    switch ((s32) proposal->result) {
    case 2:
        trade_partner_meseta = proposal->amount;
        TWindowCtrl::replace_submenu(local_client_id, 0x1D);
        trade_proposal_state = 3;
        return;
    case 3:
        text_builder_reset();
        refresh_player_status(trade_partner_client_id);
        text_builder_append((const char *)TWindowSubStatusDisp::get_message_10(0xD8));
        reset_trade_session(get_shared_text_buffer());
        return;
    case 0:
        send_trade_busy_reply(trade_partner_client_id);
    case 4:
        return;
    }
}

void handle_state_init(G_ModifyTradeProposal_6xA6 *proposal) {
    switch (proposal->result) {
    case 0:
        trade_partner_client_id = proposal->header.client_id;
        trade_partner_meseta = proposal->amount;
        TLobby__sub_802D3AA8();
        trade_proposal_state = 2;
        break;
    case 1:
    case 2:
        break;
    }
}

void TLobby::update_battle_mode() {
    if ((s8) trade_proposal_state != 0) {
        if (get_player_by_client_id(local_client_id) == NULL) {
            TLobby::cancel_trade();
            return;
        }
        if (is_trade_range_bit_set(local_client_id) == 0) {
            cancel_trade_for_member_out_of_range(local_client_id);
        }
    }
}

void TLobby::update_trade_partner() {
    if ((s8) trade_proposal_state == 0) {
        return;
    }
    if (trade_partner_client_id == 4) {
        return;
    }
    if (get_player_by_client_id(trade_partner_client_id) == NULL) {
        TLobby::cancel_trade();
        return;
    }
    if (is_trade_range_bit_set(trade_partner_client_id) == 0) {
        cancel_trade_for_member_out_of_range(trade_partner_client_id);
    }
}

void TLobby::close_trade_request() { trade_protocol_flags = 0; TWindowTradeRequest::close_request_window(); }
void TLobby::reset_trade_state() {
    s32 i;
    trade_partner_client_id = 4;
    trade_proposal_state = 0;
    trade_partner_meseta = 0;
    trade_proposal_delay = 0;
    trade_sub_window = NULL;
    trade_main_window = NULL;
    trade_message_controller = NULL;
    for (i = 0; i < 2; i++) {
        trade_window_state[i].clear();
    }
    TLobby::close_trade_request();
}

TradeProposalHandler trade_proposal_state_handlers[10][8] = {
    { handle_state_init, 0, 0, 0, 0, 0, 0, 0 },
    { handle_trade_request_reply, 0, 0, 0, 0, 0, update_status_message, handle_trade_member_out_of_range },
    { 0, 0, 0, 0, 0, handle_trade_request_state_b, 0, handle_trade_request_state_a },
    { ignore_trade_proposal_event, handle_trade_item_move, handle_trade_item_amount, handle_trade_offer_confirmation, handle_trade_final_confirmation, handle_trade_partner_cancel, 0, handle_trade_member_out_of_range },
    { ignore_trade_proposal_event, handle_trade_item_move, handle_trade_item_amount, handle_trade_offer_confirmation, handle_trade_final_confirmation, handle_trade_partner_cancel, 0, handle_trade_member_out_of_range },
    { ignore_trade_proposal_event, ignore_trade_proposal_event, ignore_trade_proposal_event, handle_trade_offer_confirmation, handle_trade_final_confirmation, handle_trade_partner_cancel, 0, ignore_trade_proposal_event },
    { ignore_trade_proposal_event, 0, 0, 0, handle_trade_final_confirmation, handle_trade_partner_cancel, 0, ignore_trade_proposal_event },
    { ignore_trade_proposal_event, 0, 0, 0, handle_trade_final_confirmation, handle_trade_state_cancel, 0, ignore_trade_proposal_event },
    { ignore_trade_proposal_event, 0, 0, 0, handle_trade_final_confirmation, handle_trade_state_cancel, 0, ignore_trade_proposal_event },
    { ignore_trade_proposal_event, 0, 0, 0, 0, handle_trade_state_cancel, 0, ignore_trade_proposal_event },
};

s32 is_trade_range_bit_set(s32 client_id) {
    return (trade_protocol_flags & (1 << client_id)) ? 1 : 0;
}

void clear_trade_range_bit(s32 client_id) {
    trade_protocol_flags &= ~(1 << client_id);
}

void set_trade_range_bit(s32 client_id) {
    trade_protocol_flags |= 1 << client_id;
}
