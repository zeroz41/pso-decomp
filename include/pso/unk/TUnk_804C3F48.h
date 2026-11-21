#ifndef PSO_UNK_TUNK_804C3F48_H
#define PSO_UNK_TUNK_804C3F48_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Created by TAdSinglePlyChrSelectGC::create_if_key_pressed in the battle areas; run_task plays a proximity
// sound by the distance from its owner to the nearest other player until its life runs out.
class TUnk_804C3F48 : public TObject {
public:
    TUnk_804C3F48(TObject *parent);
    virtual ~TUnk_804C3F48();
    virtual void run_task();
    s32 life;
    s32 timer;
    s32 owner;
};
LAYOUT_ASSERT(TUnk_804C3F48_size, sizeof(TUnk_804C3F48) == 0x28);

#endif
