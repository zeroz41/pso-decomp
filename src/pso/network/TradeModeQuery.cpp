#include "types.h"
#include "pso/network/TradeModeQuery.h"
#include "pso/network/TLobby.h"
#include "pso/network/TradeSession.h"

unsigned char get_trade_mode() {  return trade_partner_client_id; }
