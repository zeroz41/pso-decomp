#ifndef PSO_ITEM_TUNK_804A0648_H
#define PSO_ITEM_TUNK_804A0648_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TUnk_804A0648 : public TItemTimerEvent {
public:
    virtual ~TUnk_804A0648();
    void *init_item_timer_event();
    virtual void vfunc_6();
};
typedef char TUnk_804A0648_size[sizeof(TUnk_804A0648) == 0x2C ? 1 : -1];

#endif
