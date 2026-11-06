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
typedef char SwitchAttackStopOffset[(offsetof(TOSwitchAttackSub, stopSwitchId) == 0x1C) ? 1 : -1];
typedef char SwitchAttackRequiredOffset[(offsetof(TOSwitchAttackSub, requiredSwitchId) == 0x1E) ? 1 : -1];
typedef char SwitchAttackParticleOffset[(offsetof(TOSwitchAttackSub, particle) == 0x20) ? 1 : -1];
typedef char SwitchAttackPositionOffset[(offsetof(TOSwitchAttackSub, position) == 0x24) ? 1 : -1];

#endif
