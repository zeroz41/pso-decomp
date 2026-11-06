#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"

extern "C" {

void *__ct__11TBoss6ZanzoFP7TObjectll(void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TBoss6Type1::create_zanzo(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = __ct__11TBoss6ZanzoFP7TObjectll(o, arg0, arg1, arg2);
    }
    return o;
}

}
