#ifndef PSO_PLAYER_TUNK_804A5E20_H
#define PSO_PLAYER_TUNK_804A5E20_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Needle-shooting weapon class with vtable 0x804A5E20 (old ctor name init_state_2): fires five
// needles from joint 1. Made by TObjPlayer::create_init_state_2.
class TUnk_804A5E20 : public TItemWeapon {
public:
    virtual ~TUnk_804A5E20();
    virtual void emit_marker_effects();
    TUnk_804A5E20(TObject *parent, u8 *item);
};

extern const s32 five_joint_shot_angle_table[5];

#endif
