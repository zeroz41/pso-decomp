#ifndef PSO_ITEM_TUNK_804A4848_H
#define PSO_ITEM_TUNK_804A4848_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804A4848 : public TUnk_804A4948 {
public:
    TUnk_804A4848(TObject *parent, u8 *item);
    virtual ~TUnk_804A4848();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    virtual void reserved_53();
    s32 blade_angle;    // rotate_matrix_x angle in vfunc_60, advanced by blade_speed
    s32 blade_speed;    // 0xCCC idle, up to 0x3333 while attacking
    s32 attack_frames;  // counts update_attack calls
    s32 blend_off;      // 0: reserved_53 sets bit 0x10 of the model's flags while drawing
    u8 pad_20c[0x218 - 0x20C];
};

#endif
