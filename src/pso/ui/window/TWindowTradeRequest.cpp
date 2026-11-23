#include "types.h"
#include "pso/network/TradeSession.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowTradeRequest.h"


void TWindowTradeRequest::reset_trade() {
    if ((s32) trade_proposal_state == 2) {
        TLobby::send_trade_proposal_result(0, 3);
        TWindowTradeRequest::close_request_window();
        reset__6TLobbyFv();
    }
}
