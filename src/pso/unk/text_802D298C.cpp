#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/network/TProtocol.h"

struct RecoveredGlobal_802D298C_TLobby__data_80540BD0 {
    s32 value;
    u8 remaining[0x3DC];
};

struct RecoveredGlobal_802D299C_TLobby__data_80540BD0 {
    s32 value;
    u8 remaining[0x3DC];
};

struct RecoveredGlobal_802D29AC_TLobby__data_80540BD0 {
    s32 value;
    u8 remaining[0x3DC];
};

struct E_802D2A70 { u32 id; s32 count; };

extern "C" {
RecoveredGlobal_802D298C_TLobby__data_80540BD0 TLobby__trade_window_state;
u8 *TLobby__sub_802D298C(void);
u8 *TLobby__sub_802D299C(void);
s32 *get_trade_window_state(void);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
void *get_player_by_client_id(s32 i);
s32 check_player_action_allowed();
void remove_list_entry_by_id(s32 arg0);
s32 fn_801D4270(s32);
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFv();
extern s32 local_client_id;
extern s32 TLobby__protocol_instance;
extern u8 TLobby__trade_proposal_state;
extern u32 trade_message_controller;

typedef char RecoveredGlobal_802D298C_TLobby__data_80540BD0_size[sizeof(RecoveredGlobal_802D298C_TLobby__data_80540BD0) == 0x3E0 ? 1 : -1];
u8 *TLobby__sub_802D298C(void) {
    return (u8 *)&TLobby__trade_window_state.value + 0xF8;
}

typedef char RecoveredGlobal_802D299C_TLobby__data_80540BD0_size[sizeof(RecoveredGlobal_802D299C_TLobby__data_80540BD0) == 0x3E0 ? 1 : -1];
u8 *TLobby__sub_802D299C(void) {
    return (u8 *)&(*(RecoveredGlobal_802D299C_TLobby__data_80540BD0 *)&TLobby__trade_window_state).value + 0x1F0;
}

typedef char RecoveredGlobal_802D29AC_TLobby__data_80540BD0_size[sizeof(RecoveredGlobal_802D29AC_TLobby__data_80540BD0) == 0x3E0 ? 1 : -1];
s32 *get_trade_window_state(void) {
    return &(*(RecoveredGlobal_802D29AC_TLobby__data_80540BD0 *)&TLobby__trade_window_state).value;
}

s32 TLobby__sub_802D29B8(u32 arg0) {
    if ((u32) trade_message_controller != arg0) {
        return 0;
    }
    trade_message_controller = 0U;
    return 1;
}

int TLobby__sub_802D29DC(int a0) { trade_message_controller = a0; return 1; }

extern u32 TLobby__trade_main_window;

s32 TLobby__sub_802D29E8(u32 arg0) {
    if ((u32) TLobby__trade_main_window != arg0) {
        return 0;
    }
    TLobby__trade_main_window = 0U;
    return 1;
}

s32 TLobby__sub_802D2A0C(u32 arg0) {
    if ((u32) TLobby__trade_main_window != 0U) {
        return 0;
    }
    TLobby__trade_main_window = arg0;
    return 1;
}

extern u32 TLobby__data_805D6894;

s32 TLobby__sub_802D2A2C(u32 arg0) {
    if ((u32) TLobby__data_805D6894 != arg0) {
        return 0;
    }
    TLobby__data_805D6894 = 0U;
    return 1;
}

s32 TLobby__sub_802D2A50(u32 arg0) {
    if ((u32) TLobby__data_805D6894 != 0U) {
        return 0;
    }
    TLobby__data_805D6894 = arg0;
    return 1;
}
void TLobby::apply_trade_items() {
    s32 allowed;
    struct E_802D2A70 *list;
    u32 id;
    s32 player;
    struct E_802D2A70 *p;
    s32 i;
    s32 count;
    s32 flag;
    if ((s32) TLobby__trade_proposal_state == 7) {
        player = (s32)get_player_by_client_id(local_client_id);
        if (player != 0) {
            list = (struct E_802D2A70 *)((s32 *)get_trade_window_state());
            if (list != NULL) {
                allowed = check_player_action_allowed();
                p = list;
                flag = 0;
                for (i = 0; i < 0x1F; i++, p++) {
                    count = p->count;
                    id = p->id;
                    if (count > 0) {
                        if (id == 0xFFFFFF01) {
                            try_spend_actor_meseta((u8 *)player, count);
                        } else {
                            if ((allowed != 0) && (fn_801D4270(id) != 0)) {
                                remove_list_entry_by_id(id);
                                flag = 1;
                            }
                            send_6x29_delete_item__10TObjPlayerFPvii((void *)player, (s32)id, (s32)count);
                        }
                    }
                }
                if ((flag == 0) || (load_character_from_card__23TAdSinglePlyChrSelectGCFv() == 0)) {
                    TLobby__trade_proposal_state = 8;
                    ((TProtocol *)TLobby__protocol_instance)->send_trade_ready();
                }
            }
        }
    }
}

}
