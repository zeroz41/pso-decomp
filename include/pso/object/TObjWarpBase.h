#ifndef PSO_OBJECT_TOBJWARPBASE_H
#define PSO_OBJECT_TOBJWARPBASE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjWarpBase : public TObjCollidable {
    virtual ~TObjWarpBase();
    virtual void vfunc_14();
    virtual void vfunc_15() = 0;
    virtual u8 vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(s32);
    static void free_globals();
};

#endif
