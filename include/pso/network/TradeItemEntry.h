#ifndef PSO_NETWORK_TRADEITEMENTRY_H
#define PSO_NETWORK_TRADEITEMENTRY_H
#include "types.h"

// One slot of a trade offer: an inventory item id (0xFFFFFF01 for meseta) and how many.
struct TradeItemEntry {
    u32 id;
    s32 count;
};

#endif
