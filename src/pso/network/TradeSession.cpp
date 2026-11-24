#include "pso/player/TPlyDispData.h"
#include "pso/unk/TLobby_80228C84.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/network/client_id.h"
#include "pso/network/TradeSession.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include "pso/network/TProtocol.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/TWindowSubTradeMessage.h"
#include "pso/unk/text_802D298C.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/unk/TLobby_802D1EFC.h"
#include "pso/ui/window/TWindowSubTradeMain_802D2808.h"
#include <stddef.h>
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_801D40D4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/PlayerSlots.h"
struct ByteBlock_F8 { u8 bytes[0xf8]; };

struct Stack_802D23E0
{
  s32 sp8;
  s8 spC;
  s8 spD;
  u8 pad_E[0x6];
  s32 sp14;
};

struct Half_802D26C8 { u8 b[0xF8]; };

struct Pair_802D26C8 { Half_802D26C8 h[2]; };

extern "C" {
s32 get_shared_text_buffer();
s32 text_builder_append();
}
void text_builder_reset(void);
void build_6xA6_modify_trade_proposal(void *);
extern "C" {
void TWindowSubTradeMain__sub_80330A84(void *p);
s32 check_trade_offer_inventory(void *, void *);

typedef struct Stack_802D23E0 Stack_802D23E0;
void TLobby::send_trade_proposal_modify() {
  Stack_802D23E0 stack;
  u8 *player;
  player_stats *temp_r3_2;
  build_6xA6_modify_trade_proposal(&stack.sp8);
  if (((s32) trade_proposal_state) == 2)
  {
    player = (u8 *) get_player_by_client_id(local_client_id);
    if (player)
    {
      temp_r3_2 = ((TObjPlayer *)player)->get_stats();
      if (temp_r3_2 != 0)
      {
        stack.spC = 0;
        stack.spD = 2;
        stack.sp14 = temp_r3_2->meseta;
        if (((u8)trade_partner_client_id && (u8)trade_partner_client_id) && (u8)trade_partner_client_id)
        {
        }
        ((G_ModifyTradeProposal_6xA6 *)&stack.sp8)->prepare_and_send(trade_partner_client_id);
        trade_proposal_state = 3;
      }
    }
  }
}

void TLobby::update_trade_list_send() {
    u8 sp8[0x288];
    switch ((s8) trade_proposal_state) {
    case 5:
        if ((trade_protocol_flags & 0x100) && (trade_protocol_flags & 0x200)) {
            trade_proposal_state = 6;
        }
        break;
    case 6:
        ((TLobby *)sp8)->build_trade_item_list();
        TLobby::send_trade_list(protocol_instance, sp8);
        trade_protocol_flags |= 0x400;
        if ((uaddr) trade_main_window != 0U) {
            TWindowSubTradeMain__sub_80330A84((void *)trade_main_window);
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
            if ((uaddr) trade_main_window != 0U) {
                ((TWindowSubTradeMain *)trade_main_window)->forward_to_child(0);
            }
            trade_proposal_state = 3;
        }
    } else if (!(trade_protocol_flags & 0x20)) {
        if (trade_proposal_delay++ >= 0x1E) {
            TLobby::send_trade_proposal_result(3, 0);
            trade_protocol_flags |= 0x20;
            if ((uaddr) trade_main_window != 0U) {
                ((TWindowSubTradeMain *)trade_main_window)->forward_to_child(1);
            }
            trade_proposal_delay = 0;
            trade_proposal_state = 4;
        }
    } else if (!(trade_protocol_flags & 0x80)) {
        trade_proposal_delay = 0;
        if (trade_protocol_flags & 0x100) {
            TLobby::send_trade_proposal_result(4, 4);
            if ((uaddr) trade_main_window != 0U) {
                ((TWindowSubTradeMain *)trade_main_window)->forward_to_child(1);
            }
            trade_protocol_flags &= 0xFFFFFEFF;
            trade_proposal_state = 4;
        }
    } else if (!(trade_protocol_flags & 0x100)) {
        if (trade_proposal_delay++ >= 0x1E) {
            TLobby::send_trade_proposal_result(4, 0);
            trade_protocol_flags |= 0x100;
            if ((uaddr) trade_main_window != 0U) {
                ((TWindowSubTradeMain *)trade_main_window)->forward_to_child(2);
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
    TWindowSubStatusDisp::get_message_10(0xF6);
    text_builder_append();
    return get_shared_text_buffer();
}
#pragma pop

s32 TLobby::check_trade_items_and_show_error() {
    s32 code;
    Pair_802D26C8 buf;
    s32 r;
    s32 flag = 0;
    ((TLobby *)(&buf))->update_both_halves();
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[0], &trade_window_state[1].lists[0]);
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[1], &trade_window_state[0].lists[1]);
    r = check_trade_offer_inventory(&buf, &code);
    if (r == 4) {
        flag = 1;
    } else if (r != 0) {
        return TLobby::show_event_message((saddr)local_client_id, (s32)r, (s32)code);
    }
    ((TLobby *)(&buf))->update_both_halves();
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[0], &trade_window_state[0].lists[0]);
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[1], &trade_window_state[1].lists[1]);
    r = check_trade_offer_inventory(&buf, &code);
    if (r == 4) {
        if (flag) {
            return TLobby::show_event_message((saddr)(s32)trade_partner_client_id, 4, (s32)code);
        }
    } else if (r != 0) {
        return TLobby::show_event_message((saddr)(s32)trade_partner_client_id, (s32)r, (s32)code);
    }
    return 0;
}

u8 * copy_struct_f8__6TLobbyFii(saddr arg0, saddr arg1) {
    *(ByteBlock_F8 *)(arg0) = *(const ByteBlock_F8 *)(arg1);
    return (u8 *)arg0;
}
}

// The trade session state (.sbss).
u16 trade_protocol_flags;
s8 trade_partner_client_id;
u8 trade_proposal_state;
s32 TLobby__data_805D688C;
s32 trade_proposal_delay;
uaddr TLobby__data_805D6894;
uaddr trade_main_window;
uaddr trade_message_controller;

// The trade window's side: the offer/final confirmation flags, the inventory snapshot and the item moves.

extern s32 local_client_id;

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
    return ((u16) trade_protocol_flags >> 4U) & 1;
}

void clear_local_trade_offer_confirmation(void) {
    trade_protocol_flags &= 0xFFFFFFEF;
}

void set_local_trade_offer_confirmation(void) {
    trade_protocol_flags |= 0x10;
}

void snapshot_trade_inventories(void) {
  s32 *temp_r31;
  snapshot_player_trade_inventory((saddr)&trade_window_state, local_client_id);
  temp_r31 = (s32 *) ((u8 *) ((s32 *) ((u8 *)&trade_window_state + 0x1F0)));
  snapshot_player_trade_inventory((saddr)temp_r31, trade_partner_client_id);
  ((TLobby *)temp_r31)->set_trade_field_4(TLobby__data_805D688C);
}

void TWindowSubTradeMain::draw_offer(void *key, void *amount) {
    TLobby::send_modify_trade_proposal((s8)2, (saddr)key, (saddr)amount);
    ((TLobby *)trade_window_state)->transfer_trade_item_amount((uaddr)key, (saddr)amount);
    if (trade_main_window != NULL) {
        ((TWindowSubTradeMain *)trade_main_window)->draw_item_slot();
    }
}

void TWindowSubTradeMain::draw_request(void *key, void *amount) {
    TLobby::send_modify_trade_proposal((s8)1, (saddr)key, (saddr)amount);
    ((TLobby *)trade_window_state)->move_trade_item_amount((uaddr)key, (saddr)amount);
    if (trade_main_window != NULL) {
        ((TWindowSubTradeMain *)trade_main_window)->draw_item_slot();
    }
}

Half_802D38B4 trade_window_state[2];
extern "C" {

u8 *TLobby__sub_802D298C(void) {
    return (u8 *)trade_window_state[0].lists[1];
}

u8 *TLobby__sub_802D299C(void) {
    return (u8 *)trade_window_state[1].lists[0];
}

s32 *get_trade_window_state(void) {
    return (s32 *)trade_window_state[0].lists[0];
}

s32 clear_trade_message_controller_if_owner(uaddr arg0) {
    if ((uaddr) trade_message_controller != arg0) {
        return 0;
    }
    trade_message_controller = 0U;
    return 1;
}

int set_trade_message_controller(saddr a0) { trade_message_controller = a0; return 1; }

s32 TLobby__sub_802D29E8(uaddr arg0) {
    if ((uaddr) trade_main_window != arg0) {
        return 0;
    }
    trade_main_window = 0U;
    return 1;
}

s32 claim_trade_main_window(uaddr arg0) {
    if ((uaddr) trade_main_window != 0U) {
        return 0;
    }
    trade_main_window = arg0;
    return 1;
}


s32 TLobby__sub_802D2A2C(uaddr arg0) {
    if ((uaddr) TLobby__data_805D6894 != arg0) {
        return 0;
    }
    TLobby__data_805D6894 = 0U;
    return 1;
}

s32 TLobby__sub_802D2A50(uaddr arg0) {
    if ((uaddr) TLobby__data_805D6894 != 0U) {
        return 0;
    }
    TLobby__data_805D6894 = arg0;
    return 1;
}
}
void TLobby::apply_trade_items() {
    s32 allowed;
    struct TradeItemEntry *list;
    u32 id;
    saddr player;
    struct TradeItemEntry *p;
    s32 i;
    s32 count;
    s32 flag;
    if ((s32) trade_proposal_state == 7) {
        player = (saddr)get_player_by_client_id(local_client_id);
        if (player != 0) {
            list = (struct TradeItemEntry *)get_trade_window_state();
            if (list != NULL) {
                allowed = check_player_action_allowed();
                p = list;
                flag = 0;
                for (i = 0; i < 0x1F; i++, p++) {
                    count = p->count;
                    id = p->id;
                    if (count > 0) {
                        if (id == 0xFFFFFF01) {
                            try_spend_actor_meseta(reinterpret_cast<TObjChara *>(player), count);
                        } else {
                            if ((allowed != 0) && (fn_801D4270(id) != 0)) {
                                remove_list_entry_by_id(id);
                                flag = 1;
                            }
                            TObjPlayer::send_6x29_delete_item((void *)player, (s32)id, (s32)count);
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

typedef struct E_802D2BC0 { u8 p[0x14]; } E_802D2BC0;

typedef struct S_802D2BC0 {
    u8 pad0[6];
    u16 count;
    E_802D2BC0 e[1];
} S_802D2BC0;

extern "C" {

void handle_trade_received_items(S_802D2BC0 *trade_list);

void TLobby::handle_reset_choice(s32 arg0) {
    if ((s8) trade_proposal_state != 0) {
        switch (arg0) {
        case 0:
            TWindowSubStatusDisp::get_message_10(0xEC);
            ((s32 (*)())reset__6TLobbyFi)();
            return;
        case 1:
            TWindowSubStatusDisp::get_message_10(0xEB);
            ((s32 (*)())reset__6TLobbyFi)();
            break;
        }
    }
}

void handle_trade_received_items(S_802D2BC0 *trade_list) {
    s32 i;
    E_802D2BC0 *p;
    if ((s32)trade_proposal_state == 8 && trade_list != 0) {
        p = trade_list->e;
        for (i = 0; i < trade_list->count; i++, p++) {
            buy_item_for_client((TItemData *)p, local_client_id);
        }
        trade_proposal_state = 9;
    }
}
}

void handle_6xA7(void) {  }


LAYOUT_ASSERT(RecoveredGlobal_802D2C38_lbl_804E1920_size, sizeof(trade_proposal_state_handlers) == 0x140);
void handle_6xA6_modify_trade_proposal(u8 *message_window) {
    s32 (*temp_r12)(void *);
    u16 temp_r3;
    u8 temp_r5;
    ((G_ModifyTradeProposal_6xA6 *)message_window)->bswap();
    temp_r3 = *(u16 *)((s8 *)message_window + 2);
    if ((temp_r3 < 4U) && (temp_r5 = *(u8 *)((s8 *)message_window + 4), ((temp_r5 < 8U) != 0))) {
        if ((trade_partner_client_id != 4) && ((s32) temp_r3 != trade_partner_client_id)) {
            if ((temp_r5 == 0) && ((u8) *(u8 *)((s8 *)message_window + 5) == 0)) {
                ((s32 (*)())send_trade_busy_reply)();
            }
        } else {
            temp_r12 = *(s32 (**)(void *))((s8 *)((u8 *)(((u8 *)&trade_proposal_state_handlers + ((s8) trade_proposal_state << 5))) + ((temp_r5 * 4) & 0x3FC)) + 0);
            if (temp_r12 != NULL) {
                temp_r12(message_window);
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
    if (((uaddr) TLobby__data_805D6894 == 0U) && ((uaddr) trade_main_window == 0U) && ((uaddr) trade_message_controller == 0U)) {
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
        TLobby::reset();
        break;
    case 7:
    case 8:
        protocol_instance->send_cancel_trade();
        break;
    case 9:
        break;
    }
}

struct VObj_802D2E28_0x30_802D2B64 {
    char pad[0x18];
    virtual void vm0();
    virtual void vm1();
    virtual void vm2();
    virtual void vm3();
    virtual void vm4();
    virtual void vm5();
    virtual void vm6();
    virtual void vm7();
    virtual void vm8();
    virtual void vm9();
    virtual void vma();
};

s32 format_trade_out_of_range_message(s32 client_id) {
    if ((s32) local_client_id == client_id) {
        return (saddr)TWindowSubStatusDisp::get_message_10(0xF0);
    }
    text_builder_reset();
    refresh_player_status(client_id);
    (saddr)TWindowSubStatusDisp::get_message_10(0xEF);
    text_builder_append();
    return get_shared_text_buffer();
}

s32 TLobby::show_event_message(s32 client_id, s32 arg1, s32 code) {
    void *item;

    switch (arg1) {
    case 0:
        return 0;
    case 1:
        if (client_id == (s32) local_client_id) {
            return (saddr)TWindowSubStatusDisp::get_message_10(0xF4);
        }
        text_builder_reset();
        refresh_player_status(client_id);
        (saddr)TWindowSubStatusDisp::get_message_10(0xEA);
        text_builder_append();
        return get_shared_text_buffer();
    case 2:
        item = find_item_by_id(code);
        if (item == NULL) {
            return 0;
        }
        text_builder_reset();
        if (client_id == (s32) local_client_id) {
            (saddr)TWindowSubStatusDisp::get_message_10(0xF3);
            text_builder_append();
        } else {
            refresh_player_status(client_id);
            (saddr)TWindowSubStatusDisp::get_message_10(0xE8);
            text_builder_append();
        }
        ((VObj_802D2E28_0x30_802D2B64 *)item)->vma();
        text_builder_append();
        (saddr)TWindowSubStatusDisp::get_message_10(0xE9);
        text_builder_append();
        return get_shared_text_buffer();
    case 3:
        if (client_id == (s32) local_client_id) {
            return (saddr)TWindowSubStatusDisp::get_message_10(0xF2);
        }
        text_builder_reset();
        refresh_player_status(client_id);
        (saddr)TWindowSubStatusDisp::get_message_10(0xE7);
        text_builder_append();
        return get_shared_text_buffer();
    case 4:
        return (saddr)TWindowSubStatusDisp::get_message_10(0xEE);
    default:
        return 0;
    }
}


void reset__6TLobbyFv(void) {
    if (is_trade_active() == 0) {
        trade_partner_client_id = 4;
        trade_proposal_state = 0;
        TLobby__data_805D688C = 0;
        trade_proposal_delay = 0;
        trade_protocol_flags &= 0xFFFFF80F;
        if (trade_message_controller != 0U) {
            ((TWindowSubTradeMessage *)trade_message_controller)->finish();
        }
        if (trade_main_window != 0U) {
            ((TWindowSubTradeMain *)trade_main_window)->finish();
        }
        if (TLobby__data_805D6894 != 0U) {
            reset__15TLobby_802D2F7CFPv((u8 *)TLobby__data_805D6894);
        }
    }
}

LAYOUT_ASSERT(TradeProposalSize, sizeof(G_ModifyTradeProposal_6xA6) == 0x10);
LAYOUT_ASSERT(TradeProposalAmountOffset, offsetof(G_ModifyTradeProposal_6xA6, amount) == 0xC);


struct Stack_802D3228
{
  s32 sp8;
  s8 spC;
  s8 spD;
  u8 pad_E[0x2];
  s32 sp10;
  s32 sp14;
};

struct O_802D33C0 { u8 pad[5]; u8 state; };

struct O_802D3384 { u8 pad[5]; u8 state; s16 h6; };

struct Item_802D3134 { u32 a; u32 b; u32 c; s32 d; u32 e; };


struct Trade_802D3134 { u8 pad[4]; s16 who; u16 count; Item_802D3134 items[1]; };

extern "C" {

void handle_trade_state_cancel__6TLobbyFPv(O_802D33C0 *self);

void handle_trade_member_out_of_range(O_802D3384 *self);

void reset__6TLobbyFi(saddr text_handle) {
    if (is_trade_active() == 0) {
        trade_proposal_state = 0;
        trade_partner_client_id = 4;
        TLobby__data_805D688C = 0;
        trade_proposal_delay = 0;
        trade_protocol_flags &= 0xFFFFF80F;
        TLobby__sub_8024AAA0(local_client_id, 0x1E);
        uaddr temp_r3 = trade_message_controller;
        if (temp_r3 != 0U) {
            ((TWindowSubTradeMessage *)temp_r3)->show_message((const char*)text_handle);
        }
    }
}
}

void cancel_trade_for_member_out_of_range(s32 client_id) {
    G_ModifyTradeProposal_6xA6 packet;
    s8 new_var;
    build_6xA6_modify_trade_proposal(&packet.header);
    new_var = (s8) ((u8)trade_partner_client_id & 0xFFFFFFFFFFFFFFFFu);
    packet.what = 7;
    packet.result = 0;
    packet.unknown_a1 = client_id;
    packet.prepare_and_send(new_var);
    if ((s8)trade_proposal_state == 2) {
        TWindowTradeRequest::close_request_window();
        ((s32 (*)())reset__6TLobbyFv)();
        return;
    }
    TLobby::reset(format_trade_out_of_range_message(client_id));
}

void send_trade_busy_reply(saddr client_id) {
    G_ModifyTradeProposal_6xA6 packet;
    build_6xA6_modify_trade_proposal((&packet.header));
    packet.what = 6;
    packet.result = 0;
    packet.prepare_and_send(client_id);
}

void TLobby::build_trade_item_list() {
    Item_802D3134 item;
    TradeItemEntry *list;
    s32 c;
    s8 cc = trade_partner_client_id;
    ((Trade_802D3134 *)this)->who = cc;
    ((Trade_802D3134 *)this)->count = 0;
    list = (TradeItemEntry *)get_trade_window_state();
    if (list != NULL) {
        u32 i;
        s32 n;
        TradeItemEntry *e;
        u32 id;
        void *p;
        e = list;
        for (i = 0; i < 31; i++, e++) {
            n = e->count;
            id = e->id;
            if (n > 0) {
                if (id == 0xFFFFFF01) {
                    ((TObjPlayer *)(&item))->init_item_data(n);
                    ((TItemData *)(&((Trade_802D3134 *)this)->items[((Trade_802D3134 *)this)->count++]))->copy_from((TItemData *)(&item));
                } else if ((p = find_item_by_id(id)) != NULL) {
                    ((TItem *)p)->copy_to_item_data((TItemData *)&item);
                    item.d = -1;
                    ((TItemData *)&item)->set_stack_count(n);
                    ((TItemData *)(&((Trade_802D3134 *)this)->items[((Trade_802D3134 *)this)->count++]))->copy_from((TItemData *)(&item));
                }
            }
        }
    }
}

void TLobby::send_modify_trade_proposal(s8 arg0, s32 arg1, s32 arg2) {
  Stack_802D3228 stack;
  build_6xA6_modify_trade_proposal(&stack.sp8);
  stack.spC = arg0;
  stack.spD = 0;
  stack.sp10 = arg1;
  stack.sp14 = arg2;
  if (((!(u8)trade_partner_client_id) && (!(u8)trade_partner_client_id)) && (!(u8)trade_partner_client_id))
  {
  }
  ((G_ModifyTradeProposal_6xA6 *)&stack.sp8)->prepare_and_send(trade_partner_client_id);
}

void TLobby::send_trade_proposal_result(s8 arg0, s8 arg1) {
  G_ModifyTradeProposal_6xA6 packet;
  s8 new_var;
  arg1++;
  arg1--;
  build_6xA6_modify_trade_proposal(&packet.header);
  new_var = (s8) ((u8)trade_partner_client_id & 0xFFFFFFFFFFFFFFFFu);
  packet.what = arg0;
  packet.result = arg1;
  packet.prepare_and_send(new_var);
}

void send_6xA6_modify_trade_proposal(saddr client_id) {
    G_ModifyTradeProposal_6xA6 packet;
    TObjPlayer *player;
    player_stats *temp_r3_2;
    build_6xA6_modify_trade_proposal((&packet.header));
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (temp_r3_2 = player->get_stats(), ((temp_r3_2 == NULL) == 0))) {
        if ((s32) (u8)trade_partner_client_id != 4) {
            TWindowTradeRequest::close_request_window();
            if (trade_partner_client_id == client_id) {
                TLobby::send_trade_proposal_modify();
                TLobby__sub_8024AAA0(local_client_id, 0x1D);
                return;
            }
            send_trade_busy_reply((s32)trade_partner_client_id);
            goto block_6;
        }
block_6:
        packet.what = 0;
        packet.result = 0;
        packet.amount = temp_r3_2->meseta;
        packet.prepare_and_send(client_id);
        trade_partner_client_id = (s8) client_id;
        trade_proposal_state = 1;
    }
}

void ignore_trade_proposal_event(void) {  }

void handle_trade_member_out_of_range(O_802D3384 *self) {
    switch (self->state) {
    case 0:
        TLobby::reset(format_trade_out_of_range_message(self->h6));
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_state_cancel__6TLobbyFPv(O_802D33C0 *self) {
    switch (self->state) {
    case 3:
        break;
    case 4:
        TLobby::protocol_instance->send_cancel_trade();
        break;
    }
}
void handle_trade_partner_cancel(void *arg0) {
    switch (*(u8 *)((s8 *)arg0 + 5)) {
    case 4:
        text_builder_reset();
        refresh_player_status(trade_partner_client_id);
        TWindowSubStatusDisp::get_message_10(0xED);
        text_builder_append();
        TLobby::reset(get_shared_text_buffer());
        break;
    case 3:
        break;
    }
}

struct O_802D361C { u8 pad[5]; u8 state; };

struct O_802D3654 { u8 pad[5]; u8 state; };

typedef struct S_802D35B0 {
    u8 pad0[2];
    u16 f2;
    u8 pad4;
    u8 f5;
    u8 pad6[2];
    s32 f8;
    s32 fC;
} S_802D35B0;

typedef struct S_802D3544 {
    u8 pad0[2];
    u16 f2;
    u8 pad4;
    u8 f5;
    u8 pad6[2];
    s32 f8;
    s32 fC;
} S_802D3544;

struct O_802D368C { u8 pad[5]; u8 state; };

struct O_802D377C { u8 pad0[2]; u16 f2; u8 pad4; u8 state; u8 pad6[6]; s32 fC; };

extern "C" {

void handle_trade_request_state_a__6TLobbyFPv(O_802D361C *self);
void handle_trade_request_state_b__6TLobbyFPv(O_802D3654 *self);
void move_trade_item_amount__6TLobbyFUll(void *, s32, s32, void *);

void handle_trade_item_move__6TLobbyFPv(S_802D35B0 *arg0);
void transfer_trade_item_amount__6TLobbyFUll(void *, s32, s32, void *);

void handle_trade_item_amount__6TLobbyFPv(S_802D3544 *arg0);

void update_status_message__6TLobbyFPv(O_802D368C *self);

void handle_state_init__6TLobbyFPv(O_802D377C *self);
}

void handle_trade_final_confirmation(void *arg0) {

    switch ((s32) (*(u8 *)((s8 *)arg0 + 5))) {
    case 0:
        trade_protocol_flags |= 0x200;
        if (trade_main_window != 0U) {
            ((TWindowSubTradeMain *)trade_main_window)->notify_child_if_present(2);
        }
        break;
    case 4:
        trade_protocol_flags &= 0xFFFFFDFF;
        if (trade_main_window != 0U) {
            ((TWindowSubTradeMain *)trade_main_window)->notify_child_if_present(1);
        }
        break;
    }
}

void handle_trade_offer_confirmation(void *arg0) {

    switch ((s32) (*(u8 *)((s8 *)arg0 + 5))) {
    case 0:
        trade_protocol_flags |= 0x40;
        if (trade_main_window != 0U) {
            ((TWindowSubTradeMain *)trade_main_window)->notify_child_if_present(1);
        }
        break;
    case 4:
        trade_protocol_flags &= 0xFFFFFFBF;
        if (trade_main_window != 0U) {
            ((TWindowSubTradeMain *)trade_main_window)->notify_child_if_present(0);
        }
        break;
    }
}

void handle_trade_item_amount__6TLobbyFPv(S_802D3544 *arg0) {
    s32 t = arg0->f5;
    switch (t) {
    case 0:
        if (arg0->f2 == trade_partner_client_id) {
            transfer_trade_item_amount__6TLobbyFUll(&trade_window_state[1], arg0->f8, arg0->fC, trade_window_state);
            if (trade_main_window != 0) {
                ((TWindowSubTradeMain *)trade_main_window)->update_trade_window();
            }
        }
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_item_move__6TLobbyFPv(S_802D35B0 *arg0) {
    s32 t = arg0->f5;
    switch (t) {
    case 0:
        if (arg0->f2 == trade_partner_client_id) {
            move_trade_item_amount__6TLobbyFUll(&trade_window_state[1], arg0->f8, arg0->fC, trade_window_state);
            if (trade_main_window != 0) {
                ((TWindowSubTradeMain *)trade_main_window)->update_trade_window();
            }
        }
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_request_state_a__6TLobbyFPv(O_802D361C *self) {
    switch (self->state) {
    case 0:
        TWindowTradeRequest::close_request_window();
        TLobby::reset();
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_request_state_b__6TLobbyFPv(O_802D3654 *self) {
    switch (self->state) {
    case 3:
        break;
    case 4:
        TWindowTradeRequest::close_request_window();
        TLobby::reset();
        break;
    }
}

void update_status_message__6TLobbyFPv(O_802D368C *self) {
    switch (self->state) {
    case 0:
        text_builder_reset();
        refresh_player_status(trade_partner_client_id);
        TWindowSubStatusDisp::get_message_10(0xF1);
        text_builder_append();
        ((s32 (*)())get_shared_text_buffer)();
        ((s32 (*)())reset__6TLobbyFi)();
        break;
    case 1:
    case 2:
        break;
    }
}

void handle_trade_request_reply(void *arg0) {
    switch ((s32) (*(u8 *)((s8 *)arg0 + 5))) {
    case 2:
        TLobby__data_805D688C = *(s32 *)((s8 *)arg0 + 0xC);
        TLobby__sub_8024AAA0(local_client_id, 0x1D);
        trade_proposal_state = 3;
        return;
    case 3:
        text_builder_reset();
        refresh_player_status(trade_partner_client_id);
        TWindowSubStatusDisp::get_message_10(0xD8);
        text_builder_append();
        ((s32 (*)())get_shared_text_buffer)();
        ((s32 (*)())reset__6TLobbyFi)();
        return;
    case 0:
        ((s32 (*)(int))send_trade_busy_reply)(trade_partner_client_id);
    case 4:
        return;
    }
}

void handle_state_init__6TLobbyFPv(O_802D377C *self) {
    switch (self->state) {
    case 0:
        trade_partner_client_id = self->f2;
        TLobby__data_805D688C = self->fC;
        TLobby__sub_802D3AA8();
        trade_proposal_state = 2;
        break;
    case 1:
    case 2:
        break;
    }
}


extern "C" {

s32 is_trade_range_bit_set(s32);

void TLobby::update_battle_mode() {
    if ((s8) trade_proposal_state != 0) {
        if (get_player_by_client_id(local_client_id) == NULL) {
            TLobby::cancel_trade();
            return;
        }
        if (is_trade_range_bit_set(local_client_id) == 0) {
            ((s32 (*)(s32))cancel_trade_for_member_out_of_range)(local_client_id);
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
        ((s32 (*)(s32))cancel_trade_for_member_out_of_range)(trade_partner_client_id);
    }
}

void TLobby::close_trade_request() { trade_protocol_flags = 0; TWindowTradeRequest::close_request_window(); }
void TLobby::reset_trade_state() {
    s32 i;
    trade_partner_client_id = 4;
    trade_proposal_state = 0;
    TLobby__data_805D688C = 0;
    trade_proposal_delay = 0;
    TLobby__data_805D6894 = 0;
    trade_main_window = 0;
    trade_message_controller = 0;
    for (i = 0; i < 2; i++) {
        ((TLobby *)(&trade_window_state[i]))->update_both_halves();
    }
    TLobby::close_trade_request();
}

}

TradeProposalHandler trade_proposal_state_handlers[10][8] = {
    { (TradeProposalHandler)handle_state_init__6TLobbyFPv, 0, 0, 0, 0, 0, 0, 0 },
    { (TradeProposalHandler)handle_trade_request_reply, 0, 0, 0, 0, 0, (TradeProposalHandler)update_status_message__6TLobbyFPv, (TradeProposalHandler)handle_trade_member_out_of_range },
    { 0, 0, 0, 0, 0, (TradeProposalHandler)handle_trade_request_state_b__6TLobbyFPv, 0, (TradeProposalHandler)handle_trade_request_state_a__6TLobbyFPv },
    { (TradeProposalHandler)ignore_trade_proposal_event, (TradeProposalHandler)handle_trade_item_move__6TLobbyFPv, (TradeProposalHandler)handle_trade_item_amount__6TLobbyFPv, (TradeProposalHandler)handle_trade_offer_confirmation, (TradeProposalHandler)handle_trade_final_confirmation, (TradeProposalHandler)handle_trade_partner_cancel, 0, (TradeProposalHandler)handle_trade_member_out_of_range },
    { (TradeProposalHandler)ignore_trade_proposal_event, (TradeProposalHandler)handle_trade_item_move__6TLobbyFPv, (TradeProposalHandler)handle_trade_item_amount__6TLobbyFPv, (TradeProposalHandler)handle_trade_offer_confirmation, (TradeProposalHandler)handle_trade_final_confirmation, (TradeProposalHandler)handle_trade_partner_cancel, 0, (TradeProposalHandler)handle_trade_member_out_of_range },
    { (TradeProposalHandler)ignore_trade_proposal_event, (TradeProposalHandler)ignore_trade_proposal_event, (TradeProposalHandler)ignore_trade_proposal_event, (TradeProposalHandler)handle_trade_offer_confirmation, (TradeProposalHandler)handle_trade_final_confirmation, (TradeProposalHandler)handle_trade_partner_cancel, 0, (TradeProposalHandler)ignore_trade_proposal_event },
    { (TradeProposalHandler)ignore_trade_proposal_event, 0, 0, 0, (TradeProposalHandler)handle_trade_final_confirmation, (TradeProposalHandler)handle_trade_partner_cancel, 0, (TradeProposalHandler)ignore_trade_proposal_event },
    { (TradeProposalHandler)ignore_trade_proposal_event, 0, 0, 0, (TradeProposalHandler)handle_trade_final_confirmation, (TradeProposalHandler)handle_trade_state_cancel__6TLobbyFPv, 0, (TradeProposalHandler)ignore_trade_proposal_event },
    { (TradeProposalHandler)ignore_trade_proposal_event, 0, 0, 0, (TradeProposalHandler)handle_trade_final_confirmation, (TradeProposalHandler)handle_trade_state_cancel__6TLobbyFPv, 0, (TradeProposalHandler)ignore_trade_proposal_event },
    { (TradeProposalHandler)ignore_trade_proposal_event, 0, 0, 0, 0, (TradeProposalHandler)handle_trade_state_cancel__6TLobbyFPv, 0, (TradeProposalHandler)ignore_trade_proposal_event },
};
