#ifndef PSO_PLAYER_TUNK_804A4C78_H
#define PSO_PLAYER_TUNK_804A4C78_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Weapon class with vtable 0x804A4C78 (old ctor name TObjPlayer__sub_8012B0F8), made by
// TObjPlayer::create_obj_8012B140.
class TUnk_804A4C78 : public TItemWeapon {
public:
    virtual ~TUnk_804A4C78();
    virtual void reserved_53();
    TUnk_804A4C78(TObject *parent, u8 *item);
    s16 sub_8012B1F8();
    void sub_8012B1F0(s16);
};

#endif
