#ifndef PSO_ITEM_TUNK_804A2260_H
#define PSO_ITEM_TUNK_804A2260_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2260 : public TItemWeapon {
public:
    TUnk_804A2260(TObject *parent, u8 *item);
    virtual ~TUnk_804A2260();
    virtual void vfunc_60();
    void sub_80124C90();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    s32 rotation_z; // rotate_matrix_z angle, advanced by update_weapon
};

#endif
