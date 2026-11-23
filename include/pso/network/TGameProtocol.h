#ifndef PSO_NETWORK_TGAMEPROTOCOL_H
#define PSO_NETWORK_TGAMEPROTOCOL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TGameProtocol : public TObject {
public:
    TGameProtocol(TObject *parent);
    virtual ~TGameProtocol();
    virtual void run_task();
    // Counts 0..3 each frame; packets whose slot matches it are flushed (inferred name).
    u32 frame_slot;
};
LAYOUT_ASSERT(TGameProtocol_size, sizeof(TGameProtocol) == 0x20);

// The TObject whose children are the game packets TGameProtocol::run_task flushes.
extern TObject *game_protocol_instance;

#endif
