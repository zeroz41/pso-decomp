#ifndef PSO_PLAYER_TFORCEOPERATE_H
#define PSO_PLAYER_TFORCEOPERATE_H

#include "types.h"
#include "pso/system/task/TObject.h"

#include "pso/player/PlayerRef.h"

// run_task is declared first: it is the key function that places the class's vtable.
struct TForceOperate : public TObject {
    virtual void run_task();
    TForceOperate(TObject *parent, u16 id);
    virtual ~TForceOperate();
    PlayerRef player_ref;
    static const char *class_name;
};

LAYOUT_ASSERT(TForceOperate_size, sizeof(TForceOperate) == 0x24);

#endif
