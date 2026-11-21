#include "pso/boss/olgaflow/TBoss6Zanzo.h"

TBoss6Zanzo *TBoss6Zanzo::create(TObject *parent, s32 points, s32 frames) {
    return new TBoss6Zanzo(parent, points, frames);
}
