#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestListVM.h"
#include "pso/misc/TWindowSubStatusDisp.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
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
u8 * copy_struct_f8__6TLobbyFii(s32 arg0, s32 arg1);
s32 *get_shared_text_buffer(void);
s32 refresh_player_status__6TLobbyFv(int);
s32 text_builder_append();
void TLobby__sub_802D268C(void);
void *get_player_by_client_id(s32 i);
}
void text_builder_reset(void);
extern s8 TLobby__trade_partner_client_id;
void build_6xA6_modify_trade_proposal(void *);
extern u32 local_client_id;
extern u8 TLobby__trade_proposal_state;
extern "C" {
s32 send_trade_list__6TLobbyFPvPv(s32, s32 *);
void TWindowSubTradeMain__sub_80330A84(void *p);
extern s32 TLobby__protocol_instance;
extern u16 trade_protocol_flags;
extern u32 TLobby__trade_main_window;
extern s32 trade_proposal_delay;
s32 check_trade_offer_inventory(void *, void *);
extern Half_802D26C8 TLobby__trade_window_state[4];

typedef struct Stack_802D23E0 Stack_802D23E0;
void TLobby::send_trade_proposal_modify() {
  Stack_802D23E0 stack;
  u8 *player;
  u8 *temp_r3_2;
  build_6xA6_modify_trade_proposal(&stack.sp8);
  if (((s32) TLobby__trade_proposal_state) == 2)
  {
    player = (u8 *) get_player_by_client_id(local_client_id);
    if (player)
    {
      temp_r3_2 = ((TObjPlayer *)player)->get_stats();
      if (temp_r3_2 != 0)
      {
        stack.spC = 0;
        stack.spD = 2;
        stack.sp14 = *((s32 *) (((s8 *) temp_r3_2) - -0x20));
        if (((*(u8 *)&TLobby__trade_partner_client_id) && (*(u8 *)&TLobby__trade_partner_client_id)) && (*(u8 *)&TLobby__trade_partner_client_id))
        {
        }
        ((TLobby *)(&stack.sp8))->prepare_and_send_trade_packet((void*)((s8) (*(u8 *)&TLobby__trade_partner_client_id)));
        TLobby__trade_proposal_state = 3;
      }
    }
  }
}

void TLobby::update_trade_list_send() {
    u8 sp8[0x288];
    switch ((s8) TLobby__trade_proposal_state) {
    case 5:
        if ((trade_protocol_flags & 0x100) && (trade_protocol_flags & 0x200)) {
            TLobby__trade_proposal_state = 6;
        }
        break;
    case 6:
        ((TLobby *)sp8)->build_trade_item_list();
        send_trade_list__6TLobbyFPvPv(TLobby__protocol_instance, (s32 *)sp8);
        trade_protocol_flags |= 0x400;
        if ((u32) TLobby__trade_main_window != 0U) {
            TWindowSubTradeMain__sub_80330A84((void *)TLobby__trade_main_window);
        }
        TLobby__trade_proposal_state = 7;
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
            if ((u32) TLobby__trade_main_window != 0U) {
                ((TWindowSubTradeMain *)TLobby__trade_main_window)->forward_to_child(0);
            }
            TLobby__trade_proposal_state = 3;
        }
    } else if (!(trade_protocol_flags & 0x20)) {
        if (trade_proposal_delay++ >= 0x1E) {
            TLobby::send_trade_proposal_result(3, 0);
            trade_protocol_flags |= 0x20;
            if ((u32) TLobby__trade_main_window != 0U) {
                ((TWindowSubTradeMain *)TLobby__trade_main_window)->forward_to_child(1);
            }
            trade_proposal_delay = 0;
            TLobby__trade_proposal_state = 4;
        }
    } else if (!(trade_protocol_flags & 0x80)) {
        trade_proposal_delay = 0;
        if (trade_protocol_flags & 0x100) {
            TLobby::send_trade_proposal_result(4, 4);
            if ((u32) TLobby__trade_main_window != 0U) {
                ((TWindowSubTradeMain *)TLobby__trade_main_window)->forward_to_child(1);
            }
            trade_protocol_flags &= 0xFFFFFEFF;
            TLobby__trade_proposal_state = 4;
        }
    } else if (!(trade_protocol_flags & 0x100)) {
        if (trade_proposal_delay++ >= 0x1E) {
            TLobby::send_trade_proposal_result(4, 0);
            trade_protocol_flags |= 0x100;
            if ((u32) TLobby__trade_main_window != 0U) {
                ((TWindowSubTradeMain *)TLobby__trade_main_window)->forward_to_child(2);
            }
            trade_proposal_delay = 0;
            TLobby__trade_proposal_state = 5;
        }
    }
}

#pragma push
#pragma scheduling off
void TLobby__sub_802D268C(void) {
    text_builder_reset();
    refresh_player_status__6TLobbyFv(TLobby__trade_partner_client_id);
    TWindowSubStatusDisp::get_message_10(0xF6);
    text_builder_append();
    get_shared_text_buffer();
}
#pragma pop

s32 TLobby::check_trade_items_and_show_error() {
    s32 code;
    Pair_802D26C8 buf;
    s32 r;
    s32 flag = 0;
    ((TLobby *)(&buf))->update_both_halves();
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[0], &TLobby__trade_window_state[2]);
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[1], &TLobby__trade_window_state[1]);
    r = check_trade_offer_inventory(&buf, &code);
    if (r == 4) {
        flag = 1;
    } else if (r != 0) {
        return TLobby::show_event_message((s32)((void *)local_client_id), (s32)r, (s32)code);
    }
    ((TLobby *)(&buf))->update_both_halves();
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[0], &TLobby__trade_window_state[0]);
    ((u8 *(*)(void *, void *))copy_struct_f8__6TLobbyFii)(&buf.h[1], &TLobby__trade_window_state[3]);
    r = check_trade_offer_inventory(&buf, &code);
    if (r == 4) {
        if (flag) {
            return TLobby::show_event_message((s32)((void *)(s32)TLobby__trade_partner_client_id), 4, (s32)code);
        }
    } else if (r != 0) {
        return TLobby::show_event_message((s32)((void *)(s32)TLobby__trade_partner_client_id), (s32)r, (s32)code);
    }
    return 0;
}

u8 * copy_struct_f8__6TLobbyFii(s32 arg0, s32 arg1) {
    *(ByteBlock_F8 *)(arg0) = *(const ByteBlock_F8 *)(arg1);
    return (u8 *)arg0;
}
}
