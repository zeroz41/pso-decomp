#ifndef PSO_ITEM_TITEMIDCOUNTERS_H
#define PSO_ITEM_TITEMIDCOUNTERS_H

#include "types.h"

// Built with the item system: allocates the per-client item id counters and
// their sync copies (12 each) and resets them; freeing it frees both.
struct TItemIdCounters {
    TItemIdCounters();
    ~TItemIdCounters();
};

#endif
