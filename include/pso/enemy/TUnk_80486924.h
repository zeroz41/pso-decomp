#ifndef PSO_ENEMY_TUNK_80486924_H
#define PSO_ENEMY_TUNK_80486924_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TUnk_80486924 : public TObjEnemy {
public:
    virtual ~TUnk_80486924();
    void init_hanger();
    void draw_hanger();
    virtual void render();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    u8 unk_374[0xDC];
};

#endif
