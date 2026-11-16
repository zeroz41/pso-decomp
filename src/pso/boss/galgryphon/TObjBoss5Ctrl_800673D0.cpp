#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/system/task/TObject.h"

extern "C" {


extern void *tl_01;
extern void *boss5_ctrl_instance;

void *TObjBoss5Ctrl::create() {
    void *o;
    o = TObject::operator new(0x30);
    if (o != NULL) {
        o = TObjBoss5Ctrl__ct(o, tl_01);
    }
    boss5_ctrl_instance = o;
    return o;
}

}
