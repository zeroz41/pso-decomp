#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"

extern "C" {

void *__ct__14TBoss6GravBallFlPv(void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TBoss6Type1::create_grav_ball(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0xF8);
    if (o != NULL) {
        o = __ct__14TBoss6GravBallFlPv(o, arg0, arg1);
    }
    return o;
}

}
