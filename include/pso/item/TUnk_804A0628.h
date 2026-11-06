#ifndef PSO_ITEM_TUNK_804A0628_H
#define PSO_ITEM_TUNK_804A0628_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TUnk_804A0628 : public TItemTimerEvent {
public:
    virtual ~TUnk_804A0628();
    void *construct_timer_event();
    virtual void vfunc_6();
};
typedef char TUnk_804A0628_size[sizeof(TUnk_804A0628) == 0x2C ? 1 : -1];

#endif
