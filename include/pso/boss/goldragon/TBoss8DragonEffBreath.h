#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBREATH_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBREATH_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/enemy/AttackTargetHistory.h"

struct TBoss8DragonEffBreath : public TObject {
    TBoss8DragonEffBreath(TObject *parent, Vec *pos, Vec *direction, s32 kind, u16 owner);
    virtual ~TBoss8DragonEffBreath();
    Vec position;
    Vec velocity;
    u32 attack_kind;
    u16 owner_entity_id;
    AreaAttackHistory *attack_history;
    virtual void render();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(TBoss8DragonEffBreath_position, offsetof(TBoss8DragonEffBreath, position) == 0x1C);
LAYOUT_ASSERT(TBoss8DragonEffBreath_velocity, offsetof(TBoss8DragonEffBreath, velocity) == 0x28);
LAYOUT_ASSERT(TBoss8DragonEffBreath_entity, offsetof(TBoss8DragonEffBreath, owner_entity_id) == 0x38);
LAYOUT_ASSERT(TBoss8DragonEffBreath_history, offsetof(TBoss8DragonEffBreath, attack_history) == 0x3C);
LAYOUT_ASSERT(TBoss8DragonEffBreath_size, sizeof(TBoss8DragonEffBreath) == 0x40);

#endif
