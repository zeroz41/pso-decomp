#ifndef PSO_PLAYER_TUNK_804A2B98_H
#define PSO_PLAYER_TUNK_804A2B98_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2B98 : public TItemWeapon {
public:
    virtual ~TUnk_804A2B98();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_60();
    void *init_vtable_and_flags();
};

#endif
