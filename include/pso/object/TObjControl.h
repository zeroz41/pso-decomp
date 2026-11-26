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

void obj_control_on_floor_free(void);

// The enemy's row of the floor's set data (what set_entry points at).
struct EnemySetData {
    s16 set_index; u8 pad2[4]; u16 entity_id; s16 room; s16 group; u8 padC[4];
    Vec position; Vec rotation; f32 parameters[5]; s16 variant; s16 state;
};

#endif
