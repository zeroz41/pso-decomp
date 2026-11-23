#ifndef PSO_WEAPON_TWEAPONCASING_H
#define PSO_WEAPON_TWEAPONCASING_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TItem;

// Weapon casing ejected by the Inferno Bazooka; falls under gravity until the
// weapon is no longer equipped.
class TWeaponCasing : public TObject {
public:
    TWeaponCasing(TObject *parent, TItem *item, Vec *position, Vec *velocity, s32 *rotation);
    virtual ~TWeaponCasing();
    virtual void render();
    virtual void run_task();
    s32 item_id;
    Vec velocity;
    Vec position;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
};
LAYOUT_ASSERT(TWeaponCasing_size, sizeof(TWeaponCasing) == 0x44);

#endif
