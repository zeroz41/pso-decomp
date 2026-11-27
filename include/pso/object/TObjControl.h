#ifndef PSO_OBJECT_TOBJCONTROL_H
#define PSO_OBJECT_TOBJCONTROL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

extern s32 area_random_seed;

class TObjChara;

class TObjControl : public TObject {
public:
    TObjControl(TObject *parent);
    s16 m_decision_mode;
    u16 m_reserved;

    virtual ~TObjControl();
    virtual void run_task();
};

TObjChara *get_enemy_entity(u16 entity_id);

void object_control_on_floor_free_stub(void);

void clear_flag_on_phase_e();

#endif
