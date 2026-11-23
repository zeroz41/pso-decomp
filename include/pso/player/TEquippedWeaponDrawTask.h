#ifndef PSO_PLAYER_TEQUIPPEDWEAPONDRAWTASK_H
#define PSO_PLAYER_TEQUIPPEDWEAPONDRAWTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Draws the equipped weapons TItemWeapon::render_equipped queues (weapon flag 0x800) in two
// draw-list passes, and scrolls the texture of drop model 5 each frame.
class TEquippedWeaponDrawTask : public TObject {
public:
    virtual ~TEquippedWeaponDrawTask();
    TEquippedWeaponDrawTask(TObject *parent);
    virtual void render();
    virtual void run_task();
};
LAYOUT_ASSERT(TEquippedWeaponDrawTask_size, sizeof(TEquippedWeaponDrawTask) == 0x1C);

#endif
