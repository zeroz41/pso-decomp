#ifndef PSO_UNK_TUNK_804A5D10_H
#define PSO_UNK_TUNK_804A5D10_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TItem;

// Weapon casing ejected by the Inferno Bazooka; falls under gravity until the
// weapon is no longer equipped.
class TUnk_804A5D10 : public TObject {
public:
    TUnk_804A5D10(TObject *parent, TItem *item, Vec *position, Vec *velocity, s32 *rotation);
    virtual ~TUnk_804A5D10();
    virtual void render();
    virtual void run_task();
    s32 item_id;
    Vec velocity;
    Vec position;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
};
LAYOUT_ASSERT(TUnk_804A5D10_size, sizeof(TUnk_804A5D10) == 0x44);

#endif
