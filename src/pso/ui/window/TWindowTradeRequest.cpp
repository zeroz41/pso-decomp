#include "types.h"
#include "pso/player/PlayerCommands.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"

const char *TWindowTradeRequest::class_name = "TWindowTradeRequest";
void TWindowTradeRequest::render() {  }


void TWindowTradeRequest::run_task() {
    s32 slot;
    switch (state) {
    case 0:
    case 1:
        if (dialog->is_cancelled() != 0) {
            TWindowTradeRequest::reset_trade();
            TWindowTradeRequest::close_request_window();
            state = 3;
            break;
        }
        if (dialog->is_child_visible() != 0) {
            slot = dialog->get_selected_value();
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
    TWindowCtrl::show_client_lock_on_window((local_client_id));
    TWindowCtrl::enable_client_main_menu(local_client_id);
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->init_parts();
    }
    if (state == 2U) {
        TWindowCtrl::try_open_battle_menu(local_client_id, 0x1D);
    }
}
#pragma fp_contract on
TWindowTradeRequest::TWindowTradeRequest(TObject *parent) : TObject(parent) {
    m_name = TWindowTradeRequest::class_name;
    TObjPlayer *player = get_player_by_client_id(static_cast<s8>(TLobby::get_trade_mode()));
    text_builder_reset();
    if (player != NULL) {
        text_builder_append(player->get_name());
    }
    text_builder_append(TWindowSubStatusDisp::get_message_10(0xD9));
    dialog = TWindowMessageYesNo::create(this, local_client_id, NULL, NULL);
    const NJS_POINT2 *position = get_window_layout_position(0xB2);
    dialog->open_yes_no_prompt_with_text(get_shared_text_buffer(),position, 260.0f);
    dialog->set_choice_menu_flag70_bit10();
    TObjPlayer *local = get_player_by_client_id(local_client_id);
    if (local != NULL) {
        local->reset_equip_slots();
    }
    TWindowCtrl::disable_client_main_menu(local_client_id);
    TWindowCtrl::hide_client_lock_on_window(local_client_id);
    state = 0;
}
