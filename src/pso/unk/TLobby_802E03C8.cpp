#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TradeSession.h"

unsigned char TLobby::get_trade_mode() {  return trade_partner_client_id; }
