#ifndef PSO_OBJECT_WARP_TOBJWARPBASE_H
#define PSO_OBJECT_WARP_TOBJWARPBASE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjWarpBase : public TObjCollidable {
    virtual ~TObjWarpBase();
    virtual void vfunc_14();
    virtual void open_confirm_window(u16) = 0;
    virtual u8 is_warp_enabled();
    virtual void vfunc_17();
    virtual void vfunc_18(s32);
    static void free_globals();
};

#endif
