#ifndef PSO_OBJECT_SWITCH_TOSWITCHATTACKSUB_H
#define PSO_OBJECT_SWITCH_TOSWITCHATTACKSUB_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TOSwitchAttackSub : public TObject {
public:
    u16 stopSwitchId;
    u16 requiredSwitchId;
    void* particle;
    Vec position;

    TOSwitchAttackSub(TObject *parent, s32 stop_switch, s32 required_switch, u32 type, f32 scale);
    virtual ~TOSwitchAttackSub();
    virtual void run_task();
};

#include <stddef.h>
LAYOUT_ASSERT(SwitchAttackStopOffset, offsetof(TOSwitchAttackSub, stopSwitchId) == 0x1C);
LAYOUT_ASSERT(SwitchAttackRequiredOffset, offsetof(TOSwitchAttackSub, requiredSwitchId) == 0x1E);
LAYOUT_ASSERT(SwitchAttackParticleOffset, offsetof(TOSwitchAttackSub, particle) == 0x20);
LAYOUT_ASSERT(SwitchAttackPositionOffset, offsetof(TOSwitchAttackSub, position) == 0x24);

#endif
