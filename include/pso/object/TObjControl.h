#ifndef PSO_OBJECT_TOBJCONTROL_H
#define PSO_OBJECT_TOBJCONTROL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjControl : public TObject {
public:
    TObjControl(TObject *parent);
    s16 m_decision_mode;
    u16 m_reserved;

    virtual ~TObjControl();
    virtual void run_task();
};

extern "C" {
void *TObjControl__ct(void *arg0);
s32 bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
u8 *get_enemy_entity(u16 arg0);
}

#endif
