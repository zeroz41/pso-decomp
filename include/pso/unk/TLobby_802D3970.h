#ifndef PSO_UNK_TLOBBY_802D3970_H
#define PSO_UNK_TLOBBY_802D3970_H

#include "types.h"

// Floor and scene resource callbacks (FloorResourceCallbacks load/unload slots).
void close_trade_request_on_floor_unload();
void close_trade_request_on_floor_load();
void reset_trade_state_on_scene_unload();
void reset_trade_state_on_scene_load();
void set_trade_active(void);
void build_6xA6_modify_trade_proposal(void *p);


#endif
