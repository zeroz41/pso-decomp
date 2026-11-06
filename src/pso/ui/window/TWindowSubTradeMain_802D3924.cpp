#include "types.h"
#include "pso/ui/window/TWindowSubTradeMain_802D3924.h"

extern u16 trade_protocol_flags;

bool is_trade_range_bit_set(s32 arg0) {
    return (trade_protocol_flags & (1 << arg0)) != 0;
}

void clear_trade_range_bit(s32 arg0) {
    trade_protocol_flags &= ~(1 << arg0);
}

void set_trade_range_bit(s32 arg0) {
    trade_protocol_flags |= 1 << arg0;
}
