#include "types.h"
#include "pso/network/TradeSession.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowTradeRequest.h"

extern u8 TLobby__trade_proposal_state;

void TWindowTradeRequest::reset_trade() {
    if ((s32) TLobby__trade_proposal_state == 2) {
        TLobby::send_trade_proposal_result(0, 3);
        TWindowTradeRequest::close_request_window();
        reset__6TLobbyFv();
    }
}
