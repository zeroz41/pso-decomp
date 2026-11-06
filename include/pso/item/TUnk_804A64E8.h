#ifndef PSO_ITEM_TUNK_804A64E8_H
#define PSO_ITEM_TUNK_804A64E8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Slicer weapon class with vtable 0x804A64E8 (old ctor name init_position_state): its special
// throws TTecSlicer from joints 5 and 4. Made by TObjPlayer::create_position_state.
class TUnk_804A64E8 : public TItemWeapon {
public:
    virtual ~TUnk_804A64E8();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void emit_marker_effects();
    virtual void update_attack();
    TUnk_804A64E8(TObject *parent, u8 *item);
    Vec scale;       // 0x1F8: scale_current_matrix of model 2; 1 idle, 10 attacking
    s32 rotation_x;  // 0x204: rotate_matrix_x of models 1 and 3 (opposite ways)
};

#endif
