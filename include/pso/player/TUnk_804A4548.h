#ifndef PSO_PLAYER_TUNK_804A4548_H
#define PSO_PLAYER_TUNK_804A4548_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

// The S-rank bazooka-type weapon class (vtable 0x804A4548): after a shot
// (vfunc_62) update_weapon slides the barrel back and returns it.
class TUnk_804A4548 : public TUnk_804A4948 {
public:
    virtual void vfunc_60();
    virtual void update_weapon();
    TUnk_804A4548(TObject *parent, u8 *item);
    virtual void vfunc_62();
    virtual ~TUnk_804A4548();
    f32 barrel_offset;  // translate_matrix y offset in vfunc_60, 0 to -2
    s32 recoil_state;   // 1 sliding back, 2 returning, 0 at rest
};

#endif
