#include "types.h"
#include "pso/unk/TLobby.h"

    extern unsigned char trade_partner_client_id;
unsigned char TLobby::get_trade_mode() {  return trade_partner_client_id; }
