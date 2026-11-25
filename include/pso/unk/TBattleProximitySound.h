#ifndef PSO_UNK_TBATTLEPROXIMITYSOUND_H
#define PSO_UNK_TBATTLEPROXIMITYSOUND_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Created by TAdSinglePlyChrSelectGC::create_if_key_pressed in the battle areas; run_task plays a proximity
// sound by the distance from its owner to the nearest other player until its life runs out.
class TBattleProximitySound : public TObject {
public:
    TBattleProximitySound(TObject *parent);
    virtual ~TBattleProximitySound();
    virtual void run_task();
    s32 life;
    s32 timer;
    s32 owner;
};
LAYOUT_ASSERT(TBattleProximitySound_size, sizeof(TBattleProximitySound) == 0x28);

#endif
