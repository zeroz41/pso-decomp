#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *__ct__11TBoss6ZanzoFP7TObjectll(void *, void *, void *, void *);

void *TBoss6Type1::create_zanzo(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = TObject::operator new(0x2C);
    if (o != NULL) {
        o = __ct__11TBoss6ZanzoFP7TObjectll(o, arg0, arg1, arg2);
    }
    return o;
}

}
