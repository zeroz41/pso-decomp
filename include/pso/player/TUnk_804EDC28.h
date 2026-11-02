#ifndef PSO_PLAYER_TUNK_804EDC28_H
#define PSO_PLAYER_TUNK_804EDC28_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804EDC28 : public TItemWeapon {
public:
    virtual ~TUnk_804EDC28();
    virtual void emit_marker_effects();
    void *construct_guardianna(s32, void *);
};

#endif
