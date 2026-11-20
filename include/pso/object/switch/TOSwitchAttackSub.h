#ifndef PSO_OBJECT_SWITCH_TOSWITCHATTACKSUB_H
#define PSO_OBJECT_SWITCH_TOSWITCHATTACKSUB_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TOSwitchAttackSub : public TObject {
public:
    u16 stopSwitchId;
    u16 requiredSwitchId;
    void* particle;
    f32 position[3];

    virtual ~TOSwitchAttackSub();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(SwitchAttackStopOffset, offsetof(TOSwitchAttackSub, stopSwitchId) == 0x1C);
LAYOUT_ASSERT(SwitchAttackRequiredOffset, offsetof(TOSwitchAttackSub, requiredSwitchId) == 0x1E);
LAYOUT_ASSERT(SwitchAttackParticleOffset, offsetof(TOSwitchAttackSub, particle) == 0x20);
LAYOUT_ASSERT(SwitchAttackPositionOffset, offsetof(TOSwitchAttackSub, position) == 0x24);

#endif
