#include "types.h"
#include "pso/ui/window/TWindowSubTradeMain_802D3924.h"

extern u16 trade_protocol_flags;

bool is_trade_range_bit_set(s32 local_client_id) {
    return (trade_protocol_flags & (1 << local_client_id)) != 0;
}

void clear_trade_range_bit(s32 arg0) {
    trade_protocol_flags &= ~(1 << arg0);
}

void set_trade_range_bit(s32 trade_range_bit) {
    trade_protocol_flags |= 1 << trade_range_bit;
}
