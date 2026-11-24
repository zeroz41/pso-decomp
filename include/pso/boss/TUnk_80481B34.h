#ifndef PSO_BOSS_TUNK_80481B34_H
#define PSO_BOSS_TUNK_80481B34_H
#include "types.h"
#include "pso/object/base/TAttackCollider.h"

class TUnk_80481B34 : public TAttackCollider {
public:
    TUnk_80481B34(TObject *parent, TObjBase *owner);
    virtual ~TUnk_80481B34();
    virtual void apply_hit_if_active(void *, f32 *);
    virtual void area_attack_receive_direct(void *, f32 *, void *);
};
LAYOUT_ASSERT(TUnk_80481B34_size, sizeof(TUnk_80481B34) == 0xB0);

#endif
