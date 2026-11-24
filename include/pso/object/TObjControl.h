#ifndef PSO_OBJECT_TOBJCONTROL_H
#define PSO_OBJECT_TOBJCONTROL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjChara;

class TObjControl : public TObject {
public:
    TObjControl(TObject *parent);
    s16 m_decision_mode;
    u16 m_reserved;

    virtual ~TObjControl();
    virtual void run_task();
};

extern "C" {
TObjChara *get_enemy_entity(u16 arg0);
}

#endif
