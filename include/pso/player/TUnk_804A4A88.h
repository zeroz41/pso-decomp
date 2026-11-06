#ifndef PSO_PLAYER_TUNK_804A4A88_H
#define PSO_PLAYER_TUNK_804A4A88_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Lavis shot weapon class with vtable 0x804A4A88 (old ctor name init_state_object): its special
// drains 5% of the owner's HP. Made by TObjPlayer__sub_8012AB1C.
class TUnk_804A4A88 : public TItemWeapon {
public:
    virtual ~TUnk_804A4A88();
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    TUnk_804A4A88(TObject *parent, u8 *item);
    s32 rotation_z;  // rotate_matrix_z angle of the model hook, spun there
};

extern "C" u8 *TObjPlayer__sub_8012AB1C(u8 *item);

#endif
