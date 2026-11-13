#ifndef PSO_BOSS_BARBARAY_BOSS7DEROLLECBEHAVIOR_H
#define PSO_BOSS_BARBARAY_BOSS7DEROLLECBEHAVIOR_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
struct Boss7LoadCallback {
    void (*load)(void);
    void (*release)(void);
};

// What TObjEnemy::movementParameters points at.
struct TBoss7DeRolLeCMovement {
    EnemyMoveParams move;
    s32 unk_0C[4];
};

// The BML resource descriptor, followed by the action table that
// TBoss7DeRolLeC's constructor hands to set_field_d8.
struct TBoss7DeRolLeCResources {
    BmlResourceDescriptor descriptor;
    TObjMotionAction actions[17];
};

extern Boss7LoadCallback lbl_804E3C5C[6];
extern TBoss7DeRolLeCMovement lbl_804E3C8C;
extern TBoss7DeRolLeCResources lbl_804E3D1C;

#endif
