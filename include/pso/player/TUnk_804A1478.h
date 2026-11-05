#ifndef PSO_PLAYER_TUNK_804A1478_H
#define PSO_PLAYER_TUNK_804A1478_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1478 : public TItemWeapon {
public:
    virtual ~TUnk_804A1478();
    virtual void emit_marker_effects();
    TUnk_804A1478(TObject *parent, u8 *item);
};

u8 *create_wand_weapon(u8 *arg0);

#endif
