#ifndef PSO_BOSS_OLGAFLOW_TBOSS6SWORDSHOT_H
#define PSO_BOSS_OLGAFLOW_TBOSS6SWORDSHOT_H

#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TBoss6SwordShot : public TObject {
public:
    TBoss6SwordShot(TObject *owner, const Vec *position, s32 with_particles, f32 radius);
    static TBoss6SwordShot *create(TObject *owner, const Vec *position, s32 with_particles, f32 radius);
    virtual ~TBoss6SwordShot();
    virtual void run_task();

private:
    void damage_players_in_radius();
    TObject *owner;
    Vec position;
    f32 radius;
    s32 age;
    s32 damage;
};

typedef char TBoss6SwordShotSize[sizeof(TBoss6SwordShot) == 0x38 ? 1 : -1];

#endif
