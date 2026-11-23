#ifndef PSO_UI_WINDOW_TWINDOWSUBTRADEMAIN_802D3924_H
#define PSO_UI_WINDOW_TWINDOWSUBTRADEMAIN_802D3924_H

#include "types.h"

void clear_trade_range_bit(s32 arg0);
extern "C" {
bool is_trade_range_bit_set(s32 local_client_id);
}
void set_trade_range_bit(s32 trade_range_bit);

// --- C functions defined in TWindowSubTradeMain_802D3924.cpp ---
extern "C" {
bool is_trade_range_bit_set(s32 local_client_id);
}
// --- end of C functions

#endif
