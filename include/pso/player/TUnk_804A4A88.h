#ifndef PSO_PLAYER_TUNK_804A4A88_H
#define PSO_PLAYER_TUNK_804A4A88_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A4A88 : public TItemWeapon {
public:
    virtual ~TUnk_804A4A88();
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    void*init_state_object();
    u8 unk_1F8[0x4];
};

#endif
