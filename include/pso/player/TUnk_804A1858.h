#ifndef PSO_PLAYER_TUNK_804A1858_H
#define PSO_PLAYER_TUNK_804A1858_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1858 : public TItemWeapon {
public:
    virtual ~TUnk_804A1858();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    void *set_state_35();
    u8 unk_1F8[0x4];
};

#endif
