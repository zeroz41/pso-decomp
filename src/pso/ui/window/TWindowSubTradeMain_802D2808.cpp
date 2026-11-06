#include "types.h"
#include "pso/unk/TLobby_802D1EFC.h"
#include "pso/ui/window/TWindowSubTradeMain_802D2808.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_802D2870_TLobby__data_80540BD0
{
  s32 value;
  u8 remaining[0x3DC];
};

extern s32 TLobby__trade_window_state[];
extern s32 local_client_id;
extern u8 TLobby__trade_partner_client_id;
extern s32 TLobby__data_805D688C;
extern u16 trade_protocol_flags;

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

extern void *TLobby__trade_main_window;

typedef struct RecoveredGlobal_802D2870_TLobby__data_80540BD0 RecoveredGlobal_802D2870_TLobby__data_80540BD0;
typedef char RecoveredGlobal_802D2870_TLobby__data_80540BD0_size[((sizeof(RecoveredGlobal_802D2870_TLobby__data_80540BD0)) == 0x3E0) ? (1) : (-1)];

void TWindowSubTradeMain__sub_802D2870(void) {
  s32 *temp_r31;
  snapshot_player_trade_inventory((s32)(&(*(RecoveredGlobal_802D2870_TLobby__data_80540BD0 *)&TLobby__trade_window_state).value), local_client_id);
  temp_r31 = (s32 *) ((u8 *) ((s32 *) (((u8 *) (&(*(RecoveredGlobal_802D2870_TLobby__data_80540BD0 *)&TLobby__trade_window_state).value)) + 0x1F0)));
  snapshot_player_trade_inventory((s32)temp_r31, ((s32) ((s8) (TLobby__trade_partner_client_id & 0xFFFFFFFFFFFFFFFFu))));
  ((TLobby *)temp_r31)->set_trade_field_4(TLobby__data_805D688C);
}

void TWindowSubTradeMain::draw_offer(void *arg0, void *arg1) {
    TLobby::send_modify_trade_proposal((s8)2, (s32)arg0, (s32)arg1);
    ((TLobby *)TLobby__trade_window_state)->transfer_trade_item_amount((u32)arg0, (s32)arg1);
    if (TLobby__trade_main_window != NULL) {
        ((TWindowSubTradeMain *)TLobby__trade_main_window)->draw_item_slot();
    }
}

void TWindowSubTradeMain::draw_request(void *arg0, void *arg1) {
    TLobby::send_modify_trade_proposal((s8)1, (s32)arg0, (s32)arg1);
    ((TLobby *)TLobby__trade_window_state)->move_trade_item_amount((u32)arg0, (s32)arg1);
    if (TLobby__trade_main_window != NULL) {
        ((TWindowSubTradeMain *)TLobby__trade_main_window)->draw_item_slot();
    }
}
