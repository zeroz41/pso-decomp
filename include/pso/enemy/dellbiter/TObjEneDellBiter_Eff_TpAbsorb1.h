#ifndef PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_EFF_TPABSORB1_H
#define PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_EFF_TPABSORB1_H
#include "pso/object/base/TAttackCollider.h"
class TParticleCtrl;
class AreaAttackHistory;


class TObjEneDellBiter_Eff_TpAbsorb1 : public TAttackCollider {
public:
    static const char *class_name;
    TObjEneDellBiter_Eff_TpAbsorb1(TObject *, TObjBase *, const Vec *, s32, AreaAttackHistory *, f32);
    virtual ~TObjEneDellBiter_Eff_TpAbsorb1();
    virtual void render();
    virtual void run_task();
    Vec direction;
    AreaAttackHistory *attack_history;
    f32 distance;
    f32 sample_distance;
    f32 power;
    TParticleCtrl *effect;
};
LAYOUT_ASSERT(TObjEneDellBiter_Eff_TpAbsorb1_size, sizeof(TObjEneDellBiter_Eff_TpAbsorb1) == 0xD0);
#endif
