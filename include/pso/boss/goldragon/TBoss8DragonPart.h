#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONPART_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONPART_H

#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

// The TBoss8Dragon that TBoss8Dragon::spawn_attack_object creates. It differs from TBoss8Dragon only
// in its destructor and run_task.
class TBoss8DragonPart : public TBoss8Dragon {
public:
    TBoss8DragonPart(TObject *parent, void *set_data, s32 hp);
    virtual ~TBoss8DragonPart();
    virtual void run_task();
};

#endif
