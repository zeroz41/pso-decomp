#ifndef PSO_NETWORK_TRADEPROPOSALCMD_H
#define PSO_NETWORK_TRADEPROPOSALCMD_H

#include "types.h"

// Floor and scene resource callbacks (FloorResourceCallbacks load/unload slots).
void close_trade_request_on_floor_unload();
void close_trade_request_on_floor_load();
void reset_trade_state_on_scene_unload();
void reset_trade_state_on_scene_load();
void TLobby__sub_802D3AA8(void);
void build_6xA6_modify_trade_proposal(void *p);


#endif
