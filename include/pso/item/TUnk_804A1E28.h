#ifndef PSO_ITEM_TUNK_804A1E28_H
#define PSO_ITEM_TUNK_804A1E28_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1E28 : public TItemWeapon {
public:
    virtual ~TUnk_804A1E28();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_60();
    u8 unk_1F8[0x4];
    s16 m_1fc;
    u8 unk_1FE[0x2];
};

u8 *create_sorcerers_cane(u8 *arg0);
u8 *sorcerers_cane_ct(u8 *arg0, u8 *arg1, s32 _w2);

#endif
