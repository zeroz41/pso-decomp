#include "types.h"
#include "pso/boss/TObjBoss5Ctrl.h"

extern "C" {

void *__nw__7TObjectFUl(int);

extern void *tl_01;
extern void *boss5_ctrl_instance;

void *TObjBoss5Ctrl::create() {
    void *o;
    o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = TObjBoss5Ctrl__ct(o, tl_01);
    }
    boss5_ctrl_instance = o;
    return o;
}

}
