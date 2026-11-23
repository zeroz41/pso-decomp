#include "types.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8024AADC.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
extern s32 local_client_id;
u8 *get_window_layout_position(s32);
}
void text_builder_reset(void);
extern "C" {
const char *TWindowTradeRequest__name = "TWindowTradeRequest";
void TWindowTradeRequest::render() {  }


void TWindowTradeRequest::run_task() {
    s32 slot;
    switch (state) {
    case 0:
    case 1:
        if (((TWindowMessageYesNo *)(dialog))->is_cancelled() != 0) {
            TWindowTradeRequest::reset_trade();
            TWindowTradeRequest::close_request_window();
            state = 3;
            break;
        }
        if (dialog->is_child_visible() != 0) {
            slot = ((TWindowMessageYesNo *)(dialog))->get_selected_value();
            if (slot == 0) {
                TLobby::send_trade_proposal_modify();
                TWindowTradeRequest::close_request_window();
                state = 2;
            }
            if (slot == 1) {
                TWindowTradeRequest::reset_trade();
                TWindowTradeRequest::close_request_window();
                state = 3;
            }
        }
        break;
    case 2:
    case 3:
    default:
        break;
    }
}
TWindowTradeRequest::~TWindowTradeRequest() {
    if (dialog != NULL) {
        reinterpret_cast<TWindowMessageYesNo *>(dialog)->close();
        dialog = NULL;
    }
    TWindowReturnCity__sub_8024ACA8((local_client_id));
    TWindowCtrl::enable_client_main_menu(local_client_id);
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->init_parts();
    }
    if (state == 2U) {
        fn_8024AADC((local_client_id), 0x1D);
    }
}
#pragma fp_contract on
TWindowTradeRequest::TWindowTradeRequest(TObject *parent) : TObject(parent) {
    m_name = TWindowTradeRequest__name;
    TObjPlayer *player = get_player_by_client_id(static_cast<s8>(TLobby::get_trade_mode()));
    text_builder_reset();
    if (player != NULL) {
        text_builder_append((u8 *)player->get_name());
    }
    text_builder_append((u8 *)TWindowSubStatusDisp::get_message_10(0xD9));
    dialog = TWindowMessageYesNo::create(this, local_client_id, NULL, NULL);
    u8 *position = get_window_layout_position(0xB2);
    dialog->open_yes_no_prompt_with_text(reinterpret_cast<saddr>(get_shared_text_buffer()),
        reinterpret_cast<saddr>(position), 260.0f);
    dialog->set_choice_menu_flag70_bit10();
    TObjPlayer *local = get_player_by_client_id(local_client_id);
    if (local != NULL) {
        local->reset_equip_slots();
    }
    TWindowCtrl::disable_client_main_menu(local_client_id);
    fn_8024AC64(local_client_id);
    state = 0;
}
}
