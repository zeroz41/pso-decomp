#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"

TBoss6GravBall *TBoss6Type1::create_grav_ball(TBoss6Type1 *owner, const Vec *position) {
    return new TBoss6GravBall(owner, position);
}
