#ifndef PSO_OBJECT_TUNK_804AF7B0_H
#define PSO_OBJECT_TUNK_804AF7B0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804AF7B0 : public TObject {
public:
    TUnk_804AF7B0(TObject *parent, u16 client);
    virtual ~TUnk_804AF7B0();
    virtual void run_task();
    // inferred: from the ctor and run_task (TNpcPlayer.cpp).
    s32 damage_interval;  // ticks between poison damage (150 first, then 30)
    s32 damage_timer;     // ticks since the last damage
    s32 contact_ticks;    // consecutive ticks inside the fog
    u16 client;
    u8 pad_2A[0x2];
};
typedef char TUnk_804AF7B0_size[sizeof(TUnk_804AF7B0) == 0x2C ? 1 : -1];

#endif
